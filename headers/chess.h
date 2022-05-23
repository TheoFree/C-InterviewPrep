#include <tuple>
#include <vector>

class chess{
    private :
        struct coordinate;
        class piece{
                protected:
                    bool alive;
                    bool color;
                    coordinate* pos;
                    bool validMove(int my_x, int my_y, int x, int y);
                public:
                    bool capture();
                    bool getColor();
                    bool isKing();
                    piece(std::string id, bool color, coordinate* start);
                    coordinate* getPos();
                    bool move( int x, int y, chess::coordinate** board);
                    bool moveLogicChecks(int my_x, int my_y, int x, int y,chess::coordinate** board);
                    void setPos(int x, int y);
                    virtual std::vector<chess::coordinate*> getMoves();
            };
        class pawn : public piece{
            bool first_move;
            bool opposite_end;
            public:
                bool moveLogicChecks(int my_x, int my_y, int x, int y, chess::coordinate** board);
                pawn(std::string id, bool color,  coordinate* start);
                std::vector<chess::coordinate*> getMoves(chess::coordinate** board);
        };
        class knight : public piece{
            public:
                knight(std::string id, bool color,  coordinate* start);
                bool moveLogicChecks(int my_x, int my_y,int x, int y, chess::coordinate** board);
                std::vector<chess::coordinate*> getMoves(chess::coordinate** board);

        };
        class bishop : public piece{
            bool notBlocked(chess::piece* occupant);
            public:
                bishop(std::string id, bool color,  coordinate* start);
                bool moveLogicChecks(int my_x, int my_y,int x, int y, chess::coordinate** board);
                std::vector<chess::coordinate*> getMoves(chess::coordinate** board);
        };
        class rook : public piece{
            bool first_move;
            
            public:
                rook(std::string id, bool color,  coordinate* start);
                std::vector<chess::coordinate*> getMoves(chess::coordinate** board);
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
                std::vector<chess::coordinate*> getMoves(chess::coordinate** board);
                bool moveLogicChecks(int my_x, int my_y, int x, int y,chess::coordinate** board );
        };
        class queen : public piece{
                public:
                    queen(std::string id, bool color,  coordinate* start);
                    bool moveLogicChecks(int my_x, int my_y, int x, int y,chess::coordinate** board );
                    std::vector<chess::coordinate*> getMoves(chess::coordinate** board);
            };
        class team{
            bool color; // true for black, false for white
            //coordinate** board;
            std::string index[16] = {"p1","p2","p3","p4","p5","p6","p7","p8","r1","k1","b1","q","k","b2","k2","r2"};
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
            piece* getPiece(std::string id);
            bool* canCastle();
            public:
                bool inCheck();
                bool canEscapeCheck(team* opponent);
                team(bool color, coordinate** board);
                bool movePiece(std::string moveString, coordinate** board);
        };
        struct coordinate{
            int x;
            int y;
            bool black;
            piece* occupant; // can be null.
            coordinate( int x, int y, bool black);
        };
        coordinate* board[8][8];
        team* white;
        team* black;
        bool checkmate;
        void play();
        chess& getBoardState(); // prints current state of both teams on board.
        chess& move(); 
        // on current move, enter via command line next move in format:"piece id" "coordinate" such as "k1 4,5"
    public :
        chess();

};