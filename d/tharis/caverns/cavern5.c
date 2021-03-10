//Coded by Bane//
#include <std.h>
inherit ROOM;
void create(){
    ::create();
    set_name("Tharis caverns");
    set_short("A dark cavern");
    set_long(
	"You stand in a dark dreary cave. Some bones lie on the floor "+
	"against one of the walls. Rats scuttle underneath searching "+
	"for some scraps of food. Torches line the walls providing the "+
	"light in the room."
    );
    set_property("indoors",1);
    set_property("light",2);
    set_property("no teleport",1);
    set_listen("default","The sound of rats running around the room is all that can be heard.");
    set_smell("default","A horrible odor fills the air.");
    set_items( ([
	({"bones"}):"These old bones are piled up against a wall. Rats search through them looking for something to eat."
    ]) );
    set_exits( ([
	"south":"/d/tharis/caverns/cavern3",
	"north":"/d/tharis/caverns/cavern10"
    ]) );
}
