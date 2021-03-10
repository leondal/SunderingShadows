#include <std.h>
#include "area_stuff.h"
#include <daemons.h>
#include <move.h>
#include "/d/common/common.h"

inherit WORM;
int searched;

void populate_area()
{
    if(strsrch(base_name(TO), "1_") != -1)
    {
        switch(random(12)) 
        {
            case 0..4:
                set_monsters(({}), ({}));
                break;
            case 5..8:
                set_monsters( ({WMON+"young_purple_worm",}), ({ 1 }) );
                break;
            case 9..11:
                set_monsters( ({ WMON+"young_purple_worm"}), ({ 1 + random(2) }) );
                break;      			
        }
        set_repop(20);   
    }
    else if(strsrch(base_name(TO), "2_") != -1)
    {
        switch(random(12)) 
        {
            case 0..4:
                set_monsters(({}), ({}));
                break;
            case 5..8:
                set_monsters( ({WMON+"adult_purple_worm",}), ({ 1 }) );
                break;
            case 9..11:
                set_monsters( ({ WMON+"adult_purple_worm"}), ({ 1 + random(2) }) );
                break;      			
        }
        set_repop(25);   
    }
    else if(strsrch(base_name(TO), "1_") != -1)
    {
        switch(random(12)) 
        {
            case 0..4:
                set_monsters(({}), ({}));
                break;
            case 5..8:
                set_monsters( ({WMON+"greater_purple_worm",}), ({ 1 }) );
                break;
            case 9..11:
                set_monsters( ({ WMON+"greater_purple_worm"}), ({ 1 + random(2) }) );
                break;      			
        }
        set_repop(35);   
    }
    
}

void create() 
{
    populate_area();    
    ::create();
    set_name("In a cavern of stone and earth");
    set_short("%^BOLD%^%^MAGENTA%^In a cavern of %^BOLD%^%^WHITE%^stone"+
    "%^BOLD%^%^MAGENTA%^ and %^RESET%^%^ORANGE%^earth%^RESET%^");

    set_long("%^BOLD%^%^MAGENTA%^This massive cavern has been burrowed out from "+
    "a composition of %^BOLD%^%^WHITE%^stone%^BOLD%^%^MAGENTA%^ and %^RESET%^%^ORANGE%^"+
    "earth%^BOLD%^%^MAGENTA%^. It is instantly obvious that it is not the work of "+
    "any normal craftsman, nor is it a naturally occuring cavern. What serves as "+
    "the walls, floor, and ceiling all look as if they have been chewed into "+
    "existence. You notice no %^RESET%^%^GREEN%^roots%^BOLD%^%^MAGENTA%^ in this "+
    "portion of the cavern. You are not sure if they have all been chewed away or if "+
    "perhaps you are far enough into the earth to be below them. The entire cavern "+
    "is nothing less than filthy, with monstrous %^RESET%^%^WHITE%^piles%^BOLD%^"+
    "%^MAGENTA%^ of dirt and rock strewn all about the haphazard floor. At times "+
    "the entire cavern seems to shake and you wonder about the stability of "+
    "it.%^RESET%^");

    set_smell("default","\nAn odor that reminds you of unwashed filth assaults your senses.");
    
    set_listen("default","The sound of earth rumbling fills the air.");				
	
    set_items(([
    
       ({"wall", "walls", "floor", "ceiling", "cavern", 
       "stone", "earth", "roots"}) : "%^BOLD%^%^MAGENTA%^The walls, floor, and ceiling "+
       "of this cavern look like they have been chewed out from stone and earth. "+
       "You are not sure what created this cavern but it must have been a very "+
       "large creature. There are no roots in this portion of the cavern and you "+
       "are not sure if it is because they have all been chewed away or if you are "+
       "far enough into the earth to be below them. It is littered with monstrous piles "+
       "of dirt and rock and is nothing short of filthy. It constantly "+
       "shakes and you wonder about the stability of it.%^RESET%^",
       
       ({"piles", "rocks", "stones", "piles of rock and stone"}) : "%^RESET%^%^WHITE%^"+
       "These monstrous piles of dirt and rock are strewn about chaotically on the "+
       "haphazard floor. You are not sure if they have been placed about intentionally or "+
       "perhaps are remnants of the very cavern deteriorating. You are also not "+
       "sure if they might contain something worthwhile or not.%^RESET%^"
       
    ]));
      
    set_property("light",-2);
    set_property("indoors",1);

    set_terrain(NAT_CAVE);
    set_travel(SLICK_FLOOR);
	
    searched = random(10);
    
    set_search("default", "%^RESET%^%^ORANGE%^You think that the "+
    "piles of dirt and rocks could possibly hide something.%^RESET%^");
    
    set_search("piles", (:TO, "mySearch":));
    set_search("monstrous piles", (:TO, "mySearch":));    
    set_search("dirt", (:TO, "mySearch":));
    set_search("rock", (:TO, "mySearch":));
    set_search("piles of dirt", (:TO, "mySearch":));
    set_search("piles of rock", (:TO, "mySearch":));
}

void allow_search() { searched = 0; }

void test() { return WORMTREAS; }

int mySearch(string str)
{
    object ob;
    if(!objectp(TP)) return 0;
    if(!objectp(TO)) return 0;
    if(searched) 
    {
        tell_object(TP, "%^BOLD%^%^MAGENTA%^You carefully search the "+str+" but find nothing "+
        "of interest.%^RESET%^");
        if(!TP->query_invis()) 
        {
            tell_room(TO, TPQCN+"%^BOLD%^%^MAGENTA%^ searches the "+str+
            "carefully but doesn't seem to find anything of "+
            "value.%^RESET%^", TP);
        }
        return 1;
    }	
    ob = test()->find_stuff();
    if(!objectp(ob)) 
    {
        tell_object(TP, "%^BOLD%^%^MAGENTA%^You carefully search the "+str+" but find nothing "+
        "of interest.%^RESET%^");
        if(!TP->query_invis()) 
        {
            tell_room(TO, TPQCN+"%^BOLD%^%^MAGENTA%^ searches the "+str+
            "carefully but doesn't seem to find anything of "+
            "value.%^RESET%^", TP);
        }
        return 1;
    }	
    tell_object(TP, "%^RESET%^%^MAGENTA%^You search the "+str+" carefully and "+
    "manage to find "+ob->query_short()+"%^RESET%^%^MAGENTA%^!%^RESET%^");
    if(!TP->query_invis())
    {
        tell_room(TO, TPQCN+"%^RESET%^%^MAGENTA%^ searches the "+str+" carefully and "+
        "manages to find "+ob->query_short()+"%^RESET%^%^MAGENTA%^!%^RESET%^", TP);
    }
    if(ob->move(TP) != MOVE_OK)
    {
        tell_object(TP, "%^BOLD%^%^RED%^You drop "+ob->query_short()+"%^BOLD%^%^RED%^!%^RESET%^");
        ob->move(TO);
    }
    searched = 1;
    
    return 1;
}

void reset()
{
    ::reset();
    populate_area();
    searched = random(10);
}
