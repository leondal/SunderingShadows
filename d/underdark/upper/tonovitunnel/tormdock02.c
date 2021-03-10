#include <std.h>
#include "../defs.h"
inherit ROOM;

void create() {
    ::create();
    set_property("indoors",1);  
    set_property("light",2);
    set_travel(FOOT_PATH);
    set_terrain(NAT_CAVE);
    set_name("A small cave off the Dagger Sea");    
    set_short("%^BOLD%^%^BLUE%^A small cave off the Dagger Sea%^RESET%^");
    set_long("%^BOLD%^%^BLUE%^Carved by time and the %^CYAN%^waves%^BLUE%^"
", this secluded cave provides a narrow, almost unnoticed opening to the "
"encroaching %^BLACK%^Dagger Sea%^BLUE%^.  The rock shelf which circles "
"the half-moon shaped cave travels back toward a dark tunnel that looks "
"hand carved from the stone of the %^RESET%^Barrier Mountains"
"%^BOLD%^%^BLUE%^. Here, away from the dock, you can see "
"%^RESET%^%^ORANGE%^crates %^BOLD%^%^BLUE%^and %^RESET%^%^ORANGE%^barrels "
"%^BOLD%^%^BLUE%^stacked up neatly against the walls, awaiting transport "
"to their final destination.  On the other side of the cave you can see "
"several %^BLACK%^cages %^BLUE%^as well.  All are empty at the moment, "
"but based on their height you doubt it's for keeping animals.%^RESET%^\n");
    set_smell("default","The tang of the salty sea air fills the cave.");
    set_listen("default","You can hear the rush of the tide.");

    set_items(([
      ({"cave","rock shelf","shelf","half-moon"}) : "%^BOLD%^%^BLUE%^The "
"cave is small in size but big enough to provide a safe harbor for a boat "
"or two.  The deep waters of this cove allow even small ships to make "
"their way safely to the stone rim that serves as a dock here.%^RESET%^",
      ({"Dagger Sea","dagger sea","sea"}) : "%^RESET%^%^CYAN%^Due to the "
"natural formation of the cave's shape, you can't see the Dagger Sea from "
"here, but you can certainly hear the waves crashing against the stone "
"outside as well as watch the water flow and surge in the small "
"cove.%^RESET%^",
      ({"water","tide","waves"}) : "%^RESET%^%^CYAN%^Moving with the tide"
", you can see the water flowing in and out of the small cove.  It would "
"be a difficult place for swimming for the inexperienced.%^RESET%^",
      ({"tunnel","passage"}) : "%^BOLD%^%^BLUE%^Toward the back of the "
"cave you can see that a tunnel system opens up.  Based on the even size "
"and smooth edges, it looks to have been carved by hand. It would have "
"taken a lot of work to make such a thing and you have to wonder who "
"would have such dedication.%^RESET%^",
      ({"crates","crate","barrel","barrels"}) : "%^RESET%^%^ORANGE%^The "
"crates, barrels and chests all look to be in good condition.  Every one "
"of them is either locked or strapped with iron bands, making tampering "
"difficult if not impossible.  And unless you want to end up in those "
"cages across the way, its probably best not to tamper with "
"them.%^RESET%^",
      ({"cages","cage"}) : "%^BOLD%^%^BLACK%^Standing about five foot "
"tall and equally as wide, these cages are set off to the side out of the "
"way.  A terrible smell issues from them and you can almost feel the "
"misery of those who were once forced to endure their small "
"confines.%^RESET%^",
    ]));

    set_exits(([
      "south" : "/d/shadow/virtual/sea/tonovi.dock",
      "north" : TUNNEL"tormdock03",
    ]));
}
