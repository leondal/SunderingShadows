#include <std.h>
#include <daemons.h>

inherit "/d/common/obj/weapon/dagger";
int isSet, charges;

void create()
{
    ::create();
    set_name("pointed ivory dagger");
    set_id(({"pointed dagger", "ivory dagger", "dagger", "dread horn",
    "serrated ivory dagger" "serrated dagger", "horn", "ivory horn"}));

    set_obvious_short("%^BOLD%^%^WHITE%^Serrated ivory dagger%^RESET%^");

    set_short("%^BOLD%^%^WHITE%^Dr%^BOLD%^%^RED%^ea%^BOLD%^%^WHITE%^"+
    "d H%^BOLD%^%^BLACK%^o%^BOLD%^%^WHITE%^rn%^RESET%^");
	
    set_long("%^BOLD%^%^WHITE%^This thick serrated dagger is the remnants "+
    "of what could be described as a monsterous ivory horn. "+
    "Both edges of what serves as its blade are wickedly %^BOLD%^%^BLUE%^"+
    "serrated%^BOLD%^%^WHITE%^, coming together to a %^BOLD%^%^RED%^razor-sharp"+
    "%^BOLD%^%^WHITE%^ point at the tip. Beneath the serrated blade is "+
    "a strange %^BOLD%^%^GREEN%^emerald%^BOLD%^%^WHITE%^ stone serving as a makeshift "+
    "guard. The stone seems hollowed out and you think that you could "+
    "%^BOLD%^%^GREEN%^check it%^BOLD%^%^WHITE%^ if you wanted. "+
    "A %^RESET%^%^WHITE%^dirty cloth%^BOLD%^%^WHITE%^ "+
    "has been wrapped around the horn several times beneath the stone "+
    "as a means of gripping it safely.%^RESET%^");

    set_lore("%^BOLD%^%^WHITE%^This dagger was crafted from the "+
    "horn of an ancient beast known simply as a '%^BOLD%^%^RED%^d%^BOLD%^%^BLACK%^r"+
    "%^BOLD%^%^RED%^e%^BOLD%^%^BLACK%^a%^BOLD%^%^RED%^d%^BOLD%^%^BLACK%^h%^BOLD%^"+
    "%^RED%^o%^BOLD%^%^BLACK%^r%^BOLD%^%^RED%^n%^BOLD%^%^WHITE%^'. The process "+
    "for creating such a weapon has varied over the years but the latest incarnation "+
    "requires a stone which serves as a rudimentary guard and a thick cloth material to "+
    "wrap around the base of the horn to allow someone the ability "+
    "to safely wield it.%^RESET%^");

    set_property("lore difficulty", 22);
    set_value(3000);
    set_property("enchantment",5);
    set_wield((:TO,"wield_func":));
    set_unwield((:TO,"unwield_func":));
    set_hit((:TO,"hit_func":));
    charges = 0;
}

void init()
{
    ::init();
    if(!objectp(TO)) return;
    add_action("check", "check");
    add_action("fill", "fill");
    if(isSet) return;    
    if(!objectp(ETO)) return;
    if(FEATS_D->usable_feat(ETO, "weapon finesse"))
    {
        set_item_bonus("dexterity", 6);
    }
    else { set_item_bonus("strength", 6);}
    isSet = 1;
}

