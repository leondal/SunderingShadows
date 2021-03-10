#include <std.h>
inherit ROOM;
void create(){
    ::create();
   set_terrain(BARREN);
   set_travel(DIRT_ROAD);
   set_property("no teleport",1);
    set_name("Nevermore road");
    set_short("Nevermore road");
    set_long(
	"A huge mountain stands before you, its shadow cast over you like "+
	"a blanket of evil. The clouds above fly past at an alarming rate. "+
	"Lightning fills the sky, the wind whips past you. A dark cave is "+
	"embedded into the mountain. A sign hangs from the top of the cave."
    );
    set_items( ([ ({"sign"}):"Be careful brave adventurer! These caves are very dangerous, many have not returned from them alive." ]) );
    set_property("light",2);
    set_property("indoors",0);
    set_property("no teleport",1);
    set_smell("default","The smell of smoke seems to come from the cave.");
    set_listen("default","The crash of thunder and the whipping of the wind assaults your senses.");
    set_exits( ([
	"north":"/d/tharis/road/sroad5",
//	"cave":"/d/tharis/caverns/cavern1"
    ]) );
}
