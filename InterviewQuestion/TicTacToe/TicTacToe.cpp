#include<iostream>
#include<thread>
#include<mutex>
#include<bits/stdc++.h>
#include<deque>
using namespace std;

enum Piece {
    X,O,Y,G,H
};

enum Status {
    AVAILABLE,
    OCCUPIED
};

class Square {
    public:
    Piece p;
    Status stat;
    Square() {
        stat = AVAILABLE;
    }
}; 

class Board {
    public:
    int size;
    vector<vector<Square*> >tiles;
    Board(int size) {
        for(int i=0;i<size;i++) {
            vector<Square*>v;
            for(int j=0;j<size;j++) {
                v.push_back(new Square());
            }
            tiles.push_back(v);
        }
    }

    void addPieceToTile(int row, int col, Piece p) {
        //TO DO
    }

    bool checkIfValidMove(int row, int col) {
        //TO DO
    }
};

class Player {
    public:
    string name;
    int rank;
    int gamesWon, gamesPlayed;
    Player(string name) {
        this->name = name;
        gamesWon = 0;
        gamesPlayed = 0;
        rank = INT_MAX;
    }
};

class ActivePlayer {
    public:
    Player *player;
    Piece playingPiece;
    ActivePlayer(Piece pc, Player *pl) {
        this->playingPiece = pc;
        this->player = pl;
    }
};

class Game {
    public:
    Board *board;
    deque<ActivePlayer*>currPlayer;
    ActivePlayer* winner;

    Game(int size, ActivePlayer *p1, ActivePlayer *p2) {
        currPlayer.push_back(p1);
        currPlayer.push_back(p2);
        winner = NULL;
        this->board = new Board(size);
    }

    void startGame() {
        //TO DO
        cout<<"Game Started\n";
    }

    bool checkVictory() {
        //TODO
    }

};

class Ranking {
    public:
    vector<Player*>playerList;
    void recalcRanking(Game *game) {
        
        cout<<"Ranking calculated"<<endl;
    }

};

class TicTacToe {


    public:
    vector<Player*>playerList;
    vector<Game*>gameList;
    Ranking *rank;

    TicTacToe() {
        rank = NULL;
    }


    void addPlayer(Player *p1) {
        p1->rank = this->playerList.size()+1;
        this->playerList.push_back(p1);
        cout<<"Player added"<<endl;
    }
    Game* createGame(int size, Player *p1, Player *p2, Piece pe1, Piece pe2) {
        ActivePlayer *activePlayer1 = new ActivePlayer(pe1, p1);
        ActivePlayer *activePlayer2 = new ActivePlayer(pe2, p2);
        Game *game = new Game(size, activePlayer1, activePlayer2);
        gameList.push_back(game);
        cout<<"Game created"<<endl;
        return game;
    }
    void startGame(Game *game) {
        game->startGame();
    }

    void calcRanking(Game *game) {
        rank->recalcRanking(game);
    }
};

int main() {
    TicTacToe *tictactoe = new TicTacToe();
    Player *p1 = new Player("Prerna");
    Player *p2 = new Player("Aditya");

    tictactoe->addPlayer(p1); tictactoe->addPlayer(p2);
    Game *game = tictactoe->createGame(3, p1, p2, X, O);
    tictactoe->startGame(game);
    tictactoe->calcRanking(game);


}