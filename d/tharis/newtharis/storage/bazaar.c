#include <std.h>
#include "../tharis.h"
inherit VAULT;

void create() {
    ::create();
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("indoors",0);
    set_property("light",1);
    set_name("The city bazaar");
    set_short("%^BOLD%^%^CYAN%^The city bazaar%^RESET%^");
    set_long("%^RESET%^%^CYAN%^Drawing the eye before anything else here is the vast, looming bulk of "
"the hovering %^BLUE%^Shadovar %^CYAN%^fortress, far in the sky above. It casts the entire city under "
"a pall of unrelenting %^BOLD%^%^BLACK%^darkness%^RESET%^%^CYAN%^. Below, the bustle and noise of the "
"city reaches a pitch here in the market place. People rush from store to store, while %^ORANGE%^shop "
"keepers%^CYAN%^, %^MAGENTA%^vendors%^CYAN%^, %^BOLD%^%^BLACK%^con men %^RESET%^%^CYAN%^and "
"%^BOLD%^%^WHITE%^lunatics %^RESET%^%^CYAN%^all vie for their attention. C%^BOLD%^%^CYAN%^o"
"%^RESET%^%^CYAN%^lor%^BOLD%^%^RED%^f%^RESET%^%^CYAN%^ul %^BOLD%^%^MAGENTA%^s%^RESET%^%^CYAN%^ta"
"%^YELLOW%^l%^RESET%^%^CYAN%^ls are set up to sell almost anything your heart could desire. The street "
"is made up of carefully placed %^ORANGE%^cobblestones %^CYAN%^and the buildings are c%^BOLD%^%^CYAN%^o"
"%^RESET%^%^CYAN%^lor%^BOLD%^%^RED%^f%^RESET%^%^CYAN%^ul and well maintained.");
    set_smell("default","%^RESET%^%^ORANGE%^The air carries a thousand scents of a busy city.%^RESET%^");
    set_listen("default","%^GREEN%^You hear the bustle of the citizens going about their day.%^RESET%^");

    set_items (([
      "fortress" : "%^BLUE%^Above the city looms the ever-present Shadovar fortress, casting the entire "
"area into a state of perpetual twilight.%^RESET%^",
      "buildings" : "%^RESET%^%^CYAN%^Most of the buildings in the bazaar look either very new, "
"or newly repaired. %^RESET%^%^MAGENTA%^Paint %^RESET%^%^CYAN%^is freshly applied and %^RESET%^%^YELLOW%^"
"fixtures %^RESET%^%^CYAN%^are gleaming. There are shops, inns, and various homes here.%^RESET%^",
      ({"ground","street","cobblestones"}) : "%^RESET%^%^ORANGE%^The streets here are carefully "
"laid cobblestone.%^RESET%^",
    ]));
}

void init() {
    ::init();
    if(!present("tharisambiancexxx",TP)) new(OBJ"ambiance")->move(TP);
}