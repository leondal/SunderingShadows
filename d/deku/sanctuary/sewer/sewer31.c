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
      " filled with many strange objects. The tunnel branches here, it continues"+
      " to the east, south and west. The dark walls are covered with disgusting"+
      " slime mold from the many decades of sewage that remain here."
    );
    set_property("no teleport", 1);
    set_exits(([
       "north" : SEWER+"sewer29",
       "south" : SEWER+"sewer33",
       "west" : SEWER+"sewer32"
    ] ));
    set_smell("default","There is a overwhelming smell of humans and demi-humans waste.");
    set_items(([
       "sewers":"The disgusting tunnels of waste under Sanctuary."
    ] ));
}
