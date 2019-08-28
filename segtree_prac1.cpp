//g++  5.4.0
//https://www.iarcs.org.in/inoi/online-study-material/problems/inversion-permutation.php

#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;
typedef long long ll;

const int mod = 1e9+7;

vector<int> tree;

int query(int space_to_right, int r, int base){

    if(space_to_right == 0 && 2*r+1 >= base){
        if(tree[2*r+1] == 1) return 2*r+1;
        else return 2*r;
    }
    else if(space_to_right == 1 && 2*r >= base){
        return 2*r;
    }

    int left = tree[2*r];
    int right = tree[2*r+1];

    if(space_to_right < right)
        return query(space_to_right, 2*r+1, base);
    else
    {
        return query(space_to_right-right, 2*r, base);
    }
    

}

void update(int tmp){
    while(tmp > 1){
        tree[tmp/2] = tree[(tmp/2)*2] + tree[(tmp/2)*2+1];
        tmp /=2 ;
    }
}

int main()
{
    int n; cin >> n;
    vector<int> inversions(n);
    vector<int> permutation(n);

    int base = 1;
    while(base < n) base *= 2;

    tree.resize(2*base); // it tells number of blank position in an interval
    for(int i = 0; i < n; i++) tree[base+i] = 1;

    int i = base+n-1;
    while(i > 1){
        tree[i/2] += tree[i];
        i--;
    }

    for(int i = 0; i< n; i++) cin >> inversions[i];

    for(int i = n-1; i >= 0; i--){
        int tmp = query(inversions[i], 1, base);
        permutation[tmp-base] = i+1;
        tree[tmp] = 0;
        update(tmp);
    }

    for(int i = 0; i < n; i++) cout << permutation[i] << " "; cout << endl;


}
