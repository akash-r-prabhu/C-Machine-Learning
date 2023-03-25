# Machine Learning using C++

This project intends to implement machine learning algorithm like

- Linear Regression
- Logistic Regression
- K Nearest Neighbours
- SVM

Using Plain C++ and ETL(extract, transform and load) package

## Installation

- Clone the repo
  https://github.com/akash-r-prabhu/C-Machine-Learning.git

- Open folder in terminal and install boost

  `brew install boost`

- Upload dataset to dataset folder else use default wine dataset

- To run

  ```
  g++ -std=c++11 ETL/ETL.cpp main.cpp -o main

  ./main datasets/wine_data.csv "," headers=True
  ```

- Note : Make sure g++ is installed
  - For [Windows](https://techsupportwhale.com/install-gcc-compiler-on-windows/)
  - for [Unix(or mac)](https://www.bing.com/ck/a?!&&p=5e44fa7fc295f3faJmltdHM9MTY3OTcwMjQwMCZpZ3VpZD0zZjBmMzIyZS1kZjEwLTY5MzctMWU1Yy0yMGY3ZGVlNzY4YTImaW5zaWQ9NTIwNg&ptn=3&hsh=3&fclid=3f0f322e-df10-6937-1e5c-20f7dee768a2&psq=g%2b%2b+installining+in+unix&u=a1aHR0cHM6Ly9saW51eGNvbmZpZy5vcmcvaG93LXRvLWluc3RhbGwtZy10aGUtYy1jb21waWxlci1vbi11YnVudHUtMjAtMDQtbHRzLWZvY2FsLWZvc3NhLWxpbnV4&ntb=1)

## License

[MIT](https://choosealicense.com/licenses/mit/)
