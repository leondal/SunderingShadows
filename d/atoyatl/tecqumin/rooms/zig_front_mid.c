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
  set_name("A middle tier of a ziggurat");
  set_short("A middle tier of a ziggurat");
  set_long( (:TO, "long_desc":) );
  set("night long",(:TO, "night_desc":));

  set_items(([  ]));
  set_smell("default","The scent of the jungle reaches you");
  set_listen("default","The souds of the jungle are all there is to be"
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
return "You stand upon one of the middle tiers of a mighty ziggurat."
      +" Clear %^BOLD%^%^WHITE%^l%^YELLOW%^i%^WHITE%^ght%^RESET%^"
      +" strikes the bare stone from the open %^BOLD%^%^CYAN%^sky"
      +" %^RESET%^above. A large plaza stretches away to the north,"
      +" leading on to the %^ORANGE%^paths%^RESET%^ and %^CYAN%^canals"
      +" %^RESET%^of the lost city of the %^CYAN%^Tecqumin%^RESET%^.";
}

string night_desc(){
  return "%^BLUE%^You stand on one of the middle tiers of a mighty"
     +" %^RESET%^ziggurat%^BLUE%^.The night sky above is dark, and"
     +" the %^BOLD%^%^BLACK%^darkness %^RESET%^%^BLUE%^stretches away"
     +" to the north, where the plaza stands before the lost city of"
     +" the%^CYAN%^ Tecqumin%^BLUE%^.";
}

