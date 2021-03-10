// Avenue of the Golden Dawn, Verhedin
// Thorn@ShadowGate
// 010117
// New City, Verhedin

#include <std.h>
#include "/d/tsarven/include/southern.h"
#include "/d/verhedin/include/city.h"

inherit VAULT;

void create() {
  ::create();
  set_light(2);
  set_short("%^BOLD%^YELLOW%^Avenue of the Golden Dawn, Verhedin%^RESET%^");
  set_long(
@VERHEDIN
%^BOLD%^YELLOW%^Avenue of the Golden Dawn, Verhedin%^RESET%^
You are on a wide cobbled street which seems to start here and run to 
the southeast.  To the northwest, the street looks the same, but there 
is a bit of brickwork in the cobbles that forms a line.  

There is a signpost on the side of the road by the brick line.

The street passes though an area that appears to be quiet and and 
obviously residential.  On both sides, multi-story homes built close 
together display colorful awnings over their windows and the doors and 
shutters are ornately carved.  Some of the upper levels have wooden 
screens over them in a manner often found farther to the south.  To the 
west, there appears to be a wrought-iron fence surrounding a yard.  The 
fence has a gate that can be used to enter the yard beyond.
VERHEDIN
  );
  set_exits(([
    "northwest" : VNEW+"acm0",
    "southeast" : VNEW+"agd2",
    "gate"      : VNEW+"surath1"
   ]));
  set_listen("default","You hear the muted sounds of a busy city.");
  set_smell("default","You pick up the smells of a nearby river.");
  set_items( ([
    "signpost" : "It reads in Elven and Common:  %^BOLD%^YELLOW%^Avenue of the Golden Dawn%^RESET%^",
    "line" : "From what you can tell, it simply marks the end of this road and the beginning of another."
  ]) );
  set_door("gate",VNEW+"surath1","gate","surath key");
  set_open("gate",0);
  set_locked("gate",1);
  VNEW+"surath1"->set_open("gate",0);
}

void reset(){
	::reset();
}
