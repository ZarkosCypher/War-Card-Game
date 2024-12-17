// Card Game War.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// Copywrite -> this code was started 7 May 2022 created by ME and finished 11 May 2022 4:36AM 
// This was the final for my C++ class and i got a 100
/*
* this is a program that is designed to play a card game named war
* the point of the card game is to get all the other cards from the opponent 
* it is typically played between 2 players each being delt 26 cards playing to get all 52
* the way the game is played is by flipping the top card of each players deck 
* who ever ends up getting a higher card (ranked a - m, a being the lowest and m being the highest)
* if the 2 end up getting the same ranking card then they go to war how war works is 
* each person places 3 facedown cards on the table and flip the 4th card and who ever has the higher ranking card 
* takes all the cards that were put on the table 
* more information on the card game here - https://www.wikihow.com/Play-War-(Card-Game)
*/

#include <iostream>
#include <string>  // to be able to use stings 
#include <cstdlib> // for the random function 
#include <ctime> // to seed the random function to always give random results 
using namespace std; // for the cout statements 

// a list of all the functions 
int Random(int mi, int ma);
void createCards();
void shuffledCardDeck(string card[]);
void dealDecks();
void display_winner();
void playGame();
void war();

// arrays to hold the cards in the multiple decks
const string cardSuit[4] = { "spade-", "club--", "dimond", "heart-" };
const string cardValues[13] = { "-A--(a)","-2--(b)","-3--(c)","-4--(d)","-5--(e)","-6--(f)","-7--(g)","-8--(h)","-9--(i)","10--(j)","-J--(k)","-Q--(l)","-K--(m)" };
string deck[52]; 

// the table/cards each player holds
string botCards[52]; // the bot cards
int bot = 26; // counter to show mow many cards the bot has
string playerCards[52]; // the pkayer cards
int player = 26; // counter to show how many cards the player has

int main() // main finction were all the code is strored 
{
    // assings the seed for the randomizer 
    unsigned seed = time(0); 
    srand(seed); 

    // sets up the deck of cards, shuffles and deals them 
    createCards();
    shuffledCardDeck(deck);
    dealDecks();

    // welcome screen for the player and tells the set of rules and actions the user can take 
    cout << "Hello World! this is a program to play a game of war!\n";
    cout << "Cards are ranked a - m, a is the lowest and m is the highest\n";
    cout << "you and a bot are dealt 2 piles of 26 cards, you both show the card on the top of your deack\n";
    cout << "and the card that is lower is beat and the winder puts it in the bottom of their pile\n";

    cout << "What action do you want to do" << endl;
    cout << "1 - next round" << endl;
    cout << "2 - fast forward game to end and view results" << endl;
    cout << "3 - end" << endl;

    int answer;
    do //  while loop to make sure the player inputs a valid input 
    {
        if (bot <= 0 || player <= 0) // checks wether the game is over of not and stops the loop 
        {
            display_winner();
            break;
        }

        cout << "choose your action: ";
        cin >> answer; // gets a responce from the player to see what action they wish to do 


        if (answer == 1) // this plays the game at the players speed and each time they choose this 
        {                // the game progresses by 1 round 
            if (bot <= 0 || player <= 0)
            {
                display_winner();
                break;
            }
            else
            {
                playGame();
            }
        }


        else if (answer == 2) // this more or less simulates the game or fast forwards the game to the end 
        {
            while (bot > 0 || player > 0)
            {
                if (bot <= 0 || player <= 0)
                {
                    display_winner();
                    break;
                }
                else
                {
                    playGame();
                }
            }
            break;
        }


        else if (answer == 3) // this ends the game with or without a winer 
        {
            cout << "Game ended!" << endl;
            break;
        }

        else // this desplays the message if the user imputs a option thats not avalible 
        {
            cout << "that is an incorect option please choose from the list\n";
        }

    } while (answer != 3); // the while checker to see if the player has desided to end the game 

    cout << "Thansk for playing!" << endl; // thanks the player for playing the game 
}

