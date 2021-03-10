// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("noblehouse3");
    set_property("indoors",1);
    set_property("light",2);
    set_property("no teleport",1);
    set_terrain("stone building");
    set_travel("slick floor");
    set_climate("temperate");

    set_short("%^ORANGE%^a neatly-kept bedroom%^RESET%^");

    set_long("%^BOLD%^This is a small, but well furnished bedroom. An %^RESET%^%^ORANGE%^o%^GREEN%^a%^ORANGE%^k%^GREEN%^e%^ORANGE%^n d%^GREEN%^r%^ORANGE%^e%^GREEN%^s%^ORANGE%^s%^GREEN%^e%^ORANGE%^r %^BOLD%^%^WHITE%"
	"^sits at the far end of the room, with a large s%^RESET%^i%^BOLD%^l%^CYAN%^v%^RESET%^e%^BOLD%^r m%^RESET%^i%^BOLD%^r%^RESET%^r%^BOLD%^or set against the wall behind it. A large bed is placed nearby, d"
	"ressed with an o%^MAGENTA%^r%^WHITE%^n%^RED%^a%^MAGENTA%^t%^WHITE%^e q%^RED%^u%^WHITE%^i%^MAGENTA%^l%^WHITE%^t. Across from the bed there lies a simple %^RESET%^%^ORANGE%^wooden desk%^BOLD%^%^WHITE%^,"
	" placed to take advantage of the %^ORANGE%^sunlight %^WHITE%^that must pour through the nearby glass window.%^RESET%^"
	);

    set_smell("default","
This room smells faintly of citrus.");
    set_listen("default","You can hear the noise coming from the street outside.");

    
set_items(([ 
	"window" : "%^CYAN%^A small window is set into the wall opposite the desk, and it gives an appreciable view of the street outside. %^BOLD%^C%^RESET%^l%^BOLD%^e%^RESET%^a%^BOLD%^%^CYAN%^r%^RESET%^%^CYAN%^, %^BOLD%^c%^WHITE%^r%^RESET%^y%^BOLD%^s%^CYAN%^t%^WHITE%^a%^CYAN%^l%^WHITE%^l%^RESET%^i%^BOLD%^n%^CYAN%^e%^RESET%^%^CYAN%^, and free of dust, this window does an excellent job of letting in the %^YELLOW%^daylight%^RESET%^%^CYAN%^.%^WHITE%^",
	"drawers" : "%^ORANGE%^Two large drawers are set into the desk, each bearing an %^WHITE%^o%^BOLD%^r%^BLACK%^n%^RESET%^a%^BOLD%^t%^RESET%^e %^BOLD%^silver handle %^RESET%^%^ORANGE%^and a small %^BOLD%^%^BLACK%^keyhole%^RESET%^%^ORANGE%^. They appear to be locked.%^WHITE%^",
	"bed" : "%^BOLD%^This large bed looks soft and comfortable, with several %^MAGENTA%^p%^RED%^i%^GREEN%^l%^MAGENTA%^l%^RED%^o%^GREEN%^w%^MAGENTA%^s %^WHITE%^of %^RED%^v%^GREEN%^a%^RED%^r%^ORANGE%^y%^CYAN%^i%^RED%^ng %^GREEN%^c%^ORANGE%^o%^GREEN%^l%^MAGENTA%^o%^GREEN%^rs %^WHITE%^placed at its head, and made up with a number of %^RESET%^cotton blankets%^BOLD%^. A large and ornate woolen quilt is set over it all, a c%^MAGENTA%^h%^RED%^a%^WHITE%^o%^RESET%^t%^BOLD%^%^MAGENTA%^i%^WHITE%^c p%^RED%^a%^MAGENTA%^t%^RED%^t%^MAGENTA%^e%^RED%^r%^WHITE%^n of %^MAGENTA%^p%^RESET%^%^MAGENTA%^i%^BOLD%^n%^RESET%^%^MAGENTA%^k%^BOLD%^s%^WHITE%^, %^RED%^r%^RESET%^%^RED%^e%^BOLD%^ds%^WHITE%^, and w%^RESET%^h%^BOLD%^it%^RESET%^e%^BOLD%^s worked into its elaborate weave.%^RESET%^",
	"desk" : "%^ORANGE%^This is a small desk of stained wood, its surface %^WHITE%^worn down %^ORANGE%^by years of constant use. Several scholarly %^WHITE%^texts %^ORANGE%^are stacked loosely near one corner of the desktop, while a large %^BOLD%^stationary kit %^RESET%^%^ORANGE%^is kept close at hand opposite it. A small %^BOLD%^%^CYAN%^statuette %^RESET%^%^ORANGE%^of a %^GREEN%^t%^BOLD%^o%^RESET%^%^CYAN%^r%^GREEN%^t%^BOLD%^%^CYAN%^o%^RESET%^%^GREEN%^i%^BOLD%^s%^RESET%^%^GREEN%^e %^ORANGE%^is kept out of the way toward the back, seemingly decorative in nature. On the right hand side of the desk are two large %^RED%^drawers%^ORANGE%^, though judging by the keyholes, they are most often kept locked.%^WHITE%^",
	]));

    set_exits(([ 
		"foyer" : "/d/av_rooms/brandobaris/noblehouse1",
	]));

    set_door("bedroom door","/d/av_rooms/brandobaris/noblehouse1","foyer");
    set_open("bedroom door",0);
    set_string("bedroom door","knock","knock");
    set_string("bedroom door","open","%^ORANGE%^The door opens quietly.");
    set_string("bedroom door","close","%^ORANGE%^The door closes quietly.");
    set_door_description("bedroom door","%^ORANGE%^This %^BOLD%^%^WHITE%^polished %^RESET%^%^ORANGE%^wooden door bears a simple iron handle. A small %^BOLD%^%^WHITE%^s%^RESET%^i%^BOLD%^lv%^RESET%^e%^BOLD%^r %^BLACK%^keyhole %^RESET%^%^ORANGE%^is set into the door.%^WHITE%^");
}