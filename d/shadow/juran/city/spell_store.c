#include <std.h>
#include "../juran.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("%^BOLD%^%^WHITE%^Hetori's Spell Store%^RESET%^");
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_long(query_short() + "
%^MAGENTA%^Looking around, you can see the many duplicates of %^BOLD%^%^BLACK%^spells%^RESET%^%^MAGENTA%^ on the shelves that cover the walls. Two relatively weak %^BOLD%^%^BLACK%^demon%^RESET%^%^MAGENTA%^ familiars run about the room doing the ogre-mage's bidding. A stone archway lies on the %^ORANGE%^s%^ORANGE%^o%^BOLD%^%^BLACK%^u%^RESET%^%^ORANGE%^t%^BOLD%^%^BLACK%^h %^BLACK%^w%^RESET%^%^ORANGE%^a%^ORANGE%^l%^ORANGE%^l%^MAGENTA%^ allowing you to return to the staircase.
");
    set_items(([
                   ({ "spells", "scrolls", "walls", "shelves", "shelf", "wall" }) :
                   "On the walls, you see rows of shelves mounted from top " +
                   "to bottom.  Each shelf carries a full load of " +
                   "parchment, all with magical writing on them of some " +
                   "kind.  Hetori obviously has protective spells safe " +
                   "guarding his merchandise.",
                   ({ "demons", "demon", "familiar", "familiars" }) : "The demons move " +
                   "about with speed doing the ogre-mage's bidding, but they " +
                   "obviously do not like you looking at them.",
                   ({ "south wall", "south archway", "south", "empty room" }) :
                   "Through the archway on the south wall, you see what " +
                   "appears to be a relatively empty room containing " +
                   "the staircase used to move inside the mage tower."
                   ]));
    set_light(2);
    set_indoors(1);
//	set_property("no teleport", 1); //removed by Circe 6/18/08 after discussions with others
    set_smell("default", "You smell old, dusty parchment.");
    set_listen("default", "You hear the mumblings of familiars " +
               "working in the back of the store.");
    set_exits(([
                   "out" : JROOMS + "mt3",
               ]));
}
void reset()
{
    ::reset();
    if (!present("hetori")) {
        new(JMONS + "hetori")->move(TO);
    }
}
