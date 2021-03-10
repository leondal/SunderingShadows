#include <std.h>
inherit "/d/common/obj/armour/mshield.c";

#define LANGS ({"elven","common"})
int uses, darkened_time;

void create()
{
    ::create();
    set_name("shield");
    set_id(({ "shield", "gloom shield", "shield of gloom", "crystal shield","black shield","black crystal shield" }));
    set_short("%^BOLD%^%^BLACK%^Shield of %^BOLD%^%^WHITE%^G%^BOLD%^%^BLACK%^l%^BOLD%^"+
    "%^WHITE%^o%^BOLD%^%^BLACK%^o%^BOLD%^%^WHITE%^m%^RESET%^");
    set_obvious_short("A black crystal shield");
    set_long("%^BOLD%^%^BLACK%^This shield is made from a large piece of blackened %^BOLD%^"+
    "%^WHITE%^crystal%^BOLD%^%^BLACK%^.  The formation of the shield is such that the bottom "+
    "is only about half a foot across and it gradually widens to span "+
    "nearly two feet at the top.  "+
    "A mysterious %^BOLD%^%^WHITE%^g%^BOLD%^%^BLACK%^l%^BOLD%^%^WHITE%^o%^BOLD%^%^BLACK%^o"+
    "%^BOLD%^%^WHITE%^m%^RESET%^%^BOLD%^%^BLACK%^ is constantly %^RED%^radiating%^BOLD%^"+
    "%^BLACK%^ forth from it and occasionally a strange humming sound is emitted by it.  There "+
    "is an %^RESET%^%^WHITE%^inscription%^BOLD%^%^BLACK%^ on the back you might be able to read."+
    "%^RESET%^");
    set_lore("%^BOLD%^%^BLACK%^This shield was crafted by Siere Domsdrail in an attempt to reproduce the elves "+
    "incantation on the shield of light. The idea was to present this shield to Lord Blacktongues "+
    "minions with a shield that would protect them against powerful positive magic. "+
    "The shield was supposedly stolen by a chosen of %^BOLD%^%^GREEN%^Silvanus%^BOLD%^%^BLACK%^.%^RESET%^");
    set_language(LANGS[random(sizeof(LANGS))]);
    set_read("%^BOLD%^%^BLACK%^Darkness%^RESET%^ it will be, if only you command me.");
    set_value(1000);
    set_property("enchantment",3);
    set_item_bonus("positive energy resistance", 10);
    set_wear((:TO,"wear_func":));
    set_remove((:TO,"remove_func":));
    set_struck((:TO,"strike_func":));
    uses = 5 + random(16);
    set_ac(0);;
}

void init() 
{
    ::init();
    if(interactive(ETO)) 
    {
        TO->add_item_owner(ETOQN);
    }
    add_action("make_dark","darkness");
}

int make_dark()
{   
    if (TP->query_bound() || TP->query_unconscious()) 
    {
        TP->send_paralyzed_message("info",TP);
        return 1;
    }
    if(!query_worn()) 
    {
        write("You must wear the shield first.");
        return 1;
    }
    if(uses > 0)
    {
        if(time() - darkened_time > 100)
        {
            tell_room(ETO,"%^BOLD%^%^BLACK%^A dark %^RED%^au%^BLUE%^r%^RED%^a%^BOLD%^%^BLACK%^"+
            " envelopes the room.%^RESET%^");
            new("/cmds/spells/d/_darkness.c")->use_spell(TP,TP,10,8,"mage");
            darkened_time = time();
            uses--;
            return 1;
        }
        write("The shield fails to respond.");
        return 1;
    }
    write("The shield is out of charges.");
    return 1;
}

int wear_func()
{
    int x;
    if(!TO->query_owns_item(ETOQN) && interactive(ETO)) 
    {
        tell_object(ETO,"The shield refuses you!");
        return 0;
    }
    
    x = TO->query_property("enchantment");
    
    if(ALIGN->is_good(ETO) && x > 0) 
    {
        TO->remove_property("enchantment");
    }

    if(ALIGN->is_neutral(ETO) && x >= 0) 
    {
        while((int)TO->query_property("enchantment") != 1) 
        {
            TO->remove_property("enchantment");
            TO->set_property("enchantment",1);
        }
    }             
    if(ALIGN->is_evil(ETO) && x >= 0) 
    {
        while((int)TO->query_property("enchantment") != 2) 
        {
            TO->remove_property("enchantment");
            TO->set_property("enchantment",2);
        }
    }

    tell_room(environment(ETO),"%^BLUE%^A strange humming comes forth from "+
    ETO->query_cap_name()+"%^BOLD%^%^BLUE%^"+
    "'s shield%^BLUE%^!%^RESET%^",ETO);
    tell_object(ETO,"%^BLUE%^A strange humming is emitted by your shield%^BLUE%^!%^RESET%^ ");
    return 1;
}

int remove_func()
{
    tell_room(environment(ETO),"%^BLUE%^"+ETO->query_cap_name()+"%^BLUE%^'s shield stops its "+
    "strange humming!%^RESET%^",ETO);
    tell_object(ETO,"%^BLUE%^Your shield stops its strange humming!%^RESET%^");
    return 1;
}

int strike_func(int damage, object what, object who)
{
    if(random(1000) < 250)
    {
        tell_room(environment(query_worn()),"%^BLUE%^"+ETO->query_cap_name()+
        "%^BLUE%^'s shield hums "+
        "loudly as "+who->query_cap_name()+" strikes it!%^RESET%^",({ETO,who}));
	
        tell_object(ETO,"%^BLUE%^Your shield hums loudly as "+
        who->query_cap_name()+" strikes it!%^RESET%^");
        tell_object(who,"%^BLUE%^"+ETO->query_cap_name()+
        "%^BLUE%^'s shield hums loudly as you strike "+
        "it!%^RESET%^");
        who->do_damage(who->return_target_limb(),roll_dice(1,6));
        return damage;
    }
}
