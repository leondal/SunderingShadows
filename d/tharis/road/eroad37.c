#include <std.h>
#include "../eroad.h"
inherit ROOM;

void create() {
	::create();
   set_travel(DIRT_ROAD);
   set_terrain(SCRUB_LANDS);
   set_property("light",2);
   set_property("indoors",0);
   set_short("%^ORANGE%^Road to the east of Tharis%^RESET%^");
   set_smell("default","Hints of the forest to the north reach your nostrils.");
   set_listen("default","The sounds of people milling about reach your ears.");
   set_long(query_short() + "\n%^GREEN%^The road you travel passes through land left untamed by known civilizations.  To the east it seems to have"
        " once have been meant to reach the sea. It runs along the border between"+
        " the great forest to the north"+
        " and the mountains which loom large to the south. To the west is the rich"+
        " city of Tharis. You know that rich cities bring wealth but with"+
        " that wealth bring thieves in great quantity. The road stops here, it"+
	" is blocked off by heavy boulders that appear to have fallen down from"+
	" the mountains. Thick grass and forest lie thick to either side of you.\n"
	);
	set_items(([
        ({"boulder","boulders","heavy boulders"}) : "Large and heavy boulders are blocking the path here. They are too large to be moved.",
        "forest" : (:TO,"forest_desc":),
        "trees" : "While those close by are sparse, mixed with common shrubs and bushes, further away they grow denser, changing from small pine or fir to broadleaf trees.",
        "broadleaf" : "Great oaks can be seen in the distance, one majestic specimen towering over all.",
        ({"bushes","shrubs"}) : "Nearby the road there are few trees, mostly smaller shrubs such as bearberry and hyssop.",
        "grass" : "Some of the grass seems to have been trampled, suggesting that someone has tread here.",
	]));
	set_exits(([
        "west" : ROOMS+"eroad36",
        "trail" : "/d/tharis/elftrail/rooms/elfpath001",
	]));
      set_invis_exits(({"trail"}));
      set_pre_exit_functions(({"trail"}),({"trail_fun"}));
      set_search("default","Search what?");
      set_search("shrubs","A few trampled blades of grass suggest that someone has tread here.");
      set_search("bushes","A few trampled blades of grass suggest that someone has tread here.");
      set_search("forest","A few trampled blades of grass suggest that someone has tread here.");
      set_search("grass","Further inspection reveals a well hidden trail leading north into the forest.");
}

string forest_desc() {
   if((int)TP->query_race() == "elf" || (int)TP->query_skill("perception") > 25) return("In the midst of the trees that stretch away in a great forest to the south you notice a hidden trail.");
   return("From the edge of the road you can see a great forest rising up to the south, the trees smaller here but rising to dizzying heights in the distance.");
}

int trail_fun() {
  tell_object(TP,"You step into the forest, the road disappearing behind you as the foliage thickens.\n");
  if (!TP->query_invis()) tell_room(ETP,""+TP->QCN+" steps into the forest, disappearing into the thickening foliage.\n",TP);
  return 1;
}
