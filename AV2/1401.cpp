#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int num_entries;
	string word;
	cin >> num_entries;
	for (int i = 0; i < num_entries; i++)
	{
		cin >> word;
		sort(word.begin(), word.end());
		do
		{
			cout << word << endl;
		} while (std::next_permutation(word.begin(), word.end()));
		cout << '\n';
	}
	return 0;
}