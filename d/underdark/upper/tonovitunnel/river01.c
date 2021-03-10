#include <std.h>
#include "/d/underdark/upper/defs.h"
#include "/d/underdark/ud_ruins/ud_ruins.h"

inherit ROOM;

void create() {
    ::create();
    set_property("indoors",1);
    set_property("light",0);
    set_travel(FOOT_PATH);
    set_terrain(NAT_TUNNEL);
    set_name("An underground river");
    set_short("%^RESET%^%^BLUE%^An underground river%^RESET%^");
    set_long("%^BOLD%^%^BLACK%^The sound of moving water fills this "
"chamber as you scramble up on top of several large boulders.  Cresting "
"the top of the tightly fitted stones you can see a large underground "
"%^BLUE%^river %^BLACK%^flowing rapidly from north to south.  The "
"%^BLUE%^dark waters %^BLACK%^churn and splash against the stones, "
"spraying your feet and making your footing dangerous as the %^BLUE%^"
"water %^BLACK%^tries to batter its way past the impediment.  Thick "
"%^RESET%^%^ORANGE%^wooden boards %^BOLD%^%^BLACK%^span the space "
"between the boulders, forming a rough bridge of sorts that you might "
"be able to cross.%^RESET%^\n");
    set_smell("default","The heavy scent of damp earth fills the air.");
    set_listen("default","The rush of swiftly flowing water batters your senses.");

    set_items(([
      ({"water","river"}) :
        "%^BOLD%^%^BLUE%^The water moves in a swiftly flowing river, made deeper "
        "and faster by the way someone has diverted part of it away from the "
        "nearby tunnel. You're certain trying to cross the water would be "
        "hazardous at best....although it looks like you could reach a small "
        "side-tunnel from here, if you were to %^CYAN%^wade %^BLUE%^through "
        "a shallow-looking patch of flowing water.%^RESET%^",
       ({"bridge","boards"}) : "%^ORANGE%^Thick planks stretch over the "
"churning water, providing a passage across the underground river.  Supported on "
"either side by large boulders, their surfaces are wet and there are no visible "
"signs of handholds, making this a dangerous crossing to say the least.",
      ({"boulder","boulders","stones","rocks","stone","rock"}) : "%^BOLD%^%^BLACK%^These granite stones appear to be part of what was "
"removed from a nearby tunnel system.  Tool marks are clear upon their "
"surface and most show signs of having been shaped to some degree or "
"another in order to make them fit together so well.%^RESET%^",
    ]));

    set_exits(([
      "east" : TUNNEL"tunnel16",
      "southwest" : "/d/underdark/upper/cross13",
    ]));
}

void init() {
    ::init();
    add_action("wade","wade");
}

int wade(string str) {
    if(TP->query_level() < 16) {
        tell_object(TP,
            "%^BOLD%^%^CYAN%^You don't feel confident enough to try that."
        );
        return 1;
    }
    tell_object(TP,
        "%^BOLD%^%^BLUE%^You ease yourself carefully into the water, and attempt "
        "to edge your way across the flowing river...\n\n%^CYAN%^However, you "
        "cannot stand up to the river's current, and are soon swept away!"
    );
    tell_room(TO,
        "%^BOLD%^%^CYAN%^"+TP->QCN+" %^BLUE%^eases "+TP->QP+"self "
        "carefully into the water, and attempt to edge %^CYAN%^"+TP->QP+
        "%^BLUE%^ way across the flowing river...\n\n%^CYAN%^However, "
        +TP->QS+" cannot stand up to the river's current, and is soon swept away!"
    ,({TP}));
    TP->move(BASE"entry_sequence");
    return 1;
}
