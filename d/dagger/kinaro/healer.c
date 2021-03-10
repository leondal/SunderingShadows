#include <std.h>

inherit HEALER;


void create() 
{
    ::create();
    set_terrain(WOOD_BUILDING);
    set_travel(PAVED_ROAD);
    set_light(3);
    set_property("training",1);
    set_indoors(1);
    set_short("%^ORANGE%^M%^BOLD%^%^BLACK%^i%^RESET%^%^ORANGE%^n%^BOLD%^%^BLACK%^e%^RESET%^%^ORANGE%^rs"
			  " %^BOLD%^%^RED%^H%^WHITE%^o%^RED%^s%^WHITE%^p%^RED%^i%^WHITE%^t%^RED%^a%^WHITE%^l%^RESET%^" );
    set_long("This is a small %^BOLD%^%^RED%^hospital%^RESET%^, often needed by some of the many %^ORANGE%^dwarves"
			" %^WHITE%^who get %^RED%^injured %^WHITE%^working the %^ORANGE%^mines%^WHITE%^. Everyone knows how %^M"
			"AGENTA%^dangerous %^WHITE%^it is to %^ORANGE%^mine %^WHITE%^for %^BOLD%^%^CYAN%^precious %^BLACK%^meta"
			"l %^RESET%^and %^YELLOW%^g%^BLUE%^e%^RED%^m%^WHITE%^s%^CYAN%^t%^MAGENTA%^o%^GREEN%^n%^RESET%^%^RED%^e%"
			"^BLUE%^s %^WHITE%^deep in the %^ORANGE%^earth%^WHITE%^, and the evidence is very clear in this well-st"
			"ocked %^CYAN%^infirmary%^WHITE%^. Small %^BOLD%^cots %^RESET%^are placed in rows at the very end of th"
			"is large building, and several have %^GREEN%^occupants %^WHITE%^who have suffered bigger or lesser %^B"
			"OLD%^%^RED%^injuries%^RESET%^. The healer, %^BOLD%^%^BLACK%^Eirik%^RESET%^, is busy directing a few of"
			" his %^BOLD%^trainees %^RESET%^to attend patients as you walk in. One corner of the building is perman"
			"ently reserved for %^BOLD%^surgery%^RESET%^, with bright %^YELLOW%^shining lanterns%^RESET%^, %^BOLD%^"
			"clean linen%^RESET%^, and %^BOLD%^%^CYAN%^sharp surgical instruments%^RESET%^, such as delicate %^BOLD"
			"%^%^BLACK%^knives%^RESET%^, %^CYAN%^scissors %^WHITE%^and %^BOLD%^bone saws%^RESET%^. A whole shelf on"
			" the wall holds %^ORANGE%^wooden splinters%^WHITE%^, and from this it is clear that %^BOLD%^broken bones"
			"%^RESET%^must be one of the biggest %^BOLD%^%^RED%^injuries %^RESET%^in the mine. There is a sign here,"
			" displaying the services the %^BOLD%^%^RED%^hospital %^RESET%^offers.");
    set_smell("default", "%^RESET%^%^ORANGE%^There is a distinctive smell of chemicals mixed with the iron smell of fresh blood.");
    set_listen("default", "%^RESET%^%^GREEN%^A few moans emits from the patients, else the room is silent.");
    set_items( ([ "list" : "Eirik offers these services: \n",
	"cl" : "cure light wounds for 20 gold \n",
	"cs" : "cure serious wounds for 45 gold \n",
	"cc" : "cure critical wounds for 100 gold \n",
	"np" : "neutralize all poison for 150 gold \n",
	"bp" : "buy a healing potion for 30 gold \n",
      ]) );
    set_name("Eirik");
    set_exits( ([
	"west" : "/d/dagger/kinaro/street4"
      ] ));
}

void reset()
{
    ::reset();
    if(!present("eirik"))
	new("/d/dagger/kinaro/mon/eirik.c")->move(TO);
}