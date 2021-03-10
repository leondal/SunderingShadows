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
	" on the western wall. There is a small wooden table with a log book"+
	" on it and a feather quill. A bottle of ink is also on the table to"+
	" refill the quill with, along with a thick candle that is helping to"+
	" light the room. The guards are supposed to come here and make note of"+
	" any events out of the ordinary that happen during their watch. Each"+
	" guard is supposed to come here and read the log book at the beginning"+
	" of their watch to get caught up on what's going on, and the captain also"+
	" reviews it frequently. To the south is a doorway that a thick %^MAGENTA%^purple%^RESET%^"+
	" curtain hangs from, cutting this room off from the other."
	);
	set_smell("default","The bitter smell of ink permeats the room.");
	set_listen("default","You can hear the faint crackling of the candle flame.");
	set_items(([
	({"stairs","flight of stairs"}) : "A flight of stairs begins on the"+
	" western wall and spirals up to the top of the tower.",
	({"table","wooden table","small table","small wooden table"}) : "A small"+
	" wooden table is on the eastern side of the room. It holds the log"+
	" book for the guards, along with a feather quill, ink bottle, and candle.",
	({"book","log book"}) : "A large leather bound book is on the table."+
	" It is full of logs from guards, though it is mostly empty. It seems"+
	" as though Antioch is relatively quiet.",
	({"quill","feather quill"}) : "A large feather quill sits on top of the"+
	" table and is used by the guards to write their logs with.",
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
	"up" : ROOMS+"palace5",
	"south" : ROOMS+"pal2",
	]));
	set_pre_exit_functions(({"south"}),({"GoThroughDoor"}));
}

int GoThroughDoor()
{
	write("You brush aside the curtain as you pass through the door.");
	return 1;
}
