#include <std.h>
inherit ROOM;
void create(){
    ::create();
    set_name("Tharis caverns");
    set_short("A dark cavern");
    set_long(
	"The slope of this cave seems to descend just slightly. A small "+
	"stream runs through a crack in the wall into the western room. "+
	"A torch burns low on the wall casting ominous shadows across the room."
    );
    set_property("indoors",1);
    set_property("light",2);
    set_property("no teleport",1);
    set_smell("default","The air smells a little cleaner here.");
    set_listen("default","The sound of water trickling through the room can be heard.");
    set_items( ([
	({"stream"}):"The stream runs from a crack in the southern wall. It travels through the room into the western exit from the cave."
    ]) );
    set_exits( ([
	"east":"/d/tharis/caverns/cavern3",
	"north":"/d/tharis/caverns/cavern16",
	"west":"/d/tharis/caverns/cavern15"
    ]) );
}
