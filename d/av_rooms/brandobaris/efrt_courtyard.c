// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("efrt_courtyard");
    set_property("indoors",0);
    set_property("light",2);
    set_property("no teleport",1);
    set_terrain("garden");
    set_travel("paved road");
    set_climate("temperate");

    set_short("%^ORANGE%^a %^BOLD%^spectacular %^RESET%^%^ORANGE%^courtyard%^WHITE%^");

    set_long("%^ORANGE%^Impeccable %^WHITE%^stonework %^ORANGE%^and carefully nurtured %^GREEN%^plant life %^ORANGE%^blend seamlessly together within this expansive circular courtyard to create a breathtaking tapes"
	"try of rich golds and verdant greens. A large %^CYAN%^r%^BOLD%^e%^RESET%^%^CYAN%^f%^BOLD%^l%^RESET%^%^CYAN%^ec%^BOLD%^t%^RESET%^%^CYAN%^i%^BOLD%^n%^RESET%^%^CYAN%^g p%^BOLD%^o%^RESET%^%^CYAN%^ol%^ORAN"
	"GE%^, edged by a ring of low hedges, sits in the center of the smoothed %^BOLD%^%^BLACK%^c%^RESET%^o%^BOLD%^%^BLACK%^bb%^RESET%^%^ORANGE%^l%^BOLD%^%^BLACK%^est%^RESET%^o%^BOLD%^%^BLACK%^ne %^RESET%^%^"
	"ORANGE%^expanse, from which a majestic %^BOLD%^%^WHITE%^g%^ORANGE%^i%^WHITE%^ld%^ORANGE%^e%^WHITE%^d f%^ORANGE%^o%^WHITE%^un%^ORANGE%^t%^WHITE%^a%^ORANGE%^i%^WHITE%^n %^RESET%^%^ORANGE%^emerges, a %^B"
	"OLD%^golden statue %^RESET%^%^ORANGE%^set atop it. High %^WHITE%^white walls %^ORANGE%^encircle the entirety of this area, and large %^BOLD%^%^BLACK%^gates %^RESET%^%^ORANGE%^set into the eastern and "
	"western sides allow passage both out of and further into the fortress. %^WHITE%^"
	);

    set_smell("default","
The soft scent of the surrounding flora wafts through the area.");
    set_listen("default","Water from the fountain splashes tranquilly into the pool below.");

    
set_items(([ 
	({ "walls", "gates", "gate" }) : "%^BOLD%^The high walls rise up over thirty feet into the air, and are wrought of sm%^RESET%^oo%^BOLD%^th w%^RESET%^h%^BOLD%^i%^RESET%^t%^BOLD%^e s%^RESET%^t%^BOLD%^o%^RESET%^n%^BOLD%^e. Two large %^BLACK%^g%^RESET%^a%^BOLD%^%^BLACK%^t%^RESET%^e%^BOLD%^%^BLACK%^s %^WHITE%^are set into the eastern and western portions of the wall, and these seem to be the only exits into and out of this place. A small, easily-overlooked set of %^RED%^<%^ORANGE%^stairs%^RED%^> %^WHITE%^is set into each gatehouse, allowing access to the top of the walls.%^RESET%^",
	({ "pool", "statue", "fountain", "hedges", "center" }) : "%^CYAN%^A wide and shallow %^BOLD%^reflecting pool %^RESET%^%^CYAN%^is the centerpiece of this elaborate courtyard, surrounded on all sides by a ring of %^GREEN%^verdant %^CYAN%^and %^GREEN%^immaculately trimmed hedges%^CYAN%^. %^BOLD%^Water %^RESET%^%^CYAN%^pours steadily into the pool from a %^BOLD%^%^WHITE%^g%^ORANGE%^i%^WHITE%^ld%^ORANGE%^e%^WHITE%^d m%^ORANGE%^a%^WHITE%^r%^RESET%^b%^BOLD%^le f%^RESET%^o%^BOLD%^u%^CYAN%^n%^RESET%^t%^BOLD%^a%^RESET%^i%^BOLD%^n%^RESET%^%^CYAN%^, carved into the likeness of an %^BOLD%^%^WHITE%^el%^CYAN%^e%^WHITE%^gant %^RESET%^%^CYAN%^and %^GREEN%^serpentine %^BOLD%^%^WHITE%^dragon%^RESET%^%^CYAN%^. A smaller %^YELLOW%^g%^RESET%^%^ORANGE%^o%^BOLD%^ld%^RESET%^%^ORANGE%^e%^BOLD%^n s%^RESET%^%^ORANGE%^t%^BOLD%^at%^RESET%^%^ORANGE%^u%^BOLD%^e %^RESET%^%^CYAN%^is set atop the fountain, depicting several slender %^BOLD%^%^GREEN%^e%^RESET%^l%^BOLD%^%^GREEN%^v%^RESET%^e%^BOLD%^%^GREEN%^n %^RESET%^%^CYAN%^figures gazing down upon the waters in stoic contemplation.%^WHITE%^",
	({ "courtyard", "ground", "cobblestone" }) : "%^ORANGE%^The courtyard is paved neatly with flat, natural stones, their colors ranging from %^RED%^warm %^BOLD%^reds %^RESET%^%^ORANGE%^to p%^WHITE%^a%^ORANGE%^le %^BOLD%^gold%^RESET%^%^ORANGE%^, with the occasional accent of %^WHITE%^gray %^ORANGE%^mixed in to create a subtle pattern.%^WHITE%^",
	]));

    set_exits(([ 
		"stairs" : "/d/av_rooms/brandobaris/efrt_walls",
		"west" : "/d/av_rooms/brandobaris/efrt_hall",
		"east" : "/d/av_rooms/brandobaris/efrt_entrance",
	]));



    set_invis_exits(({ "stairs" }));

    set_door("inner gates","/d/av_rooms/brandobaris/efrt_hall","west");
    set_open("inner gates",0);
    set_string("inner gates","knock","knock");
    set_string("inner gates","open","%^BOLD%^The gates swing open.");
    set_string("inner gates","close","%^BOLD%^The gates swing shut.");
    set_door_description("inner gates","%^BOLD%^This heavy gate is wrought of solid %^BLACK%^steel%^WHITE%^, though it is so finely %^RESET%^%^CYAN%^p%^BOLD%^o%^RESET%^%^CYAN%^l%^BOLD%^is%^RESET%^%^CYAN%^h%^BOLD%^e%^RESET%^%^CYAN%^d %^BOLD%^%^WHITE%^that it might more readily resemble s%^RESET%^i%^BOLD%^l%^CYAN%^v%^RESET%^e%^BOLD%^r in a strong enough light.%^RESET%^");
    set_door("steel gates","/d/av_rooms/brandobaris/efrt_entrance","east");
    set_open("steel gates",0);
    set_string("steel gates","knock","knock");
    set_string("steel gates","open","%^BOLD%^The steel gates open in surprising silence.");
    set_string("steel gates","close","%^BOLD%^The steel gates close in surprising silence.");
    set_door_description("steel gates","%^BOLD%^This heavy gate is wrought of solid %^BLACK%^steel%^WHITE%^, though it is so finely %^RESET%^%^CYAN%^p%^BOLD%^o%^RESET%^%^CYAN%^l%^BOLD%^is%^RESET%^%^CYAN%^h%^BOLD%^e%^RESET%^%^CYAN%^d %^BOLD%^%^WHITE%^that it might more readily resemble s%^RESET%^i%^BOLD%^l%^CYAN%^v%^RESET%^e%^BOLD%^r in a strong enough light.%^RESET%^");
}