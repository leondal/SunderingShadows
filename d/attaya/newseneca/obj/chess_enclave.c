//Chessboard for the psion enclave in new Seneca
//~Circe~ 12/2/07
#include <std.h>
inherit "/d/common/obj/misc/chessboard.c";

void create(){
   ::create();
   set_short("A mahogany chess table");
   set_long("%^MAGENTA%^This small square table is set between two of the "+
      "chairs and features a carved %^BOLD%^%^BLACK%^c%^RESET%^h%^BOLD%^"+
      "%^BLACK%^e%^RESET%^s%^BOLD%^%^BLACK%^s%^RESET%^b%^BOLD%^%^BLACK%^"+
      "o%^RESET%^a%^BOLD%^%^BLACK%^r%^RESET%^d %^MAGENTA%^on its surface.  "+
      "A %^BOLD%^%^BLACK%^velvet-lined %^RESET%^%^MAGENTA%^drawer on each "+
      "side holds the beautiful %^BOLD%^%^WHITE%^crystalline pieces %^RESET%^"+
      "%^MAGENTA%^needed for the game.%^RESET%^\n"+
      "<help board> for help on how to play.");
   set_id( ({"board", "chessboard", "chess board", "game", "table", 
                                      "chess table", "game board"}) );

   set_weight(10000);
}
