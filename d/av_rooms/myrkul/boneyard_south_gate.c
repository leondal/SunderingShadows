// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("boneyard_south_gate");
    set_property("indoors",0);
    set_property("light",0);
    set_property("no teleport",1);
    set_terrain("garden");
    set_travel("foot path");
    set_climate("temperate");

    set_short("%^BOLD%^%^BLACK%^T%^RESET%^%^RED%^h%^BOLD%^%^BLACK%^e %^BLACK%^B%^YELLOW%^o%^RESET%^%^RED%^n%^BOLD%^%^BLACK%^e%^%^RESET%^%^RED%^y%^BOLD%^%^YELLOW%^a%^RESET%^%^RED%^r%^%^BOLD%^BLACK%^d%^RESET%^");

    set_long("%^BOLD%^%^RED%^You stand in the wreckage of a cemetary. What was once a %^GREEN%^s%^CYAN%^e%^GREEN%^re%^CYAN%^n%^GREEN%^ne%^RED%^ and %^YELLOW%^elegant%^RED%^ resting place for the %^BLACK%^dead%^RED%"
	"^, is now a rally point for the %^BLUE%^forces of evil%^RED%^. The %^RESET%^%^ORANGE%^headstones%^BOLD%^%^RED%^ are smashed, and graves have been dug up from the %^WHITE%^inside%^RED%^. In broad dayli"
	"ght or the darkness of night, the %^BLACK%^R%^WHITE%^e%^BLACK%^stless %^BLACK%^D%^WHITE%^e%^BLACK%^ad%^RED%^ walk fearless and unfettered, hungering for the %^MAGENTA%^flesh of the living%^RED%^. Noth"
	"ing grows here anymore.%^RESET%^"
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
		"north" : "/d/av_rooms/myrkul/boneyard_south",
		"south" : "/d/av_rooms/myrkul/location_gate",
	]));

}