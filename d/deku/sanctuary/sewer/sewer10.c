#include <std.h>
#include "../dragon.h";

inherit BSEWER;

void create() {
    ::create();
    set_property("light",0);
    set_property("indoors",1);
    set_short("Sanctuary Sewers");
    set_long(
      "%^BOLD%^%^BLACK%^These are the disgusting sewers under the city of Sanctuary. They are"+
      " filled with many strange objects. The tunnel bends here toward the"+
      " west and continues back to the north. The dark walls are covered with"+
      " disgusting slime mold from the many decades of sewage that has"+
      " flowed through theses dark tunnels."
    );
    set_exits(([
       "north" : SEWER+"sewer09",
       "west" : SEWER+"sewer11"
    ] ));
    set_items(([
       "sewers":"The disgusting tunnels of waste under Sanctuary."
    ] ));
}
