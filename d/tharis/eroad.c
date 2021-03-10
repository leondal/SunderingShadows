#include <std.h>

inherit ROOM;

void create() {
   ::create();
   set_travel(DIRT_ROAD);
   set_terrain(SCRUB_LANDS);
   set_property("light",2);
   set_property("indoors",0);
   set_short("%^ORANGE%^Road to the east of Tharis%^RESET%^");
   set_long( (:TO,"long_desc":) );
   set_smell("default","Hints of the forest to the north reach your nostrils.");
   set_listen("default","The sounds of people milling about reach your ears.");
   set_items(([]));
}

string long_desc(string str) {
    return(query_short() + "\n" + "%^GREEN%^The road you travel passes through"+
	" land left untamed by known civilizations. To the east it seems to have"+
	" once have been meant to reach the sea. It runs along the border between"+
	" the great forest to the north"+
	" and the mountains which loom large to the south. To the west is the rich"+
	" city of Tharis. You know that rich cities bring wealth but with"+
	" that wealth bring thieves in great quantity.\n"
   );
}
