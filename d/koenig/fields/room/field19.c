//field19.c - Circe 11/9/03 - new description based on the ritual performed by the Lathanderites.  Will change again
#include <std.h>
#include "../../koenig.h"

inherit FIELDS;

void create() {
    ::create();
    set_long( ::query_long()+"A fence blocks your passage east.  Just to the "+
       "the south, you can see a clearing where a tree is growing.");
    add_item("fence","The ancient wooden fence is bleached nearly white and covered "+
       "with patches of moss.  From here, you can see five fence posts that seem "+
       "to have strange carvings.");
    add_item("posts","Weathered symbols have been etched into the gnarled wood.  "+
       "The symbols look very old.  The first is that of a sunburst, while on the "+
       "second post there is a symbol that looks sort of like a horse's head.  The "+
       "third post bears an oak leaf.  The fourth has a worn triangle shape.  On "+
       "the fifth post two symbols have been carved, that of a waterfall with "+
       "something surrounding it, though that has faded in time, and a teardrop shape.");
    add_item("clearing","To the south, a ring of ground has been left unsown.  No "+
       "corn grows there, but a pleasant patch of grass surrounds a tree.");
    add_item("tree","The tree growing to the south is small and seems to be "+
       "some sort of fruit tree.");
    set_exits(([
       "south" : KFIELD"field20",
       "north" : KFIELD"field18",
       "west" : KFIELD"field14",
    ] ));
}

void init() {
  ::init();
}

void reset() {
  ::reset();
}