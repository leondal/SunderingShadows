#include <std.h>
inherit ROOM;

void create() {
        ::create();
        set_property("indoors",0);
        set_property("light",2);
        set_terrain(LIGHT_FOREST);
        set_travel(FOOT_PATH);
        set_name("Middle of the grove");
        set_short("%^GREEN%^Middle of the grove%^RESET%^");
        set_long("%^GREEN%^You now stand in the long si%^RESET%^"+
           "%^WHITE%^lv%^RESET%^%^GREEN%^er-g%^RESET%^%^WHITE%^re"+
           "%^RESET%^%^GREEN%^en grass of the grove.  "+
           "%^RESET%^%^BOLD%^Stone pillars%^RESET%^ %^GREEN%^lay "+
           "broken and strewn through the grass, covered in moss.  "+
           "A well-worn path has been trampled through the grass and "+
           "branches off in four different directions.  To your west "+
           "is a clearing with a circle of large stones dominating the "+
           "area.  To the distant east is a shaded garden.  The rest "+
           "of the grove is dwarfed by the giant o%^RESET%^%^YELLOW%^a"+
           "%^RESET%^%^GREEN%^k that stands to the south, watching the "+
           "grove silently.  To the north is the overgrown pathway "+
           "leading away from the temple.  A few travellers pass by, "+
           "speaking amongst themselves or moving as silently as a "+
           "shadow.%^RESET%^\n");
        set_items(([
           ({"pillars", "stone pillars"}) : "%^BOLD%^%^WHITE%^These "+
              "once prominent pillars now lay crumbled, covered in"+
              "%^RESET%^ %^GREEN%^ivy and moss%^RESET%^", 
           ({"path", "pathway"}) : "%^YELLOW%^The feet of many "+
              "visitors to the grove have worn paths through the "+
              "long grass.%^RESET%^", 
           "grass" : "%^GREEN%^The grass stands about three feet high, "+
              "swaying back and forth in the wind.%^RESET%^"
        ]));
        set_smell("default","%^GREEN%^The refreshing smell of grass "+
           "is all around.%^GREEN%^");
        set_listen("default","%^RED%^The sound of nesting birds "+
           "provides a noisy distraction.%^RESET%^");
        set_exits(([
           "north" : "/d/magic/temples/mielikki_entrance",
           "south" : "/d/magic/temples/mielikki",
           "west" : "/d/magic/temples/mielikki_circle",
           "east" : "/d/magic/temples/mielikki_garden"
        ]));
}