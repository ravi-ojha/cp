#include <bits/stdc++.h>

// Some constants that are frequently used
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007

// Something to print to console and debug
#define DEBUG false
#define CONSOLE(x) if(DEBUG) {cout << '>' << #x << ':' << x << endl;}

using namespace std;
#define MAXL 2000000

char res[MAXL];
vector< pair<int, int> > gohan;
int main() {
    int n;
    for(int i=0; i<MAXL; i++) {
        res[i] = '?';
    }

    scanf(" %d",&n);

    vector<string> v;
    for(int i=0; i<n; i++) {
        string s;
        cin >> s;
        int slen = s.size();
        int k;
        scanf(" %d",&k);
        v.push_back(s);
        for(int j=0; j<k; j++) {
            int x;
            scanf(" %d", &x);
            x--;
            gohan.push_back(make_pair(x, v.size()-1));
        }
    }

    sort(gohan.begin(), gohan.end());
    int glen = gohan.size();

    // for(int i=0; i<glen;i++) {
    //     cout << gohan[i].first << " " << gohan[i].second << endl;
    // }

    // vector< pair<int, string> > goku;
    // if(glen == 1) {
    //     goku.push_back(make_pair(gohan[0].first, gohan[0].second));
    // } else {

    //     for(int i=1; i<glen;i++) {
    //         if(gohan[i].first != gohan[i-1].first) {
    //             goku.push_back(make_pair(gohan[i-1].first, gohan[i-1].second));
    //         }
    //     }
    //     if(gohan[glen-1].first != gohan[glen-2].first) {
    //         goku.push_back(make_pair(gohan[glen-1].first, gohan[glen-1].second));
    //     }
    // }



    // for(int i=0; i<goku.size();i++) {
    //     cout << goku[i].first << " " << goku[i].second << endl;
    // }

    int done = 0;
    for(int i=0; i<gohan.size(); i++) {
        int s2len = v[gohan[i].second].size();

        int s2_i = 0;
        int idx = gohan[i].first;

        int begin = idx;
        if(idx < done) {
            s2_i = done - idx;
            begin = done;
        }
        int z;
        for(z=begin; s2_i<s2len; z++) {
            res[z] = v[gohan[i].second][s2_i];
            s2_i += 1;
        }
        done = z;
    }


    for(int i=0; i<done; i++) {
        if(res[i] != '?') {
            printf("%c", res[i]);
        } else {
            printf("a");
        }
    }
    return 0;
}


// The following solution is giving TLE
// char res[MAXL];
// int nxt[MAXL];
// int main() {
//     int n;
//     for(int i=0; i<MAXL; i++) {
//         res[i] = '?';
//         nxt[i] = i;
//     }
//     scanf(" %d",&n);
//     //printf("%s\n", res);
//     int mn = MAXL;
//     int mx = 0;
//     for(int i=0; i<n; i++) {
//         string s;
//         cin >> s;
//         int slen = s.size();
//         int k;
//         scanf(" %d",&k);
//         for(int j=0; j<k; j++) {
//             int x;
//             scanf(" %d", &x);
//             x--;
//             mn = min(mn, x);
//             mx = max(mx, x+slen);

//             int res_i = x;
//             int s_i = 0;
//             while(s_i < slen) {
//                 if(nxt[res_i] != res_i) {
//                     // This means that we have to make a jump
//                     // Which position to jump on is specified by nxt[res_i]

//                     // It is imp that we update s_i before res_i
//                     // Nahi to hum res_i ko loose kar baithenge
//                     s_i = s_i + nxt[res_i] - res_i;
//                     res_i = nxt[res_i];
//                 } else {
//                     // Update nxt
//                     nxt[res_i] = x+slen;

//                     res[res_i] = s[s_i];
//                     s_i += 1;
//                     res_i += 1;
//                 }
//             }
//         }

//         for(int z=0;z<MAXL;z++) {
//             printf(" %c", res[z]);
//         }
//         printf("\n");
//         for(int z=0;z<MAXL;z++) {
//             printf("%2d", nxt[z]);
//         }

//     }

//     for(int i=0; i<mx; i++) {
//         if(res[i] != '?') {
//             printf("%c", res[i]);
//         } else {
//             printf("a");
//         }
//     }
//     return 0;
// }
