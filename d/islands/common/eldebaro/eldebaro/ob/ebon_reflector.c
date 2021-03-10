#include <std.h>
#include <daemons.h>

inherit "/d/common/obj/armour/shield.c"; 
int FeatFlag;

void create() 
{
    ::create();
    set_name("ebon shield");
    set_id(({ "shield", "ebon shield", "the reflector", "ebon reflector", "reflector", 
    "dull shield", "dull ebon shield"}));
    
    set_obvious_short("dull ebon shield");

    set_short("%^BOLD%^%^BLACK%^R%^BOLD%^%^WHITE%^e%^BOLD%^%^BLACK%^fl%^BOLD%^%^WHITE%^e"+
    "%^BOLD%^%^BLACK%^ct%^BOLD%^%^WHITE%^o%^BOLD%^%^BLACK%^r%^RESET%^");

    set_long("%^BOLD%^%^BLACK%^This rather small and round shield is made from an "+
    "ebon material. It is lightweight and actually seems a lot "+
    "thinner than a normal shield. However, after careful examination you "+
    "believe that whatever material it is made from is stout and capable of "+
    "absorbing an inordinate amount of force. The front of it is almost "+
    "perfectly smooth and quite dull, almost unremarkable in fact, save for "+
    "a series of %^BOLD%^%^RED%^emblems%^BOLD%^%^BLACK%^ that have been %^BOLD%^%^WHITE%^"+
    "em%^BOLD%^%^RED%^blazon%^BOLD%^%^WHITE%^ed%^BOLD%^%^BLACK%^ in "+
    "several different spots. The first %^BOLD%^%^RED%^emblem%^BOLD%^%^BLACK%^ "+
    "depicts an %^RESET%^%^RED%^ancient red dragon%^BOLD%^%^BLACK%^ breathing "+
    "fire on a hunkered human. The second %^BOLD%^%^RED%^emblem%^BOLD%^%^BLACK%^ "+
    "depicts the fire reflecting back at the dragon, who seems to ignore it. The "+
    "third %^BOLD%^%^RED%^emblem%^BOLD%^%^BLACK%^ depicts the human stabbing a sword "+
    "into the chest of the %^RESET%^%^RED%^ancient red dragon%^BOLD%^%^BLACK%^ who "+
    "collapses into a heap. The back of the shield is equally dull and even more "+
    "unremarkable, save for a couple leather straps that allow someone to strap "+
    "or wrap them around their arm to secure it.%^RESET%^");
        
    set_lore("%^BOLD%^%^WHITE%^These shields were known as 'reflectors' for their "+
    "ability to sometimes reflect magic back at whoever attacked their wearer, as well "+
    "as their ability to somehow even reflect damage back at the attacker. Some stories even "+
    "suggest that they imbue the wearer with unnatural health. The creator of them "+
    "is entirely unknown. However, one thing is for certain, that being that the giants who "+
    "bowed down to Kayan Freeholm were said to wear them in combat always. Centuries ago they "+
    "were frequently used to inspire fear and awe in those who would dare stand against the "+
    "giants. In recent times, after the majority of Eldebaro was raised from the ocean, they "+
    "have started showing back up.%^RESET%^");
    
    set_property("lore difficulty", 25);
    
    set_size(-1);
    set_weight(8);
    set_value(10000);
    set_property("no curse", 1);
    set_property("enchantment", 5);
    set_item_bonus("constitution", 4);
    set_wear((:TO,"wearme":));
    set_remove((:TO,"removeme":));
    set_struck((:TO, "strike_func":));
}

int wearme()
{
    if((int)ETO->query_highest_level() < 35)
    {
        tell_object(ETO, "%^BOLD%^%^BLACK%^The shield rejects one as weak as you!%^RESET%^");
        return 0;
    }
    tell_object(ETO, "%^BOLD%^%^WHITE%^You feel healthier as you wear the shield!%^RESET%^");
    if(!pointerp(ETO->query_temporary_feats())) return 1;
    if(member_array("reflection",(string*)ETO->query_temporary_feats()) == -1) 
    {
        ETO->add_temporary_feat("reflection");
        FeatFlag = 1;
    }
	return 1;
}
	
int removeme()
{
    tell_object(ETO, "%^BOLD%^%^WHITE%^You feel the health provided by the shield fade "+
    "away as you release the shield!%^RESET%^");
    
    if(FeatFlag) 
    {
        ETO->remove_temporary_feat("reflection");
        FeatFlag = 0;
    }    
	return 1;
}

int strike_func(int damage, object what, object who)
{
    if(!objectp(who)) return damage;
    if(!objectp(ETO)) return damage;
   
    if(!random(2)) return damage;
    
    tell_object(ETO, "%^BOLD%^%^BLACK%^As "+who->QCN+"%^BOLD%^%^BLACK%^ strikes your shield, "+
    "the force of the blow is reflected back at "+who->QO+"!%^RESET%^");
    
    tell_object(who, "%^BOLD%^%^BLACK%^As you strike "+ETOQCN+"%^BOLD%^%^BLACK%^'s shield, the "+
    "force of the blow is reflected back at you!%^RESET%^");
    
    tell_room(EETO, "%^BOLD%^%^BLACK%^As "+who->QCN+"%^BOLD%^%^BLACK%^ strikes "+ETO->QCN+
    "%^BOLD%^%^BLACK%^'s shield, the force of the blow is reflected back at "+who->QO+"!%^RESET%^", ({ETO, who}));
    
    who->cause_typed_damage(who, who->return_target_limb(), damage, "force");
    return 0;
}
