#include <std.h>
inherit "/d/deku/open/dforest2i";

void create() {
    ::create();
    set_property("light",1);
    set_short("Road to Verbobone");
    set_terrain(SHORE);
    set_long(
@KAYLA
%^ORANGE%^A footpath joins a horrifying shoreline here.  Looking at the 
forest from afar, you notice it is quite bleak.  The gloomy clouds
seem to hover over both the forest and this wicked sea.  Dark green 
waves wash upon the shore, leaving dead and decaying creatures upon 
its blackish sand.  To the east is a large decaying dock.
KAYLA
    );
    set_smell("default","There is an overwhelming stench of rot and decay.");
    set_exits(([
      "west" : "/d/deku/open/dforest9",
      "dock" : "/d/shadow/virtual/sea/deku.dock"
    ] ));
    set_items(([
      "sea":"The sea is a darkish green color.  Dead creaturs floot upon\n"+
            "its murky waters.  You notice that, far out upon the water, \n"+
            "a thick grayish fog that you cannot see through.",
      "shore":"The sand of the shore is black.  It runs as far as the eyes can see."
    ] ));
}

