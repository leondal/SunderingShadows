#include <std.h>
#include <move.h>
#include "../../tecqumin.h"

inherit TABAXROOM + "battlement.c";


void create() {
  ::create();
  set_short("On the battlement");
/*  set_long("You are on the battlement, above the main gate of the stockade. You can see over to the"
          +" main field outside from here. If you wanted, you could target enemies in the field"
          +", with a missile weapon. A ladder leads up to the watchtower above the gate here."
          +" There doesn't appear to be an easy way down, but to the east and west, you"
          +" can see ladders leading down into the stockade."); */

  set_exits( ([ "west" : TABAXROOM + "battlement7" ,
                "east": TABAXROOM + "battlement5",
                "up": TABAXROOM + "watchtower",
              "stock"   : TABAXROOM + "stockade",
              "sw"    : TABAXROOM + "southwest_corner",
              "se"    : TABAXROOM + "southeast_corner"
             ]) );
  set_invis_exits( ({"stock", "se", "sw" }) );
  set_pre_exit_functions( ({ "stock", "se", "sw"}),({ "go_on", "go_on", "go_on" }) );
  field_name = TABAXROOM + "main_field";
  set_field(find_object_or_load(field_name));

}

string query_granary_dir(){
  return "east";
}


void clean_up(){
  string f;
  f = field_name;
  ::clean_up();
  field_name = f;
}

void init(){
  ::init();
  if (!objectp(field)){
    set_field(find_object_or_load(field_name));
  }
}

int go_on(){
  return 0;
}

string long_desc(){
  string desc;
  desc = ::long_desc();
  desc += " A %^ORANGE%^ladder%^RESET%^ leads up to the watchtower above the gate.";
  return desc;
}
