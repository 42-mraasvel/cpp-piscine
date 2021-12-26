#ifndef STREAM_EDITOR_HPP
# define STREAM_EDITOR_HPP

# include <fstream>
# include <string>

class StreamEditor {

public:

	StreamEditor();
	StreamEditor(std::string filename, std::string find, std::string replace);
	~StreamEditor();

	static void FileFindAndReplace(std::string filename, std::string find, std::string replace);
	bool SedFailed() const;

private:


	void _Replace();
	std::string _GenerateReplacement();
	void _FindReplaceString(std::string& line) const;
	void _WriteToFile(std::string& new_file);

	void _Error(std::string msg);
	bool _failed;

	const std::string _filename;
	const std::string _find;
	const std::string _replace;

};

#endif /* STREAM_EDITOR_HPP */
