//Coded by Bane//
#include <std.h>
inherit "/d/laerad/cavern1/special/croom_cavern.c";

void create(){
   set_monsters( ({"/d/laerad/mon/illithid"}), ({1}) );
    ::create();
    set_short("Laerad caverns");
    set_property("indoors",1);
    set_property("light",2);
    set_smell("default","The air is surprisingly clean and refreshing.");
    set_listen("default","You can hear the trickling of the stream.");
    set_exits( ([
	"northeast":"/d/laerad/cavern1/cav033",
	"southwest":"/d/laerad/cavern1/cav036",
	"southeast":"/d/laerad/cavern1/cav035"
    ]) );
}
void reset(){
    ::reset();
/* changed to be controlled by CROOM
    if(!present("illithid")){
	new("/d/laerad/mon/illithid")->move(this_object());
    }
*/
}
