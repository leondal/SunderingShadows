//Top of platform -- Yves
#include <std.h>
#include "../argabbr.h"
inherit INH+"outdoors.c";

void create(){
    ::create();
    set_long((:TO,"long_desc":));
    set_items(([
        ({"platform","branch","floor"}): 
            "%^ORANGE%^Numerous branches emerge from the tree and form the "
            "floor of the platform.%^RESET%^",
        
        ({"trunk","tree"}): 
            "%^ORANGE%^You cannot identify what kind of tree this is. It is "
            "like nothing you have ever seen before, with a diameter "
            "of at least twenty feet, though peaking here, and a %^RESET%^cool "
            "gray color%^ORANGE%^ with smooth bark.%^RESET%^",
        
        ({"branches","canopy","below"}): 
            "%^ORANGE%^Thick, stout branches are %^GREEN%^growing%^ORANGE%^ from the trunk at evenly "
            "spaced intervals encircling the tree at a forty-five "
            "degree angle. They esentially form %^GREEN%^living%^ORANGE%^ steps "
            "to descend to the platforms below.%^RESET%^",
        
        ({"ocean","view","forest"}): 
            "The vast %^GREEN%^forest%^RESET%^ streches for %^RED%^miles%^RESET%^ all around and you "
            "can barely see the %^ORANGE%^dock%^RESET%^ to the northeast "
            "against the backdrop of the vast %^BLUE%^ocean%^RESET%^.",
    ]));
    set_exits(([
        "down" : PATH+"platform23",
    ]));
}

string long_desc(){
    return
        "%^BOLD%^%^GREEN%^A hidden platform in the trees of Argentrock Forest%^RESET%^\n"
        "%^ORANGE%^You are standing on a small platform very high up in the %^GREEN%^trees.%^ORANGE%^ "
        "Emerging from the trunk of the great tree are %^RED%^numerous%^ORANGE%^ branches "
        "that intertwine and seem to have %^GREEN%^grown%^ORANGE%^ for the very purpose of "
        "being a floor. The canopy breaks open here offering a "
        "spectacular %^BOLD%^%^WHITE%^view%^RESET%^%^ORANGE%^ of the %^BLUE%^ocean%^ORANGE%^ and surrounding %^GREEN%^forest%^ORANGE%^ "
        "and you can make out the dock far off to the northeast. Several "
        "smaller branches sprout from the trunk and form steps to the "
        "platforms %^GREEN%^below%^ORANGE%^.%^RESET%^";
}
