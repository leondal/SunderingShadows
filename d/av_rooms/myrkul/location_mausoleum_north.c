// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("location_mausoleum_north");
    set_property("indoors",0);
    set_property("light",0);
    set_property("no teleport",1);
    set_terrain("garden");
    set_travel("foot path");
    set_climate("temperate");

    set_short("Stone Mausoleum");

    set_long("%^RESET%^%^CYAN%^You stand in a peaceful and undefiled mausoleum. There is a crate full of food, and a cot in the corner. A stone sarcophagus lies in the center, shaped like an old soldier. Above, a l"
	"ight shines through a hole in the roof.%^RESET%^"
	);

    set_smell("default","
It smells like old stone here.");
    set_listen("default","You hear the muffled thumps and thuds outside the door.");

    set_search("grave","%^RESET%^%^ORANGE%^The dirt feels loose in your hands, and many %^BLUE%^personal effects%^RESET%^%^ORANGE%^ scatter the ground. Who knows what you might find? You find yourself weighing the voices of your %^BOLD%^%^RED%^inner demons%^RESET%^%^ORANGE%^ and %^BOLD%^%^WHITE%^better angels%^RESET%^%^ORANGE%^ of your nature.%^RESET%^ ");
    set_search("sarcophagus","It doesn't seem to open, and the lid seems like it just won't lift.");
    set_search("graves","%^RESET%^%^ORANGE%^The dirt feels loose in your hands, and many %^BLUE%^personal effects%^RESET%^%^ORANGE%^ scatter the ground. Who knows what you might find? You find yourself weighing the voices of your %^BOLD%^%^RED%^inner demons%^RESET%^%^ORANGE%^ and %^BOLD%^%^WHITE%^better angels%^RESET%^%^ORANGE%^ of your nature.%^RESET%^ ");
    
set_items(([ 
	({ "restless dead", "dead" }) : "%^BOLD%^%^GREEN%^The %^BLACK%^dead%^GREEN%^ walk. Villagers, soldiers, farmers, young, old. The %^BLACK%^h%^YELLOW%^orror%^GREEN%^ of this place is %^RESET%^%^MAGENTA%^unspeakable.%^RESET%^",
	({ "grave", "graves" }) : "%^BOLD%^%^BLACK%^Hmmm. This now empty grave looks to be, oh, %^MAGENTA%^about your size!%^RESET%^",
	"evil" : "%^RED%^The presence of evil in this place is undeniable.%^RESET%^",
	"sarcophagus" : "There is an inscription: Samuel, soldier to the last, who stands on his last watch, even now.",
	"food" : "Its not a lot of food, and there's a few jars of water.",
	]));

    set_exits(([ 
		"south" : "/d/av_rooms/myrkul/boneyard_north_mausoleum",
	]));

    set_door("marble door","/d/av_rooms/myrkul/boneyard_mausoleum_north","south","skeleton key","brass lock");
    add_lock("marble door","skeleton key","brass lock","brass lock");
    set_locked("marble door",1,"brass lock");
    lock_difficulty("marble door",-5,"brass lock");
    set_open("marble door",0);
    set_string("marble door","knock","pounds on the");
    set_string("marble door","open","With a struggle the door opens inward.");
    set_string("marble door","close","The sound of the door slamming shut echos with a disturbing finality.");
    set_door_description("marble door","This is an extraordinarily heavy marble door with a ring for a handle to open and a brass lock.");
}