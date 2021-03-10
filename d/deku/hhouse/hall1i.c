#include <std.h>
#include "/d/deku/inherits/deku.h"

inherit "/d/deku/inherits/hauntings_inh.c";

void create() {
    ::create();
    set_property("light",2);
    set_property("indoors",1);
    set_terrain(WOOD_BUILDING);
    set_travel(DECAYED_FLOOR);
    set_name("Haunted House");
    set_short("%^CYAN%^Haunted House%^RESET%^");
    set_long( (: TO, "ldesc" :) );
    set_listen("default","You hear the evidence of rodent and insect infestation.");
     set_smell("default","The smells of mold and decay fill the stale air.");
    set_items(([
      "mold" : "%^CYAN%^It seems to be growing on everything.",
      "rubbish" : "%^ORANGE%^It looks like no one has cleaned up here in ages.",
    ] ));
    set_exits(([
       "north" : HH_ROOMS+"study",
       "south" : HH_ROOMS+"library",
       "west" : HH_ROOMS+"living_1i",
       "east" : HH_ROOMS+"entrance"
    ] ));
    hauntings();
}

string ldesc(string str) {
   return("The hallway is very dilapidated and damp, with patches of "
      "what you hope is just harmless %^CYAN%^mold %^RESET%^everywhere.  "
      "Cobwebs festoon the hallways and the woodwork looks rather rotten.  "
      "Dust and dirt are thick throughout and %^ORANGE%^rubbish %^RESET%^"
      "is scattered about in profusion.  Plaster that has fallen from the "
      "ceiling and walls lies on the floor in several places.\n");
}