#include <std.h>
#include "../farm.h"
inherit ROOM;

void create(){
   	::create();
   	set_property("indoors",1);
   	set_property("light",1);
	set_property("no sticks",1);
   	set_terrain(CITY);
   	set_travel(PAVED_ROAD);
   	set_name("%^CYAN%^Piaf Huffelmuffin's Kitchen");
   	set_short("%^CYAN%^Piaf Huffelmuffin's Kitchen");
   	set_long("%^CYAN%^This small area is reserved for the "+
			"kitchen.  A %^GREEN%^soapstone%^CYAN%^ sink"+
			" and spigot are mounted into the wall.  The "+
			"sink is currently full of %^ORANGE%^dirty "+
			"crusted dishes%^CYAN%^ which are soaking in "+
			"a %^RESET%^grayish %^CYAN%^water.  Hanging "+
			"%^ORANGE%^copper%^CYAN%^ baskets are filled"+
			" with cheeses, loaves of breads, and some "+
			"fruit and vegetables.  A loud roaring %^BLUE%^"+
			"box%^CYAN%^ with numerous gears and hoses is "+
			"attached to a pump in the kitchen.  The window,"+
			" in the shape of a goose, allows some light to"+
			" filter through it's dirty panes.%^RESET%^\n");
	set_smell("default","The kitchen smell putrid!");
   	set_listen("default","The roaring of the box drowns out any noise.");
  	set_items(([
      	({"basket","fruit","cheese","bread"}) : "%^YELLOW%^The hanging"+
			" copper basket holds a selection of cheeses, breads, "+
			"fruits and vegetables.  Some of the food has spoiled and"+
			" began to sprout greenish mold.",
      	({"sink","dishes","spigot"}) : "%^GREEN%^The gnome sized sink is "+
			"crafted from soapstone and mounted to the wall.  A wooden "+
			"spigot allows for water to be drawn from the stream into the"+
			" sink.  Currently the sink is full of dirty dishes that are "+
			"soaking in a gray tinged water.  No telling how long those "+
			"have been there!",
		({"box","pump","gears","hoses"}) : "%^BLUE%^This strange wooden box"+
			" rest in the kitchen, taking up nearly all of the space.  "+
			"Strange gears and hoses are connected to the box.  One thick"+
			" hose leads from the box to a pump next to it.  Opening the "+
			"box up confronts you with a blast of cold air and lumps of "+
			"frozen meat."
		]));
		set_exits(([ "southwest" : ROOMDIR"foyer",
				 "northwest" : ROOMDIR"bedroom"
		 ]));

}
