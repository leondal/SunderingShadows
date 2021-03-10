#include <std.h>
inherit ROOM;

void create(){
  ::create();
  set_terrain(WOOD_BUILDING);
  set_travel(DIRT_ROAD);
  set_property("light",2);
  set_property("indoors",1);
  set_short("Silver Strings");
  set_long("%^BOLD%^Silver Strings%^RESET%^\n"+
"%^RESET%^%^CYAN%^This shop is %^RESET%^simplistic %^CYAN%^and open, allowing plenty of space to move and inspect its "
"wares.  It does not carry a vast quantity of stock, but what few items are here seem to be of %^MAGENTA%^fine quality"
"%^CYAN%^.  All are hand-carved, in wood ranging from %^RESET%^pale ash %^CYAN%^to %^RED%^polished mahogany%^CYAN%^, as "
"well as more exotic substances such as %^GREEN%^turtleshell%^CYAN%^.  The door and window-shutters stand open at the "
"front of the shop, allowing plenty of %^YELLOW%^light %^RESET%^%^CYAN%^to filter in from the street beyond.  Another "
"door allows access to the other half of this long building.");
  set_smell("default","The scent of wood shavings and polish fills the air.");
  set_listen("default","You can hear the bustle of the city street outside.");
  set_exits(([
    "east":"/d/darkwood/tabor/room/math9",
    "south":"/d/darkwood/tabor/room/taborbardcomps",
  ]));
}

void reset(){
   ::reset();
   if(!present("mayyadah")) new("/d/darkwood/tabor/mon/mayyadah")->move(TO);
}
