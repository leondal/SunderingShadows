// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("noblehouse1");
    set_property("indoors",1);
    set_property("light",2);
    set_property("no teleport",1);
    set_terrain("stone building");
    set_travel("slick floor");
    set_climate("temperate");

    set_short("%^YELLOW%^a large mansion foyer%^RESET%^");

    set_long("%^YELLOW%^This well-lit mansion foyer conveys an immediate aura of %^RESET%^%^ORANGE%^wealth %^BOLD%^and %^MAGENTA%^prestige %^ORANGE%^with just a glance, with its %^WHITE%^s%^RESET%^p%^BOLD%^a%^RESET"
	"%^r%^BOLD%^k%^RESET%^l%^BOLD%^i%^RESET%^n%^BOLD%^g m%^RESET%^a%^BOLD%^r%^RESET%^bl%^BOLD%^e f%^RESET%^l%^BOLD%^o%^RESET%^o%^BOLD%^r %^ORANGE%^and s%^RESET%^%^ORANGE%^a%^WHITE%^n%^ORANGE%^d%^BOLD%^y s%"
	"^WHITE%^t%^ORANGE%^u%^RESET%^c%^BOLD%^c%^ORANGE%^o walls bathing the room in w%^RESET%^%^ORANGE%^a%^BOLD%^rm, g%^RESET%^%^ORANGE%^o%^BOLD%^ld%^RESET%^%^ORANGE%^e%^BOLD%^n l%^RESET%^%^ORANGE%^i%^BOLD%^"
	"g%^RESET%^%^ORANGE%^h%^BOLD%^t. A %^WHITE%^small%^ORANGE%^, %^WHITE%^c%^CYAN%^r%^WHITE%^y%^RESET%^%^CYAN%^s%^BOLD%^%^WHITE%^t%^CYAN%^a%^WHITE%^l%^RESET%^%^CYAN%^l%^BOLD%^%^WHITE%^i%^CYAN%^n%^WHITE%^e "
	"%^CYAN%^chandelier %^ORANGE%^hangs from the ceiling. Several rooms are adjoined to this one, hidden away behind elaborate sliding doors. A %^RESET%^%^ORANGE%^curved staircase %^BOLD%^of %^WHITE%^white"
	" stone %^ORANGE%^wraps along the outside of the room, leading up to the mansion's second story, where a number of doors line the halls in both directions.%^RESET%^"
	);

    set_smell("default","
The air in this room is clean, and free of odor.");
    set_listen("default","Sound echoes easily throughout the foyer.");

    
set_items(([ 
	"floor" : "%^BOLD%^The floor is made from large tiles of g%^RESET%^l%^BOLD%^e%^RESET%^a%^BOLD%^mi%^RESET%^n%^BOLD%^g m%^RESET%^a%^BOLD%^rb%^RESET%^l%^BOLD%^e, each of them a slightly different shade of white, creating a subtle c%^RESET%^h%^BOLD%^e%^BLACK%^c%^WHITE%^k%^BLACK%^e%^WHITE%^r%^RESET%^e%^BOLD%^d effect.%^RESET%^",
	({ "staircase", "stairs" }) : "%^BOLD%^This staircase is wrought of flawless white stone and with an %^BLACK%^ornate scrolled banister %^WHITE%^of %^RESET%^%^ORANGE%^stained wood%^BOLD%^%^WHITE%^.%^RESET%^",
	"chandelier" : "%^BOLD%^A small %^CYAN%^chandelier %^WHITE%^hangs from the ceiling, more easily visible from the second story. Crafted from o%^RESET%^r%^BOLD%^n%^RESET%^a%^BOLD%^te%^RESET%^l%^BOLD%^y blown g%^RESET%^l%^BOLD%^a%^RESET%^s%^BOLD%^s and many individual lanterns, this seems to light the room quite easily.%^RESET%^",
	]));

    set_exits(([ 
		"office" : "/d/av_rooms/brandobaris/noblehouse2",
		"bedroom" : "/d/av_rooms/brandobaris/noblehouse3",
		"out" : "/d/antioch/antioch2/rooms/street28",
	]));

    set_door("office doors","/d/av_rooms/brandobaris/noblehouse2.c","office");
    set_string("office doors","knock","knock");
    set_string("office doors","open","%^ORANGE%^The doors swing open to reveal a large and %^BOLD%^ornate %^RESET%^%^ORANGE%^office.%^WHITE%^");
    set_string("office doors","close","%^ORANGE%^The doors swing shut, closing with a quiet %^BOLD%^%^BLACK%^thud%^RESET%^%^ORANGE%^.%^WHITE%^");
    set_door_description("office doors","%^ORANGE%^These large double doors are made from polished d%^BOLD%^%^BLACK%^a%^RESET%^%^ORANGE%^rk w%^BOLD%^%^BLACK%^oo%^RESET%^%^ORANGE%^d, and each door bears an o%^BOLD%^r%^WHITE%^n%^ORANGE%^a%^WHITE%^t%^RESET%^%^ORANGE%^e handle of %^BOLD%^gold%^RESET%^%^ORANGE%^.%^WHITE%^");
    set_door("bedroom door","/d/av_rooms/brandobaris/noblehouse3","bedroom","silver key","keyhole");
    add_lock("bedroom door","silver key","keyhole","A simple looking keyhole.");
    set_locked("bedroom door",1,"keyhole");
    lock_difficulty("bedroom door",-75,"keyhole");
    set_open("bedroom door",0);
    set_string("bedroom door","knock","knock");
    set_string("bedroom door","open","%^ORANGE%^The door opens quietly.");
    set_string("bedroom door","close","%^ORANGE%^The door closes quietly.");
    set_door_description("bedroom door","%^ORANGE%^This %^BOLD%^%^WHITE%^polished %^RESET%^%^ORANGE%^wooden door bears a simple iron handle. A small %^BOLD%^%^WHITE%^s%^RESET%^i%^BOLD%^lv%^RESET%^e%^BOLD%^r %^BLACK%^keyhole %^RESET%^%^ORANGE%^is set into the door.%^WHITE%^");
}