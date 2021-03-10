#include <std.h>
#include "../inherits/area_stuff.h"
inherit OBJECT;

object myController, myBound;
int failChance, myCount;

int is_invincible() { return 1; }

void set_controller(object ob)
{
    if(!objectp(ob)) return;
    myController = ob;
}

void create() 
{
    ::create();
    set_name("an indestructable irridescent chain");
    set_value(0);
    set_weight(10000);
	
    set_id(({"chain", "binding chain", "indestructable chain"}));
    set_property("no animate", 1);

    set_short("%^BOLD%^%^RED%^I%^BOLD%^%^BLACK%^nd%^BOLD%^%^RED%^e"+
    "%^BOLD%^%^BLACK%^str%^BOLD%^%^RED%^u%^BOLD%^%^BLACK%^ct%^BOLD%^"+	
    "%^RED%^a%^BOLD%^%^BLACK%^bl%^BOLD%^%^RED%^e binding chain %^BOLD%^%^WHITE%^( "
    "%^BOLD%^%^CYAN%^suspended in midair%^BOLD%^%^WHITE%^ )%^RESET%^");

    set_long("%^BOLD%^%^BLACK%^This chain is made from a "+
    "irridescent black substance. It is surrounded by a field of "+
    "%^BOLD%^%^RED%^crackling energy%^BOLD%^%^BLACK%^ that extends the "+
    "length of it. A powerful magic keeps it suspended in midair. "+
    "You are able to ascertain that no physical or magical "+
    "power could cause it the least bit of damage once it is binding "+
    "someone. The only way to be free of its bounds is to "+
    "%^BOLD%^%^WHITE%^<%^BOLD%^%^CYAN%^break%^BOLD%^%^WHITE%^> "+
    "%^BOLD%^%^BLACK%^them with sheer willpower.%^RESET%^");

    set_property("noMissChance", 1);
    failChance = 0;
    myCount = 4;
    set_heart_beat(1);
}

void init()
{
    ::init();   
    add_action("break_function", "break");
}

void bind(object ob)
{
    if(!objectp(myController)) return;
    if(!objectp(ob)) return;
    myBound = ob;
    myController->add_bound(myBound);
}

void bind_notify()
{
    if(!objectp(TO)) return;
    if(!objectp(myBound)) return;
    if(!objectp(myController)) return;
    tell_object(myBound, TO->query_short()+ "%^BOLD%^%^BLACK%^ wraps tightly "+
    "around your body, holding you in place!%^RESET%^");

    tell_object(myBound, "%^BOLD%^%^RED%^If you hope to have any chance of "+
    "escaping, you must %^BOLD%^%^WHITE%^<%^BOLD%^%^CYAN%^break%^BOLD%^%^WHITE%^"+
    ">%^BOLD%^%^RED%^ your bonds!%^RESET%^");

    tell_room(ETO, TO->query_short()+ "%^BOLD%^%^BLACK%^ wraps tightly "+
    "around "+myBound->QCN+"%^BOLD%^%^BLACK%^'s body, holding "+
    myBound->QO+"%^BOLD%^%^BLACK%^ in place!%^RESET%^", myBound);

    myBound->set_paralyzed(10000, "%^BOLD%^%^BLACK%^You are held "+
    "in place by the "+TO->query_short()+"!%^RESET%^");
    myBound->set_missChance((int)myBound->query_missChance() - 100);

    return;
}

