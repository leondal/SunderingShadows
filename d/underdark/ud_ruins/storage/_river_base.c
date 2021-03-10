#include <std.h>
#include "../ud_ruins.h"

inherit CROOM;

void set_pop();

void create() {
    set_repop(30);
    set_pop();
    ::create();
    set_name("a wide subterranean river");
    set_property("indoors",1);
    set_property("light", 0);
    set_terrain(NAT_CAVE);
    set_travel(FRESH_BLAZE);
    set_property("no teleport", 1);
    set_short(
        "%^CYAN%^a wide %^BOLD%^%^BLUE%^subterranean "
        "%^RESET%^%^CYAN%^river%^WHITE%^"
    );
    set_long(
        "%^CYAN%^You are in the middle of a wide subterranean river. "
        "%^BOLD%^Cold water %^RESET%^%^CYAN%^rushes past you as it flows "
        "downstream to the south. The waters are relatively shallow, and, by "
        "the light of the "
        "%^MAGENTA%^fl%^BOLD%^o%^CYAN%^u%^MAGENTA%^r%^ORANGE%^e"
        "%^RESET%^%^MAGENTA%^s%^GREEN%^c%^BOLD%^e%^RESET%^%^GREEN%^n%^MAGENTA%^t "
        "m%^GREEN%^u%^BOLD%^%^MAGENTA%^s%^CYAN%^h%^MAGENTA%^r%^GREEN%^o"
        "%^MAGENTA%^o%^RESET%^%^GREEN%^m%^MAGENTA%^s %^CYAN%^growing on nearby "
        "outcroppings, you find you can navigate them with some care. You "
        "must remain wary of the numerous %^BOLD%^%^BLACK%^crevices "
        "%^RESET%^%^CYAN%^in the riverbed, however, which drop sharply into "
        "a seemingly %^BLUE%^bottomless abyss%^CYAN%^. All you can see to the "
        "west is a high rock cliff that rises up to meet the looming ceiling "
        "of the underdark, while to the east lies a shallower incline, with "
        "what looks like some manner of settlement atop its ridge."
    );
    set_smell("default", "A strange acrid stench wafts down from upstreram.");
    set_listen("default", "The thundrous current of the river rushes past you.");
    set_exits(([
    ]));
    set_items(([
        ({"river","water"}) :
            "%^CYAN%^The river is not any higher than two feet in most places, "
            "although its current is swift enough to knock one from their feet "
            "if they are uncareful. The water is almost clear, and glows an "
            "%^BOLD%^o%^RESET%^%^CYAN%^t%^BOLD%^%^GREEN%^h%^RESET%^%^CYAN%^e"
            "%^BOLD%^r%^GREEN%^w%^CYAN%^o%^RESET%^%^CYAN%^r%^BOLD%^%^GREEN%^l"
            "%^RESET%^%^CYAN%^d%^GREEN%^l%^BOLD%^%^CYAN%^y "
            "b%^RESET%^%^GREEN%^l%^BOLD%^u%^CYAN%^e %^RESET%^%^CYAN%^in the "
            "light of the surrounding mushrooms.",
        "mushrooms" :
            "%^CYAN%^These strange-looking mushrooms provide most of the "
            "natural light in this area. They cling to the wet rocks of the "
            "riverbed, and grow upward several feet into the air with a "
            "%^BOLD%^%^WHITE%^long white stalk%^RESET%^%^CYAN%^. Each has a "
            "bulbous, spherical cap, its color either a "
            "%^MAGENTA%^f%^BOLD%^l%^RESET%^%^MAGENTA%^u%^BOLD%^%^CYAN%^o"
            "%^RESET%^%^MAGENTA%^r%^BOLD%^%^WHITE%^e%^RESET%^%^MAGENTA%^s"
            "%^BOLD%^%^CYAN%^c%^RESET%^%^MAGENTA%^e%^CYAN%^n%^MAGENTA%^t "
            "%^BOLD%^%^CYAN%^blue %^RESET%^%^CYAN%^or %^BOLD%^%^MAGENTA%^pink "
            "%^RESET%^%^CYAN%^in color. Each of them as bright as a torch, they "
            "cast the area in a strange, foreign light.",
        ({"crevices","crevice","abyss"}) :
            "%^BOLD%^%^BLACK%^Precarious drops into what seem like a "
            "bottomless abyss are found in the stone riverbed, and falling "
            "into them does not seem like a good idea. From time to time, it "
            "looks like there might be small figures swimming about within the "
            "depths of these cracks, but it is difficult to tell for sure.",
        "cliff" :
            "%^BOLD%^%^BLACK%^The cliff wall to the west is made up of jagged "
            "rock, and much of the bottom half is covered in slippery "
            "vegetation, making climbing it impossible. Even were one to manage "
            "it, the wall rises up to meet with the cavern ceiling, and there "
            "looks to be nothing of interest above.",
        ({"settlement","village"}) :
            "%^BOLD%^%^BLACK%^You can't see much of it from this vantage, but "
            "to the east, just over a low, rocky ridge, lies what appears to "
            "be a small settlement of sorts.",
        ]));
}

void set_pop() {
    //Occasional random kuo-toa.
    if(!random(5)) {
        set_monsters(({MON"kuo_toa"}),({random((2) + 1)}));
    }
}
