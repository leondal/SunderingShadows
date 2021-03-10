//updated 4/17/04 for return of Bane by Circe
#include "/d/dagger/tonovi/town/short.h"

inherit "/std/church.c";

void create(){
    ::create();
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("light",2);
    set_property("indoors",1);
    set_name("Ruined Outer Chamber");
    set_short("%^ORANGE%^Ruined %^ORANGE%^Outer %^BOLD%^%^BLACK%^C%^RESET%^%^ORANGE%^hamber");
    set_long("%^ORANGE%^Ruined %^ORANGE%^Outer %^BOLD%^%^BLACK%^C%^RESET%^%^ORANGE%^hamber
%^BOLD%^%^BLACK%^The ceiling of this ruined chamber has collapsed, burying all beneath it in a massive pile of %^RESET%^%^ORANGE%^rubble%^BOLD%^%^BLACK%^.%^BLACK%^ No sign remains of what this room once was, today there stands a simple stone altar to all gods in the middle, with candles and a bowl. A great %^BLACK%^a%^RESET%^%^ORANGE%^rchw%^BOLD%^%^BLACK%^a%^RESET%^%^ORANGE%^y%^BOLD%^%^BLACK%^ looks to have led to the east at one time, but the chamber beyond is now completely inaccessible. A similar archway still leads to the south, but it doesn't look like you'll find much there.%^RESET%^\n"
    );
    set_smell("default","You can still smell smoke and dust on the air.");
    set_listen("default","All is deathly quiet here.");
    set_items(([
       ({"rubble","ruins","stone"}) : "The black stone that  once formed this temple has fallen about in utter  ruin. It has been covered over with a fine layer of  dust and filth.",
       ({"altar"}) : "Simple stone slab, cut and decorated in holy symbols. Dedicated to all gods.",
       ({"archway","archways"}) : "There are two archways, one to the east and one to the south.",
       ({"south archway","southern archway"}) : "The southern  archway still stands and seems, miraculously, to have  avoided whatever it was that destroyed this place.  The same cannot be said for the chamber beyond.",
       ({"east archway","eastern archway"}) : "The eastern  archway is completely destroyed, clearly smashed  from above. The chamber beyond is inaccessible.",
    ]));
    set_exits(([
      "north" : RPATH "street8",
    ]));
}
