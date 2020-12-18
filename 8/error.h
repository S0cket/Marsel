#include <string>
#include <iostream>

using namespace std;

class Error {
public:
	virtual void what() {};
};

class SizeError : public Error {
protected:
	string msg;
public:
	SizeError() {
		msg = "SizeError";
	}
	virtual void what() {
		cout << "\n" << msg << "\n";
	}
};

class NullSizeError : public SizeError {
protected:
	string msg_;
public:
	NullSizeError() {
		SizeError();
		msg_ = "Null Size";
	}
	virtual void what() {
		cout << "\n" << msg << ": " << msg_ << "\n";
	}
};

class OverflowError : public SizeError {
protected:
	string msg_;
public:
	OverflowError() {
		SizeError();
		msg_ = "Overflow";
	}
	virtual void what() {
		cout << "\n" << msg << ": " << msg_ << "\n";
	}
};

class EmptyError : public SizeError {
protected:
	string msg_;
public:
	EmptyError() {
		SizeError();
		msg_ = "Empty container";
	}
	virtual void what() {
		cout << "\n" << msg << ": " << msg_ << "\n";
	}
};

class IndexError : public Error {
protected:
	string msg;
public:
	IndexError() {
		msg = "IndexError";
	}
	virtual void what() {
		cout << "\n" << msg << "\n";
	}
};

class IndexOutOfRangeError : public IndexError {
protected:
	string msg_;
public:
	IndexOutOfRangeError() {
		IndexError();
		msg_ = "Index out of range";
	}
	virtual void what() {
		cout << "\n" << msg << ": " << msg_ << "\n";
	}
};