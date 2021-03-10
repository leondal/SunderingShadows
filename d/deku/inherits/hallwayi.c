#include <std.h>

inherit CROOM;

void create() {
    ::create();
    set_property("light",0);
    set_property("indoors",1);
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_name("Fortress hallway");
    set_short("%^BOLD%^%^WHITE%^Fortress hallway%^RESET%^");
    set_long("%^BOLD%^%^WHITE%^You find yourself in a wide "+
    "hallway made entirely from a strange %^RESET%^gray stone"+
    "%^BOLD%^%^WHITE%^.  The walls of the hall are obviously "+
    "thick and sturdy, appearing as if their construction was "+
    "completed only recently.  The floor of the hallway is "+
    "completely barren, free from even the smallest amount of "+
    "debris.  The ceiling hangs high overhead, completely "+
    "smooth from what you can determine.  The walls, ceiling, "+
    "and floor create the feeling that you are walking "+
    "in a stone box of sorts.  Only once that feeling becomes "+
    "apparent do you realize that a tangible %^BOLD%^%^BLACK%^"+
    "darkness%^BOLD%^%^WHITE%^ lingers here.%^RESET%^");
    
    set_smell("default","The smell of death hangs heavily in the "+
    "air and mixes with odor of unwashed living bodies.");
    
    set_listen("default","Strange sounds echo through the "+
    "fortress.");

    set_items(([
        ({"stone","gray stone"}) : "%^BOLD%^%^WHITE%^This strange "+
        "gray stone is hard to behold.  It is intense, reflecting "+
        "some apparent invisible light that makes looking at it "+
        "almost unbearable.  The entire fortress in which you now "+
        "stand is constructed from it.%^RESET%^",
        ({"darkness","tangible darkness"}) : "%^BOLD%^%^BLACK%^This "+
        "tangible darkness lingers in the fortress.  It is impossible "+
        "to determine from where it comes, yet it seems to seep "+
        "up from or out of everything here.%^RESET%^",
        ({"floor","clean floor","barren floor"}) : "The floor here "+
        "is barren of any debris, suggesting that something keeps "+
        "it meticulously clean.",
        ({"ceiling","smooth ceiling"}) : "The ceiling here hangs "+
        "high overhead and from what you can determine is "+
        "completely smooth.",
        ({"walls","smooth walls","stone walls"}) : "The walls of "+
        "the hallway are smooth and constructed from the strange "+
        "gray stone.  They appear sturdy and thick.",
        ({"stone box","box"}) : "Yes, you almost think that you "+
        "are traversing a large stone box.",
        ({"debris"}) : "There are none here that you can reckon."
    ] ));
    set_search("default","%^BOLD%^%^WHITE%^This place is definately "+
    "strange, but you find nothing that would provide a "+
    "viable hiding spot.%^RESET%^");
}
