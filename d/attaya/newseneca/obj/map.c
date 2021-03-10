//~Circe~ 11/3/07 for new Seneca

#include <std.h>

inherit OBJECT;

void create() {
  ::create();
  set_name("map of seneca");
  set_id(({"map","seneca map","map of seneca","map of Seneca"}));
  set_short("A map of Seneca");
  set_long("This is a map of Seneca drawn on high quality parchment "+
     "that has been weather-proofed so it will not run.  All of the "+
     "major locations of the city are on here, though the city is "+
     "often expanding.  You should read it.");
  set_weight(0);
  set_value(0);
}

void init(){
  ::init();
  add_action("read_map","read");
}

int read_map(string str){
  if(!str) notify_fail("Read what?");
  if(str != "map") return 0;
  TP->more("/d/attaya/newseneca/obj/final_map");
  return 1;
}