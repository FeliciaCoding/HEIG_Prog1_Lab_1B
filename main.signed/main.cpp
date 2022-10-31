/* ---------------------------
Laboratory:         Labo 01B – Bureau de change
Author(s):          Dominik SAUL, Pei-Wen LIAO, Richard SIERRA
Version:            1.0
Date:               06.10.2022
Description:        Program to simulate an ATM that calculates the currency change (Euro to CHF) and the handling fees of a debit.
                    In the end the ATM prints a virtual ticket.
Modification(s):
--------------------------- */
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    // Declare and initialize the constants
    const double HANDLING_FEE      = 5.;
    const double EXCHANGE_RATE     = 1.024;
    const int    PRECISION_MONEY   = 2;
    const int    PRECISION_EX_RATE = 3;

    // Constants to format the ticket output
    const int WIDTH_LEFT  = 17;
    const int WIDTH_RIGHT = 8;
    const int WIDTH_FULL  = WIDTH_LEFT + WIDTH_RIGHT + 3;

    // User inputs
    int accountNr = 0;
    cout << "Quel est votre numéro de compte ?" << endl;
    cin >> accountNr;

    string userName = "";
    cout << "Quel est votre nom de famille ?" << endl;
    cin >> userName;

    // Output account info
    double accountBalance = 1000;
    cout << fixed;
    cout << "Solde de votre compte CHF : " << setprecision(PRECISION_MONEY) << accountBalance << endl;
    cout << "Taux de change : 1 CHF = " << setprecision(PRECISION_EX_RATE) << EXCHANGE_RATE << " Euro" << endl;
    cout << "Frais d’opération : " << setprecision(PRECISION_MONEY) << HANDLING_FEE << " CHF" << endl;

    // User input of the amount to withdraw
    double withdrawAmountEUR = 0.;
    cout << "Entrez la somme souhaitée en Euro :" << endl;
    cin >> withdrawAmountEUR;

    double withdrawAmountCHF = 0.;
    withdrawAmountCHF = withdrawAmountEUR / EXCHANGE_RATE;
    accountBalance -= (withdrawAmountCHF + HANDLING_FEE);

    // Output Ticket
    cout << fixed << setprecision(PRECISION_MONEY) << endl;
    cout << "+" << setfill('-') << setw(WIDTH_FULL + 1) << right << "+" << endl;
    cout << setfill(' ');
    cout << "| " << setw(WIDTH_FULL) << right << "|" << endl;
    cout << "| " << setw(WIDTH_FULL - 1) << left << userName << "|" << endl;
    cout << "| " << setw(WIDTH_FULL - 1) << left << accountNr << "|" << endl;
    cout << "| " << setw(WIDTH_FULL) << right << "|" << endl;
    cout << "| " << setw(WIDTH_LEFT) << left << "Somme Euro" << ":" << setw(WIDTH_RIGHT) << right << withdrawAmountEUR
         << " |"
         << endl;
    cout << setprecision(PRECISION_EX_RATE);
    cout << "| " << setw(WIDTH_LEFT) << left << "1 CHF en Euro" << ":" << setw(WIDTH_RIGHT) << right << EXCHANGE_RATE
         << " |"
         << endl;
    cout << setprecision(PRECISION_MONEY);
    cout << "| " << setw(WIDTH_FULL) << right << "|" << endl;
    cout << "| " << setw(WIDTH_LEFT) << left << "Somme CHF" << ":" << setw(WIDTH_RIGHT) << right << withdrawAmountCHF
         << " |"
         << endl;
    cout << "| " << setw(WIDTH_LEFT) << left << "Frais" << ":" << setw(WIDTH_RIGHT) << right << HANDLING_FEE << " |"
         << endl;
    cout << "| " << setw(WIDTH_FULL) << right << "|" << endl;
    cout << "| " << setw(WIDTH_LEFT) << left << "Solde Compte" << ":" << setw(WIDTH_RIGHT) << right << accountBalance
         << " |"
         << endl;
    cout << "| " << setw(WIDTH_FULL) << right << "|" << endl;
    cout << "+" << setfill('-') << setw(WIDTH_FULL + 1) << right << "+" << endl;

    return 0;
}
