#ifndef Utils_h
#define Utils_h
#include <iostream>
#include <bitset>
#include <fstream>
#include <string>
#include <memory>
using namespace std;

class Utils{
    private:
        Utils();

    public:

        static unique_ptr<ifstream> OpenFile(const char* filename);

        static unique_ptr<ofstream> WriteFile(const char* filename);

        static void EncodeRBG(unique_ptr<ifstream> & file, unique_ptr<ofstream> & output);
};

#endif