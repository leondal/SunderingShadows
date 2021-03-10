#include <std.h>
#include "../dagger.h"
inherit ROOM;

void create(){
    ::create();
    set_terrain(WOOD_BUILDING);
    set_travel(DIRT_ROAD);
    set_property("light", 2);
    set_property("indoors",1);
    set_name("A ruined building");
    set_short("%^BOLD%^%^BLACK%^A ruined building%^RESET%^");
    set_long("%^BOLD%^%^BLACK%^This workroom has been left in tatters by whoever destroyed the building itself"
". Tools lie strewn across the floor, some in workable condition and others %^RESET%^melted %^BOLD%^%^BLACK%^"
"beyond repair. Blocks of wood, once kept carefully in bins, have been thrown across the room, many splintered "
"or burnt, and a few embedded in the walls themselves by some %^RED%^explosive %^BLACK%^force. A partly-broken "
"staircase leads up to a back room.%^RESET%^");
    set_smell("default","An acrid, burnt smell fills the air.");
    set_listen("default","It is deathly quiet here.");

    set_exits(([
      "out" : SHOPS"woodwright",
      "stairs" : SHOPS"wood_apprent",
    ]));
    set_search("default","Where do you want to search?");
    set_search("wall",(:TO,"search":));
    set_search("south wall",(:TO,"search":));
}

void init() {
  ::init();
  add_action("search","search");
}

int search(string str) {
  if(str == "wall") {
    write("Search which wall?");
    return 1;
  }
  write("You search the wall and find only the remains of a few scratches there.\n");
  tell_room(ETP,TPQCN+" searches the south wall.", TP);
  return 1;
}