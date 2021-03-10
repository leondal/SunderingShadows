#include <std.h>
#include "../include/tabor.h"

inherit ROOM;

void create(){
	::create();
	set_travel(PAVED_ROAD);
	set_terrain(CITY);
	set_light(2);
//	set_property("no teleport", 1); //removed by Circe 6/18/08 after discussions with others
	set_indoors(1);
	set_name("Room of Reflection");
	set_short("Room of Reflection");
	set_long(
"%^BOLD%^Room of %^CYAN%^R%^RESET%^%^CYAN%^e%^BOLD%^f"+
"%^RESET%^%^CYAN%^l%^BOLD%^e%^RESET%^%^CYAN%^c%^BOLD%^t"+
"%^RESET%^%^CYAN%^i%^BOLD%^o%^RESET%^%^CYAN%^n%^BOLD%^%^WHITE%^, Tabor%^RESET%^\n"+
"%^CYAN%^The calm, serene sounds of %^BOLD%^water %^RESET%^"+
"%^CYAN%^gently playing over %^BOLD%^%^BLACK%^rocks "+
"%^RESET%^%^CYAN%^fills this room.  An impressive "+
"%^BOLD%^%^BLACK%^fountain %^RESET%^%^CYAN%^comprised of "+
"smooth, flat, river rocks stands in the center, the "+
"%^BOLD%^%^BLACK%^rocks%^RESET%^%^CYAN%^ arranged to "+
"provide an aesthetically pleasing focal point.  Tall, "+
"leafy %^GREEN%^potted plants %^CYAN%^shade the area, "+
"bringing a sense of nature into the crystalline walls.  "+
"Thin %^ORANGE%^mats %^CYAN%^are spread along the floor, "+
"offering psions a comfortable place to relax and "+
"appreciate the serenity this place can offer a busy mind.  "+
"No hard angles can be seen here - even the walls seem to "+
"flow into one another and the ceiling.\n"
	);
	set_smell("default","A crisp, clean fragrance permeates the air.");
	set_listen("default","The gentle murmur of falling water brings peace to the mind.");
	set_items( ([
       ({"wall","walls","floor","here"}) : "The walls, floor, and "+
          "ceiling have been carved from a smooth crystalline "+
          "substance that seems somewhat unlike natural rock.  "+
          "They have a reflective sheen, allowing you to catch a "+
          "brief glimpse of yourself.",
       ({"light","lights"}) : "A soft, pleasant light fills the room, "+
          "though not from any source you can see.",
       ({"fountain","rocks","rock","water"}) : "%^BOLD%^%^BLACK%^The fountain "+
          "is comprised of thin river rocks, a deep dusky gray in "+
          "color.  They are balanced atop one another in various "+
          "ways, creating an asymmetrical design.  The water "+
          "cascades down them slowly, forming a serene sort of "+
          "music.",
       ({"plants","potted plants","plant"}) : "Arranged "+
          "throughout the room are leafy plants and ferns, "+
          "placed simply into wicker baskets.",
       ({"mats","thin mats","thin mat","mat"}) : "Thin padded "+
          "mats comprise the whole of the floor, giving a comfortable "+
          "place for psions to relax and listen to the fountain.  "+
          "They are made to be comfortable enough to sit for "+
          "long periods of time without being an actual place "+
          "to lounge, like a divan might be."
    ]) );
    set_exits(([
        "west" : ROOMDIR+"psihall"
    ]) );
}
