#include <std.h>
#include "/d/islands/tonerra/areadefs.h"
inherit I_JUNGLE;

void create(){
  ::create();
  set_short("A clearing in the jungle");
  set_long(
@VETRI
%^GREEN%^You are in a small clearing in the middle of the 
jungle. Trees surround you on all sides. Small plants
grow around you, the occasional animal tracks are present.
There is a path to the north leading back into the jungle.
VETRI
  );
  set_indoors(0);
  set_light(2);
  set_listen("default","You hear movement in the jungle and wonder if it is the wind.");
  set_exits(([
    "north":PATH+"path61",
  ]));

	set_search("jungle","%^BOLD%^%^GREEN%^Straining hard to make out things in the "+
		"darkness of the foilage you find a greater darkness to the southwest, "+
		"maybe you can enter the jungle from here and explore that darkness "+
		"further is you have the backbone for it.%^RESET%^\n");
}
void init() {
  ::init();
  add_action("enter_em","enter");
}
int enter_em(string str) {
    if(!str) {
        tell_object(TP,"Enter what?");
        return 1;
    }
  if(str == "jungle"){
     tell_object(TP,"You force your way into the dense jungle foilage and leave the "+
		"clearing completely!\n");
     tell_room(ETP,""+TPQCN+" moves into the dense jungle foilage to have a better "+
     		"look and disappears!.\n",TP);
     TP->move("/d/guilds/raiders/mosutha/rooms/mosent");
     tell_object(TP,"You find yourself inside a small cave.\n");     
     return 1;
     }
}