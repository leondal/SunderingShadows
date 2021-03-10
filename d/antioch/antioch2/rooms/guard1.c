#include <std.h>
#include "../antioch.h"
inherit ROOM;

void create()
{
	::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
	set_property("indoors",1);
	set_property("light",2);
	set_property("no sticks",1);
	set_short("Guard Post");
	set_long(
	"The room is mostly empty. There are a flight of stairs spiraling upwards"+
	" on the western wall. There is a small wooden table with a sign-in book"+
	" on it and a feather quill. A bottle of ink is also on the table to"+
	" refill the quill with, along with a thick candle that is helping to"+
	" light the room. The guards are supposed to sign in and out here, marking"+
	" the times for their captain to check. To the south a thick %^MAGENTA%^purple%^RESET%^"+
	" curtain hangs over the doorway."
	);
	set_smell("default","The bitter smell of ink permeats the room.");
	set_listen("default","You can hear the faint crackling of the candle flame.");
	set_items(([
	({"stairs","flight of stairs"}) : "A flight of stairs begins on the"+
	" western wall and spirals up to the top of the tower.",
	({"table","wooden table","small table","small wooden table"}) : "A small"+
	" wooden table is on the eastern side of the room. It holds the sign-in"+
	" book for the guards, along with a feather quill, ink bottle, and candle.",
	({"book","sign-in book"}) : "A large leather bound book is on the table."+
	" It has neat lines drawn through the pages for the guards to print their"+
	" name on, and the time they sign in and out. The date is written on the"+
	" top of each page. This way the captain can keep better track of the"+
	" guards.",
	({"quill","feather quill"}) : "A large feather quill sits on top of the"+
	" table and is used by the guards to sign in and out with.",
	({"bottle","ink bottle"}) : "A small glass bottle of ink sits on the"+
	" table. There is a cork on it so that the ink does not dry out.",
	({"candle","thick candle"}) : "%^BOLD%^A thick white candle sits on top"+
	" of the small table. It is in a pewter candle holder in the shape of a"+
	" circle. It is burning very slowly and gives a fair amount of light to"+
	" the room.",
	({"holder","pewter holder","pewter candle holder","candle holder"}) : "A"+
	" circular pewter candle holder keeps the large candle upright and catches"+
	" the wax instead of allowing it to fall onto the desk.",
	"floor" : "The floor is made of dun colored bricks and looks to have"+
	" been swept recently, probably by the palace servants.",
	"ceiling" : "The ceiling is flat and unremarkable.",
	({"curtain","purple curtain"}) : "%^MAGENTA%^A thick purple curtain hangs"+
	" down from the southern doorway, keeping this room seperate from the"+
	" hallway.",
	]));
	set_exits(([
	"up" : ROOMS+"palace1",
	"south" : ROOMS+"pal4",
	]));
	set_pre_exit_functions(({"south"}),({"GoThroughDoor"}));
}

int GoThroughDoor()
{
	write("You brush aside the curtain as you pass through the door.");
	return 1;
}
