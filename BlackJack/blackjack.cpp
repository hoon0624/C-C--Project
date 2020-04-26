// author: Donghoon Lee
#include <iostream>
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

// construct card with rank and type 
Card::Card(Rank pRank, Type pType) {
    this->aRank = pRank;
    this->aType = pType;
}

int Card::getValue() {
    return this->aRank;
}

void Card::displayCard() {
    // display J Q K as characters instead of their int values	
    if(this->aRank == 'J' || this->aRank == 'Q' || this->aRank == 'K') {
        cout << (char) this->aRank << (char) this->aType << " ";
    }
    else {
        cout << this->aRank << (char) this->aType << " ";
    }
}

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
    // Hand has attribute vector of Card
    vector<Card> cards;
    vector<Card>::iterator Iter;
};

Card Hand::getCard() {
    return this->cards.back();
}
void Hand::add(Card pCard) {
    this->cards.push_back(pCard);
}

void Hand::clear() {
    this->cards.clear();
}

int Hand::getTotal() const {
    int total = 0;
    int numOfAce = 0;
    // iterate through cards 
    for(auto card : this->cards) {
	// if the card is ACE, numOfAce++ and add 1 to the toatl for now     
        if(card.getValue() == 1) {
            numOfAce++;
            total += card.getValue();
        }
	// if the card is JACK, QUEEN, KING, add 10 
        else if(card.getValue() > 10){
            total += 10;
        }
        else {
            total += card.getValue();
        }
    }
    // make ACE = 11 if the total does not exceed 21
    for(int i=0; i < numOfAce; i++) {
        if(total + 10 <= 21) {
            total += 10;
        } 
    }
    return total; 
}

// display all the cards in the hand
void Hand::displayHand() {
    for(auto card : this->cards) {
        card.displayCard();
    }
}

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

int Deck::getSize() {
    return this->cards.size();
}

void Deck::Populate() {
    // making enums iterable
    constexpr std::initializer_list<Rank> all_Rank = {ace, two, three, four, five, six, seven, eight, nine, ten, jack, queen, king};
    constexpr std::initializer_list<Type> all_Type = {clubs, diamonds, hearts, spades};
    
    for(auto suit : all_Type) {
        for(auto rank : all_Rank) {
            this->cards.push_back(Card(rank, suit));
        }
    }
}

void Deck::shuffle() {
    // use time to randomly generate seed
    std::srand(std::time(0));
    random_shuffle(this->cards.begin(), this->cards.end()); 
}

void Deck::deal(Hand &pHand) {
    // add the last card of the deck to the hand and delete it from the deck
    pHand.add(this->cards.back());
    cards.pop_back();
}

class AbstractPlayer: public Hand
{
public:
    virtual bool isDrawing() const = 0;
    bool isBusted();
    virtual ~AbstractPlayer() {};
};

bool AbstractPlayer::isBusted() {
    if(getTotal() > 21) {
        return 1; 
    }
    return 0;
}

class HumanPlayer: public AbstractPlayer
{
public:
    HumanPlayer() = default;
    bool isDrawing() const;
    void announce(AbstractPlayer &opponent);
    ~HumanPlayer() {};
};

bool HumanPlayer::isDrawing() const {
    
    string response;
    cout << "Do you want to draw? (y/n): " << " ";
    
    cin >> response;
    
    while(response != "") {
       if(response == "y") {
           cin.clear();
            return true;
        }
        else if(response == "n") {
            cin.clear();
            return false;
        }
        else if(cin.fail()) {
            cout << "Please type 'y' or 'n': \t";
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cin >> response;
        }
    }
    return false;
}

void HumanPlayer::announce(AbstractPlayer &opponent) {
    if(this->isBusted()) {
        cout << "Player has lost" << endl;
    } 
    else if(opponent.isBusted()) {
        cout << "Player has won" << endl;
    }
    else if(this->getTotal() > opponent.getTotal()) {
        cout << "Player has won" << endl;
    }
    else if(this->getTotal() < opponent.getTotal()) {
        cout << "Player has lost" << endl;
    }
    else if(this->getTotal() == opponent.getTotal()) {
        cout << "The game has been tied" << endl;
    }
}

class ComputerPlayer: public AbstractPlayer
{
public:
    ComputerPlayer() = default;
    bool isDrawing() const;
    ~ComputerPlayer() {};
    
};

bool ComputerPlayer::isDrawing() const {
    // computer wants to draw if they have hand less or equal to 16
    if(this->getTotal() <= 16) {
        return true;
    }
    else {
        return false;
    }
}

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

void BlackJackGame::play() {
    
    cout << "Welcome to the Comp322 Blackjack table!" << endl;
    // make casino's hand clear and prepare a new deck for the ganme
    this->m_casino.clear();
    this->m_deck.clear();
    this->m_deck.Populate();
    this->m_deck.shuffle();
    
    HumanPlayer player;
    
    cout << this->m_deck.getSize() << endl;
    
    //dealing cards
    this->m_deck.deal(this->m_casino);
    this->m_deck.deal(player);
    this->m_deck.deal(player);
    
    // displaying computer's hand
    cout << "Casino: "; 
    this->m_casino.displayHand();
    cout << "[" << m_casino.getTotal() << "]" << endl;
    
    // displaying player's hand
    cout << "Player: ";
    player.displayHand();
    cout << "[" << player.getTotal() << "]" << endl;
    
    // ask player if they want to draw
    bool draw = player.isDrawing();
    
    while(draw) {
        this->m_deck.deal(player);
        
        cout << "Player: ";
        player.displayHand();
        cout << "[" << player.getTotal() << "]" << endl;
        if(player.isBusted()) {
            cout << "Player busts." << endl;
            cout << "Casino wins." << endl;
            return;
        }
        draw = player.isDrawing();
    }
 
    bool computer_draw = this->m_casino.isDrawing();
    while(computer_draw) {
        this->m_deck.deal(this->m_casino);
        
        cout << "Casino: "; 
        this->m_casino.displayHand();
        cout << "[" << m_casino.getTotal() << "]" << endl;
        
        if(this->m_casino.isBusted()) {
            cout << "Casino busts." << endl;
            cout << "Player wins." << endl;
            return;
        }
        
        computer_draw = this->m_casino.isDrawing();
    }
    
    // announce the winner!
    player.announce(this->m_casino);
}

