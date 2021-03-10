#include <std.h>
#include "../cleric.h"
inherit VAULT;

void create()
{
	::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
	set_property("no teleport",1);
	set_property("indoors",1);
	set_property("light",3);
	set_short("%^BOLD%^The Cleric's Lounge");
	set_long(
	"This room is for clerics to sit down and discuss ideas, especially"+
	" different religious views. The room has several couches and"+
	" chairs in it. On the western wall is a big %^BOLD%^%^BLUE%^blue couch%^RESET%^"+
	" that could seat three people. A large %^GREEN%^green couch%^RESET%^"+
	" is against the north wall, it could fit four people on it. There's"+
	" a %^RED%^burgundy chair%^RESET%^ in the east corner, right"+
	" next to a %^ORANGE%^tan chair%^RESET%^. The floor is covered"+
	" in a %^YELLOW%^cream rug%^RESET%^ that is kept very clean. In"+
	" the center of the room there is a walnut coffee table for people"+
	" to set their food and drinks on, though most just put their"+
	" feet up on it. On the east side of the room is a plain iron door."
	);
	set_smell("default","The room smells of sweet gardenias.");
	set_listen("default","Everything is peacefully quiet right now.");
	set_items(([
	"incense" : "Sticks of incense are in holders on the walls, it"+
	" gives off the sweet scent of gardenias.",
	({"floor","carpet","rug","cream rug"}) : "%^YELLOW%^The floor is"+
	" covered in a thick cream rug that is kept clean.",
	"ceiling" : "The ceiling is flat and made of gray stones.",
	({"blue couch","big blue couch","big couch"}) : "%^BOLD%^%^BLUE%^A large blue"+
	" couch is placed against the back of the western wall. It could"+
	" hold three normal sized people and looks very comfortable. It"+
	" is rather plain, but doesn't look worn and is kept free from"+
	" stains. Followers of Auril, Akadi, and Istishia usually prefer"+
	" this couch.",
	({"green couch","large green couch","large couch"}) : "%^GREEN%^This"+
	" large green couch is placed against the north wall. It can fit"+
	" at least four people on it and looks quite comfortable. This"+
	" couch is the usual favorite of Grumbar, Silvanus, Mielikki and"+
	" other such forest and earth gods and goddesses.",
	"tan chair" : "%^ORANGE%^This tan chair is placed against the southern"+
	" wall in the eastern corner. It is large and completely cushioned."+
	" The arms of the chair look a little worn from so many people"+
	" sitting in it, but it is still in quite good shape.",
	"burgundy chair" : "%^RED%^This deep burgundy chair is thickly"+
	" padded. The back is very high and there is a foot stool that"+
	" you can put your feet up on and stretch out.",
	({"stool","foot stool"}) : "%^RED%^There is a little cushioned foot stool near the"+
	" burgundy chair that people can use.",
	({"table","walnut table","coffee table"}) : "Near the two couches"+
	" is a walnut coffee table. It can be used to set drinks on, though"+
	" most people just put their feet up on it. It has been varnished"+
	" so as to resist most of the dirt and scuffs from shoes.",
	({"door","iron door"}) : "On the eastern wall is a plain iron"+
	" door that leads to the library.",
	]));
	set_exits(([
	"south" : ROOMS+"cleric2",
	"east" : ROOMS+"cleric4",
	]));
	set_door("door",ROOMS+"cleric4","east",0);
	set_string("door","open","The door swings open without a squeak.");
}
