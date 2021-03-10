// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("tomb2");
    set_property("indoors",1);
    set_property("light",-1);
    set_property("no teleport",1);
    set_terrain("built cave");
    set_travel("slick floor");
    set_climate("mountain");

    set_short("%^RESET%^%^CYAN%^Tomb of the Long Winter%^RESET%^");

    set_long("%^RESET%^%^CYAN%^You have entered a place forgotten by time.  The decor suggests this is a tomb of some kind, but glacial ice has invaded, locking the old architecture in a frozen state.  Rough stones"
	" compose the floor and walls, with pillars supporting the short vaulted ceiling.  Above, sculpted images of %^RESET%^devils%^CYAN%^ watch over the dead. In the far reach of the room, an impressive scu"
	"lpted platform hosts a large %^BLUE%^sarcophagus%^CYAN%^.  Sconces and candlesticks lie dormant.  Piles of frozen %^BLUE%^fl%^MAGENTA%^ow%^BOLD%^er%^RED%^s%^RESET%^%^CYAN%^ and other offerings rest un"
	"disturbed before the sarcophagus.  A dull chill hangs loosely in the air.%^RESET%^"
	);

    set_smell("default","
%^GREEN%^You smell the sterile ice.");
    set_listen("default","%^ORANGE%^You hear very little here.");

    
set_items(([ 
	"coffin" : "%^BLUE%^The large stone coffin sits on top of a short marble platform.  It stands almost four feet in height and made of very strong stone.  The sarcophagus is topped with a decorative carving of a powerful figure in archaic armor, clutching a sword to his heart.  Hishelmed face is open insofar as it looks like a skull staring upwards.  The whole casing is covered in a thin layer of ice.",
	"flowers" : "%^BOLD%^%^MAGENTA%^Old, somewhat rotten flowers lie in a heap near the sarcophagus as offerings.  Most of them are not recognizable, but are locked in a frozen, thorny mass.%^RESET%^",
	"devils" : "Devilish gargoyles are carved into the supports for the vaulted ceiling.  They seem to be standing vigil over the sarcophagus.",
	"sarcophagus" : "%^BLUE%^The large stone coffin sits on top of a short marble platform.  It stands almost four feet in height and made of very strong stone.  The sarcophagus is topped with a decorative carving of a powerful figure in archaic armor, clutching a sword to his heart.  Hishelmed face is open insofar as it looks like a skull staring upwards.  The whole casing is covered in a thin layer of ice.",
	]));

    set_exits(([ 
		"south" : "/d/av_rooms/tiamat/tomb1",
	]));

}