//Coded by Bane//
#include <std.h>
inherit "/d/laerad/cavern1/special/croom_cavern.c";
void create(){
    set_monsters( ({"/d/laerad/mon/illithid2"}), ({1}) );
    ::create();
    set_repop(80);
    set_short("Laerad caverns");
    set_short("Laerad caverns");
    set_property("indoors",1);
    set_property("light",2);
    set_smell("default","The air is surprisingly clean and refreshing.");
    set_listen("default","You can hear the trickling of the stream.");
    set_exits( ([
	"north":"/d/laerad/cavern1/cav075",
	"northwest":"/d/laerad/cavern1/cav076",
	"southwest":"/d/laerad/cavern1/cav074",
	"southeast":"/d/laerad/cavern1/cav072"
    ]) );
}
void reset(){
    ::reset();
/* changing to use CROOM
    if(!present("illithid")){
	new("/d/laerad/mon/illithid2")->move(this_object());
    }
*/
}
