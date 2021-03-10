//Coded by Bane//
#include <std.h>
inherit "/d/laerad/cavern1/special/croom_cavern.c";

void create(){
   set_monsters( ({"/d/laerad/mon/beholder"}), ({1}) );
    ::create();
   set_repop(75);
    set_short("Laerad caverns");
    set_property("indoors",1);
    set_property("light",2);
    set_smell("default","The air is surprisingly clean and refreshing.");
    set_listen("default","You can hear the trickling of the stream.");
    set_exits( ([
	"east":"/d/laerad/cavern1/cav063",
	"northwest":"/d/laerad/cavern1/cav065",
	"southwest":"/d/laerad/cavern1/cav066"
    ]) );
}
void reset(){
    ::reset();
/* changed to use CROOM
    if(!present("beholder")){
	new("/d/laerad/mon/beholder")->move(this_object());
    }
*/
}
