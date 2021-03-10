#include <std.h>
#include "../tormdefs.h"
inherit ROOM;

void create(){
  ::create();
  set_terrain(WOOD_BUILDING);
  set_travel(DIRT_ROAD);
  set_property("light",2);
  set_property("indoors",1);
  set_short("The Music Box");
  set_long(
  "%^BOLD%^The Music Box%^RESET%^\n"+
  "%^BOLD%^%^CYAN%^This room might once have been only used for storage for the shop,"+
  " but now serves as a secondary section for purchases.  %^RESET%^%^ORANGE%^Short shelves%^BOLD%^%^CYAN%^"+
  " line one wall, leaving enough space to traverse the length of the"+
  " room, and each bears short sheaves of %^RESET%^parchment %^BOLD%^%^CYAN%^scrawled with text"+
  ".  Similarly furnished to the larger room beyond, the walls sport"+
  " %^YELLOW%^cheery pictures %^CYAN%^and %^YELLOW%^c%^BLUE%^o%^CYAN%^l%^MAGENTA%^o%^GREEN%^r"+
  "%^RED%^f%^YELLOW%^u%^GREEN%^l %^CYAN%^silks, brightening this otherwise drab"+
  " back room and lending it an air of space it would not normally possess."+
  "  To the north lies the main section of the shop."
  );
  set_items(([
  ({"rug","red rug","bright red rug"}) : "%^BOLD%^%^RED%^The rug that"+
  " covers the floor is a bit dirty and worn thin, but it is still"+
  " a bright shade of red.",
  ({"shelves","sheaves","parchment"}) : "A series of shelves line one"+
  " wall of the room, set about with sheaves of parchment bearing"+
  " excepts of writing.",
  ({"pictures","walls"}) : "The walls are decorated with cheery pictures"+
  " of various scenes, such as picnics in a meadow and people playing"+
  " in a lake.",
  ({"masks","silks","colorful silks"}) : "There are many exotic masks"+
  " and colorful silks that are draped artfully about the room.",
  ]));
  set_smell("default","You smell the sawdust from the instruments in the room to the north.");
  if(query_night()) {
    set_listen("default","You can hear people passing by on the street"+
    " outside.");
  }
  else {
    set_listen("default","The streets outside are quiet at night.");
  }
  set_exits(([
  "north":TCITY+"c53",
  ]));
}

void reset(){
   ::reset();
   if(!present("eva")) {
      new(MON+"eva")->move(TO);
   }
}
