#include <std.h>
#include <move.h>
#include "../../tecqumin.h"

inherit TABAXBASE + "stock_wall_base.c";


void create() {
  ::create();
  set_exits( ([ "west" : TABAXROOM + "stock_wall2" ,
                 "south": TABAXROOM + "low_field",
                  "north": TABAXROOM + "treetop_base1",
              "east": TABAXROOM + "jungle06" ]) );
  set_pre_exit_functions( ({"south" }), ({"go_south"}) );
}

int go_south(){
  object room;
  room = find_object_or_load(TABAXROOM + "low_field");
  if (objectp(room)){
    room->on_entry(TP, TO);
  }
  return 1;
}


string long_desc(){
  string desc;
  desc = ::long_desc();
  desc += "\n%^RESET%^You can see a %^GREEN%^terraced field%^RESET%^ to the south\n";
  return desc;
}

int climb(string str){
  if (!stringp(str)){
    tell_object (TP, "Climb what?");
    return 1;
  }
  if (str == "wall" || str == "stockade" || str == "fence" || str == "stockade fence"){
    tell_object(TP, "The fence here is all green and slippery with moss and mildew from its proximity"
                   +" to the edge of the jungle. It would be near impossible to climb. It would be"
                   +" easier to head north and climb one of the trees");
    return 1;
  }
  tell_object(TP, "You can't climb " + str);
  return 1;
}
