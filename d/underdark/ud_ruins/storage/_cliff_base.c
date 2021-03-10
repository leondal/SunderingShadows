#include <std.h>
#include "../ud_ruins.h"
inherit ROOM;

void create() {
    ::create();
    set_name("before a cliffside shrine");
    set_property("indoors",1);
    set_property("light", 0);
    set_terrain(NAT_CAVE);
    set_travel(FRESH_BLAZE);
    set_property("no teleport", 1);
    set_short(
        "%^BOLD%^%^BLACK%^before a %^WHITE%^cliffside %^BLACK%^shrine%^RESET%^"
    );
    set_long(
        "%^BOLD%^%^BLACK%^You are upon the crest of what looks to be the "
        "highest point of this underground cavern. To the west, you can see the "
        "whole of a tiny %^RESET%^%^CYAN%^village %^BOLD%^%^BLACK%^upon a "
        "plateau, and the narrow path leading away from it and down to the river. "
        "Nearby, just to the west of you, a %^RESET%^%^ORANGE%^modest shrine "
        "%^BOLD%^%^BLACK%^has been built from loosely-cobbled stones taken from the "
        "cliffside, which looks to have seen a great deal of damage.%^RESET%^"
    );
    set_smell("default", "The air smells of earth and ash.");
    set_listen("default", "The hollow cavern winds whip past you.");
    set_exits(([
    ]));
    set_items(([
        "shrine" :
            "%^ORANGE%^This %^BOLD%^shrine %^RESET%^%^ORANGE%^seems to have "
            "been a point of pride amongst the inhabitants of whatever lived "
            "here, as it is easily the most elaborate and permanently-constructed "
            "building in the entire building. Even so, it is of decidedly modest "
            "craftsmanship, seemingly "
            "c%^CYAN%^o%^ORANGE%^b%^BOLD%^%^BLACK%^b%^RESET%^%^ORANGE%^l%^GREEN%^"
            "e%^ORANGE%^d together from whatever stones could be taken from "
            "nearby. Much of the shrine lies in a state of ruin that not even the "
            "passage of time can account for. Walls and roofing are collapsed in "
            "many places, and even the sturdier central walls are "
            "%^BOLD%^%^BLACK%^s%^RESET%^%^RED%^c%^BOLD%^%^BLACK%^o%^RED%^r"
            "%^BLACK%^c%^RESET%^%^RED%^h%^BOLD%^e%^BLACK%^d %^RESET%^%^ORANGE%^and "
            "%^WHITE%^f%^BOLD%^ra%^RESET%^ct%^BOLD%^u%^BLACK%^r%^WHITE%^e"
            "%^RESET%^d%^ORANGE%^, though it is unclear what might have caused this "
            "damage.%^WHITE%^",
        "village" :
            "%^CYAN%^From up here, you have an unobstructed view of the village "
            "below you. Although it consists of no more than a hundred "
            "buildings, most of them small huts, it appears that it had been "
            "inhabited for quite a long time before its downfall, with "
            "%^BOLD%^%^BLACK%^s%^RESET%^m%^BOLD%^%^BLACK%^o%^RESET%^o"
            "%^BOLD%^%^BLACK%^t%^RESET%^he%^BOLD%^%^BLACK%^d "
            "r%^RESET%^o%^BOLD%^%^BLACK%^a%^RESET%^d%^BOLD%^%^BLACK%^s "
            "%^RESET%^%^CYAN%^and well-worn %^WHITE%^s%^ORANGE%^i%^WHITE%^de "
            "p%^ORANGE%^a%^WHITE%^t%^ORANGE%^h%^WHITE%^s %^CYAN%^criss-crossing "
            "the area. Looking over the entirety of it at once, it is clear that the "
            "village was the victim of some %^BOLD%^%^RED%^attack "
            "%^RESET%^%^CYAN%^or %^RED%^raid%^CYAN%^, with many of the buildings "
            "on the outskirts collapsed or razed to the ground. A similar trail of "
            "destruction leads all the way to the base of the trail leading up "
            "to this shrine.%^WHITE%^",
        ]));
}