// this is a randomizer function that produses a random number between the min and max value 
int Random(int mi, int ma)//---------------------------------------------------------------------------------------------
{
    const int MIN_VALUE = mi;
    const int MAX_VAlUE = ma;
    int ran = (rand() % MAX_VAlUE - MIN_VALUE + 1) + MIN_VALUE;
    return ran;
}//----------------------------------------------------------------------------------------------------------------------

// creats a deck of cards in to the deck array from the top 2 already filled out const arrays 
void createCards()//-----------------------------------------------------------------------------------------------------
{
    int a = 0;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 13; j++)
        {
            deck[a] = cardSuit[i] + cardValues[j];
            a++;
        }
    }
}//----------------------------------------------------------------------------------------------------------------------

// this function shuffles the deck of cards, it finds random placements and just swaps them arround shuffaling the deck 
void shuffledCardDeck(string card[])//-----------------------------------------------------------------------------------
{
    for (int i = 0; i < 52; i++)
    {
        int r = i + (rand() % (52 - i));
        swap(card[i], card[r]);
    }
}//----------------------------------------------------------------------------------------------------------------------

// gives the bot and player each 25 cards from the shuffled deck 
void dealDecks()//-------------------------------------------------------------------------------------------------------
{
    int j;
    j = 0; // sets a counter 
    for (int i = 0; i < 26; i++) // gives the bot the first 26 shuffled cards
    {
        botCards[j] = deck[i];
        j++;
    }
    j = 0; // resets counter 
    for (int i = 26; i < 52; i++) // gives the player the last of the 26 shuffled cards 
    {
        playerCards[j] = deck[i];
        j++;
    }
}//----------------------------------------------------------------------------------------------------------------------

// just a function that desplayes who won the game in the end
void display_winner()//--------------------------------------------------------------------------------------------------
{
    if (bot <= 0)
    {
        cout << "you win and bot looses! you had " << player << " cards!\n";
    }
    if (player <= 0)
    {
        cout << "bot wins you loose! bot had " << bot << " cards!\n";
    }
}//----------------------------------------------------------------------------------------------------------------------

// the function were the actual game is determend for each turn and keeps the game rules in check
void playGame()//--------------------------------------------------------------------------------------------------------
{
    if (bot > 0 && player > 0) // checks if the bot and player are both over 0 cards (looking at the counter near the array)
    {
        cout << "bot has " << botCards[bot - 1] << endl;          // displays the bot cards
        cout << "player has " << playerCards[player - 1] << endl; // displays the player cards

        char b = botCards[bot - 1][13 - 2];        //finds the rank of the current bot card
        char p = playerCards[player - 1][13 - 2];  //finds the rank of the current player card

        if (b > p) // checks if the bot card is higher than the player card
        {
            // pushes the array back for the bot and then adds the 2 cards to the bottom of the dack 
            bot++; // adds to the amount of cards the bot has 
            for (int i = bot; i != 0; i--) // pushes the array back 
            {
                botCards[i - 1] = botCards[i - 2];
            }
            botCards[0] = playerCards[player - 1]; // adds the wining card from the round to the bttom of the bot deck
            for (int i = bot; i != 0; i--) // pushes the array back again 
            {
                botCards[i] = botCards[i - 1];
            }
            botCards[0] = botCards[bot]; // adds the wining player card to the botton of the bot deck 
            botCards[bot] = "";

            playerCards[player - 1] = ""; // removes players loosing card
            player--; // chnages the counter of how many cards the player has 

            cout << "bot won they have " << bot << " cards now.\n"; // displays the bot stats 
            cout << "you have " << player << " cards now.\n"; // dislays the player stats 
        }
        else if (p > b) // checks if the plaer has a higher card and does the same thing like with the bot but for the player 
        {
            player++; 
            for (int i = player; i != 0; i--)
            {
                playerCards[i - 1] = playerCards[i - 2];
            }
            playerCards[0] = botCards[bot - 1];
            for (int i = player; i != 0; i--)
            {
                playerCards[i] = playerCards[i - 1];
            }
            playerCards[0] = playerCards[player];
            playerCards[player] = "";

            botCards[bot - 1] = "";
            bot--;

            cout << "you won you have " << player << " cards now.\n";
        }
        else if (p == b) // checks and sees if the cards are equal and if they are there is war 
        {
            cout << "It is War!\n";
            war();
        }
        else // if a crash or somethign wrong happens this cathches it and errors or displays end game 
        {
            cout << "End Game!\n";
        }
        cout << endl;
    }
    else // if the amount of cards is at 0 for one of the players then it desplays that the game is over 
    {
        cout << "Game Over!" << endl;
    }
}//----------------------------------------------------------------------------------------------------------------------

