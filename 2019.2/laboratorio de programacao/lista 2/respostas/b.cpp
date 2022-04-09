#include<iostream>
#include<map>
using namespace std;

int main(){
    int q;
    int poder;
    string item;
    map<string, int> m;
    map<string, int>::iterator it;
    
    cin>>q;
    cin.ignore();
    for(int i=0; i<q; i++){
        cin>>poder;
        cin.ignore();
        getline(cin, item);

        if(m[item] < poder){
            m[item] = poder;
        }
    }

    for(it = m.begin(); it != m.end(); it++){
        cout<<(*it).first<<' '<<(*it).second<<endl;
    }
    return 0;
}