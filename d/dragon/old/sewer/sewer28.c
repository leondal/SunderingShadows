#include <std.h>
#include <objects.h>

inherit ROOM;

void create() {
    room::create();
    set_property("light",-2);
    set_property("indoors",1);
    set_short("Sanctuary Sewers");
    set_long("%^RED%^%^BOLD%^
These are the disgusting sewers under the city of Sanctuary.  They are
filled with many strange and ordinary objects.  The tunnel abluntly
ends here.  The dark walls are covered with disgusting slime mold 
from the many decades of sewage that flowed within here.
    ");
    set_exits(([
        "south":"/d/dragon/sewer/sewer29"
    ] ));
    set_items(([
       "sewers":"The disgusting tunnels of waste under Sanctuary."
    ] ));
    set_search("default","You manage to search the walls and find some interesting marks.");
    set_post_exit_functions(({"south"}),({"go_south"}));
    set_smell("default","The reeking smell of waste is becoming overwhelming.");
    set_property("no teleport", 1);
}

int go_south() {
  if(avatarp(TP)) return 1;
  say(TP->query_cap_name()+" enters trough a imaginary wall.");
  return 1;
}
