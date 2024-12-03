/*
Program Title: Ch6Ex24
Programmer: Josh Richards
Date: December 2, 2024
Requirements:

Write a program that lets the user play the game Rock, Paper, Scissors against the computer. The program should work as follows:

1. When the program begins, a random number in the range of 1 through 3 is generated. 
If the number is 1, then the computer has chosen rock. 
If the number is 2, then the computer has chosen paper. 
If the number is 3, then the computer has chosen scissors.
(Don't display the computer's choice yet.)

2. The user enters his or her choice of "rock", "paper", or "scissors" at the keyboard. 
(You can use a menu if you prefer.)

3. The computer's choice is displayed.

4. A winner is selected according to the following rules:

    - If one player chooses rock and the other player chooses scissors, then rock wins. 
        (The rock smashes the scissors.)
    - If one player chooses scissors and the other player chooses paper, then scissors wins. 
        (Scissors cuts paper.)
    - If one player chooses paper and the other player chooses rock, then paper wins.
        (Paper covers rock.)
    - If both players make the same choice, the game must be played again to determine the winner.

*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

int getComputerChoice();
string getUserChoice();
string convertChoice(int choice);
string determineWinner(string userChoice, string computerChoice);


int main()
{
    srand(static_cast<unsigned int>(time(0)));

    while (true) {
        int computerChoice = getComputerChoice();
        string userChoice = getUserChoice();
        string computerChoiceStr = convertChoice(computerChoice);

        cout << "Computer chose: " << computerChoiceStr << endl;

        string result = determineWinner(userChoice, computerChoiceStr);

        if (result == "Draw") {
            cout << "It's a draw! Let's play again.\n" << endl;
        }
        else {
            cout << result << endl;
            break;
        }
    }
    return 0;
}

int getComputerChoice() {
    return rand() % 3 + 1;
}

string getUserChoice() {
    string choice;
    while (true) {
        cout << "Enter your choice (rock, paper, or scissors): ";
        cin >> choice;

        for (char& c : choice) c = tolower(c);

        if (choice == "rock" || choice == "paper" || choice == "scissors") {
            break;
        }
        else {
            cout << "Invalid choice. Please enter 'rock', 'paper', or 'scissors'.\n";
        }
    }
    return choice;
}

string convertChoice(int choice) {
    switch (choice) {
    case 1: return "rock";
    case 2: return "paper";
    case 3: return "scissors";
    default: return "unknown";
    }
}

string determineWinner(string userChoice, string computerChoice) {
    if (userChoice == computerChoice) {
        return "Draw";
    }
    else if ((userChoice == "rock" && computerChoice == "scissors") ||
        (userChoice == "scissors" && computerChoice == "paper") ||
        (userChoice == "paper" && computerChoice == "rock")) {
        return "You Win!!!";
    }
    else {
        return "Computer Wins!";
    }
}