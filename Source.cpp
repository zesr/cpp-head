#include<iostream>
using std::cout;
using std::endl;
struct mvector {
	mvector() {//3 constructor which can receive int,list or null;
		list = nullptr;
		maxsize = 1;
		size = 0; 
		cout << maxsize <<endl<< size << endl;
	}
	mvector(int const &n, int const &a):mvector() {
		init(n);
		for (int i = 0; i < n; ++i)
			list[i] = a;
	}
	mvector(std::initializer_list<int> const &key):mvector() {
		
		cout << maxsize << endl << size << endl;
		init(key.size());
		for (auto const &x : key)
			push_back(x);//
		size += key.size();
	}
	int operator[] (int &i) {//reload []
		if (i >= size || i < 0)
			throw("Out of range");
		else 
			return list[i];
	}
	mvector& push_back(int const &a) {//Use it after give enough room
		list[size] = a;
		size += 1;
		return *this;
	}
	mvector& push_back(std::initializer_list<int> const &key) {
		init(key.size());
		for (auto const &x : key)
			push_back(x);
		return *this;
	}
	~mvector() {
		if (list){
			delete[] list;
			list = nullptr;
		}
	}
private:
	void init(int const &n) {//new the room
		bool flag = 0;
		cout << maxsize << endl << size << endl;
		while (size + n > maxsize)
		{
			maxsize *= 2;//The size of the new pointer
			flag = 1;
		}
		while (size + n <= maxsize / 4) {//The maxsize is too big
			maxsize /= 2;
			flag = 1;
		}
		if (flag){
			int *temp = new int[maxsize];
			if (list)
				for (int i = 0; i < size; ++i)
					temp[i] = list[i];
			delete[] list;
			list = temp;
		}
	}
	int *list;
	int size;
	int maxsize;
};

int main() {
	mvector a({1,2,3});
	return 0;
}