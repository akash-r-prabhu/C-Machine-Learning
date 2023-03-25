#ifndef ETL_h
#define ETL_h

#include <iostream>
#include <fstream>
#include "../eigen-3.3.7/Eigen/Dense"
using namespace std;

class ETL
{
    string dataset;
    string delimiter;
    bool header;

public:
    ETL(string data, string seperator, bool head) : dataset(data), delimiter(seperator), header(head){};
    vector<vector<string>> read_csv();
    Eigen::MatrixXd CSVtoEigen(vector<vector<string>> dataset, int rows, int cols);
    Eigen::MatrixXd Normalize(Eigen::MatrixXd matrix);
    auto Mean(Eigen::MatrixXd data) -> decltype(data.colwise().mean());
    auto Std(Eigen::MatrixXd data) -> decltype(((data.array().square().colwise().sum()) / (data.rows() - 1)).sqrt());
};

#endif