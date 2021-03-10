#include <std.h>
inherit "/d/common/obj/weapon/sickle.c";
int true_reaping;

void create() 
{
    ::create();
    set_name("serrated sickle");
    set_id(({"sickle", "serrated sickle", "wooden sickle", 
    "the reaping", "reaping"}));
	
    set_obvious_short("%^BOLD%^%^GREEN%^%^"+
    "A serrated sickle%^RESET%^");
		
    set_short("%^RESET%^%^ORANGE%^R%^BOLD%^%^GREEN%^ea%^RESET%^%^ORANGE%^p%^BOLD%^%^GREEN%^"+
    "i%^RESET%^%^ORANGE%^ng%^RESET%^");
	
    set_long("%^RESET%^%^ORANGE%^This sickle has a very small and bumpy wooden handle. "+
    "There are grooves set between some of the bumps which obviously are intended to "+
    "serve as a way to grip the weapon. Extending out from the handle and forming a semi-circle "+
    "is a %^BOLD%^%^BLACK%^very dark%^RESET%^%^ORANGE%^ blade. The substance that forms the "+
    "blade appears metallic and seems very solid. Both edges of the blade are wickedly "+
    "%^BOLD%^%^GREEN%^serrated%^RESET%^%^ORANGE%^ and sharp enough to cut flesh easily. "+
    "There are tiny, almost indistinguishable %^BOLD%^%^BLACK%^silhouettes%^RESET%^%^ORANGE%^ "+
    "of faces traveling the length of the blade. Each of them appears frozen in a wide "+
    "mouthed %^BOLD%^%^RED%^scream%^RESET%^%^ORANGE%^.%^RESET%^");

    set_value(3000);
    set_property("lore difficulty", 28);

    set_lore("%^RESET%^%^ORANGE%^Known simply as the reaping, these sickles "+
    "are centuries old. The original creator has been lost to the ages, but they were "+
    "rumored to be the weapon of choice for some obscure cult centuries past. The cult was "+
    "supposedly behind the sinking of the Eldebaro island and the imprisonment of Asantra and Kayan "+
    "Freeholm. Some say that they never left the island. Which could explain why these sickles have "+
    "started turning up there. However, others suggest that they did indeed leave for a long time "+
    "but something brought them back recently. Each sickle was rumored to be able actually reap "+
    "souls for Lysara, but who knows if that is true or not. Most of them are also rumored to "+
    "provided increased accuracy in combat.%^RESET%^");

    set_property("enchantment",5);

    set_wield((:TO,"wield_me":));
    set_unwield((:TO,"unwield_me":));
    set_hit((:TO,"special":));
    set_item_bonus("attack bonus", 3);
    true_reaping = random(100);
}

int wield_me()
{
    if((int)ETO->query_highest_level() < 35 && true_reaping == 777)
    {
        tell_object(ETO, "%^RESET%^%^ORANGE%^The sickle will never be controlled by one as "+
        "weak as you are!%^RESET%^");
        return 0;
    }
    tell_object(ETO, "%^RESET%^%^ORANGE%^You feel a sense of empowerment settle over you, lending itself "+
    "to your accuracy, as you wield the sickle!%^RESET%^");
    return 1;
}

int unwield_me()
{
    tell_object(ETO, "%^RESET%^%^ORANGE%^You feel the sense of empowerment fade away!%^RESET%^");
    return 1;
}

