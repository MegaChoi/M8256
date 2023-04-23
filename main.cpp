#include <iostream>
#include <bitset>
#include <fstream>
#include <string>
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;
int main(int argc, char *argv[]) {
    // if there are no argument, argc == 1 means argument
    if (argc == 1) {
        cout << "no file found" << endl;
        return 1;
    }

    ifstream file(argv[1], ios::binary);
    // if cant open file 
    if(!file){
        cerr  << "Error Opening File" << endl;
    }
    std::ofstream output("output.txt", std::ios::trunc);
    if (!output) {
        std::cout << "Error opening output file!" << std::endl;
        return 1;
    }

    // get file size
    file.seekg(0, std::ios::end); //  set the file position indicator to the end of the file
    std::streampos fileSize = file.tellg(); // get the size in bytes
    file.seekg(0, std::ios::beg); // reset position indicator


    const int chunkSize = 1024; // read 1KB at a time
    char* buffer = new char[chunkSize];
    
    // read file data into buffer in chunks
    std::streampos bytesRead = 0;
    while (bytesRead < fileSize) {
        file.read(buffer, chunkSize);
        std::streamsize bytesJustRead = file.gcount(); // returns the number of characters read

        // do something with the buffer...
        for (int i = 0; i < bytesJustRead; i++) {
            char byte = buffer[i];
            int base10 = static_cast<int>(byte);
            output << base10 << " " << base10 << " " << base10 << "\n";
        }

        bytesRead += bytesJustRead;
    }

    // Read the RGB values from a file
    ifstream infile("output.txt");
    vector<Vec3b> rgb_values;
    int r, g, b;
    while (infile >> r >> g >> b)
    {   std::cout<< r << g << b << endl;
        rgb_values.push_back(Vec3b(r, g, b));
    }

    // Create an image with the same size as the number of RGB values
    Mat img(rgb_values.size(), 1, CV_8UC3);

    // Set the color of each pixel to the corresponding RGB value
    for(int i = 0; i < img.rows; i++)
    {
        img.at<Vec3b>(i, 0) = rgb_values[i];
    }

    // Save the image
    imwrite("output.jpg", img);
    return 0;
} 







