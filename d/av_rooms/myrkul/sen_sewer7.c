// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("sen_sewer7");
    set_property("indoors",1);
    set_property("light",1);
    set_property("no teleport",1);
    set_terrain("built tunnel");
    set_travel("slick floor");
    set_climate("temperate");

    set_short("%^RESET%^%^ORANGE%^Old S%^GREEN%^e%^ORANGE%^wer Beneath %^BOLD%^%^CYAN%^S%^RESET%^%^CYAN%^e%^BOLD%^neca%^RESET%^");

    set_long("%^RESET%^%^ORANGE%^This is an older part of the sewer system where the canal is a bit narrower. There is an old drain in the ceiling of the sewer here. You think you must be below the old %^BOLD%^%^WH"
	"ITE%^c%^BLUE%^a%^WHITE%^t%^YELLOW%^h%^WHITE%^e%^BLUE%^d%^WHITE%^r%^YELLOW%^a%^WHITE%^l%^RESET%^%^ORANGE%^ now.%^RESET%^"
	);

    set_smell("default","
You smell the sewer still, but there's also the smell of sawdust now.");
    set_listen("default","You can hear the sounds of tinkering above you - things like hammers, mallets and saws.");

    
set_items(([ 
	"floor" : "There are walkways on the sides of the canal here. They are crumbling from old age and moisture.",
	"walktways" : "The walkways are corroded here and falling to pieces.",
	"ceiling" : "The ceiling has the drain in it, and is otherwise quite old as the rest of the sewer.",
	"drain" : "The drain is above the canal, but with some clever climbing, it can be gotten to.",
	"walls" : "The walls are old here, from when the aqueducts were first built.",
	"walkways" : "The walkways are corroded here and falling to pieces.",
	"canal" : "The canal is mostly empty here, and what water is there moves slowly.",
	]));

    set_exits(([ 
		"up" : "/d/attaya/newseneca/rooms/cath_workroom",
		"north" : "/d/av_rooms/myrkul/sen_sewer5",
	]));

}