#include <std.h>
inherit ROOM;
void create(){
    ::create();
    set_name("Tharis caverns");
    set_short("A dark cavern");
    set_long(
	"You have entered a dark and dreary cave. This cavern is lit "+
	"very well, many torches line its walls. Water covers the floor "+
	"of the room, it measures almost a foot deep."
    );
    set_property("indoors",1);
    set_property("light",2);
    set_property("no teleport",1);
    set_smell("default","An old swampy smell fills this cavern.");
    set_listen("default","Dripping water is heard throughout the cave.");
    set_exits( ([
	"south":"/d/tharis/caverns/cavern24",
	"north":"/d/tharis/caverns/cavern27",
	"west":"/d/tharis/caverns/cavern20"
    ]) );
}
