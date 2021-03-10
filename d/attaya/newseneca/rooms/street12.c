//street11 - Circe 11/22/07 for new Seneca
#include <std.h>
#include "../seneca.h"

inherit AZUL;

void create(){
   ::create();
   set_long(::query_long()+"South of here is a tall %^RED%^brick wall "+
      "%^RESET%^rising three stories into the air.  To the east, you see "+
      "the corner of %^BOLD%^%^BLUE%^Azul Avenue "+
      "%^RESET%^and %^MAGENTA%^Lila Way%^RESET%^.\n");
   set_exits(([
      "west" : ROOMS"street11",
      "east" : ROOMS"estreet13"
   ]));
   add_item("wall","The wall to the south is %^RED%^red brick %^RESET%^"+
      "with gray mortar.  It rises three stories, but you cannot tell "+
      "what the building might be from this side.");
}