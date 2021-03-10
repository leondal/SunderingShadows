#include <std.h>
#include "area_stuff.h"
#include <daemons.h>
#include "/d/common/common.h"
inherit CVAULT;
int searched;

void create() 
{
    if(base_name(TO) != FFC && base_name(TO) != FFCE) 
    { 
        switch(random(11)) 
        {
            case 0..6:
                break;
            case 7..10:
                set_monsters(({FFMON+"monstrous_spider"}), ({1 + random(2)}));
                break;      			
        }
        set_repop(40);
    }
    ::create();
    set_property("light",1);
    set_property("indoors",1);
    set_name("An abandoned cellar");
    set_short("%^RESET%^%^WHITE%^An abandoned cellar%^RESET%^");
    set_terrain(BUILT_TUNNEL);
    set_travel(PAVED_ROAD);
    //set_terrain(LIGHT_FOREST);
    //set_travel(DIRT_ROAD);

    set_long("%^BOLD%^%^BLUE%^This massive %^RESET%^%^WHITE%^cellar%^BOLD%^"+
    "%^BLUE%^ has long since been abandoned. "+
    "Its original purpose has been lost but judging by the fact that it still "+
    "stands while the rest of the farm around it has fallen victim to decay suggests "+
    "that it was an important one. The %^RESET%^%^CYAN%^walls%^BOLD%^%^BLUE%^"+
    ", %^RESET%^%^CYAN%^floor%^BOLD%^%^BLUE%^, and %^RESET%^%^CYAN%^ceiling%^BOLD%^%^BLUE%^"+
    " are composed of large chunks of %^BOLD%^%^CYAN%^bluish stone%^BOLD%^%^BLUE%^ "+
    "that once shined brilliantly but have faded to a dull sheen. %^BOLD%^%^WHITE%^"+
    "Thick spider's web %^BOLD%^%^BLUE%^is visible in every corner and crevice of this place. "+
    "Thick %^BOLD%^%^MAGENTA%^dust%^BOLD%^%^BLUE%^ has settled over most of the "+
    "remaining %^RESET%^%^WHITE%^cellar%^BOLD%^%^BLUE%^ but it looks as if it has been "+
    "recently %^RESET%^%^MAGENTA%^disturbed%^BOLD%^%^BLUE%^.%^RESET%^");

    set_smell("default","A strong odor of mildew hangs in the air .");
    set_listen("default","Skittering and screeching noises echo all around you.");

    set_search("default", "What do you want to search?");

    set_items(([({"cellar", "stone", "bluish stone", "chunks", "large chunks", "walls",
    "ceiling", "floor"}) : "%^RESET%^%^BLUE%^The large chunks of bluish stone which compose this cellar "+
    "were one quite magnificient and shined brilliantly but as the rest of this farm aged they have "+
    "faded to a dull sheen. The decay here is less pronounced than outside but still "+
    "neglect is still very evident. The ceiling, walls, and floor are still obviously quite "+
    "sturdy despite this neglect.%^RESET%^", 
    ({"dust", "disturbed"}) : "%^RESET%^%^MAGENTA%^The dust that hangs over much of this area "+
    "is quite thick but shows obvious signs of being recently disturbed.%^RESET%^",	
    ({"web", "spiders web", "thick web", "thick spiders web"}) : "%^BOLD%^%^WHITE%^This thick spider web "+
    "hangs over almost everything in this area, offering some insight into what type of life remains here. "+
    "The amount of web suggests a tremendous multitude of spiders call this place home.%^RESET%^",
    ]) ); 

    searched = random(4);

    set_search("webs", (:TO, "mySearch":));
    set_search("web", (:TO, "mySearch":));	
    set_search("room", (:TO, "mySearch":));
}


int mySearch(string ob)
{
    if(!objectp(TP)) return 0;
    if(!objectp(TO)) return 0;
    if(searched) 
    {
        tell_object(TP, "%^BOLD%^%^RED%^You carefully search around the "+
        "area but find nothing of value.%^RESET%^");
        if(!TP->query_invis()) 
        {
            tell_room(TO, TPQCN+"%^BOLD%^%^RED%^ searches around "+
            "carefully but doesn't seem to find anything of "+
            "value.%^RESET%^", TP);
        }
        return 1;
    }

    tell_object(TP, "%^BOLD%^%^GREEN%^You manage to find something of "+
    "value!%^RESET%^");
    if(!TP->query_invis())
    {
        tell_room(TO, TPQCN+"%^BOLD%^%^GREEN%^ searches around and "+
        "seems to find something of value!%^RESET%^", TP);
    }
    searched = 1;
    switch(random(25)) 
    {
        case 0..10:
            RANDTREAS->find_stuff(TO,"random");
            break;
        case 11..14:
            new("/d/common/obj/potion/cure_poison")->move(TO);
            break;
        case 15..24:
            RANDTREAS->find_stuff(TO,"random");
            break;
    }
    return 1;
}

void reset()
{
    ::reset();
    searched = random(4);
}



