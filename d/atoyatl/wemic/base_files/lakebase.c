#include <std.h>
#include <move.h>
#include "../wemic.h"

inherit ROOM;

string long_desc();

void create() {
  ::create();
  set_indoors(0);
  set_property("light", 2);
  set_terrain(JUNGLE);
  set_travel(FOOT_PATH);
  set_name("village footpath");
  set_short("village footpath");
  set_long( (:TO, "long_desc":) );
  set("night long",(:TO, "night_desc":));

  set_items(([  ]));
  set_smell("default","You can smell the freshwater lake, and the myriad"
                     +" scents of the jungle.");
  set_listen("default","Waves lap gently against the shore and you can"
                      +" hear the quiet murmurings of village life.");
}
void init() {
   ::init();
}

string long_desc(){
return "You are by the side of the %^BOLD%^%^BLUE%^l%^CYAN%^a%^BLUE%^ke"
      +"%^RESET%^. A short, gravelly beach leads down to the %^BOLD%^"
      +"%^CYAN%^water%^RESET%^. A small village of %^ORANGE%^tents%^RESET%^"
      +" is behind the beach, and more %^BOLD%^%^GREEN%^j%^RESET%^"
      +"%^GREEN%^u%^BOLD%^%^GREEN%^ng%^RESET%^%^GREEN%^l%^BOLD%^%^GREEN%^e"
      +" %^RESET%^beyond that.";
}

string night_desc(){
  return "%^BLUE%^You are by the side of the %^BOLD%^%^BLUE%^l%^CYAN%^a"
        +"%^BLUE%^ke%^RESET%^%^BLUE%^. A short, %^RESET%^gravelly%^BLUE%^"
        +" beach leads down to the %^BOLD%^%^CYAN%^water%^RESET%^%^BLUE%^."
        +" A small village of %^ORANGE%^tents%^RESET%^%^BLUE%^ is behind"
        +" the beach, and more %^BOLD%^%^GREEN%^j%^RESET%^%^GREEN%^u"
        +"%^BOLD%^%^GREEN%^ng%^RESET%^%^GREEN%^l%^BOLD%^%^GREEN%^e"
        +" %^RESET%^%^BLUE%^beyond that.";
}

