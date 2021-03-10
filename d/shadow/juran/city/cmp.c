#include <std.h>
#include "../juran.h"
inherit ROOM;

void create(){
    	::create();
    	set_light(1);
    	set_indoors(1);
//	set_property("no teleport", 1); //removed by Circe 6/18/08 after discussions with others
    	set_short("Luchien's Component Shop");
    	set_terrain(STONE_BUILDING);
    	set_travel(PAVED_ROAD);
    	set_long(
    		"%^BOLD%^This is Luchien's Component Shop.%^RESET%^\nLuchien "+
   "has set up this shop to make a money off fellow magis desire "+
        	"for power.  The shop is very dim and he seems to like it that way.  "+
        	"He sells spell components needed to utilize the "+
        	"countless forms of magic.  Directly to the south an archway "+
   "leads to a conference room with a staircase. <help shop> will "+
        	"give you help on how to use the shop.");
    	set_smell("default","You smell the odor of the bat dung and "+
        	"oil barrels on the wall away from the counter.");
    	set_listen("default","You hear the sounds of small animals "+
        	"locked up in the back of the shop.");
    	set_items( ([
        	({"components","store","counter","shelf","shelves"}):
            	"On the shelves covering the walls behind the "+
            	"main counter, there are all sorts of neatly "+
            	"categorized and ordered components for a large "+
            	"number of spells that you've even heard of.",
        	({"barrels","oil barrels","bat dung barrels","oil",
            	"bat dung"}):"Near the archways, there are a few "+
            	"large barrels of oil and bat dung, no doubt stored "+
            	"in such a place to avoid their stench."
    	]) );
    	set_exits( ([
        	"out" : JROOMS+"mt1"
    	]) );
}
void reset(){
    	::reset();
    	if(!present("luchien"))new(JMONS+"luchien")->move(TO);
}
