//Coded by Bane//
#include <std.h>
inherit ROOM;
void create(){
    ::create();
    set_name("Tharis caverns");

    set_short("A dark cavern");
    set_long(
	"You are standing in a dark underground cavern. The room is "+
	"rather small, a single torch lights the area. Dirt and rubble "+
	"cover the floor, apparently there was some sort of collapse "+
	"recently up above. A skeleton lies on the floor in the corner "+
	"of the room."
    );
    set_property("light",2);
    set_property("indoors",1);
    set_property("no teleport",1);
    set_listen("default","An eerie silence fills the room.");
    set_smell("default","A musky old smell travels through the cave.");
    set_items( ([
	({"skeleton"}):"The skeleton is still wearing its armor, although it has rusted to the point of being totally useless. A shield that lies at its side bears an insignia of a bear standing up on two legs."
    ]) );
    set_exits( ([
	"up":"/d/tharis/caverns/cavern1",
	"north":"/d/tharis/caverns/cavern3",
	"south":"/d/tharis/caverns/cavern4"
    ]) );
}
