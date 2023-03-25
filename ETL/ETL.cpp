#include "ETL.h"
#include <vector>
#include <stdlib.h>
#include <cmath>
#include "boost/algorithm/string.hpp"
using namespace std;

vector<vector<string>> ETL::read_csv()
{
    ifstream file(dataset);
    vector<vector<string>> dataString;
    string line = "";
    while (getline(file, line))
    {
        vector<string> vec;
        boost::algorithm::split(vec, line, boost::is_any_of(delimiter));
        dataString.push_back(vec);
    }
    file.close();
    return dataString;
}

Eigen::MatrixXd ETL::CSVtoEigen(vector<vector<string>> dataset, int rows, int cols)
{
    if (header == true)
    {
        rows -= 1;
    }
    Eigen::MatrixXd matrix(cols, rows);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            matrix(j, i) = atof(dataset[i][j].c_str());
        }
    }
    return matrix.transpose();
}

auto ETL::Mean(Eigen::MatrixXd data) -> decltype(data.colwise().mean())
{
    return data.colwise().mean();
}
auto ETL::Std(Eigen::MatrixXd data) -> decltype(((data.array().square().colwise().sum()) / (data.rows() - 1)).sqrt())
{
    return ((data.array().square().colwise().sum()) / (data.rows() - 1)).sqrt();
}

Eigen::MatrixXd ETL::Normalize(Eigen::MatrixXd matrix)
{
    auto mean = Mean(matrix);
    Eigen::MatrixXd scaled_data = matrix.rowwise() - mean;
    auto std = Std(scaled_data);

    Eigen::MatrixXd normalized_data = scaled_data.array().rowwise() / std;
    return normalized_data;
}
