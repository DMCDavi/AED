#include <iostream>
#include <cstring>
#include <list>

using namespace std;

typedef struct
{
    string name;
    char region;
    int distance;
} STUDENT;

int main()
{
    STUDENT student;
    list<STUDENT> listStudent;
    list<STUDENT>::iterator it;
    int num_students;
    bool insert_end;
    while (cin >> num_students)
    {
        for (int i = 0; i < num_students; i++)
        {
            cin >> student.name >> student.region >> student.distance;
            if (listStudent.empty())
                listStudent.push_back(student);
            else
            {
                insert_end = true;
                for (it = listStudent.begin(); it != listStudent.end(); it++)
                {

                    if (it->distance == student.distance)
                    {
                        if (it->region == student.region)
                        {
                            if (it->name.compare(student.name) >= 0)
                            {
                                listStudent.insert(it, student);
                                insert_end = false;
                                break;
                            }
                        }
                        else if (it->region > student.region)
                        {
                            listStudent.insert(it, student);
                            insert_end = false;
                            break;
                        }
                    }
                    else if (it->distance > student.distance)
                    {
                        listStudent.insert(it, student);
                        insert_end = false;
                        break;
                    }
                }
                if (insert_end)
                    listStudent.push_back(student);
            }
        }
        for (it = listStudent.begin(); it != listStudent.end(); it++)
        {
            cout << it->name << endl;
        }
        listStudent.clear();
    }

    return 0;
}