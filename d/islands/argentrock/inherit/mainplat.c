#include <std.h>
#include "../argabbr.h"
inherit INH+"outdoors";

void create(){
    set_monsters(({MON+"refugee",MON+"ambusher"}),({random(3),random(2)}));
    ::create();
    set_long((:TO,"long_desc":));
    set_items(([
        ({"platform","branch","floor","space","open space"}):
            "%^ORANGE%^Numerous large branches emerge from the tree and form the "
            "floor of the platform along with other branches of nearby "
            "trees.%^RESET%^",

        ({"trunk","tree","trees"}):
            "%^ORANGE%^You cannot identify what kind of trees these are. They "
            "are like nothing you have ever seen before, with a diameter "
            "of at least twenty feet and a %^RESET%^cool gray color%^ORANGE%^ with "
            "smooth bark.%^RESET%^",
    ]));
}

string long_desc(){
    return
        "%^BOLD%^%^GREEN%^A hidden platform in the trees of Argentrock Forest%^RESET%^\n"
        "%^ORANGE%^You are standing on an enormous platform high up in the %^GREEN%^trees%^ORANGE%^. "
        "Emerging proudly from the trunk of the great tree are %^RED%^numerous%^ORANGE%^ "
        "large branches that intertwine and seem to have %^GREEN%^grown%^ORANGE%^ level "
        "with the branches of other nearby %^GREEN%^trees%^ORANGE%^. The branches spread "
        "in all directions for %^CYAN%^hundreds%^ORANGE%^ of feet, creating a vast open "
        "space in the canopy of the forest. ";
}
