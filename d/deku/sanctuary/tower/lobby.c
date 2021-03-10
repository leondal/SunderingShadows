#include <std.h>
#include "../dragon.h";

inherit BTOWER;

void create() {
   ::create();
   set_long(
      "%^RESET%^A large %^BOLD%^%^YELLOW%^chandelier"+
      " %^RESET%^hangs from the ceiling, basking the room in a"+
      " warm glow. A grand staircase rises to a large"+
      " balcony that surrounds the entire foyer area."+
      " There are two doors on either side of this"+
      " foyer which are ornately crafted. %^RESET%^"+
      "%^GREEN%^Plants %^RESET%^sit around the foyer"+
      " giving it an almost exotic look about it."+
      " The floors are made out of marble and reflect"+
      " the light around the room, making it look magical."
   );
   set_items( ([
      "plants" : "These plants are more like small trees, that surround the foyer.",
      "staircase" : "This grand staircase is made of marble and has oak handles which to hold onto as you walk atop it.",
      "chandelier" : "The large crystal chandelier is beautiful and made of crystal.",
   ]) );
   set_exits( ([
      "upstairs" : TOWER+"balcony01",
      "downstairs" : TOWER+"stairs",
      "east" : TOWER+"library",
      "west" : TOWER+"conference",
   ]) );
}

void reset() {
   ::reset();
   if(!present("animated guard")) {
      new(MON+"guard")->move(TO);
      new(MON+"guard")->move(TO);
   }
}
