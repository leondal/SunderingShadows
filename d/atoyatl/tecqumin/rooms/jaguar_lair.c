#include <std.h>
#include <move.h>
#include "../../tecqumin.h"

inherit ROOM;

int searched;

void create() {
  ::create();
  searched = 0;
  set_indoors(0);
  set_property("light", 2);
  set_terrain(JUNGLE);
  set_travel(GAME_TRACK);
  set_name("A hidden tree house");
  set_short("%^GREEN%^A %^BOLD%^%^BLACK%^hidden%^RESET%^%^GREEN%^"
           +" lair%^RESET%^");
  set_long( "%^GREEN%^This little tree house has been arranged for a minimum"
        +" of comfort. There is a %^BOLD%^%^GREEN%^bower%^RESET%^%^GREEN%^"
        +" lined with %^BOLD%^%^GREEN%^l%^RESET%^%^GREEN%^ea%^BOLD%^"
        +"%^GREEN%^v%^RESET%^%^GREEN%^e%^BOLD%^%^GREEN%^s%^RESET%^"
        +"%^GREEN%^. It is fairly dry. Alongside the bed is a thick, flat"
        +" topped %^RESET%^log%^GREEN%^ which has the distinct appearance"
        +" of a bedside table, albeit a rather crude one. One of the walls"
        +" of the hideaway runs alongside the bole of the tree, one of the"
        +" branches of which supports a sloping, leaf-clad roof." );
  set_items (([ ({"bed", "leaf bed", "bed of leaves", "leaves"}):
         "%^GREEN%^The bed is large enough for a medium to large humanoid.",
                 ({"bole", "tree"}):"The bole of the large tree which holds"
        +" the treehouse is marked with thick claw scars." ]) );
  set_search("bed",(:TO, "bed_search":));
  set_smell("default","The air is heavy with %^CYAN%^humidity%^ORANGE%^"
                    +" and the heady scent of %^GREEN%^j%^BOLD%^"
                    +"%^GREEN%^u%^RESET%^%^GREEN%^ngle %^ORANGE%^plant"
                    +" life.");
  set_listen("default","There is the constant hum of insect activity, the"
                     +" bustle and shrill calls of exotic birds. Small"
                     +" animals can be heard scurrying in the undergrowth"
                     +" and larger creatures are occasionally heard"
                     +" further in the distance.");
  set_exits(([
      "out" : JUNG_ROOM + "jag_lair_outside",
   ]));
}

void init() {
  ::init();
}

void reset(){
  ::reset();
  searched = 0;
}

int bed_search(string str){
  object pot;
  if (searched ==0)
  {
    pot = new(OBJ + "draught_flowers");
   tell_object(TP, "Rummaging around in the %^BOLD%^%^GREEN%^b%^RESET%^%^GREEN%^e%^RESET%^d %^BOLD%^%^GREEN%^of l%^RESET%^%^GREEN%^ea%^BOLD%^%^GREEN%^v%^RESET%^e%^GREEN%^s%^RESET%^, you find " + pot->query_short() );
    tell_room(TO, "Rummaging around in the %^BOLD%^%^GREEN%^b%^RESET%^%^GREEN%^e%^RESET%^d %^BOLD%^%^GREEN%^of l%^RESET%^%^GREEN%^ea%^BOLD%^%^GREEN%^v%^RESET%^e%^GREEN%^s%^RESET%^, " + TPQCN + " seems to find something", TP);
    pot = new(OBJ + "draught_flowers");
    pot->move(TP);
    searched = 1;
    return 1;
  } 
  else 
  {
   tell_object(TP, "You rummage around in the %^BOLD%^%^GREEN%^b%^RESET%^%^GREEN%^e%^RESET%^d %^BOLD%^%^GREEN%^of l%^RESET%^%^GREEN%^ea%^BOLD%^%^GREEN%^v%^RESET%^e%^GREEN%^s%^RESET%^, but you don't find anything");
    tell_room(TO, "Rummaging around in the %^BOLD%^%^GREEN%^b%^RESET%^%^GREEN%^e%^RESET%^d %^BOLD%^%^GREEN%^of l%^RESET%^%^GREEN%^ea%^BOLD%^%^GREEN%^v%^RESET%^e%^GREEN%^s%^RESET%^, " + TPQCN + " doesn't seem to find anything", TP);
    return 1;
  }
}
