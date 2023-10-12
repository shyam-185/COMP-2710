//Shyam Patel 
//sjp0059@auburn.edu
//project2_Patel_sjp0059.cpp
//To compile my code type "g++ project2_Patel_sjp0059.cpp" and hit enter
//run using ./a.out
//I used Dr. Li's 02/07/2022 lecture video for help
//I used the hints on the project files

#include <iostream>
#include <stdlib.h>
#include <assert.h>
#include <ctime>
using namespace std;

//VARIABLES
const int Aaron_acc = 33;
const int Bob_acc = 50;
const int Charlie_acc = 100;

int A_wins1 = 0;
int A_wins2 = 0;
int B_wins = 0;
int C_wins = 0;

const int duels = 10000;
int count = 0;
int rng = rand() % 100;

bool A_alive = true;
bool B_alive = true;
bool C_alive = true;


bool at_least_two_alive(bool A_alive, bool B_alive, bool C_alive);
void Aaron_shoots1(bool& B_alive, bool& C_alive);
void Bob_shoots(bool& A_alive, bool& C_alive);
void Charlie_shoots(bool& A_alive, bool& B_alive);
void Aaron_shoots2(bool& B_alive, bool& C_alive);
      

void test_at_least_two_alive(void);
void test_Aaron_shoots1(void);
void test_Bob_shoots(void);
void test_Charlie_shoots(void);
void test_Aaron_shoots2(void);
void Press_any_key(void);

int main(){
//Initializes Random number generator's seed and calls test functions
    cout << "*** Welcome to Shyam's Duel Simulator ***\n";

    srand(time(0));

    test_at_least_two_alive();
    Press_any_key();
    test_Aaron_shoots1();
    Press_any_key();
    test_Bob_shoots();
    Press_any_key();
    test_Charlie_shoots();
    Press_any_key();
    test_Aaron_shoots2();
    Press_any_key();

//Starts strategy 1 and runs 10,000 times
    cout << "Ready to test strategy 1 (run 10000 times):\n";
    Press_any_key();
    for (int i = 0; i < duels; i++ ){
        bool A_alive = true;
        bool B_alive = true;
        bool C_alive = true;
        while (at_least_two_alive(A_alive, B_alive, C_alive)){
            if (A_alive && at_least_two_alive(A_alive, B_alive, C_alive)){
                Aaron_shoots1(B_alive, C_alive);
            }
            if (B_alive && at_least_two_alive(A_alive, B_alive, C_alive)){
                Bob_shoots(A_alive, C_alive);
            }
            if (C_alive && at_least_two_alive(A_alive, B_alive, C_alive)){
                Charlie_shoots(A_alive, B_alive);
            }
        }

        if (A_alive){
            A_wins1++;
        }
        if (B_alive){
            B_wins++;
        }
        if (C_alive){
            C_wins++;
        }
    }

    cout << "Aaron won " << A_wins1 << "/10000 duels or " << static_cast<double>(A_wins1) / duels * 100 << "%\n"
         << "Bob won " << B_wins << "/10000 duels or " << static_cast<double>(B_wins) / duels * 100 << "%\n"
         << "Charlie won " << C_wins << "/10000 duels or " << static_cast<double>(C_wins) / duels * 100 << "%\n"
         << endl;


//Reinitializes variables and starts strategy 2 to run 10,000 times
    A_wins2 = 0;
    B_wins = 0;
    C_wins = 0;
    srand(time(0));

    cout << "Ready to test strategy 2 (run 10000 times):\n";
    Press_any_key();
    for (int i = 0; i < duels; i++){
        bool A_alive = true;
        bool B_alive = true;
        bool C_alive = true;
        while (at_least_two_alive(A_alive, B_alive, C_alive)){
            if (A_alive && at_least_two_alive(A_alive, B_alive, C_alive)){
                Aaron_shoots2(B_alive, C_alive);
            }
            if (B_alive && at_least_two_alive(A_alive, B_alive, C_alive)){
                Bob_shoots(A_alive, C_alive);
            }
            if (C_alive && at_least_two_alive(A_alive, B_alive, C_alive)){
                Charlie_shoots(A_alive, B_alive);
            }
        }

        if (A_alive){
            A_wins2++;
        }
        if (B_alive){
            B_wins++;
        }
        if (C_alive){
            C_wins++;
        }
    }

    cout << "Aaron won " << A_wins2 << "/10000 duels or " << static_cast<double>(A_wins2) / duels * 100 << "%\n"
         << "Bob won " << B_wins << "/10000 duels or " << static_cast<double>(B_wins) / duels * 100 << "%\n"
         << "Charlie won " << C_wins << "/10000 duels or " << static_cast<double>(C_wins) / duels * 100 << "%\n"
         << endl;

    if (A_wins1 > A_wins2){
        cout << "Strategy 1 is better than strategy 2.\n";
    }
    else{
        cout << "Strategy 2 is better than strategy 1.\n";
    }
    return 0;
}


