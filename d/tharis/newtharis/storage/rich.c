#include <std.h>
#include "../tharis.h"
inherit ROOM;

void create() {
    ::create();
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("indoors",0);
    set_property("light",1);
    set_name("Well tended avenue");
    set_short("%^RESET%^%^CYAN%^We%^WHITE%^l%^CYAN%^l tended a%^WHITE%^v%^CYAN%^enue%^RESET%^");
    set_long("%^RESET%^%^CYAN%^Drawing the eye before anything else here is the vast, looming bulk of "
"the hovering %^BLUE%^Shadovar %^CYAN%^fortress, far in the sky above. It casts the entire city under "
"a pall of unrelenting %^BOLD%^%^BLACK%^darkness%^RESET%^%^CYAN%^. Below, the normal bustle of the city "
"is just a memory in this well tended area. The roads here are made of %^WHITE%^fine gravel %^CYAN%^with "
"%^BOLD%^%^WHITE%^fitted marble slabs %^RESET%^%^CYAN%^on either side to form a sidewalk. "
"%^BOLD%^%^GREEN%^Pru%^RESET%^%^GREEN%^n%^BOLD%^%^GREEN%^ed trees %^RESET%^%^CYAN%^line the avenue at "
"regular intervals. On either side of the avenue are %^ORANGE%^sprawling villas%^CYAN%^, %^BOLD%^"
"%^CYAN%^mansions%^RESET%^%^CYAN%^, and %^BOLD%^%^WHITE%^grand estates%^RESET%^%^CYAN%^. Every residence "
"is protected by %^WHITE%^tall walls %^CYAN%^and heavily armed guards.");
    set_smell("default","%^RESET%^%^ORANGE%^The smell of gardens reaches you.%^RESET%^");
    set_listen("default","%^BLACK%^%^BOLD%^You hear birds.");
    set_items (([
      "fortress" : "%^BLUE%^Above the city looms the ever-present Shadovar fortress, casting the entire "
"area into a state of perpetual twilight.%^RESET%^",
      ({"road","street","avenue","avenues"}) : "%^RESET%^The road is a perfectly laid path of fine "
"gravel. The cost of maintaining such an avenue would be obscene.%^RESET%^",
      ({"buildings","villas","mansions","estates"}) : "%^RESET%^%^ORANGE%^The buildings here are "
"expensive opulant estates of the merchants, government, and local clergy members.%^RESET%^",
      "trees" : "%^RESET%^%^GREEN%^Well tended trees line the avenue. They have been carefully "
"pruned and are well cared for.%^RESET%^",
    ]));
}

void init() {
    ::init();
    if(!present("tharisambiancexxx",TP)) new(OBJ"ambiance")->move(TP);
}