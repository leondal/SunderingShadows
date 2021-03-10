// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("crypt_clinic");
    set_property("indoors",1);
    set_property("light",0);
    set_property("no teleport",1);
    set_terrain("ruins");
    set_travel("decayed floor");
    set_climate("temperate");

    set_short("%^BOLD%^%^BLACK%^Z%^RED%^o%^BLACK%^mb%^RED%^i%^BLACK%^e C%^RED%^l%^BLACK%^in%^RED%^i%^BLACK%^c%^RESET%^");

    set_long("%^BOLD%^%^BLACK%^The fist thing you notice is the floor, slick with %^RED%^blood%^BLACK%^ and the piles of rotting %^GREEN%^c%^RED%^h%^GREEN%^o%^RED%^p%^GREEN%^p%^RED%^e%^GREEN%^d%^BLACK%^ bodies stac"
	"ked to the ceiling. In the center of the room, a rough table stained with g%^GREEN%^o%^BLACK%^re is the only uncluttered surface. A dismal lantern %^YELLOW%^lights%^BLACK%^ the c%^RED%^a%^BLACK%^rnage"
	", revealing a staircase on the south side of the room and dark hallways on the east and west walls.%^BLACK%^"
	);

    set_smell("default","
It reeks of death and decay.");
    set_listen("default","Drip, drip, dripping echos through the room as blood pools underneath the table.");

    set_search("bodies","%^CYAN%^You find nothing in the rotted remains. Oddly though, there's no fresh bodies to chop. You wonder if you might have been next slated for the table??%^RESET%^");
    set_search("table","%^CYAN%^You find nothing on the table besides the cleaver. Oddly though, there's no fresh bodies to chop. You wonder if you might have been next slated for the table??%^RESET%^");
    set_search("carnage","%^CYAN%^You find nothing in the rotted remains. Oddly though, there's no fresh bodies to chop. You wonder if you might have been next slated for the table??%^RESET%^");
    set_search("piles","%^CYAN%^You find nothing in the rotted remains. Oddly though, there's no fresh bodies to chop. You wonder if you might have been next slated for the table??%^RESET%^");
    
set_items(([ 
	({ "body", "bodies" }) : "%^BOLD%^%^BLACK%^These bodies have been %^GREEN%^c%^RED%^h%^GREEN%^o%^RED%^p%^GREEN%^p%^RED%^e%^GREEN%^d%^BLACK%^ to pieces, sorted, and stacked in a %^RED%^macabre%^BLACK%^ scene that reminds you a smith's pile of %^MAGENTA%^unused parts.%^RESET%^",
	({ "lamp", "lantern", "light" }) : "%^BOLD%^%^BLACK%^The lantern sways back and forth slowly, casting a %^YELLOW%^g%^BLACK%^r%^YELLOW%^i%^BLACK%^t%^YELLOW%^t%^BLACK%^y %^WHITE%^l%^YELLOW%^i%^WHITE%^g%^YELLOW%^h%^WHITE%^t%^BLACK%^ across the g%^RESET%^%^MAGENTA%^l%^BOLD%^%^BLACK%^oom.%^RESET%^",
	"table" : "%^BOLD%^%^BLACK%^Heavy grooves mar the heavy %^RESET%^%^ORANGE%^oak table%^BOLD%^%^BLACK%^ from heavy chopping. A mighty %^RED%^meat cleaver%^BLACK%^ is stuck to the surface, and while the table is currently free of %^GREEN%^human debris%^BLACK%^, it is deeply stained with %^RED%^blood.%^RESET%^",
	"blood" : "%^RED%^Sticky pools of blood coat the floor, making it %^CYAN%^slick.%^RESET%^",
	"carnage" : "%^RED%^Human wreckage is spread across the room, abhorrent to any with a conscience.%^RESET%^",
	"piles" : "%^CYAN%^Neatly stacked by part: heads, arms, legs, torsos.%^RESET%^",
	]));

    set_exits(([ 
		"west" : "/d/av_rooms/myrkul/crypt_hall_west1",
		"down" : "/d/av_rooms/myrkul/crypt_stair",
		"east" : "/d/av_rooms/myrkul/crypt_hall_east1",
	]));

}