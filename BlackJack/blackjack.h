// author: Donghoon Lee
#ifndef BLACKJACK_H
#define BLACKJACK_H

#include <vector>
#include <algorithm>
#include <random>
#include <ctime>

using namespace std;

enum Rank {ace=1, two, three, four, five, six, seven, eight, nine, ten, jack='J', queen='Q', king='K'};

enum Type {clubs='C', diamonds='D', hearts='H', spades='S'};

class Card 
{
    
public:

    Card(Rank rank, Type type);
    int getValue();
    void displayCard();
    ~Card(){};
        
private:
    Rank aRank;
    Type aType;
};

class Hand 
{

public:
    Hand() = default;
    void add(Card pCard);
    void clear();
    int getTotal() const;
    Card getCard();
    void displayHand();
    virtual ~Hand(){};
    
protected:
    vector<Card> cards;
    vector<Card>::iterator Iter;
};

class Deck: public Hand
{

public: 
    Deck() = default;
    void Populate();
    void shuffle();
    void deal(Hand &pHand);
    int getSize();
    ~Deck(){};
   
};

class AbstractPlayer: public Hand
{
public:
    virtual bool isDrawing() const = 0;
    bool isBusted();
    virtual ~AbstractPlayer() {};
};

class HumanPlayer: public AbstractPlayer
{
public:
    HumanPlayer() = default;
    bool isDrawing() const;
    void announce(AbstractPlayer &opponent);
    ~HumanPlayer() {};
};

class ComputerPlayer: public AbstractPlayer
{
public:
    ComputerPlayer() = default;
    bool isDrawing() const;
    ~ComputerPlayer() {};
    
};

class BlackJackGame 
{
public:
    BlackJackGame() = default;
    void play();
    ~BlackJackGame() {};
    
private: 
    Deck m_deck;
    ComputerPlayer m_casino;
};




#endif