void remove_chain()
{
    if(!objectp(TO)) return;
    if(!objectp(myBound)) 
    {
        tell_room(ETO, TO->query_short()+"%^BOLD%^%^RED%^ E%^BOLD%^%^YELLOW%^"+
        "X%^BOLD%^%^RED%^P%^BOLD%^%^YELLOW%^L%^BOLD%^%^RED%^O%^BOLD%^%^YELLOW%^"+
        "D%^BOLD%^%^RED%^E%^BOLD%^%^YELLOW%^S%^BOLD%^%^RED%^ into a mist of "+
        "tiny fragments!%^RESET%^");
        if(objectp(myController)) myController->remove_bound(myBound);
        TO->remove();
        return;
    }
    tell_object(myBound, TO->query_short()+"%^BOLD%^%^RED%^ releases its "+
    "hold on you before E%^BOLD%^%^YELLOW%^X%^BOLD%^%^RED%^P%^BOLD%^%^YELLOW%^"+
    "L%^BOLD%^%^RED%^O%^BOLD%^%^YELLOW%^"+
    "D%^BOLD%^%^RED%^I%^BOLD%^%^YELLOW%^N%^BOLD%^%^RED%^G into a mist of "+
    "tiny fragments!%^RESET%^");

    tell_room(ETO, TO->query_short()+"%^BOLD%^%^RED%^ releases its "+
    "hold on "+myBound->QCN+" before E%^BOLD%^%^YELLOW%^X%^BOLD%^%^RED%^P%^BOLD%^%^YELLOW%^"+
    "L%^BOLD%^%^RED%^O%^BOLD%^%^YELLOW%^"+
    "D%^BOLD%^%^RED%^I%^BOLD%^%^YELLOW%^N%^BOLD%^%^RED%^G into a mist of "+
    "tiny fragments!%^RESET%^", myBound);
    if(myBound->query_paralyzed()) myBound->set_paralyzed(0);
    if(objectp(myController)) myController->remove_bound(myBound);
    TO->remove();
    return;
}

		

void heart_beat()
{
    if(!objectp(TO)) return;
    if(!objectp(myBound) || !objectp(myController)) 
    {
        remove_chain();
        return;
    }
    if(!interactive(myBound)) 
    {
        tell_room(ETO, myBound->QCN+"%^BOLD%^%^RED%^ is torn in %^BOLD%^%^YELLOW%^HALF "+
        "by "+TO->query_short()+"%^BOLD%^%^RED%^!%^RESET%^");
        myBound->die();
        myBound = 0;
        return;
    }
    if(myBound->query_ghost())
    {
        remove_chain();
        return;
    }
    if(environment(myBound) != ETO)
    {
        remove_chain();
        return;
    }
    if(!myBound->query_paralyzed()) 
    {
        myBound->set_paralyzed(1000, "%^BOLD%^%^BLACK%^You are held "+
        "in place by the "+TO->query_short()+"!%^RESET%^");
    }
    myCount--;
    if(myCount <= 0) 
    {
        tell_object(myBound, "%^BOLD%^%^RED%^You must %^BOLD%^%^WHITE%^<%^BOLD%^%^CYAN%^"+
        "break%^BOLD%^%^WHITE%^>%^BOLD%^%^RED%^ the bonds if you ever have a "+
        "chance of escaping!%^RESET%^");    
        failChance = 0;
        myCount = 4;
    }
}

void query_my_bound() { return myBound; }

int break_function() 
{
    object *inv, ob;
    int x;
    if(!objectp(TO)) return 0;
    if(!objectp(ETO)) return 0;
    if(!objectp(TP)) return 0;
    if(myBound != TP)
    {
        inv = all_inventory(ETO);
        for(x = 0;x < sizeof(inv);x++)
        {
            if(!inv[x]->id("binding chain")) continue;
            if(!objectp(ob = inv[x]->query_my_bound())) continue;
            if(ob != TP) continue;
            ob->break_function();
            return 1;
        }
        tell_object(TP, "%^BOLD%^%^CYAN%^You are not bound and cannot use your "+
        "will to break any binding chains!%^RESET%^");
        return 1;
    }
    //making this easier to escape from - was 35, which is pretty high 
    //for classes that don't have strong will saves. 
    if(roll_dice(1,20) > 10 && !failChance)
    //if(TP->will_save(22) && !failChance)  
    {
        tell_object(TP, "%^BOLD%^%^CYAN%^You use every ounce of willpower that you "+
        "can muster and manage to free yourself from the "+TO->query_short()+"!%^RESET%^");
        TP->remove_paralyzed();
        remove_chain();
        TP->set_missChance((int)myBound->query_missChance() + 100);
        return 1;
    }
    else
    {
        tell_object(TP, "%^BOLD%^%^CYAN%^You use every ounce of willpower that you "+
        "can muster but are unable to free yourself from the "+TO->query_short()+"!%^RESET%^");
        failChance = 1;
        return 1;		
    }
    return 1;
}		

int get() { return 0; }