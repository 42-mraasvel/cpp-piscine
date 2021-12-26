#ifndef STREAM_EDITOR_HPP
# define STREAM_EDITOR_HPP

# include <string>
# include <fstream>

enum SedEnums {
	OK = 0,
	ERROR
};

class StreamEditor {

public:

	StreamEditor(const std::string& filename, const std::string& find, const std::string& replace);
	~StreamEditor();

	static void Sed(const std::string& filename, const std::string& find, const std::string& replace);
	void Execute();
	bool Good() const;

private:

	enum SedEnums _OpenFiles();
	void _ReplaceFile();
	std::string _ReplacedLine(const std::string& line) const;

	bool _failed;
	const std::string _filename;
	const std::string _find;
	const std::string _replace;

	std::ifstream _src_file;
	std::ofstream _dst_file; 

};

#endif /* STREAM_EDITOR_HPP */
