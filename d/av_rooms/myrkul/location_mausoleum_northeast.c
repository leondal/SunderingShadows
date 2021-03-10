// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("location_mausoleum_northeast");
    set_property("indoors",0);
    set_property("light",0);
    set_property("no teleport",1);
    set_terrain("garden");
    set_travel("foot path");
    set_climate("temperate");

    set_short("Stone Mausoleum");

    set_long("%^RESET%^%^BLUE%^This mausoleum is bare except for a crumbling stone statue of an angel. The angel looks human, but has magnificent wings. One hand is raised palm up, and the other hand is palm down. "
	"A sword at his side, once proud, is cracked and broken. The figure stares off into Eternity, face dispationate.%^RESET%^"
	);

    set_smell("default","
%^BOLD%^%^BLACK%^D%^MAGENTA%^e%^BLACK%^ath and D%^MAGENTA%^e%^BLACK%^cay permeates the air, with a hint of %^YELLOW%^sulfur%^BLACK%^.%^RESET%^");
    set_listen("default","%^BOLD%^%^BLUE%^Echos of %^WHITE%^bone%^BLUE%^ and %^CYAN%^st%^BLACK%^e%^CYAN%^el%^BLUE%^ ring through the %^RED%^B%^BLACK%^o%^RED%^neyard.%^RESET%^");

    set_search("grave","%^RESET%^%^ORANGE%^The dirt feels loose in your hands, and many %^BLUE%^personal effects%^RESET%^%^ORANGE%^ scatter the ground. Who knows what you might find? You find yourself weighing the voices of your %^BOLD%^%^RED%^inner demons%^RESET%^%^ORANGE%^ and %^BOLD%^%^WHITE%^better angels%^RESET%^%^ORANGE%^ of your nature.%^RESET%^ ");
    set_search("graves","%^RESET%^%^ORANGE%^The dirt feels loose in your hands, and many %^BLUE%^personal effects%^RESET%^%^ORANGE%^ scatter the ground. Who knows what you might find? You find yourself weighing the voices of your %^BOLD%^%^RED%^inner demons%^RESET%^%^ORANGE%^ and %^BOLD%^%^WHITE%^better angels%^RESET%^%^ORANGE%^ of your nature.%^RESET%^ ");
    
set_items(([ 
	({ "grave", "graves" }) : "%^BOLD%^%^BLACK%^Hmmm. This now empty grave looks to be, oh, %^MAGENTA%^about your size!%^RESET%^",
	({ "restless dead", "dead" }) : "%^BOLD%^%^GREEN%^The %^BLACK%^dead%^GREEN%^ walk. Villagers, soldiers, farmers, young, old. The %^BLACK%^h%^YELLOW%^orror%^GREEN%^ of this place is %^RESET%^%^MAGENTA%^unspeakable.%^RESET%^",
	"evil" : "%^RED%^The presence of evil in this place is undeniable.%^RESET%^",
	]));

    set_exits(([ 
		"southwest" : "/d/av_rooms/myrkul/boneyard_northeast_mausoleum",
	]));

    set_door("marble door","/d/av_rooms/myrkul/boneyard_mausoleum_northeast","southwest","iron key","iron lock");
    add_lock("marble door","iron key","iron lock","This is a beautifully made iron lock.");
    set_locked("marble door",1,"iron lock");
    lock_difficulty("marble door",-25,"iron lock");
    set_open("marble door",0);
    set_string("marble door","knock","pounds on the");
    set_string("marble door","open","The door opens easily on well oiled hinges.");
    set_string("marble door","close","The door closes with a click.");
    set_door_description("marble door","This is a heavy marble door with a finely made iron lock.");
}