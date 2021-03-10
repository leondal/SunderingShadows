#include <std.h>
#include "../farm.h"

inherit ROOM;

void create(){
   ::create();
   set_terrain(GRASSLANDS);
   set_travel(RUTTED_TRACK);
   set_name("A narrow pathway");
   set_property("light",3);
   set_property("indoors",0);
   set_short("A narrow pathway");
   set_long("%^ORANGE%^This narrow pathway is in itself a work "+
      "of art.  No simple dirt or grass for this path - oh, no.  "+
      "The smooth pathway is lined neatly with well-fitting "+
      "%^RED%^m%^ORANGE%^u%^YELLOW%^l%^RESET%^%^GREEN%^t%^CYAN%^i"+
      "%^BOLD%^-%^BLUE%^c%^RESET%^%^MAGENTA%^o%^RED%^l%^ORANGE%^o"+
      "%^YELLOW%^r%^RESET%^%^GREEN%^e%^CYAN%^d cobblestone%^ORANGE%^.  "+
      "A few %^GREEN%^plants %^ORANGE%^grow along the sides of "+
      "the path, but there seems to be no rhyme or reason. \n");
   set_smell("default","A slightly malodorous scent fills the air.");
   set_listen("default","Strange metallic sounds reach your ears from time to time.");
   set_items(([
      ({"cobblestones","path","pathway"}) : "The pathway is lined "+
         "neatly with multi-colored stones.  There seems to be no "+
         "pattern, but it is not overly chaotic.",
      ({"house","farmhouse"}) : "The farmhouse looks very strangely "+
         "shaped, rather like a diamond pointing north.  It is riddled "+
         "with portholes of various shapes.",
      ({"plant","plants"}) : "The plants are mostly normal, although "+
         "you notice a few oddities.  Too many points on a leaf here, "+
         "a weird color there...odd."
   ]));
   set_exits(([
      "northeast" : PATHS"path1",
      "west" : PATHS"gnomehome",
      "southwest" : PATHS"farm18",
      "south" : PATHS"farm19"
   ]));
}