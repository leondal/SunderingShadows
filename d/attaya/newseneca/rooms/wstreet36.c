//sstreet36 - Circe 11/23/07 for new Seneca
#include <std.h>
#include "../seneca.h"

inherit ROSA;

void create(){
   ::create();
   set_long(::query_long()+"The %^BOLD%^cream stucco wall %^RESET%^"+
      "of a building stands to the east.  Peeking around the northeastern "+
      "corner, you can see the edge of a %^GREEN%^s%^RESET%^t%^GREEN%^r%^RESET%^i"+
      "%^GREEN%^p%^RESET%^e%^GREEN%^d %^GREEN%^a%^RESET%^w%^GREEN%^n"+
      "%^RESET%^i%^GREEN%^n%^RESET%^g.  North of here is the %^ORANGE%^"+
      "junction %^RESET%^of %^BOLD%^%^MAGENTA%^Rosa Terrace %^RESET%^and "+
      "%^BOLD%^%^CYAN%^Viento Lane%^RESET%^.\n");
   set_exits(([
      "north" : ROOMS"wstreet37",
      "south" : ROOMS"wstreet35"
   ]));
   add_item("building","The building to the east has %^BOLD%^cream-"+
      "colored stucco walls%^RESET%^ and seems to have a %^GREEN%^s"+
      "%^RESET%^t%^GREEN%^r%^RESET%^i"+
      "%^GREEN%^p%^RESET%^e%^GREEN%^d %^GREEN%^a%^RESET%^w%^GREEN%^n"+
      "%^RESET%^i%^GREEN%^n%^RESET%^g in the front, but you cannot "+
      "tell any more about it.");
}