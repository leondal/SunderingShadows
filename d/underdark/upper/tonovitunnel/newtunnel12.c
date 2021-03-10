#include <std.h>
#include "../defs.h"
inherit INH+"tunnel2";

void create() {
    ::create();

    set_exits(([
      "south" : TUNNEL"newtunnel11",
      "crawl" : "/d/av_rooms/lurue/frozen"
    ]));
    set_invis_exits( ({"crawl"}) );
    set_climb_exits((["climb":({ "/d/dagger/tonovi/temp/upper1",3,6,100})]));
    set_search("tunnels","%^BOLD%^%^WHITE%^You search over the avalanche and "
"notice one tunnel you might be able to crawl into.%^RESET%^");
}
