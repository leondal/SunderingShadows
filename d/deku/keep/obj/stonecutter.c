#include <std.h>
inherit "/d/common/obj/weapon/pick.c";

void create() 
{   
    ::create();
    set_id(({ "pick","stonecutter","stonecutter pick"}));
    set_name("A heavy iron pick");
    set_obvious_short("A heavy iron pick");
    set_short("%^BOLD%^%^WHITE%^Stonecutter%^RESET%^");
    set_long("%^BOLD%^%^WHITE%^This weapon is a solid piece "+
    "of heavy iron that has been "+
    "forged into what is commonly known as a pick.  "+
    "The handle extends approximately "+
    "three feet and then suddenly splits into two "+
    "large %^RED%^spikes%^BOLD%^%^WHITE%^.  "+
    "Each of the spikes end in a %^RED%^sharpened "+
    "%^BOLD%^%^BLACK%^black metal%^BOLD%^%^WHITE%^.  "+
    "At the opposite end of the weapon there is a thick "+
    "%^RED%^cri%^YELLOW%^ms%^RED%^on "+
    "%^BOLD%^%^WHITE%^colored fabric wrapped around it, "+
    "serving as a makeshift grip for the handle.%^RESET%^");
    set_lore("%^BOLD%^%^WHITE%^Ancient dwarves of Deku aided the citizens "+
    "of Verbobone in crafting these picks. They had their dwarven priest "+
    "enchant them with magic, in a hope that the citizens would be able to "+
    "aid the noble dwarves in their battles against the encroaching corruption");
        
    set_property("enchantment",4);
    set_weight(8);
    set_value(4000);
    set_wield((:TO,"wield_me":));    
    set_item_bonus("endurance", 2);
    set_unwield((:TO,"unwield_me":));
    set_hit((:TO,"special":));
}

int wield_me() 
{
    tell_object(ETO,"%^BOLD%^%^WHITE%^You take hold of "+
    "the pick and consider your options.%^RESET%^");
    if(!ETO->query_invis()) 
    {
        tell_room(EETO,ETO->QCN + "%^BOLD%^%^WHITE%^ takes hold of "+
        ETO->QP + "%^BOLD%^%^WHITE%^ pick.%^RESET%^",ETO);
    }
    return 1;
}

int unwield_me() 
{
    tell_object(ETO,"%^BOLD%^%^RED%^You release the pick "+
    "with a heavy sigh.%^RESET%^");
    if(!ETO->query_invis()) 
    {
        tell_room(EETO,ETO->QCN + "%^BOLD%^%^RED%^ "+
        "sighs heavily.%^RESET%^",ETO);
    }
    return 1;
}

int special(object targ) 
{
    if(random(10) > 5) 
    {
        ETO->set_property("magic",1);
        tell_object(ETO,"%^BOLD%^%^RED%^You sink your "+
        "pick deep into " +targ->QCN+
        "%^BOLD%^%^RED%^'s flesh!%^RESET%^");
        tell_object(targ,ETO->QCN + "%^BOLD%^%^RED%^ sinks " +
        ETO->query_possessive()+
        "%^BOLD%^%^RED%^ pick deep into your flesh, "+
        "causing you to scream out in pain!%^RESET%^");
 
        tell_room(EETO,targ->QCN + "%^BOLD%^%^RED%^ screams out in pain "+
        "as " +ETO->QCN + "%^BOLD%^%^RED%^ sinks a pick deep into "
        +targ->QP+ " %^BOLD%^%^RED%^flesh!%^RESET%^",({targ,ETO}));

        targ->do_damage(targ->return_target_limb(),roll_dice(1,10));
        ETO->set_property("magic",-1);
    }
    return 0;
}