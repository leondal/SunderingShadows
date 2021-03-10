#include <std.h>
#include "area_stuff.h"
#include <daemons.h>
#include "/d/common/common.h"

inherit CVAULT;
int searched;

void create() 
{
    if(base_name(TO) != FFO) 
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
    set_property("light",2);
    set_property("indoors",0);
    set_name("An abandoned farm");
    set_short("%^RESET%^%^GREEN%^An abandoned farm%^RESET%^");
    //set_terrain(BUILT_TUNNEL);
    //set_travel(PAVED_ROAD);
    set_terrain(LIGHT_FOREST);
    set_travel(DIRT_ROAD);

    set_long("%^RESET%^%^GREEN%^The area around you is what remains of a once prestigious farm. "+
    "The %^BOLD%^%^WHITE%^skeletal remains%^RESET%^%^GREEN%^ of what were once %^BOLD%^%^MAGENTA%^"+
    "proud buildings%^RESET%^%^GREEN%^ dot the landscape in various "+
    "stages of %^BOLD%^%^RED%^decay%^RESET%^%^GREEN%^. The %^RESET%^%^WHITE%^road%^RESET%^%^GREEN%^"+
    " beneath your feet has crumbled to nothing more than bits of "+
    "%^RESET%^%^MAGENTA%^hard rock%^RESET%^%^GREEN%^ and %^RESET%^%^MAGENTA%^packed dirt%^RESET%^%^GREEN%^"+
    ", with %^BOLD%^vines%^RESET%^%^GREEN%^ and %^BOLD%^briars%^RESET%^%^GREEN%^ jutting up from it "+
    "periodically, an obvious testament to years of %^BOLD%^%^WHITE%^neglect%^RESET%^%^GREEN%^. "+
    "The %^BOLD%^trees%^RESET%^%^GREEN%^ in this area have largely died out and "+
    "what remains of them are %^BOLD%^towering husks%^RESET%^%^GREEN%^. A %^BOLD%^%^WHITE%^"+
    "thick spider's web%^RESET%^%^GREEN%^ is draped over almost "+
    "everything in this area.%^RESET%^");

    set_smell("default","A lingering odor of decay hangs heavily here.");
    set_listen("default","Skittering and screeching noises echo faintly around you.");

    set_search("default", "What do you want to search?");

    set_items(([({"remains", "skeletal remains", "skeletal", "buildings", "building", 
    "proud buildings"}) : "%^BOLD%^%^MAGENTA%^The skeletal remains of these once proud buildings dot "+
    "the landscape here.  They have almost all collapsed and whatever their "+
    "original purpose might have been has long since been forgotten.  One larger building in the center of the "+
    "area looks like it could have been a family's home but it too has lost all sense of purpose. "+
    "A thick spider's web hangs over most of them.%^RESET%^", 
    ({"neglect", "decay"}) : "%^RESET%^%^RED%^The decay and neglect here seem to be almost contagious. "+
    "They have spread from the the buildings, to the road, and have even impacted the trees. "+
    "There is no sense of hope here and whatever life remains does not seem to care.%^RESET%^", 
    ({"road", "rock", "hard rock", "dirt", "packed dirt", "vines", "briars"}) : "%^RESET%^%^MAGENTA%^The road here could very "+
    "well have once been meticulous but that time has long since passed.  All that even remains of a "+
    "road are bits of rock and packed dirt that has given birth to vines and briars.%^RESET%^", 
    ({"tree", "trees", "husks", "towering husks"}) : "%^RESET%^%^GREEN%^The trees scarcely resemble "+
    "those in the other areas of the forest here.  They have decayed and what remains are towering husks.  "+
    "A thick spider's web hangs over most of them, offering perhaps some insight into what type of "+
    "life remains here.%^RESET%^", 
    ({"web", "spiders web", "thick web", "thick spiders web"}) : "%^BOLD%^%^WHITE%^This thick spider web "+
    "hangs over almost everything in this area, offering some insight into what type of life remains here. "+
    "The amount of web suggests a tremendous multitude of spiders were here recently.%^RESET%^",
    ]) ); 

    searched = random(4);

    set_search("webs", (:TO, "mySearch":));
    set_search("web", (:TO, "mySearch":));	
    set_search("vines", (:TO, "mySearch":));
    set_search("buildings", (:TO, "mySearch":));
    set_search("road", (:TO, "mySearch":));
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
    object eggsac;
    ::reset();
    if(base_name(TO) == FFO) return;
    searched = random(4);
    if(!random(2))
    {
        if(present("eggsac 2", TO)) return;
        eggsac = new(FFOB+"eggsac");
        eggsac->move(TO);	
    }
    if(!random(4))
    {
        if(present("eggsac 2", TO)) return;
        eggsac = new(FFOB+"eggsac");
        eggsac->move(TO);	
    }
}