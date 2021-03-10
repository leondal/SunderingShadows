//Coded by Bane//
#include <std.h>
inherit ROOM;
void create(){
    ::create();
    set_name("Tharis caverns");
    set_short("A dark cavern");
    set_long(
	"You have walked into a dead end cave. The area is well lit and "+
	"littered with garbage and other trinkets. A large nest sits "+
	"against the northern wall filled with rather large eggs."
    );
    set_smell("default","A musty smell fills the room.");
    set_listen("default","The dripping of water can be heard from other caverns.");
    set_property("light",2);
    set_property("indoors",1);
    set_property("no teleport",1);
    set_exits( ([
    	"south":"/d/tharis/caverns/cavern28"
    ]) );
}
void reset(){
    ::reset();
    if(!present("dragonnel")){
	new("/d/tharis/caverns/mon/dragonnel")->move(this_object());
    }
}
