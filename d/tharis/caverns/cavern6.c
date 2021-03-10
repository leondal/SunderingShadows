//Coded by Bane//
#include <std.h>
inherit ROOM;
void create(){
    ::create();
    set_name("Tharis caverns");
    set_short("A dark cavern");
    set_long(
	"You have entered a dark dreary cave. Bats swoop down through "+
	"the room right above your head. The entire cavern is bare other "+
	"than the torches that line the walls."
    );
    set_property("indoors",1);
    set_property("light",2);
    set_property("no teleport",1);
    set_smell("default","The air is thick and hard to breath.");
    set_listen("default","The screeching of bats echoes around the cave.");
    set_exits( ([
	"west":"/d/tharis/caverns/cavern3",
	"north":"/d/tharis/caverns/cavern19",
	"east":"/d/tharis/caverns/cavern20",
	"southeast":"/d/tharis/caverns/cavern21"
    ]) );
}