int special(object targ) 
{
    string tlim;
    int dam, amt;
    if(!objectp(ETO)) return 0;
    if(!objectp(EETO)) return 0;
    if(!objectp(targ)) return 0;
    if(random(100) < 60) return 0;
    if(true_reaping == 77) amt = random(10);
    else amt = random(9);
    switch(amt)
    {
        case 0..7:
            tlim = targ->return_target_limb();

            tell_object(ETO, "%^BOLD%^%^GREEN%^The serrated blade of your sickle "+
            "slashes deep into "+targ->QCN+"%^BOLD%^%^GREEN%^'s "+tlim+
            " and you RIP it from the wound!%^RESET%^");
            
            tell_object(targ, "%^BOLD%^%^GREEN%^The serrated blade of "+ETO->QCN+"%^BOLD%^%^GREEN%^'s sickle "+
            "slashes deep into "+tlim+" and "+ETO->QS+" RIPS it from the wound!%^RESET%^");
            
            tell_room(EETO,  "%^BOLD%^%^GREEN%^The serrated blade of "+ETO->QCN+"%^BOLD%^%^GREEN%^'s sickle "+
            "slashes deep into "+targ->QCN+"%^BOLD%^%^GREEN%^'s "+tlim+
            " and "+ETO->QS+" RIPS it from the wound!%^RESET%^", ({targ, ETO}));
            
            targ->cause_typed_damage(targ,tlim,roll_dice(3,6),"slashing");
            return 0;
            break;
        case 8:
            tell_object(ETO, "%^RESET%^%^ORANGE%^You slice the serrated blade of your sickle into "+targ->QCN+"%^RESET%^%^ORANGE%^ and "+
            "quickly pull back for another attack!%^RESET%^");
            
            tell_object(targ, ETOQCN+"%^RESET%^%^ORANGE%^ slices the serrated blade of "+ETO->QP+" sickle into you and "+
            "quickly pulls back for another attack!%^RESET%^");

            tell_room(EETO, ETOQCN+"%^RESET%^%^ORANGE%^ slices the serrated blade of "+ETO->QP+" sickle into "+
            targ->QCN+"%^RESET%^%^ORANGE%^ and quickly pulls back for another attack!%^RESET%^", ({targ, ETO}));
            
            ETO->execute_attack();
            return roll_dice(2, 4);
            break;
            
        case 9:
            
            tell_object(ETO, "%^BOLD%^%^BLACK%^The %^BOLD%^%^WHITE%^s%^BOLD%^%^GREEN%^i%^BOLD%^%^WHITE%^lh%^BOLD%^%^GREEN%^oue"+
            "%^BOLD%^%^WHITE%^tt%^BOLD%^%^GREEN%^e%^BOLD%^%^WHITE%^s %^BOLD%^%^BLACK%^along the blade of your sickle "+
            "flash erratically as it sinks into "+targ->QCN+"%^BOLD%^%^BLACK%^!!%^RESET%^");
            
            tell_object(targ, "%^BOLD%^%^BLACK%^The %^BOLD%^%^WHITE%^s%^BOLD%^%^GREEN%^i%^BOLD%^%^WHITE%^lh%^BOLD%^%^GREEN%^oue"+
            "%^BOLD%^%^WHITE%^tt%^BOLD%^%^GREEN%^e%^BOLD%^%^WHITE%^s %^BOLD%^%^BLACK%^along the blade of "+ETO->QCN+"%^BOLD%^%^BLACK%^'s sickle "+
            "flash erratically as it sinks into you!!%^RESET%^");
            
            tell_room(EETO, "%^BOLD%^%^BLACK%^The %^BOLD%^%^WHITE%^s%^BOLD%^%^GREEN%^i%^BOLD%^%^WHITE%^lh%^BOLD%^%^GREEN%^oue"+
            "%^BOLD%^%^WHITE%^tt%^BOLD%^%^GREEN%^e%^BOLD%^%^WHITE%^s %^BOLD%^%^BLACK%^along the blade of "+ETO->QCN+"%^BOLD%^%^BLACK%^'s sickle "+
            "flash erratically as it sinks into "+targ->QCN+"%^BOLD%^%^BLACK%^!!%^RESET%^");
            
            tell_object(targ, "%^BOLD%^%^GREEN%^You feel something tugging at your %^BOLD%^%^RED%^SOUL%^BOLD%^%^GREEN%^!%^RESET%^");
            
            if(targ->fort_save(20 + random(21)) || targ->query_property("no death"))
            {
                tell_object(targ, "%^BOLD%^%^GREEN%^You manage to resist the reaping!%^RESET%^");
            }
            else
            {
                if(userp(targ) && random(777)) tell_object(targ, "%^BOLD%^%^GREEN%^You manage to resist the reaping!%^RESET%^");
                else
                {
                    tell_room(EETO, "%^BOLD%^%^RED%^A voice entones: %^RESET%^I AM %^RESET%^%^ORANGE%^R%^BOLD%^%^GREEN%^EA%^RESET%^%^ORANGE%^P"+
                    "%^BOLD%^%^GREEN%^I%^RESET%^%^ORANGE%^NG%^RESET%^ "+targ->QCN+"!");
                    tell_object(targ, "%^BOLD%^%^RED%^You feel your soul %^BOLD%^%^BLACK%^TORN%^BOLD%^%^RED%^ from your body!%^RESET%^");
                    targ->cause_typed_damage(targ, "head", 10000000, "untyped");
                    return 0;
                }
            }
            return roll_dice(3,4);
            break;
    }
            
            
            
}
