#include <iostream>
#include <set>
using namespace std;

int main()
{
    //
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //

    int n;
    int m;
    int pal = 0;
    int norm = 0;
    set<string> palavrao;
    set<string> palavrao_aux;
    set<string> normal;

    cin >> n >> m;
    for (int i = 0; i < n; i++){
        string aux;
        cin >> aux;
        palavrao_aux.insert(aux);
        palavrao.insert(aux);
    }

    for (int i = 0; i < m; i++){
        int x;
        cin >> x;
        string aux;
        string frase[x];
        for (int j = 0; j < x; j++){
            cin >> aux;
            if (palavrao.count(aux) == 1){
                frase[j] = "bobba";
                if (palavrao_aux.count(aux) == 1){
                    palavrao_aux.erase(aux);
                    pal++;
                }
            }
            else{
                frase[j] = aux;
                if (normal.count(aux) == 0){
                    normal.insert(aux);
                    norm++;
                }
            }
        }
        for (int j = 0; j < x; j++){
            cout << frase[j] << ' ';
        }
        cout << endl;
    }
    
    cout << norm << ' ' << pal << endl;

    return 0;
}