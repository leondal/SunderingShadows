//Circe 11/5/03 - commented out the lever until/unless something is added to stop bug reports about it
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
      " filled with many strange but interesting objects. The tunnel comes to a bend "+
      "here. The walls are dark and covered with disgusting slime mold"+
      " from the many decades of sewage that flowed within here."
    );
    set_exits(([
       "west" : SEWER+"sewer26",
       "south" : SEWER+"sewer28"
    ] ));
    set_items(([
       "sewers":"The disgusting tunnels of waste under Sanctuary."
    ] ));
/*
    set_search("default","%^RESET%^%^GREEN%^You search the nasty human waste and find a small lever within the south wall.");
*/
    set_property("no teleport", 1);
    set_property("no castle", 1);
    set_smell("default","The smell of human and demi-human waste is becoming overwhelming.");
}
