//Coded by Diego//

#include <std.h>
#include "../jdrow.h"

inherit VAULT;

void set_rope(int rope);

int rope_present;

void create(){
 	::create();
   set_name("master bedroom");
   set_short("Master's Bedroom");
   set_long(
   	"%^BOLD%^%^CYAN%^"+
   	"The room is the most opulent and decadently furnished room of all "+
   	"the bedrooms that you have seen so far.  The bed is huge and firm yet "+
   	"comfortable.  The bed is covered in %^BLACK%^black %^CYAN%^silk material "+
   	"that seems to glimmer and ripple like the surface of an underground lake.  "+
   	"There is a post at each corner of the bed.  %^RED%^Red %^CYAN%^silk "+
   	"material hangs from the top of each post and runs to the floor.  The "+
   	"fluffy down-filled pillows are, also, cased in %^BLACK%^black %^CYAN%^"+
   	"silk.  On the south wall is a painting of a beautiful woman.  Below the "+
		"painting is a small table.  On the table are two %^YELLOW%^gold "+
		"%^CYAN%^candlestick holders with large candles in each and a vase with a "+
		"dozen %^RED%^red %^CYAN%^roses in the center.  The candlesticks are "+
		"placed in such a way that when they are lit they will shine %^WHITE%^light "+
		"%^CYAN%^on the portrait and the roses.  In the northwest corner of the "+
		"room sits a dressing cabinet.  In the middle of the north wall is "+
		"another table with a pitcher of %^BLUE%^water%^CYAN%^, %^BLUE%^water "+
		"%^CYAN%^bowl, and a soft cloth folded neatly."+
		"%^RESET%^"
   );
  	set_terrain(BUILT_TUNNEL);
   set_travel(PAVED_ROAD);
 	set_property("indoors",1);
   set_property("light",-3);
   set_smell("default","You smell a mixture of roses and burnt candles.");
   set_listen("default","The room is as quiet as the room it is embedded in.");
   set_items(([
     	"moss" : "Gray and benign it looks as if its only purpose is to cover "+
     		"the floor.\n",
     	({"walls","wall"}) : "The walls are smooth and gray and the stonework "+
     		"looks to be of dwarven quality.\n",
     	"floor" : "Covered with a gray moss the floor is smooth, level, and free "+
     		"of dirt and debris.\n",
     	"ceiling" : "About 10 feet overhead the ceiling looks to be smooth and even.\n",
     	"bed" : "The bed is very large and covered completely in black silks and "+
     		"seems to glimmer and ripple like the surface of an underground "+
     		"lake.  At the head of the bed are large fluffy down-filled pillows, "+
			"also, cased in black silk.  At each corner of the bed is a wooden "+
			"post and on each post long ribbons of red silk are draped.  The "+
			"bed is firm to the touch, but does not appear as if it would "+
			"be uncomfortable.\n",
		"painting" : "%^RESET%^The painting is of the best quality and depicts a "+
			"woman of mixed heritage smiling at you.  She looks to be of both "+
			"%^GREEN%^elven %^RESET%^and human parents and she is "+
			"beautiful.  She has long %^BOLD%^%^YELLOW%^blonde %^RESET%^hair, "+
			"enchanting %^BOLD%^%^GREEN%^hazel %^RESET%^eyes, and she is very "+
			"voluptuous.  She is wearing diaphanous %^BOLD%^%^WHITE%^white "+
			"%^RESET%^silk leaving very little to your imagination, while still "+
			"tastefully covering her so that all of her secrets are not "+
			"revealed.  While this lady is very lovely to look at, you notice "+
			"the edge of %^BOLD%^%^BLACK%^steel %^RESET%^in her eyes.  This "+
			"woman looks like she can be hard and soft in all the right places "+
			"at all the right times.  This woman's portrait is set in such a way "+
			"that it looks as if the person who placed it this way did so to "+
			"honor her or the memory of her.\n",
		"roses" : "%^RESET%^A dozen %^BOLD%^%^RED%^red%^RESET%^ roses are placed "+
			"in a vase beneath the portrait.  The roses look to be fresh and "+
			"vibrant.\n",
		({"candles","candle","candlesticks","candlestick"}):"%^BOLD%^%^YELLOW%^Golden"+
			"%^RESET%^candlesticks with large %^BOLD%^%^WHITE%^white%^RESET%^ "+
			"candles are placed beneath the portrait of the lady.\n",
		({"dressing cabinet","cabinet"}) : "The cabinet is about 6 feet tall and "+
			"is divided in the center.  One side is drawers up to about 3 feet "+
			"high with a small shelf above.  Behind the shelf is a small mirror "+
			"mounted in the wood.  The other half of the cabinet is a door.  "+
			"When you open the door you can see garments hanging inside.\n",
		({"pitcher","water bowl"}) : "The pitcher and the water bowl are things "+
			"used for freshening up after a long day/night of torture and play.\n"
	]));
   set_exits(([
		"west" : DROOMS+"cdd3"
   ]));

   set_door("east room door",DROOMS+"cdd3","west","obsidian key");
   set_door_description("east room door","The door is heavily made and is reinforced "+
		"with iron bands.");
   set_string("east room door","open","You open the door into a dark hallway.\n");

	set_search("cabinet","You find that the cabinet moves when you start searching "+
     	"it.  Maybe it can be moved so you can see what's behind it.\n");

}
void init() {
  	::init();
  	add_action("move","move");
}
int move(string str) {
   if(!str) {
     	tell_object(TP,"Move what?");
     	return 1;
   }
  	if(str == "cabinet"){
   	tell_object(TP,"You to the side and reveal a hole in the floor behind it "+
     		"leading down into the darkness. Maybe you can descend into this tunnel "+
     		"as well if you have the skills and the courage.\n");
     	tell_room(ETP,""+TPQCN+" moves the cabinet to the side revealing a hole into "+
     		"the floor.  Maybe you can descend into this tunnel as well.\n",TP);
		return 1;
   
   	set_climb_exits((["descend":({DROOMS+"lab0",20,6,100})]));
   	set_fall_desc("%^BOLD%^%^RED%^You fall a long way tumbling into the "+
			"darkness bouncing off the sides of the tunnel until you come to a sudden "+
			"and painful stop at the bottom!%^RESET%^\n");
 	}
}