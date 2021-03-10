#include <std.h>
#include "../inherits/area_stuff.h"
inherit OBJECT;
int count_down, hatchlings, is_broken;

void create() 
{
    ::create();
    set_name("eggsac");
    set_value(1);
    set_weight(1);
	
    set_id(({"egg", "eggs", "sac", "eggsac"}));
    	
    set_short("%^BOLD%^%^WHITE%^Giant eggsac%^RESET%^");

    set_long("%^RESET%^This giant silky eggsac has been "+
    "partially concealed in thick spider's web. "+
    "It is pulsating consistently as if it has a "+
    "heartbeat of its own. At first glance it appears "+	
    "quite thick but you could try to %^RED%^"+
    "smash%^RESET%^ it if you wanted to see "+
    "what was inside.%^RESET%^");

	//some of them will randomly hatch on their 
	//own, others will not
    if(!random(3)) set_heart_beat(1);
    count_down = 25 + random(100);
    hatchlings = 1 + random(3);
    is_broken = 0;
}

void init()
{
    ::init();   
    add_action("smash_function","smash");
}

void adjust_count_down(int x) 
{
    count_down = x;
}

void hatchlings_come_forth()
{
    object spiderling;
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    if(hatchlings != 0)
    {
        hatchlings--;
        tell_room(ETO, "%^BOLD%^%^RED%^A large spiderling "+
        "climbs out of the giant eggsac!%^RESET%^");
        spiderling = new(FFMON+"spiderling");
        if(objectp(spiderling)) spiderling->move(ETO);
        if(hatchlings == 0)
        {
            tell_room(ETO, "%^BOLD%^%^GREEN%^Sickly "+
            "green goo continues to pour out of "+
            "the broken eggsac until it collapses "+
            "in on itself!%^RESET%^");
            TO->remove();
        }
    }
    call_out("hatchlings_come_forth", 18);
    return;
}

void hatch_me()
{
    object spiderling;
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    is_broken = 1;

    TO->set_long("%^RESET%^This giant silky eggsac has been "+
    "partially concealed in thick spider's web. "+
    "The upper portion of it has been broken "+
    "open and %^BOLD%^%^GREEN%^sickly green "+
    "goo%^RESET%^ is visibly inside.%^RESET%^");

    if(!random(2)) 
    {
        tell_room(ETO, "%^BOLD%^%^GREEN%^Sickly "+
        "green goo continues to pour out of "+
        "the broken eggsac until it collapses "+
        "in on itself!%^RESET%^");
        TO->remove();
        return;
    }
    hatchlings_come_forth();
    return;
}

int smash_function(string what) 
{
    if(!objectp(TO)) return 0;
    if(!objectp(ETO)) return 0;
    if(!objectp(TP)) return 0;
    if(!stringp(what)) return 0;
    if(TO != present(what, ETO)) return 0;
    if(is_broken) return 0;
    tell_object(TP, "%^BOLD%^%^RED%^You quickly smash the "+
    what+" and sickly %^BOLD%^%^GREEN%^green goo "+
    "%^BOLD%^%^RED%^starts pouring out of it!%^RESET%^");

    tell_room(ETO, TPQCN+"%^BOLD%^%^RED%^ quickly smashes "+
    what+" and sickly %^BOLD%^%^GREEN%^green goo "+
    "%^BOLD%^%^RED%^starts pouring out of it!%^RESET%^", TP);
    hatch_me();
    return 1;
}		

void heart_beat()
{	
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    count_down--;
    if(count_down > 0 || is_broken) return;
    tell_room(ETO, "%^BOLD%^%^WHITE%^The giant eggsac "+
    "suddenly bursts open and sickly green "+
    "%^BOLD%^%^YELLOW%^goo %^BOLD%^%^WHITE%^"+
    "begins pouring out of it!%^RESET%^");
    hatch_me();
    set_heart_beat(0);
    return;
}

int get() { return 0; }