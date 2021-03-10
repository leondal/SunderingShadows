// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("dekumage_m5");
    set_property("indoors",1);
    set_property("light",0);
    set_property("no teleport",1);
    set_terrain("wood building");
    set_travel("decayed floor");
    set_climate("tropical");

    set_short("%^BOLD%^%^WHITE%^An old manor house%^RESET%^");

    set_long("%^RESET%^This room was once a bedroom by the looks of it.  A small %^BOLD%^%^BLACK%^bed %^RESET%^occupies one half of the room, while a %^ORANGE%^cabinet %^RESET%^and %^CYAN%^writing desk%^RESET%^ can"
	" be found on the the far side of the room.  A closet holds a few %^BLUE%^old outfits%^RESET%^ that look to be in disrepair, and the rug on the floor is threadbare and worn.  It appears no one has used"
	" this room in a long time.%^RESET%^"
	);

    set_smell("default","
The air smells of ruin and mold.");
    set_listen("default","The boards under your feet groan with your weight.");

    set_search("cabinet","%^ORANGE%^You search through the cabinet but it appears to already have been cleared out.%^RESET%^");
    set_search("closet","%^RESET%^%^BLUE%^Nothing here but some moth eaten clothing and a lot of dust.%^RESET%^");
    set_search("drawer","%^BOLD%^%^WHITE%^You tug and yank and finally get the drawer free, but there isn't much inside.  Just a letter from the general store in Verbobone detailing a purchase of a ten seed packets, two pots of unidentified plants, and a coil of copper wire.%^RESET%^");
    set_search("bed","%^BOLD%^%^BLACK%^You search around in the bed and cause a big dust cloud to lift into the air.  Your nose itches and you're sure you're going to sneeze!%^RESET%^");
    set_search("desk","%^RESET%^%^ORANGE%^You search the desk and find one drawer is rather suck.  Maybe you could search that drawer if you could get it open.%^RESET%^");
    
set_items(([ 
	({ "closet", "outfits", "outfit" }) : "%^BOLD%^%^BLUE%^Looking the outfits in the closet over, you notice they're all rather small, as though they were made for a child or someone of small stature.%^RESET%^",
	({ "desk", "writing desk" }) : "%^CYAN%^The desk is covered in a thick layer of dust and appears to be about ready to fall apart.%^RESET%^",
	({ "cabinet", "drawers" }) : "A chest of drawers, the cabinet looks old and worn, nearly falling apart with age.  You do notice however one drawer seems rather stuck, perhaps you could search it, if you could get it open.%^RESET%^",
	"bed" : "%^BOLD%^%^BLACK%^The bed is covered in a lot of bedding.  Though old and tattered, who knows what might be found under all that fabric.%^RESET%^",
	]));

    set_exits(([ 
		"south" : "/d/av_rooms/lurue/dekumage_m3",
	]));

    set_door("entry door","/d/av_rooms/lurue/dekumage_m1","west","manor_key","entry lock");
    add_lock("entry door","manor_key","entry lock","The lock is made of iron and looks to be in fairly good repair.");
    set_locked("entry door",1,"entry lock");
    lock_difficulty("entry door",-30,"entry lock");
    set_open("entry door",0);
    set_string("entry door","knock","pounds on the");
    set_string("entry door","open","You put your weight against the heavy wooden door and shove it open.");
    set_string("entry door","close","With a heave, you close the heavy wooden door.");
    set_door_description("entry door","%^RESET%^%^ORANGE%^This large wooden door is covered in fancy scrollwork and inset with delightful panels of amethyst glass.  Unfortunately, time and weather have swollen the wood to the point that the door is nearly wedged into the door jam.  Though, you do notice evidence of it having been opened recently. %^RESET%^");
    set_door("wood door","/d/av_rooms/lurue/dekumage_m3","south","manor key","steel lock");
    add_lock("wood door","manor key","steel lock","This steel lock is well made and appears fairly new compared to much of the manor house.  It would take a lot of effort to break it.");
    set_locked("wood door",1,"steel lock");
    lock_difficulty("wood door",-30,"steel lock");
    set_open("wood door",0);
    set_string("wood door","knock","knocks on the");
    set_string("wood door","open","The wooden door swings open.");
    set_string("wood door","close","The wooden door swings closed.");
    set_door_description("wood door","%^RESET%^%^ORANGE%^This wooden door appears to be in good condition, especially when considered against the rest of the manor.  The thick wood is free of warping and looks almost new, as does the lock.%^RESET%^");
}