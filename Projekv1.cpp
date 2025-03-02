#include <iostream>
using namespace std;

struct akun{
    string ussername, password;
};

akun user[100];
int tot_user = 0; 
int chances = 3;  

void header(){
    system("cls");
    cout << "\n+--------------------+";
    cout << "\n| Test Program V1... |";
    cout << "\n+--------------------+" << endl;
    return;
}

void home2(){
    header();
    cout << "memek";
}

void home1();
void sign_in(){
    header();
    cout << "Username : ";
        cin >> user[tot_user].ussername;
    cout << "Password : ";
        cin >> user[tot_user].password;
    tot_user++;
    home1();
}

void login(){
    header();
    if (tot_user == 0){
        cout << "\nSilahkan Sign In terlebih dahulu !!!\n";
        system("pause");
        sign_in();
    } else {
        cout << "Username : ";
            cin >> user[tot_user].ussername;
        cout << "Password : ";
            cin >> user[tot_user].password;

        bool login_success = false;
        for (int i = 0; i < tot_user; i++) {
            if (user[i].ussername == user[tot_user].ussername && user[i].password == user[tot_user].password) {
                login_success = true;
                break;
            }
        }

        if (login_success) {
            cout << "Login successful!\n";
            system("pause");
            home2();
        } else {
            chances--;
            if (chances == 0){
                cout << "Exiting...\n";
                exit(0);
            } else {
                cout << "Username or password incorrect.\n";
                cout << "You have " << chances << " chances left.\n";
                system("pause");
                login();
            }
        }
    }
}

void home1(){ 
    int pil;

    header();
    cout << "\n1. Login";
    cout << "\n2. Sign In";
    cout << "\n3. Exit\n";
    
    cout << "\nSudah punya akun?(1/2) "; cin >> pil;
    switch (pil){
    case 1:  
        login();          
        break;
    
    case 2:            
        sign_in();
        break;

    case 3:            
        cout << "Exiting...\n";
        break;

    default:
        cout << "Invalid option. Please try again.\n";
        break;
    }
}

int main(){
    home1();
    return 0;
}
