#include <std.h>
#include <move.h>
#include "../../tecqumin.h"

inherit TABAXROOM + "battlement.c";


void create() {
  ::create();

  set_short("On the battlement");
  set_long("You are on the battlement, above the southwest corner of the stockade. You can see over to"
          +" the main field outside from here. If you wanted, you could target enemies in the field"
          +", with a missile weapon. To the east, the battlement runs across the top of the main gate"
          +" of the stockade. There is a ladder leading down into the stockade here.");
  set_exits( ([ "north" : TABAXROOM + "battlement8" ,
                "east": TABAXROOM + "battlement6",
                "down": TABAXROOM + "southwest_corner",
             "watch" : TABAXROOM + "watchtower",
             "stock"   : TABAXROOM + "stockade",
             "bt5"   : TABAXROOM + "battlement5",
             ]) );
  set_invis_exits( ({"watch", "stock", "bt5", "se" }) );
  set_pre_exit_functions( ({"watch", "stock", "bt5", "se"}),({"go_on", "go_on", "go_on", "go_on" }) );
  field_name = TABAXROOM + "main_field";
  set_field(find_object_or_load(field_name));
}

string query_granary_dir(){
  return "down";
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
