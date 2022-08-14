#include <bits/stdc++.h>
using namespace std;

int computeScore(int n, vector<int> & scores){
    if (scores[n] != -1){
//        cout << "n:" << n <<endl;
//        cout << "scores n :" << scores[n] << endl;
        return scores[n];
    }

    if (n % 2 == 0){
        scores[n] = n/2 * n/2 + 2*computeScore(n/2,scores);
//        cout << "n:" << n <<endl;
//        cout << "scores n :" << scores[n] << endl;
        return scores[n];
    }

    scores[n] = (n-1)/2*(n+1)/2 + computeScore((n+1)/2,scores) + computeScore((n-1)/2,scores);
//    cout << "n:" << n <<endl;
//    cout << "scores n :" << scores[n] << endl;
    return scores[n];
}

int main(){
    vector<int> scores;
    int n, score;
    cin >> n;
    for (int i = 0; i <= n; i++){
        scores.push_back(-1);
    }
    scores[0] = 0;
    scores[1] = 0;
    scores[2] = 1;
    score = computeScore(n,scores);
    cout << "n: " << n << endl;
    cout << "score: " << score << endl;
    return score;
}


int cup() {
    int n;
    cin >> n ;
    bool* array = new bool[n];
    for(int i = 0; i < n; i++){
        array[i] = false;
    }

    int k = 0;
    for(int i = 0; i < n; i++){
        k = k + i;
        array[k % n] = true;
    }

    bool answer = true;
    for(int i = 0; i < n; i++){
        if(array[i] == false){
            answer = false;
            break;
        }
    }

    cout << (answer ? "YES":"NO");
    delete [] array;
    return 0;
}


