//b11.c - Lothwaite barrows.  Circe 4/29/04 - eventual 
//hidden exit to the underdark.
#include <std.h>
#include "../lothwaite.h"
inherit BARROWS;

void create(){
   ::create();
   set_long( ::query_long()+"\n%^BLUE%^This seems to be the lowest "+
      "point of this passageway, and the ground rises to both "+
      "the southwest and southeast.\n");
   set_exits(([
      "southwest" : PATHEXIT"b10",
      "southeast" : PATHEXIT"b12",
   ]));
   set_search("default","Hmm...the shadows along the northern wall "+
      "seem deeper than all the others.");
   set_search("shadows","You cringe and reach into the shadows, but "+
      "all you feel is the cool stone.");
}