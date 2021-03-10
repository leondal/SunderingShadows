#include <std.h>
#include <move.h>
#include "../../tecqumin.h"

inherit TABAXBASE + "stock_wall_base.c";


void create() {
  ::create();
  set_exits( ([ "east" : TABAXROOM + "stock_wall2" ,
                 "south": TABAXROOM + "high_field",
                 "north": TABAXROOM + "treetop_base3",
                 "west" : TABAXROOM + "jungle07" ]) );
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
