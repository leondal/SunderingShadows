#include <std.h>
#include "../defs.h"
inherit "/std/pier";

void create() {
        ::create();
        set_property("indoors",0);
        set_property("light",2);
        set_terrain(HEAVY_FOREST);
        set_travel(GAME_TRACK);
        set_name("A small brook");
        set_short("%^RESET%^%^ORANGE%^A small brook");
        set_long("%^GREEN%^Babbling away to the south, a "+
		"narrow %^BOLD%^%^CYAN%^brook%^RESET%^%^GREEN%^ "+
		"ripples over a shallow bed of %^BOLD%^%^BLACK%^"+
		"riverstones%^RESET%^%^GREEN%^. A %^ORANGE%^fallen "+
		"tree %^GREEN%^allows for a simple bridge by which "+
		"the brook can be crossed without getting your ankles wet.");
        set_smell("default","%^RESET%^%^ORANGE%^The earthy scents of nature surround you.");
        set_listen("default","%^RESET%^%^ORANGE%^Water moves audibly over the stones here.");
        set_items(([
           ({"riverstones","stones"}) : "Palm sized, rounded rocks, "+
		   "they have all been worn smooth over years of water"+
		   " flowing over them.",
           ({"tree","fallen tree"}) : " About a foot wide, this tree"+
		   " fell long ago, few of its branches remaining and"+
		   " those devoid of leaves. Patches of bright moss "+
		   "grow on it sporadically.",
        ]));
        set_exits(([
           "north" : ROOMS"elfpath006",
           "southeast" : ROOMS"elfpath004",
		   "east":ROOMS"hidden1",
        ]));
		 set_invis_exits(({"east"}));
        set_water_body("brook");
		set_search("room","Is there something to the east?"); 
}
