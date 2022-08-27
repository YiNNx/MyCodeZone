#include"iostream"
#include"string"
using namespace std;

int* getNext(string s2){
    int* next  = NULL;  
    next  = new int[s2.length()];
    next[0]=0;
    int now=0,x=1;

    while(x<s2.length()){
        if(s2[now]==s2[x]){
            next[x]=now+1;
            x++;
            now++;
        }else if(now==0){
                next[x]=0;
                x++;
        }else{
                now=next[now-1];
        }
    }

    return next;
}

void kmp(string s1,string s2,int* next){
    int i=0,j=0;
    while(i<s1.length()){
        if(s1[i]==s2[j]){
            if(j==s2.length()-1){
                cout<<(i-j+1)<<endl;
                j=next[j];
                i++;
            }else{
                i++;
                j++;
            }
        }else if(j!=0){
            j=next[j-1];
        }else{
            i++;
        }
    }
}

int main(){
    string s1,s2;
    cin>>s1>>s2;
    int *next=getNext(s2);
    kmp(s1,s2,next);
    for(int i=0;i<s2.length();i++){
        cout<<next[i]<<" ";
    }
    free(next);
    return 0;
}