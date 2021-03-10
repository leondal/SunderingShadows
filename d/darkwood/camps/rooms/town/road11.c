#include <std.h>
#include "../../elfisland1.h";
inherit BTOWN;

void create() {
   ::create();
   set("long",
      "%^RESET%^%^GREEN%^The already wide path breaks out even further to accomodate the tree here. This tree"+
      " has one doorway and it is rather small. On the door to the tree there is a small sign that protrudes from"+
      " the door itself. Several windows are set around the tree to let as much light as"+
      " possible inside. To the south of the tree is a large garden bed that only grows white roses. There is a"+
      " small set of stones lined up around the garden bed to keep people from accidentally stepping inside."+
      " On the opposite side of the entrance to the tree, there is a small area with outdoor tables and chairs"+
      " for those whom wish to sit outside."
   );
   set_items( ([
      "sign":"The sign reads: %^RESET%^%^ORANGE%^The cafe.%^RESET%^" 
   ]) );
   set_exits( ([
      "enter" : TOWN+"cafe",
      "northeast" : TOWN+"road10",
   ]) );
}
