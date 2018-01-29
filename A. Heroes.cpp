#include <bits/stdc++.h>

using namespace std;
int a,b,c;
bool liking[7][7];
vector <int> arr[3];
vector <pair <int,int> > sorted;

void rec (int n){
    if (n == 7){
        if (!arr[0].empty() && !arr[1].empty() && !arr[2].empty()){
            int xp0,xp1,xp2, max, min, likes=0;
            xp0 = a / arr[0].size();
            xp1 = b / arr[1].size();
            xp2 = c / arr[2].size();
            xp0 > xp1? (xp0 > xp2? max = xp0 : max = xp2) : (xp1 > xp2? max=xp1 : max=xp2);
            xp0 < xp1? (xp0 < xp2? min = xp0 : min = xp2) : (xp1 < xp2? min=xp1 : min=xp2);
            for (int i=0; i<7; i++){
                for (int j=0; j<7; j++){
                    if (liking[i][j] ) {
                        if ( ( find(arr[0].begin(), arr[0].end(), j) != arr[0].end() && find(arr[0].begin(), arr[0].end(), i) != arr[0].end() )  ||
                             ( ( find(arr[1].begin(), arr[1].end(), j) != arr[1].end() ) && ( find(arr[1].begin(), arr[1].end(), i) != arr[1].end() ) ) ||
                             ( ( find(arr[2].begin(), arr[2].end(), j) != arr[2].end() ) && ( find(arr[2].begin(), arr[2].end(), i) != arr[2].end() ) ) )
                        likes++;
                    }
                }
            }
            sorted.push_back(make_pair(max-min, -likes));
        }
        return;
    }
        arr[0].push_back(n);
        rec(n+1);
        arr[0].pop_back();
        arr[1].push_back(n);
        rec(n+1);
        arr[1].pop_back();
        arr[2].push_back(n);
        rec(n+1);
        arr[2].pop_back();
}

int main()
{
    memset(liking, 0, sizeof liking);
    int n, x, y;
    string p, likes,q ;
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> p >> likes >> q;
        if (p == "Anka") x=0;
        else if (p == "Chapay") x=1;
        else if (p == "Cleo") x=2;
        else if (p == "Troll") x=3;
        else if (p == "Dracul") x=4;
        else if (p == "Snowy") x=5;
        else x=6;
        if (q == "Anka") y=0;
        else if (q == "Chapay") y=1;
        else if (q == "Cleo") y=2;
        else if (q == "Troll") y=3;
        else if (q == "Dracul") y=4;
        else if (q == "Snowy") y=5;
        else y=6;
        liking[x][y] = true;
    }
    cin >> a >> b >> c;
    rec (0);
    sort(sorted.begin(), sorted.end());
    cout << sorted.front().first << " " << -sorted.front().second ;
}