#include <std.h>
#include <move.h>
#include "../tecqumin.h"

inherit ROOM;

string long_desc();

void create() {
  ::create();
  set_indoors(0);
  set_property("light", 2);
  set_terrain(BEACH);
  set_travel(FOOT_PATH);
  set_property("no teleport", 1);
  set_name("A secret beach");
  set_short("%^BOLD%^%^YELLOW%^On an island beach");
  set_long( "%^BOLD%^%^YELLOW%^You are on the beach of a small, secret"
           +" island in the middle of a %^BOLD%^%^GREEN%^j%^RESET%^"
           +"%^GREEN%^u%^BOLD%^%^GREEN%^ng%^RESET%^%^GREEN%^l%^BOLD%^"
           +"%^GREEN%^e %^RESET%^%^BLUE%^river%^BOLD%^%^YELLOW%^. Beyond"
           +" the sand, the %^RESET%^%^GREEN%^trees %^BOLD%^%^YELLOW%^"
           +"are dense." );
  set_items(([  ]));
  set_smell("default","The air is heavy with %^CYAN%^humidity%^ORANGE%^"
                    +" and the heady scent of %^GREEN%^j%^BOLD%^"
                    +"%^GREEN%^u%^RESET%^%^GREEN%^ngle %^ORANGE%^plant"
                    +" life");
  set_listen("default","You can hear the water flowing swiftly by.");
  set_exits( ([ "southwest" : ROOMS + "beach3" ,
                "southeast" : ROOMS + "beach2"]) );
}
void init() {
   ::init();
}