//Implementation of functions

    bool at_least_two_alive(bool A_alive, bool B_alive, bool C_alive){
        if (A_alive && B_alive){
            return true;
        }
        if (A_alive && C_alive){
            return true;
        }
        if (B_alive && C_alive){
            return true;
        }
            return false;
    }

    void test_at_least_two_alive(void){
        cout << "Unit Testing 1: Function - at_least_two_alive()\n";

        cout << "\tCase 1: Aaron alive, Bob alive, Charlie alive\n";
        assert(true == at_least_two_alive(true, true, true));
        cout << "\tCase passed ...\n";

        cout << "\tCase 2: Aaron dead, Bob alive, Charlie alive\n";
        assert(true == at_least_two_alive(false, true, true));
        cout << "\tCase passed ...\n";

        cout << "\tCase 3: Aaron alive, Bob dead, Charlie alive\n";
        assert(true == at_least_two_alive(true, false, true));
        cout << "\tCase passed ...\n";

        cout << "\tCase 4: Aaron alive, Bob alive, Charlie dead\n";
        assert(true == at_least_two_alive(true, true, false));
        cout << "\tCase passed ...\n";

        cout << "\tCase 5: Aaron dead, Bob dead, Charlie alive\n";
        assert(false == at_least_two_alive(false, false, true));
        cout << "\tCase passed ...\n";

        cout << "\tCase 6: Aaron dead, Bob alive, Charlie dead\n";
        assert(false == at_least_two_alive(false, true, false));
        cout << "\tCase passed ...\n";

        cout << "\tCase 7: Aaron alive, Bob dead, Charlie dead\n";
        assert(false == at_least_two_alive(true, false, false));
        cout << "\tCase passed ...\n";

        cout << "\tCase 8: Aaron dead, Bob dead, Charlie dead\n";
        assert(false == at_least_two_alive(false, false, false));
        cout << "\tCase passed ...\n";
    }

    void Aaron_shoots1(bool& B_alive, bool& C_alive){
        assert(B_alive || C_alive);
        int shootResult = rand() % 100;
            if (C_alive){
                if (shootResult <= Aaron_acc){
                    C_alive = false;
                }
            }
            else{
                if (B_alive){
                    if(shootResult <= Aaron_acc){
                        B_alive = false;
                    }
                }
            }
    }

    void test_Aaron_shoots1(void) {
        cout << "Unit Testing 2: Function Aaron_shoots1(Bob_alive, Charlie_alive)\n";
        B_alive = true;
        C_alive = true;
        cout << "\tCase 1: Bob alive, Charlie alive\n"
             << "\t\tAaron is shooting at Charlie\n";
        Aaron_shoots1(B_alive, C_alive);
        

        B_alive = false;
        C_alive = true;
        cout << "\tCase 2: Bob dead, Charlie alive\n"
             << "\t\tAaron is shooting at Charlie\n";
        Aaron_shoots1(B_alive, C_alive);
        

        B_alive = true;
        C_alive = false;
        cout << "\tCase 3: Bob alive, Charlie dead\n"
             << "\t\tAaron is shooting at Bob\n";
        Aaron_shoots1(B_alive, C_alive);
    }

    void Bob_shoots(bool& A_alive, bool& C_alive){
        assert(A_alive || C_alive);
        int shootResult = rand() % 100;
            if (C_alive){
                if (shootResult <= Bob_acc){
                    C_alive = false;
                }
            }
            else{
                if (A_alive){
                    if (shootResult <= Bob_acc){
                        A_alive = false;
                    }
                }
            }
    }

    void test_Bob_shoots(void){
        cout << "Unit Testing 3: Function Bob_shoots(Aaron_alive, Charlie_alive)\n";
        A_alive =true; 
        C_alive = true;
        cout << "\tCase 1: Aaron alive, Charlie alive\n"
             << "\t\tBob is shooting at Charlie\n";
        Bob_shoots(A_alive, C_alive);

        A_alive = false;
        C_alive = true;
        cout << "\tCase 2: Aaron dead, Charlie alive\n"
             << "\t\tBob is shooting at Charlie\n";
        Bob_shoots(A_alive, C_alive);

        A_alive = true;
        C_alive = false;
        cout << "\tCase 3: Aaron alive, Charlie dead\n"
             << "\t\tBob is shooting at Aaron\n";
        Bob_shoots(B_alive, C_alive);
    }

    void Charlie_shoots(bool& A_alive, bool& B_alive){
        assert(A_alive || B_alive);
        int shootResult = rand() % 100;
            if (B_alive){
                B_alive = false;
            }
            else{
                A_alive = false;
            }
    }

    void test_Charlie_shoots(void){
        cout << "Unit Testing 4: Function Charlie_shoots(Aaron_alive, Bob_alive)\n";
        A_alive = true; 
        B_alive = true;
        cout << "\tCase 1: Aaron alive, Bob alive\n"
             << "\t\tCharlie is shooting at Bob\n";
        Charlie_shoots(A_alive, B_alive);

        A_alive = false;
        B_alive = true;
        cout << "\tCase 2: Aaron dead, Bob alive\n"
             << "\t\tCharlie is shooting at Bob\n";
        Charlie_shoots(A_alive, B_alive);

        A_alive = true;
        B_alive = false;
        cout << "\tCase 3: Aaron alive, Bob dead\n"
             << "\t\tCharlie is shooting at Aaron\n";
        Charlie_shoots(A_alive, B_alive);
    }

    void Aaron_shoots2(bool& B_alive, bool& C_alive){
        int shootResult = rand() % 100;
        if (C_alive && !B_alive){
            if (shootResult <= Aaron_acc){
                C_alive = false;
            }
        }
        if (B_alive && !C_alive){
            if (shootResult <= Aaron_acc){
                B_alive = false;
            }
        }
    }

    void test_Aaron_shoots2(void){
        cout << "Unit Testing 5: Function Aaron_shoots2(Bob_alive, Charlie_alive)\n";
        B_alive = true; 
        C_alive = true;
        cout << "\tCase 1: Bob alive, Charlie alive\n"
             << "\t\tAaron is shooting at Charlie\n";
        Aaron_shoots2(B_alive, C_alive);

        B_alive = false;
        C_alive = true;
        cout << "\tCase 2: Bob dead, Charlie alive\n"
             << "\t\tAaron is shooting at Charlie\n";
        Aaron_shoots2(B_alive, C_alive);

        B_alive = true;
        C_alive = false;
        cout << "\tCase 3: Bob alive, Charlie dead\n"
             << "\t\tAaron is shooting at Bob\n";
        Aaron_shoots2(B_alive, C_alive);
    }


    void Press_any_key(void) {
    cout << "Press any key to continue...";
    cin.ignore().get(); 
}