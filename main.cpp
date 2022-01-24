// Libraries
// ---------
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
#include <string>
#include <windows.h>
#include <cstdio>
#include "colours.h"

using namespace std;


// Functions
// ---------
int getSales(int,int);
int getMaxSales(double numLemons, double numWater, double numSugar);


// Start Main
// ----------
int main()
{
    // variables
    // ---------
    int price = 0;                // price of a glass of lemonade in cents
    int totalCash = 0;            // total cash user has in cents
    int day = 0;                  // tracks number of days played
    double numLemons = 0;         // lemons in inventory
    double numWater = 0;          // water in inventory
    double numSugar = 0;          // sugar in inventory
    int buyLemons = 0;            // purchased lemons
    int buySugar = 0;             // purchased sugar
    int buyWater = 0;             // purchased water
    double incomeGoal = 0;        // $ amount user wants to earn
    int maxDays = 0;              // max # of days to play
    int costLemons = 0;           // cost of lemons in cents
    int costWater = 0;            // cost of one litre of water in cents
    int costSugar = 0;            // cost of 1 kg bag of sugar in cents
    int totalCost = 0;            // cost of total product purchased
    int maxGlasses = 0;           // maximum # of glasses you can sell
    int numSales = 0;             // # glasses you sell in a day
    int income = 0;               // total income for a day
    int seed = 0;                 // seed for random generator
    int x = 0;                    // x coordinate for printing warnings
    int y = 0;                    // y coordinate for printing warnings
    string choice;                // user's choice for repeating program
    string username;              // user's name
    string sentencechoice;        // user's choice for what said to duck
    int peopleleft;               // people that left
    int costGrapes;               // cost of grapes for duck in cents

    // seed random generator
    // ----------------------
    seed = time(NULL);
    srand(seed);

    // intro  (ascii art/animation goes here)
    // ------------------------------------------


    // set parameters for game
    // -----------------------
    cout << "Hi user! Welcome to the Lemonade Stand Game!!!";
    cout << "\nPlease enter your name here: ";
    getline(cin,username);

do{
    system("CLS"); // clear scream
    cout << "How many days would you like to run your lemonade stand?: ";
    cin >> maxDays;
    cout << "How much money would you like to earn in those " << maxDays << " days?: $";
    cin >> incomeGoal;
    system("CLS"); // clear screen

    // determine start up investment ($5-$10)
    // ---------------------------------------
    totalCash = rand()%501 + 500;

    // repeat days
    // ---------------
do {

         // count day
         // ---------
        day++;
         // current inventory
         // ------------------
        cout << "============== DAY " << day << "/" << maxDays << " ==============";
        cout << "\n|     *** Current Inventory ***     |";
        cout << "\n| Number of Lemons:                 |";
        setCoord(20,2);
        printf("%4.2f", numLemons);
        cout << "\n| 1L Bottles of Water:              |";
        setCoord(23,3);
        printf("%4.2f", numWater);
        cout << "\n| 1Kg Bags of Sugar:                |";
        setCoord(21,4);
        printf("%4.2f", numSugar);
        cout << "\n| Total Cash: $                     |";
        setCoord(15,5);
        cout << totalCash/100.00;
        cout << "\n| Max # of Glasses You Can Sell:    |";
        setCoord(33,6);
        maxGlasses = getMaxSales(numLemons, numWater, numSugar);
        cout << maxGlasses;
        cout << "\n=====================================";

         // set price of lemons, water and sugar
         // ------------------------------------
        if (totalCash < 1000){
            costLemons = rand() % 30 + 10; // Cost 10¢-49¢
            costWater = rand() % 5 + 5; // Cost 5¢-57¢
            costSugar = rand() % 99 + 100; // Cost 100¢-199¢
        }
        else if (totalCash >= 1000){
            costLemons = rand() % 61 + 15; // Cost 15¢ - 75¢
            costWater = rand() % 66 + 15; // Cost 15¢ - 80¢
            costSugar = rand() % 376 + 125; // Cost 125¢ - 400¢
        }
         // print cost of supplies
         // ----------------------
        cout << "\n\n=========== GROCERY STORE ===========";
        cout <<"\n| Lemons: $                         |";
        cout <<"\n| 1L Bottle of Water: $             |";
        cout <<"\n| 1Kg Bag of Sugar: $               |";
        cout << "\n=====================================";
        setCoord(11,10);
        cout << costLemons/100.0;
        setCoord(23,11);
        cout << costWater/100.0;
        setCoord(21,12);
        cout << costSugar/100.0;

        // checkout counter
        setCoord(x,13);
        cout << "\n\n========= CHECKOUT COUNTER ==========";
        cout << "\n|                                   |";
        cout << "\n|                                   |";
        cout << "\n|                                   |";
        cout << "\n|                                   |";
        cout << "\n|                                   |";
        cout << "\n|                                   |";
        cout << "\n|                                   |";
        cout << "\n|                                   |";
        cout << "\n=====================================";

		 // print global market warnings
         // ----------------------------
         x = 38;
         setCoord(x,0);
         cout << "======= GLOBAL MARKET WARNINGS =======";

            //lemons
            if (costLemons <= 17){
                y = 2;
                setCoord(x,y);
                cout << "New trade opened with Lemon County!";
                y = 3;
                setCoord(x,y);
                cout << "Lemons cheap today!\n";
            }
            else if (costLemons >= 60){
                y = 2;
                setCoord(x,y);
                cout << "Lemon harvests took a hit as a parasite";
                y = 3;
                setCoord(x,y);
                cout << "infected all lemons. Expensive lemons today!\n";
            }
            //water
            if (costWater <= 16){
                y = 5;
                setCoord(x,y);
                cout << "New water well built! Water prices low!\n";
            }
            else if (costWater >= 70){
                y = 5;
                setCoord(x,y);
                cout << "Cholera outbreak contaminates water supplies!";
                y = 6;
                setCoord(x,y);
                cout << "Due to shortage of uncontaminated water, water prices high!\n";
            }
            //sugar
            if (costSugar <= 175){
                y = 8;
                setCoord(x,y);
                cout << "Neighbouring farm gifted us sugar canes";
                y = 9;
                setCoord(x,y);
                cout << "from overharvest. Sugar cheap today!\n";
            }
            else if (costSugar >= 325){
                y = 8;
                setCoord(x,y);
                cout << "Sugar supplies dissolved after flash flood.";
                y = 9;
                setCoord(x,y);
                cout << "Sugar prices high today!\n";
            }

        //print recipe
        //
         // Buy Sugar
         // ---------
         setCoord(2,17);
         cout << "How many 1Kg bags of sugar would";
         setCoord(2,18);
         cout << "you like to buy?: ";

         do {cin >> buySugar; //error checking
             totalCost = buySugar * costSugar;
             if (totalCost > totalCash){
                setCoord(2,17);
                cout << "                                  "; //clear space
                setCoord(2,18);
                cout << "                                  "; //clear space
                setCoord(2,17);
                cout << "Sorry, you cannot afford " << buySugar << " bags";
                setCoord(2,18);
                cout << "of sugar, but you can buy " << (int)(buySugar = totalCash/costSugar);
                setCoord(2,19);
                cout << "bags of sugar and have $" << (totalCash - (costSugar*buySugar))/100.00 << " left.";
                setCoord(2,20);
                cout << "Please re-enter a new amount of";
                setCoord(2,21);
                cout << "bags to buy: ";
                continue;}
             else {
                setCoord(2,17);
                cout << "                                  "; //clear space
                setCoord(2,18);
                cout << "                                  "; //clear space
                setCoord(2,19);
                cout << "                                  "; //clear space
                setCoord(2,20);
                cout << "                                  "; //clear space
                setCoord(2,21);
                cout << "                                  "; //clear space
                setCoord(2,17);
                cout << "You have bought " << buySugar;
                setCoord(2,18);
                cout << "1Kg bag(s) of sugar.";
                Sleep(3000); //pause message
                setCoord(2,17);
                cout << "                                  "; //clear space
                setCoord(2,18);
                cout << "                                  "; //clear space
                break;
             }
         } while(true);


         // Update sugar inventory and totalCash
         // ------------------------------------
         numSugar = numSugar + buySugar;
         setCoord(21,4);
         cout << "     ";
         setCoord(21,4);
         printf("%4.2f", numSugar);

         totalCash = totalCash - totalCost;
         setCoord(15,5);
         cout << "            ";
         setCoord(15,5);
         cout << totalCash/100.00;

         // Buy Lemons
         // ----------
         setCoord(2,17);
         cout << "How many lemons would you";
         setCoord(2,18);
         cout << "like to buy?: ";

         do {cin >> buyLemons; //error checking
             totalCost = buyLemons * costLemons;
             if (totalCost > totalCash){
                setCoord(2,17);
                cout << "                                 "; //clear space
                setCoord(2,18);
                cout << "                                 "; //clear space
                setCoord(2,17);
                cout << "Sorry, you cannot afford " << buyLemons;
                setCoord(2,18);
                cout << "lemon(s), but you can buy " << (int)(buyLemons = totalCash/costLemons);
                setCoord(2,19);
                cout << "and have $" << (totalCash - (costLemons*buyLemons))/100.00 << " left over.";
                setCoord(2,20);
                cout << "Please re-enter a new amount of";
                setCoord(2,21);
                cout << "lemons to buy: ";
                continue;
                }
             else {
                setCoord(2,17);
                cout << "                                  "; //clear space
                setCoord(2,18);
                cout << "                                  "; //clear space
                setCoord(2,19);
                cout << "                                  "; //clear space
                setCoord(2,20);
                cout << "                                  "; //clear space
                setCoord(2,21);
                cout << "                                  "; //clear space
                setCoord(2,17);
                cout << "You have bought " << buyLemons << " lemon(s).";
                Sleep(3000); //pause message
                setCoord(2,17);
                cout << "                                  "; //clear space
                setCoord(2,18);
                cout << "                                  "; //clear space
                break;
                }
         } while(true);

         // Update lemon inventory and totalCash
         // ------------------------------------
         numLemons = numLemons + buyLemons;
         setCoord(20,2);
         cout << "     ";
         setCoord(20,2);
         printf("%4.2f", numLemons);

         totalCash = totalCash - totalCost;
         setCoord(15,5);
         cout << "            ";
         setCoord(15,5);
         cout << totalCash/100.00;

         // Buy Water
         // ---------
         setCoord(2,17);
         cout << "How many 1L bottles of water";
         setCoord(2,18);
         cout << "would you like to buy?: ";

         do {cin >> buyWater; //error checking
             totalCost = buyWater * costWater;
             if (totalCost > totalCash){
                setCoord(2,17);
                cout << "                                "; //clear space
                setCoord(2,18);
                cout << "                                "; //clear space
                setCoord(2,17);
                cout << "Sorry, you cannot afford " << buyWater;
                setCoord(2,18);
                cout << "1L bottle(s) of water, but you";
                setCoord(2,19);
                cout << "can buy " << (int)(buyWater = totalCash/costWater) << " bottle(s) and have";
                setCoord(2,20);
                cout << "$" << (totalCash - (costWater*buyWater))/100.00 << " left.";
                setCoord(2,21);
                cout << "Please re-enter a new amount of";
                setCoord(2,22);
                cout << "1L bottles of water to buy: ";
                continue;
                }
             else {
                setCoord(2,17);
                cout << "                                "; //clear space
                setCoord(2,18);
                cout << "                                "; //clear space
                setCoord(2,19);
                cout << "                                "; //clear space
                setCoord(2,20);
                cout << "                                "; //clear space
                setCoord(2,21);
                cout << "                                "; //clear space
                setCoord(2,22);
                cout << "                                "; //clear space
                setCoord(2,17);
                cout << "You have bought " << buyWater;
                setCoord(2,18);
                cout << "1L bottle(s) of water.";
                Sleep(3000); //pause message
                setCoord(2,17);
                cout << "                                "; //clear space
                setCoord(2,18);
                cout << "                                "; //clear space
                break;
                }
         } while(true);

         // Update water inventory and totalCash
         // ------------------------------------
         numWater = numWater + buyWater;
         setCoord(24,3);
         cout << "     ";
         setCoord(24,3);
         printf("%4.2f", numWater);

         totalCash = totalCash - totalCost;
         setCoord(15,5);
         cout << "            ";
         setCoord(15,5);
         cout << totalCash/100.00;

         // Print max number of glasses that can be sold
         // --------------------------------------------
         maxGlasses = getMaxSales(numLemons,numWater,numSugar);
         setCoord(33,6);
         cout << "  ";
         setCoord(33,6);
         cout << maxGlasses;

         // Clear away global market warnings
         // ----------------------------------
         y = 0;
         do{
            setCoord(38,y);
            cout << "                                         ";
            y++;
         }while(y < 20);

         // Get price of 1 glass of lemonade from user
         // ------------------------------------------
         setCoord(39,1);
         cout << "How much would you like to charge for a";
         setCoord(39,2);
         cout << "glass of lemonade (in cents)?: ";
         cin >> price;

         // Display Stand
         // -------------
         system("CLS");
         setCoord(0,0);

         cout << "======== " << username << "\'s LEMONADE!! ONLY $" << price/100.00 << "! ========";

         // Duck disturbance
         //-----------------
         cout << "\n\nA duck walks up to your lemonade stand and says,";
         cout << "\n\n      ,~~.\n";
         cout << "     \(  9 \)-_,\n";
         cout << "\(\\___ )==\'-\'\n";
         cout << " \ .   ) )\n";
         cout << "  \ \`-\' /\n";
         cout << "   `~|-\'\n";
         cout << "     \"--\n";

         cout << "[Duck]: \"Hey!";
         Beep(523,300);
         Sleep(100);
         Beep(440,300);
         Sleep(100);
         Beep(349,300);
         Sleep(100);
         cout << " Got any grapes?\"";

         cout << "\n\nWhat do you say? Choose from the following (A/B): ";
         cout << "\n   A. No, but we have lemonade for $" << price/100.00 << "!";
         cout << "\n   B. No, but do you want me to buy you some?";
         cout << "\nEnter here: ";
         cin >> sentencechoice;
         system("PAUSE");
         system("CLS");

         // Determine sales for the day
         // --------------------------
         numSales = getSales(price,maxGlasses);
         peopleleft = rand()%(numSales/2) + 1;

         // Record income for the day
         // --------------------------
         costGrapes = rand()%301 + 50; // cost between 50 cents & $3.50
         income = price * numSales;
         totalCash = totalCash + income;

         // Print sales and income for the day
         // ----------------------------------
         if (sentencechoice == "A"
          || sentencechoice == "a"){
            cout << "Today you sold " << numSales - peopleleft << " glasses of lemonade, " << username << "!";
            cout << "\nYou could have sold " << getSales(price,maxGlasses) << " glasses,";
            cout << "\nbut the duck scared customers away!";

            cout << "\n\nSo, you made $";
            printf("%4.2f",income/100.00);
            cout << " instead.";

            cout << "\n\nYou now have $";
            printf("%4.2f",totalCash/100.00);
            cout << " towards your goal of $" << incomeGoal << "!\n";
          }
          else if (sentencechoice == "B"
                || sentencechoice == "b"){
                 cout << "\n\nToday you sold " << numSales << " glasses of lemonade, " << username << "!";

                 cout << "\n\nYou made $";
                 printf("%4.2f",income/100.00);
                 cout << " but you bought grapes for the duck which";
                 cout << "\ncosted $" << costGrapes/100.00 << " so you end with: $" << income/100.00 - costGrapes/100.00;


                 cout << "\n\nYou now have $";
                 printf("%4.2f",(totalCash - costGrapes)/100.00);
                 cout << " towards your goal of $" << incomeGoal << "!\n";
          }


         system("PAUSE");
         system("CLS");


		 // Calculate supplies left
         // -----------------------
         numLemons -= (numSales/2.0);
         numWater -= (numSales/4.0);
         numSugar -= (numSales/20.0);


    // Repeats each day
    } while(day < maxDays);

    // Determine win/loss
    // -------------------
    if(totalCash/100.00 < incomeGoal){
        cout << "Too bad, " << username << ", you lost!";
    }
    else if (totalCash/100.0 > incomeGoal){
        cout << "Congrats, " << username << "!! You won!";
    }

    system("PAUSE"); // pause screen

    // user choice to repeat program
    //------------------------------

    cout << "Thank you for playing, " << username << "!";
    cout << "\nWould you like to play again? (Y/N)";
    cin >> choice;

if (choice == "YES"
 || choice == "Yes"
 || choice == "yes"
 || choice == "Y"
 || choice == "y"){
    continue;
 }
 else if (choice == "NO"
       || choice == "No"
       || choice == "no"
       || choice == "N"
       || choice == "n"){
        break;
    }
else {
    do {
        cout << "Enter a VALID choice (Y/N): ";
        cin >> choice;
}while(true);
}

//end of program loop
//-------------------
}while(true);
    // end program
    // -----------
    return 0;

} // main

