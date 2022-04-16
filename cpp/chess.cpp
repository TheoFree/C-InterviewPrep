#include "../headers/chess.h"

chess::chess(){
    char alpha[8] = {'a','b','c','d','e','f','g'};
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            board[i][j] = new coordinate(i, alpha[j], (i != j)?true:false); // create board.
        }
    }
    this->white = new team(false, *board);
    this->black = new team(true, *board);
    

};

chess::team::team(bool color, coordinate** board){
    this->color = color;
    this->p1 = new pawn("p1", color, color?&board[0][1]:&board[0][6]);
    this->p2 = new pawn("p2", color, color?&board[1][1]:&board[1][6]);
    this->p3 = new pawn("p3", color, color?&board[2][1]:&board[2][6]);
    this->p4 = new pawn("p4", color, color?&board[3][1]:&board[3][6]);
    this->p5 = new pawn("p5", color, color?&board[4][1]:&board[4][6]);
    this->p6 = new pawn("p6", color, color?&board[5][1]:&board[5][6]);
    this->p7 = new pawn("p7", color, color?&board[6][1]:&board[6][6]);
    this->p8 = new pawn("p8", color, color?&board[7][1]:&board[7][6]);
    this->r1 = new rook("r1", color, color?&board[0][0]:&board[0][7]);
    this->k1 = new knight("k1", color, color?&board[1][0]:&board[1][7]);
    this->b1 = new bishop("b1", color, color?&board[2][0]:&board[2][7]);
    this->k  = new king("k", color, color?&board[3][0]:&board[3][7]);
    this->q  = new queen("q", color, color?&board[4][0]:&board[4][7]);
    this->b2 = new bishop("b2", color, color?&board[5][0]:&board[5][7]);
    this->k2 = new knight("k2", color, color?&board[6][0]:&board[6][7]);
    this->r2 = new rook("r2", color, color?&board[7][0]:&board[7][7]);
};

chess::team::pawn::pawn(std::string id, bool color,chess::coordinate* start):piece(id,color,start){
    first_move = true;
    opposite_end = false;
};
chess::team::knight::knight(std::string id, bool color, chess::coordinate* start):piece(id,color,start){};
chess::team::bishop::bishop(std::string id, bool color, chess::coordinate* start):piece(id,color,start){};
chess::team::rook::rook(std::string id, bool color, chess::coordinate* start):piece(id,color,start){};
chess::team::king::king(std::string id, bool color, chess::coordinate* start):piece(id,color,start){
    check = false;
};
chess::team::queen::queen(std::string id, bool color, chess::coordinate* start):piece(id,color,start){};

chess::team::piece::piece(std::string id, bool color, chess::coordinate* start){
    this->id = id;
    this->alive = true;
    this->start = start;
    this->pos = start;
};

chess::coordinate::coordinate(int x, char y, bool black){
    this->x = x;
    this->y = y;
    this->black = black;
};
