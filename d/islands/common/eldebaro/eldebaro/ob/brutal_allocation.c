#include <std.h>
#include "../area_stuff.h"
#define QN query_name()
inherit "/d/common/obj/weapon/large_battle_axe";

void create() 
{
    ::create();
    set_name("rough bladed silver axe");

    set_id(({"axe", "silver axe", "rough bladed silver axe", 
    "brutal allocation", "brutal axe"}));
	
    set_obvious_short("%^BOLD%^%^RED%^Rough bl%^BOLD%^%^WHITE%^"+
    "a%^RED%^ded %^BOLD%^%^WHITE%^s%^RESET%^%^WHITE%^i%^BOLD%^lver "+
    "%^RED%^axe%^RESET%^");
			
    set_short("%^BOLD%^%^RED%^Br%^WHITE%^u%^RED%^t%^WHITE%^a"+
    "%^RED%^l All%^WHITE%^o%^RED%^c%^WHITE%^a%^RED%^tion%^RESET%^");

    set_long("%^BOLD%^%^WHITE%^The handle of this massive axe has been forged from "+
    "a large piece of a s%^RESET%^%^WHITE%^i%^BOLD%^lvery substance. It extends "+
    "more than four feet in length. The base of it is much thicker and has "+
    "sk%^RESET%^%^WHITE%^u%^BOLD%^lls etched into it, each of them with "+
    "their mouth agape, making them appear as if they are trapped in an eternal "+
    "%^BOLD%^%^RED%^scream%^BOLD%^%^WHITE%^. Closer to the head of the axe the "+
    "handle is much narrower and has been reinforced on all sides by a %^BOLD%^"+
    "%^BLACK%^darker%^BOLD%^%^WHITE%^ metal which seems very solid. The head of the "+
    "axe is double bladed and rough, almost what you would consider "+
    "%^BOLD%^%^BLUE%^serrated%^BOLD%^%^WHITE%^ but it appears to be the "+
    "result of frequent violent use rather than intentional design.%^RESET%^");

    set_value(8000);
    
    set_property("lore difficulty", 40);

    set_lore("%^BOLD%^%^WHITE%^The legends surrounding these axes are quite "+
    "rare. They were rumored to have been wielded by ancient beasts that were known "+
    "as 'dreadhorns', which were supposedly a breed of minotaurs that were once used "+
    "as guardians in the hallways of castle Freeholm. Castle Freeholm itself was thought "+
    "nothing more than a myth until recent events on the island of Eldebaro have made "+
    "it impossible to disregard as real. The legends around these axes say that they "+
    "were forged by some ancient Storm Giant blacksmith using a portion of the souls of "+
    "those storm giants who had rebelled against the castle to power them. They were each "+
    "known as brutal allocation, a term meant to imply the forcibly splitting of whoever "+
    "happened to be unlucky enough to illicit the wrath of a dreadhorn.%^RESET%^");

    set_property("enchantment",5);
    
    set_item_bonus("strength", 6);
    set_item_bonus("constitution", 2);
    
    set_wield((:TO,"wield_me":));
    set_unwield((:TO,"unwield_me":));
    set_hit((:TO,"special":));
}

int wield_me()
{
    if(ETO->query_highest_level() < 35) 
    {
        tell_object(ETO, "%^BOLD%^%^RED%^The axe refuses to submit to one as "+
        "puny as you!%^RESET%^");
        return 0;
    }
    tell_object(ETO, "%^BOLD%^%^WHITE%^You feel power radiate out "+
    "to you from the screaming skulls on the handle of the axe!%^RESET%^");    
    return 1;
}

int unwield_me()
{
    tell_object(ETO, "%^BOLD%^%^WHITE%^You physically feel the power flow "+
    "back into the screaming skulls and it leaves you feeling "+
    "disconcerted!%^RESET%^");
    return 1;
}

int special(object targ) 
{
    string tlim;
    int dam;
    object wound;
    if(!objectp(TO)) return 0;
    if(!objectp(ETO)) return 0;
    if(!objectp(EETO)) return 0;
    if(!objectp(targ)) return 0;
    if(random(1000) < 350) 
    {
        switch(random(101))
        {
            case 0..99:
                dam = roll_dice(2,4);
                tlim = targ->return_target_limb();
                if(tlim == "head") dam *= 3;
                else if(tlim == "torso") dam *= 2;
                else if(tlim == "neck") dam *= 3;
                
                tell_object(ETO, "%^BOLD%^%^BLACK%^Your axe splits open "+
                targ->QCN+"%^BOLD%^%^BLACK%^'s "+tlim+"!");
                
                tell_object(targ, ETOQCN+"%^BOLD%^%^BLACK%^'s "+TO->QN+" splits "+
                "open your "+tlim+"!%^RESET%^");
	
                tell_room(EETO, ETOQCN+"%^BOLD%^%^BLACK%^'s "+TO->QN+" splits "+
                "open "+targ->QCN+"%^BOLD%^%^BLACK%^'s "+tlim+"!%^RESET%^", ({ETO, targ}));
                wound = new(ELOB+"grievous_wound");
                wound->set_for(tlim, dam);
                wound->move(targ);
                targ->cause_typed_damage(targ, tlim, dam, "slashing");
                return 0;

            case 100:                
                if(userp(targ) || targ->query_property("no death") || random(666))
                {
                    dam = roll_dice(2, 4);
                    tlim = targ->return_target_limb();
                    if(tlim == "head") dam *= 3;
                    else if(tlim == "torso") dam *= 2;
                    else if(tlim == "neck") dam *= 3;
                
                    tell_object(ETO, "%^BOLD%^%^BLACK%^Your axe splits open "+
                    targ->QCN+"%^BOLD%^%^BLACK%^'s "+tlim+"!");
                
                    tell_object(targ, ETOQCN+"%^BOLD%^%^BLACK%^'s "+TO->QN+" splits "+
                    "open your "+tlim+"!%^RESET%^");
	
                    tell_room(EETO, ETOQCN+"%^BOLD%^%^BLACK%^'s "+TO->QN+" splits "+
                    "open "+targ->QCN+"%^BOLD%^%^BLACK%^'s "+tlim+"!%^RESET%^", ({ETO, targ}));
                    wound = new(ELOB+"grievous_wound");
                    wound->set_for(tlim, dam);
                    wound->move(targ);
                    targ->cause_typed_damage(targ, tlim, dam, "slashing");
                    return 0;
                }
                tell_object(ETO, "%^BOLD%^%^BLACK%^With a sudden ROAR you "+
                "slice through "+targ->QCN+"%^BOLD%^%^BLACK%^'s body, splitting "+
                targ->QO+" in %^BOLD%^%^GREEN%^TWAIN%^BOLD%^%^BLACK%^!%^RESET%^");
                
                tell_object(targ, ETOQCN+"%^BOLD%^%^BLACK%^ suddenly ROARS "+
                "and before you realize what is happening.... it is too "+
                "late... your body is split in %^BOLD%^%^GREEN%^TWAIN%^BOLD%^%^BLACK%^"+
                "!%^RESET%^");
                                
                tell_room(EETO, ETOQCN+"%^BOLD%^%^BLACK%^ suddenly ROARS "+
                "and slices "+ETO->QP+" "+TO->QN+" through "+targ->QCN+
                "%^BOLD%^%^BLACK%^'s body, splitting "+targ->QO+ 
                " in %^BOLD%^%^GREEN%^TWAIN%^BOLD%^%^BLACK%^!%^RESET%^", ({targ, ETO}));                
                targ->die();
                return 0;
        }
    }
    return 0;
}
