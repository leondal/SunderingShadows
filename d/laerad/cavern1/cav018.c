//Coded by Bane//
#include <std.h>

inherit "/d/laerad/cavern1/special/croom_cavern.c";

void create(){
    ::create();
   set_repop(50);
   set_monsters( ({"/d/laerad/mon/illithid"}), ({1}) );
    set_short("Laerad caverns");
    set_property("indoors",1);
    set_property("light",2);
    set_smell("default","The air is surprisingly clean and refreshing.");
    set_listen("default","You can hear the trickling of the stream.");
    set_exits( ([
	"southwest":"/d/laerad/cavern1/cav017",
	"south":"/d/laerad/cavern1/cav019"
    ]) );
}

void reset(){
    ::reset();
/* changed to use CROOM
    if(!present("illithid")){
	new("/d/laerad/mon/illithid")->move(this_object());
    }
*/
}
