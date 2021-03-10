#include <std.h>
#include "../area_stuff.h"
#define VALID_TYPES ({"heaven", "power", "insight"})
inherit OBJECT;
string MannaType;

void create() 
{
    string tmp;
    ::create();
    
     
    set_name("thick baked bread");
    MannaType = VALID_TYPES[random(sizeof(VALID_TYPES))];
    set_id( ({ "bread", "manna", "unleavened bread", "thick bread", 
    "thick baked break", "manna of "+MannaType}) );
    set_obvious_short("%^RESET%^%^ORANGE%^Thick baked bread%^RESET%^");

    set_short("%^RESET%^%^ORANGE%^Manna of "+MannaType+"%^RESET%^");    
    
    set_long("%^RESET%^%^ORANGE%^This is a thick slice of unleavened bread. "+
    "It looks as if it were prepared for far too long. "+
    "It appears dry and almost as if it would have no taste at first glance. "+
    "However, there is something strange about it, an aura of almost tangible "+
    "power radiates out from it. You are unsure what ingredients were used in "+
    "its creation, but whatever was involved was obviously quite powerful. You get "+
    "the sense that it would not be very filling in the tradional way, but that "+
    "consuming or eating it may have some as of yet unknown effect.%^RESET%^");
    set_weight(1);
    tmp = "%^RESET%^%^ORANGE%^This bread is known as manna of "+
    MannaType+". The process for preparing it has been lost to time, or at least "+
    "was thought lost, until now. Originally it was prepared for a "+
    "nomadic cult of Lysaraian priests, to take with them on their "+
    "journies. This particular type of manna is said to ";
    switch(MannaType)
    {
        case "heaven":
            tmp += "grant wisdom and will power ";
            break;
        case "power":
            tmp += "grant strength and health ";
            break;
        case "insight":
            tmp += "grant intelligence and an expanded mind ";
            break;
    }
    tmp += "to whoever consumes or eats it.%^RESET%^";
    set_lore(tmp);
    set_property("lore difficulty", 25);

}

void init()
{
    ::init();
    if(living(ETO)) 
    {
        add_action("eat", "eat");
        add_action("eat", "consume");
    }
}

int eat(string str)
{
    string me;
    object EffectOb, targOb, who;
    if(!objectp(TO)) return 0;
    if(!objectp(ETO)) return 0;
    if(!stringp(str)) return 0;
    if(!objectp(targOb = present(str, ETO))) return 0;
    if(!objectp(environment(targOb))) return 0;
    who = environment(targOb);
    if(!living(who)) return 0;
    if(who != ETO) return 0;
    
    me = targOb->query_short();
    MANNA_D->register_effect(who, MannaType);
    
    tell_object(who, "%^RESET%^%^ORANGE%^You manage to choke down the "+me+".%^RESET%^");
    tell_room(environment(who), who->QCN+"%^RESET%^%^MAGENTA%^ manages to choke down the "+me+".%^RESET%^", who);
    targOb->remove();
    return 1;   
}

int isMagic() { return 5;}
