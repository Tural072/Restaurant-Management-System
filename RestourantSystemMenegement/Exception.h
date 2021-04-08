#pragma once
#include <string>
using namespace std;
namespace Exception {
	class Exception
	{
		string text;
		int line;
		string file_name;
	public:
		Exception(const string& text, const int& line, const string& file_name) {
			setText(text);
			setLine(line);
			setFilename(file_name);
		};
		void setText(const string& text) {
			this->text = text;
		};
		string getText() const {
			return text;
		};
		void setLine(const int& line) {
			if (line >= 0) {
				this->line = line;
			}
		};
		int getLine() const {
			return line;
		};
		void setFilename(const string& file_name) {
			if (!file_name.empty()) {
				this->file_name = file_name;
			}
		};
		string getFilename() const {
			return file_name;
		};
		friend ostream& operator << (ostream& out, const Exception& exception);
	};
	class DataBaseException : public Exception
	{
	public:
		DataBaseException(const string& text, const int& line, const string& file_name)
			:Exception(text, line, file_name) {};
	};
	class InvalidArgumentException : public Exception
	{
	public:
		InvalidArgumentException(const string& text, const int& line, const string& file_name)
			:Exception(text, line, file_name) {};
	};
	ostream& operator << (ostream& out, const Exception& exception) {
		out << "Error text : " << exception.getText() << endl;
		out << "Error line : " << exception.getLine() << endl;
		out << "File name : " << exception.getFilename() << endl;
		return out;
	}
}