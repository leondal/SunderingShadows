#include <std.h>
#include "area_stuff.h"
#include <daemons.h>
#include "/d/common/common.h"
inherit CROOM;
int searched;

void create() 
{
    if(base_name(TO) != FFT && base_name(TO) != FFTE) 
    { 
        switch(random(11)) 
        {
            case 0..4:
                break;
            case 5..10:
                set_monsters(({FFMON+"acidic_spider"}), ({1 + random(2)}));
                break;      			
        }
        set_repop(40);
    }
    ::create();
    set_property("light",0);
    set_property("indoors",1);
    set_property("no teleport", 1);
    set_name("A dirt tunnel");
    set_short("%^BOLD%^%^YELLOW%^A dirt tunnel%^RESET%^");
    set_terrain(BUILT_TUNNEL);
    set_travel(PAVED_ROAD);
    //set_terrain(LIGHT_FOREST);
    //set_travel(DIRT_ROAD);

    set_long("%^BOLD%^%^YELLOW%^This massive tunnel resembles an %^RESET%^%^MAGENTA%^"+
    "animal burrow%^BOLD%^%^YELLOW%^ more than the careful work of a craftsman. It has been "+
    "%^RESET%^hollowed%^BOLD%^%^YELLOW%^ out of the very %^RESET%^ground"+
    "%^BOLD%^%^YELLOW%^ and it does not appear to be very "+
    "stable in any sense of the word. "+
    "The %^RESET%^walls%^BOLD%^%^YELLOW%^, %^RESET%^floor%^BOLD%^%^YELLOW%^, and "+
    "%^RESET%^ceiling%^BOLD%^%^YELLOW%^ are mostly smooth but very uneven. "+
    "%^RESET%^%^MAGENTA%^Roots%^BOLD%^%^YELLOW%^ of various sizes break into the "+
    "chamber though the walls and ceiling and snake across the floor. "+
    "A %^BOLD%^%^WHITE%^heavy%^BOLD%^%^YELLOW%^, %^BOLD%^%^WHITE%^thick "+
    "spider's web%^BOLD%^%^YELLOW%^ hangs over everything here and "+
    "there is almost no way to avoid walking through it.  Bits and pieces "+
    "of %^BOLD%^%^WHITE%^bones%^BOLD%^%^YELLOW%^ and %^BOLD%^%^WHITE%^"+
    "flesh%^BOLD%^%^YELLOW%^ litter the floor, partially obscurred by "+
    "web.%^RESET%^");
    set_smell("default","A strong odor of mildew mixes with decay here.");
    set_listen("default","Skittering and screeching noises echo all around you.");

    set_search("default", "What do you want to search?");

    set_items(([({"animal burrow", "burrow", "animal"}) : "%^MAGENTA%^"+
    "You are not sure what type of animal created this tunnel but it is most "+
    "certainly an animal burrow, as bones and bits of flesh from various "+
    "animals litter the uneven floor, partially hidden by the spider's "+
    "web.%^RESET%^",
    ({"hollowed", "ground", "walls", "floor", "ceiling"}) : "%^RESET%^"+
    "This tunnel has been hallowed out from the very ground. The "+
    "walls and ceiling are hosts to a multitude of roots which "+
    "snake across the floor haphazardly and offer a measure of "+
    "support. Otherwise, it is obviously not "+
    "very stable at all.%^RESET%^",
    ({"roots", "root"}) : "%^MAGENTA%^These roots are from the "+
    "many trees in the forest above.  Most of them are slowly "+
    "decaying but their presence seems to be adding "+
    "some structural support to this tunnel.%^RESET%^",
    ({"bones", "flesh"}) : "%^BOLD%^%^WHITE%^These bits and "+
    "pieces of bone and flesh are from various animals and "+
    "some even appear human.  They litter the floor here "+
    "and are partially obscurred by the thick spider's "+
    "web.%^RESET%^",
    ({"web", "spiders web", "thick web", 
    "thick spiders web", "heavy spider webs"}) : "%^BOLD%^%^WHITE%^This thick "+
    "spider web hangs over almost everything in this area, offering some "+
    "insight into what type of life remains here. "+
    "The amount of web suggests a tremendous multitude of spiders call "+
    "this place home.%^RESET%^",
    ]) ); 

    searched = random(4);

    set_search("webs", (:TO, "mySearch":));
    set_search("web", (:TO, "mySearch":));	
    set_search("room", (:TO, "mySearch":));
    set_search("bones", (:TO, "mySearch":));
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

void CheckCollapse()
{
    string cexit, *exits;
    int x, y;
    if(!objectp(TO)) return;
    if(!sizeof(TO->query_exits())) return;
    if(sizeof(TO->query_buried_exits())) return;
    if(random(35)) return;
    y = random(10);
    x = sizeof(TO->query_exits());
    exits = TO->query_exits();
    if(x == 1) y = 1;
    switch(random(10))
    {
        case 0..8:
            cexit = exits[random(x)];
            tell_room(TO, "%^BOLD%^%^BLACK%^A violent shuddering "+
            "causes you to almost fall to your knees as "+
            "the very earth around you seems to "+
            "move and you watch in horror as the opening "+
            "to the %^BOLD%^%^RED%^"+
            cexit+"%^BOLD%^%^BLACK%^ collapses!%^RESET%^");
            TO->collapse_exit(cexit, 100);
            break;
        case 9:
            tell_room(TO, "%^BOLD%^%^BLACK%^A violent shuddering "+
            "causes you to almost fall to your knees as "+
            "the very earth around you seems to move "+
            "and you watch in horror as %^BOLD%^%^RED%^"+
            "ALL%^BOLD%^%^BLACK%^ the openings leading "+
            "out of here collapse!%^RESET%^");
            TO->collapse_all_exits(100);
            break;
    }
    return;
}

/*void init()
{
	::init();
	//Something quite buggy about this happening on init - Saide.
	//CheckCollapse();
}*/
