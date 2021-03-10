#include <std.h>
#include "../../tecqumin.h"
inherit J_ROOM;

void create(){
  string filename, room_num;
  ::create();
  set_exits( ([ "south" : TABAXROOM + "stock_wall2", 
                "west" : TABAXROOM + "treetop_base3",
                "north" : TABAXROOM + "jungle27",
                "east" :  TABAXROOM + "treetop_base1"]) );
  filename = file_name(TO);
  room_num = filename[strlen(filename)-1..strlen(filename)-1];
  set_climb_exits(([
    "climb":({TABAXROOM + "treetop" + room_num,2,0, 30}),
  ]));
}

string long_desc(){
  string desc;
  desc = ::long_desc();
  desc += "%^GREEN%^The trees here look like they would be quite easy to"
         +" climb.\n%^RESET%^There is wooden %^ORANGE%^stockade%^RESET%^ in a clearing in the jungle"
         +" to the south";
  return desc;
}
