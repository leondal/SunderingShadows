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
	"west":"/d/laerad/wasteland/waste54",
	"east":"/d/laerad/plains/plains1",
	"north":"/d/laerad/wasteland/waste65",
	"south":"/d/laerad/wasteland/waste67"
    ]) );
}

/*
void reset(){
    ::reset();
   if(!present("runner")){
	new("/d/laerad/mon/runner")->move(this_object());
    }
}
*/
