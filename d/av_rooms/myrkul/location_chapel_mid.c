// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("location_chapel_mid");
    set_property("indoors",1);
    set_property("light",1);
    set_property("no teleport",1);
    set_terrain("stone building");
    set_travel("paved road");
    set_climate("temperate");

    set_short("%^RESET%^%^MAGENTA%^Chapel Pews%^RESET%^");

    set_long("%^RESET%^%^GREEN%^You stand in the center of the church underneath a vaulting, arched %^YELLOW%^ceiling%^RESET%^%^GREEN%^ of the chapel. Once this room held sturdy %^ORANGE%^oak pews%^GREEN%^ for the "
	"worship of the faithful. Now, they are cast %^RED%^a%^ORANGE%^s%^RED%^un%^ORANGE%^d%^RED%^er%^GREEN%^ in enormous %^MAGENTA%^piles%^GREEN%^ of %^MAGENTA%^wreckage%^GREEN%^. Some pews look like they mi"
	"ght still bear weight, others are nothing more than %^ORANGE%^kindling%^GREEN%^. Further west is the entry to the church, and in the very front of the chapel is a %^WHITE%^stone altar%^GREEN%^. Alcove"
	"s lie to the north and south, which can be reached by walking between the rows of pews. %^YELLOW%^S%^CYAN%^t%^GREEN%^a%^BLUE%^i%^WHITE%^n%^RED%^e%^MAGENTA%^d %^CYAN%^glass windows%^RESET%^%^GREEN%^ li"
	"ne the chapel walls, splashing streams of %^YELLOW%^light%^GREEN%^ and %^WHITE%^c%^RED%^o%^YELLOW%^l%^RESET%^%^BLUE%^o%^ORANGE%^r%^GREEN%^ throughout the chapel.%^RESET%^ "
	);

    set_smell("default","
%^RESET%^Your adventurer's nose detects the always elegent and refined fragrance of %^BOLD%^%^MAGENTA%^l'%^RED%^e%^MAGENTA%^au de %^RED%^Z%^MAGENTA%^ombie%^RESET%^ in the air.%^RESET%^");
    set_listen("default","%^RESET%^You feel %^BOLD%^%^BLACK%^...organ music%^RESET%^, but no such sound graces your ears.");

    set_search("wreckage","You search the piles of wreckage and come up with wood. Lots and lots of wood.");
    set_search("piles","You search the piles of wreckage and come up with wood. Lots and lots of wood.");
    set_search("pews","You search the piles of wreckage and come up with wood. Lots and lots of wood.");
    
set_items(([ 
	({ "pews", "piles", "wreckage", "kindling", "pile" }) : "The remnants of pews look like something smashed them and the shoved them into piles.",
	({ "alcoves", "alter" }) : "You will have to walk closer to get a better look.",
	({ "floor", "walls" }) : "They look pretty much like rock solid stone. Marble in fact.",
	({ "windows", "stained glass windows", "glass", "stained glass" }) : "%^BOLD%^%^BLACK%^In this %^YELLOW%^S%^CYAN%^t%^GREEN%^a%^BLUE%^i%^WHITE%^n%^RED%^e%^MAGENTA%^d%^CYAN%^ glass%^BLACK%^ you see the %^YELLOW%^death%^BLACK%^ of a %^WHITE%^s%^BLACK%^k%^WHITE%^e%^BLACK%^l%^WHITE%^e%^BLACK%^t%^WHITE%^a%^BLACK%^l figure holding a %^RESET%^%^CYAN%^scythe%^BOLD%^%^BLACK%^, killed by a %^BLUE%^mysterious woman%^BOLD%^%^BLACK%^ with eyes full of %^GREEN%^m%^YELLOW%^a%^BLUE%^g%^YELLOW%^i%^GREEN%^c%^BLACK%^.%^RESET%^",
	"ceiling" : "%^YELLOW%^Directly underneath the ceiling you see an %^WHITE%^enchanted mural%^YELLOW%^ in which %^CYAN%^Angels%^YELLOW%^ and %^RED%^Demons%^YELLOW%^ do endless battle.%^RESET%^",
	]));

    set_exits(([ 
		"west" : "/d/av_rooms/myrkul/location_chapel_entry",
		"north" : "/d/av_rooms/myrkul/location_chapel_nalcove",
		"south" : "/d/av_rooms/myrkul/location_chapel_salcove",
		"east" : "/d/av_rooms/myrkul/location_chapel_altar",
	]));

}