#include<iostream>
#include <sstream>
#include<vector>

using namespace std;

long long int strtoint(string ss){

    return stoll(ss);
}

bool isBeautiful(long long int num){
    

    string snum = to_string(num);
    int i;
    for(i =0; i < snum.length(); i++){
        string schar(1,snum[i]);
        
        if( strtoint(schar) % 2 != 0){
            
            return false;
            
        }
    }

    
    return true;
}


long long int getP(long long int num){
    string snum = to_string(num);
    string s;
    int i;

    for(i = 0; i < snum.length(); i++)
    {
        s = snum.substr(i,1);
        if(strtoint(s)%2 != 0){
            break;
        }
    }

    if( i < snum.length()){

        //character at index i is an odd number
        string replacement_num = to_string(strtoint(s)-1);
        snum = snum.replace(i,1,replacement_num);

        //Change all charaters after i to 8
        for(int j=1; j < snum.length() - i ;j++){
            replacement_num = "8";
            snum = snum.replace(i+j,1,replacement_num);
        }
    
    }

    
    return strtoint(snum);
}



long long int getM(long long int num){
    string snum = to_string(num);
    string s;
    int i,si;

    for(i = 0; i < snum.length(); i++){
        s = snum.substr(i,1);
        si = strtoint(s);

        if(si % 2 != 0){
            break;
        }
    }

    if(i < snum.length()){

        string replacement_num;
        if(si == 9 ){
            snum = snum.replace(i,1,"0");
            if(i==0){
                snum = "1"+snum;
            }else{
                string temps(1,snum[i-1]);
                snum.replace(i-1,1,to_string(strtoint(temps)+1));
            }

        }else{
            replacement_num = to_string(si+1);
            snum.replace(i,1,replacement_num);
        }

        for(int j = 1; j < snum.length()-i; j++){
            replacement_num = "0";
            snum = snum.replace(i+j,1,replacement_num);
        }

        if(!isBeautiful(strtoint(snum))){
            return getM(strtoint(snum));
        }

    }

    return strtoint(snum);
}

long long int beautifulNumberDistance(long long int num){

    long long int p = getP(num);
    long long int m = getM(num); 


    return abs(p-num) > abs(m-num) ? abs(m-num):abs(p-num);
}


int main(){
    //freopen("../stdin.txt","r",stdin);

    int i,n;
    cin >> n;

    for(i=0; i < n; i++){
        long long int vi;
        cin >> vi;
        cout << "Case #"<< i+1 <<": " << beautifulNumberDistance(vi) << endl;
    }


    return 0;
}


