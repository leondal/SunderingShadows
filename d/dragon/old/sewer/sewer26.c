#include <std.h>
#include <objects.h>

inherit ROOM;

void create() {
    room::create();
    set_property("light",-1);
    set_property("indoors",1);
    set_short("Sanctuary Sewers");
    set_long("%^RED%^%^BOLD%^
These are the disgusting sewers under the city of Sanctuary.  They are
filled with many strange and ordinary objects.  The tunnel bluntly
ends here.  The dark walls are covered with disgusting slime mold 
from the many decades of sewage that flowed within here.
    ");
    set_exits(([
      "east":"/d/dragon/sewer/sewer27"
    ] ));
    set_items(([
       "sewers":"The disgusting tunnels of waste under Sanctuary."
    ] ));
    set_search("default","You manage to search the walls and find some interesting marks.");
    set_smell("default","The reeking smell of waste is becoming overwhelming.");
    set_property("no teleport", 1);
}

void reset() {
  ::reset();
  if(!present("neo-otyugh")) {
    new("/d/dragon/mon/neo")->move(this_object());
  }
}
