#include <iostream>
#include <string>
using namespace std;

int main() {
    int a, b, c, d, e, f;
    string vrag, nash;
    
    againNash:
    cout << "Enter your figure: ";
    getline(cin, nash);
    bool NASH = nash == "horse" || nash == "elephant" || nash == "queen" || nash == "king" || nash == "rook" || nash == "pawn";
    if (!NASH) { cout << "There is no such figure, try to repeat" << endl;
    goto againNash; }
    else goto again1;
    
    again1 :
    cout << endl << "Enter the coordinates of your figure: ";
    cin >> a >> b;
    int ab = a * 10 + b;
    bool ba = ab > 10 && ab <= 88;
    if (!ba) { cout << "Impossible coordinates! try to repeat ";
    goto again1; }
    else goto againVrag;
    
    againVrag:
    cout << "Enter an enemy figure: ";
    getline(cin, vrag);
    bool VRAG = vrag == "horse" || vrag == "elephant" || vrag == "queen" || vrag == "king" || vrag == "rook" || vrag == "pawn";
    if (!VRAG) { cout << "There is no such figure, try to repeat" << endl;
    goto againVrag; }
    else goto again2;
        
        
    again2:
    cout << endl << "Enter the coordinates an enemy figure: ";
    cin >> c >> d;
    int cd = c * 10 + d;
    bool dc = cd > 10 && cd <= 88;
    if (!dc) { cout << "Impossible coordinates! try to repeat ";
    goto again2; }
          
    
    if (nash == "horse" && vrag == "horse") { 
        
        again :
        cout << endl << "Enter the coordinates where you want to go: ";
        cin >> e >> f;
        int ef = e * 10 + f;
        
        if (ef - ab == 19 || ef - ab == 8 || ef - ab == 21 || ef - ab == 12 || ab - ef == 19 || ab - ef == 8 || ab - ef == 21 || ab - ef == 12) {
            if (ef - cd == 19 || ef - cd == 8 || ef - cd == 21 || ef - cd == 12 || cd - ef == 19 || cd - ef == 8 || cd - ef == 21 || cd - ef == 12) 
            cout << "In this case, your figure will be eaten";
            else cout << "You can be like that";
        }
        else { cout << "You can not be like that, try to repeat ";
        goto again; }
    }
}