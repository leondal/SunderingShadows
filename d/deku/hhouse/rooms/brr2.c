#include <std.h>
#include "../inherits/area_stuff.h"
inherit BASEMENT;

int searched;

void create() 
{
    ::create();
    set_name("A small washroom");
    set_short("%^BOLD%^%^WHITE%^A small washroom%^RESET%^");

    set_property("is_washable", 1);

    set_long("%^BOLD%^%^WHITE%^The room that you find yourself in "+
    "is in remarkable condition compared to the rest of this place. "+
    "The ceiling is relatively intact and shows only mild signs of "+
    "decay. The walls of the room look sturdy and only slightly warped. "+
    "The floor is very uneven and some of the boards which construct "+
    "it have split apart. Overall, the %^RESET%^%^GREEN%^oak%^BOLD%^%^WHITE%^ "+
    "from which it all has been constructed is still in decent shape. "+
    "Scattered about the room are various tables, chairs, and "+
    "%^RESET%^%^ORANGE%^washboards%^BOLD%^%^WHITE%^. Wooden "+
    "%^RESET%^%^ORANGE%^buckets%^BOLD%^%^WHITE%^ with suprisingly clean water, "+
    "are stationed on most of the tables. Thick %^BOLD%^%^MAGENTA%^dust%^BOLD%^"+
    "%^WHITE%^ has built up over almost everything in the room and despite "+
    "the shape of the chamber, it is easy to tell that it has not been "+
    "used in a very long time.%^RESET%^");
	
    set_smell("default","\nThe smell of stale water hangs in the air.");
	
    set_listen("default","Silence lingers here interrupted by the occassional "+
    "drip of water.");			
			
    set_items(([
        ({"walls", "ceiling", "floor", "oak"}) : "%^RESET%^%^GREEN%^The oak that "+
        "constructs this room is in remarkable condition compared to the rest of this "+
        "place. The beams of the ceiling are mostly intact, the floor is only slightly "+
        "split, and the walls, though slightly warped, are still in decent shape.%^RESET%^",

        ({"table", "chairs", "washboards", "buckets", "water"}) : "%^RESET%^%^ORANGE%^"+
        "Chairs have been set up next to several tables in this room. Atop each of the "+
        "tables are washboards and wooden buckets of suprisingly clean water. You could "+
        "probably use the provided tools to %^BOLD%^%^WHITE%^<%^BOLD%^%^CYAN%^wash"+
        "%^BOLD%^%^WHITE%^> %^RESET%^%^ORANGE%^something if you wanted to.%^RESET%^",
		
        ({"dust", "thick dust"}) : "%^BOLD%^%^MAGENTA%^Despite the condition of "+
        "this room, there is a remarkable amount of thick dust settled over "+
        "most of it. It looks as if this room has not been used in ages.%^RESET%^",

    ]));
	
    set_property("light",1);
    set_property("indoors",1);
    set_property("no teleport", 1);
    set_terrain(WOOD_BUILDING);
    set_travel(DECAYED_FLOOR);
    searched = 0;
    TO->check_adjustment();
}

void init()
{
    ::init();
    add_action("wash_item", "wash");	
}

void reset()
{
    ::reset();	
}
int wash_item(string arg)
{
    object targ;
    int myStr;
    if(!objectp(TO)) return 0;
    if(!objectp(TP)) return 0;
    if(!arg) 
    {
        tell_object(TP, "What would you like to wash?");
        return 1;
    }
    if(!objectp(targ = present(arg, TP))) 
    {
        tell_object(TP, "You have no "+arg+ " to wash.");
        return 1;
    }
    if(targ->query_worn()) 
    {
        tell_object(TP, "You should remove "+arg+" before you try to wash it!");
        return 1;
    }
    if(targ->query_wielded())
    {
        tell_object(TP, "You should unwield "+arg+" before you try to wash it!");
        return 1;
    }	

    if(targ->id("hhousedingysaidesash")) 
    {
        tell_object(TP, "%^BOLD%^%^GREEN%^You quickly wash the sash, scrubbing and "+
        "scrubbing and are amazed as it is once again brilliant!%^RESET%^");		
        if(!TP->query_invis())
        {
            tell_room(TO, TPQCN+"%^BOLD%^%^GREEN%^ quickly washes "+TP->QP+" sash, scrubbing and "+
            "scrubbing into it is no longer dingy but quite brilliant!%^RESET%^", TP);
        }
        targ->clean_me_up();
        return 1;
    }
	
    tell_object(TP, "%^BOLD%^%^WHITE%^You go over to one of the washboards and quickly wash "+
    "your "+arg+"!");
    if(!TP->query_invis()) 
    {
        tell_room(TO, TPQCN+" %^BOLD%^%^WHITE%^goes over to one of the washboards and "+
        "quickly washes "+TP->QP + " "+arg+".", TP);
    }
    if(targ->id("paper") || targ->id("scroll") || targ->id("parchment")) 
    {
        tell_object(TP, "%^BOLD%^%^RED%^You instantly realize it was a bad idea to wash "+
        "your "+targ->query_short()+" as it saturates with water and comes apart!%^RESET%^");
        if(!TP->query_invis()) 
        {
            tell_room(TO, targ->QCN+"%^BOLD%^%^RED%^'s "+targ->query_short()+" gets satured with water and comes "+
            "apart!%^RESET%^", TP);
        }
        targ->remove();
        return 1;
    }
    return 1;
}
