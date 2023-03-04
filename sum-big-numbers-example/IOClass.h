#ifndef HW3_IOCLASS_H
#define HW3_IOCLASS_H

#include "SumBigIntegers.h"
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>

using namespace std;

class IOClass : public SumBigIntegers{
private:
    string path;

private:
    void readFile(string path)
    {
        ifstream readFile;
        readFile.open(path);

        if (!readFile.is_open())
        {
            cerr << "[!] FILE IS NOT OPENED!" << endl;
            exit(EXIT_FAILURE);
        }

        string line;
        string number;

        for (int i = 0 ; getline(readFile, line) ; ++i )
        {
            stringstream line_stream(line);
            getline(line_stream , number  );

            for (int j = 0 ; j < number.size() ; ++j)
                list[i].insertFirst(abs( 0x30 - number[j] ) );

        }

        readFile.close();

    }



public:

    // Constructor
    IOClass(string path)
    {
        this->path = path;
        readFile(path);
    }

    // Trigger Function
    void run()
    {
        sumIntegers();
    }
};


#endif //HW3_IOCLASS_H
