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
return "Breaking through the upper canopies of the %^GREEN%^jungle"
      +"%^RESET%^, you stand on one of the higher tiers of a mighty"
      +" ziggurat, more than a hundred feet above the ground. The"
      +" %^BOLD%^%^CYAN%^s%^BLUE%^k%^CYAN%^y%^RESET%^ opens up above you,"
      +" breathtaking in its scale compared to the enclosed spaces you"
      +" have emerged from. Below you, they unfettered tangle of the"
      +" %^GREEN%^jungle%^RESET%^ seems to go on for miles in all"
      +" directions. A little way above, the ziggurat's zenith stands in"
      +" splendid isolation.";
}

string night_desc(){
  return "%^BLUE%^Breaking through the upper canopies of the%^GREEN%^"
         +" jungle%^BLUE%^, you stand on one of the upper tiers of the"
         +" %^RESET%^ziggurat%^BLUE%^. The night sky swaddles you in"
         +" %^BOLD%^%^BLACK%^darkness%^RESET%^%^BLUE%^, and the %^BOLD%^"
         +"%^BLACK%^black silhouettes%^RESET%^%^BLUE%^ of the %^BOLD%^"
         +"%^BLACK%^jungle's tangled shapes%^RESET%^%^BLUE%^ spread out"
         +" for miles all around. You sense that the ziggurat's"
         +" %^RESET%^zenith%^BLUE%^ is not far away.";
}

