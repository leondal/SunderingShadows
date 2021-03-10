#include <std.h>
#include "../defs.h"
inherit ROOM;

void create()
{
  ::create();
   set_terrain(VILLAGE);
   set_travel(FOOT_PATH);
  set_property("indoors",0);
  set_property("light",1);
  set_short("%^BOLD%^A Small Campsite%^RESET%^");
  set_long("The forest opens up a little bit here, allowing "+
	"more sunlight to find its way to the ground.  Large "+
	"sacks lay neatly along the outskirts, and a few large "+
	"sleeping mats are rolled up and lean against nearby trees.  "+
	"It seems to be rather peaceful in this section of the "+
	"forest.  To the east you can see a large lake, while the "+
	"forest closes in again a little ways to the west.");
  set("night long","The moonlight reveals a small clearing "+
	"currently being used as a campsite.  Large mats lay "+
	"rolled out under the stars, while sacks are stacked "+
	"neatly out of the way.  To the east, you can hear the "+
	"rhythmic sound of water caressing a shore.  A little "+
	"ways to the west, the forest seems to return to its "+
	"darkened state.");
  set_smell("default","The crisp, fresh scent of pine fills the air.");
  set_listen("default","The trees creak as they sway in the wind.");
  set_items(
    ([
    ({"tree","trees","pine","oak"}):"Huge, sprawling oak trees fight "+
	"for space amongst the tall pine trees."
    ]) );
  set_exits(
    ([
    "east" : ROOMS+"c2",
    "west" : ROOMS+"f43",
    "north" : ROOMS+"f41",
    "south" : ROOMS+"f51"
    ]) );
}

void reset()
{
  ::reset();
  if(!present("hunter")) 
  {
    new(MONS+"vhunter")->move(this_object());
  }
}
