// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("sen_oldsewer3");
    set_property("indoors",1);
    set_property("light",0);
    set_property("no teleport",1);
    set_terrain("built tunnel");
    set_travel("slick floor");
    set_climate("temperate");

    set_short("%^RESET%^%^ORANGE%^Old S%^GREEN%^e%^ORANGE%^wer Beneath %^BOLD%^%^CYAN%^S%^RESET%^%^CYAN%^e%^BOLD%^neca%^RESET%^");

    set_long("%^BOLD%^%^BLACK%^This is an ancient aqueduct system left over from the old city. The air is tight here, and the walls feel very close in. Water no longer flows here as the new sewers have blocked off "
	"the old construction. Bricks block the canal in either direction. The dust is thick with age. %^BOLD%^%^WHITE%^A %^MAGENTA%^g%^CYAN%^r%^MAGENTA%^i%^CYAN%^n%^MAGENTA%^n%^CYAN%^i%^MAGENTA%^n%^CYAN%^g%^W"
	"HITE%^ skeleton stares at you, slumped against the wall facing you with a giant spearhead stuck between its ribs.%^RESET%^"
	);

    set_smell("default","
You air is not as stale here. You smell fresher air nearby.");
    set_listen("default","The familiar sound of rats scratching echos from somewhere in the darkness.");

    set_search("floor","You see tracks leading to the east wall and the south wall.");
    set_search("skeleton","The skeleton bears the marks of the guards of Seneca. Clearly it has been left as a warning.");
    set_search("south wall","There is a gap in the bricks here, and you think you can go <south> by squeezing through the gap.");
    set_search("ceiling","The ceiling is made of old bricks.");
    set_search("bricks","The bricks are shrouded in darkness and the sturdy looking construction might be deceiving.");
    set_search("walls","The bricks are shrouded in darkness and the sturdy looking construction might be deceiving.");
    set_search("east wall","There is a gap in the bricks here, and you think you can go <east> by squeezing through the gap.");
    
set_items(([ 
	"floor" : "The floors are covered in dust.",
	"skeleton" : "The skeleton has been arranged so that it is giving you the bird. Whoever did this clearly has no respect for the dead.",
	"ceiling" : "The ceiling is made of old bricks.",
	"bricks" : "The bricks are new construction and look quite sturdy.",
	"walls" : "The bricks are new construction compared to the walls and they block the channel leaving this part of the sewer entombed.",
	]));

    set_exits(([ 
		"south" : "/d/av_rooms/myrkul/sen_oldsewer6",
		"east" : "/d/av_rooms/myrkul/sen_oldsewer1",
	]));



    set_invis_exits(({ "east", "south" }));

}