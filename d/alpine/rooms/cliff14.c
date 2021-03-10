
#include <std.h>

#include "short.h"

inherit ROOM;

void create(){
      ::create();
      set_name("Clff");
      set_short("A ledge on a steep cliff");
      set_long(
	       "You are climbing up a steep rocky cliff.  The ledge "
	       "dissappears here.  You'll have to backtrack and find "
	       "another way.  As you climb higher you notice that "
	       "it's getting colder and the air is getting thinner. "
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
	"cliff":"The cliff is steep and treacherous.  You can see no handholds here.",
	"top":"You can't see the top, it's hidden in the clouds."
       ]));
      set_exits(([
	 "east": RPATH "cliff13"
       ]));
     }
