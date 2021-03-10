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
      +" %^GREEN%^creepers%^RESET%^. The %^GREEN%^jungle%^RESET%^ presses"
      +" in close on every side, its canopies closing out most of the"
      +" sun's rays. Such %^ORANGE%^l%^YELLOW%^i%^RESET%^%^ORANGE%^ght"
      +" %^RESET%^as does break through casts a dappled, %^GREEN%^m"
      +"%^ORANGE%^o%^GREEN%^s%^ORANGE%^a%^BOLD%^%^GREEN%^i%^RESET%^"
      +"%^ORANGE%^c%^RESET%^ pattern on the stones.";
}

string night_desc(){
  return "%^BLUE%^You stand upon one of the lower tiers of a mighty"
        +" %^RESET%^ziggurat%^BLUE%^. The %^RESET%^stones%^BLUE%^ are"
        +" covered with %^GREEN%^vines%^BLUE%^ and trailing"
        +" %^GREEN%^creepers%^BLUE%^ which grab at your feet in the"
        +" darkness. The tangled %^BOLD%^%^BLACK%^black silhouettes"
        +" %^RESET%^%^BLUE%^of the %^GREEN%^jungle%^BLUE%^ press in all"
        +" around, barely distinguishable against the night sky.";
}
