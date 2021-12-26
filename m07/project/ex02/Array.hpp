#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <exception>

template <typename T>
class Array {
public:

/* Constructors/Destructors */

	Array<T>() : _table(NULL), _size(0) {}

	Array<T>(unsigned int n) : _size(n) {
		_table = new T[n]();
	}

	Array<T>(const Array<T>& from) : _size(from.size()) {
		_table = new T[from.size()];
		for (unsigned int i = 0; i < _size; i++) {
			_table[i] = from[i];
		}
	}

	~Array<T>() {
		if (_table) {
			delete [] _table;
		}
	}

/* Operators */

	Array<T>& operator=(const Array<T>& rhs) {
		if (this == &rhs) {
			return *this;
		}

		delete [] _table;

		_table = new T[rhs.size()];
		_size = rhs.size();
		for (unsigned int i = 0; i < _size; i++) {
			_table[i] = rhs[i];
		}
		return *this;
	}

	T& operator[](unsigned int index) {
		if (index >= _size) {
			throw std::exception();
		}
		return _table[index];
	}

	const T& operator[](unsigned int index) const {
		if (index >= _size) {
			throw std::exception();
		}
		return _table[index];
	}

/* Methods */

	unsigned int size() const {
		return _size;
	}

private:
/* Attributes */

	T* _table;
	unsigned int _size;

};

#endif /* ARRAY_HPP */
