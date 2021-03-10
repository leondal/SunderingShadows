#include <std.h>
inherit ROOM;
void create(){
    ::create();
    set_name("Tharis caverns");
    set_short("A dark cavern");
    set_long(
	"You have entered a dark and dreary cave. Dirt and debris lie "+
	"scattered across the room. A strange blue moss covers the walls. "+
	"A few torches can be seen buried in the moss on the walls. Only "+
	"one remains lit."
    );
    set_property("light",2);
    set_property("indoors",1);
    set_property("no teleport",1);
    set_smell("default","A strange odor fills this cavern.");
    set_listen("default","Dead silence.");
    set_items( ([
	({"moss"}):"This strange blue moss covers the entire cavern. It seems to shift and move on the walls, making the room seem alive..."
    ]) );
    set_exits( ([
	"northwest":"/d/tharis/caverns/cavern6",
	"south":"/d/tharis/caverns/cavern23",
	"east":"/d/tharis/caverns/cavern24"
    ]) );
}
