//Coded by Bane//
#include <std.h>
inherit "/d/laerad/cavern1/special/cavern.c";
void create(){
    ::create();
    set_short("Laerad caverns");
    set_long(
	"You are standing in an underground cavern system.  A small stream "+
	"is running along one of the walls winding its way through the room.  "+
	"The ceiling is fairly low, only about 9 feet from the ground.  Lichen "+
	"and other assorted mosses cover about 90 percent of the walls, glowing "+
	"a strange fluorescent yellow and lighting up the area.  Stalagtites "+
	"and stalagmites litter the ceilings and floor."
	"\nTo the south are what appears to be animal pens."
    );
    set_property("indoors",1);
    set_property("light",2);
    set_smell("default","The air is surprisingly clean and refreshing.");
    set_listen("default","You can hear the trickling of the stream.");
    set_exits( ([
	"south":"/d/laerad/cavern1/cav096",
	"northeast":"/d/laerad/cavern1/cav115"
    ]) );
}
