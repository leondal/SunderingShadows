#include <std.h>
#include "../exchange.h"
inherit VAULT;
inherit "/d/common/inherit/hitching_post";

void create(){
    ::create();
   set_terrain(OLD_MOUNTS);
   set_travel(DIRT_ROAD);
    set_property("light" , 2);
    set_property("indoors" , 0);
    set_name("A well tended road");
    set_short("%^ORANGE%^A well tended road%^RESET%^");
    set_long("%^RESET%^%^ORANGE%^Before you stands a magnificent building "+
"complex nestled in the mountains. The road to the complex is well tended"+
" and well traveled. The buildings are large and seem well fortified against"+
" both the elements and any attack. The buildings are constructed from "+
"huge blocks of %^RESET%^%^BOLD%^%^WHITE%^pure white marble %^RESET%^"+
"%^ORANGE%^with roofs of %^RESET%^%^BOLD%^%^BLACK%^a black stone%^RESET%^"+
"%^ORANGE%^. You see a stables, warehouses, and the main building. The "+
"%^RESET%^%^WHITE%^dark mountains %^RESET%^%^ORANGE%^in the distance "+
"provides stark contrast.%^RESET%^\n");
    set_smell("default","You can smell the fresh mountain air.");
    set_listen("default","You can hear the wind blowing through the
valleys.");


    set_items(([
        "road":"A new road through the mountains.",
              ({"post","posts","hitching post","hitching posts","tether","tethering
              post","tethering posts"}) : "There are several posts set up here to tether
              horses to. They are"+
                      " basically long wooden bars that are supported on either end"+
                              " that you loop the reins of a horse around to keep them there."+
                                      " There are four posts all together, circling a round, wooden trough.",
        "mountains":"They are impressive, even from here.",
        ]));

    set_exits(([
                   "southwest" : "/d/shadow/room/pass/pass16",
                   "north" : "/d/dagger/exchange/rooms/foyer"
        ]));

    set_door("glass door",ROOMS"foyer","north",0);
    set_door_description("glass door","%^RESET%^%^BOLD%^Although the frame for this"+
" door is %^RESET%^%^ORANGE%^heavy oak%^RESET%^%^BOLD%^, it is dominated by a beautifull"+
" pane of glass that allows light to pass through.");
    set_string("glass door", "open", "%^RESET%^%^CYAN%^The glass door opens silently.%^RESET%^");
    set_string("glass door", "close", "%^RESET%^%^CYAN%^The glass door closes silently.%^RESET%^%^BOLD%^");
}
