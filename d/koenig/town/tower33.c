#include <std.h>
inherit ROOM;

void create(){
  	::create();
   set_terrain(WOOD_BUILDING);
   set_travel(PAVED_ROAD);
  	set_property("light", 0);
  	set_property("no teleport",1);
  	set_property("indoors", 1);
  	set_short("A Room Overflowing with Shiny Treasure!");
  	set_long("%^BOLD%^%^YELLOW%^I'm sure this isn't exactly where you intended "+
           	"to go, adventurer, but WOW. It would appear you have walked into "+
           	"the Gentleman's %^RESET%^%^ORANGE%^treasure room%^YELLOW%^! You can see so many things here. "+
           	"There is %^RESET%^%^ORANGE%^gold%^YELLOW%^, %^MAGENTA%^gems%^YELLOW%^, %^RESET%^armor%^YELLOW%^ of fallen "+
           	"foes, %^RESET%^weapons%^YELLOW%^ of the same, and to be honest there is so much "+
           	"here it would take forever and a day to name everything. But "+
           	"you should remember this, adventurer, the little boys time is "+
           	"running out!%^RESET%^\n");
  	set_smell("default", "It smells of riches beyond your wildest dreams.");
  	set_listen("default", "You hear gold clinking.");
    	set_items(([
        	({"gold","gems","armor","weapons"}) : "Upon closer examination "+
        		"you see that this room is a cruel joke.  All of the glorious "+
        		"items contained appear to be fake.  Gold is really painted "+
        		"lead, gems are glass, and the armors and weapons are made of tin."
	]));

  	set_exits( ([
     		"south" : "/d/koenig/town/tower29"
	]) );
}
