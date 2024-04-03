#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>

using namespace std;

void drawLine(int n, char ch){

    for(int i=0; i<n; i++){
        cout<<ch;
    }
    cout<<endl;
}


void clearScreen() {
    // ANSI escape code to clear the screen
    cout << "\033[2J\033[H";
}

void rules(){
    
    clearScreen();

    cout<<"\n\n";

    drawLine(80, '-');
    cout<<"\t\t\tRules of the Game"<<endl;
    drawLine(80, '-');

    cout<<"\t 1. You can choose any number between 1 to 10."<<endl;
    cout<<"\t 2. If you win, you will get 10 times of money you bet."<<endl;
    cout<<"\t 3. If you bet on wrong number, you will lose you betting amount"<<endl;

    drawLine(80, '-');
}

int main(){

    string playername;
    int amount;
    int bettingAmount;
    int guess;
    int dice; // Stores random computer generated number
    char choice;

    srand(time(0));

    drawLine(60, '_');
    cout<<"\n\n\n\t\tCASINO GAME \n\n\n\n";
    drawLine(60, '_');

    cout<<"\n\nEnter Your Name \n";
    getline(cin, playername);

    cout<<"\n\nEnter Deposit amount to play game: \n";
    cin>>amount;

    do{
        clearScreen();
        rules();
        
        cout<<"\n\n Your current Balence is: $ "<<amount<<"\n";

        // Code for taking input for bet money
        do{
            cout<<playername<<", enter money to bet ! \n";
            cin>>bettingAmount;

            if(bettingAmount > amount){
                cout<<"\n Your betting amount is more than your current balence\n"<<"\n Re-Enter Data\n\n";
            }
        }
        while(bettingAmount > amount);

        //Code for taking guess number as input
        do{
            cout<<"\nGuess your number between 1 to 10\n";
            cin>>guess;

            if(guess<=0 || guess > 10){
                cout<<"\n Please check the number, should be between 1 to 10 !! \n"<<"\n Re-Enter Data\n\n";
            }
        }
        while(guess <=0 || guess > 10);

        dice = rand()%10 + 1;

        if(dice == guess){
            cout<<"\n Good Luck !! You won "<<bettingAmount*10;
            amount = amount + bettingAmount*10;
        }
        else{
            cout<<"\n Bad Luck this time, You Lost "<<bettingAmount;
            amount = amount - bettingAmount;
        }

        cout<<"\n The winning number was "<<dice<<"\n\n";
        cout<<"\n"<<playername<<", You have $"<<amount<<"\n";

        if(amount <= 0){
            cout<<"You have no money to play !! \n";
            break;
        }

        cout<<"\n Do you want to play again ?? (y/n): ";
        cin>>choice;
    }
    while(choice == 'y' || choice == 'Y');

    cout<<"\n\n\n";

    drawLine(70, '-');
    cout<<"Thanks for playing the game !! Your balence is $"<<amount<<"\n\n";
    drawLine(70, '-');

    return 0;
}