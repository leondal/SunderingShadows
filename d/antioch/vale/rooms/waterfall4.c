//hades added terrian 1/12/10

#include <std.h>
#include "../vale.h"
inherit ROOM;

void create()
{
   ::create();
   set_terrain(NAT_CAVE);
   set_travel(RUTTED_TRACK);
   set_property("indoors",1);
	set_property("fill waterskin", 1);
   set_property("light",1);
   set_property("no sticks",1);
   set_short("Behind the Waterfall");
   set_long(
   "%^BOLD%^%^CYAN%^Heated Pools%^RESET%^\n"+
   "%^CYAN%^You have discovered a series of %^RED%^heated%^CYAN%^ pools here in the depths"+
   " of the cliff. The cave is larger here, with a domed ceiling that"+
   " is over twenty feet in height. There are two large %^BOLD%^pools%^RESET%^%^CYAN%^, one on"+
   " the north and one on the south, with a series of pools in the"+
   " very center. The center pools start several feet taller, with"+
   " %^RED%^hot %^CYAN%^water pouring out into a circular area top, then spilling"+
   " down into a larger and deeper pool with a ridge around the inner"+
   " edge, and finally falling into the largest pool that has a %^ORANGE%^sandy"+
   " %^CYAN%^bottom. The top two pools have %^BOLD%^%^WHITE%^steam%^RESET%^%^CYAN%^ rising from them and are"+
   " clearly the %^BOLD%^%^RED%^hottest%^RESET%^%^CYAN%^. The pools off"+
   " to the sides seem to be %^BOLD%^%^BLUE%^cooler%^RESET%^%^CYAN%^,"+
   " being fed by both the %^RED%^hot spring%^CYAN%^ as well as a cooler underground"+
   " %^BLUE%^river%^CYAN%^. Water is constantly being poured into all the pools and"+
   " swept out again through small openings in either the bottom edges."+
   " Soft %^BOLD%^%^CYAN%^blue%^RESET%^%^CYAN%^ and %^BOLD%^%^GREEN%^green%^RESET%^"+
   " %^CYAN%^light emanates from phosphorescent moss that grows on the edges"+
   " of the walls and ceiling. This place was obviously sculpted by"+
   " someone.\n"
   );
   set_listen("default","The roar of the waterfall echoes faintly.");
   set_smell("default",
   "The air is warm and thick with a faint sulphiric tinge.");
   set_items(([
   ({"moss","phosphorescent moss"}) : "%^BOLD%^%^CYAN%^Blue%^RESET%^%^CYAN%^ and"+
   " %^GREEN%^green%^CYAN%^ phosphorescent moss grow along the edges"+
   " of the ceiling and walls, shedding a dim light on the room.%^RESET%^",
   ({"walls","ceiling"}) : "The walls and ceiling are very smooth and"+
   " are beaded with sweat. %^BOLD%^%^CYAN%^Blue%^RESET%^ and %^BOLD%^%^GREEN%^green%^RESET%^"+
   " phosphorescent moss grows along the edges.",
   "top pool" : "%^CYAN%^The pool on the very top has hot water constantly"+
   " bubbling into it from below. It is shallower than some of the"+
   " other pools, probably only three feet deep, and water spills"+
   " over the edges into the middle pool.",
   ({"side pools","north pool","south pool"}) : "%^BOLD%^%^BLUE%^The pools"+
   " on the north and south sides of the room are identical. They"+
   " are large and rounded, with smooth bottoms and sides and a ridge"+
   " on the inner edge that you can sit on. They are cooler than the"+
   " center pools, being fed by both the hot spring and an underground"+
   " river of colder water. The water is sucked out through a small hole"+
   " in the bottom sides, probably draining into the lake.",
   ({"pool","pools"}) : "%^BLUE%^There are many pools here, side pools, the"+
   " top pool, middle pool, bottom pool. They all look warm and inviting.",
   "middle pool" : "The middle pool in the center is almost six feet"+
   " deep, it has a ledge running around the inner edge of it that is"+
   " smooth and can be sat on while you soak in the relaxing, hot"+
   " waters. Water from the top pool pours over the sides down into"+
   " the middle pool, which in turn pours into the bottom pool.",
   "bottom pool" : "%^BOLD%^%^BLUE%^The bottom pool in the center is eight feet deep"+
   " but it grows shallower closer to the edges, where it is only"+
   " two feet deep. There is sand all over the bottom that people"+
   " can scrub clean with before moving up into either of the other"+
   " pools. You notice a series ledges in the very back that are like"+
   " stairs, leading up to the higher pools.",
   ({"ledges","stairs"}) : "%^ORANGE%^In the very back of the room are a series"+
   " of ledges that look strikingly like wide stairs. You can use them"+
   " to get into the upper pools.",
   "sand" : "%^ORANGE%^Fine pale sand lightly covers the bottom pool."+
   " People can use it to scrub themselves clean.%^RESET%^",
   "water" : "%^BOLD%^%^BLUE%^The water of the pools is clean and fresh, having no"+
   " chance to get stagnant since it's constantly moving.",
   "floor" : "The floor is smooth and flat.",
   "waterfall" : "%^CYAN%^%^BOLD%^The waterfall crashes somewhere in the eastern distance.",
   ]));
   set_exits(([
   "east" : ROOMS+"waterfall3",
   ]));
}
 
