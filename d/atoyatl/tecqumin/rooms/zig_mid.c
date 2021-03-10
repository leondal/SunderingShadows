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
      +" Trailing %^GREEN%^vines%^RESET%^ and %^GREEN%^creepers%^RESET%^"
      +" stretch across from the upper canopy of the surrounding"
      +" %^GREEN%^jungle%^RESET%^ and paths of clear %^BOLD%^%^WHITE%^l"
      +"%^YELLOW%^i%^WHITE%^ght%^RESET%^ break through here and there to"
      +" strike the bare stone.";
}

string night_desc(){
  return "%^BLUE%^You stand on one of the middle tiers of a mighty"
        +" %^RESET%^ziggurat%^BLUE%^. Glimpses of the night sky can be"
        +" seen through occasional gaps in the upper canopies of the"
        +" surrounding %^GREEN%^jungle%^BLUE%^. Trailing %^GREEN%^vines"
        +" %^BLUE%^and %^GREEN%^creepers%^BLUE%^ threaten to grab and"
        +" snare unwary feet in the %^BOLD%^%^BLACK%^darkness"
        +"%^RESET%^%^BLUE%^.";
}

