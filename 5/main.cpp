#include <iostream>
#include <utility>
#include <math.h>

using namespace std;

typedef pair<double, double> point;

class Quadrangle {
protected:
	point p[4];
public:
	Quadrangle() {
		p[0] = point(0, 0);
		p[1] = point(2, 0);
		p[2] = point(2, 1);
		p[3] = point(0, 1);
	}
	Quadrangle(point a, point b, point c, point d) {
		this->p[0] = a;
		this->p[1] = b;
		this->p[2] = c;
		this->p[3] = d;
	}
	double len(int n) {
		if (n < 0 || n > 3) {
			cout << "Error\n";
			return 0;
		}
		point a = p[n], b = p[(n + 1) % 4];
		return sqrt(pow(b.first - a.first, 2) + pow(b.second - a.second, 2));
	}
	double D(int n = 0) {
		if (n < 0 || n > 1) {
			cout << "Error\n";
			return 0;
		}
		point a = p[n], b = p[n + 2];
		return sqrt(pow(b.first - a.first, 2) + pow(b.second - a.second, 2));
	}
	double P() {
		double ret = 0;
		for (int i = 0; i < 4; ++ i)
			ret += len(i);
		return ret;
	}
	double S() {
		double p = P() / 2;
		double ret = 1;
		for (int i = 0; i < 4; ++ i)
			ret *= (p - len(i));
		return sqrt(ret);
	}

	void print() {
		cout << "Quadrangle:\n";
		for (int i = 0; i < 4; ++ i)
			cout << "\tside " << (i + 1) << ": " << len(i) << "\n";
		for (int i = 0; i < 2; ++ i)
			cout << "\tdiag " << (i + 1) << ": " << D(i) << "\n";
		cout << "\tS: " << S() << "\n";
		cout << "\tP: " << P() << "\n";
		cout << "\n";
	}

	~Quadrangle() {}
};

class Trapeze : public Quadrangle {
private:
	//Определяет по координатам векторов, коллинеарны ли они
	bool is_koll(point a, point b) {
		if (b.first == 0 && a.first == 0 || b.second == 0 && a.second == 0)
			return true;
		return (a.second / b.second == a.first / b.first);
	}
public:
	Trapeze() {
		p[0] = point(0, 0);
		p[1] = point(2, 0);
		p[2] = point(2, 1);
		p[3] = point(0, 1);
	}
	Trapeze(point a, point b, point c, point d) {
		this->p[0] = a;
		this->p[1] = b;
		this->p[2] = c;
		this->p[3] = d;
	}

	bool is() {
		//Координаты векторов, лежащих на сторонах трапеции
		point a = point(p[0].first - p[1].first, p[0].second - p[1].second); // Сторона с индексом 0
		point b = point(p[1].first - p[2].first, p[1].second - p[2].second);
		point c = point(p[2].first - p[3].first, p[2].second - p[3].second);
		point d = point(p[3].first - p[0].first, p[3].second - p[0].second);

		//Если ни одна из сторон не параллельна никакой другой или стороны попарно параллельны
		if (!is_koll(a, c) && !is_koll(b, d) || is_koll(a, c) && is_koll(b, d))
			return false;

		if (is_koll(a, c)) {
			return (len(1) == len(3));
		}
		else {
			return (len(0) == len(2));
		}

	}

	~Trapeze () {}
};

int main(void) {
	int n, m;
	cin >> n >> m;

	double ms = 0;
	int cnt = 0;
	for (int i = 0; i < n; ++ i) {
		cout << "Quadrangle " << i << ":\n";
		point a, b, c, d;
		cin >> a.first >> a.second;
		cin >> b.first >> b.second;
		cin >> c.first >> c.second;
		cin >> d.first >> d.second;
		Quadrangle q(a, b, c, d);
		if (q.S() > ms) {
			ms = q.S();
			cnt = 1;
		}
		else if (q.S() == ms)
			++ cnt;
	}


	Trapeze md;
	bool flag = false;
	for (int i = 0; i < m; ++ i) {
		cout << "Trapeze " << i << ":\n";
		point a, b, c, d;
		cin >> a.first >> a.second;
		cin >> b.first >> b.second;
		cin >> c.first >> c.second;
		cin >> d.first >> d.second;
		Trapeze t(a, b, c, d);
		if (!t.is()) {
			cout << "Error\n";
			-- i;
			continue;
		}
		if (!flag) {
			flag = true;
			md = t;
		}
		else {
			if (t.D() < md.D())
				md = t;
		}
	}
	cout << "\n\n";
	cout << "Number 1:\nMin Area: " << ms << "; Count: " << cnt << "\n";
	cout << "\n\n";
	cout << "Number 2:\n"; md.print();

	return 0;
}