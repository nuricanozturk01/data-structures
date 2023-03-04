//
// Created by msi on 14.10.2021.
//
#include <vector>
#include <string>
#include <iostream>


#ifndef HW1_MOVIES_H
#define HW1_MOVIES_H

using namespace std;

class Movies{

private:
    vector <Movies> movies;
    static int id ;
    string name;
    float point;
    int year;
    int ID;

    vector<float> votes;
   float averageVote;



protected:



    string toString()
    {
        cout << "----------------------------------------------------" << endl;
        return "ID: " + to_string(ID) + "\nName: " + getName() + "\nPoint: " + to_string(getPoint()) + "\nYear: " + to_string(getYear()) +"\n";

    }

    int getYear()
    {
        return year;
    }

    int getID()
    {
        return ID;
    }

    float getPoint()
    {
        return point;
    }

    void setPoint(float newPoint)
    {
        point = newPoint;
    }

    string getName()
    {
        return name;
    }


    // Add the movies vector
    void addMovie(Movies movie)
    {
        movies.push_back(movie);
    }



    static void printMovies(vector<Movies> movie)
    {
        for (int i = 0 ; i < movie.size() ; ++i)
            cout<<movie[i].toString()<<endl;
    }



    // Print Movies
    void printMovies()
    {
        for (int i = 0; i < movies.size(); ++i)
            cout << movies[i].toString();
    }



    //List movies between the years entered
    void listMoviesByYears(int year1 , int year2)
    {
        vector <Movies> mov;

        for (int i = 0 ; i < movies.size() ; ++i)
            if (movies[i].getYear() >= year1 && movies[i].getYear() <= year2 )
                mov.push_back(movies[i]);
        cout<<"----------------------BETWEEN "<<year1<<" - "<<year2<<" ----------------------"<<endl;
        printMovies(mov);
        cout<<"----------------------BETWEEN "<<year1<<" - "<<year2<<" ----------------------"<<endl;
    }


    //Change the point of a movie
    void changePoint(int  id , float point)
    {
        Movies m = movies[id -1];
        m.setPoint(point);
        movies[id - 1].setPoint(point);
        cout << movies[id - 1].toString();

    }





    //Get movie details starting with the entered letter
    void getStartingLetter(char chr)
    {
        vector<Movies> mov;
        for (int i = 0 ; i < movies.size() ; ++i)
            if(movies[i].getName()[0] == chr)
                mov.push_back(movies[i]);
        cout << "---------------START WITH "<<chr<<" ---------------"<<endl;
        printMovies(mov);
        cout << "---------------START WITH "<<chr<<" ---------------"<<endl;
    }




    //Get movie details by ID
    void getMovieDetailsById(int n)
    {
        Movies m;

        for (int i = 0 ; i < movies.size() ; ++i)
            if (movies[i].getID() == n)
                m = movies[i];
        cout << m.toString()<<endl;
    }


//--------------------------------------------------------------------------------
    float sumOfVotes()
    {
        float sum = 0;
        for (int i = 0 ; i < votes.size() ; sum += votes[i] , ++i);
        return sum;
    }
    void vote(int id , float vote)
    {
        if (vote > 10 || vote < 1)
            return;
        if (votes.size() > 10)
            return;
        votes.push_back(vote);
        if (votes.size() == 1)
            averageVote = (point + vote) / 2;


       else averageVote = sumOfVotes() / votes.size();


        movies[id - 1].setPoint(averageVote);

    }
//--------------------------------------------------------------------------------

public:


    Movies()
    {

    }

    Movies(string name , float point , int year)
    {
        this->name = name;
        this->point = point;
        this->year = year;
        ID = id++;
    }



};


#endif //HW1_MOVIES_H
