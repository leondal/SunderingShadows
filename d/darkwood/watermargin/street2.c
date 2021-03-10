//	A Village Street
//	Thorn@Shadowgate
//	11/15/94
//	Darkwood Forest Area
//	street2.c

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

	This is a side street in the village of Watermargin.  To the 
north of you, you notice a building where people are going out 
frequently with	new supplies and goods.  To the south of you
is another building, a bit less well, kept up.  The people leaving 
that building have no new goods, but either leave with some 
sort of item that looks used, or a fuller purse.  Looking to the
east of you, you see an intersection of streets in the center of
town.
	The side street continues to the west.
	
THORN
);
    set_exits( (["north" : "/d/darkwood/watermargin/supply_shop",
	             "south" : "/d/darkwood/watermargin/pawn_shop",
				 "east" : "/d/darkwood/watermargin/street3",
	             "west" : "/d/darkwood/watermargin/street1"]) );

}

