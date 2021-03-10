// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("efrt_dungeon");
    set_property("indoors",1);
    set_property("light",2);
    set_property("no teleport",1);
    set_terrain("stone building");
    set_travel("slick floor");
    set_climate("temperate");

    set_short("%^ORANGE%^within a %^BOLD%^fortress %^RESET%^%^ORANGE%^dungeon%^WHITE%^");

    set_long("%^ORANGE%^A long winding staircase leads down into this underground dungeon. Surprisingly well lit by rows of %^BOLD%^t%^RESET%^%^RED%^o%^BOLD%^r%^RESET%^%^ORANGE%^c%^BOLD%^%^RED%^h%^RESET%^%^RED%^e%^"
	"YELLOW%^s%^RESET%^%^ORANGE%^, the %^BOLD%^%^BLACK%^walls %^RESET%^%^ORANGE%^and %^BOLD%^%^BLACK%^floor %^RESET%^%^ORANGE%^are made of %^BOLD%^%^BLACK%^s%^RESET%^m%^BOLD%^%^BLACK%^o%^RESET%^ot%^BOLD%^%"
	"^BLACK%^h%^RESET%^e%^BOLD%^%^BLACK%^d g%^RESET%^r%^BOLD%^%^BLACK%^ay s%^RESET%^t%^BOLD%^%^BLACK%^o%^RESET%^n%^BOLD%^%^BLACK%^e%^RESET%^%^ORANGE%^, and it the room still retains traces of the %^RED%^wa"
	"rmth %^ORANGE%^that wafts in from above. Two hallways extend to the east and west, lined with %^BOLD%^%^BLACK%^barred doors %^RESET%^%^ORANGE%^that lead into different small, but clean cells. Directly"
	" opposite the stairway, next to a simple %^WHITE%^desk%^ORANGE%^, is a larger door that appears to lead into a large holding cell.%^WHITE%^"
	);

    set_smell("default","
The smell of damp earth is strong here.");
    set_listen("default","Sounds from the fortress echo down from above.");

    
set_items(([ 
	({ "stairs", "staircase" }) : "%^BOLD%^%^BLACK%^A long and winding staircase of %^RESET%^%^ORANGE%^wood %^BOLD%^%^BLACK%^descends quite a ways from the hall above to reach this dungeon.%^RESET%^",
	({ "cells", "cell" }) : "%^ORANGE%^Each of the cells contains a sparse, but adequate assortment of furniture, making a stay here slightly more comfortable than in an average prison. A small %^GREEN%^bed %^ORANGE%^is provided, as is a simple %^WHITE%^desk %^ORANGE%^and %^BOLD%^%^WHITE%^chair%^RESET%^%^ORANGE%^. A large %^CYAN%^c%^ORANGE%^e%^CYAN%^ra%^ORANGE%^m%^CYAN%^ic b%^ORANGE%^o%^CYAN%^wl %^ORANGE%^of %^CYAN%^water %^ORANGE%^is set near each of the cell doors.%^WHITE%^",
	({ "walls", "wall", "floor" }) : "%^BOLD%^%^BLACK%^The dungeon seems to be well maintained, with the %^RESET%^gray stone %^BOLD%^%^BLACK%^making up the walls and floor doing a fair job of keeping the %^RESET%^%^CYAN%^moisture %^BOLD%^%^BLACK%^from the surrounding earth out, and holding the heat of the surrounding %^RED%^torches%^BLACK%^.%^RESET%^",
	"torches" : "%^ORANGE%^Set into brackets in regular intervals along the dungeon halls, these simple %^BOLD%^%^RED%^t%^ORANGE%^o%^BLACK%^r%^ORANGE%^c%^BLACK%^h%^ORANGE%^e%^RED%^s %^RESET%^%^ORANGE%^seem to hold some enchantment that prevents them from ever burning out, while still lending their %^RED%^warmth %^ORANGE%^to the area.%^WHITE%^",
	"desk" : "%^ORANGE%^A simple w%^WHITE%^o%^ORANGE%^o%^GREEN%^d%^WHITE%^e%^ORANGE%^n d%^WHITE%^e%^ORANGE%^sk and %^WHITE%^chair %^ORANGE%^is placed before the large holding cell, unadorned but for an assortment of drawers and several pieces of stationary atop it. Most likely the desk is for the use of the fortress jailer, to keep track of the prisoners here.%^WHITE%^",
	]));

    set_exits(([ 
		"south" : "/d/av_rooms/brandobaris/efrt_cell",
		"up" : "/d/av_rooms/brandobaris/efrt_hall",
	]));

    set_door("cell door","/d/av_rooms/brandobaris/efrt_cell","south","cell key","cell lock");
    add_lock("cell door","cell key","cell lock","A lock set within the cell door.");
    set_locked("cell door",1,"cell lock");
    lock_difficulty("cell door",-60,"cell lock");
    set_open("cell door",0);
    set_string("cell door","knock","knock");
    set_string("cell door","open","%^BOLD%^%^BLACK%^The cell door %^RESET%^c%^BOLD%^r%^RESET%^e%^ORANGE%^a%^BOLD%^%^WHITE%^k%^RESET%^s %^BOLD%^%^BLACK%^as it opens.%^RESET%^");
    set_string("cell door","close","%^BOLD%^%^BLACK%^The cell door %^RESET%^c%^BOLD%^r%^RESET%^e%^ORANGE%^a%^BOLD%^%^WHITE%^k%^RESET%^s %^BOLD%^%^BLACK%^as it closes.%^RESET%^");
    set_door_description("cell door","%^BOLD%^%^BLACK%^This large cell door is wrought from black steel, and looks as if it would be difficult to force open.");
}