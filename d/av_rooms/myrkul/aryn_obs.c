// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("aryn_obs");
    set_property("indoors",1);
    set_property("light",1);
    set_property("no teleport",1);
    set_terrain("stone building");
    set_travel("slick floor");
    set_climate("temperate");

    set_short("%^BOLD%^%^RED%^O%^RESET%^%^RED%^b%^MAGENTA%^s%^BOLD%^%^RED%^e%^RESET%^%^RED%^r%^MAGENTA%^v%^BOLD%^%^RED%^a%^RESET%^%^RED%^t%^MAGENTA%^i%^BOLD%^%^RED%^o%^RESET%^%^RED%^n %^BOLD%^%^WHITE%^C%^RESET%^h%^BOLD%^%^WHITE%^a%^RESET%^m%^BOLD%^%^WHITE%^b%^RESET%^e%^BOLD%^%^WHITE%^r%^RESET%^");

    set_long("%^BOLD%^%^CYAN%^You stand inside a %^RESET%^%^CYAN%^tidy room%^BOLD%^ that branches off from the main laboratory. The main focus of the room is on what would appear to be a %^WHITE%^transparent window"
	"%^CYAN%^ in the west wall. The room beyond the window holds a %^RESET%^%^ORANGE%^table and chairs%^BOLD%^%^CYAN%^ with walls that are entirely %^WHITE%^p%^RESET%^a%^BOLD%^%^WHITE%^d%^RESET%^d%^BOLD%^%"
	"^WHITE%^e%^RESET%^d%^BOLD%^%^CYAN%^. To the side of the transparent window is some kind of magical or psionic %^YELLOW%^e%^RESET%^%^ORANGE%^n%^YELLOW%^e%^RESET%^%^ORANGE%^r%^YELLOW%^g%^RESET%^%^ORANGE"
	"%^y%^YELLOW%^ b%^RESET%^%^ORANGE%^a%^YELLOW%^r%^RESET%^%^ORANGE%^r%^YELLOW%^i%^RESET%^%^ORANGE%^e%^YELLOW%^r%^CYAN%^ which serves as a door. There is a set of table and chairs with notebooks and pens "
	"to take notes on whatever occurs inside the room. Various %^GREEN%^cubbies%^CYAN%^ line the north and east walls full of supplies.%^RESET%^"
	);

    set_smell("default","
It smells of alcohol disinfectant and possibly sulfur.");
    set_listen("default","You hear the ticking of a chronometer on the table.");

    
set_items(([ 
	"floor" : "The floor could use some wax. Perhaps there is an old bloodstain here or there? Odd, but otherwise unremarkable.",
	({ "wall", "west wall", "north wall", "east wall", "south wall", "walls" }) : "The north and east walls are lined with cubbies full of supplies. The west wall has an energy barrier and a transparent window. There is no south wall, it leads into the main laboratory.",
	({ "notebooks", "pens", "table", "chronometer" }) : "A chronometer shows the time on the table. Various notebooks and pens lay about. No experiments have been done as of late because the notebooks look very fresh.",
	"cubbies" : "Various magical components, crystals, and mechanical knick-knacks fill the cubbies, enough to satisfy any reasonable mage, psion, or bored gnome (which is really quite a lot).",
	"ceiling" : "The ceiling looks quite ordinary. In fact it is ordinary.",
	"window" : "You can <peer window> to see into the room beyond. Furthermore, the window appears to be a one-way portal as well for throwing food or shooting arrows at whatever happens to be beyond the wall. Woe be to the person who tries to lean on it, as they would be in for a shock!",
	]));

    set_exits(([ 
		"south" : "/d/av_rooms/myrkul/aryn_lab",
//                "window" : "/d/av_rooms/myrkul/aryn_cell",
		"portal" : "/d/av_rooms/myrkul/aryn_cell",
	]));

    set_door("energy barrier","/d/av_rooms/myrkul/aryn_cell","portal","skeleton key","lock");
    add_lock("energy barrier","skeleton key","lock","This lock is made out of %^YELLOW%^pure energy%^RESET%^, something a locksmith could only dream of making. It appears however, that some quite ordinary key should be able to  unlock it.");
    set_locked("energy barrier",1,"lock");
    lock_difficulty("energy barrier",-65,"lock");
    set_open("energy barrier",0);
    set_string("energy barrier","knock","pounds on the");
    set_string("energy barrier","open","%^BOLD%^%^CYAN%^The %^YELLOW%^energy barrier%^CYAN%^ snaps open with a %^RESET%^%^CYAN%^hiss.%^RESET%^");
    set_string("energy barrier","close","%^BOLD%^%^CYAN%^The %^YELLOW%^energy barrier%^CYAN%^ snaps shut with a %^RESET%^%^CYAN%^hiss.%^RESET%^");
    set_door_description("energy barrier","%^BOLD%^%^CYAN%^This appear to be some kind of magical or psionic %^YELLOW%^energy barrier%^CYAN%^. It seems harder than diamond and stronger than steel. There does appear to be some kind of lock assembly in the center.");
}
