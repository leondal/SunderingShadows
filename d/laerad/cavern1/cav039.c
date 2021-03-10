//Coded by Bane//
#include <std.h>
inherit "/d/laerad/cavern1/special/croom_cavern.c";
void create(){
    set_monsters( ({"/d/laerad/mon/vampill"}), ({2}) );
    ::create();
    set_repop(80);
    set_short("Laerad caverns");
    set_property("indoors",1);
    set_property("light",2);
    set_smell("default","The air is surprisingly clean and refreshing.");
    set_listen("default","You can hear the trickling of the stream.");
    set_exits( ([
	"northeast":"/d/laerad/cavern1/cav038",
	"northwest":"/d/laerad/cavern1/cav037",
	"southwest":"/d/laerad/cavern1/cav079",
	"north":"/d/laerad/cavern1/cav040"
    ]) );
}
void reset(){
    ::reset();
/* changing to be controlled by CROOM
    if(!present("vampire illithid")){
	new("/d/laerad/mon/vampill")->move(this_object());
	new("/d/laerad/mon/vampill")->move(this_object());
    }
*/
}
