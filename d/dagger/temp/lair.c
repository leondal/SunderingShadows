#include <std.h>
inherit ROOM;

void create()
{
	::create();
	set_property("indoors",3);
	set_property("light",3);
	set_short("Dragon's Lair");
	set_long(
	"You are in a cave in the side of a mountain. It is very"+
	" high up and a dragon has apparently made this spot his"+
	" lair. The walls of the cave have been melted by fiery"+
	" breath to make them smooth and comfortable for the dragon"+
	" to reside. Judging from the size of the cave, this must"+
	" be a very large beast. You wouldn't want to tackle with"+
	" this creature. Perhaps you should turn back and head for"+
	" safety while you still can."
	);
	set_smell("default",
	"There is a slight scent of smoke that hangs in the air.");
	set_listen("default",
	"You think you can hear the breathing of the great dragon.");
    set_exits( ([
      "up" : "/d/dagger/temp/tun5.c",
    ]) );
}
 
