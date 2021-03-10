#include <std.h>
inherit ROOM;
void create(){
    ::create();
    set_name("Tharis caverns");
    set_short("A dark cavern");
    set_long(
	"You are standing in a dark dreary cave. Skeletons of many "+
	"different creatures cover the floor of the room. Perhaps you "+
	"shouldnt be here..."
    );
    set_property("indoors",1);
    set_property("light",2);
    set_property("no teleport",1);
    set_smell("default","The room smells like decaying flesh.");
    set_listen("default","A loud thumping sound echoes off of the walls.");
    set_items( ([
	({"skeletons"}):"These skeletons have been torn apart and picked clean. It looks as if these poor creatures ran into some truly terrible monster."
    ]) );
    set_exits( ([
	"south":"/d/tharis/caverns/cavern10",
	"northeast":"/d/tharis/caverns/cavern12",
	"east":"/d/tharis/caverns/cavern13"
    ]) );
}