int fill(string str)
{
    string tmp, arg, tar;
    object vial;
    int doses;
    if(!objectp(TO)) return 0;
    if(!objectp(ETO)) return 0;
    if(!living(ETO)) return 0;
    if(!stringp(str)) return 0;
    str = lower_case(str);
    if(sscanf(str, "%s with %s", arg, tar) != 2) return 0;
    if(arg != "it" && arg != "emerald" && arg != "stone" && arg != "dagger") return 0;
    if(!objectp(vial = present(tar, ETO))) 
    {
        tell_object(ETO, "You have no "+tar+".");
        return 1;
    }
    if(!vial->id("poison_vial_object_xxx"))
    {
        tell_object(ETO, vial->query_short()+" is not a valid poison!");
        return 1;
    }
    if(stringp(TO->query("PoisonType")))
    {
        if((string)TO->query("PoisonType") != (string)vial->query_poison_name())
        {
            tell_object(ETO, "%^BOLD%^%^GREEN%^You jab the tip of your ivory "+
            "dagger into the vial of poison and watch as it all spills out!%^RESET%^");
            if(objectp(EETO) && !ETO->query_invis())
            {
                tell_room(EETO, ETOQCN+"%^BOLD%^%^GREEN%^ jabs the tip of "+ETO->QP+
                " ivory dagger into "+vial->query_short()+" and it all spills out!%^RESET%^", ETO);
            }
            vial->set_poison_doses(0);
            return 1;
        }
        else
        {
            charges = (int)TO->query("PoisonDoses");
            if(charges >= 15)
            {
                tell_object(ETO, "%^BOLD%^%^GREEN%^You jab the tip of your ivory "+
                "dagger into the vial of poison and watch as it all spills out!%^RESET%^");
                if(objectp(EETO) && !ETO->query_invis())
                {
                    tell_room(EETO, ETOQCN+"%^BOLD%^%^GREEN%^ jabs the tip of "+ETO->QP+
                    " ivory dagger into "+vial->query_short()+" and it all spills out!%^RESET%^", ETO);
                }
                vial->set_poison_doses(0);
                return 1;
            }            
            doses = (int)vial->query_poison_doses();
            doses += (int)TO->query("PoisonDoses");
            if(doses >= 15) 
            {
                tell_object(ETO, "%^BOLD%^%^GREEN%^You jab the tip of your ivory "+
                "dagger into the vial of poison and watch as some of the liquid is "+
                "sucked through the blade and into the emerald stone, the rest of "+
                "it spills out!%^RESET%^");
                if(objectp(EETO) && !ETO->query_invis())
                {
                    tell_room(EETO, ETOQCN+"%^BOLD%^%^GREEN%^ jabs the tip of "+ETO->QP+
                    " ivory dagger into "+vial->query_short()+" you watch as some of the "+
                    "liquid is sucked through the blade and into the emerald stone, the rest of "+
                    "it spills out!%^RESET%^", ETO);
                }
                doses = 15;
            }
            else
            {
                tell_object(ETO, "%^BOLD%^%^GREEN%^You jab the tip of your ivory "+
                "dagger into the vial of poison and watch as the liquid is "+
                "sucked through the blade and into the emerald stone!%^RESET%^");
                if(objectp(EETO) && !ETO->query_invis())
                {
                    tell_room(EETO, ETOQCN+"%^BOLD%^%^GREEN%^ jabs the tip of "+ETO->QP+
                    " ivory dagger into "+vial->query_short()+" you watch as the "+
                    "liquid is sucked through the blade and into the emerald stone!", ETO);
                }
            }
            TO->delete("PoisonDoses");
            TO->set("PoisonDoses", doses);
            vial->set_poison_doses(0);
            return 1;
        }
    }
    else
    {
        if((string)vial->query_delivery_method() != "injury")
        {
            tell_object(ETO, "%^BOLD%^%^GREEN%^You jab the tip of your ivory "+
            "dagger into the vial of poison and watch as it all spills out!%^RESET%^");
            if(objectp(EETO) && !ETO->query_invis())
            {
                tell_room(EETO, ETOQCN+"%^BOLD%^%^GREEN%^ jabs the tip of "+ETO->QP+
                " ivory dagger into "+vial->query_short()+" and it all spills out!%^RESET%^", ETO);
            }
            vial->set_poison_doses(0);
            return 1;
        }
        else
        {
            doses = (int)vial->query_poison_doses();
            tell_object(ETO, "%^BOLD%^%^GREEN%^You jab the tip of your ivory "+
            "dagger into the vial of poison and watch as the liquid is "+
            "sucked through the blade and into the emerald stone!%^RESET%^");    
            if(objectp(EETO) && !ETO->query_invis())
            {
                tell_room(EETO, ETOQCN+"%^BOLD%^%^GREEN%^ jabs the tip of "+ETO->QP+
                " ivory dagger into "+vial->query_short()+" you watch as the "+
                "liquid is sucked through the blade and into the emerald stone!", ETO);
            }
            TO->delete("PoisonDoses");
            TO->set("PoisonDoses", doses);
            TO->set("PoisonType", (string)vial->query_poison_name());
            vial->set_poison_doses(0);
            return 1;
        }
    }
    return 0;
}


