#include <std.h>
#include "area_stuff.h"
#include <daemons.h>
#include "/d/common/common.h"

inherit VAULT;
int disturbed, spiders;

void create() 
{
    ::create();
    set_property("light",1);
    set_property("indoors",1);
    set_name("A ruined building");
    set_short("%^BOLD%^%^RED%^A ruined building%^RESET%^");
    set_terrain(BUILT_TUNNEL);
    set_travel(PAVED_ROAD);
    //set_terrain(LIGHT_FOREST);
    //set_travel(DIRT_ROAD);

    set_long("%^BOLD%^%^RED%^The building you are standing "+
    "in is now a ruined husk of its former self. The fragments of it "+
    "that are still standing are %^BOLD%^%^BLACK%^charred%^BOLD%^"+
    "%^RED%^ to that point that the materials from which it was "+
    "built are now unidentiable. A thick layer of "+
    "%^MAGENTA%^dust%^BOLD%^%^RED%^ has settled over most of "+
    "the remainder of it and a thick %^BOLD%^%^WHITE%^"+
    "spider's web%^BOLD%^%^RED%^ is spun chaotically "+
    "throughout. In the center of the building there "+
    "are layers upon layers of %^BOLD%^%^WHITE%^web"+
    "%^BOLD%^%^RED%^ spun into a great mass. It appears to be a "+
    "%^BOLD%^%^WHITE%^giant nest%^BOLD%^%^RED%^.%^RESET%^");

    set_smell("default","A lingering odor of decay hangs heavily "+
    "in the air here.");
    set_listen("default","Skittering and screeching noises echo all around you.");

    set_search("default", "%^BOLD%^%^WHITE%^The giant nest in "+
    "the center of the building draws your attention.%^RESET%^");

    set_items(([
    ({"charred", "ruins", "building", "husk",
    "remains"}) : "%^BOLD%^%^BLACK%^The charred remains of "+
    "this building are just a husk of whatever it might have "+
    "once been. The materials from which it was originally made "+
    "have long since been forgotten.%^RESET%^",
	
    ({"dust", "layer","thick dust"}) : "%^MAGENTA%^"+
    "This thick layer of dust covers almost everything here "+
    "but it has been disturbed recently and the web is "+
    "on top of it.%^RESET%^",
	
    ({"mass", "nest", "giant nest"}) : (:TO, "nest_state":),
	
    ({"web", "spiders web", "thick web", 
    "thick spiders web", "heavy spider webs"}) : "%^BOLD%^%^WHITE%^This thick "+
    "spider web is spun chaotically about this entire "+
    "building. It seems to originate outward from the great mass of "+
    "web in the center of the building.%^RESET%^",
    ]) ); 
    if(random(2)) disturbed = 1;
    spiders = 1 + random(3);
    set_search("nest", (:TO, "mySearch":));
    set_search("mass", (:TO, "mySearch":));	
    set_search("giant nest", (:TO, "mySearch":));
}

void SpidersEngage()
{
    object mon;
    if(!objectp(TO)) return;
    switch(random(10))
    {
        case 0..7:
            mon = new(FFMON+"spiderling");
            break;
        case 8:
            mon = new(FFMON+"monstrous_spider");
            break;
        case 9:
            mon = new(FFMON+"acidic_spider");
            break;
    }
    tell_room(TO, "%^BOLD%^%^RED%^An angry "+mon->query_short()+
    "%^BOLD%^%^RED%^ crawls quickly out of the giant nest!%^RESET%^");
    mon->move(TO);
    spiders--;
    if(spiders > 0) 
    {
        call_out("SpidersEngage", 8);
    }
    return;
}
	

int mySearch(string ob)
{
	if(!objectp(TP)) return 0;
	if(!objectp(TO)) return 0;
	if(disturbed) 
	{
		tell_object(TP, "%^BOLD%^%^WHITE%^You realize that the "+
		"nest has already been disturbed recently.%^RESET%^");
		return 1;
	}	
	disturbed = 1;
	if(random(3)) 
	{
		tell_object(TP, "%^BOLD%^%^WHITE%^You manage to find something of "+
		"value in the nest!%^RESET%^");
		if(!TP->query_invis())
		{
			tell_room(TO, TPQCN+"%^BOLD%^%^WHITE%^ searches the nest and "+
			"seems to find something of value!%^RESET%^", TP);
		}
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
    else
    {
        tell_object(TP, "%^BOLD%^%^WHITE%^You quickly abandon your search as "+
        "something begins moving inside the nest!%^RESET%^");

        if(!TP->query_invis())
        {
            tell_room(TO, TPQCN+"%^BOLD%^%^WHITE%^ searches the nest "+
            "and quickly abandons "+
            TPQP+" search as something begins stirring "+
            "inside of it!%^RESET%^", TP);
        }
        else
        {
            tell_room(TO, "%^BOLD%^%^WHITE%^Something begins stirring "+
            "within the giant nest!%^RESET%^", TP);
        }
        SpidersEngage();
    }
    return 1;
}

void reset()
{
    ::reset();
    if(disturbed == 1)
    {
        if(!random(2)) disturbed = 0;
        spiders = 1 + random(3);    
    }

}
	


string nest_state()
{
    string desc;
    desc = "%^BOLD%^%^WHITE%^The giant mass of web here "+
    "is spun from layers upon layers of thick spider's web. "+
    "It might contain something of value, if you were brave "+
    "enough to search it. It is obviously a giant spider's "+
    "nest.";
    if(disturbed)
    {
        desc += "%^BOLD%^%^WHITE%^ It looks as empty now, "+
        "as if it were recently disturbed.%^RESET%^";
    }
    return desc;
}
		

