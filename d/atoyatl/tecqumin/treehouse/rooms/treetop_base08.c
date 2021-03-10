#include <std.h>
#include "../../tecqumin.h"
inherit J_MAZE;

void create(){
  string filename, room_num;
  ::create();
  set_exits( ([ "southeast" : TREEHOUSE + "/rooms/" + "t_house_base"]) );
  filename = file_name(TO);
  room_num = filename[strlen(filename)-2..strlen(filename)-1];
  set_climb_exits(([
    "climb":({TREEHOUSE + "/rooms/" + "treetop" + room_num,2,0, 30}),
  ]));
}

string long_desc(){
  string desc;
  desc = ::long_desc();
  desc += "%^GREEN%^The trees here look like they would be quite easy to"
         +" climb.\n%^RESET%^There is a clearing in the jungle to the"
         +" southeast";
  return desc;
}