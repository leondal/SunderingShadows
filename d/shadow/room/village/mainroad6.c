#include "../shadow.h"
inherit "/d/shadow/room/forest/road1";
inherit VAULT;

void create(){
    ::create();
    set_short("On The Quiet Forest Road");
    set_long("/d/shadow/room/forest/road1"->query_long()+"
%^RED%^A warning sign stands on the side of the road, just in front of the gates to the farmland.%^RESET%^");
    set_items(([
	"road":"A road through the village.",
	"village":"A small village with farmers working.",
	({"warning", "sign"}) : ({"%^RESET%^%^ORANGE%^This large wooden sign has been planted "+
	"firmly in the ground here. The writing on it is barely legible "+
	"but you sense that it is important.%^RESET%^", "%^BOLD%^%^RED%^"+
	"WARNING!! Feyren Farm has fallen to hordes of %^BOLD%^%^BLACK%^"+
	"s%^BOLD%^%^RED%^p%^BOLD%^%^BLACK%^i%^BOLD%^%^RED%^d%^BOLD%^%^BLACK%^"+
	"%^BOLD%^%^RED%^e%^BOLD%^%^BLACK%^r%^BOLD%^%^RED%^s! STAY AWAY!!!"+
	"\n\n%^BOLD%^%^WHITE%^<%^BOLD%^%^YELLOW%^"+
	"OOC%^BOLD%^%^WHITE%^>%^B_CYAN%^%^YELLOW%^ This area is designed "+
	"for adventurers level 10 - 15. Should anything seem out of whack "+
	"please bug report it. Enjoy!%^RESET%^", "wizish"}),
	]));

    set_exits(([
	"west" : FORESTDIR+"road1",
	"east" : VILLAGEDIR+"mainroad5",
	"south" : FEYRENDIR+"rooms/ffout1",
   	]));
	set_door("gate",FEYRENDIR+"rooms/ffout1","south");
	set_door_description("gate","%^RESET%^%^ORANGE%^This gate is composed of a dark "+
	"wood that has badly dilapidated over time. It still functions, but "+
	"barely. It has scrawled into the center of it, "+
	"in a barely legible script, the initials %^BOLD%^%^RED%^FF%^RESET%^%^ORANGE%^.%^RESET%^");

	set_smell("default","You smell fresh air and the odor of baked goods mixed with decay here.");
    	set_listen("default","You hear loud skittering and screeching noises, which almost "+
	"drown out the sound of the other farmers in the area.");
}
