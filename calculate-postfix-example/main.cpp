

#include "stack.h"
#include <fstream>
#include <sstream>
#include <math.h>
#include <string>
#include "vector"

vector<string> getStrVector(string str);
bool isOperand(string str);



vector<string> readFile()
{
    vector<string> list;
    ifstream file ;
    file.open("C:\\Users\\msi\\CLionProjects\\COMP 2310\\hw2\\equations.txt")  ;

    if (!file.is_open())
    {
        cerr<< "File is not opened! "<<endl;
        exit(EXIT_FAILURE);
    }
    string line;


    string eq;
    while (getline(file, line)) {
        stringstream line_stream(line);
        getline(line_stream,eq,'\n');
        list.push_back(eq);
    }

    file.close();
    return list;

}
bool isOperator(char c)
{
    return (c == '^' || c == '*' || c == '/' || c == '+' || c == '-');
}
bool isOperator(string c)
{
    return (c == "^" || c == "*" || c == "/" || c == "+" || c == "-");
}



float calculator(float  val1 , float  val2 , string ch)
{
    float num;
    if (ch == "^")
        num = pow(val1,val2);
    if (ch == "*")
        num =  ((val1) * (val2));
    if (ch == "/")
        num =  val1 / val2;
    if (ch == "+")
        num =  val1 + val2;
    if (ch == "-")
        num =  val1 - val2;
    return num;
}
float calculatePostfix(string str)
{

    Stack<float> stack;
    vector<string> vector = getStrVector(str);


    for (int i = 0 ; i < vector.size() ; ++i)
    {
        if (!isOperator(vector[i]))
            stack.push(stof(vector[i]));

        else
        {

            float val1 = stack.pop();
            float val2 = stack.pop();

            float  result = calculator(val2 , val1 , vector[i]);
            stack.push(result);
        }
        //stack.printStack();
    }
    return stack.pop();
}






vector<string> delEmpty(vector<string> v)
{
    vector<string> n;

    for (int i = 0 ; i < v.size() ; ++i)
        if (v[i] != "" && v[i] != " ")
            n.push_back(v[i]);
    return n;
}
vector<string> getStrVector(string str)
{
    vector<string> v;
    string help;
    string tmp;

    for (int i = 0 ; i < str.size() ; ++i)
    {
        if (isOperator(str[i]))
            tmp = str[i];

        if (str[i] != ';' && !isOperator(str[i]))
            help += str[i];
        else
        {
            v.push_back(help);
            v.push_back(tmp);
            help.clear();
            tmp.clear();
        }

    }
    return delEmpty(v);
}

int main()
{
    vector<string> list;
    list = readFile();

    for (int i = 0 ; i < list.size() ; ++i)
    {
        cout<<list[i]<<endl;
        cout<<"  Answer: "<<calculatePostfix(list[i])<<endl;
    }

    return 0;
}
