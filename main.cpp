#include <iostream>
#include <vector>
#include "string.h"
#include <algorithm>
#include <cstring>
using namespace std;
const int arrSize = 2048;
const int vecSize = 5;
void exListShow();
void myList();
void sorting(vector<String*> vec);

int main()
{
   int answer = 0;
   vector<String*> vec;
   cout << "Выберите подходящий для вас вариант: " <<endl;
   cout << "1 - Ввести свой список строк" << endl;
   cout << "2 - Ввести заранее заготовленный список строк" << endl;
   cin >> answer;
   cout << "\n";
   switch (answer) {
   case 1:
      myList();
       break;
   case 2:
       exListShow();
        break;
   default:
       cout << "Нет такого варианта ответа!" << endl;

   }
   return 0;
}

void exListShow()
{   int secondAnswer = 0;

    int sizeEx = 5;
    const char * ex[] = {"Natasha", "Alena", "Marina", "Irina", "Nastya"};
    vector<String*> exVec;

    for(int i = 0; i < sizeEx; i++)
    {
        exVec.push_back(new String(ex[i]));
    }

    const char *problem[] = {"Работы нет", "Бросила девушка", "Денег нет", "Зрение падает", "Будущего нет"};
    int sizeProblem = 5;
    vector<String*> problemVec;

    for(int i = 0; i < sizeProblem; i++)
    {
        problemVec.push_back(new String(problem[i]));
    }

    cout << "1 - Cписок твоих бывших" << endl;
    cout << "2 - Список твоих проблем" << endl;
    cin >> secondAnswer;
    cout <<"\n";
    switch (secondAnswer)
    {
    case 1:
        cout << "Вот этот список: " << endl;
        for (int i = 0; i < sizeEx; i++)
        {
            cout << exVec.at(i)->str << endl;
        }
        sorting(exVec);
        break;
    case 2:
        cout << "Вот этот список: " << endl;
        for (int i = 0; i < sizeProblem; i ++)
        {
            cout << problemVec.at(i)->str << endl;
        }
        sorting(problemVec);
        break;
    default:
        cout << "Нет такого варианта ответа" << endl;

    }

    return;
}

void myList()
{   vector<String*> vec;
    char s[arrSize];
    cout << "Начинай вводить строки: " << endl;
    for (int i = 0; i < 5; i++)
    {
        cin.getline(s, arrSize);
        vec.push_back(new String(s));
    }
    sorting(vec);
    return;
}

void sorting(vector<String*> vec)
{
    cout << "\n\n";
    cout << "А это этот же список после сортировки: " << endl;
    // сортировка строк

    int size = vec.size();

    for (int i = 0; i < size; i++)
    {
        for (int j = i+1; j < size; j++)
        {
            if ( strcmp(vec.at(i)->str, vec.at(j)->str) > 0)
            {
                char * tmp = vec.at(i)->str;
                vec.at(i)->str = vec.at(j)->str;
                vec.at(j)->str = tmp;
            }
        }
    }

    for (int i = 0; i < size; i++)
    {
        cout << vec.at(i)->str << endl;
    }
    return;
}
