#include <iostream>
#include <vector>

using namespace std;

class Matrix {
public:
	unsigned n;
	vector<vector<double>> m;

	Matrix() {
		this->n = 0;
	}
	Matrix(unsigned n) {
		this->n = n;
		for (int i = 0; i < n; ++ i)
			this->m.push_back(vector<double>(n, 0));
	}
	Matrix(unsigned n, vector<vector<double>> m) {
		if (m.size() != n) {
			cout << "Error!!!\n";
			this->n = 0;
		}
		else {
			bool flag = true;
			for (int i = 0; i < n; ++ i) {
				if (m[i].size() != n)
					flag = false;
			}
			if (flag) {
				this->n = n;
				this->m = m;
			}
			else {
				cout << "Error!!!\n";
				this->n = 0;
			}

		}
	}


	void print() {
		for (int i = 0; i < n; ++ i) {
			for (int j = 0; j < n; ++ j)
				cout << m[i][j] << " ";
			cout << "\n";
		}
	}
	bool is_ed() {
		for (int i = 0; i < n; ++ i) {
			for (int j = 0; j < n; ++ j)
				if (!(i == j && m[i][j] == 1 || i != j && m[i][j] == 0))
					return false;
		}
		return (n != 0);
	}

	Matrix operator+(Matrix M) {
		if (this->n != M.n) {
			cout << "Error!!!\n";
			return Matrix();
		}
		vector<vector<double>> a = this->m;
		for (int i = 0; i < n; ++ i) {
			for (int j = 0; j < n; ++ j) {
				a[i][j] += M.m[i][j];
			}
		}
		return Matrix(a.size(), a);
	}
	Matrix operator-(Matrix M) {
		if (this->n != M.n) {
			cout << "Error!!!\n";
			return Matrix();
		}
		vector<vector<double>> a = this->m;
		for (int i = 0; i < n; ++ i) {
			for (int j = 0; j < n; ++ j) {
				a[i][j] -= M.m[i][j];
			}
		}
		return Matrix(a.size(), a);	
	}
	Matrix operator*(Matrix M) {
		if (this->n != M.n) {
			cout << "Error!!!\n";
			return Matrix();
		}
		Matrix ret = Matrix(this->n);
		for (int i = 0; i < this->n; ++ i) {
			for (int j = 0; j < this->n; ++ j) {
				ret.m[i][j] = 0;
				for (int k = 0; k < this->n; ++ k)
					ret.m[i][j] += this->m[i][k] * M.m[k][j];
			}
		}
		return ret;
	}
	Matrix operator*=(double n) {
		vector<vector<double>> a = this->m;
		for (int i = 0; i < this->n; ++ i) {
			for (int j = 0; j < this->n; ++ j) {
				a[i][j] *= n;
			}
		}
		return Matrix(a.size(), a);
	}

	~Matrix() {}
};

int main(void) {
	vector<vector<double>> x(3, vector<double>(3)), y(3, vector<double>(3));
	x[0][0] = 1; x[0][1] = 2; x[0][2] = 2;
	x[1][0] = 0; x[1][1] = 3; x[1][2] = 1;
	x[2][0] = 1; x[2][1] = 0; x[2][2] = 0;

	y[0][0] = 0; y[0][1] = 0; y[0][2] = 1;
	y[1][0] = -0.25; y[1][1] = 0.5; y[1][2] = 0.25;
	y[2][0] = 0.75; y[2][1] = -0.5; y[2][2] = -0.75;

	
	Matrix a(3, x), b(3, y), d;
	d = (a *= 3) * b + (a - b) * a;
	d.print();

	if ((a * b).is_ed())
		cout << "YES\n";
	else
		cout << "NO\n";
	return 0;
}