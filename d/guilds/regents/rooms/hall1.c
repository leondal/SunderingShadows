#include <std.h>
inherit ROOM;

void create()
{
	::create();
   set_terrain(WOOD_BUILDING);
   set_travel(PAVED_ROAD);
	set_property("indoors",1);
	set_property("light",3);
	set_property("no sticks",1);
//	set_property("no teleport",1);
	set_short("A secret room in the theatre");
	set_long(
	"This is a secret room in the theatre of the Rhapsody Inn. To the east"+
	" is a fake wall. From the other side it looks real, but is basically"+
	" just an illusion. This room is fairly bare and small. The walls are"+
	" made of wood and have simply been varnished to help preserve them,"+
	" it is a refreshing change from all black. The floor is covered in a"+
	" thin green carpet that runs down a set of stairs into the basement."+
	" An oil lamp hangs from the ceiling, shedding light on the room."
	);
	set_smell("default","There is a musky smell to the room.");
	set_listen("default","The distant chatter of the inn's customers can"+
	" still be heard.");
	set_items(([
	({"floor","carpet","green carpet"}) : "%^GREEN%^The floor is covered"+
	" by a thin green carpet.",
	({"wall","walls"}) : "The walls are made of wood and have been varnished"+
	" to help preserve them. It is a refreshing change from all the black"+
	" of the backstage.",
	({"east wall","fake wall"}) : "The east wall is basically an illusion"+
	" and isn't really there at all. From the other side it looks real and"+
	" solid, but you can pass right through it without a problem.",
	"ceiling" : "An oil lamp hangs from the ceiling on an iron chain.",
	({"lamp","oil lamp"}) : "A simple oil lamp hangs from the ceiling, giving"+
	" light to the room.",
	({"chain","iron chain"}) : "The oil lamp hangs from the ceiling on an"+
	" iron chain.",
	"stairs" : "Stairs on the west lead down into the basement.", 
	]));
	set_exits(([
	"stairs" : "/d/guilds/regents/rooms/hall2.c",
	"east" : "/d/darkwood/room/backstage.c",
	]));
	set_pre_exit_functions(({"stairs","east"}),({"go_stairs","go_east"}));
}

int go_stairs()
{
	write("You descend into the basement.");
	return 1;
}

int go_east()
{
	write("You feel a tingle as you pass through the false wall.");
	return 1;
}
