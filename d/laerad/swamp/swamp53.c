//Coded by Bane//
#include <std.h>
inherit "/d/laerad/swamp/special/base.c";
void create(){
    ::create();
    set_short("Swamp of the Dead");
    set("day long",
	"You have stumbled into the dreaded swamp of the dead.  You are "+
	"knee deep in water and have trouble walking through the mud.  Insects "+
	"are swarming around you constantly, biting and scratching at your face.  "+
	"Dead trees poke out of the water along with an uncountable number of lily "+
	"pads, and other assorted swamp brush."
    );
    set("night long",
	"You have walked into a very dark and dreary swamp.  The moon shines "+
	"brightly in the midnight sky.  An erie fog drifts across the surface of the "+
	"water.  The place looks so alive you wonder if you should stand around "+
	"for very long."
    );
    set_property("indoors",0);
    set_property("light",2);
    set_smell("default","The marsh gas is turning your stomach.");
    set_listen("default","The swamp is alive with the many sounds of insects and other creatures.");
    set_exits( ([
	"northwest":"/d/laerad/swamp/swamp46",
	"northeast":"/d/laerad/swamp/swamp47",
	"southwest":"/d/laerad/swamp/swamp60",
	"east":"/d/laerad/swamp/swamp54"
    ]) );
}
void reset(){
    ::reset();
    if(!present("beast")){
	if(random(5) < 2){
	    new("/d/laerad/mon/undead_beast")->move(this_object());
	}
    }
    if(!present("wight")){
	new("/d/laerad/mon/wight")->move(this_object());
    }
}
