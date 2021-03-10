
#include <std.h>

#include "short.h"

inherit ROOM;

void create(){
      ::create();
      set_name("Top");
      set_short("The top of a steep cliff");
      set_long(
	       "You've finally reached the top of this treacherous cliff. "
	       "You need a break to recover from that difficult climb. "
	       "The air is thinner up here than you're used to and "
	       "you realize that you're really cold now. "
      );
      set_listen("default",
        "Strange echoes bounce up from the valley far below."
      );
      set_smell("default",
        "The air is fresh and clean here ... but so cold it's hard to breath."
      );
      set_listen("echoes",
	"They seem to come from far, far below."
      );
      set_items(([
	"cliff":"The cliff is steep and treacherous.  You can discern a few handholds "
		"which makes you think you could climb down here.",
        "top":"You're at the top!",
	"down":"It's a long, long way down!"
       ]));
      set_climb_exits((["descend":({ RPATH "cliff20",6,10,100})]));
      set_fall_desc(
         "You slip on the steep cliff and fall down to a ledge. "
         "Good thing the ledge was here to break your fall!");
     }
