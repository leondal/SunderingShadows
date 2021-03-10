#include <std.h>
#include "../inherits/area_stuff.h"
inherit FFTE;

void create() 
{
    ::create();
    set_property("fill waterskin", 1);
    set_long(TO->query_long()+"%^BOLD%^%^YELLOW%^The tunnel comes to an "+
    "end here. An opening to the west leads into darkness. A wide "+
    "%^RESET%^%^BLUE%^pool%^BOLD%^%^YELLOW%^ of murky water "+
    "along the eastern edge of the tunnel offers a slight chill to the air "+
    "here.%^RESET%^");
    set_exits( (["west" : FFTR"12" ]) ); 
    TO->add_items(({"water","pool",
    "murky water"}), "%^RESET%^%^BLUE%^This cool murky water "+
    "laps about uneasily. It appears to be quite deep as "+
    "you are unable to see the bottom. You could "+
    "%^BOLD%^%^WHITE%^<%^BOLD%^%^CYAN%^"+
    "dive%^BOLD%^%^WHITE%^>%^RESET%^"+
    "%^BLUE%^ into its murky depths "+
    "if you were so inclined.%^RESET%^");
}

void init()
{
    ::init();
    add_action("dive_em", "dive");
}

int dive_em(string str)
{
    if(!str)
    {
        tell_object(TP, "What do you want to dive into?");
        return 1;
    }
    if(str == "water" || str == "pool" || str == "murky water")
    {
        if(TP->query_bound() || TP->query_unconcious() || TP->query_paralyzed()
        || TP->query_tripped()) 
        {
            TP->send_paralyzed_message("info",TP);
            return 1;
        }
        tell_object(TP, "%^BOLD%^%^BLUE%^You decide to be brave and "+
        "dive head first into the %^RESET%^%^CYAN%^pool of murky water"+
        "%^BOLD%^%^BLUE%^!%^RESET%^");	
        if(!TP->query_invis()) 
        {
            tell_room(TO, TPQCN + " bravely dives head first into the "+
            "%^BOLD%^%^BLUE%^murky water%^RESET%^!", TP);
        }
        TP->move(FFUR"1");
        TP->force_me("look");
        return 1;
    }
    else 
    {
        tell_object(TP, "What do you want to dive into?");
        return 1;
    }
}
