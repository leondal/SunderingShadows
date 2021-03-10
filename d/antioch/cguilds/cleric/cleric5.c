#include <std.h>
#include "../cleric.h"
inherit ROOM;

void create()
{
	::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
	set_property("no teleport",1);
	set_property("indoors",1);
	set_property("light",2);
	set_short("%^BOLD%^%^CYAN%^Pool of Reflection");
	set_long(
	"Walking into the room a sense of tranquility washes over you. There is"+
	" a large pool at the far end of the room. A %^BOLD%^white lily%^RESET%^"+
	" is fixed to the wall and water is slowly trickling out of it into the"+
	" pool. Solid gray stone seems to rise up out of the floor and forms a"+
	" circle to hold the water. Looking into the pool you don't see any place"+
	" for the water to be draining out from, but it must be going somewhere."+
	" The water is a %^BOLD%^%^BLUE%^deep blue%^RESET%^ shade and even though"+
	" the pool is only a few feet deep you can't see the bottom clearly. The"+
	" rest of the room is rather bare. On the north and south walls are two"+
	" bees wax candles. The candlelight is steady and casts a gentle light"+
	" about the room."
	);
	set_smell("default","The faint scent of gardenias is pleasant.");
	set_listen("default","You can hear the gentle splashing of water.");
	set_items(([
	({"pool","pool of reflection","Pool","Pool of Reflection"}) : "%^BOLD%^%^CYAN%^At"+
	" the far end of the room is a pool formed by a circle of solid stones."+
	" A %^WHITE%^white lily%^CYAN%^ is attached to the wall and from it water"+
	" slowly trickles into the pool. Although the water should be rippling"+
	" from the stream pouring into it, it is completely still. Staring at"+
	" the pool the surface is smooth as glass and it reflects an image like"+
	" a mirror, but only your image and nothing else in the room. This is"+
	" the Pool of Reflection, it is here for clerics to stare into its depths"+
	" and see themselves as they are.",
	({"lily","white lily"}) : "%^BOLD%^A perfect white lily is attached to"+
	" the back wall. From the center of it %^BLUE%^water%^WHITE%^ trickles out in a steady"+
	" stream, pouring into the pool below.",
	"water" : "%^BOLD%^%^BLUE%^The water is a clear blue color, seemingly"+
	" depthless.",
	({"candle","candles","bees wax candle","bees wax candles","beeswax candle","beeswax candles"}) : "%^BOLD%^There is a bees wax candle on each of"+
	" the north and south walls. Although the candles are lit, they don't"+
	" appear to be burning down any and no wax is dripping from them. The"+
	" pewter cherry blossom holders that the candles sit in are clean and"+
	" completely free from wax.",
	({"candle holder","candle holders","pewter holders","cherry blossom holders","blossom holders","cherry holders"}) : "The"+
	" pewter candle holders are fixed to the north and south stone walls."+
	" They're in the shape of cherry blossoms and they each hold a bees wax"+
	" candle.",
	"floor" : "The floor is made of gray stone blocks and looks very clean.",
	"ceiling" : "The ceiling is flat and made of gray stone blocks. Light"+
	" reflecting from the pool shimmers across the ceiling.",
	({"wall","walls"}) : "The walls are made from gray stone blocks. The"+
	" north and south walls have candles on them and the eastern wall has a"+
	" %^BOLD%^white lily%^RESET%^ in the center of it that trickles a stream of water.",
	]));
	set_exits(([
	"west" : ROOMS+"cleric2",
	]));
}
