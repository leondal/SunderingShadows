// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("dekumage_m1");
    set_property("indoors",1);
    set_property("light",0);
    set_property("no teleport",1);
    set_terrain("wood building");
    set_travel("stairway");
    set_climate("tropical");

    set_short("%^BOLD%^%^WHITE%^An old porch%^RESET%^");

    set_long("%^RESET%^A large porch extends across the front of the manor house and at one time provided a comfortable place to sit and lounge while enjoying the afternoon or evening.  Hints of the chairs that use"
	"d to line this wide, wooden deck, can still be seen in the %^CYAN%^moss covered%^RESET%^ piles of %^ORANGE%^lumber %^RESET%^that lay about.  Above, casting shade down upon the squalor is a wood and sl"
	"ate roof, fancifully decorated along the edges with a %^BOLD%^%^WHITE%^lattice work %^RESET%^design. A grand looking doorway prevents entry into the house and a set of stairs lead down into an over ru"
	"n yard with a pond.%^RESET%^"
	);

    set_smell("default","
The smell of mold is heavy in the air.");
    set_listen("default","You can hear the drone of insects all about you.");

    
set_items(([ 
	({ "lumber", "wood", "piles" }) : "%^RESET%^%^ORANGE%^Looking closely, you think those might once have been wooden chairs, and that one over there may have been a table.  How nice it must have once been to sit out here on the deck and enjoy a sunset.%^RESET%^",
	({ "moss", "mold", "ruin" }) : "%^BOLD%^%^GREEN%^You look over the mold and moss and wonder how long it will be before the swamp reclaims the entire building.%^RESET%^",
	]));

    set_exits(([ 
		"west" : "/d/av_rooms/lurue/dekumage_g5",
		"east" : "/d/av_rooms/lurue/dekumage_m2",
	]));

    set_door("entry door","/d/av_rooms/lurue/dekumage_m2","east","manor key","entry lock");
    add_lock("entry door","manor key","entry lock","The lock is made of iron and looks to be in fairly good repair.");
    set_locked("entry door",1,"entry lock");
    lock_difficulty("entry door",-30,"entry lock");
    set_open("entry door",0);
    set_string("entry door","knock","pounds on the");
    set_string("entry door","open","You put your weight against the heavy wooden door and shove it open.");
    set_string("entry door","close","With a heave, you close the heavy wooden door.");
    set_door_description("entry door","%^RESET%^%^ORANGE%^This large wooden door is covered in fancy scrollwork and inset with delightful panels of amethyst glass.  Unfortunately, time and weather have swollen the wood to the point that the door is nearly wedged into the door jam.  Though, you do notice evidence of it having been opened recently. %^RESET%^");
}