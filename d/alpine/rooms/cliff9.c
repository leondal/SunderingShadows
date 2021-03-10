
#include <std.h>

#include "short.h"

inherit ROOM;

void create(){
      ::create();
      set_name("Cliff");
      set_short("A ledge on a steep cliff");
      set_long(
	       "You are climbing up a steep rocky cliff.  You pause "
	       "here at a narrow ledge.  You hope you are skilled "
	       "enough to make it to the top.  As you climb higher "
	       "you notice that it's getting colder and the air is "
	       "getting thinner. "
      );
      set_listen("default",
        "Strange echoes bounce off this cliff."
      );
      set_smell("default",
        "The air is fresh and clean here ... if a bit cold."
      );
      set_listen("echoes",
	"They seem to come from far, far below."
      );
      set_items(([
	"cliff":"The cliff is steep and treacherous.  You can discern a few handholds "
		"which makes you think you could climb up here.",
	"top":"You can't see the top, it's hidden in the clouds."
       ]));
      set_exits(([
	 "east": RPATH "cliff10",
	 "west": RPATH "cliff8"
       ]));
      set_climb_exits((["climb":({ RPATH "cliff20",7,10,400})]));
      set_fall_desc(
         "You slip on the steep cliff and fall down to a ledge. "
         "Good thing the ledge was here to break your fall!");
     }
