#include <std.h>
#include <move.h>
#include "../tecqumin.h"

inherit ROOM;

string long_desc();

void create() {
  ::create();
  set_indoors(0);
  set_property("light", 2);
  set_terrain(GRASSLANDS);
  set_travel(FOOT_PATH);
  set_name("The lower tier of a ziggurat");
  set_short("The lower tier of a ziggurat");
  set_long( (:TO, "long_desc":) );
  set("night long",(:TO, "night_desc":));

  set_items(([  ]));
  set_smell("default","The scent of the jungle reaches you.");
  set_listen("default","The sounds of the jungle are all there is to be"
             +" heard.");
}
void init() {
   ::init();
}

string query_path(){
  return ROOMS;
}

string query_name(){
  return base_name(TO)[strlen(ROOMS)..strlen(base_name(TO))-1];
}

string long_desc(){
return "You stand upon one of the lower tiers of a mighty ziggurat. The"
      +" stones are covered with %^GREEN%^vines%^RESET%^ and trailing"
      +" %^GREEN%^creepers%^RESET%^. To the north, A large plaza stands"
      +" before the zigurrat, stretching away towards the %^ORANGE%^paths"
      +" %^RESET%^and %^CYAN%^canals%^RESET%^ of the lost city of the"
      +" %^CYAN%^Tecqumin%^RESET%^.";
}

string night_desc(){
  return "%^BLUE%^You stand upon one of the lower tiers of a mighty"
        +" %^RESET%^ziggurat%^BLUE%^. The %^RESET%^stones%^BLUE%^ are"
        +" covered with %^GREEN%^vines%^BLUE%^ and trailing"
        +" %^GREEN%^creepers%^BLUE%^ which grab at your feet in the"
        +" darkness. %^BOLD%^%^BLACK%^Darkness %^RESET%^%^BLUE%^ flows to"
        +" the north, where open space expands in front of the %^RESET%^"
        +"ziggurat%^BLUE%^.";
}
