#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit WFTRAIL;

void create() {
    ::create();
    set_short("%^RED%^Near the altar of fire.%^RESET%^");
    set_long(TO->query_long()+"%^BOLD%^%^BLACK%^  An %^RED%^altar"+
    "%^BOLD%^%^BLACK%^ made of controlled %^RED%^fire"+
    "%^BOLD%^%^BLACK%^ stands unattended here.%^RESET%^");
    set_exits(([
       "west" : F_ROOMS"33-15",
       "south" : F_ROOMS"32-14",
       "north" : F_ROOMS"32-16",
       "northwest" : F_ROOMS"33-16",
       "southwest" : F_ROOMS"33-14",
    ] ));
    add_items(({"altar","fire altar","altar of fire"}),"%^RED%^"+
    "This massive altar of fire stands here, unattended.  It is "+
    "burning brightly, yet the fire is controled.  Closer inspection "+
    "reveals the presence of a light %^BLUE%^blue%^RESET%^%^RED%^ "+
    "barrier surrounding it.  At the bottom of it is a plaque "+
    "that you could read.%^RESET%^");
}
void reset() {
    ::reset();
    if(!pointerp(TO->query_exits())) return;
    if(member_array("portal",TO->query_exits()) != -1) {
        TO->remove_exit("portal");
    }
}

void init() {
    ::init();
    add_action("__Read_me","read");
    add_action("say_func","say");
}

int say_func(string str) {
    str = "/daemon/filters_d"->filter_colors(str);
    if((str != "Kinorda" && str != "kinorda") || !present("dekukinordaemberkey",TP)) {
        return 0;
    }
    if(member_array("portal",TO->query_exits()) != -1) {
        return 0;
    }
    tell_room(TO,TPQCN+"%^RED%^ starts to say something and before "+
    TP->QS+" can even complete the word, the "+
    "ember "+TP->QS+" carries falls to ash and an explos%^YELLOW%^"+
    "i%^RESET%^%^RED%^on of f%^YELLOW%^i%^RESET%^%^RED%^r%^YELLOW%^"+
    "e%^RESET%^%^RED%^ erupts upward from the altar to form a "+
    "portal on top of it.%^RESET%^",TP);
    
    tell_object(TP,"%^RED%^Before you can even complete the word, the "+
    "ember you carry falls to ash and an explos%^YELLOW%^i%^RESET%^"+
    "%^RED%^on of f%^YELLOW%^i%^RESET%^%^RED%^r%^YELLOW%^"+
    "e%^RESET%^%^RED%^ erupts upward from the altar to form a "+
    "portal on top of it.%^RESET%^");
    present("dekukinordaemberkey",TP)->remove();
    TO->add_exit(FTUN_ROOMS"firetemple5","portal");
    return 0;
}
    

int __Read_me(string str) {
    	if(str == "plaque" || str == "altar") 
	{
    write(
@SAIDE
The altar that you now behold is a gateway into the realm of 
a man that was long ago forgotten.  What lies within the gate
is of disturbing consequence.

There is only one way to open the gateway, the curious and 
ultimately foolish should seek out the elemental of fire 
and speak to him about the altar.
SAIDE
    );
    return 1;
    }
    return 0;
}