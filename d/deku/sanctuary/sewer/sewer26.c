#include <std.h>
#include "../dragon.h";

inherit BSEWER;


void create() {
    ::create();
    set_property("light",-1);
    set_property("indoors",1);
    set_short("Sanctuary Sewers");
    set_long(
      "%^BOLD%^%^BLACK%^These are the disgusting sewers under the city of Sanctuary. They are"+
      " filled with many strange but interesting objects. The tunnel abluntly"+
      " ends here. The walls are dark and covered with disgusting slime mold"+
      " from the many decades of sewage that flowed within here."
    );
    set_exits(([
       "east" : SEWER+"sewer27",
       "west" : SEWER+"sewer25"
    ] ));
    set_items(([
       "sewers":"The disgusting tunnels of waste under Sanctuary.",
    ] ));
    set_search("default","%^RESET%^%^GREEN%^You search the nasty human waste and find a small lever within the west wall.");
    set_property("no teleport", 1);
    set_property("no castle", 1);
    set_smell("default","The smell of human and demi-human waste is becoming overwhelming.");
}
