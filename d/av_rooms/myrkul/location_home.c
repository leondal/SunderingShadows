// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("location_home");
    set_property("indoors",0);
    set_property("light",0);
    set_property("no teleport",1);
    set_terrain("garden");
    set_travel("foot path");
    set_climate("temperate");

    set_short("%^BOLD%^%^GREEN%^C%^MAGENTA%^e%^GREEN%^metary K%^MAGENTA%^e%^GREEN%^eper's H%^MAGENTA%^o%^GREEN%^me%^RESET%^");

    set_long("%^BOLD%^%^GREEN%^This is a tidy looking home that has seen some better days. Very tiny, it consists of a single room with a pot-belly stove, a counter for cooking, a four-poster bed with a straw-stuff"
	"ed matress, and a table with chairs. Some cabinets seem to have some pots and pans above the counter, and food stuffs reside in a built-in wall chest. Tools sit in a barrel by the door. A single steel"
	"-barred window lets in light from outside. Peaceful symbols of Kelemvor line the walls throughout the house.%^RESET%^"
	);

    set_smell("default","
%^BOLD%^%^BLACK%^D%^MAGENTA%^e%^BLACK%^ath and D%^MAGENTA%^e%^BLACK%^cay permeates the air, with a hint of %^YELLOW%^sulfur%^BLACK%^.%^RESET%^");
    set_listen("default","%^BOLD%^%^BLUE%^Echos of %^WHITE%^bone%^BLUE%^ and %^CYAN%^st%^BLACK%^e%^CYAN%^el%^BLUE%^ ring through the %^RED%^B%^BLACK%^o%^RED%^neyard.%^RESET%^");

    set_search("grave","%^RESET%^%^ORANGE%^The dirt feels loose in your hands, and many %^BLUE%^personal effects%^RESET%^%^ORANGE%^ scatter the ground. Who knows what you might find? You find yourself weighing the voices of your %^BOLD%^%^RED%^inner demons%^RESET%^%^ORANGE%^ and %^BOLD%^%^WHITE%^better angels%^RESET%^%^ORANGE%^ of your nature.%^RESET%^ ");
    set_search("graves","%^RESET%^%^ORANGE%^The dirt feels loose in your hands, and many %^BLUE%^personal effects%^RESET%^%^ORANGE%^ scatter the ground. Who knows what you might find? You find yourself weighing the voices of your %^BOLD%^%^RED%^inner demons%^RESET%^%^ORANGE%^ and %^BOLD%^%^WHITE%^better angels%^RESET%^%^ORANGE%^ of your nature.%^RESET%^ ");
    
set_items(([ 
	({ "cabinet", "cabinets", "pots", "pans" }) : "Pots and pans have seen better days.",
	({ "symbols", "kelemvor" }) : "%^BOLD%^%^WHITE%^A skeletal hand holding scales papers the walls, the grave digger clearly a devout artist. Such handiwork must be holding the undead out.. or perhaps holding the undead in!%^RESET%^",
	"tools" : "The tools look to be for gardening and a shovel for digging graves.",
	"counter" : "%^ORANGE%^The crumbs left on the counter have no one to clean them up, not even a mouse.%^RESET%^",
	"stove" : "%^ORANGE%^Once piping hot, it has gone cold with no one to tend to it. The keeper once made his meals here.%^RESET%^",
	"matress" : "%^ORANGE%^The bed is unmade with a few worn blankets on top.%^RESET%^",
	]));

    set_exits(([ 
		"southeast" : "/d/av_rooms/myrkul/boneyard_northwest_home",
	]));

    set_door("door","/d/av_rooms/myrkul/boneyard_northwest_home","southeast","skeleton key","cast iron lock");
    add_lock("door","skeleton key","cast iron lock","This looks like a well made lock by a local blacksmith, sufficient to disuade the local riff raff but no barrier to the true professional.");
    set_locked("door",1,"cast iron lock");
    lock_difficulty("door",-5,"cast iron lock");
    set_open("door",0);
    set_string("door","knock","pounds on the");
    set_string("door","open","The door creeeaaaakkkkssss open.");
    set_string("door","close","The door slams shut with a resounding THUD.");
    set_door_description("door","This is a heavy wooden door made from sturdy planks of oak.");
}