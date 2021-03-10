#include <std.h>
#include "../../newbie.h"
inherit ROOM;

void create()
{
	::create();
	set_property("indoors",1);
	set_short("The %^ORANGE%^Bronze%^RESET%^ Warrior");
	set_terrain(STONE_BUILDING);
	set_travel(PAVED_ROAD);
	set_long(
	"You're standing in the Bronze Warrior armor shop. There are polished"+
	" suits of all sorts of armors hanging on the walls and on wooden display"+
	" stands. There is everything from gleaming fullplate, to shining bronze"+
	" platemail. Shields, helmets, leather armors, and robes can also be found"+
	" about the shop. This is the place for young adventurers to outfit"+
	" themselves before venturing into battle. The armor here can help protect"+
	" you in combat. It is best to pick what suits you the most."+
	"\n\n%^BOLD%^<help shop> will provide a list of shop commands"

	);
	set_property("light",2);
	set_smell("default","The smell of oils from the different armors is a bit"+
	" strange to you, but not unpleasant.");
	set_listen("default","You can hear the villagers walking by on the street outside."); 
	set_items(([
	({"armors","display","wooden display"}) : "Various armors are displayed"+
	" about the shop. There are many wooden displays set up from which entire"+
	" suits of armor are hung, including helmets and shields. Each piece is"+
	" carefully polished or well oiled.",
	({"shields","helmets","leather armors","robes","equipment"}) : "All sorts"+
	" of adventuring equipment can be found about the store. Pick out what"+
	" suits you best. If you want to look at something closer, the shop keeper"+
	" is always willing to <show> it to you.",
	]));
	set_exits(([
	"south" : MAINTOWN"estreet2",
	]));
}

void reset(){
   ::reset();
   if(!present("nicculis"))   find_object_or_load(MON"nicculis")->move(TO);
}
