//placed in /d/antioch/village/snakes.c (on qdemon.c) for quest
inherit "/std/Object";
#include "/d/antioch/areadefs.h"
#include <std.h>
void create() {
     ::create();
set_name("a demonic element");
set_id( ({"a demonic element", "demonic element", "element"}) );
set_short("A demonic element");
set_long(
"\n"
"The element seems to vanish in your hand.\n");
set_weight(5);
}

void init(){
  ::init();
  if(interactive(ETO)&&base_name(environment(ETO))=="/d/antioch/castle/snakes")
    ETP->add_exit(CASTLE+"castle12","out");
}
