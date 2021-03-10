#include <std.h>
#include "../inherits/area_stuff.h"
#include <daemons.h>

inherit ROOM;
int searched;
object ob;

void create() 
{
    ::create();
    set_property("no teleport", 1);
    set_property("light",0);
    set_property("indoors",1);
    set_name("A massive dirt chamber");
    set_short("%^BOLD%^%^YELLOW%^A massive dirt chamber%^RESET%^");
    set_terrain(BUILT_TUNNEL);
    set_travel(PAVED_ROAD);
	//set_terrain(LIGHT_FOREST);
   	//set_travel(DIRT_ROAD);

    set_long("%^BOLD%^%^YELLOW%^This massive dirt %^RESET%^"+
    "%^MAGENTA%^chamber %^BOLD%^%^YELLOW%^"+
    "sprawls out in all directions. The %^RESET%^ceiling "+
    "%^BOLD%^%^YELLOW%^hangs far overhead and "+
    "monstrous %^RESET%^%^MAGENTA%^roots%^BOLD%^%^YELLOW%^"+
    " jut down from it in twisted shapes. The %^RESET%^walls "+
    "%^BOLD%^%^YELLOW%^are almost as smooth as glass, "+
    "as if intentionally made that way. "+
    "The %^RESET%^floor%^BOLD%^%^YELLOW%^ is "+
    "horribily uneven and littered with too many "+
    "%^BOLD%^%^WHITE%^bones%^BOLD%^%^YELLOW%^"+ 
	" to count. A %^BOLD%^%^WHITE%^thick spider's web "+
    "%^RESET%^%^BOLD%^%^YELLOW%^seems to be concentrated on "+
    "the %^RESET%^southern wall%^BOLD%^%^YELLOW%^"+
    " of the chamber with a few other "+
    "%^BOLD%^%^WHITE%^webs%^BOLD%^%^YELLOW%^"+
    " scattered through the chamber. A dirt tunnel "+
    "opens out of this chamber on the west wall.%^RESET%^");

    set_smell("default","A strong odor of mildew mixes with decay here.");
    set_listen("default","Skittering and screeching noises echo all around you.");

    set_search("default", "What do you want to search? The web on "+
    "the southern wall and the bones draw your attention.");

    set_items(([({"chamber", "dirt chamber"}) : "%^RESET%^"+
    "%^MAGENTA%^This dirt chamber is massive and it sprawls "+	
    "out in every direction. It is obviously the feeding grounds "+
    "of something and judging from the amount of spider "+
    "web in this area the answer is fairly obvious.%^RESET%^",
    ({"ceiling", "roots"}) : "%^YELLOW%^The ceiling "+
    "of this chamber hangs high over head and monstrous "+
    "roots jut down from it in twisted shapes.%^RESET%^",
    ({"wall","walls"}) : "%^MAGENTA%^The walls "+
    "here are almost as smooth as glass. A break in "+
    "them on the western wall offers an exit from this "+
    "chamber.%^RESET%^", 
    ({"floor", "bones"}) : "%^BOLD%^%^WHITE%^"+
    "The floor here is littered with multitudes of "+
    "bones, far too many to count, and most of them "+
    "are scratched and chipped.%^RESET%^",
    ({"web", "spiders web", "thick web", 
    "thick spiders web", "heavy spider webs", 
    "south spider web", "spider web", "south wall",
    "southern wall"}) : "%^BOLD%^%^WHITE%^The "+
    "thick spider web seems to be concentrated on the "+
    "southern wall of this chamber with a few other "+
    "webs scattered through the chamber.%^RESET%^",
    ]) ); 
	
    set_exits((["west" : FFTR"39", "south" : FFGTR"1"]));
    set_invis_exits(({"south"}));
    set_search("south web", (:TO, "south_web":));
    set_search("south wall", (:TO, "south_web":));
    set_search("southern wall", (:TO, "south_web":));
    set_search("bones", (:TO,"bones_search":));
    searched = 0;
}

int bones_search(string ob)
{
    if(!objectp(TP)) return 0;
    if(!objectp(TO)) return 0;
    if(present("ahyriquel", TO)) 
    {
        tell_object(TP, "%^BOLD%^%^BLACK%^The spider queen "+
        "prevents you from searching the bones!%^RESET%^");
        return 1;
    }
    if(searched)
    {
        tell_object(TP, "%^BOLD%^%^WHITE%^You patiently "+
        "dig through the vast hoard of bones but find "+
        "nothing of value.%^RESET%^");
        return 1;
    }
    //let Vanity be here sometimes 
    switch(random(3))
    {
        case 0..1:
            ob = new("/d/common/obj/weapon/scimitar");
            ob->set_property("enchantment", 2);
            break;
        case 2:
            ob = new(FFOB+"vanity");
            break;
    }
    if(!objectp(ob)) 
    {
        tell_object(TP, "ERROR - Object Failed to Load. "+
        "Bug Report this message and this room. Thanks. Saide");
        return 1;
    }
    tell_object(TP, "%^BOLD%^%^WHITE%^You carefully dig through the "+
    "bones and find a "+ob->query_short()+"%^BOLD%^%^WHITE%^"+
    "!%^RESET%^");
    tell_room(TO, TPQCN+"%^BOLD%^%^WHITE%^ digs through the bones and "+
    "finds a "+ob->query_short()+"%^BOLD%^%^WHITE%^!%^RESET%^", TP);
    ob->move(TO);
    searched = 1;
}


int south_web(string ob)
{
    if(!objectp(TP)) return 0;
    if(!objectp(TO)) return 0;
    if(!TP->query_invis())
    {
        tell_room(TO, TPQCN +"%^BOLD%^%^WHITE%^ carefully searches "+
        "the spider webs on the southern wall of the room.%^RESET%^",TP);
    }

    tell_object(TP, "%^BOLD%^%^WHITE%^You carefully search the "+
    "spider webs on the southern wall of this room and realize "+
    "that they are concealing another opening that leads out of "+
    "this chamber!%^RESET%^");
    return 1;
}

void reset()
{
    object queen;
    ::reset();
    if(random(3))
    {
        if(present("ahyriquel", TO)) return;
        queen = new(FFMON+"ahyriquel");
        searched = 0;
        queen->move(TO);	
    }
}