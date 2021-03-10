//estreet16 - Circe 11/23/07 for new Seneca
#include <std.h>
#include "../seneca.h"

inherit LILA;

void create(){
   ::create();
   set_long(::query_long()+"To the west is the wall of a %^BOLD%^stone "+
      "building %^RESET%^with long, narrow windows near the %^GREEN%^"+
      "tiled roof%^RESET%^.  Just south of here, you see the %^ORANGE%^"+
      "junction %^RESET%^of %^MAGENTA%^Lila Way %^RESET%^and %^BOLD%^%^CYAN%^"+
      "Viento Lane%^RESET%^.\n");
   set_exits(([
      "north" : ROOMS"estreet15",
      "south" : ROOMS"estreet17"
   ]));
   add_item("building","The building to the west has thick stone walls "+
      "and a %^GREEN%^green tiled roof %^RESET%^.  The walls on this side "+
      "are broken only by long, narrow windows set near the top of the roof.");
}