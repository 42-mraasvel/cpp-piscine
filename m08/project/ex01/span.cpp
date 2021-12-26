#include "span.hpp"
#include <vector>
#include <numeric>
#include <algorithm>

/* Constructors/Destructors */
Span::Span()
:
_size(0),
_capacity(0),
_duplicate(false) {}

Span::Span(unsigned int N)
:
_size(0),
_capacity(N),
_duplicate(false) {}

Span::Span(const Span& from) {
	*this = from;
}

Span::~Span() {}

/* Operators */
Span& Span::operator=(const Span& rhs) {
	if (this == &rhs) {
		return *this;
	}
	_size = rhs.size();
	_capacity = rhs.capacity();
	_duplicate = rhs._duplicate;
	_table = rhs._table;
	return *this;
}

/* Methods */

/* Span Functions */
unsigned int Span::shortestSpan() const {
	if (_size <= 1) {
		throw InsufficientDataException();
	} else if (_duplicate) {
		return 0;
	}

	std::vector<int> diff(_table.size());
	std::adjacent_difference(_table.begin(), _table.end(), diff.begin());
	return *std::min_element(diff.begin() + 1, diff.end());
}

unsigned int Span::longestSpan() const {
	if (_size <= 1) {
		throw InsufficientDataException();
	}

	std::set<int>::iterator last_element = _table.end();
	--last_element;
	return *last_element - *_table.begin();
}

/* Adder Functions */
void Span::addNumber(int n) {
	if (size() == capacity()) {
		throw FullArrayException();
	}

	std::pair<container::iterator, bool> result = _table.insert(n);
	if (!result.second) {
		_duplicate = true;
	}
	++_size;
}

void Span::addRange(int start, int end) {
	while (start <= end) {
		addNumber(start);
		++start;
	}
}

void Span::addRange(int end) {
	addRange(0, end);
}

/* Others */
unsigned int Span::size() const {
	return _size;
}

unsigned int Span::capacity() const {
	return _capacity;
}

/* Exceptions */
const char* Span::FullArrayException::what() const throw() {
	return "array is at full capacity";
}

const char* Span::InsufficientDataException::what() const throw() {
	return "insufficient members for operation";
}
