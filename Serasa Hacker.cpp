#include<bits/stdc++.h>

typedef unsigned long long ull;

using namespace std;

int main(){
     ull n;
     set<ull> hack;

     while(scanf("%llu", &n) != EOF)
        {
         if(hack.count(n))
         {
            ull ans = 7312; //ans adalah angka random dari 1-10000
                             //berada di atas 5000
            ull x = n % 10001;
            if(x < ans) printf("<\n");
            if(x ==ans)
            printf("==\n");
            if(x > ans) printf(">\n");
         }
         else hack.insert(n);
     }
    return 0;
}
