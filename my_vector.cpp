//#include<iostream>
//using std::cout;
//using std::endl;
struct mvector {
	mvector():list(nullptr),maxsize(1),size(0) {//3 constructor which can receive int,list or null;
		list = new int[0];
	}

	mvector(int a):mvector() {
		init(1);
		push_back(a);
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
	}

	int operator[] (int &i) {//reload []
		if (i >= size || i < 0)
			throw("Out of range");
		else 
			return list[i];
	}

	mvector& push_back(int const &a) {//Use it after give enough room
		init(1);
		list[size-1] = a;
		return *this;
	}

	mvector& push_back(std::initializer_list<int> const &key) {
		init(key.size());
		for (auto const &x : key)
			push_back(x);
		return *this;
	}

	mvector& push_front(int const &a) {
		linsert(0, 1);
		list[0] = a;
		return *this;
	}

	mvector& push_front(std::initializer_list<int> const &a) {
		linsert(a.size());
		int i = 0;
		for (auto const &g : a)
			list[i++] = g;
		return *this;
	}

	mvector insert(int n, std::initializer_list<int> a) {
		linsert(n, a.size());
		int i = n;
		for (auto const &x : a)
			list[i++] = x;
	}

	~mvector() {
		if (list){
			delete[] list;
			list = nullptr;
		}
	}
private:
	void linsert(int const &n,int const &count = 1) {//It can clear a room for a new data
		init(count);
		for (int i = size + count - 1; i > n; --i)
			list[i] = list[i - count];
	}
	void init(int const &n) {//appear n byte for the mvector
		bool flag = 0;
		size += n;
		while (size > maxsize)
		{
			maxsize *= 2;//The size of the new pointer
			flag = 1;
		}
		while (size <= maxsize / 4) {//The maxsize is too big
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
	size_t size;
	size_t maxsize;
};
