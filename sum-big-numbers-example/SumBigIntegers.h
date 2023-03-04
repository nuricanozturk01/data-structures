#include "LinkedList.h"
#include <vector>
#ifndef HW3_SUMBIGINTEGERS_H
#define HW3_SUMBIGINTEGERS_H

#define SIZE 103

class SumBigIntegers {


protected:

    LinkList<int> list[SIZE];

    vector<int> getResultNumberFormat(LinkList<int> list)
    {
        vector<int> number;
        vector<int> number2;
        Node<int> *p = list.head;

        for ( ; p != NULL ; p = p->next)
            number.push_back(p->data);
        for (int i = number.size() - 1 ; i != 0 ; --i)
            number2.push_back(number[i]);

        return number2;
    }

    void printSolution(LinkList<int> list)
    {
        vector<int> result = getResultNumberFormat(list);

        for (int i = 0 ; i < result.size() ; ++i)
            cout<<result[i];
        cout<<endl;
    }

    void sumIntegers()
    {
        LinkList<int> init;

        init = list[0].LinkListClone(init);

        LinkList<int> result;

        int tmp = 0 , sum = 0;

        for (int i = 1 ; i < SIZE ; i++)
        {
            Node<int> *p2 = list[i].head;
            Node<int> *p1 = init.head;

            while (p1 != NULL || p2 != NULL)
            {

                int n1 = p1 != NULL ? p1->data : 0;
                int n2 = p2 != NULL ? p2->data : 0;

                sum = tmp + n1 + n2;

                if (sum >= 10)
                    tmp = 1;
                else tmp = 0;

                sum %= 10;

                result.insertLast(sum);

                if(p1 != NULL)
                    p1 = p1->next;
                if (p2 != NULL)
                    p2 = p2->next;
            }


            if (tmp > 0)
                result.insertLast(tmp);

            init =  result.LinkListClone(init);

            result.head = NULL;

        }
        printSolution(init);
    }

};


#endif //HW3_SUMBIGINTEGERS_H
