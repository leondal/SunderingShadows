#include <std.h>
#include "../defs.h"
inherit ROOM;

void create()
{
  ::create();
   set_terrain(SHORE);
   set_travel(FOOT_PATH);
  set_property("indoors",0);
  set_property("light",1);
  set_short("%^BOLD%^A Small Campsite%^RESET%^");
  set_long("You stand along the shore of a large, pristine "+
	"lake.  The water is very still, reflecting the surrounding "+
	"areas like a mirror.  Across the lake, to the far east, "+
	"stands a range of snowcapped mountains.  Ospreys glide "+
	"gracefully through the air, watching the water's surface "+
	"carefully for fish.  A few feet from the shore are the "+
	"burned up remains of a campfire.");
  set("night long","You stand along the shore of a large, pristine "+
	"lake.  The water seems to glow, shimmering in the evening's "+
	"moonlight.  A campfire crackles a few feet from the shore, "+
	"giving off a gentle, comforting warmth.");
  set_smell("default","The crisp, fresh scent of pine fills the air.");
  set_listen("default","The trees creak as they sway in the wind.");
  set_items(
    ([
    ({"tree","trees","pine","oak"}):"Huge, sprawling oak trees fight "+
	"for space amongst the tall pine trees.",
    ({"fire","campfire"}):"The campfire is an obvious sign that "+
	"someone stays in the area.",
    "lake":"A gentle fog hangs over the still waters.  Across the "+
	"lake, the forest rises up along the side of a mountain range.",
    "mountains": "The mountain range rises up over the lake to the "+
	"far east."
    ]) );
  set_exits(
    ([
    "west" : ROOMS+"c2",
    "north" : ROOMS+"c5",
    "south" : ROOMS+"f53"
    ]) );
}

void reset()
{
  ::reset();
  if(!present("scout")) 
  {
    new(MONS+"vscout")->move(this_object());
  }
}