// -----------------------------------------------------------------------------
// Function: getSales
// Input:    price in cents, max # glasses that can be sold
// Output:   Actual number of sales
// Purpose: generates a number of sales based on set price and random numbers
// -----------------------------------------------------------------------------
int getSales(int price, int maxGlasses) {

    int numSales = 0;
    int calcSales = 0;
    int randNum = rand() % 100 + 1;

    // formula requires prices to be between 10 cents and 3 dollars
    if (price < 1) price = 1;
    else if (price > 300) price = 300;

    // formula for sales
    calcSales = (int)((-1 / 3.0) * price) + 100;

    // numSales is halfway btwn randNum and calcSales
    int difference = randNum - calcSales;
    if (randNum > calcSales)
        numSales = randNum - (difference / 3);
    else
        numSales = calcSales - (difference / 3);

	if (numSales > 100) numSales = 100;

    return (int)(maxGlasses * (numSales / 100.0));
} // getSales


// -----------------------------------------------------------------------------
// Function: getMaxSales
// Input:    numLemons - number of lemons in inventory
//           numWater  - number of litres of water in inventory
//           numSugar  - number of bags of sugar in inventory
// Output:   Maximum number of glasses of lemondade that can be sold
// Purpose:  determine how many glasses of lemonade that can be sold
// -----------------------------------------------------------------------------
int getMaxSales(double numLemons, double numWater, double numSugar){
     int a = int (numLemons * 2);  // 2 glasses /lemon
     int b = int (numWater * 4);   // 4 glasses / litre water
     int c = int (numSugar * 20);  // 20 glasses / 1 kg sugar
     return (a < b && a < c) ? a : ((b < c) ? b : c);
} // getMaxSales
