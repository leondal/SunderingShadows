#include "chaos.h"

inherit VAULT;

void create() {
    ::create();
    set_property("light", 2);
    set_property("indoors", 1);
    set_short("North room");
    set_long( 
	"This is a very well kept room. There is a desk in one corner of "
"the room, and a couch in another corner. The room looks out of place for "
"this tower. In the center of the room is a large glass case. There is an "
"eerie glow surrounding the case."
    );
    set_exits( ([
	"south" : CHAOSDIR+"floor9"
        ]) );
    set_door("north door",CHAOSDIR+"floor9","south",0);
    set_smell("default","There is a musky odor about the place.");
    set_listen("default","The sounds of silence numbs your ears.");
    set_items(( [
	"desk":"It is and old oak desk. Looks to be in perfect shape.",
	"couch":"A well made couch, looks to be made from some animal hide.",
        "black sword":"A bastard sword, with a black blade. It seems to call out to you.",
	"glow":"A magical glow."
    ] ));
}
void init(){
    ::init();
}
void reset(){
    ::reset();
	if(!present("glass case"))
	    new(MISCDIR+"chaos_case")->move(TO);
	if(!present("darkmage"))
		new(MONDIR+"darkmage")->move(TO);

}
