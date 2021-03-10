//Coded by Bane//
#include <std.h>
inherit "/d/laerad/cavern1/special/croom_cavern.c";

void create(){
    set_monsters( ({"/d/laerad/mon/illithid2"}), ({1}) );
    ::create();
    set_repop(50);
    set_short("Laerad caverns");
    set_property("indoors",1);
    set_property("light",2);
    set_smell("default","The air is surprisingly clean and refreshing.");
    set_listen("default","You can hear the trickling of the stream.");
    set_exits( ([
	"northwest":"/d/laerad/cavern1/cav030",
	"southwest":"/d/laerad/cavern1/cav023",
	"northeast":"/d/laerad/cavern1/cav020"
    ]) );
}
void reset(){
    ::reset();
/* changing to use CROOM controls
    if(!present("illithid")){
	new("/d/laerad/mon/illithid2")->move(this_object());
    }
*/
}
