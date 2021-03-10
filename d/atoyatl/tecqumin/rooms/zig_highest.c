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
return "You stand just below the zenith of the ziggurat. Above you, you"
      +" can make out a four-columned structure with a pagoda style roof,"
      +" with some form of altar arranged beneath it. There is a cooling+"
      +" %^BOLD%^%^CYAN%^br%^RESET%^ee%^BOLD%^%^CYAN%^ze%^RESET%^ up"
      +" where, in contrast to the stifling %^ORANGE%^humidity%^RESET%^"
      +" of the %^BOLD%^%^GREEN%^j%^RESET%^%^GREEN%^u%^BOLD%^%^GREEN%^ngl"
      +"%^RESET%^%^GREEN%^e%^RESET%^ below. In the distance, beyond the"
      +" dark green spread of the %^GREEN%^jungle%^RESET%^, you can make"
      +" out the %^CYAN%^sh%^BOLD%^%^WHITE%^i%^RESET%^%^CYAN%^mm%^BOLD%^"
      +"%^CYAN%^e%^RESET%^%^CYAN%^r%^BOLD%^%^CYAN%^i%^RESET%^%^CYAN%^ng"
      +" %^BOLD%^%^BLUE%^bl%^CYAN%^u%^BLUE%^e%^RESET%^ of the %^BOLD%^"
      +"%^BLUE%^sea%^RESET%^, and possibly the built shapes of some sort"
      +" of %^ORANGE%^civilisation%^RESET%^.";
}

string night_desc(){
  return "%^BLUE%^You stand just below the %^CYAN%^zenith%^BLUE%^ of the"
        +" %^RESET%^ziggurat%^BLUE%^. Above you, the shape of a pagoda"
        +" roof supported on four columns is %^BOLD%^%^BLACK%^silhouetted"
        +"%^RESET%^%^BLUE%^ against the night sky. There is a cooling"
        +" %^CYAN%^br%^RESET%^ee%^CYAN%^ze%^BLUE%^ up here, in contrast"
        +" to the stifling heat of the %^GREEN%^jungle%^BLUE%^ down"
        +" below.";
}

