#include <tuple>
#include <vector>

class chess{
    private :
        struct coordinate;
        class team{
            bool color; // true for black, false for white
            class piece{
                std::tuple<int,char> position;
                bool alive;
                std::vector<coordinate> moves();
                std::string id;
                coordinate* start;
                coordinate* pos;
                public:
                    bool capture();
                    piece& move();
                    int getID();
                    piece(std::string id, bool color, coordinate* start);
            };
            class pawn : public piece{
                bool first_move;
                bool opposite_end;
                public:
                    pawn(std::string id, bool color,  coordinate* start);
            };
            class knight : public piece{
                public:
                    knight(std::string id, bool color,  coordinate* start);
            };
            class bishop : public piece{
                public:
                    bishop(std::string id, bool color,  coordinate* start);
            };
            class rook : public piece{
                public:
                    rook(std::string id, bool color,  coordinate* start);
            };
            class king : public piece{
                bool check;
                public:
                    king(std::string id, bool color,  coordinate* start);
            };
            class queen : public piece{
                public:
                    queen(std::string id, bool color,  coordinate* start);
            };
            
            pawn* p1;
            pawn* p2;
            pawn* p3;
            pawn* p4;
            pawn* p5;
            pawn* p6;
            pawn* p7;
            pawn* p8;
            knight* k1;
            knight* k2;
            bishop* b1;
            bishop* b2;
            rook* r1;
            rook* r2;
            king* k;
            queen* q;
            public:
                team(bool color, coordinate** board);
        };
        struct coordinate{
            int x;
            char y;
            bool black;
            int occupant_id; // can be null.
            coordinate( int x, char y, bool black);
        };
        /*grid: x =   0  1  2  3  4  5  6  7
                y = A -  @  -  @  -  @  -  @
                    B @  -  @  -  @  -  @  -
                    C -  @  -  @  -  @  -  @
                    D @  -  @  -  @  -  @  -
                    E -  @  -  @  -  @  -  @
                    F @  -  @  -  @  -  @  -
                    G -  @  -  @  -  @  -  @
                    H @  -  @  -  @  -  @  -
         */
        coordinate* board[8][8];
        team* white;
        team* black;
        bool checkmate;
    public :
        chess();
        chess& getBoardState(); // prints current state of both teams on board.
        chess& move(); // on current move, enter via command line next move in format "piece id" - "coordinate" such as k1 - E6

};