// this is what happens in the rare occation that the cards are equal to eachother (when war is triggured)
void war()//-------------------------------------------------------------------------------------------------------------
{
    char b = botCards[bot - 1][13 - 2];       // finds the bot cards rank 
    char p = playerCards[player - 1][13 - 2]; // finds the player cards rank 

    int num = 4; // counter of what card is at play for the calculations 

    int tBot = bot;       // sets the theoretical amount of cards 
    int tPlayer = player; // sets the theoretical amount of cards 

    do
    {
        if (tPlayer >= 5 && tBot >= 5) // checks if both players have more than 5 cards in their decks
                                       // checks the theoretical cards that are left
        {
            cout << "bot has " << botCards[bot - (1 + num)] << endl;          //displays what card is at play  
            cout << "player has " << playerCards[player - (1 + num)] << endl; //displays what card is at play 

            b = botCards[bot - (1 + num)][13 - 2];       //finds the 4th card (technicaly 3 cards face down and 4th one plays)
            p = playerCards[player - (1 + num)][13 - 2]; //finds the 4th card (3 cards face down 4th one plays)

            if (b > p) // if the bot has a higher card 
            {
                for (int j = 0; j < num + 1; j++) //gives the bot all the cards that are theoreticaly on the table 
                                                  //and then actualy changes the real amount on each deck 
                {
                    bot++;
                    for (int i = bot; i != 0; i--)
                    {
                        botCards[i - 1] = botCards[i - 2];
                    }

                    botCards[0] = playerCards[player - 1];
                    for (int i = bot; i != 0; i--)
                    {
                        botCards[i] = botCards[i - 1];
                    }
                    botCards[0] = botCards[bot];
                    botCards[bot] = "";

                    playerCards[player - 1] = "";
                    player--;
                }

                cout << "bot won they have " << bot << " cards now.\n";
                cout << "you have " << player << " cards now.\n";
            }
            else if (p > b) //if the player has a higher card then all the theoretical table cards are given to the player 
            {
                for (int j = 0; j < num + 1; j++)
                {
                    player++;
                    for (int i = player; i != 0; i--)
                    {
                        playerCards[i - 1] = playerCards[i - 2];
                    }

                    playerCards[0] = botCards[bot - 1];
                    for (int i = player; i != 0; i--)
                    {
                        playerCards[i] = playerCards[i - 1];
                    }
                    playerCards[0] = playerCards[player];
                    playerCards[player] = "";

                    botCards[bot - 1] = "";
                    bot--;
                }

                cout << "you won you have " << player << " cards now.\n";
            }
            else // if there is another war then 3 more are placed face down and the 4th one is shown for the battle 
            {
                num = num + 4;         //sets the card that will be compaired next for both becks 
                tPlayer = tPlayer - 4; //sets the players theoretical cards
                tBot = tBot - 4;       //sets the bots theoretical cards 
                cout << "\n its War Again!\n" << endl;
            }
        }
        // if one of the players has less than 5 cards then this vertion is triggured were war is played by slightly diffrent rules 
        else if (tPlayer < 5 || tBot < 5)//-------------------------------
        {
            if (player < 5) // if the player has less than 5 cards 
            {
                b = botCards[bot - (1 + (player - 1))][13 - 2];
                p = playerCards[0][13 - 2];

                cout << "bot has " << botCards[bot - (1 + (player - 1))] << endl;
                cout << "player has " << playerCards[0] << endl;

                if (b > p) // if the bots cards are larger than players 
                {
                    for (int j = 0; j < 4; j++)
                    {
                        bot++;
                        for (int i = bot; i != 0; i--)
                        {
                            botCards[i - 1] = botCards[i - 2];
                        }

                        botCards[0] = playerCards[player - 1];
                        for (int i = bot; i != 0; i--)
                        {
                            botCards[i] = botCards[i - 1];
                        }
                        botCards[0] = botCards[bot];
                        botCards[bot] = "";

                        playerCards[player - 1] = "";
                        player--;
                    }

                    cout << "bot won they have " << bot << " cards now.\n";
                    cout << "you have " << player << " cards now.\n";
                }
                else if (p > b) // if players are larger than bots 
                {
                    for (int j = 0; j < 4; j++)
                    {
                        player++;
                        for (int i = player; i != 0; i--)
                        {
                            playerCards[i - 1] = playerCards[i - 2];
                        }

                        playerCards[0] = botCards[bot - 1];
                        for (int i = player; i != 0; i--)
                        {
                            playerCards[i] = playerCards[i - 1];
                        }
                        playerCards[0] = playerCards[player];
                        playerCards[player] = "";

                        botCards[bot - 1] = "";
                        bot--;
                    }

                    cout << "you won you have " << player << " cards now.\n";
                }
                else // this removes 5 from each of the players after one of the players has less than 5 cards 
                {
                    bot = bot - 5;
                    player = player - 5;
                    break;//-----------------------------------
                }
            }

            else if (bot < 5) //if the bot has less then 5 cards
            {
                b = botCards[0][13 - 2];
                p = playerCards[player - (1 + 4)][13 - 2];

                cout << "bot has " << botCards[0] << endl;
                cout << "player has " << playerCards[player - (1 + (bot - 1))] << endl;

                if (b > p)
                {
                    for (int j = 0; j < 4; j++)
                    {
                        bot++;
                        for (int i = bot; i != 0; i--)
                        {
                            botCards[i - 1] = botCards[i - 2];
                        }

                        botCards[0] = playerCards[player - 1];
                        for (int i = bot; i != 0; i--)
                        {
                            botCards[i] = botCards[i - 1];
                        }
                        botCards[0] = botCards[bot];
                        botCards[bot] = "";

                        playerCards[player - 1] = "";
                        player--;
                    }

                    cout << "bot won they have " << bot << " cards now.\n";
                    cout << "you have " << player << " cards now.\n";
                }
                else if (p > b)
                {
                    for (int j = 0; j < 4; j++)
                    {
                        player++;
                        for (int i = player; i != 0; i--)
                        {
                            playerCards[i - 1] = playerCards[i - 2];
                        }

                        playerCards[0] = botCards[bot - 1];
                        for (int i = player; i != 0; i--)
                        {
                            playerCards[i] = playerCards[i - 1];
                        }
                        playerCards[0] = playerCards[player];
                        playerCards[player] = "";

                        botCards[bot - 1] = "";
                        bot--;
                    }

                    cout << "you won you have " << player << " cards now.\n";
                }
                else
                {
                    bot = bot - 5;
                    player = player - 5;
                    break;//----------------------------------------
                }
            }

            else // makes a winer if none of the above critera is met 
            {
                bot = bot - 5;
                player = player - 5;
                break;
            }
        }//---------------------------------------------------------
        else // failsafe if something bugges out 
        {
            cout << "something went wrong \n";
            break;
        }
    } while (b == p); // checks if in the off chance one or more wars are triggured it keeps going until war is over 
    cout << "war has ended\n";
}//----------------------------------------------------------------------------------------------------------------------
