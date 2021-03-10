//New by Circe 1/25/04 to reflect tunnels project
#include <std.h>

inherit ROOM;

void create(){
	::create();
       set_terrain(SCRUB_LANDS);
       set_travel(RUTTED_TRACK);
       set_property("no sticks", 1);
	 set_property("light",2);
	 set_property("indoors",0);
       set_short("A construction site");
	set_long(
@CIRCE
This construction site is just south of the elven registry.  The aged building stands to the north, with a large hole in the back wall covered by what looks to be a tapestry.  Out here, the beginnings of a hole can be seen.  Shovels and piles of dirt are scattered around the site, and it looks as though those who are building it are careful, if not all that neat.  No sign of what this place may be can be seen as of yet, though.
CIRCE
	);
	set_exits(([
           "north" : "/d/tharis/Tharis/reg2"
	]));
	set_items(([
		"hole" : "The hole is quite large, about twelve to fifteen feet in diameter.  "+
               "It is not overly deep yet.",
		({"dirt","piles","shovels"}) : "The dirt forms neat piles around the site, "+
               "braced by various shovels and picks.",
            ({"building","tapestry","wall"}) : "The building to the north has been altered "+
               "to allow access to this site.  A crude tapestry has been placed to cover the hole, "+
               "although it doesn't seem the best way to keep a secret.",
		]));
	set_smell("default","A rich earthy scent fills the air, masking the rancid scent from the north.");
	set_listen("default","You can hear the sound of voices from the north.");
      set_pre_exit_functions(({"north"}),({"GoThroughDoor"}));
}

int GoThroughDoor(){
   if(member_array("south","/d/tharis/Tharis/reg2"->query_exits()) == -1){
      tell_room("/d/tharis/Tharis/reg2","The tapestry on the back wall lifts suddenly.");
      return 1;
   }
   return 1;
}

/*
//This query weather is for a plot.  Remove when no longer needed.
//~Circe~ 7/15/08
query_weather() { return "%^BOLD%^%^BLACK%^Stormclouds %^CYAN%^roll in the %^BLUE%^sky%^CYAN%^, shedding a steady downpour of %^BLUE%^rain%^CYAN%^.%^RESET%^"; }
*/