#include <std.h>
#include "../../ud_ruins.h"
inherit STORAGE"_river_base";

void create() {
    ::create();
    set_exits(([
        "north" : ROOMS"river/river_3",
        "west" : ROOMS"river/river_2",
        "ravine" : ROOMS"river/rapids",
        ]));
    add_item("ravine",
        "%^BOLD%^%^BLUE%^The river takes a steep plunge into a deep ravine here, "
        "bottoming out perhaps fifty feet down and continuing along through a dark "
        "and narrow tunnel."
    );
    set_pre_exit_functions(({"ravine"}),({"ravine_func"}));
}

void init() {
    ::init();
    add_action("sneak_func","sneak");
}

int ravine_func() {
    if(TP->query_property("warned about rapids")) {
        TP->remove_property("warned about rapids");
        tell_object(TP,
            "%^BOLD%^%^CYAN%^You steady yourself before taking the long "
            "plunge into the ravine!"
        );
        tell_room(TO,
            "%^BOLD%^%^CYAN%^"+TP->QCN+" steadies "+TP->QO+"self before "
            "taking the long plunge into the ravine!"
        ,({TP}));
        return 1;
    }
    tell_object(TP,
        "%^CYAN%^The river takes a steep plunge into a deep ravine here, "
        "bottoming out perhaps fifty feet down and continuing along through a "
        "dark and narrow tunnel. Jumping may lead you out of this cavern, but "
        "there is no guarantee that you will survive the trip. Are you sure you "
        "want to do this?"
    );
    tell_room(TO,
        "%^BOLD%^%^CYAN%^"+TP->QCN+" stops at the edge of the ravine and "
        "looks down, appearing to hesitate."
    ,({TP}));
    TP->set_property("warned about rapids",1);
    return 0;
}

int sneak_func(string str) {
    if(str == "ravine") {
        tell_object(TP,"There isn't much room to sneak, there.");
        return 1;
    }
}
