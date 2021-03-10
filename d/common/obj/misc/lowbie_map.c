//Coded by ~Circe~ to reflect the lowbie areas and hopefully provide 
//better navigation for new players.  The text file is used in 
//several places - please do not remove it.
#include <std.h>

inherit OBJECT;

void init(){
  ::init();
  add_action("read_map","read");
}

void create() {
  ::create();
  set_id(({"map","lowbie map","map of lowbie areas"}));
  set_name("map");
  set_short("A map of the area west of Shadow");
  set_long("This map is drawn on high quality parchment weatherproofed "+
     "against the elements.  It contains a sketch of all the areas "+
     "west of the city of Shadow.  You should read it.");
  set_weight(0);
  set_value(0);
}

int read_map(string str){
  if(!str) notify_fail("Read what?");
  if(str != "map") return 0;
  TP->more("/d/common/text/lowbie_map");
  return 1;
}