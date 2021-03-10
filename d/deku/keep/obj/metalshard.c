#include <std.h>
inherit "/d/common/obj/weapon/dagger.c";

void create() 
{
    ::create();
    set_name("dagger");
    set_id(({"weapon","dagger","metal shard","blue metal shard","shard"}));
    set_obvious_short("A blue metal shard%^RESET%^");
    set_short("%^BOLD%^%^BLUE%^A blue m%^BOLD%^"+
    "%^BLACK%^e%^BLUE%^t%^BOLD%^%^BLACK%^a%^BLUE%^l "+
    "shard%^RESET%^");
    set_long("%^BOLD%^%^WHITE%^This dagger is nearly one "+
    "foot long and made from a "+
    "%^BOLD%^%^BLACK%^da%^BLUE%^rk%^BOLD%^%^BLACK%^"+
    "en%^BLUE%^ed%^RESET%^ %^BLUE%^"+
    "blue%^BOLD%^%^WHITE%^ metal shard, shaped into the "+
    "form of a small claw.  The "+
    "handle and blade of the weapon %^CYAN%^flow%^WHITE%^ "+
    "together into a solid piece "+
    "of material with a slightly curved, "+
    "%^YELLOW%^shar%^BLUE%^p%^YELLOW%^ened%^BOLD%^"+
    "%^WHITE%^ edge.  One end of the material is "+
    "rounded and has a strip of cloth wrapped "+
    "around it, it serves as a makeshift handle.%^RESET%^");
    set_lore("Enchanted by Lord Blacktongues %^BOLD%^%^BLACK%^half-drow sorceress%^RESET%^ for his "+
    "%^BOLD%^%^WHITE%^drow%^RESET%^ assassin. This metal shard is said to aid one in combat "+
    "by ensuring that the person never misses an attack and is unseen for a stealthy kill.");
    set_property("enchantment",3);
    set_item_bonus("stealth", 2);
	set_item_bonus("attack bonus", 1);
    set_value(2000 + random(201));
    set_wield((:TO,"wield_me":));
    set_unwield("%^BOLD%^%^BLUE%^You quickly release "+
    "the metal shard.%^RESET%^");
    set_hit((:TO,"special":));
}

int wield_me() 
{
    tell_object(ETO, "%^BOLD%^%^BLUE%^You carefully grip "+
    "the metal shard.%^RESET%^");
    return 1;
}

int special(object targ) 
{
    int chance;
    string limb;
    chance = random(1000);
    if(!objectp(ETO)) return 0;
    if(!objectp(EETO)) return 0;
    if(chance > 400 && chance < 650) 
    {
        if(!objectp(targ)) return 0;
        switch(random(2)) 
        {
            case 0:
                tell_object(ETO,"%^BLUE%^You stab " + targ->QCN + 
                "%^BLUE%^ in the neck with your metal shard!%^RESET%^");
       
                tell_room(EETO,ETOQCN + "%^BLUE%^ stabs " +
                targ->QCN + "%^BLUE%^ in the neck with " +
                ETO->QP + "%^BLUE%^ metal shard!%^RESET%^",({targ,ETO}));
        
                tell_object(targ,ETOQCN + "%^BLUE%^ stabs you in "+
                "the neck with "+ETO->QP + "%^BLUE%^ metal shard!%^RESET%^");
                return roll_dice(1,6);			
                break;
            case 1:
                limb = targ->return_target_limb();
                tell_object(ETO,"%^BOLD%^%^GREEN%^You stab " + targ->QCN+
                "%^BOLD%^%^GREEN%^ in the "+limb+" with your %^BLUE%^metal "+
                "shard %^BOLD%^%^GREEN%^and suddenly %^RED%^yank"+
                "%^BOLD%^%^GREEN%^ it from the wound!%^RESET%^");
            
                tell_room(EETO,ETOQCN + "%^BOLD%^%^GREEN%^ stabs " +
                targ->QCN + "%^BOLD%^%^GREEN%^ in the "+limb+" with " + 
                ETO->QP + "%^BLUE%^ metal shard%^BOLD%^%^GREEN%^ and "+
                "suddenly %^RED%^yanks%^BOLD%^%^GREEN%^ it from the "+
                "wound!%^RESET%^",({targ,ETO}));

                tell_object(targ,ETOQCN + "%^BOLD%^%^GREEN%^ stabs you "+
                "in the "+limb+" with " + ETO->QP + "%^BLUE%^ metal "+
                "shard and then suddenly %^RED%^yanks%^BOLD%^%^GREEN%^ "+
                "it from the wound!%^RESET%^");
                
                return roll_dice(2,3);
                break;
        }
    }
    return 0;
}
