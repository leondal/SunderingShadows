// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("location_manor");
    set_property("indoors",0);
    set_property("light",0);
    set_property("no teleport",1);
    set_terrain("garden");
    set_travel("foot path");
    set_climate("temperate");

    set_short("An old manor house");

    set_long("This is the main hall of a once proud house. Paintings of many Dukes and Duchesses line the wall, all of the house Sarcosta. A red carpet, one a luxury of %^RED%^red fabric%^RESET%^ is now tarnished a"
	"nd brown. Pedestals once aloft held vases of antiquity, are now bare. Fragments of art lie, smashed on the ground. An oak chair sits in the open, as if placed there in order to better contemplate the "
	"meaninglessness of existence."
	);

    set_smell("default","
It smells of rot and mold.");
    set_listen("default","The hall, once bustling with life, is now silent.");

    set_search("grave","%^RESET%^%^ORANGE%^The dirt feels loose in your hands, and many %^BLUE%^personal effects%^RESET%^%^ORANGE%^ scatter the ground. Who knows what you might find? You find yourself weighing the voices of your %^BOLD%^%^RED%^inner demons%^RESET%^%^ORANGE%^ and %^BOLD%^%^WHITE%^better angels%^RESET%^%^ORANGE%^ of your nature.%^RESET%^ ");
    set_search("graves","%^RESET%^%^ORANGE%^The dirt feels loose in your hands, and many %^BLUE%^personal effects%^RESET%^%^ORANGE%^ scatter the ground. Who knows what you might find? You find yourself weighing the voices of your %^BOLD%^%^RED%^inner demons%^RESET%^%^ORANGE%^ and %^BOLD%^%^WHITE%^better angels%^RESET%^%^ORANGE%^ of your nature.%^RESET%^ ");
    
set_items(([ 
	({ "grave", "graves" }) : "%^BOLD%^%^BLACK%^Hmmm. This now empty grave looks to be, oh, %^MAGENTA%^about your size!%^RESET%^",
	({ "restless dead", "dead" }) : "%^BOLD%^%^GREEN%^The %^BLACK%^dead%^GREEN%^ walk. Villagers, soldiers, farmers, young, old. The %^BLACK%^h%^YELLOW%^orror%^GREEN%^ of this place is %^RESET%^%^MAGENTA%^unspeakable.%^RESET%^",
	"chair" : "The chair was once very fine. Now the upholstery is shredded, and the wood is cracked.",
	"evil" : "%^RED%^The presence of evil in this place is undeniable.%^RESET%^",
	"paintings" : "You recognize at least two of the paintings: the Duke Sarcosta who rescued you , and his son, the last of the line.",
	]));

    set_exits(([ 
		"east" : "/d/av_rooms/myrkul/boneyard_west_manor",
	]));

    set_door("door","/d/av_rooms/myrkul/boneyard_west_manor","east","silver key","enchanted lock");
    add_lock("door","silver key","enchanted lock","The lock looks to be enchanted bending in the light to deceive the eye.");
    set_locked("door",1,"enchanted lock");
    lock_difficulty("door",-30,"enchanted lock");
    set_open("door",0);
    set_string("door","knock","is rap, rap, rapping on the");
    set_string("door","open","The door opens effortlessly.");
    set_string("door","close","The door closes with a sound.");
    set_door_description("door","The door seems wonderously light, almost as if enchanted to respond to your touch.");
}