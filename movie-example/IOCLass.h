#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include "Movies.h"

#ifndef HW1_OICLASS_H
#define HW1_OICLASS_H

using namespace std;

class IOCLass : public Movies{
private:

    void getMenu()
    {
        cout <<"---------------------------------------------------------"<<endl;
        cout << "Welcome to the Movie Market. Please select an option."<<endl
             <<"1 - Get movie details by ID"<<endl
             <<"2 - List movies between the years entered"<<endl
             <<"3 - Change the point of a movie"<<endl
             <<"4 - Get movie details starting with the entered letter"<<endl
             <<"5 - Exit"<<endl
             <<"6 - Print Movies"<<endl
             <<"7 - Vote"
             <<endl;
        cout <<"---------------------------------------------------------"<<endl;
    }

    // Read the file
    void readFile()
    {
        ifstream readFile;
        readFile.open("C:\\Users\\msi\\CLionProjects\\hw1\\movies.txt");

        if (!readFile.is_open())
        {
            cerr << "FILE IS NOT OPENED!" << endl;
            exit(EXIT_FAILURE);
        }

        string line;
        string name;
        string point;
        string year;

        while (getline(readFile, line))
        {
            stringstream line_stream(line);

            getline(line_stream, point, ';');
            getline(line_stream, name, '(');
            getline(line_stream, year, ')');

            float floatPoint = stof(point);
            int intYear = stoi(year);

            addMovie(Movies(name, floatPoint, intYear));


        }
        readFile.close();

    }

protected:
    void init(int choice)
    {
        switch (choice)
        {
            case 1:
            {
                int n ;
                cout <<"Enter n: "<<endl;
                cin >> n;
                getMovieDetailsById(n);
                break;
            }
            case 2:
            {
                int y1 , y2;
                cout <<"Enter the year1"<<endl;
                cin>>y1;
                cout <<"Enter the year2"<<endl;
                cin>>y2;
                listMoviesByYears(y1,y2);
                break;
            }
            case 3:
            {
                int idNumber;
                float newPoint;
                cout << "Enter the ID number"<<endl;
                cin >>idNumber;
                cout << "Enter the new Point"<<endl;
                cin >> newPoint;
                changePoint(idNumber, newPoint);
                break;
            }
            case 4:
            {
                char c;
                cout <<"Enter the character: "<<endl;
                cin >>c;
                getStartingLetter(c);
                break;
            }

            case 5:
            {
                cout << "EXIT!"<<endl;
                exit(1);
            }
            case 6:
            {
                printMovies();
                break;
            }
            case 7:
            {
                float votee;
                int idd;
                cout << "Enter the movie ID: "<<endl;
                cin >> idd;
                cout << "Enter the vote"<<endl;
                cin >> votee;
                vote(idd,votee);
                break;
            }
        }
    }




public:
    IOCLass()
    {
        readFile();
    }

    // First trigger function
    void run()
    {
        int choice ;

        do {
            getMenu();
            cout <<"ENTER THE OPERATION:"<<endl;
            cin >> choice;
            if (choice <= 0 || choice > 7)
                break;
            init(choice);

        }
        while(true);

    }


};


#endif //HW1_OICLASS_H
