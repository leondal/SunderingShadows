//estreet14 - Circe 11/23/07 for new Seneca
#include <std.h>
#include "../seneca.h"

inherit LILA;

void create(){
   ::create();
   set_long(::query_long()+"West of here is a tall %^RED%^brick wall "+
      "%^RESET%^rising three stories into the air.  To the north, you see "+
      "the corner of %^BOLD%^%^BLUE%^Azul Avenue "+
      "%^RESET%^and %^MAGENTA%^Lila Way%^RESET%^.\n");
   set_exits(([
      "north" : ROOMS"estreet13",
      "south" : ROOMS"estreet15"
   ]));
   add_item("wall","The wall to the west is %^RED%^red brick %^RESET%^"+
      "with gray mortar.  It rises three stories, but you cannot tell "+
      "what the building might be from here.");
}