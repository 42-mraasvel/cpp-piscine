#ifndef SPAN_HPP
# define SPAN_HPP

# include <exception>
# include <set>

class Span {
private:

	typedef std::set<int> container;

public:
/* Constructors/Destructors */
	Span();
	Span(unsigned int N);
	Span(const Span&);
	~Span();

/* Operators */
	Span& operator=(const Span&);

/* Methods */
	unsigned int shortestSpan() const;
	unsigned int longestSpan() const;

	void addNumber(int n);
	void addRange(int start, int end);
	void addRange(int end);

	template <typename InputIterator>
	void addRange(InputIterator first, InputIterator last) {
		while (first != last) {
			addNumber(*first);
			++first;
		}
	}

	unsigned int size() const;
	unsigned int capacity() const;

private:
/* Exceptions */
	class FullArrayException : public std::exception {
	public:
		virtual const char* what() const throw();
	};

	class InsufficientDataException : public std::exception {
	public:
		virtual const char* what() const throw();
	};

/* Attributes */
	unsigned int _size;
	unsigned int _capacity;
	bool _duplicate;
	std::set<int> _table;
};

#endif /* SPAN_HPP */
