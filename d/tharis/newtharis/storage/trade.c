#include <std.h>
#include "../tharis.h"
inherit ROOM;

void create() {
    ::create();
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("indoors",0);
    set_property("light",1);
    set_name("Bustling street");
    set_short("%^RESET%^%^CYAN%^Bus%^GREEN%^t%^CYAN%^ling stre%^GREEN%^e%^CYAN%^t%^RESET%^");
    set_long("%^RESET%^%^CYAN%^Drawing the eye before anything else here is the vast, looming bulk of "
"the hovering %^BLUE%^Shadovar %^CYAN%^fortress, far in the sky above. It casts the entire city under "
"a pall of unrelenting %^BOLD%^%^BLACK%^darkness%^RESET%^%^CYAN%^. Below, the normal bustle of the city "
"continues without pause, perhaps less %^RED%^busy %^CYAN%^here than the central bazaar, but not by much. "
"Occasional guards pass by, as much a present reminder of law and order as the distant fortress above. "
"Storefronts line either side of the street here, with b%^YELLOW%^r%^RESET%^%^CYAN%^igh%^BOLD%^%^MAGENTA%^t "
"%^RESET%^%^CYAN%^sign%^BOLD%^%^CYAN%^a%^RESET%^%^CYAN%^ge in the windows and the occasional worker "
"emerging to shout for customers. Shoppers come and go at all times of the day, a constant stream of feet "
"passing over the well-kept %^ORANGE%^cobblestones%^CYAN%^.");
    set_smell("default","%^RESET%^%^ORANGE%^The air carries a thousand scents of a busy city.%^RESET%^");
    set_listen("default","%^GREEN%^You hear the bustle of the citizens going about their day.%^RESET%^");
    set_items (([
      "fortress" : "%^BLUE%^Above the city looms the ever-present Shadovar fortress, casting the entire "
"area into a state of perpetual twilight.%^RESET%^",
      "buildings" : "%^RESET%^%^CYAN%^Most of the buildings here are old, but seem to be kept in a good "
"state of repair. Almost all of the ground-level doorways seem to lead directly into shops, though you "
"suspect the upper levels may be living quarters for the shopkeepers and their families. Bright signage "
"proudly declares the wares of each store to the street.%^RESET%^",
      ({"ground","street","cobblestones"}) : "%^RESET%^%^ORANGE%^The streets here are carefully "
"laid cobblestone.%^RESET%^",
    ]));
}

void init() {
    ::init();
    if(!present("tharisambiancexxx",TP)) new(OBJ"ambiance")->move(TP);
}