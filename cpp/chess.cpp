#include "../headers/chess.h"
#include <iostream>
#include <typeinfo>
//Constructors
chess::chess(){
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            board[i][j] = new coordinate(i, j, ((i%2==0) != (j%2==0))?true:false); // create board.
        }
    }
    white = new team(false, *board);
    black = new team(true, *board);
    

};
chess::team::team(bool color, coordinate** board){
    this->color = color;
    this->board = board;
    p1 = new pawn("p1", color, color?&board[0][1]:&board[0][6]);
    if(color) board[0][1].occupant = p1 ; else board[0][6].occupant = p1;
    p2 = new pawn("p2", color, color?&board[1][1]:&board[1][6]);
    if(color) board[1][1].occupant = p2; else board[1][6].occupant = p2;
    p3 = new pawn("p3", color, color?&board[2][1]:&board[2][6]);
    if(color) board[2][1].occupant = p3; else board[2][6].occupant = p3;
    p4 = new pawn("p4", color, color?&board[3][1]:&board[3][6]);
    if(color) board[3][1].occupant = p4; else board[3][6].occupant = p4;
    p5 = new pawn("p5", color, color?&board[4][1]:&board[4][6]);
    if(color) board[4][1].occupant = p5; else board[4][6].occupant = p5;
    p6 = new pawn("p6", color, color?&board[5][1]:&board[5][6]);
    if(color) board[5][1].occupant = p6; else board[5][6].occupant = p6;
    p7 = new pawn("p7", color, color?&board[6][1]:&board[6][6]);
    if(color) board[6][1].occupant = p7; else board[6][6].occupant = p7;
    p8 = new pawn("p8", color, color?&board[7][1]:&board[7][6]);
    if(color) board[7][1].occupant = p8; else board[7][6].occupant = p8;
    r1 = new rook("r1", color, color?&board[0][0]:&board[0][7]);
    if(color) board[0][0].occupant = r1; else board[0][7].occupant = r1;
    k1 = new knight("k1", color, color?&board[1][0]:&board[1][7]);
    if(color) board[1][0].occupant = k1; else board[1][7].occupant = k1;
    b1 = new bishop("b1", color, color?&board[2][0]:&board[2][7]);
    if(color) board[2][0].occupant = b1; else board[2][7].occupant = b1;
    q  = new queen("q", color, color?&board[3][0]:&board[3][7]);
    if(color) board[3][0].occupant = q; else board[3][7].occupant = q;
    k  = new king("k", color, color?&board[4][0]:&board[4][7]);
    if(color) board[4][0].occupant = k; else board[4][7].occupant = k;
    b2 = new bishop("b2", color, color?&board[5][0]:&board[5][7]);
    if(color) board[5][0].occupant = b2; else board[5][7].occupant = b2;
    k2 = new knight("k2", color, color?&board[6][0]:&board[6][7]);
    if(color) board[6][0].occupant = k2; else board[6][7].occupant = k2;
    r2 = new rook("r2", color, color?&board[7][0]:&board[7][7]);
    if(color) board[7][0].occupant = r2; else board[7][7].occupant = r2;
};
chess::pawn::pawn(std::string id, bool color,chess::coordinate* start):piece(id,color,start){
    first_move = true;
    opposite_end = false;
};
chess::knight::knight(std::string id, bool color, chess::coordinate* start):piece(id,color,start){};
chess::bishop::bishop(std::string id, bool color, chess::coordinate* start):piece(id,color,start){};
chess::rook::rook(std::string id, bool color, chess::coordinate* start):piece(id,color,start){
    first_move = false;
};
chess::king::king(std::string id, bool color, chess::coordinate* start):piece(id,color,start){
    check = false;
    first_move = false;
};
chess::queen::queen(std::string id, bool color, chess::coordinate* start):piece(id,color,start){};
chess::piece::piece(std::string id, bool color, chess::coordinate* start){
    alive = true;
    pos = start;
    this-> color = color;
};
chess::coordinate::coordinate(int x, int y, bool black){
    this->x = x;
    this->y = y;
    this->black = black;
    this->occupant = nullptr;
};

