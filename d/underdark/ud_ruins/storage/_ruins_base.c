#include <std.h>
#include "../ud_ruins.h"

inherit CROOM;

void set_pop();

void create() {
    set_repop(30);
    set_pop();
    ::create();
    set_name("a forgotten underground village");
    set_property("indoors",1);
    set_property("light", 0);
    set_terrain(SHALLOW_WATER);
    set_travel(FRESH_BLAZE);
    set_property("no teleport", 1);
    set_short(
        "%^CYAN%^a %^BOLD%^%^BLACK%^forgotten "
        "%^RESET%^%^CYAN%^underground village%^WHITE%^"
    );
    set_long(
        "%^BOLD%^%^BLACK%^All around you are the ruins of what used to be a "
        "small, underground village. Dilapitated, half-collapsed "
        "%^RESET%^%^CYAN%^buildings %^BOLD%^%^BLACK%^line the road, their "
        "entrances long since buried under centuries of %^RESET%^%^ORANGE%^rot "
        "%^BOLD%^%^BLACK%^and %^ORANGE%^fungus%^BLACK%^. Against the rocky "
        "cavern floor, it is difficult to pick out which parts of it were meant "
        "to be roads, but you are able to keep your orientation by means of many "
        "%^RESET%^%^CYAN%^stone markers %^BOLD%^%^BLACK%^that seem to have "
        "survived the village's destruction, jutting out at intersections."
        "%^RESET%^"
    );
    set_smell("default", "The smell of fungus is potent.");
    set_listen("default", "You can hear strange shufflings from behind the ruin walls.");
    set_exits(([
    ]));
    set_items(([
        ({"buildings","village","huts","houses"}) :
            "%^CYAN%^The structures lining the streets are mostly simple huts, "
            "though some larger and more elaborate buildings are interspersed. "
            "Most are built with entrances and windows quite low to the ground, "
            "such that a human would have to stoop in order to enter them. "
            "Though there looks to be a foundation of stone at the base of many "
            "buildings, the primary building material seems to have been a kind "
            "of dense, "
            "%^BOLD%^b%^RESET%^l%^BOLD%^u%^RESET%^i%^BOLD%^%^CYAN%^sh-wh"
            "%^RESET%^i%^BOLD%^t%^CYAN%^e "
            "f%^RESET%^u%^BOLD%^%^CYAN%^n%^WHITE%^g%^RESET%^u%^BOLD%^%^CYAN%^s"
            "%^RESET%^%^CYAN%^, split into long planks and nailed into place.",
        ({"road","floor","ground","roads"}) :
            "%^CYAN%^Though it is difficult to make out after centuries of "
            "disuse, stretches of the cavern floor have been cleared of their "
            "jagged outcroppings and smoothed over, forming a road that makes "
            "walking about the village easier than in the rest of the cavern.",
        ({"markers","stone markers"}) :
            "%^BOLD%^%^BLACK%^Throughout the village, the only things that seem "
            "to have survived its fall entirely intact are the stone markers "
            "jutting out of the cavern floor at the corners of every "
            "intersection. Most are a little over three feet tall, and have "
            "short pieces of %^RESET%^gnomish script %^BOLD%^%^BLACK%^inscribed "
            "into its sides, each no more than fifty characters in length. Each "
            "marker seems to designate the name of its corresponding street.",
        ({"rot","fungus"}) :
            "%^MAGENTA%^The village has become entirely overgrown by the "
            "%^CYAN%^lu%^BOLD%^m%^WHITE%^i%^RESET%^n%^BOLD%^e%^RESET%^s"
            "%^BOLD%^c%^CYAN%^e%^RESET%^%^CYAN%^nt %^MAGENTA%^fungi that grows "
            "amongst the entirety of this cavern. It smells strongly of "
            "%^ORANGE%^rot %^MAGENTA%^and impedes movement at times, but the "
            "constant glow it gives off serves to light the entire area.",
        ]));
}

void set_pop() {
    // Hook horrors (groups of 6-10, every 3-4 rooms.)
    // No spawns in ruins_17
    if(base_name(TO) == ROOMS"ruins/ruins_17") { return; }
    if(!random(3)) {
        set_monsters(({MON"hook_horror"}),({6+random(5)}));
    }
}
