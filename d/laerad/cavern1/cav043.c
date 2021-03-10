//Coded by Bane//
#include <std.h>
inherit "/d/laerad/cavern1/special/cavern.c";
void create(){
    ::create();
    set_short("Laerad caverns");
    set_property("indoors",1);
    set_property("light",2);
    set_smell("default","The air is surprisingly clean and refreshing.");
    set_listen("default","You can hear the trickling of the stream.");
    set_exits( ([
	"northwest":"/d/laerad/cavern1/cav042",
	"south":"/d/laerad/cavern1/cav044",
	"northeast":"/d/laerad/cavern1/cav025"
    ]) );
}
