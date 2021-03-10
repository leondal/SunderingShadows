// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("efrt_antechamber");
    set_property("indoors",1);
    set_property("light",3);
    set_property("no teleport",1);
    set_terrain("stone building");
    set_travel("slick floor");
    set_climate("temperate");

    set_short("%^ORANGE%^a %^BOLD%^gilded %^RESET%^%^ORANGE%^antechamber%^WHITE%^");

    set_long("%^BOLD%^%^RED%^This is a smaller room, perhaps thirty feet across either way, but it boasts %^WHITE%^o%^RESET%^%^ORANGE%^r%^BOLD%^n%^RESET%^a%^BOLD%^m%^ORANGE%^e%^RESET%^%^ORANGE%^n%^BOLD%^t%^WHITE%^a"
	"%^RESET%^t%^YELLOW%^i%^RESET%^%^ORANGE%^o%^BOLD%^%^WHITE%^n %^RED%^just as opulent as the rest of this fortress. The floor is polished %^WHITE%^w%^RESET%^h%^BOLD%^i%^RESET%^t%^BOLD%^e m%^RESET%^a%^BOL"
	"D%^rb%^RESET%^l%^BOLD%^e f%^RED%^l%^WHITE%^e%^RED%^c%^WHITE%^k%^RED%^e%^WHITE%^d %^RED%^with red which seems to disperse the glow from the %^RESET%^s%^BOLD%^il%^CYAN%^v%^WHITE%^e%^RESET%^r c%^BOLD%^h%"
	"^BLACK%^a%^RESET%^n%^BOLD%^d%^RESET%^el%^BOLD%^%^BLACK%^i%^WHITE%^e%^RESET%^r %^BOLD%^%^RED%^above and light the room evenly. The walls are a muted %^RESET%^%^ORANGE%^o%^BOLD%^r%^RESET%^%^ORANGE%^a%^W"
	"HITE%^n%^YELLOW%^g%^RESET%^%^ORANGE%^e %^BOLD%^%^RED%^in color, bearing numerous %^RESET%^%^ORANGE%^f%^WHITE%^re%^BOLD%^s%^RESET%^c%^ORANGE%^o m%^WHITE%^ur%^BOLD%^a%^RESET%^l%^ORANGE%^s, %^BOLD%^%^RED"
	"%^and large %^WHITE%^c%^CYAN%^r%^WHITE%^y%^CYAN%^s%^RESET%^%^CYAN%^t%^BOLD%^%^WHITE%^a%^CYAN%^l%^WHITE%^li%^CYAN%^n%^WHITE%^e windows %^RED%^are set into them, offering a clear view of the surrounding"
	"s outside. Two large %^RESET%^doors %^BOLD%^%^RED%^stand open to the east, leading out into the hall, while a smaller, %^ORANGE%^g%^WHITE%^i%^RESET%^%^ORANGE%^l%^BOLD%^d%^WHITE%^e%^ORANGE%^d d%^RESET%"
	"^%^ORANGE%^o%^BOLD%^%^WHITE%^o%^ORANGE%^r %^RED%^is set to the south.%^RESET%^"
	);

    set_smell("default","
Clean air drifts in through the opened windows.");
    set_listen("default","The noise you make echoes throughout this chamber.");

    
set_items(([ 
	"floor" : "%^BOLD%^The hard marble floor of this room is white as s%^RESET%^n%^BOLD%^%^CYAN%^o%^WHITE%^w, and it isn't particularly difficult to make out one's own reflection upon its surface. F%^RED%^l%^RESET%^e%^BOLD%^c%^RESET%^k%^BOLD%^s of %^RED%^red %^WHITE%^- perhaps ruby - run throughout the stone, lending a feel of %^RESET%^%^ORANGE%^warmth %^BOLD%^%^WHITE%^to this otherwise cold-looking floor.%^RESET%^",
	({ "window", "windows" }) : "%^BOLD%^%^CYAN%^Two wide %^WHITE%^windows %^CYAN%^are set into the northern wall, offering an unimpeded view of the lands around the fortress. Made from clear and %^RESET%^%^CYAN%^crytsalline glass %^BOLD%^and framed in %^ORANGE%^c%^RESET%^%^ORANGE%^o%^BOLD%^r%^WHITE%^r%^RESET%^%^ORANGE%^u%^BOLD%^g%^RESET%^%^ORANGE%^a%^BOLD%^t%^RESET%^%^ORANGE%^e%^BOLD%^d g%^WHITE%^o%^ORANGE%^ld%^CYAN%^, these windows are just as impressive to look upon as the landscape beyond.%^RESET%^",
	({ "murals", "wall", "walls" }) : "%^ORANGE%^The walls are decorated with a number of elegant f%^WHITE%^r%^BOLD%^e%^RESET%^%^CYAN%^s%^WHITE%^c%^ORANGE%^o m%^WHITE%^u%^CYAN%^r%^BOLD%^%^WHITE%^a%^RESET%^l%^ORANGE%^s, most of them depicting grand scenes of %^BOLD%^%^RED%^w%^RESET%^%^RED%^a%^BOLD%^rf%^RESET%^%^RED%^a%^BOLD%^re %^RESET%^%^ORANGE%^and %^BOLD%^%^CYAN%^m%^WHITE%^a%^CYAN%^g%^WHITE%^i%^CYAN%^c%^RESET%^%^ORANGE%^. The scenes of triumph and destruction seem to portray the duality of both these arts: from their undeniable %^BOLD%^g%^WHITE%^l%^ORANGE%^o%^WHITE%^r%^ORANGE%^i%^WHITE%^e%^ORANGE%^s%^RESET%^%^ORANGE%^, to their unavoidable %^BOLD%^%^MAGENTA%^tragedies%^RESET%^%^ORANGE%^.%^WHITE%^",
	"chandelier" : "%^BOLD%^Hanging from a single metallic thread attached to the room's vaulted ceiling, this 'chandelier' is little more than an intricate s%^RESET%^i%^BOLD%^l%^CYAN%^v%^RESET%^e%^BOLD%^r %^RESET%^l%^BOLD%^a%^RESET%^t%^BOLD%^t%^RESET%^i%^BOLD%^c%^RESET%^e%^BOLD%^, woven from thin wires into an elaborate, hollowed sphere. There is nothing within or attached to the lattice that looks like it might give off light, but some enchantment seems to give the metal itself a powerful %^ORANGE%^glow%^WHITE%^, more than enough to light the room in its entirety.%^RESET%^",
	"doors" : "%^BOLD%^The double doors set into the eastern wall seem almost ceremonial in nature, crafted from %^ORANGE%^p%^WHITE%^o%^ORANGE%^l%^WHITE%^is%^ORANGE%^h%^WHITE%^e%^ORANGE%^d g%^WHITE%^o%^ORANGE%^ld %^WHITE%^as much as wood, and standing open at all times. It seems to lead back into the hall.%^RESET%^",
	]));

    set_exits(([ 
		"south" : "/d/av_rooms/brandobaris/efrt_council",
		"east" : "/d/av_rooms/brandobaris/efrt_hall",
	]));

    set_door("golden door","/d/av_rooms/brandobaris/efrt_council","south");
    set_open("golden door",0);
    set_string("golden door","knock","knock");
    set_string("golden door","open","%^ORANGE%^The door %^BOLD%^g%^WHITE%^l%^ORANGE%^i%^WHITE%^t%^ORANGE%^t%^RED%^e%^WHITE%^r%^ORANGE%^s %^RESET%^%^ORANGE%^in the light as it opens.%^WHITE%^");
    set_string("golden door","close","%^ORANGE%^The door closes with a solemn %^BOLD%^%^WHITE%^-%^BLACK%^thud%^WHITE%^-%^RESET%^%^ORANGE%^.%^WHITE%^");
    set_door_description("golden door","%^YELLOW%^This heavy door is made from %^BLACK%^da%^RESET%^%^ORANGE%^r%^BOLD%^%^BLACK%^k wo%^RESET%^%^ORANGE%^o%^BOLD%^%^BLACK%^d%^ORANGE%^, and e%^RESET%^%^ORANGE%^m%^BOLD%^b%^RESET%^%^ORANGE%^e%^BOLD%^l%^RESET%^%^ORANGE%^l%^BOLD%^i%^RESET%^%^ORANGE%^s%^BOLD%^h%^RESET%^%^ORANGE%^e%^BOLD%^d heavily with g%^RESET%^%^ORANGE%^o%^BOLD%^ld and %^RED%^r%^RESET%^%^RED%^u%^BOLD%^b%^WHITE%^i%^RESET%^%^RED%^e%^BOLD%^s%^ORANGE%^.%^RESET%^");
}