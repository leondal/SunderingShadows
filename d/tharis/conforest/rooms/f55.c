#include <std.h>
#include "../defs.h"
inherit INC+"forest";

void create()
{
  ::create();
  set_exits(
    ([
    "east" : ROOMS+"f56",
    "north" : ROOMS+"f47"
    ]) );
	set_search("forest","You look over the forest carefully "+
		"and notice a hidden path to west, but you will have "+
		"to enter the forest to take that path.\n");
}
void init() {
  	::init();
  	add_action("path_em","enter");
}
int path_em(string str) {
 	if(!str) {
   	tell_object(TP,"Enter where?");
      return 1;
   }
  	if(str == "forest" || str == "the forest"){
     	tell_object(TP,"You leave the main path and enter the forest.\n");
     	tell_room(ETP,""+TPQCN+" leaves the path to the west.\n",TP);
     	TP->move("/d/shadow/room/city/secret/stefano/path");
     	return 1;
   }
	return 1;
}
