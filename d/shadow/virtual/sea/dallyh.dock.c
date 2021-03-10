#include "/d/islands/dallyh/fways.h"
#include <objects.h>

inherit DOCK;

int is_virtual() { return 1; }
int is_water() { return 1; }
int is_dock() { return 1; }

void create()
{
// object ob;
    ::create();
    set_name("A sandy beach on the edge of the forest");
    set_short("%^BOLD%^%^YELLOW%^A sandy beach on the edge of the forest%^RESET%^");
    set_property("indoor",0);
    set_property("light",1);
    set_terrain(BEACH);
    set_travel(FOOT_PATH);
    set_long("%^BOLD%^%^YELLOW%^You stand on a peaceful sandy %^BOLD%^%^WHITE%^beach"+
    "%^BOLD%^%^YELLOW%^. Directly south is the massive Saakrune Sea. The "+
    "%^BOLD%^%^CYAN%^waves%^BOLD%^%^YELLOW%^ from the great sea lap away at the sand "+
    "without a care in the world, slowly eroding some of the coastline in the process. "+
    "A small old dock sits on the edge of the beach bouncing about carelessly on the "+
    "waves. "+
    "A vast %^BOLD%^%^GREEN%^forest%^BOLD%^%^YELLOW%^ encroaches on the "+
    "beach from the north. It is difficult to not be awestruck by the natural "+
    "beauty of the %^BOLD%^%^GREEN%^forest%^BOLD%^%^YELLOW%^ and your curiosity "+
    "is piqued as you wander about what creatures might call it home.%^RESET%^");

    set_items(([
        ({"beach", "sandy beach", "coastline"}) : "%^BOLD%^%^YELLOW%^This beach is magnificent. "+
        "The sand beneath your feet is soft and pure. The great ocean laps away at it, slowly "+
        "eroding the coastline. A vast impressive forest encroaches from the north.%^RESET%^",

        ({"forest", "vast forest", "beautiful forest"}) : "%^RESET%^%^GREEN%^This forest is "+
        "vast and beautiful. A great many of its trees reach towering heights, stretching up almost "+
        "as far as the eye can see. There are thick canopies of branches which make the view from "+
        "here even more impressive. It slowly encroaches on this peaceful beach.%^RESET%^",

        ({"saakrune sea", "waves", "sea" }) : "%^BOLD%^%^BLUE%^This waves of the massive "+
        "Saakrune Sea lap away at the coastline here, without a care in the world. The sea stretches "+
        "all the way to the horizon and beyond, you cannot help but to be awestruck by the "+
        "enormity of it.%^RESET%^",
    ]));


    set_smell("default","\nThe lush fragrances of the forest mixes with the scent of the ocean.");
    set_listen("default","The sound of the ocean waves slapping into the shore drowns out all else.");
    set_exits(([
        "north" : FRPATH "for1",
    ] ));
}
