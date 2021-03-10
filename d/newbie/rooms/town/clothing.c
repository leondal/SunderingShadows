#include <std.h>
#include "../../newbie.h"
inherit ROOM;

void create()
{
	::create();
	set_property("indoors",1);
	set_short("The Singing Seamstress");
	set_terrain(STONE_BUILDING);
	set_travel(PAVED_ROAD);
	set_long(
@CRYSTAL
You are standing in a little tailor's shop fondly named the Singing Seamstress.
It is located on Shale Street, on the south side of town, and does not
see too many customers. There are many bolts of all sorts of fabrics,
colors, and patterns strewn about around the store. Hung in the back
are the finished items. There is everything from work trousers to pretty
summer dresses. There is a small display of shoes, hats, and gloves as
well. Although these clothes offer no help to you in battle, it is nice
to be wearing something instead of walking around naked.
CRYSTAL
	);
	set_property("light",2);
        set_smell("default","There is the pleasant scent of some lavender incense in the air.");
	set_listen("default","You can hear people passing by on the street outside.");
	set_items(([
	"clothes" : 
@CRY1
There are all sorts of clothes hung in the back of the room. Most of
them are fairly simple, something that would please almost anyone.
There are tunics and work pants, nicer jackets and several dresses.
If you want to see anything, the shop keeper will be more than happy
to show it to you.
CRY1
        , ({"shoes","hats","gloves","display"}) : 
@CRY2
There is a display set up on the right side of the room. There are a
couple different types of shoes, hats, and gloves on it. Not everything
is always available, however, but anything that is in stock you can ask
for the shop keeper to show you.
CRY2
        , "floor" : 
@CRY3
The floor is covered in a very elaborate hand-woven rug that stretches
the entire length of the floor. It is of an abstract pattern, but is
quite lovely.
CRY3
        , ({"fabric","bolts","cloth"}) : 
@CRY4
Many different types of bolts of fabric are scattered about the room. They are of almost every color imaginable, and of several different fabrics ranging from plain cotton to spun silk. Some of them already have patterns of various sorts in the fabric, such as stripes or flowers.
CRY4
        , "patterns" : 
@CRY5
There are several different types of paper and cloth patterns around
the room. Some are for dresses and skirts, others for tunics, jackets,
and pants.
CRY5
        , ]));
	set_exits(([
    "east" : MAINTOWN"nstreet1",
	"south" : MAINTOWN"wstreet1",
	]));
}

void reset() {
   ::reset();
   if(!present("adresa")) {
      new(MON"adresa")->move(TO);
   }
}
