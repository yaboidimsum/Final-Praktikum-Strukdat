#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

int main()
{
    int query;
    char cd[10];

    string input;
    cin >> query;
    vector<string> path = {"home", "anton"};

    while (query--)
    {
        cin >>cd;
        if (!strcmp(cd, "goto"))
        {
            cin >> input;
            path.push_back(input);
        }

        else if (!strcmp(cd, "whereami"))
        {
            if (path.size() != 0)
            {
                for (int i = 0; i < path.size(); i++)
                {
                    cout << path[i];
                    if (i != path.size() - 1)
                         cout <<"/";
                }
                printf("\n");
            }
            else
            {
                cout << "i am nowhere";
                cout << "\n";
            }
        }

        else if (!strcmp(cd, "goback"))
        {
            if (path.size() == 0)
            {
                 cout <<"cannot go back";
                 cout <<"\n";
            }
            else
                path.pop_back();
        }
        else
        {
             cout <<"Query not found";
             cout <<"\n";
        }
    }
    return 0;
}
