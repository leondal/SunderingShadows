#include <std.h>
inherit ROOM;
void create(){
    ::create();
    set_name("Tharis caverns");
    set_short("A dark cavern");
    set_long(
	"You have entered a dark dreary cave. A few torches line the "+
	"walls illuminating the cavern. A lot of cobwebs clutter the "+
	"room, spiders occupy all of them."
    );
    set_property("indoors",1);
    set_property("light",2);
    set_property("no teleport",1);
    set_smell("default","The air remains stale and old in this part of the cave.");
    set_listen("default","Silence fills the room.");
    set_exits( ([
	"west":"/d/tharis/caverns/cavern6",
	"east":"/d/tharis/caverns/cavern25",
	"north":"/d/tharis/caverns/cavern26"
    ]) );
}
