#include <std.h>
#include <move.h>
#include "../../tecqumin.h"

inherit TABAXBASE + "stock_wall_base.c";


void create() {
  ::create();
  set_exits( ([ "east" : TABAXROOM + "stock_wall1" ,
                 "west": TABAXROOM + "stock_wall3",
                "north": TABAXROOM + "treetop_base2" ]) );
}


string long_desc(){
  string desc;
  desc = :: long_desc();
  desc += "The %^ORANGE%^wooden stockade fence %^RESET%^blocks the way to the south.";
  return desc;
}
