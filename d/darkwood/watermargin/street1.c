//	A Village Street
//	Thorn@Shadowgate
//	11/15/94
//	Darkwood Forest Area
//	street1.c

#include <std.h>
#include <rooms.h>

inherit ROOM;

void create() {
    ::create();
    set_light(1);
    set_indoors(0);
    set_short("A Village Street");
	set_long(
@THORN

	This is the end of the small side street iin the middle of
the village.  To the north of you, you see a sign hanging 
above the door.  To the south is a building that could only be
the Watermargin Town Hall.  West of you is one of the two docks
of this village, where you can take a boat downriver to other 
places.
	The street continues to the east.
	
THORN
);
    set_exits( (["north" : "/d/darkwood/watermargin/doctor",
	             "south" : "/d/darkwood/watermargin/town_hall",
				 "east" : "/d/darkwood/watermargin/street2",
	             "west" : "/d/darkwood/watermargin/boathouse1"]) );

}

