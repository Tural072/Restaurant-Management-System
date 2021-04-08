#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
class FileHelper
{
public:
    static void Append_file_in_text_format(const string& file_name, const string& text) {
        ofstream fout(file_name, ios_base::app);
        if (fout.is_open())
            fout << text;
        else
            cout << "File could not be opened!\n";
        fout.close();
    };



};