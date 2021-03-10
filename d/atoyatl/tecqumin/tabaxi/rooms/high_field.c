#include <std.h>
#include "../../tecqumin.h"
inherit TABAXROOM + "field_base.c";


string long_desc();

void create() {
  ::create();
  set_indoors(0);
  set_property("light", 2);
  set_terrain(GRASSLANDS);
  set_travel(FOOT_PATH);
  set_name("The high field");
  set_short("%^GREEN%^A well tended m%^ORANGE%^a%^GREEN%^i%^BOLD%^%^YELLOW%^z%^RESET%^%^GREEN%^e"
           +" field");
  set_long( (:TO, "long_desc":) );
  set_items(([ ({"maize", "corn"}): (: TO, "long_corndesc" :),  
               ({"battlement", "battlements"}): (: TO, "batt_desc" :)    ]));
  set_exits( (["north" : TABAXROOM + "stock_wall3", 
                "south" : TABAXROOM + "corner_field1",
                "west" : TABAXROOM + "jungle05",
           "southeast" : TABAXROOM + "entry"
                ]) );
  battlement = find_object_or_load(TABAXROOM + "battlement8");
  set_pre_exit_functions( ({"east" }), ({"go_east"}) );
}
void init() {
   ::init();
}

int go_east(){
  object room;
  room = find_object_or_load(TABAXROOM + "main_field");
  if (objectp(room)){
    room->on_entry(TP, TO);
  }
  return 1;
}

void reset_battlement(){
  battlement = find_object_or_load(TABAXROOM + "battlement8");
}
string long_desc(){
  string desc, corndesc, pitdesc, stakedesc;
  corndesc = corn_desc(); // Gives a different description for the maize, depending on current month
  pitdesc = pit_desc(); //gives a description of the pits (if any) in the field
  stakedesc = stake_desc(); // gives a description of the stakes (if any) in the field
  desc = "You stand in a large field of maize. " + corndesc + " A solid looking %^ORANGE%^stockade"
        +" %^RESET%^forms part of the boundary to the west. The rest of the boundary is marked by a"
         +" raised terrace leading up to another %^GREEN%^field%^RESET%^. The %^GREEN%^j%^BOLD%^"
         +"%^GREEN%^u%^RESET%^%^GREEN%^ng%^BOLD%^%^GREEN%^l%^RESET%^%^GREEN%^e%^RESET%^ to the east is"
         +" thick and impenetrable. To the north, there is just space to get in between the%^GREEN%^"
         +" j%^BOLD%^%^GREEN%^u%^RESET%^%^GREEN%^ng%^BOLD%^%^GREEN%^l%^RESET%^%^GREEN%^e%^RESET%^ and"
         +" the %^ORANGE%^stockade%^RESET%^.\n";
  if (pitdesc) desc += pitdesc;
  if (stakedesc) desc += stakedesc;
  return desc;
}


