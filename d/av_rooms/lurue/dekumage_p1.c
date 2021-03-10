// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("dekumage_p1");
    set_property("indoors",1);
    set_property("light",1);
    set_property("no teleport",1);
    set_terrain("wood building");
    set_travel("slick floor");
    set_climate("tropical");

    set_short("%^ORANGE%^A small cabin on a plantation%^RESET%^");

    set_long("%^RESET%^In better repair then you would have expected, this small hut appears to be lived in.  A %^RED%^mantle %^RESET%^hovers over a cleaned out fireplace with a neat stack of %^ORANGE%^logs %^RESET"
	"%^and %^ORANGE%^tinder %^RESET%^nearby.  Before this a table sits with four chairs around it.  A wooden %^CYAN%^partition%^RESET%^ separates a part of the cabin's space into a small bedroom where a th"
	"ick padded %^BOLD%^%^WHITE%^mattress%^RESET%^ and hand quilted %^RED%^bed throws %^RESET%^can be seen.  A few small %^ORANGE%^cupboards %^RESET%^store supplies and beside the door appears to be a set "
	"of %^BOLD%^%^BLACK%^riding equipment%^RESET%^."
	);

    set_smell("default","
The smell of wood polish mixes with leather.");
    set_listen("default","The cabin is quiet except for a few chirps of crickets.");

    
set_items(([ 
	({ "riding equipment", "equipment" }) : "%^BOLD%^%^BLACK%^There are some straps, a bridle and a pair of chaps hanging on a peg by the door.  It looks like the building's resident owns a horse and knows how to ride.%^RESET%^",
	({ "partition", "cupboards" }) : "%^ORANGE%^The partition and cupboards both appear to be made out of some type of oak wood.  They look strong and sturdy, and very well tended.%^RESET%^",
	({ "bed", "bedding", "throws" }) : "%^RED%^The bed looks soft and comfortable, as well as recently slept in.  Clearly someone still lives here.%^RESET%^",
	({ "mantle", "fireplace", "tinder", "logs", "wood" }) : "%^RED%^The fireplace is simple in design and appears to get a lot of use.  A neat pile of logs is stacked up beside it, along with a box of tinder to get the logs started.%^RESET%^",
	]));

    set_exits(([ 
		"east" : "/d/av_rooms/lurue/dekumage_g7",
	]));

}