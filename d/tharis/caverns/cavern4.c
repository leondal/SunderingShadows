//Coded by Bane//
#include <std.h>
inherit ROOM;
void create(){
    ::create();
    set_name("Tharis caverns");
    set_short("A dark cavern");
    set_long(
	"You stand in a dark dreary cave. Torches hang from the walls "+
	"lighting up the room. Cobwebs hang in the corners. Dirt and "+
	"rocks cover the floor."
    );
    set_property("light",2);
    set_property("indoors",1);
    set_property("no teleport",1);
    set_smell("default","The air smells musty.");
    set_listen("default","The scuttling of feet come from all around.");
    set_exits( ([
	"south":"/d/tharis/caverns/cavern8",

	"east":"/d/tharis/caverns/cavern9",
	"north":"/d/tharis/caverns/cavern2"
    ]) );
}
void reset(){
    ::reset();
    if(!present("umber hulk")){
	new("/d/tharis/caverns/mon/umber_hulk")->move(this_object());
    }
}
