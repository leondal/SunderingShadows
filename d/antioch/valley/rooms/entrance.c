#include <std.h>
#include "../valley.h"
inherit ROOM;

void create()
{
        ::create();
   set_terrain(HILLS);
   set_travel(RUTTED_TRACK);
        set_property("outside", 2);
        set_property("light", 2);
   set_short("%^BOLD%^%^WHITE%^Valley Entrance");
        set_long(
        "%^GREEN%^You are standing at the top of a trail that"+
        " overlooks a large valley. The valley looks %^BOLD%^lush%^RESET%^%^GREEN%^,"+
        " filled with grazing %^ORANGE%^animals%^GREEN%^. Several trees are"+
        " growing within it, and you can see a meadow off"+
        " to the east. In the very distance you can make"+
        " out a%^BOLD%^%^CYAN%^ waterfall%^RESET%^%^GREEN%^"+
        " that spills into a %^BOLD%^%^BLUE%^lake%^RESET%^%^GREEN%^, and a"+
        "%^BLUE%^ river%^GREEN%^ winds down from it, disappearing into the"+
        " forest. The valley itself seems %^CYAN%^peaceful%^GREEN%^ enough,"+
        " but the trees on the edge still appear %^BOLD%^%^BLACK%^sinister%^RESET%^%^GREEN%^."+
        " You can either climb down into the valley or turn"+
        " around and take the trail back.\n"
        );
        set_smell("default",
        "The scent of wildflowers drifts in the breeze."
        );
        set_listen("default",
        "The rush of the waterfall can barely be heard."
        );
        set_items( ([
        "valley" : "%^BOLD%^%^GREEN%^The valley stretches out into the"+
        " distance and looks very tranquil."
        ]) );
        set_exits( ([
        "trail" : ROOMS+"dt15",
        "valley" : ROOMS+"v4",
        ]) );
	set_pre_exit_functions(({"valley", "trail"}),({"go_valley", "go_trail"}));
}

int go_valley()
{
	write("%^BOLD%^You make your way down the trail into the valley.");
	return 1;
}

int go_trail()
{
     if(!userp(TP) && TP->id("druid")) {
      tell_object(TP,"You cannot go that way.");
      return 0;
   }
	write("You walk up the trail into the woods.");
	return 1;
}
