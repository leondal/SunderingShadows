#include "../../undead.h"
inherit "/d/common/inherit/hitching_post";

void create() {
    ::create();
    set_light(2);
    set_indoors(0);
    set_terrain(CITY);
    set_travel(DIRT_ROAD);
    set_name("A small grassy yard");
    set_short("%^RESET%^%^GREEN%^A small grassy yard%^RESET%^");
    set_long("%^RESET%^%^GREEN%^A small grassy yard%^RESET%^\n"
"Behind the main stable building here is this fenced yard.  Covered in "
"%^GREEN%^short grass%^RESET%^, it contains perhaps the only greenery you've "
"seen within this entire town.  A few %^ORANGE%^horses %^RESET%^mill about, "
"given room here to exercise and feed, while others are tethered in half-"
"shelters near the fence.  Some of the horses seem fairly docile, but others "
"are fiery and obviously bred for %^RED%^combat %^RESET%^- it seems both common "
"soldiers and town visitors alike are able to use this yard.\n");
    set_smell("default","The thick scent of animals overwhelms everything else here.");
    set_listen("default","You hear the sounds of battle in the distance.");
    set_exits( ([
        "west":TOWN"stable"
    ]) );
}
