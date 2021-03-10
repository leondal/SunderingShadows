#include <std.h>
inherit ROOM;
void create(){
    ::create();
    set_name("Tharis caverns");
    set_short("A dark cavern");
    set_long(
	"You have entered a dark and dreary cave. The floor seems to "+
	"descend a bit. Water covers the floor at almost half a foot deep. "+
	"Torches line the walls providing much needed light."
    );
    set_property("indoors",1);
    set_property("light",2);
    set_property("no teleport",1);
    set_smell("default","The cavern smells like a swamp.");
    set_listen("default","Rushing water can be heard from nearby caves.");
    set_exits( ([
	"south":"/d/tharis/caverns/cavern20",
	"east":"/d/tharis/caverns/cavern27"
    ]) );
}
