//Titania 1/20/2020 (Updated from Circe's Tabor version)
// Map of Shadow
// shadow
// citymap.c

#include <std.h>

inherit OBJECT;

void init(){
  ::init();
  add_action("read_map","read");
}

void create() {
  ::create();
  set_id( ({"map", "shadow map", "map of shadow" }) );
  set_name("map");
  set_short("A map of Shadow");
  set_long("This is a map of the city of Shadow, drawn on high quality parchment "+
     "that has been weather-proofed so it will not run. All of the "+
     "major locations of the city are on here. You should read it.");
  set_weight(0);
  set_value(0);
}

int read_map(string str){
  if(!str) notify_fail("Read what?");
//  if(str != "map") return 0;
// This is wrong, Please use the below for better reading...
   if (present(str, ETO) != TO) {
            return 0;                       //notify_fail("You do not notice that here.\n");
        }
  TP->more("/d/shadow/city/obj/shadowmap");
  return 1;
}
