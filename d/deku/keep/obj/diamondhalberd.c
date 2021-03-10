#include <std.h>
#define HIT ({"maim", "destroy", "mutilate", "shear", "strike" })
inherit "/d/common/obj/weapon/halberd.c";

void create()
{
    ::create();
    set_id(({"heavy halberd","diamond pole axe","pole axe","diamond halberd",
    "diamond pole arm","diamond polearm","polearm","pole arm","halberd"}));
    set_name("a diamond halberd");
    set_obvious_short("A diamond halberd");
    set_short("A %^BOLD%^%^WHITE%^di%^CYAN%^am%^BOLD%^"+
    "%^WHITE%^ond%^RESET%^%^BOLD%^%^GREEN%^ "+
    "halberd%^RESET%^");
    set_long("%^CYAN%^This massive eight foot poleaxe "+
    "is made from a solid piece of "+
    "%^BOLD%^%^WHITE%^di%^CYAN%^am%^BOLD%^%^WHITE%^ond%^RESET%^%^CYAN%^.  "+
    "It has a "+
    "convex blade with several %^BLUE%^grooves%^RESET%^%^CYAN%^ "+
    "etched into it, with a "+
    "curved spike potruding off the reverse side.  The shaft of this "+
    "poleaxe is a "+
    "varying coloration of %^BOLD%^%^WHITE%^di%^CYAN%^am%^BOLD%^%^WHITE%^"+
    "ond%^RESET%^%^CYAN%^, "+
    "it extends past the convex axe blade and ends in a large spear head."+
    "%^RESET%^");
    set_lore("The diamond halberd was a weapon of choice for Verbobone's militia."+
             " Clan Stonecrusher helped equip Verbobone as darkness swept across Deku.");
    set_value(2000);
    set_weight(15);
    set_property("enchantment",3);
    set_wield((:TO,"wield_me":));
    set_unwield("%^RED%^Your muscles are relieved as "+
    "you release the heavy diamond halberd!"+
    "%^RESET%^");
    set_hit((:TO,"special":));
}

int wield_me() 
{    
    tell_object(ETO,"%^RED%^Your muscles strain "+
    "as you prepare the diamond halberd!%^RESET%^");		
    return 1;
}

int do_what_damage(string str) 
{
    int dam;
    switch(str) 
    {
        case "maim":
            dam = roll_dice(5,4);
            break;
        case "destroy":
            dam = roll_dice(4,4);
            break;
        case "mutilate":
            dam = roll_dice(3,4);
            break;
        case "strike":
            dam = roll_dice(2,4);
            break;
        case "shear":
            dam = roll_dice(1,6);
            break;
    }
    return dam;
}
	
int special(object targ) 
{
    int chance;
    string hits, limb;
    hits = HIT[random(sizeof(HIT))];

    chance = random(1000);
		
    switch(chance) 
    {
        case 645..700:

            tell_object(ETO,"%^RED%^You sweep your halberd under " +
            targ->query_cap_name() + 
            "%^RED%^'s feet, tripping " + 
            targ->query_objective() + "%^RED%^!%^RESET%^");
        
            tell_room(environment(ETO),ETO->query_cap_name() + 
            "%^RED%^ sweeps " +
            ETO->query_possessive() + "%^RED%^ halberd under " + 
            targ->query_cap_name() +
            "%^RED%^'s feet, tripping " +targ->query_objective() + 
            "%^RED%^!%^RESET%^",({targ,ETO}));
        
            tell_object(targ,ETO->query_cap_name() + "%^RED%^ sweeps " +
            ETO->query_possessive() + "%^RED%^ halberd under your feet, "+
            "tripping you!%^RESET%^");
        
            targ->set_tripped(random(2) + 1,"You struggle to get "+
            "back to your feet!");
        break;
            case 800..925:

            limb = targ->return_target_limb();
            tell_object(ETO,"%^BLUE%^You " +hits+ " " + 
            targ->query_cap_name() + "%^BLUE%^ in "+
            "the " + limb + "%^BLUE%^ with your halberd!%^RESET%^");
        
            tell_room(environment(ETO),ETO->query_cap_name() + " " +hits+ " " + 
            targ->query_cap_name() + "%^BLUE%^ in the " + limb + 
            "%^BLUE%^ with " + 
            ETO->query_possessive() + 
            "%^BLUE%^ halberd!%^RESET%^",({targ,ETO}));
        
            tell_object(targ,ETO->query_cap_name() + "%^BLUE%^ " + 
            hits + " you in the " +
            limb + "%^BLUE%^ with " + 
            ETO->query_possessive() + "%^BLUE%^ halberd!%^RESET%^");
            return targ->do_damage(limb,do_what_damage(hits));
            break;
    }
    return 0;
}
