#include <std.h>
inherit ROOM;

void create()
{
	::create();
   set_terrain(LIGHT_FOREST);
   set_travel(FOOT_PATH);
	set_property("indoors",0);
	set_property("light",2);
	set_short("A little dirt path");
	set_long(
	"This is a small dirt path that travels between the large forest trees,"+
	" it looks as though it hasn't been used in some time. Grass has begun"+
	" to grow up in the center of the path and a few weeds have made their"+
	" way across it. Animals can be heard scurrying about in the trees and"+
	" beneath the brush. In the distance a few birds are even singing. It"+
	" is hard to believe that you are still in the Tharis Forest, everything"+
	" seems so normal."
	);
	set_smell("default","The smells of the forest surround you.");
	set_listen("default","Animals can be heard scurrying about through the woods.");
	set_listen("birds","You can hear the pleasant trill of bird song in the"+
	" distance.");
	set_listen("brush","You hear the rustling of the brush.");
	set_listen("animals","Animals scurry about in the trees and under the"+
	" forest brush.");
	set_items(([
	"path" : "The small dirt path that you are walking on winds its way around"+
	" the large trees. It looks as though it hasn't been used in a while for"+
	" grass is starting to grow up in the center of the path and a few weeds"+
	" have stretched themselves across it.",
	"grass" : "%^BOLD%^%^GREEN%^Tufts of grass have begun growing in the"+
	" center of the path.",
	"weeds" : "%^GREEN%^Several spindly weeds have stretched themselves out"+
	" along sections of the path.",
	"trees" : "Large trees tower over you, stretching up to incredibly heights."+
	" They are obviously very old, but they are in quite good health. You"+
	" can hear squirrels and other animals scurrying about in their branches.",
	"brush" : "Brush grows thick along the forest floor, you can see it"+
	" moving in places and hear the animals that are rustling about.",
	"forest" : "This is part of the legendary Tharis Forest. The trees are"+
	" old and tall, towering above you, and the entire place is alive with"+
	" signs of life. It is hard to believe this is still part of the same"+
	" forest back to the east, it doesn't feel dangerous at all.",
	]));
}
