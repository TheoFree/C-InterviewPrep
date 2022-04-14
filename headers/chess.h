#include <tuple>
#include <vector>

class chess{
    private :
        struct coordinate;
        class piece{
            std::tuple<int,char> position;
            bool alive;
            bool capture();
            piece& move();
            std::vector<coordinate> moves();
            int id;
        };
        struct coordinate{
            int x;
            char y;
            bool black;
            chess::piece occupant; // can be null.
        };
        class pawn : private piece{
            bool first_move;
            bool opposite_end;
        };
        class knight : private piece{};
        class bishop : private piece{};
        class rook : private piece{};
        class king : private piece{
            bool check;
        };
        class queen : private piece{};
        //grid: x =   0  1  2  3  4  5  6  7
        /*      y = A -  @  -  @  -  @  -  @
                    B @  -  @  -  @  -  @  -
                    C -  @  -  @  -  @  -  @
                    D @  -  @  -  @  -  @  -
                    E -  @  -  @  -  @  -  @
                    F @  -  @  -  @  -  @  -
                    G -  @  -  @  -  @  -  @
                    H @  -  @  -  @  -  @  -
         */
    public :
        chess();

};