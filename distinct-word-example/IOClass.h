
//18070006034 Nuri Can ÖZTÜRK


#ifndef HW4_IOCLASS_H
#define HW4_IOCLASS_H

#include <fstream>
#include <sstream>

using namespace std;


#include "Word.h"
class IOClass : public Word{

private:
    string path;


    string setValid(string str)
    {
        for (int i = 0 ; i < str.size() ; ++i)
            if (isupper(str[i]))
                str[i] += 32;
        return str;
    }
    bool valid(char c)
    {
        return c == ',' || c == '.' || c == '?' || c == '\n' || c == '\r' ;
    }
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

        string str;

        for (int i = 0 ; getline(readFile, line) ; ++i )
        {

            stringstream line_stream(line);
            getline(line_stream , str);
            string s;

            for (int k = 0 ; k < str.size() ; ++k)
            {
                if (isalpha(str[k]) )
                    s += str[k];
                if (str[k] == ' ' || valid(str[k]) || k == str.size() - 1)
                {
                    list.insertLast(setValid(s));
                    s.clear();
                }
            }

        }
        readFile.close();

    }



    // write File

    void writeFile(BinaryTreeNode<string> *p)
    {
        ofstream write;
        write.open("output.txt",ios::app);
        write << p->count << "\t\t" << p->data<<endl;

    }



// Travels tree
    void InOrderTravels(BinaryTreeNode<string> *p) override
    {
        if (p == NULL)
            return;
        InOrderTravels(p->left);
        writeFile(p);
        InOrderTravels(p->right);
    }


public:

    IOClass(string path)
    {
        this->path = path;
    }
    void run()
    {
        readFile(path);
        getDistinctWords();

    }

};


#endif //HW4_IOCLASS_H
