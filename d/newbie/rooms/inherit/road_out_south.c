//road_out_south2 - inherited file for mountainous section of southern end of road between Offestry & Shadow

#include <std.h>
#include "../../newbie.h"

inherit ROOM;

void create(){
   ::create();
   set_property("light",3);
//   set_property("no teleport",1);
   set_short("%^CYAN%^Winding mountain pass%^RESET%^");
	set_terrain(NEW_MOUNTS);
	set_travel(FOOT_PATH);
   set_long( (: TO,"ldesc" :) );
   set_smell("default","You catch a scent of pine in the thin mountain air.");
   set_listen("default","You hear the wind rushing through the trees.");
   set_items( ([ 
   	  ({"trees","pine trees"}): "%^CYAN%^The pine trees are sparse.", 
      ({"ivy", "ferns", "undergrowth"}):"%^GREEN%^The ivy is a dark green and ferns more plentiful.%^RESET%^", 
	  "path":"%^ORANGE%^This part of the path seems to be heavily traveled.%^RESET%^" ]) );
}

string ldesc(string str) {
  return("%^CYAN%^Winding mountain pass%^RESET%^\n"
    "You are on a winding road crossing over and through a mountain range.  "
    "The path is steep and rocky here, making each step a struggle to keep "
    "your balance.  Pine trees and scraggly bushes seem to be the only "
    "vegetation.");
}