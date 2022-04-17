#include "../headers/chess.h"
#include <iostream>

//Constructors
chess::chess(){
    char alpha[8] = {'a','b','c','d','e','f','g'};
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            board[i][j] = new coordinate(i, j, (i%2==0 != j%2==0)?true:false); // create board.
        }
    }
    this->white = new team(false, *board);
    this->black = new team(true, *board);
    

};
chess::team::team(bool color, coordinate** board){
    this->color = color;
    this->p1 = new pawn("p1", color, color?&board[0][1]:&board[0][6]);
    if(color) board[0][1].occupant = p1 ; else board[0][6].occupant = p1;
    this->p2 = new pawn("p2", color, color?&board[1][1]:&board[1][6]);
    if(color) board[1][1].occupant = p2; else board[1][6].occupant = p2;
    this->p3 = new pawn("p3", color, color?&board[2][1]:&board[2][6]);
    if(color) board[2][1].occupant = p3; else board[2][6].occupant = p3;
    this->p4 = new pawn("p4", color, color?&board[3][1]:&board[3][6]);
    if(color) board[3][1].occupant = p4; else board[3][6].occupant = p4;
    this->p5 = new pawn("p5", color, color?&board[4][1]:&board[4][6]);
    if(color) board[4][1].occupant = p5; else board[4][6].occupant = p5;
    this->p6 = new pawn("p6", color, color?&board[5][1]:&board[5][6]);
    if(color) board[5][1].occupant = p6; else board[5][6].occupant = p6;
    this->p7 = new pawn("p7", color, color?&board[6][1]:&board[6][6]);
    if(color) board[6][1].occupant = p7; else board[6][6].occupant = p7;
    this->p8 = new pawn("p8", color, color?&board[7][1]:&board[7][6]);
    if(color) board[7][1].occupant = p8; else board[7][6].occupant = p8;
    this->r1 = new rook("r1", color, color?&board[0][0]:&board[0][7]);
    if(color) board[0][0].occupant = r1; else board[0][7].occupant = r1;
    this->k1 = new knight("k1", color, color?&board[1][0]:&board[1][7]);
    if(color) board[1][0].occupant = k1; else board[1][7].occupant = k1;
    this->b1 = new bishop("b1", color, color?&board[2][0]:&board[2][7]);
    if(color) board[2][0].occupant = b1; else board[2][7].occupant = b1;
    this->k  = new king("k", color, color?&board[3][0]:&board[3][7]);
    if(color) board[3][0].occupant = k; else board[3][7].occupant = k;
    this->q  = new queen("q", color, color?&board[4][0]:&board[4][7]);
    if(color) board[4][0].occupant = q; else board[4][7].occupant = q;
    this->b2 = new bishop("b2", color, color?&board[5][0]:&board[5][7]);
    if(color) board[5][0].occupant = b2; else board[5][7].occupant = b2;
    this->k2 = new knight("k2", color, color?&board[6][0]:&board[6][7]);
    if(color) board[6][0].occupant = k2; else board[6][7].occupant = k2;
    this->r2 = new rook("r2", color, color?&board[7][0]:&board[7][7]);
    if(color) board[7][0].occupant = r2; else board[7][7].occupant = r2;
};
chess::pawn::pawn(std::string id, bool color,chess::coordinate* start):piece(id,color,start){
    first_move = true;
    opposite_end = false;
};
chess::knight::knight(std::string id, bool color, chess::coordinate* start):piece(id,color,start){};
chess::bishop::bishop(std::string id, bool color, chess::coordinate* start):piece(id,color,start){};
chess::rook::rook(std::string id, bool color, chess::coordinate* start):piece(id,color,start){};
chess::king::king(std::string id, bool color, chess::coordinate* start):piece(id,color,start){
    check = false;
};
chess::queen::queen(std::string id, bool color, chess::coordinate* start):piece(id,color,start){};
chess::piece::piece(std::string id, bool color, chess::coordinate* start){
    this->alive = true;
    this->pos = start;
    this->color = color;
};
chess::coordinate::coordinate(int x, int y, bool black){
    this->x = x;
    this->y = y;
    this->black = black;
    this->occupant = nullptr;
};

//Member functions
bool chess::piece::getColor(){return color;};
chess::coordinate* chess::piece::getPos(){return pos;};
chess::piece* chess::pawn::move(bool color, std::string dest, chess::coordinate** board){
    //dest should be of the form "1B" i.e. first char is int x, second is char y
    try{
        int x = int(dest[0]);
        char y = dest[1];
        coordinate* pos = getPos();
        if(x == (color?pos->x+1:pos->x-1) || //normal move
        (first_move && x == color?pos->x+2:pos->x-2) // first move could be +2
        && 0<=x<=7){    //space must exist on board
            piece* space_occupant = board[x][pos->y].occupant;
            if(space_occupant == nullptr){ // space unoccupied
                pos->x = x;
                first_move = false;
                return this;
            }
            else{
                if(space_occupant->getColor() != color){
                    pos->x = x;
                    first_move = false;
                    space_occupant->capture(); // removes piece from game
                    board[x][pos->y].occupant = this;
                }
                else{
                    std::cout << "Your own piece is in that spot.\n";
                    return this;
                }
            }
        }
    
    }catch(error_t e){
        std::cout<<"Bad input\n";
        return this;
    }
    return this;
};
bool chess::piece::capture(){
    alive = false;
    pos = nullptr;
    return true;
};