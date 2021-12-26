#ifndef DATA_HPP
# define DATA_HPP

# include <string>

# ifdef __MAC__
# include <cstdint>
# else
typedef unsigned long uintptr_t;
# endif /* __MAC__ */

typedef struct Data {
	std::string str1;
	int n;
	std::string str2;
} Data;


uintptr_t serialize(Data* ptr);
Data* deserialize(uintptr_t raw);

#endif /* DATA_HPP*/
