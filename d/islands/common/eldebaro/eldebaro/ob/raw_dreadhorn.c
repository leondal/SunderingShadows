#include <std.h>
#include "../area_stuff.h"
inherit OBJECT;

void create()
{
    ::create();
    set_name("serrated ivory horn");
    set_id(({ "horn", "ivory horn", "serrated ivory horn",
    "dreadhorn_xxx_horn", "piece of a horn"}));
    
    set_short("%^BOLD%^%^WHITE%^A serrated ivory horn%^RESET%^");    
    
    set_long("%^BOLD%^%^WHITE%^This is the upper portion of what could be "+
    "considered a monsterous ivory horn. Strangely both sides of it are "+
    "serrated and the tip of it forms a %^BOLD%^%^RED%^razor-sharp%^BOLD%^"+
    "%^WHITE%^ point. The bottom of it is quite jagged, as if it was "+
    "broken off the rest of the horn violently. You realize that "+
    "if you had something that would work for a guard and "+
    "something to wrap around the base of it, you could easily "+
    "%^RESET%^assemble%^BOLD%^%^WHITE%^ a dagger.%^RESET%^");
    
    set_weight(2);
    set_value(1000);
}

void init()
{
    ::init();
    add_action("assemble", "assemble");
    return;
}

int assemble(string str)
{
    object guard, wrap, dag;
    if(!objectp(TO)) return 0;
    if(!objectp(ETO)) return 0;
    if(!living(ETO)) return 0;
    if(!stringp(str)) return 0;
    str = lower_case(str);
    if(str != "dagger") return 0;
    if(!objectp(guard = present("dreadhorn_xxx_guard", ETO)))
    {
        tell_object(ETO, "You realize that you are missing something "+
        "that could serve as the guard for the dagger.");
        return 1;
    }
    if(!objectp(wrap = present("dreadhorn_xxx_wrap", ETO)))
    {
        tell_object(ETO, "You realize that you are missing something "+
        "that could serve as a wrap to allow you to wield the dagger "+
        "safely.");
        return 1;        
    }
    tell_object(ETO, "%^BOLD%^%^WHITE%^You quickly attach the "+
    guard->query_short()+"%^BOLD%^%^WHITE%^ to serve as a makeshift guard and then "+
    "wrap the "+wrap->query_short()+"%^BOLD%^%^WHITE%^ around the base of the horn, to "+
    "allow you to wield it safely!%^RESET%^");
    
    if(objectp(EETO) && !ETO->query_invis())
    {
        tell_room(EETO, ETOQCN+"%^BOLD%^%^WHITE%^ quickly attaches "+
        guard->query_short()+" to "+ETO->QP+" serrated ivory horn, to "+
        "serve as a makeshift guard and then wraps "+wrap->query_short()+
        " around the base of the horn to allow "+ETO->QO+" to wield it "+
        "safely!%^RESET%^");
    }
    if(objectp(guard)) guard->remove();
    if(objectp(wrap)) wrap->remove();
    dag = new(ELOB+"dreadhorn");
    dag->set("PoisonDoses", 15);
    dag->set("PoisonType", "deathblade");
    dag->move(ETO);
    if(objectp(TO)) TO->remove();
    return 1;    
}