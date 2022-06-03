#include <bits/stdc++.h>

using namespace std;

int main(){
    vector<int> hole;
    int balls;
    cin >> balls;
    int ball[balls];
    for(int i = 0; i < balls; ++i){
        int counter = 2;
        cin >> ball[i];

        hole.push_back(ball[i]);
        for(int j = hole.size(); j > 0; --j){
            if(ball[i] == hole[j - 2])
            {
                if(counter == ball[i])
                {
                    int remain = hole.size() - counter;
                    hole.resize(remain);
                    cout << remain << endl;
                    break;
                }
                counter += 1;
            }
            else
            {
                cout << hole.size() << endl;
                break;
            }
        }
    }
    return 0;
}
