//description changed 10/23/03 by Circe to show that the tunnel kept going
#include <std.h>
#include "../dragon.h";

inherit BSEWER;

void create() {
    ::create();
    set_property("light",-2);
    set_property("indoors",1);
    set_short("Sanctuary Sewers");
    set_long(
      "%^BOLD%^%^BLACK%^These are the disgusting sewers under the city of Sanctuary. They are"+
      " filled with many strange and ordinary objects. The dark walls are covered with disgusting slime mold"+
      " from the many decades of sewage that flowed within here."
/*The tunnel abluntly ends here. 
This was taken out to allow the tunnel to continue as the exits do.  Circe 10/23/03
*/
    );
    set_exits(([
        "south": SEWER+"sewer29",
        "north": SEWER+"sewer27"
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
   if(!present("quaggoth")) {
   new(MON+"quaggoth")->move(TO);
}
}
