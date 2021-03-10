#include <std.h>
#include "../theater.h"
inherit ROOM;

	void create(){
   	::create();
   	set_property("indoors",1);
   	set_property("light",3);
	set_property("no sticks",1);
	set_property("no teleport",1);
   	set_terrain(CITY);
   	set_travel(PAVED_ROAD);
   	set_name("%^RED%^Desert Sun Theater - Foyer");
   	set_short("%^RED%^Desert Sun Theater - Foyer");
   	set_long("%^ORANGE%^The foyer of The Desert Sun"+
		" theater opens before you.  This large room once"+
		" served as the gathering spot for the audience, before"+
		" taking their seats.  Plush %^RED%^red velvet%^ORANGE%^"+
		" carpeting covers the floor, with a %^YELLOW%^sunburst"+
		"%^RESET%^%^ORANGE%^ pattern burnt into the fabric.  Three rounded"+
		" archways can be seen from within the foyer, two leading "+
		"to the north and south and one to the west.  The %^YELLOW%^"+
		"chestnut%^RESET%^%^ORANGE%^ arches are supported by spiraling"+
		" %^YELLOW%^gold leaf%^RESET%^%^ORANGE%^ columns.  "+
		"Tiled %^YELLOW%^golden%^RESET%^%^ORANGE%^ panels cover the"+
		" ceiling, helping to reflect the light of a large %^BOLD%^%^WHITE%^"+
		"chandelier%^RESET%^%^ORANGE%^ hanging from the center. The walls of"+
		" the foyer have been painted a golden orange color, which brings "+
		"out the fiery tones of this room.  %^YELLOW%^Chestnut%^RESET%^%^ORANGE%^"+
		" crown molding carved to look like musical instruments intersects "+
		"the ceiling and walls.  Even with the faded colors and the large"+
		" amounts of %^RESET%^dust%^ORANGE%^, this room still retains a "+
		"lavish opulence.\n");
   	set_smell("default","%^RED%^A stale musty scent hangs in the air.");
   	set_listen("default","%^BOLD%^%^MAGENTA%^A bewitching melody can be heard.");
  	set_items(([
      	({"carpet","floor"}) : "%^RED%^Dark crimson velvet carpet"+
	" covers the floor of the theater.  A%^YELLOW%^ sunburst%^RESET%^"+
	"%^RED%^ pattern has been burnt into the velvet, gilded with "+
	"%^YELLOW%^metallic gold%^RESET%^%^RED%^ threads.  The carpet "+
	"seem threadbare and bald in some sections.",
      	({"ceiling","tiles","chandelier"}) : "%^YELLOW%^Gold tiles"+
	" cover the ceiling of the theater.  Their %^RESET%^%^ORANGE%^"+
	"antiqued%^BOLD%^ muted finish keeps them from reflecting too "+
	"much light.  Each gold panel features a convex sunburst design"+
	" around an intricate border of leaves and flowers.  In the "+
	"center of the room a two tiered %^WHITE%^crystal chandelier"+
	"%^YELLOW%^ hangs.  Orbs of%^MAGENTA%^ rose%^YELLOW%^ colored"+
	" lights are placed within crystal chambers, casting a rosy"+
	" glow around the room.  Some of the crystal chambers are%^BLACK%^"+
	" dark%^YELLOW%^, showing that their light orbs have disappeared.",
		({"molding","crown molding"}) : "%^ORANGE%^Carved from "+
	"golden chestnut wood, the crown molding of the foyer shows a "+
	"variety of musical instruments, some that seem familiar and "+
	"others that look exotic and strange.",
		({"arches","pillars","columns"}) : "%^ORANGE%^Wide rounded"+
	" arches lead into the theater and to the stairs that access the"+
	" mezzanine levels.  The golden chestnut wood has been polished "+
	"to a smooth finish.  Thick spiraling columns covered with "+
	"%^YELLOW%^gold leafing%^RESET%^%^ORANGE%^ support the arches, "+
	"adding a majestic touch to the entryways.",
	]));
	set_exits(([ "west" : ROOMDIR"dso1",
			 "north" : ROOMDIR"stairs1",
			 "south" : ROOMDIR"stairs4",
			 "outside" : ROOMDIR"theater1",
	]));
	}
 
