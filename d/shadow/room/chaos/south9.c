#include "chaos.h"
inherit VAULT;

void create() {
    ::create();
    set_property("light", 2);
    set_property("indoors", 1);
    set_short("South room");
    set_long( 
	"This is a very clean room. There is a desk in one corner of "
"the room. The room looks out of place for this tower. In the center "
"of the room is a large glass case. There is a glow surrounding the case."
    );
    set_exits( ([
	"north" : CHAOSDIR+"floor9"
        ]) );
    set_door("south door",CHAOSDIR+"floor9","north",0);
    set_smell("default","There is an odor of fresh wood about the place.");
    set_listen("default","The sounds of dripping water fills your ears.");

    set_items(( [
	"desk":"It is and old oak desk. Looks to be in perfect shape.",
        "staff":"A quarter staff. There are runes carved into the wood.",
	"glow":"A magical glow."
    ] ));
}
void init(){
    ::init();
}

void reset(){
    ::reset();
	if(!present("case"))
	    new(MISCDIR+"serpent_case")->move(TO);
	if(!present("mage"))
		new(MONDIR+"serpentmage")->move(TO);

}
