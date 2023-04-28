#include "../headers/Utils.h"

Utils::Utils(){}

unique_ptr<ifstream> Utils::OpenFile(const char* filename){
    
    try{
        // open file
        unique_ptr<ifstream> file = make_unique<ifstream>(filename, ios::binary);
        // check file condition
        if(!file->is_open() && !file->good()){
            cerr  << "Error Opening File" << endl;
            return nullptr;
        }
        // return the file pointer
        return file;

    }
    catch (...){
        cerr  << "Error Opening File" << endl;
    }
    
    return nullptr;
}

unique_ptr<ofstream> Utils::WriteFile(const char* filename){
    try{
        // open file
        unique_ptr<ofstream> file = make_unique<ofstream>(filename);

        // check file condition
        if(!file->is_open() && !file->good()){
            cerr  << "Error Write File" << endl;
            return nullptr;
        }
        // return the file pointer
        return file;
    }
    catch (...){
        cerr  << "Error Opening File" << endl;
    }
    return nullptr;
}

void Utils::EncodeRBG(unique_ptr<ifstream> & file, unique_ptr<ofstream> &  output){
    try{
            // get the file size
            file->seekg(0, ios::end);
            streamsize size = file->tellg();
            file->seekg(0, ios::beg);

            // open binary file
            // unique_ptr<ofstream> binaryFile = Utils::WriteFile("out/binary.txt");

            // Read the file into a buffer
            char* buffer = new char[size];

            if (!file->read(buffer, size)) {
                cerr << "Error reading file\n";
                delete[] buffer;
                return;
            }

            // write 
            for (int i = 0; i < size; i+=3) {
                if (i+2 < size) {
                    *output << static_cast<unsigned int>(static_cast<unsigned char>(buffer[i])) << " " << static_cast<unsigned int>(static_cast<unsigned char>(buffer[i + 1]))<< " " << static_cast<unsigned int>(static_cast<unsigned char>(buffer[i + 2])) << "\n";
                    // *binaryFile << bitset<8>(static_cast<unsigned char>(buffer[i])) << " " << bitset<8>(static_cast<unsigned char>(buffer[i+1])) << " " << bitset<8>(static_cast<unsigned char>(buffer[i+2])) << "\n";
                } else if (i+1 < size) {
                    *output << static_cast<unsigned int>(static_cast<unsigned char>(buffer[i])) << " " << static_cast<unsigned int>(static_cast<unsigned char>(buffer[i + 1]))<< "\n";
                    // *binaryFile << bitset<8>(static_cast<unsigned char>(buffer[i])) << " " << bitset<8>(static_cast<unsigned char>(buffer[i+1])) << "\n";
                } else {
                    *output << static_cast<unsigned int>(static_cast<unsigned char>(buffer[i])) << "\n";
                    // *binaryFile << bitset<8>(static_cast<unsigned char>(buffer[i])) <<"\n";
                }
            }

            // Free the buffer and close the file
            delete[] buffer;
            file->close();
            // binaryFile->close();
            
    }catch(...){
        cerr << "Error reading file\n";
    }
}

void Utils::EncodeGrayscale(unique_ptr<ifstream> & file, unique_ptr<ofstream> &  output){
    try{
            // get the file size
            file->seekg(0, ios::end);
            streamsize size = file->tellg();
            file->seekg(0, ios::beg);

            // open binary file
            // unique_ptr<ofstream> binaryFile = Utils::WriteFile("out/binary.txt");

            // Read the file into a buffer
            char* buffer = new char[size];

            if (!file->read(buffer, size)) {
                cerr << "Error reading file\n";
                delete[] buffer;
                return;
            }

            // write 
            for (int i = 0; i < size; i+=3) {
                *output <<  bitset<8>(static_cast<unsigned char>(buffer[i])) <<  bitset<8>(static_cast<unsigned char>(buffer[i + 1]))<<  bitset<8>(static_cast<unsigned char>(buffer[i + 2])) << "\n";
            }

            // Free the buffer and close the file
            delete[] buffer;
            file->close();
            // binaryFile->close();
            
    }catch(...){
        cerr << "Error reading file\n";
    }
}