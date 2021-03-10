#include <std.h>
#include "../undead.h"

inherit CWEAP"sickle";

int uses;
object owned;

void init() 
{
    ::init();
    if(interactive(TP) && !owned) owned = TPQN;
}

void create() 
{
    ::create();
    set_name("sickle of venom");
    set_id(({"sickle","sickle_of_venom"}));
    set_obvious_short("%^RESET%^%^BLUE%^a rune covered sickle%^RESET%^");
    set_short("%^BOLD%^%^GREEN%^S%^RESET%^%^BLUE%^ickle of Venom%^RESET%^");
    
    set_long("%^BOLD%^%^BLUE%^This sickle is made of a most mysterious metal "
        "which seems to almost absorb the light around it instead of reflect "
        "it.  Along the blade you can make out very precise runes which where"
        " carved into it by a master artisan.%^RESET%^");

    set("value",1000);
    set_hit((: TO, "extra_hit":));
    set_wield((: TO, "extra_wield":));
    set_property("enchantment",2);
    set_type("slashing");
    uses = roll_dice(3,6);
}

int extra_hit(object targ) 
{
    if(!objectp(targ))      { return 0; }
    if(!objectp(ETO))       { return 0; }
    if(uses > 1)            { return 1; }
    if(random(3))           { return 1; }
    if(!ETO->is_player())   { return roll_dice(1,6); }
    
    tell_object(ETO,"%^BOLD%^%^BLACK%^The sickle throbs violently as it "
        "cuts into "+targ->QCN+"'s flesh!");
    tell_object(targ,"%^BOLD%^%^BLACK%^The sickle wielded by "+ETO->QCN+" "
        "throbs as it cuts into your flesh!");
    tell_room(EETO,"%^BOLD%^%^BLACK%^The sickle wielded by "+ETO->QCN+" throbs "
        "as it cuts "+targ->QCN+"'s flesh!",(({ETO, targ})));
    TO->set_property("magic",1);
    targ->do_damage(targ->return_limb(),roll_dice(5,6));
    TO->set_property("magic",-1);
    uses--;
}

int extra_wield() 
{
    if(!objectp(ETO)) return 0;
    if(!ETO->is_player()) return 1;
    
    if((int)ETO->query_level() < 15) 
    {
        write("You can not control the evil that resides within the blade!");
	    return 0;
    }
    if((string)ETO->query_name() != owned)
    {
        write("%^CYAN%^You are not worthy of such a weapon.%^RESET%^");
        TO->remove();
        return 0;
    }
    
    if(uses > 0) 
    {
        tell_object(ETO,"%^RESET%^%^BLUE%^You hear dark voices calling "
            "out to your blade.");
        return 1;
    } 
    else 
    {
	tell_object(ETO,"%^BLUE%^The darkness within your blade has returned "
        "to its master.%^RESET%^");
	    return 1;
    }
}
