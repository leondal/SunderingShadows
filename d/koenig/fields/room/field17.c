//field17.c - Circe 11/9/03 - changed to reflect Lathandrite ceremony.  Will change again.
#include <std.h>
#include "../../koenig.h"

inherit FIELDS;

void create() {
    ::create();
    set_long( ::query_long()+"A fence blocks your passage east.");
    add_item("fence","The ancient wooden fence is bleached nearly white and covered "+
       "with patches of moss.  From here, you can see five fence posts that seem "+
       "to have strange carvings.");
    add_item("posts","Weathered symbols have been etched into the gnarled wood.  "+
       "The symbols look very old.  The first is that of a sunburst, while on the "+
       "second post there is a symbol that looks sort of like a horse's head.  The "+
       "third post bears an oak leaf.  The fourth has a worn triangle shape.  On "+
       "the fifth post two symbols have been carved, that of a waterfall with "+
       "something surrounding it, though that has faded in time, and a teardrop shape.");
    set_exits(([
       "south" : KFIELD"field18",
       "north" : KFIELD"field16",
       "west" : KFIELD"field12",
    ] ));
}

void init() {
  ::init();
}

void reset() {
  ::reset();
}