#include "ETL/ETL.h"
#include <iostream>
#include <string>
#include "eigen-3.3.7/Eigen/Dense"
#include "boost/algorithm/string.hpp"
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    ETL etl(argv[1], argv[2], argv[3]);

    // to read csv file
    vector<vector<string>> data = etl.read_csv();
    int rows = data.size();
    int cols = data[0].size();

    // to convert csv file to Eigen matrix
    Eigen::MatrixXd matrix = etl.CSVtoEigen(data, rows, cols);

    // linear regression

    // preprocessing
    Eigen::MatrixXd normalized_data = etl.Normalize(matrix);
    cout << normalized_data << endl;
    return EXIT_SUCCESS;
}
