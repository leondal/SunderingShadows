// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("dekumage_m3");
    set_property("indoors",1);
    set_property("light",0);
    set_property("no teleport",1);
    set_terrain("wood building");
    set_travel("decayed floor");
    set_climate("tropical");

    set_short("%^BOLD%^%^WHITE%^An old manor house%^RESET%^");

    set_long("%^RESET%^The hallway stretches to the back of the house where it ends in flight of stairs going up to the second floor.  The %^RED%^threadbare rug %^RESET%^continues up each of the steps and you can s"
	"ee patches of what it once was like in the underside of each step.  The stairs look sturdy enough to ascend, though the %^BOLD%^%^WHITE%^railing %^RESET%^is brittle and cracked.  Under the stairs is a"
	" small door, probably leading to storage, while to the north another door blocks access to a room.%^RESET%^"
	);

    set_smell("default","
The air smells of ruin and mold.");
    set_listen("default","The boards under your feet groan with your weight.");

    
set_items(([ 
	({ "stair", "stairs", "railing" }) : "%^BOLD%^%^WHITE%^The stairs lead up to the second floor of the manor house.  They look sturdy enough, and you're certain they'll hold your weight, for now.  The railing though has begun to fall apart, which makes you think that its only time before the whole thing collapses. %^RESET%^",
	({ "floor", "rug" }) : "%^RED%^Looking at the floor you can see that a once plush rug stretched along the length of the hallway.  Though you see only a small amount of design work along the edges it was probably at one time very soft under foot.  Now it is thredbare and dirty.%^RESET%^",
	]));

    set_exits(([ 
		"stairs" : "/d/av_rooms/lurue/dekumage_u1",
		"west" : "/d/av_rooms/lurue/dekumage_m2",
		"north" : "/d/av_rooms/lurue/dekumage_m5",
		"closet" : "/d/av_rooms/lurue/dekumage_b2",
	]));

    set_door("closet door","/d/av_rooms/lurue/dekumage_b2","closet");
    set_open("closet door",0);
    set_string("closet door","knock","knock on the door");
    set_string("closet door","open","The door swings open with a soft groan of sound.");
    set_string("closet door","close","The door swings closed with a soft groan of sound.");
    set_door_description("closet door","The door is simply made from a panel of wood under the stairs.  Narrow, it offers just enough room to squeeze through with perhaps a few small bundles of items.");
    set_door("wood door","/d/av_rooms/lurue/dekumage_m5","north","manor key","steel lock");
    add_lock("wood door","manor key","steel lock","This steel lock is well made and appears fairly new compared to much of the manor house.  It would take a lot of effort to break it.");
    set_locked("wood door",1,"steel lock");
    lock_difficulty("wood door",-30,"steel lock");
    set_open("wood door",0);
    set_string("wood door","knock","knocks on the");
    set_string("wood door","open","The wooden door swings open.");
    set_string("wood door","close","The wooden door swings closed.");
    set_door_description("wood door","%^RESET%^%^ORANGE%^This wooden door appears to be in good condition, especially when considered against the rest of the manor.  The thick wood is free of warping and looks almost new, as does the lock.%^RESET%^");
}