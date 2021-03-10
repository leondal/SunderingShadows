#include <std.h>
inherit "/d/common/obj/misc/chessboard.c";

void create() 
{
  ::create();
  set_short("A sturdy chess table");
  set_long("%^ORANGE%^A pedestal chess table made out of solid cedar "
          +"wood, with a %^RED%^cherry%^ORANGE%^ finish. The pedestal of"
         +" the table is carved out of a solid trunk of wood, with an"
         +" open scrollwork design wrapping around the middle of it."
         +" There are two %^GREEN%^felt lined drawers%^ORANGE%^"
         +" to store the delightfully carved %^BOLD%^%^WHITE%^i%^RESET%^v"
         +"%^BOLD%^%^WHITE%^ory%^RESET%^%^ORANGE%^ chess pieces.\n"
         +"%^BOLD%^%^YELLOW%^<help board>%^RESET%^%^ORANGE%^ for help on"
         +" how to play.");
   set_id( ({"board", "chessboard", "chess board", "game", "table", 
                                      "chess table", "game board"}) );

   set_weight(10000);
}



