
#include <std.h>

#include "short.h"

inherit ROOM;

void create(){
      ::create();
      set_name("Cliff");
      set_short("A dead end on a steep cliff");
      set_long(
	       "You are climbing up a steep rocky cliff.  You have "
	       "climbed as far as you can here ... you'll have to "
	       "go back down and try somewhere else.  As you climb higher "
	       "you notice that it's getting colder and the air is "
	       "getting thinner."
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
		"which makes you think you could climb down here.",
        "top":"You can't see the top, it's hidden in the clouds."
       ]));
      set_climb_exits((["descend":({ RPATH "cliff6",5,10,100})]));
      set_fall_desc(
         "You slip on the steep cliff and fall down to a ledge. "
         "Good thing the ledge was here to break your fall!");
     }