int check(string str)
{
    string tmp;
    if(!objectp(TO)) return 0;
    if(!objectp(ETO)) return 0;
    if(!living(ETO)) return 0;
    if(!stringp(str)) return 0;
    str = lower_case(str);
    if(str != "it" && str != "emerald" && str != "stone" && str != "dagger") return 0;
    tell_object(ETO, "%^BOLD%^%^GREEN%^You carefully check over the strange "+
    "emerald stone....");
    charges = (int)TO->query("PoisonDoses");
    if(charges > 15) 
    {
        TO->delete("PoisonDoses");
        TO->set("PoisonDoses", 15);
        charges = 15;
    }  
    switch(charges)
    {
        case 0:
            tmp = ".... it appears that the inside of the stone is empty. "+
            "You believe that you could <fill with something> if you had a suitable "+
            "liquid.";
            break;
        case 1..5:
            tmp = ".... it appears that there is a little liquid inside the stone. "+
            "You believe that you could <fill with something> if you had a suitable "+
            "liquid.";
            break;
        case 6..14:
            tmp = ".... it appears that there is a lot of liquid left inside the stone. "+
            "You believe that you could <fill with something> if you had a suitable "+
            "liquid.";
            break;      
        case 15:
            tmp = ".... it appears that the stone is completely full of liquid.";
            break;
    }
    if(charges)
    {
        tmp += " You determine that the liquid is "+(string)TO->query("PoisonType");
        if(strsrch(tmp, "poison") == -1) tmp += " poison.";
        else tmp += ".";
        
    }
    tell_object(ETO, "%^BOLD%^%^GREEN%^"+tmp+"%^RESET%^");
    if(!ETO->query_invis())
    {
        if(objectp(EETO)) 
        {
            tell_room(EETO, ETOQCN+"%^BOLD%^%^GREEN%^ seems to be carefully studying "+
            ETO->QP+" ivory dagger.%^RESET%^", ETO);
        }
    }
    return 1;
}


int wield_func()
{
    if((int)ETO->query_highest_level() < 35)
    {
        tell_object(ETO, "%^BOLD%^%^CYAN%^You can't seem to figure "+
        "out how to use the dagger properly!%^RESET%^");
        return 0;
    }
    tell_object(ETO, "%^BOLD%^%^BLACK%^You feel an immense power "+
    "course through your veins as you wield the dagger!%^RESET%^");
    return 1;
}


int unwield_func()
{
    tell_object(ETO, "%^BOLD%^%^BLACK%^You feel unsettled as the power "+
    "fades away.%^RESET%^");
    return 1;
}

int hit_func(object targ)
{
    string tlimb;
    if(!objectp(ETO)) return 0;
    if(!objectp(EETO)) return 0;
    if(!objectp(targ)) return 0;
    if(random(1000) < 325)
    {
        tlimb = targ->return_target_limb();
        tell_object(ETO, "%^BOLD%^%^BLACK%^You stab into "+targ->QCN+"%^BOLD%^%^BLACK%^ "+
        " piercing "+targ->QP+" "+tlimb+"%^BOLD%^%^BLACK%^!%^RESET%^");
				
        tell_object(targ, ETOQCN+"%^BOLD%^%^BLACK%^ stabs into you, piercing your "+
        tlimb+"!%^RESET%^");
				
        tell_room(EETO, ETOQCN +"%^BOLD%^%^BLACK%^ stabs into "+targ->QCN+"%^BOLD%^%^BLACK%^ "+
        "piercing "+targ->QP+" "+tlimb+"!%^RESET%^", ({ETO, targ}));                
        return roll_dice(2,6);
    }
    return 0;
}

