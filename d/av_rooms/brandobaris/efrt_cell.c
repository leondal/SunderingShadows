// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("efrt_cell");
    set_property("indoors",1);
    set_property("light",2);
    set_property("no teleport",1);
    set_terrain("stone building");
    set_travel("slick floor");
    set_climate("temperate");

    set_short("%^ORANGE%^within a %^BOLD%^large %^RESET%^%^ORANGE%^cell%^WHITE%^");

    set_long("%^BOLD%^%^BLACK%^You are within a large holding cell, its walls and floor made of well-constructed, g%^RESET%^r%^BOLD%^a%^BLACK%^y s%^RESET%^t%^BOLD%^%^BLACK%^o%^RESET%^n%^BOLD%^%^BLACK%^e. Although t"
	"he %^RESET%^%^CYAN%^damp %^BOLD%^%^BLACK%^of the earth still seems to seep through the walls in places, the air here is %^RESET%^%^RED%^warm%^BOLD%^%^BLACK%^, and somehow the area is lit comfortably, "
	"though you cannot discern it's source. Apparently intended to hold several prisoners at once, an assortment of %^ORANGE%^furniture %^BLACK%^can be found against the back wall of the cell - a number of"
	" soft %^RESET%^%^MAGENTA%^mats %^BOLD%^%^BLACK%^can be found in the corner, while a simple %^RESET%^%^ORANGE%^w%^WHITE%^oo%^ORANGE%^d%^WHITE%^e%^ORANGE%^n %^WHITE%^table %^BOLD%^%^BLACK%^with %^RESET%"
	"^chairs %^BOLD%^%^BLACK%^is chained to the floor a short distance away. The only way out of here seems to be the large %^RESET%^%^CYAN%^cell door %^BOLD%^%^BLACK%^set into the northern wall, leading b"
	"ack out into the dungeon hallway.%^RESET%^"
	);

    set_smell("default","
The smell of damp earth is strong here.");
    set_listen("default","Sounds from the fortress echo down from above.");

    
set_items(([ 
	({ "furniture", "table", "chair", "chairs", "mats", "mat" }) : "%^ORANGE%^The furniture here is sparse, but still of a higher quality than might be found in an average prison. Several %^BOLD%^%^MAGENTA%^s%^RESET%^%^MAGENTA%^o%^BOLD%^ft mats %^RESET%^%^ORANGE%^are provided in one corner, which, while far from luxurious, look more comfortable to rest upon than the stone floor. A %^BOLD%^table %^RESET%^%^ORANGE%^and %^WHITE%^c%^ORANGE%^h%^WHITE%^ai%^ORANGE%^r%^WHITE%^s %^ORANGE%^lie a short distance away, %^BOLD%^%^BLACK%^c%^RESET%^h%^BOLD%^%^BLACK%^a%^RESET%^i%^BOLD%^%^BLACK%^n%^RESET%^e%^BOLD%^%^BLACK%^d %^RESET%^%^ORANGE%^to the floor so as to prevent them from being easily moved, but sufficient to rest or take meals at.%^WHITE%^",
	({ "walls", "wall", "floor" }) : "%^BOLD%^%^BLACK%^The dungeon seems to be well maintained, with the %^RESET%^gray stone %^BOLD%^%^BLACK%^making up the walls and floor doing a fair job of keeping the %^RESET%^%^CYAN%^moisture %^BOLD%^%^BLACK%^from the surrounding earth out.%^RESET%^",
	]));

    set_exits(([ 
		"north" : "/d/av_rooms/brandobaris/efrt_dungeon",
	]));

    set_door("cell door","/d/av_rooms/brandobaris/efrt_dungeon","north","cell key","cell lock");
    add_lock("cell door","cell key","cell lock","A lock set within the cell door.");
    set_locked("cell door",1,"cell lock");
    lock_difficulty("cell door",-60,"cell lock");
    set_open("cell door",0);
    set_string("cell door","knock","knock");
    set_string("cell door","open","%^BOLD%^%^BLACK%^The cell door %^RESET%^c%^BOLD%^r%^RESET%^e%^ORANGE%^a%^BOLD%^%^WHITE%^k%^RESET%^s %^BOLD%^%^BLACK%^as it opens.%^RESET%^");
    set_string("cell door","close","%^BOLD%^%^BLACK%^The cell door %^RESET%^c%^BOLD%^r%^RESET%^e%^ORANGE%^a%^BOLD%^%^WHITE%^k%^RESET%^s %^BOLD%^%^BLACK%^as it closes.%^RESET%^");
    set_door_description("cell door","%^BOLD%^%^BLACK%^This large cell door is wrought from black steel, and looks as if it would be difficult to force open.");
}