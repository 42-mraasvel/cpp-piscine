#ifndef PONY_HPP
# define PONY_HPP

# include <string>

void ponyOnTheHeap(void);
void ponyOnTheStack(void);

class Pony {

public:

	Pony(); // Constructor
	Pony(int height, int weight, std::string name, std::string breed);
	~Pony(); // Destructor


	void DisplayStatus(void);
	void DoStuff(void);

	/* Accessors */
	int GetHeight(void);
	int GetWeight(void);
	std::string GetName(void);
	std::string GetBreed(void);

	/* Non-member Methods */
	static int GetInstanceCount(void);

private:

	/* Non-member Attributes */
	static int _instance_count;

	/* What attributes does a pony have? */
	int _height; /* centimeters */
	int _weight; /* Kilograms */
	std::string _name;
	std::string _breed;
	bool _tired;

};

#endif /* PONY_HPP */
