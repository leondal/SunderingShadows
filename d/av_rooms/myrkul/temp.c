// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("temp");
    set_property("indoors",1);
    set_property("light",1);
    set_property("no teleport",1);
    set_terrain("stone building");
    set_travel("slick floor");
    set_climate("temperate");

    set_short("%^YELLOW%^Secluded Strongpoint%^RESET%^");

    set_long("%^BOLD%^%^CYAN%^You stand in a stone hut that has been %^GREEN%^camouflaged%^CYAN%^ with brush to hide it from view of the road. Inside is a kitchen with a %^RED%^fireplace%^CYAN%^ over which a huge %"
	"^BLACK%^iron pot%^CYAN%^ hangs. A rack of many obscure weapons hangs on the wall: %^WHITE%^katanas, %^YELLOW%^no-dachi's%^RED%^, and naginatas%^CYAN%^. Cots line the walls, and a large table with a si"
	"ngle lamp is covered with many maps. A large chest with an iron lock sits at the rear of the hut.%^RESET%^ "
	);

    set_smell("default","
It smells of day old soup and polish.");
    set_listen("default","Muffled sounds from the road occasionally can be heard.");

    
set_items(([ 
	({ "fireplace", "pot" }) : "It looks like someone cooked here recently. There are burnt pieces of wood and ash that seems to be kind of warm still.",
	({ "weapons", "weapon", "katanas", "no-dachi", "no-dachi's", "no-dachis", "naginata", "naginatas" }) : "The weapons look in fairly good repair, although none look spectacular. They are, however, not common in Daggerdale.",
	"chest" : "The lock on it seems impressive, and due to its enormous size, it is doubtful that anyone could move it without a wagon.",
	"cots" : "Theres enough cots here to represent a significant force, possibly fifty in all.",
	]));

    set_exits(([ 
		"out" : "/d/dagger/road/road38",
	]));

}