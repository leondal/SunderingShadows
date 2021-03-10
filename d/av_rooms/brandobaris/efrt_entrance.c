// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("efrt_entrance");
    set_property("indoors",0);
    set_property("light",0);
    set_property("no teleport",1);
    set_terrain("city");
    set_travel("paved road");
    set_climate("temperate");

    set_short("%^ORANGE%^an entrance to a %^BOLD%^spectacular %^RESET%^%^ORANGE%^fortress%^WHITE%^");

    set_long("%^ORANGE%^A majestic %^BOLD%^%^BLACK%^f%^RESET%^o%^BOLD%^%^BLACK%^r%^RESET%^t%^BOLD%^%^BLACK%^r%^RESET%^e%^BOLD%^s%^BLACK%^s %^RESET%^%^ORANGE%^rises up before you, its %^BOLD%^%^WHITE%^h%^RESET%^i%^B"
	"OLD%^gh w%^RESET%^h%^BOLD%^i%^RESET%^t%^BOLD%^e w%^RESET%^a%^BOLD%^l%^RESET%^l%^BOLD%^s %^RESET%^%^ORANGE%^easily exceeding thirty feet in height and proffering an appearance of %^BOLD%^%^BLACK%^nigh-"
	"impenetrability %^RESET%^%^ORANGE%^against any who would attempt to assail them. A well-paved c%^WHITE%^o%^BOLD%^%^BLACK%^b%^RESET%^%^ORANGE%^b%^WHITE%^l%^ORANGE%^e%^WHITE%^s%^ORANGE%^t%^BOLD%^%^BLACK"
	"%^o%^RESET%^n%^ORANGE%^e path leads up to a %^BOLD%^%^WHITE%^gl%^CYAN%^e%^WHITE%^a%^RESET%^m%^BOLD%^ing%^RESET%^%^ORANGE%^, %^BOLD%^%^WHITE%^s%^RESET%^t%^BOLD%^%^BLACK%^e%^RESET%^e%^BOLD%^l g%^RESET%^"
	"a%^BOLD%^te %^RESET%^%^ORANGE%^set into the wall, seeming to offer passage into the fortress proper, and rows of %^BOLD%^golden statues%^RESET%^%^ORANGE%^, crafted in the likeness of various elven war"
	"riors stand watch before it.%^WHITE%^"
	);

    set_smell("default","
The faint scent of various flora lingers in the air.");
    set_listen("default","Echoes of those within the fortress reach your ears.");

    
set_items(([ 
	({ "walls", "wall" }) : "%^BOLD%^Smooth walls of w%^RESET%^h%^BOLD%^i%^RESET%^t%^BOLD%^e s%^RESET%^t%^BOLD%^o%^RESET%^n%^BOLD%^e rise up to well over thirty feet in height before you. The walls seem to be in almost %^CYAN%^pristine %^WHITE%^condition, almost g%^RESET%^l%^BOLD%^o%^RESET%^w%^BOLD%^i%^RESET%^n%^BOLD%^g where the light hits them, and utterly free of any scuffs or debris that might otherwise mar its surface.%^RESET%^",
	({ "path", "cobblestone" }) : "%^ORANGE%^This flat, carefully paved path is about twenty feet across, and paved with %^WHITE%^m%^ORANGE%^u%^BOLD%^%^WHITE%^l%^BLACK%^t%^RESET%^%^ORANGE%^i%^WHITE%^c%^BOLD%^o%^BLACK%^l%^RESET%^%^ORANGE%^o%^BOLD%^%^WHITE%^r%^BLACK%^e%^RESET%^d %^ORANGE%^flat natural stones.%^WHITE%^",
	({ "statues", "statue" }) : "%^YELLOW%^Set upon a base of %^RESET%^solid stone%^YELLOW%^, these golden statues tower into the air twelve feet above the ground. The statues depict an array of dignified e%^RESET%^%^ORANGE%^l%^BOLD%^v%^RESET%^%^ORANGE%^e%^BOLD%^n w%^RESET%^%^ORANGE%^a%^BOLD%^r%^RESET%^%^ORANGE%^r%^BOLD%^i%^RESET%^%^ORANGE%^o%^BOLD%^rs standing at attention, a %^WHITE%^longsword %^ORANGE%^sheathed at their side and a heavy %^RESET%^%^ORANGE%^shield %^BOLD%^in hand. Their heads held high, they look off into the distance opposite the fortress with steeled expressions.%^RESET%^",
	]));

    set_exits(([ 
		"west" : "/d/av_rooms/brandobaris/efrt_courtyard",
	]));

    set_door("steel gates","/d/av_rooms/brandobaris/efrt_courtyard","west");
    set_open("steel gates",0);
    set_string("steel gates","knock","knock");
    set_string("steel gates","open","%^BOLD%^The steel gates open in surprising silence.");
    set_string("steel gates","close","%^BOLD%^The steel gates close in surprising silence.");
    set_door_description("steel gates","%^BOLD%^This heavy gate is wrought of solid %^BLACK%^steel%^WHITE%^, though it is so finely %^RESET%^%^CYAN%^p%^BOLD%^o%^RESET%^%^CYAN%^l%^BOLD%^is%^RESET%^%^CYAN%^h%^BOLD%^e%^RESET%^%^CYAN%^d %^BOLD%^%^WHITE%^that it might more readily resemble s%^RESET%^i%^BOLD%^l%^CYAN%^v%^RESET%^e%^BOLD%^r in a strong enough light.%^RESET%^");
}