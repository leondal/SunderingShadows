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
      " filled with many strange objects. The tunnel stretches toward the east"+ 
      " and toward the west. The dark walls are covered with disgusting slime"+
      " mold from the many decades of sewage that flowed within here."
    );
    set_exits(([
       "east" : SEWER+"sewer13",
       "west" : SEWER+"sewer15"
    ] ));
    set_items(([
       "sewers":"The disgusting tunnels of waste under Sanctuary."
    ] ));
}
