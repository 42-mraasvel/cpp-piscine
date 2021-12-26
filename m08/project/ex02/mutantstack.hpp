#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> {
private:

	typedef std::stack<T> stack_t;

public:

/* Constructors/Destructors */
	MutantStack() : std::stack<T> () {}
	MutantStack(const MutantStack& from)
		: std::stack<T>(from) {}
	virtual ~MutantStack() {}

/* Operators */
	MutantStack& operator=(const MutantStack& rhs) {
		if (this == &rhs)
			return *this;
		std::stack<T>::operator=(rhs);
		return *this;
	}

/* Iterators */
	typedef typename Container::iterator iterator;
	typedef typename Container::const_iterator const_iterator;
	typedef typename Container::reverse_iterator reverse_iterator;
	typedef typename Container::const_reverse_iterator const_reverse_iterator;

/* Forward Iterators */
	iterator begin() {
		return stack_t::c.begin();
	}

	iterator end() {
		return stack_t::c.end();
	}

	const_iterator cbegin() const {
		return stack_t::c.begin();
	}

	const_iterator cend() const {
		return stack_t::c.end();
	}

/* Reverse Iterators */
	reverse_iterator rbegin() {
		return stack_t::c.rbegin();
	}

	reverse_iterator rend() {
		return stack_t::c.rend();
	}

	const_reverse_iterator crbegin() const {
		return stack_t::c.rbegin();
	}

	const_reverse_iterator crend() const {
		return stack_t::c.rend();
	}
};

#endif /* MUTANTSTACK_HPP */
