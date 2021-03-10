#include <std.h>
#include "../eroad.h"
inherit VAULT;

void create()
{
	::create();
   set_terrain(WOOD_BUILDING);
   set_travel(FOOT_PATH);
	set_property("indoors",1);
	set_property("light",1);
	set_property("no sticks",1);
	set_short("An Old Mill");
	set_long(
	"It is hard to believe that this old and decaying building was once a"+
	" mill that helped to supply Tharis and other surrounding cities with"+
	" lumber. It is quite tiny and obviously did not do the job all by itself,"+
	" but its owners must have worked very hard. Now the floors are covered"+
	" in dirt and saw dust, the roof has a few holes where the rain water"+
	" leaks through, and most people probably don't even know about the mill"+
	" here. You can imagine that in its day this place was new, clean, and"+
	" in full production. Although the water wheel is still slowly turning,"+
	" the saw blades are getting rather rusty and probably haven't touched"+
	" a piece of wood in the last year. There is still a small pile of"+
	" lumber stacked up in one corner, but mold is already growing on it."
	);
	set_smell("default","There is a musty smell in this room.");
	set_listen("default","The water wheel splashes in the stream outside.");
	set_items(([
	"floor" : "The floor is rather worn and covered with saw dust and dirt."+
	" There are spots on the floor where it has begun to mold from water"+
	" leaking in through the roof. Cobwebs hang in a few corners, but it"+
	" looks like even the spiders have abandoned this place.",
	({"ceiling","roof"}) : "You can see a few holes in the ceiling above"+
	" you, places where water has leaked through during rain.",
	({"lumber","pile of lumber","stack of lumber"}) : "A small stack of"+
	" lumber sits in one corner of the room. It is old and worthless, with"+
	" mold covering most of it.",
	"mold" : "Mold has begun to grow around the room thanks to the holes"+
	" in the roof that are letting the cold, wet air in.",
	({"saw","saw blade","saw blades"}) : "The saw blades are dull and have"+
	" gotten rusty over time. They probably haven't even touched a piece of"+
	" wood in years.",
	({"wall","walls"}) : "The walls are still standing, amazingly enough."+
	" They have a few patches in places, but there aren't any holes in them."+
	" Cobwebs cling to them at the corners, but they actually look rather"+
	" sturdy. They must have been very well built.",
	"door" : "The door is old and rather dilapidated, but it still clings"+
	" to its hinges.",
	]));
	set_exits(([
	"out" : ROOMS+"path4",
	]));
	set_door("door",ROOMS+"path4","out",0);
}
