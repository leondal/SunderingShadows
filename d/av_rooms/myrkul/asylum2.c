// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("asylum2");
    set_property("indoors",1);
    set_property("light",1);
    set_property("no teleport",1);
    set_terrain("stone building");
    set_travel("paved road");
    set_climate("temperate");

    set_short("%^BOLD%^%^WHITE%^P%^RESET%^a%^BOLD%^d%^RESET%^d%^BOLD%^%^WHITE%^e%^RESET%^d%^BOLD%^%^CYAN%^ C%^RESET%^%^CYAN%^e%^BOLD%^l%^RESET%^%^CYAN%^l%^RESET%^");

    set_long("You are surround by %^BOLD%^%^BLACK%^four %^WHITE%^padded%^BLACK%^ walls.%^RESET%^ There is %^GREEN%^urine%^RESET%^ on the floor and the only other dash of color are the deep %^RED%^red stains%^RESET%"
	"^ that can be faintly seen in the fabric of the padding on the walls. The ceiling has the same terrible paster. This room once had a %^CYAN%^door%^RESET%^ with a slot in it for food. That door now lie"
	"s ripped off its hinges lying haphazardly on the floor. The room is full of %^CYAN%^sorrow%^RESET%^ and its weight hangs on your %^BOLD%^%^CYAN%^soul%^RESET%^ like a %^RESET%^%^ORANGE%^stone%^RESET%^,"
	" its crushing embrace unhinging your %^GREEN%^mind.%^RESET%^"
	);

    set_smell("default","
You smell urine, blood, and mildew.");
    set_listen("default","Muffled by the padding, you can still hear the hideous cries and sobbing.");


    set_exits(([ 
		"north" : "/d/av_rooms/myrkul/asylum1",
	]));

}