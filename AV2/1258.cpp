#include <iostream>
#include <cstring>
#include <list>

using namespace std;

typedef struct
{
    string name, color;
    char size;
} SHIRT;

int main()
{
    SHIRT shirt;
    list<SHIRT> listAnswer;
    list<SHIRT> listShirt;
    list<SHIRT>::iterator it;
    int num_shirts;
    bool insert_end;
    while (cin >> num_shirts)
    {
        if (num_shirts == 0)
        {
            //POG para resolver presentation error
            listAnswer.pop_back();
            break;
        }
        for (int i = 0; i < num_shirts; i++)
        {
            cin.ignore();
            getline(cin, shirt.name);
            cin >> shirt.color >> shirt.size;
            if (listShirt.empty())
                listShirt.push_back(shirt);
            else
            {
                insert_end = true;
                for (it = listShirt.begin(); it != listShirt.end(); it++)
                {

                    if (it->color.compare(shirt.color) == 0)
                    {
                        if (it->size == shirt.size)
                        {
                            if (it->name.compare(shirt.name) >= 0)
                            {
                                listShirt.insert(it, shirt);
                                insert_end = false;
                                break;
                            }
                        }
                        else if (it->size < shirt.size)
                        {
                            listShirt.insert(it, shirt);
                            insert_end = false;
                            break;
                        }
                    }
                    else if (it->color.compare(shirt.color) >= 0)
                    {
                        listShirt.insert(it, shirt);
                        insert_end = false;
                        break;
                    }
                }
                if (insert_end)
                    listShirt.push_back(shirt);
            }
        }
        for (it = listShirt.begin(); it != listShirt.end(); it++)
        {
            listAnswer.push_back(*it);
        }
        //POG para resolver presentation error
        shirt.size = NULL;
        listAnswer.push_back(shirt);
        listShirt.clear();
    }
    for (it = listAnswer.begin(); it != listAnswer.end(); it++)
    {
        if (it->size != NULL)
            cout << it->color << ' ' << it->size << ' ' << it->name << endl;
        else
            cout << '\n';
    }
    return 0;
}