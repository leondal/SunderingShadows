#include <std.h>
#include "/d/dagger/road/short.h"
inherit ROOM;

void create(){
    ::create();
    set_terrain(OLD_MOUNTS);
    set_travel(DIRT_ROAD);
    set_property("light", 2);
    set_name("A Narrow Footpath");
    set_short("A Narrow Footpath");
    set_long("%^ORANGE%^This path leads around the impressive red stone "
"building to a clearing that lies beside it.  The worn path beneath your "
"feet spreads to form a tidy circle of earth at its end, in the centre of "
"which stands an %^RED%^arcing portal %^ORANGE%^that rises far above your head.  Made of "
"the same red stone as the building itself, it stands separate but is "
"obviously part of the same design.\n");
    set_smell("default", "The scent of the marsh is mingled with that of sweat.");
    set_listen("default", "You can hear the occasional clang of steel against steel.");
    set_items( ([
        "plains" : "These emerald plains span a great distance.",
        ({"trees", "forest"}) : "The tops of the great trees of the "+
         "Kilkean forest are barely visible in the distance.",
        ({"building","temple"}) : "The large red stone building "+
         "beside you looks to be some sort of military "+
         "compound.  The entrance lies back to the southwest.",
        ({"portal","arch","archway"}) : "The grand archway rises "+
         "above your head, made of the same red stone as the building.  "+
         "No purpose is disclosed as to the reason for its "+
         "construction, as it seems empty and inert.  Perhaps you "+
         "could %^BOLD%^%^WHITE%^<enter>%^RESET%^ it?"
    ]) );
    set_exits( ([
       "southwest" : RPATH"p8",
       "enter" : "/d/undead/rooms/town/portal",
    ]) );
    set_invis_exits(({"enter"}));
    set_pre_exit_functions(({"enter"}),({"go_portal"}));
}

int go_portal() {
    tell_object(TP,"%^BOLD%^%^CYAN%^There is a sudden flash as you step "
"through the portal, and you find yourself elsewhere!%^RESET%^");
    tell_room(TO,"%^BOLD%^%^CYAN%^There is a bright flash as "+TP->QCN+
" steps through the portal and disappears!%^RESET%^",TP);
    return 1;
}
