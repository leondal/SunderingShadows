#include <std.h>
#include "../valley.h"
inherit ROOM;

void create()
{
   ::create();
   set_terrain(NAT_CAVE);
   set_travel(RUTTED_TRACK);
   set_property("indoors",2);
   set_property("light",2);
   set_short("A cave");
   set_long("%^BOLD%^%^BLACK%^This is the mouth of a large cave. It was perfectly concealed "+
   "behind the %^RESET%^%^GREEN%^trees %^BOLD%^%^BLACK%^and %^RESET%^%^GREEN%^bushes %^BOLD%^%^BLACK%^of the forest. "+ 
   "The entrance to the cave is very tall, but it looks as though it gets narrower the further back "+ 
   "the cave goes. The walls of the cave are rough and the floor is bumpy. There is a lot of "+ 
   "%^RESET%^%^ORANGE%^dirt %^BOLD%^%^BLACK%^on the ground and some %^RESET%^bear tracks "+ 
   "%^BOLD%^%^BLACK%^are clearly visible. A bear has probably taken up residence in this secluded spot. "+ 
   "The cave continues further back.%^RESET%^");
   set_smell("default",
   "It smells as though some mangy animal has been living here for some time."
   );
   set_listen("default",
   "It's rather quiet."
   );
   set_items( ([
   "cave" : "The cave walls are rough and the floor is covered with dirt. The mouth of"+
   "the cave is a little ways behind you, concealed by brush from intruders.",
   "dirt" : "There are bear tracks in the dirt.",
   "tracks" : "Obviously some large bear has taken residence in this cave.",
   "floor" : "The floor is rather bumpy and covered in dirt.",
   "ceiling" : "The ceiling of the cave is high, but it narrows as the cave continues"+
   " on.",
   ]) );
   set_exits( ([
   "south" : ROOMS+"e2803",
   "north" : ROOMS+"cave2",
   ]) );
   set_pre_exit_functions(({"south"}),({"goThroughDoor"}));
}

int goThroughDoor()
{
   write("You make your way through the bushes and back into the forest.");
   say(""+TP->query_cap_name()+" stumbles off into the brush.");
   return 1;
}

void reset()
{
	::reset();
	if(!present("bear")) {
		new(MONS+"bear")->move(TO);
		return 1;
	}
}
