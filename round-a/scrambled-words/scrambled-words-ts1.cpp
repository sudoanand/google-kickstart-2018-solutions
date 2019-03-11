//Does not work for large dataset due to time limit

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int Solve(const vector<string> &dictionary, const string &S){

    vector<string> foundwords;
    for(string dictword: dictionary){
        int st,en,w; //Sliding window: st = start, en = end, w = window size
        st = 0;
        w = dictword.size();
        en = st+w-1;
        
        string midtext = "";
        while(st < S.size()-(w-1)){
            
            en = st+w-1;

            if(S[st]==dictword[0] && S[en]==dictword[w-1]){
                
                if(w==2){
                    foundwords.push_back(dictword);
                    break;
                }else{
                    midtext = dictword.substr(1,w-2);
                    string midtext_ = "";
                    for(int mi = 1; mi < w-1; mi++){
                        midtext_ += S[st+mi];
                    }
                    
                    sort(midtext.begin(),midtext.end());
                    sort(midtext_.begin(),midtext_.end());

                    if(midtext==midtext_){
                        foundwords.push_back(dictword);
                        break;
                    }
                }
            }


            st = st+1;
        }

    }

    return foundwords.size();
}

int main() {
    //freopen("/Users/hack4mer/Lab/stdin.txt","r",stdin);

    int T = 0;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        int L = 0;
        cin >> L;
        vector<string> dictionary(L);
        for (string &word : dictionary) cin >> word;
        char S1 = 0, S2 = 0;
        int N = 0, A = 0, B = 0, C = 0, D = 0;
        cin >> S1 >> S2 >> N >> A >> B >> C >> D;
        vector<int> X(N);
        X[0] = S1;
        X[1] = S2;
        for (int i = 2; i < N; ++i) X[i] = ((long long)A*X[i - 1] + (long long)B*X[i - 2] + C)%D;
        string S;
        S.resize(N);
        S[0] = S1;
        S[1] = S2;
        for (int i = 2; i < N; ++i) S[i] = char('a' + X[i]%26);

        cout << "Case #" << t << ": " << Solve(dictionary, S) << endl;
    }

    return 0;
}