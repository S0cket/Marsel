#include <iostream>
#include <vector>
#include "error.h"

using namespace std;

class Queue {
private:
	vector<int> q;
	unsigned max_size;
public:
	Queue() {
		this->max_size = 128;
	}
	Queue(unsigned max_size) {
		if (max_size == 0) throw NullSizeError();
		this->max_size = max_size;
	}
	Queue(vector<int> q) {
		this->q = q;
		this->max_size = q.size();
	}
	vector<int> getvector() {
		return q;
	}

	void push(int elem) {
		if (q.size() == max_size) throw OverflowError();
		q.push_back(elem);
	}
	int pop() {
		if (q.size() == 0) throw EmptyError();
		int ret = q[0];
		q.erase(q.begin());
		return ret;
	}
	int top() {
		if (q.size() == 0) throw EmptyError();
		return q[0];
	}
	int& operator[](unsigned index) {
		if (index >= q.size()) throw IndexOutOfRangeError();
		return q[index];
	}
	unsigned operator()() {
		return max_size;
	}
	void operator()(unsigned max_size) {
		if (max_size == 0) throw NullSizeError();
		this->max_size = max_size;
	}
	Queue operator*(Queue Q) {
		vector<int> a = Q.getvector();
		int n = min(a.size(), q.size());
		vector<int> ret(n);
		for (int i = 0; i < n; ++ i)
			ret[i] = q[i] * a[i];
		return Queue(ret);
	}

	~Queue() {}

};

int main(void) {
	try {
		Queue a;
		a.push(1);
		a.push(2);
		a.push(3);

		
		cout << a[0] << " " << a[1] << " " << a[2] << endl;
		//cout << a[4]; // Error
		cout << a.top() << endl;
		cout << a.pop() << " ";
		cout << a.pop() << " ";
		cout << a.pop() << " ";
		cout << "\n";
		//cout << a.top() << endl; // Error


	}
	catch (Error & E) {
		E.what();
	}
	return 0;
}