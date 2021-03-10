#include <std.h>
#include "../farm.h"
inherit VAULT;

void create(){
   	::create();
   	set_property("indoors",0);
   	set_property("light",1);
	set_property("no sticks",1);
   	set_terrain(CITY);
   	set_travel(PAVED_ROAD);
   	set_name("%^CYAN%^Piaf Huffelmuffin's Home");
   	set_short("%^CYAN%^Piaf Huffelmuffin's Home");
   	set_long("%^GREEN%^Nestled between the farmland"+
		" and the stream, a small gnomish homestead"+
		" has been crafted.  The diamond shaped home"+
		" rests on a verdant patch of grass.  Oddly "+
		"shaped windows can be seen on the house.  The"+
		" aged wood takes on a %^RESET%^bleached %^GREEN%^"+
		"appearance, looking as if it has been ages since"+
		" it's been painted.  %^BLUE%^Slate%^GREEN%^ "+
		"triangular stepping stones lead to the front "+
		"door of the home.  A tangled flower bed flanks"+
		" the stepping stones.  %^YELLOW%^Dandelions%^RESET%^"+
		"%^GREEN%^ now mix with the %^BOLD%^%^RED%^poppies"+
		"%^RESET%^%^GREEN%^ and %^MAGENTA%^violets%^GREEN%^"+
		" in the garden.  A wooden cart rests in the front yard."+
		" The front door of the home is made"+
		" from %^ORANGE%^oak%^GREEN%^ and covered with sheets"+
		" of aged %^BOLD%^copper%^RESET%^%^GREEN%^.  A %^YELLOW%^"+
		"brass%^RESET%^%^GREEN%^ knocker in the shape of a rabbit"+
		" is attached to the front of the door.%^RESET%^\n");
	set_smell("default","The scents of the farm tickle your nose.");
   	set_listen("default","The sounds of the farm and running stream filter in.");
  	set_items(([
      	({"flower bed","poppies","violets","dandelions"}) : "%^YELLOW%^Dandelions"+
			"%^RESET%^ grow wild in the garden, mixing with %^MAGENTA%^violets"+
			" and %^BOLD%^%^RED%^poppies%^RESET%^.",
      	({"house","windows"}) : "%^BOLD%^The diamond shaped house stands out like a"+
			" sore thumb among the farmland.  The windows of the house "+
			"are in strange animal like silhouettes.",
		({"door","knocker","rabbit"}) : "The%^ORANGE%^ oak%^RESET%^"+
			" door is covered with sheets of weathered copper, giving"+
			" it a %^GREEN%^greenish%^RESET%^ hue.  Mounted on the front"+
			" of the door is a rabbit's head %^YELLOW%^brass %^RESET%^knocker.",
		({"cart"}) : "%^ORANGE%^A wooden cart rests in the front yard.  The "+
			"cart looks much like one might attach to a horse to carry "+
			"items across long trips.  Only the harness on this cart is"+
                        " rather small, about the size of a mouse.  Canvas is stretched"+
			" across the bed, as if to create a make shift tent."
		]));
		set_exits(([ "inside" : ROOMDIR"foyer",
				 "east" : ROOMDIR"path2",
		 ]));
	set_door("door",ROOMDIR"foyer","inside",0);
   	set_door_description("door","The%^ORANGE%^ oak%^RESET%^"+
			" door is covered with sheets of weathered copper, giving"+
			" it a %^GREEN%^greenish%^RESET%^ hue.  Mounted on the front"+
			" of the door is a rabbit's head %^YELLOW%^brass %^RESET%^knocker.");

}
void reset(){
   ::reset();
   if(!present("piaf")){
      new(MON"piaf")->move(TO);
   }
}
