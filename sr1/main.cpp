#include <iostream>
#include <deque>
#include <stdlib.h>
#include <time.h>
#include <list>

using namespace std;

void print(deque<int> d) {
	for (int i = 0; i < d.size(); ++ i)
		cout << d[i] << " ";
	cout << endl;
}
void print(list<int> d) {
	for (auto iter = d.begin(); iter != d.end(); ++ iter)
		cout << *iter << " ";
	cout << endl;
}

int main(void) {
	//1
	srand(time(NULL));
	int n;
	cin >> n;

	deque<int> d;
	for (int i = 0; i < n; ++ i)
		d.push_back(rand() % 100);
	print(d);
	bool flag = true;
	for (auto iter = d.begin(); iter != d.end(); ++ iter) {
		if (*iter == 0) {
			flag = false;
			d.erase(iter);
			break;
		}
	}
	if (flag) {
		for (auto iter = d.begin(); iter != d.end(); ++ iter) {
			if (*iter % 2 == 0) {
				d.erase(iter);
				break;
			}
		}	
	}
	print(d);
	for (int i = 0; i < d.size(); ++ i) {
		if (d[i] % 2 == 0) {
			d.insert(d.begin() + i + 1, d[i] + 2);
			++ i;
		}
	}
	print(d);


	//2
	cin >> n;
	list<int> l;
	for (int i = 0; i < n; ++ i)
		l.push_back(rand() % 100);
	print(l);
	cin >> n;
	for (int i = 0; i < n; ++ i)
		l.push_front(0);
	print(l);
	return 0;


}