#ifndef PROJECT_H
#define PROJECT_H
#include <iostream>
#include <iomanip> //design
#include <fstream> //read and write data
#include <string>
#include <cstring>       //convert string to c string
#include <algorithm>     //sort
#include <vector>        //vector
#include <utility>       //vector pair
#include <set>           //not include same element
#include <unordered_map> //mapscards
#include <map>           //map
#include <chrono>        //time
#include <thread>        //time
using namespace std;
class Database
{
public:
    string username, password, displayname, moneyInWeb;

    string toUpperStr(string);
    bool checkIfNewWeb();
    void registerUser();
    void loginUser(int &);
    void writeData2_txt(const map<pair<string, string>, vector<string>> &, const string &);
    void importDatafromfile(string, vector<string> &, vector<string> &);
    void Delete_();
    // เพิ่มเติม
    void setDisplayName();
};

struct Deck
{
private:
    char ranks[13] = {'2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A'};
    char suits[4] = {'\3', '\4', '\5', '\6'};

public:
    Deck();
    vector<string> allCardsLeft; // ไพ่ใน Deck ที่เหลือ ณ ตอนนั้น
    void shuffle();              // สับไพ่
    void showcardsLeft();        // Show cards ที่เหลือ
};
struct Player
{
public:
    Player(string, long long int);
    pair<string, pair<int, pair<int, int>>> rankOfHand; // ประกอบไปด้วย (Rankไพ่บนมือ(String),{Rank(int),{ไพ่สูงสุด,ไพ่รองคู่สูงสุด}})
    string name;                                        // ชื่อคนเล่น
    long long int moneyInWeb;                           // เงินในระบบ
    int chip;                                           // เงินในเกม
    int moneyToRaise;                                   // เงินที่ Raise เพิ่มจาก Bet สูงสุด ณ ตอนนั้น
    int accumulateBet;                                  // เงินที่เราลงเดิมพันไปแล้ว
    vector<string> cards;                               // การ์ดบนมือเรา มี 2 ใบ
    string action;                                      // การกระทำของเรา ณ ตอนนั้น Call Raise Bet Fold Cheat etc.
    string role;                                        // ตำแหน่งของเรา dealer ,Small Blind, Big Blind
    int order;                                          // คำสั่งของเรา
};
class PokerGame
{
private:
    vector<string> cardsOnBoard; // ไพ่บนBoard
    int num_player;
    int current;   // position
    int lastRaise; // position
    int dealer;    // position
    int round;
    int mandatory_bet;
    int pot;        // เงินใน Board รวม
    int highestBet; // เงินเดิมพันสูงสุด ณ ตอนนี้resetAccumulateBet
    bool restart;
    bool hasBetRaiseOrAllIn;

public:
    PokerGame(Deck &, int, int, int);
    ~PokerGame();
    vector<Player *> players;
    Deck deck;
    map<int, vector<string>> od;
    void showTurn();
    void createOrderTable();
    void topboard();
    void midboard0();
    void midboard3();
    void midboard4();
    void midboard5();
    void botomtboard();
    void actionboard();
    void showBoard1();
    void showBoard2();
    void showBoard3();
    void showBoard4();;
    void showMoneyPot();
    void showMoneyBet();
    void showPlayerMoney(Player *);
    void showPlayerCards(Player *);
    void showHandRank(Player *p);
    void showChoice();
    void holecards();
    void communityCards(int);
    void checkHand(Player *p);
    void recieveOrder(Player *);
    void checkOrder(Player *);
    void doOrder(Player *);
    void updateLastBetRaiseOrAllIn(Player *p);
    void check(Player *);
    void bet(Player *);
    void call(Player *);
    void cheat();
    void raise(Player *);
    void allIn(Player *);
    void fold(Player *);
    void assignRole();
    void resetAction();
    void resetHandRank();
    void resetAccumulateBet();
    void moneyForMandatoryBet(Player *, Player *);
    bool findWinner();
    void updateRound();
    void beforeStart();
    void preflop();
    void flop();
    void turn();
    void river();
};
#endif
