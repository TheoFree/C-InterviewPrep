#include <tuple>
#include <vector>

class chess{
    private :
        struct coordinate;
        class piece{
                bool alive;
                bool color;
                coordinate* pos;
                
                public:
                    bool capture();
                    bool getColor();
                    bool isKing();
                    piece(std::string id, bool color, coordinate* start);
                    coordinate* getPos();
                    piece* move(std:: string dest, chess::coordinate** board);
                    bool moveLogicChecks(int my_x, int my_y, int x, int y,chess::coordinate** board);
                    void setPos(int x, int y);
            };
        class pawn : public piece{
            bool first_move;
            bool opposite_end;
            public:
                pawn(std::string id, bool color,  coordinate* start);
                piece* move(bool color,std::string dest,coordinate** board);
        };
        class knight : public piece{
            public:
                knight(std::string id, bool color,  coordinate* start);
                piece* move(std::string dest);
                bool moveLogicChecks(int my_x, int my_y,int x, int y, chess::coordinate** board);
        };
        class bishop : public piece{
            public:
                bishop(std::string id, bool color,  coordinate* start);
                piece* move(std::string dest);
                bool moveLogicChecks(int my_x, int my_y,int x, int y, chess::coordinate** board);
        };
        class rook : public piece{
            bool first_move;
            
            public:
                rook(std::string id, bool color,  coordinate* start);
                piece* move(std::string dest);
                bool isFirstMove();
                void moved();
                bool moveLogicChecks(int my_x, int my_y,int x, int y, chess::coordinate** board);
        };
        class king : public piece{
            bool check;
            bool first_move;
            public:
                bool isKing();
                bool isFirstMove();
                void moved();
                king(std::string id, bool color,  coordinate* start);
                piece* move(std::string dest);
        };
        class queen : public piece{
                public:
                    queen(std::string id, bool color,  coordinate* start);
                    piece* move(std::string dest);
            };
        class team{
            bool color; // true for black, false for white
            coordinate** board;
            
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
                bool movePiece(std::string moveString);
        };
        struct coordinate{
            int x;
            int y;
            bool black;
            piece* occupant; // can be null.
            coordinate( int x, int y, bool black);
        };
        /*
........grid:.x.=...0..1..2..3..4..5..6..7
..............y.=.0.#..X..#..X..#..X..#..X
..................1.X..#..X..#..X..#..X..#
..................2.#..X..#..X..#..X..#..X
..................3.X..#..X..#..X..#..X..#
..................4.#..X..#..X..#..X..#..X
..................5.X..#..X..#..X..#..X..#
..................6.#..X..#..X..#..X..#..X
..................7.X..#..X..#..X..#..X..#
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