#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    int num_entries, num_letters, index[2];
    string letters, ordered_letters;
    char aux;
    cin >> num_entries;
    if (num_entries >= 1 && num_entries <= 100)
    {
        for (int i = 0; i < num_entries; i++)
        {
            ordered_letters.clear();
            index[0] = 0;
            index[1] = 0;
            bool equal = true;
            int j = 0;
            cin >> num_letters >> letters;
            if (num_letters >= 2 && num_letters <= 26)
            {
                for (int i = 'A'; i < 'A' + num_letters; i++)
                {
                    ordered_letters.push_back(i);
                }
                for (int i = 0; i < num_letters; i++)
                {
                    if (letters[i] != ordered_letters[i])
                    {
                        equal = false;
                        index[j] = i;
                        j++;
                        if (j == 2)
                            break;
                    }
                }
                //armazena numa variavel auxiliar o primeiro char que sera substituido
                aux = letters[index[0]];
                //troca as letras
                letters[index[0]] = letters[index[1]];
                letters[index[1]] = aux;
                if (letters.compare(ordered_letters) == 0 && !equal)
                    cout << "There are the chance." << endl;
                else
                    cout << "There aren't the chance." << endl;
            }
        }
    }

    return 0;
}