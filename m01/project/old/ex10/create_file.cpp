#include <iostream>
#include <fstream>

using namespace std;

int main(void) {

	const char *OUTFILE = "binary.file";
	const int SIZE = 256;

	unsigned char ASCII[SIZE];
	for (int i = 0; i < SIZE; i++) {
		ASCII[i] = i;
	}
	ofstream ofs;

	ofs.open(OUTFILE, ios::binary | ios::out);
	ofs.write((const char *)ASCII, SIZE);
	ofs.close();

	ifstream ifs;
	ifs.open(OUTFILE, ios::in | ios::binary);
	unsigned char buffer[1];
	while (ifs.read((char *)buffer, 1)) {
		cout << (int)buffer[0];
	}
	ifs.close();
	return 0;
}
