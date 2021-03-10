#include <std.h>
inherit ROOM;


void create() {
  ::create();
  set_property("light", 1);
  set_property("indoors",1);
  set_short("The stables of Sanctuary");
  set_long("%^BOLD%^%^YELLOW%^
      Welcome to the stables of Sanctuary%^RESET%^%^CYAN%^
The stables are a dark and foreboding structure, even though lanterns
hang on pegs throughout the building.  A wooden sign hangs on the 
wall.  Many of the horses in the stables are restless, especially 
during rainstorms, and the majority of them are in need of exercise.  
With the current threat to Sanctuary, Orvig has been reluctant to 
let the horses out.");

  set_smell("default", "You smell fresh hay, manure, and leather.");
  set_listen("default", "You hear the neighing of many mounts back in the "
                        "stables area.");
  set_exits( ([
     "west" : "/d/dragon/town/general",
     "south" : "/d/dragon/town/roadE2"
           ]) );
  set_items( ([
"sign" : "\n"
"%^BOLD%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n"+
"%^RESET%^\n"
"                        %^RED%^MOUNTS OFFERED FOR RENT:\n"+
"%^RESET%^\n"
"%^BOLD%^%^YELLOW%^  Steppe Pony       *lvl 11 or higher*           200 gold\n"
"%^BOLD%^%^YELLOW%^  Medium Warhorse   *lvl 11 or higher*           225 gold\n"
"%^BOLD%^%^YELLOW%^  Heavy Warhorse    *lvl 11 or higher*           400 gold\n"
"%^RESET%^\n"
"%^BOLD%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n"+
  "\n"
     ]) );
}


void reset() {
  ::reset();
  if(!present("stablemaster")) {
    new("/d/dragon/mon/stmaster")->move(TO);
   }
}
