// Vala Street, Tabor
// Thorn@ShadowGate
// 000922
// Tabor
// vala2.c

#include <std.h>
#include "../include/tabor.h"

inherit ROOM;

void create() {
  room::create();
   set_travel(DIRT_ROAD);
   set_terrain(CITY);
  set_light(2);
  set_short("Vala Street, Tabor");
  set_long("%^BOLD%^Vala Street, Tabor%^RESET%^\n"
"You are standing outside the great %^YELLOW%^Cathedral %^RESET%^of "
"%^BOLD%^%^CYAN%^St. Vala %^RESET%^on %^BOLD%^%^CYAN%^Vala Street%^RESET%^."
"  The cathedral%^RESET%^ looms above you, ponderous and very serene "
"looking with its thick stone walls and %^YELLOW%^s%^RESET%^%^ORANGE%^t"
"%^RED%^a%^BOLD%^%^MAGENTA%^i%^CYAN%^n%^GREEN%^ed %^CYAN%^glass "
"windows%^RESET%^.  In and of itself, the church could easily be a "
"fortress with just a little imagination, and may have even served that "
"way once perhaps.  If you care to pray a bit, the %^YELLOW%^Cathedral"
"%^RESET%^ is always open.\n\n"
"%^BOLD%^%^CYAN%^Vala Street%^RESET%^ continues to the north and southwest.\n"
"The main entrance to the %^YELLOW%^Cathedral%^RESET%^ is to the east."
    );
  set_exits(([
    "east" : ROOMDIR+"church",
    "southwest" : ROOMDIR+"vala1",
    "north" : ROOMDIR+"vala3"
  ]));
  set_listen("default","You hear the sounds of a busy town all around you.");
  set_smell("default", "The slightly rank scent of a busy city mingles with the fragrance of incense.");
  set_items(([
    "cathedral" : "The cathedral is built in the Romanesque style, and is very solid looking.",
    "statue" : "From here you can make out the statue of a king who faces the east, towards you."
  ]));
 }

void reset(){
	::reset();
  if(!present("street_light",TO))
    new("/d/common/obj/misc/street_light")->move(TO);
}
