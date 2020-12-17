#include <iostream>
#include <set>

using namespace std;

template<class T>
class Set {
private:
	set<T> a;
public:
	Set() {}
	Set(set<T> b) {
		a = b;
	}
	set<T> getset() {
		return a;
	}
	unsigned getsize() {
		return a.size();
	}
	T operator[](unsigned index) {
		T ret;
		int cnt = 0;
		for (auto iter = a.begin(); iter != a.end(); ++ iter, ++ cnt) {
			ret = *iter;
			if (cnt == index)
				break;
		}
		return ret;

	}
	bool operator!=(Set<T> S) {
		return (S.getset() != a);
	}
	bool operator<(T value) {
		return (a.count(value));
	}
	~Set() {}
};

class Money {
private:
	long rub;
	int kop;
public:
	Money() {
		rub = 0;
		kop = 0;
	}
	Money(long r) {
		rub = r;
		kop = 0;
	}
	Money(long r, int k) {
		rub = r + k / 100;
		kop = k % 100;
	}
	void print() {
		cout << rub << "," << kop << endl;
	}
	~Money() {}
};

int main(void) {
	set<int> a;
	a.insert(1);
	a.insert(2);
	a.insert(3);
	a.insert(4);
	a.insert(3);
	Set<int> st(a);
	for (int i = 0; i < st.getsize(); ++ i)
		cout << st[i] << " ";
	cout << "\n";
	cout << (st < 6) << (st < 1) << (st < 3) << endl;
	return 0;

}