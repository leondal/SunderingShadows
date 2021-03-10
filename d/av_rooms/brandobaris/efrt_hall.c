// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("efrt_hall");
    set_property("indoors",1);
    set_property("light",2);
    set_property("no teleport",1);
    set_terrain("stone building");
    set_travel("slick floor");
    set_climate("temperate");

    set_short("%^ORANGE%^a %^BOLD%^grand %^RESET%^%^ORANGE%^fortress hall%^WHITE%^");

    set_long("%^BOLD%^%^RED%^This %^ORANGE%^o%^MAGENTA%^p%^ORANGE%^ul%^RED%^e%^ORANGE%^nt %^RED%^fortress hall stretches out to nearly seventy yards lengthwise, and is lit by %^ORANGE%^magically g%^RESET%^l%^BOLD%^"
	"o%^ORANGE%^w%^WHITE%^i%^RESET%^n%^YELLOW%^g g%^WHITE%^l%^RESET%^a%^BOLD%^s%^ORANGE%^s o%^WHITE%^r%^RESET%^b%^YELLOW%^s %^RED%^that line the vaulted stone ceiling at regular intervals. The hall is line"
	"d with %^RESET%^%^ORANGE%^warm%^BOLD%^%^RED%^, %^RESET%^%^ORANGE%^g%^BOLD%^o%^RESET%^%^ORANGE%^l%^WHITE%^d%^YELLOW%^e%^RESET%^%^ORANGE%^n-h%^BOLD%^u%^RESET%^e%^ORANGE%^d s%^BOLD%^t%^RESET%^o%^YELLOW%^"
	"n%^RESET%^%^ORANGE%^e t%^WHITE%^i%^ORANGE%^l%^BOLD%^e%^RESET%^%^ORANGE%^s%^BOLD%^%^RED%^, and a long %^RESET%^%^RED%^carpet %^BOLD%^of s%^RESET%^%^RED%^h%^BOLD%^i%^RESET%^%^RED%^m%^BOLD%^m%^RESET%^%^R"
	"ED%^e%^BOLD%^r%^RESET%^%^RED%^in%^BOLD%^g red runs its entire length. Many doors of %^RESET%^white wood %^BOLD%^%^RED%^line the hallway, leading into other rooms within the fortress, but a larger, %^W"
	"HITE%^o%^BLACK%^r%^WHITE%^na%^BLACK%^t%^WHITE%^e door %^RED%^at the end of the hallway seems to stand out, leading to the fortress's innermost chambers.%^RESET%^"
	);

    set_smell("default","
The warm scent of spice permeates the hall.");
    set_listen("default","The noise in here is muffled by the plush carpet underfoot.");

    
set_items(([ 
	({ "door", "ornate door" }) : "%^BOLD%^The double doors at the far end of the hall are larger than the rest, and seem almost ceremonial in nature, crafted from %^ORANGE%^p%^WHITE%^o%^ORANGE%^l%^WHITE%^is%^ORANGE%^h%^WHITE%^e%^ORANGE%^d g%^WHITE%^o%^ORANGE%^ld %^WHITE%^as much as wood, and standing open at all times. It seems to lead into a wider, open room.%^RESET%^",
	({ "floor", "carpet", "rug", "tiles", "stone tiles" }) : "%^ORANGE%^Countless small, %^BOLD%^g%^RESET%^%^ORANGE%^o%^BOLD%^l%^RESET%^%^ORANGE%^d%^WHITE%^e%^YELLOW%^n-h%^RESET%^u%^ORANGE%^e%^BOLD%^d tiles %^RESET%^%^ORANGE%^have been masterfully arranged to form an immaculate, seamless floor. An %^RED%^o%^BOLD%^r%^RESET%^n%^BOLD%^a%^RED%^t%^RESET%^%^RED%^e c%^BOLD%^r%^RESET%^%^RED%^im%^BOLD%^s%^RESET%^%^RED%^on c%^BOLD%^ar%^RESET%^%^RED%^p%^BOLD%^e%^RESET%^%^RED%^t %^ORANGE%^runs along the entire length of the hall, embellished with %^BOLD%^golden trim %^RESET%^%^ORANGE%^and %^BOLD%^i%^RESET%^n%^YELLOW%^t%^RESET%^r%^YELLOW%^i%^RESET%^c%^YELLOW%^a%^RESET%^t%^YELLOW%^e e%^RESET%^m%^YELLOW%^b%^RESET%^r%^YELLOW%^o%^RESET%^i%^YELLOW%^d%^RESET%^e%^BOLD%^r%^ORANGE%^y%^RESET%^%^ORANGE%^.%^WHITE%^",
	({ "orbs", "glass orbs" }) : "%^ORANGE%^Each of these %^BOLD%^y%^RESET%^%^ORANGE%^e%^BOLD%^l%^RESET%^%^ORANGE%^l%^WHITE%^o%^YELLOW%^w-h%^RESET%^u%^ORANGE%^e%^BOLD%^d %^RESET%^%^ORANGE%^glass orbs is about a foot and a half in diameter, and a %^BOLD%^%^GREEN%^v%^RESET%^%^GREEN%^i%^ORANGE%^n%^BOLD%^%^GREEN%^e-l%^RESET%^%^GREEN%^i%^ORANGE%^k%^BOLD%^%^GREEN%^e %^RESET%^%^ORANGE%^pattern has been frosted over its surface. A steady %^BOLD%^g%^RESET%^o%^BOLD%^l%^ORANGE%^d%^RESET%^e%^YELLOW%^n g%^RESET%^l%^BOLD%^o%^ORANGE%^w %^RESET%^%^ORANGE%^emanates somehow from within, casting a %^RED%^warm %^ORANGE%^light throughout the entire room.%^WHITE%^",
	"doors" : "%^BOLD%^The doors here are made from high-quality wood of purest w%^RESET%^h%^BOLD%^i%^RESET%^t%^BOLD%^e embellished with %^ORANGE%^gold%^WHITE%^, and elaborately %^RESET%^e%^BOLD%^n%^RESET%^g%^BOLD%^%^BLACK%^r%^WHITE%^a%^RESET%^v%^BOLD%^%^BLACK%^e%^RESET%^d %^BOLD%^with decorative patterns. Most of the doors seem to lead into side hallways or offices, but a single door near to the courtyard betrays a small draft of %^RESET%^%^CYAN%^cooler %^BOLD%^%^WHITE%^air - it seems this door leads down into the fortress's %^RED%^<%^ORANGE%^dungeon%^RED%^>%^WHITE%^.%^RESET%^",
	]));

    set_exits(([ 
		"west" : "/d/av_rooms/brandobaris/efrt_antechamber",
		"dungeon" : "/d/av_rooms/brandobaris/efrt_dungeon",
		"east" : "/d/av_rooms/brandobaris/efrt_courtyard",
	]));



    set_invis_exits(({ "dungeon" }));

    set_door("inner gates","/d/av_rooms/brandobaris/efrt_courtyard","east");
    set_open("inner gates",0);
    set_string("inner gates","knock","knock");
    set_string("inner gates","open","%^BOLD%^The gates swing open.");
    set_string("inner gates","close","%^BOLD%^The gates swing shut.");
    set_door_description("inner gates","%^BOLD%^This heavy gate is wrought of solid %^BLACK%^steel%^WHITE%^, though it is so finely %^RESET%^%^CYAN%^p%^BOLD%^o%^RESET%^%^CYAN%^l%^BOLD%^is%^RESET%^%^CYAN%^h%^BOLD%^e%^RESET%^%^CYAN%^d %^BOLD%^%^WHITE%^that it might more readily resemble s%^RESET%^i%^BOLD%^l%^CYAN%^v%^RESET%^e%^BOLD%^r in a strong enough light.%^RESET%^");
}