//Member methods
chess::piece* chess::pawn::move(bool color, int x, int y, chess::coordinate** board){
    //dest should be of the form "1B" i.e. first char is int x, second is char y
    try{
        
        coordinate* pos = getPos();
        if(x-1<=pos->x<=x+1){ // ensure x move is only in valid range of all potential pawn moves.
            std::cout << "Pawns can only move up the board straight or capture to the side one space.";
            return this;
        }
        piece* space_occupant = board[x][y].occupant;
        if(y == (color?pos->y+1:pos->y-1) || //normal move
        (first_move && y == color?pos->y+2:pos->y-2) || // first move could be +2
        (space_occupant != nullptr && (y==color?pos->y+1:y-1 && (x== pos->x+1 || x==pos->x-1 ))) && //handles pawn capture behavior
        0<=y<=7 &&
        0<=x<=7
        ){    //space must exist on board
            if(space_occupant == nullptr){ // space unoccupied
                pos->y = y;
                first_move = false;
                return this;
            }
            else{
                if(space_occupant->getColor() != color){
                    pos->y = y;
                    first_move = false;
                    space_occupant->capture(); // removes piece from game
                    board[x][y].occupant = this;
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
chess::piece* chess::piece::move(std::string dest, chess::coordinate** board){
    try{
        int x = int(dest[0]);
        int y = int(dest[1]);
        coordinate* my_Pos = getPos();
        int my_x = my_Pos->x;
        int my_y = my_Pos->y;
        if((0<=x<=7) && (0<=y<=7) && (my_x != x) && (my_y != y)){
            piece* occupant = board[x][y].occupant;
            if(moveLogicChecks(my_x,my_y,x,y, board)){
                if(occupant != nullptr && occupant->color != this->color){
                    occupant->capture();
                    board[x][y].occupant = this;
                    this->pos = &board[x][y];
                    return this;
                }
                else if(occupant== nullptr){
                    board[x][y].occupant = this;
                    this->pos = &board[x][y];
                    return this;
                }
                else {
                    std::cout << "That space is occupied by your own piece.\n";
                    return this;
                }
            }
        }
    }
    catch(error_t e){
        std::cout<<"Bad input\n";
        return this;
    }
};
bool chess::knight::moveLogicChecks(int my_x, int my_y,int x, int y, chess::coordinate** board){
    //knight can move up 2 over 1 in any direction
    if((x == my_x+2 && y == my_y-1)
    ||(x == my_x+2 && y == my_y+1)
    ||(x == my_x-2 && y == my_y-1)
    ||(x == my_x-2 && y == my_y+1)
    ||(x == my_x-1 && y == my_y-2)
    ||(x == my_x+1 && y == my_y-2)
    ||(x == my_x-1 && y == my_y+2)
    ||(x == my_x+1 && y == my_y+2)) return true;
    return false;
};
bool chess::bishop::moveLogicChecks(int my_x, int my_y,int x, int y, chess::coordinate** board){
    //bishop can move diagonally in any direction for any distance till it hits an obstacle.
    int shift_x = my_x-x; 
    int shift_y = my_y-y;
    if(abs(shift_x) != abs(shift_y)) return false; //diagonal path must have same diff x and y
    int x_pos = shift_x < 0 ? 1: -1;  // if new value greater than current , positive modifier else negative.
    int y_pos = shift_y < 0 ? 1: -1; 
    // need to walk diagonal path in direction of attempted move to find first object encountered. 
    for(int i = my_x; i!=x; i += shift_x){
        for(int j = my_y; j!=y; j += shift_y){
            if(board[i][j].occupant != nullptr) return false;
        }
    }
    return true;
}
bool chess::rook::moveLogicChecks(int my_x, int my_y, int x, int y, chess::coordinate**board){
    int shift_x = my_x-x; 
    int shift_y = my_y-y;
    if(shift_x != 0 && shift_y != 0) return false;
    bool shift_Dir_x = shift_x != 0 ? true : false; 
    int walk = shift_Dir_x ?
    shift_x > 0? 1:-1 // if shift in x plane, decide if shift is positive or negative
    :
    shift_y > 0? 1:-1; // if shift in y plane, decide if shift is positive or negative    
    for(int i = shift_Dir_x?my_x:my_y;i!=shift_Dir_x?x:y;x+=shift_Dir_x?shift_x:shift_y){
        if((shift_Dir_x?board[i][my_y]:board[my_x][i]).occupant != nullptr) return false;
    }
    return true;
}
bool chess::piece::capture(){
    alive = false;
    pos = nullptr;
    return true;
};

//--Getter functions
bool chess::piece::isKing(){return false;};
bool chess::king::isKing(){return true;};
bool chess::king::isFirstMove(){return first_move;};
bool chess::rook::isFirstMove(){return first_move;};
bool chess::piece::getColor(){return color;};
chess::coordinate* chess::piece::getPos(){return pos;};
chess::piece* chess::team::getPiece(std::string pieceID){
    int i = 0;
    for(auto p : index){
        if(p == pieceID) break;
        i++;
    }
    switch(i){
        case 0: return p1;
        case 1: return p2;
        case 2: return p3;
        case 3: return p4;
        case 4: return p5;
        case 5: return p6;
        case 6: return p7;
        case 7: return p8;
        case 8: return r1;
        case 9: return k1;
        case 10:return b1;
        case 11:return q;
        case 12:return k;
        case 13:return b2;
        case 14:return k2;
        case 15:return r2;
        default:{ 
            cout<< "Piece entered was not found\n.";
            return nullptr;
    }
}

//Gameplay 

bool chess::team::movePiece( std::string moveString){
    //moveString should be of the form "p1 1,1" where p1 = piece identifier and 1,1 = x,y
    //moveString can also have form of "castle" to attempt to castle
    //movePiece 
    if(moveString.length() > 6 || moveString.length() < 5){
        std::cout << "Bad input\n";
        return false;
    }
    if(moveString == "castle"){
        if(k->isFirstMove() && r2->isFirstMove()){

            if(
                r2->moveLogicChecks(7,color?0:7,5,color?0:7, board) &&
                k->moveLogicChecks(4,color?0:7,6,color?0:7, board)
            )
            r2->setPos(5,color?0:7);
            board[5][color?0:7].occupant = r2;
            board[7][color?0:7].occupant = nullptr;
            board[6][color?0:7].occupant = k;
            board[4][color?0:7].occupant = nullptr;
            r2->moved();
            k->moved();
            return true;
        }
    }
    std::string pieceID = "";
    int x,y = -1;
    int space = moveString.find(' ');
    pieceID = moveString.substr(0,space);
    x = int(moveString.substr(space,space+1));
    y = int(moveString.substr(space+2));
    piece* piece = getPiece(pieceID);
    if(piece != nullptr)return piece->move(color,x,y,board); 
    return false;
}

void chess::play(){
    bool turn = false; // start with white.
    std::string moveInput;
    while(!checkmate){
        getBoardState();
        if(turn?white->canCastle():black->canCastle())cout <<"You might be able to castle.\n";
        cout<<"Enter you input as: 
            \n\t\"castle\" to castle
            \n\t\"p1 x,y\" to move where p1 is piece id and x,y are move coordinates.
        \nMake your move. \n";
        cin<<moveInput;
        if((turn?white:black)->movePiece(moveInput)){
            turn = !turn;
        }
        else cout<<"Invalid move, try again.\n";


    }

    return;
}