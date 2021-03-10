//camp1.c - Updated by Circe 11/28/03
#include <std.h>
#include "../koenig.h"
inherit ROOM;

void create()
{
	::create();
      set_terrain(VILLAGE);
      set_travel(DIRT_ROAD);
	set_property("indoors",0);
	set_property("light",2);
	set_short("An old campground");
	set_long(
	   "This is the site of an old campground. Adventurers who used to cross"+
	   " the mountains would rest here before or after they made their trip."+
	   " It is a quiet area, not too far from the stream, and far enough away"+
	   " from the mountain cliffs to feel comfortable and not have to worry"+
	   " about a sudden rock slide. The foothills are relatively bare and"+
	   " uninhabited, no need to worry about raiding orcs and the like. The"+
	   " campground has deteriorated a little over time. Shrubs and weeds have"+
	   " begun growing in the center of the campground. There are a few stone"+
	   " tables and benches on the edges of the campground. In the center,"+
	   " beneath a large stone roof supported by several pillars, is a fire pit."+
	   " The stones are still standing tall, but they have a layer of thick"+
	   " dust covering them. The fire pit in the center has not been used in"+
	   " some time, either, and there is no firewood with which to start it."
	);
	set_smell("default","The crisp mountain air blows through the campground.");
	set_listen("default","The wind whispers through the mountain foothills.");
	set_items(([
	({"pit","fire pit"}) : "A fire pit sits in the center of the campground."+
	   " It has not been used in some time, and is almost completely filled with"+
	   " dirt. Tradition normally held that whoever used the campground would"+
	   " leave a supply of firewood behind, but it has long since been carried"+
	   " away by the winds.",
	({"roof","stone roof","pillars","stone pillars"}) : "Stone pillars support"+
	   " a large stone roof that stretches over the campground. It would give"+
	   " shelter to the weary travelers as they rested through the night."+
	   " Obviously no one uses it anymore.",
	({"tables","benches","stone tables","stone benches"}) : "Stone tables"+
	   " and benches are found along the edges of the campground, just outside"+
	   " the reach of the large stone roof. Adventurers would sit at them and"+
	   " tell stories or play cards, perhaps share a meal, long ago.",
	]));
	set_exits(([
	"southeast" : VILSTREAM"trail5",
	"west" : VILSTREAM"camp2",
	]));
}
