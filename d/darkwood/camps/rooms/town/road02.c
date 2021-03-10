#include <std.h>
#include "../../elfisland1.h";
inherit BTOWN;

void create() {
   ::create();
   set("long",
      "%^RESET%^%^GREEN%^The path here heads west to the village and east into a very large tree. There is"+
      " a staircase that spirals up around the tree heading into the heights of the massive oak. The stairs"+
      " don't appear to have been added to the tree, but grown out of the tree along with plain looking smooth"+
      " railing to hold onto. When you look up you can see a platform protruding from the tree facing the east."
   );
   set_items( ([
      "tree":"This is the furthest occupied tree to the east by far. There are stairs leading up the tree.",
   ]) );
   set_exits( ([
      "west" : TOWN+"road01",
      "stairs" : TOWN+"ghouse",
   ]) );
}
