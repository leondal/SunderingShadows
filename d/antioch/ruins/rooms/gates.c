#include <std.h>
#include "../ruins.h"
inherit ROOM;

void create()
{
	::create();
   set_terrain(RUINS);
   set_travel(DIRT_ROAD);
	set_property("indoors",0);
	set_property("light",2);
	set_short("Crumbled Gates");
	set_long(
	"%^BOLD%^%^BLACK%^Crumbled Gates%^RESET%^
%^ORANGE%^The %^BOLD%^%^BLACK%^g%^RESET%^%^CYAN%^ates%^ORANGE%^ before you once lead into the magnificent city of Antioch. Now they lay in %^CYAN%^rui%^BOLD%^%^BLACK%^n%^BLACK%^s%^RESET%^%^CYAN%^.%^ORANGE%^ The %^WHITE%^st%^CYAN%^e%^WHITE%^el%^ORANGE%^ of the large gates has been melted by incredible heat, and the %^CYAN%^wo%^BOLD%^%^BLACK%^o%^BLACK%^d%^RESET%^%^ORANGE%^ has been splintered and charred. The huge stone wall that once surrounded the city has toppled to the ground, along with the %^CYAN%^towe%^BOLD%^%^BLACK%^r%^BLACK%^s%^RESET%^%^ORANGE%^ that once stood on either side of the gates. The towers and %^BOLD%^%^BLACK%^w%^RESET%^%^CYAN%^alls%^ORANGE%^ could not protect the citizens from their enemies, and now all that is left of the once wonderous town is a pile of ruins. A small path to the west leads to the new city of Antioch."
	);
	set_smell("default","The air has a musty quality to it.");
	set_listen("default","Everything is strangely still.");
	set_items(([
	"ruins" : "The ruins of Antioch lay before you, crumbled and charred. In"+
	" the far distance you can see the remains of what once was a large tower.",
	({"tower","towers"}) : "Stone towers on either side of the gates have"+
	" been blasted and demolished. So much for their protection.",
	({"wall","stone wall"}) : "The stone walls that once surrounded the large"+
	" city, protecting it from danger, have toppled over and fallen onto the"+
	" streets.",
	"gates" : "The large gates that once lead into the city of Antioch have"+
	" been blasted and burnt and have now fallen to the ground.",
	"wood" : "The wood of the gates has been splintered and partially charred.",
	"steel" : "The steel the gates were made of has been melted, only incredible"+
	" heat could have done such a thing.",
	]));
	set_exits(([
	"west" : AROOMS+"trail1",
	"north" : ROOMS+"fountain",
	"east" : ROOMS+"path1",
	"south" : "/d/antioch/wild/mount/pass_6",
	]));
	new(OBJ+"sign")->move(TO);
   set_pre_exit_functions(({"north"}),({"GoThroughDoor"}));
}

int GoThroughDoor()
{
   if(TP->query_lowest_level() < 15) {
   tell_object(TP,"You are not strong enough to venture further.");
      return 0;
   }
   return 1;
}
