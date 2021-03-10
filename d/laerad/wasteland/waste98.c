#include <std.h>
inherit "/d/laerad/wsland";

void create(){
    ::create();
/*  set_long(
	"You are standing on a barren plain. The earth is cracked and dead. "+
	"No vegetation can be seen for miles. A wicked wind bites at your "+
	"face blowing sand into your eyes. The lifeless wasteland continues "+
	"to the west, the Gods Plains are to the east."
    );
*/
    set_exits( ([
	"west":"/d/laerad/wasteland/waste88",
	"east":"/d/laerad/plains/plains17",
	"north":"/d/laerad/wasteland/waste97",
	"south":"/d/laerad/plains/plains8"
    ]) );
}
/*
void reset(){
    ::reset();
    if(!present("hyena")){
	new("/d/laerad/mon/hyena")->move(this_object());
    }
}
*/
