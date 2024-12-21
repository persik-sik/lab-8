#include <iostream>
using namespace std;

struct Matrix {
  int** data_ = nullptr;
  size_t n_ = 0u;
  size_t m_ = 0u;
};

void Construct(Matrix& output, size_t n, size_t m){
    output.n_ = n;
	output.m_ = m;
	output.data_ = new int* [m];
	for (int i = 0; i < m; i++) {
		output.data_[i] = new int[n]();
	}
}

void Destruct(Matrix& ex){
    for (int i = 0; i < ex.m_; i++){
        delete ex.data_ [i];
    }
    delete ex.data_;
}

Matrix Copy(const Matrix& matrix){
    Matrix copy;
    Construct(copy, matrix.n_, matrix.m_);
    for (int i = 0; i<matrix.m_; i++){
        for (int j = 0; j<matrix.n_; j++){
            copy.data_[i][j] = matrix.data_[i][j];
        }
    }
    return copy;
}

Matrix Add(const Matrix& first, const Matrix& second){
    Matrix total;
    Construct(total, first.n_, second.m_);
    for (int i = 0; i<first.m_; i++){
        for (int j = 0; j<first.n_; j++){
            total.data_[i][j] = first.data_[i][j] + second.data_[i][j];
        }
    }
    return total;
}

Matrix Sub(const Matrix& first, const Matrix& second){
    Matrix total;
    Construct(total, first.n_, second.m_);
    for (int i = 0; i<first.m_; i++){
        for (int j = 0; j<first.n_; j++){
            total.data_[i][j] = first.data_[i][j] - second.data_[i][j];
        }
    }
    return total;
}

Matrix Mult(const Matrix& first, const Matrix& second){
    Matrix output;
    if(first.data_ && second.data_ && first.m_ == second.n_){
        Construct(output,first.n_,second.m_);
        for(int i = 0; i < first.n_; ++i){
            for(int j = 0; j < second.m_; ++j){
                for(int k = 0; k < first.m_; ++k){
                    output.data_[i][j] += first.data_[i][k] * second.data_[k][j];
                }
            }
        }
    }
    return output;
}

Matrix Transposition(const Matrix& input){
    Matrix output;
    Construct(output, input.n_, input.m_);
    for (int i = 0; i<input.m_; i++){
        for (int j = 0; j<input.n_; j++){
            output.data_[i][j] = input.data_[j][i];
        }
    }
    return output;
}

bool operator==(const Matrix& first, const Matrix& second) {
    auto m = first.m_;
    auto n = first.n_;
    int count = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if(first.data_[i][j] == second.data_[i][j]){
               count+=1;
            }
        }
    }
    return (count == m * n);
}
