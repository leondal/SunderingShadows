#include <std.h>
#include "graveyard.h"
inherit VAULT;

void create() {
    ::create();
    set_property("light",1);
    set_property("indoors",0);
    set_terrain(LIGHT_FOREST);
    set_travel(FOOT_PATH);
    set_name("road to graveyard");
    set_short("%^BOLD%^%^BLACK%^Road to the graveyard%^RESET%^");
    set_long("%^BOLD%^%^WHITE%^This dirt road has branched out from "+
    "the thick %^RESET%^%^GREEN%^trees%^BOLD%^%^WHITE%^ of the "+
    "%^RESET%^%^GREEN%^shadowlord forest%^BOLD%^%^WHITE%^ "+
    "to the east.  The %^RESET%^%^GREEN%^thick trees%^BOLD%^%^WHITE%^ "+
    "of the forest have given away to %^RED%^saplings%^BOLD%^"+
    "%^WHITE%^, who, like their kin in the forest, are in varying "+
    "stages of dying.  The %^MAGENTA%^road%^BOLD%^%^WHITE%^ itself "+
    "is packed down and cracked in some places from use.  "+
    "You guess that the use is not all "+
    "that frequent though as %^RESET%^%^GREEN%^"+
    "grass%^BOLD%^%^WHITE%^ has grown up in thick clumps in some "+
    "places.  Driftly from the %^RESET%^%^GREEN%^forest"+
    "%^BOLD%^%^WHITE%^ and shrouding the entire area is a thick "+
    "%^BOLD%^%^BLACK%^dark fog%^BOLD%^%^WHITE%^.%^RESET%^");

    set_items(([
    ({"fog","thick fog","dark fog"}) : "%^BOLD%^%^BLACK%^This "+
    "thick and dark mist shrouds the trail here, making it "+
    "difficult to see more than a few feet ahead in any direction.  "+
    "A cold chill runs down your spine as it contacts your flesh."+
    "%^RESET%^",
    ({"trees","thick trees"}) : "%^GREEN%^These thicks trees are "+
    "far to the east in the shadowlord forest.  Even from here "+
    "it is apparent that they are all dead or dying.%^RESET%^",
    ({"saplings","dead saplings"}) : "%^GREEN%^The trees here "+
    "have given away to smaller saplings.  You realize how "+
    "strange it is that saplings would grow here, as they, "+
    "like their kin in the forest, are either dead or dying.%^RESET%^",
    ({"forest","shadowlord forest"}) : "%^GREEN%^The forest "+
    "lies to the east and provides this trail with a "+
    "thick layer of dark fog.  Silence reaches you from it and "+
    "you easily recognize that all the trees that grow there have "+
    "either died or are in the process of dying.%^RESET%^",
    ({"grass","thick grass"}) : "%^GREEN%^This grass grows up from "+
    "the trail you are traveling on in thick clumps.  It, like the "+
    "saplings nearby, is dead or in the process of dying.%^RESET%^",
    ({"road","cracked road","packed road"}) : "%^MAGENTA%^The road "+
    "you are traveling on is made from packed dirt, suggesting that "+
    "it has saw an amount of use.  The dirt has cracked open and "+
    "grass grows up in thick clumps out of it.  You think that the "+
    "use of this road probably isn't too frequent.%^RESET%^",
    ]));
    set_search("default","There is nothing here that really "+
    "draws your attention.");

    set_smell("default","The air here reeks with a strong odor of death and decay.");
    set_listen("default","An ominous silence lingers here.");
  
}
