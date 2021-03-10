#include "/d/islands/dallyh/ways.h"
#include "/d/islands/dallyh/fways.h"
inherit DFOREST;

void create()
{
    ::create();
    set_name("Cliffs");
    set_short("Cliffs");
    set_property("outdoors",0);
    set_property("light",1);
    set_terrain(HEAVY_FOREST);
    set_travel(FOOT_PATH);
    set_long(TO->query_long()+"
%^RESET%^%^GREEN%^A %^BOLD%^%^WHITE%^sheer cliff%^RESET%^%^GREEN%^ "+
    "falls a good forty feet down to an %^BOLD%^ancient and gloomy marsh%^RESET%^%^GREEN%^ at "+
    "the northern edge of the forest. It looks like you can <descend> here.%^RESET%^");
    add_item(({"cliff", "cliffs"}), "%^BOLD%^%^WHITE%^This sheer cliff seems to almost severe the forest "+
    "here, serving as a boundary into the gloomy and ancient marsh about forty feet below. You could "+
    "%^RESET%^climb%^BOLD%^%^WHITE%^ down if you were so inclined, but the marsh looks far from inviting."+
    "%^RESET%^");
    add_item(({"marsh", "gloomy marsh", "ancient marsh"}), "%^BOLD%^%^BLACK%^This ancient and gloomy marsh extends for as "+
    "far as the eye can see northward. You suspect that at some time, long forgotten, the marsh was but another "+
    "section of the forest. Now it no longer appears inviting, but spews a forboding and dreadful aura.%^RESET%^");   
    
    set_exits(([
        "south" : FRPATH "forest7",
    ]));
    
    set_smell("default","\nThe lush fragrances of the forest mix with something foul wafting up from the depths "+
    "of the marsh.");
    set_listen("default","The sounds of forest life are overwhelmed by screams and growls rising up from the marsh.");
    set_climb_exits((["descend":({ "/d/islands/dallyh/marsh/rooms/marshenter",25,15,300})]));
    set_fall_desc(
        "You fall down about 40 feet. You land on some rocks, and other debris. Pain racks your body."
    );
    set_pre_exit_functions(({"descend"}),({"go_descend"}));
}

int go_descend() 
{
    int x;
    if(TP->query_highest_level() < 35) 
    {
        tell_object(TP, "%^BOLD%^%^BLACK%^You are unable to descend into the marsh.... a terrible feeling threatens to overtake you when you attempt.%^RESET%^");
        tell_object(TP, "%^B_CYAN%^%^YELLOW%^OOC: This area is now meant for level 35+ adventures. In order to prevent needless deaths I have restricted access to level 35. ");
        return 0;
    }
    return 1;
}


