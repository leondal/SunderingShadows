#include <std.h>

inherit ROOM;

void create()
{
  ::create();
  set_property("light",0);
  set_property("indoors",1);
  set_short("a Cave");
  set_long("%^RED%^a Cave%^RESET%^\n"
           "You have entered a dark cave in inner Darkwood. It is damp "
           "and chilly in here and large cracks run from ceiling to "
           "floor. It would appear this is a den to something, "
           "considering the bones that litter the floor.");
  set_smell("default","It is damp and chilly here.");
  set_listen("default","There is no sound except for the echo of your "
             "movements.");
  set_items( ([
     "cracks" : "They run floor to ceiling and some appear to be deep.",
     "bones"  : "There are bones from various animals and humanoid races "
                "scattered on the cave floor."
	       ]) );
  set_search("cracks","You search the cracks and find one that leads "
             "down.");
  set_exits( ([
     "out" : "/d/darkwood/forest/if29",
     "down" : "/d/darkwood/forest/caves/tunnels/tun31"
	       ]) );
  set_invis_exits( ({"down"}) );
  }
