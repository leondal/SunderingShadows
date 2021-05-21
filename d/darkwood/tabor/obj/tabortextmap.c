//updated by Circe 5/31/04 to use new map
// Map of Tabor
// Thorn@ShadowGate
// 001013
// Tabor
// map.c

#include <std.h>

inherit OBJECT;

void init(){
  ::init();
  add_action("read_map","read");
}

void create() {
  ::create();
  set_id( ({"map", "tabor map", "map of tabor" }) );
  set_name("map");
  set_short("A map of Tabor");
  set_long("This is a text-only map of Tabor written on high quality parchment "+
     "that has been weather-proofed so it will not run. All of the "+
     "major locations of the city are on here. You should read it.");
  set_weight(0);
  set_value(0);
}

int read_map(string str){
  if(!str) return notify_fail("Read what?"); //causing errors in debug log hopefully this will fix -Hades
//  if(str != "map") return 0;
// Fix to make sure you can "read map 2"...
        if (present(str, ETO) != TO) return 0;
  TP->more("/d/darkwood/tabor/obj/tabor_text_map");
  return 1;
}