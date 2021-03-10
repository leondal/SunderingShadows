#include <std.h>
#include <move.h>
#include "../../tecqumin.h"

inherit TABAXROOM + "battlement.c";


void create() {
  ::create();
  set_short("On the battlement");
  set_long("You are on the battlement, above the northwest corner of the stockade. You can see over to"
          +" the high field outside from here. If you wanted, you could target enemies in the field"
          +", with a missile weapon. There is a ladder leading down into the stockade here.");
  set_exits( ([ "east" : TABAXROOM + "battlement2" ,
                "south": TABAXROOM + "battlement8",
                 "down": TABAXROOM + "northwest_corner"
             ]) );
  field_name = TABAXROOM + "high_field";
  set_field(find_object_or_load(field_name));
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

string query_granary_dir(){
  return "down";
}
