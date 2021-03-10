#include <std.h>
#include "../../tecqumin.h"

#define DEST "/daemon/destinations_d.c"

inherit J_ROOM;

void create(){
  string filename, room_num;
  ::create();
  DEST->add_waystation(file_name(TO), file_name(TO), 1);
  DEST->add_waystation(file_name(TO), TABAXROOM + "jungle07", 2);
  DEST->add_waystation(file_name(TO), TABAXROOM + "jungle27", 2);
  DEST->add_waystation(file_name(TO), TABAXROOM + "jungle16", 3);
  DEST->add_waystation(file_name(TO), TABAXROOM + "jungle18", 3);
  set_exits( ([ "south" : TABAXROOM + "stock_wall1",
                 "east" : TABAXROOM + "jungle08",
             "southeast": TABAXROOM + "jungle06",
           "northeast"  : TABAXROOM + "jungle11",
            "northwest" : TABAXROOM + "jungle27",
                 "west" : TABAXROOM + "treetop_base2"
]) );
  filename = file_name(TO);
  room_num = filename[strlen(filename)-1..strlen(filename)-1];
  set_climb_exits(([
    "climb":({TABAXROOM  + "treetop" + room_num,2,0, 30}),
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
