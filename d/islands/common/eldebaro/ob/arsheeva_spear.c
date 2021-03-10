#include <std.h>
#include "../area_stuff.h"
inherit OBJECT;

object myController, myImpaled;
int myCount;
void remove_spear();
int is_invincible() { return 1; }

void set_controller(object ob)
{
    if(!objectp(ob)) return;
    myController = ob;
}

string get_my_short()
{
    string ret;
    ret = "%^BOLD%^%^CYAN%^tr%^RESET%^%^CYAN%^a%^BOLD%^nsl%^RESET%^%^CYAN%^"+
    "u%^BOLD%^c%^RESET%^%^CYAN%^e%^BOLD%^nt l%^RESET%^%^CYAN%^o%^BOLD%^ng "+
    "sp%^RESET%^%^CYAN%^ea%^BOLD%^r%^RESET%^";
    if(objectp(myImpaled))
    {
        ret += " %^BOLD%^%^CYAN%^( %^BOLD%^%^WHITE%^pinning "+myImpaled->QCN+ 
        "%^BOLD%^%^WHITE%^ to the ground%^BOLD%^%^CYAN%^ )%^RESET%^";
    }
    return ret;
}

string get_my_long()
{
    string ret;
    ret = "%^BOLD%^%^CYAN%^This strange longspear is completely translucent. "+
    "It is composed of a substance that wavers, flickers, and almost completely "+
    "vanishes before your very eyes. It is hard to make out the actual outline of it "+
    "because of the bizarre composition of the substance. However, you are able to "+
    "determine that it is quite long, reaching nearly ten feet in length. You realize "+
    "that there is a %^BOLD%^%^CYAN%^g%^BOLD%^%^MAGENTA%^l%^BOLD%^%^YELLOW%^i"+
    "%^BOLD%^%^RED%^t%^BOLD%^%^CYAN%^t%^BOLD%^%^MAGENTA%^e%^BOLD%^"+
    "%^YELLOW%^r%^BOLD%^%^RED%^i%^BOLD%^%^CYAN%^n%^BOLD%^%^MAGENTA%^g"+
    "%^BOLD%^%^CYAN%^ trail that is only sometimes visible.";
    if(objectp(myController))
    {
        ret += " The trail seems to "+
                "connect the spear to "+myController->query_short()+"%^BOLD%^%^CYAN%^ and you realize that "+
                "somehow it is linked to him...";
        if(objectp(myImpaled))
        {
            ret += " in fact a sudden realization reveals that damage "+
                "caused to "+myController->query_short()+"%^BOLD%^%^CYAN%^ is transferred to "+myImpaled->QCN+
                "%^BOLD%^%^CYAN%^!%^RESET%^";
        }
    }
    ret += "%^RESET%^";
    return ret;
}

void create() 
{
    ::create();
    set_name("a translucent long spear");
    set_value(0);
    set_weight(10000);
	
    set_id(({"spear", "long spear", "translucent long spear"}));
    set_property("no animate", 1);

    set_short((:TO, "get_my_short":));

    set_long((:TO, "get_my_long":));

    set_property("noMissChance", 1);
    myCount = roll_dice(4,10);
    set_heart_beat(1);
}

void impale(object ob)
{
    if(!objectp(myController)) return;
    if(!objectp(ob)) return;
    myImpaled = ob;
    if(!myController->add_impaled(myImpaled))
    {
        remove_spear();
        return;
    }
    return;
}

void impale_notify()
{
    if(!objectp(TO)) return;
    if(!objectp(myImpaled)) return;
    if(!objectp(myController)) return;
    tell_object(myImpaled, capitalize(TO->query_short())+ "%^BOLD%^%^CYAN%^ impales you!! "+
    "Pinning you to the desert ground!!!%^RESET%^");

    tell_room(ETO, capitalize(TO->query_short())+ "%^BOLD%^%^CYAN%^ impales "+
    myImpaled->QCN+", pinning "+myImpaled->QO+" to the desert "+
    "ground!!%^RESET%^", myImpaled);

    myImpaled->set_paralyzed(10000, "%^BOLD%^%^RED%^You are pinned "+
    "to the ground by the "+TO->query_short()+"!%^RESET%^");    
    return;
}

void remove_spear()
{
    if(!objectp(TO)) return;
    if(!objectp(myImpaled)) 
    {
        tell_room(ETO, capitalize(TO->query_short())+"%^BOLD%^%^CYAN%^ vanishes into "+
        "nothingness!!!%^RESET%^");
        if(objectp(myController)) myController->remove_impaled(myImpaled);
        TO->remove();
        return;
    }
    tell_object(myImpaled, capitalize(TO->query_short())+"%^BOLD%^%^CYAN%^ vanishes into "+
    "nothingness - you are FREED from its impossible hold!%^RESET%^");

    tell_room(ETO, capitalize(TO->query_short())+"%^BOLD%^%^CYAN%^ vanishes into "+
    "nothingness - "+myImpaled->QCN+"%^BOLD%^%^CYAN%^ is FREED from its "+
    "impossible hold!", myImpaled);
    
    if(myImpaled->query_paralyzed()) myImpaled->set_paralyzed(0);
    if(objectp(myController)) myController->remove_impaled(myImpaled);
    TO->remove();
    return;
}

void heart_beat()
{
    if(!objectp(TO)) return;
    if(!objectp(myImpaled) || !objectp(myController)) 
    {
        remove_spear();
        return;
    }
    if(myImpaled->query_ghost())
    {
        remove_spear();
        return;
    }
    if(environment(myImpaled) != ETO)
    {
        remove_spear();
        return;
    }
    if(!myImpaled->query_paralyzed()) 
    {
        myImpaled->set_paralyzed(10000, "%^BOLD%^%^RED%^You are pinned "+
        "to the ground by the "+TO->query_short()+"!%^RESET%^");   
    }
    myCount--;
    if(myCount <= 0) 
    {
        remove_spear();
        return;
    }
}

void query_my_impaled() { return myImpaled; }

int get() { return 0; }