#ifndef Utils_h
#define Utils_h
#include <iostream>
#include <bitset>
#include <fstream>
#include <string>
#include <memory>
#include <sstream>

using namespace std;

class Utils{
    private:
        Utils();

    public:

        static unique_ptr<ifstream> OpenFile(const string&  filename);

        static unique_ptr<ofstream> WriteFile(const string&  filename);

        static bool ReadInput(string& a, string& b, string& c);
        static void EncodeRBG(unique_ptr<ifstream> & file, unique_ptr<ofstream> & output);
        static void EncodeGrayscale(unique_ptr<ifstream> & file, unique_ptr<ofstream> & output);
};

#endif