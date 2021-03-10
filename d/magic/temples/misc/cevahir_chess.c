#include <std.h>
inherit "/d/common/obj/misc/chessboard.c";

void create() 
{
  ::create();
  set_short("A sturdy chess table");
  set_long("%^ORANGE%^A pedestal chess table made out of solid cedar wood with a burnished %^YELLOW%^gold finish%^RESET%^%^ORANGE%^. The pedestal of the table is carved out of a solid trunk of wood, with an angular design depicting intricately locked squares that seem almost like an optical illusion. There are two %^MAGENTA%^felt-lined drawers%^ORANGE%^ to store the %^BOLD%^%^WHITE%^m%^RESET%^e%^BOLD%^%^BLACK%^t%^RESET%^a%^BOLD%^l %^RESET%^%^ORANGE%^chess pieces.\n%^BOLD%^%^YELLOW%^<help board>%^RESET%^%^ORANGE%^ for help on how to play.%^RESET%^");
   set_id(({"board", "chessboard", "chess board", "game", "table", "chess table", "game board"}));
   set_weight(10000);
}



