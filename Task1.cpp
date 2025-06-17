/*


#include<iostream>
#include<fstream>
#include<windows.h>
#include<string>  // Needed for string
using namespace std;

class Login {
private:
    string LoginID, Password;

public:
    Login() : LoginID(""), Password("") {}

    void setID(string id) {
        LoginID = id;
    }

    void setPW(string pw) {
        Password = pw;
    }

    string getID() {
        return LoginID;
    }

    string getPW() {
        return Password;
    }
};

void registration(Login &log) {
    system("cls");
    string id, pw;
    cout << "\tEnter Login ID: ";
    cin >> id;
    log.setID(id);

start:
    cout << "\tEnter a strong Password: ";
    cin >> pw;
    if (pw.length() >= 8) {
        log.setPW(pw);
    } else {
        cout << "\tEnter minimum 8 characters!" << endl;
        goto start;
    }

    ofstream outfile("D:/Login.txt", ios::app);
    if (!outfile) {
        cout << "\tError: File can't open!" << endl;
    } else {
        outfile << "\t" << log.getID() << " : " << log.getPW() << endl << endl;
        cout << "\tUser Registered Successfully!" << endl;
    }
    outfile.close();
    Sleep(3000);  // Use capital 'S' in Sleep
}
login(){
    system("cls");
    string id,pw;
    cout<<"\tEnter Login ID: ";
    cin>>id;

    cout<<"\tEnter Password: ";
    cin>>pw;

    istream infile("d:/Login.txt");
    if(!infile){
        cout<<"\tError: File Can't Open!"<<endl;
    }
    else{
        string line;
        bool found=false;
        while(getloine(infile,line)){
        stringstream ss;
    ss<<line;
    string userID,userPW;
    char delimiter;
    ss>>userID>>delimiter>>userPW;

    if(id==userID && pw==userPW)
    found=true;

    cout<<"\tPlease Wait";
    for(int i=0; i<3; i++){
        cout<<" . ";
        Sleep(800);
    }
    system("cls");
    cout<<"\tWelcome To This Page!"<<endl;
    } 
}
    if(!found){
    cout<<"\tError: Incorrect Login ID or Password!"<<endl;

    }
    infile.close();
    sleep(5000);
}
int main() {
    Login log;

    bool exit = false;
    while (!exit) {
        system("cls");
        int val;
        cout << "\tWelcome To Registration & Login Form" << endl;
        cout << "\t**************************************" << endl;
        cout << "\t1. Register" << endl;
        cout << "\t2. Login" << endl;
        cout << "\t3. Exit" << endl;
        cout << "\tEnter choice: ";
        cin >> val;

        if (val == 1) {
            registration(log);
        } else if (val == 2) {
            login();
            // login functionality (not implemented)
            cout << "\tLogin Feature Not Implemented Yet!" << endl;
            Sleep(3000);
        } else if (val == 3) {
            
            system("cls");
            Sleep(3000);
            exit = true;
            cout<<"\tGOOD LUCK!<<endl;"
        } else {
            cout << "\tInvalid Choice!" << endl;
            Sleep(3000);
        }
    }

    return 0;
}
*/

#include<iostream>
#include<fstream>
#include<windows.h>
#include<string>
#include<sstream>
using namespace std;

class Login {
private:
    string LoginID, Password;

public:
    Login() : LoginID(""), Password("") {}

    void setID(string id) {
        LoginID = id;
    }

    void setPW(string pw) {
        Password = pw;
    }

    string getID() {
        return LoginID;
    }

    string getPW() {
        return Password;
    }
};

void registration(Login &log) {
    system("cls");
    string id, pw;
    cout << "\tEnter Login ID: ";
    cin >> id;
    log.setID(id);

start:
    cout << "\tEnter a strong Password: ";
    cin >> pw;
    if (pw.length() >= 8) {
        log.setPW(pw);
    } else {
        cout << "\tEnter minimum 8 characters!" << endl;
        goto start;
    }

    ofstream outfile("D:/Login.txt", ios::app);
    if (!outfile) {
        cout << "\tError: File can't open!" << endl;
    } else {
        outfile << log.getID() << ":" << log.getPW() << endl;
        cout << "\tUser Registered Successfully!" << endl;
    }
    outfile.close();
    Sleep(3000);
}

void login() {
    system("cls");
    string id, pw;
    cout << "\tEnter Login ID: ";
    cin >> id;

    cout << "\tEnter Password: ";
    cin >> pw;

    ifstream infile("D:/Login.txt");
    if (!infile) {
        cout << "\tError: File Can't Open!" << endl;
    } else {
        string line;
        bool found = false;

        while (getline(infile, line)) {
            stringstream ss(line);
            string userID, userPW;

            if (getline(ss, userID, ':') && getline(ss, userPW)) {
                // Trim possible leading/trailing whitespaces
                userID.erase(0, userID.find_first_not_of(" \t"));
                userPW.erase(0, userPW.find_first_not_of(" \t"));
                userPW.erase(userPW.find_last_not_of(" \t\r\n") + 1);

                if (id == userID && pw == userPW) {
                    found = true;
                    break;
                }
            }
        }

        cout << "\tPlease Wait";
        for (int i = 0; i < 3; i++) {
            cout << " . ";
            Sleep(800);
        }

        if (found) {
            system("cls");
            cout << "\tWelcome To This Page, " << id << "!" << endl;
        } else {
            cout << "\n\tError: Incorrect Login ID or Password!" << endl;
        }

        infile.close();
        Sleep(5000);
    }
}

int main() {
    Login log;

    bool exit = false;
    while (!exit) {
        system("cls");
        int val;
        cout << "\tWelcome To Registration & Login Form" << endl;
        cout << "\t**************************************" << endl;
        cout << "\t1. Register" << endl;
        cout << "\t2. Login" << endl;
        cout << "\t3. Exit" << endl;
        cout << "\tEnter choice: ";
        cin >> val;

        if (val == 1) {
            registration(log);
        } else if (val == 2) {
            login();
        } else if (val == 3) {
            system("cls");
            cout << "\tGOOD LUCK!" << endl;
            Sleep(3000);
            exit = true;
        } else {
            cout << "\tInvalid Choice!" << endl;
            Sleep(3000);
        }
    }

    return 0;
}
