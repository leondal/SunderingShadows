#include <std.h>
#include "../antioch.h"
inherit VAULT;

int found;
int found1;

void create()
{
	::create();
   set_travel(DIRT_ROAD);
   set_terrain(WOOD_BUILDING);
	set_property("indoors",1);
	set_property("light",2);
	set_short("%^GREEN%^Green Room");
	set_long(
	"%^GREEN%^The Green Room\n"+
	"%^BOLD%^This room is decorated entirely in green. The walls are"+
	" covered in forest wall paper and the carpet is the same color"+
	" as that in the hallway outside. The bed is large, though rather"+
	" plain, and the pillows and covering are a deep green shade. It"+
	" is tucked into the far left corner up against the wall, facing"+
	" the doorway. There is a small dresser at the foot of the bed"+
	" with a square mirror attached to the top of it. A wash bowl has"+
	" been set on top of the dresser, it would be quite easy to shave"+
	" there the way the mirror is placed. On the right hand side of"+
	" the room is a little desk with a comfortable looking chair."+
	" Directly across from the door is a little window with green"+
	" curtains. It overlooks the street below and you can hear people"+
	" passing by outside. Oil lamps are fixed around the room and"+
	" give off a good light. The entire rooms smells like mint for"+
	" some reason."
	);
	set_smell("default","This room smells like mint.");
	set_listen("default","You can hear people passing by on the street"+
	" below.");
	set_items(([
	({"carpet","floor"}) : "%^GREEN%^The floor is covered in the"+
	" same thick green carpet as in the hallway outside the room.",
	({"wall","walls","wall paper"}) : "%^GREEN%^The wall paper is"+
	" in a forest pattern with large tree trunks branching out into"+
	" green foliage. It gives the room a secluded feeling.",
	"bed" : "The bed is rather plain, but it is large enough to stretch"+
	" out on. The pillows look comfortable and the covers are a"+
	" %^GREEN%^deep green color%^RESET%^ that matches the rest of the room.",
	"mirror" : "The medium sized square mirror is attached to the"+
	" top of the dresser.",
	({"bowl","wash bowl"}) : "The wash bowl is set on top of the"+
	" dresser and filled with clean looking water. It would be a"+
	" good place to shave if the need arose.",
	"dresser" : "This mahogany dresser has a varnish that makes the"+
	" coloration even darker. It is tucked into the eastern corner"+
	" of the room at the foot of the bed. It isn't very wide but"+
	" reaches about five feet in height. A mirror is fixed to it and"+
	" a wash bowl sits on top of the dresser, and ideal spot for"+
	" shaving.",
	"chair" : "The comfortable chair is padded with green cushions"+
	" and is very large and sturdy looking. It could probably even"+
	" hold an ogre, at least for a time.",
	"desk" : "The desk is made out of mahogany and varnished to give"+
	" it an even darker coloration, matching the dresser. It is quite"+
	" simple, but would be a good place to write on. You can envision"+
	" a bard writing ballads at the desk during a stay at the inn.",
	"window" : "The window overlooks %^ORANGE%^C%^BOLD%^%^BLACK%^e%^BLACK%^d%^BLACK%^a%^RESET%^%^ORANGE%^r %^ORANGE%^s%^BOLD%^%^BLACK%^tre%^RESET%^%^ORANGE%^e%^ORANGE%^t%^RESET%^, you can hear the"+
	" people passing by below. %^GREEN%^Green curtains%^RESET%^ frame"+
	" the window, they can be shut to block out the light.",
	"curtains" : "%^GREEN%^Dark green curtains frame the window. They"+
	" are thick and would probably block out even noon time sun light.",
	({"lamps","lamp","oil lamps","oil lamp"}) : "Oil lamps are fixed"+
	" to the walls around the room, lighting it up.",
	]));
	set_exits(([
	"north" : ROOMS+"inn4",
	]));
	set_door("green door",ROOMS+"inn4","north",0);
	set_search("desk",(:TO,"search_desk":));
	set_search("dresser",(:TO,"search_dresser":));
}

int search_dresser()
{
	if(found) {
		write("You search the dresser thoroughly but can't seem to find"+
		" anything.");
		return 1;
	}
	else {
		write("You search through the dresser and find a bottle of"+
		" cleaning polish in one of the drawers.");
		say(""+TP->query_cap_name()+" searches through the dresser"+
		" and finds something in one of the drawers.");
		found = 1;
		new(OBJ+"polish")->move(TO);
		return 1;
	}
}

int search_desk()
{
	if(found1) {
		write("It looks as though someone has already searched the"+
		" desk and you find nothing of interest.");
		return 1;
	}
	else {
		write("You find a piece of paper with the lyrics of a song"+
		" on it.");
		new(OBJ+"song1")->move(TO);
		found1 = 1;
		return 1;
	}
}
