#include <std.h>
inherit "/d/common/obj/weapon/hammer_sm.c";
int flag;

void create() 
{
    ::create();
    set_id(({ "small hammer","hammer","hammer of quickness",
    "reliable hammer","elazo's hammer","small red hammer",
    "red hammer"}));
    set_name("hammer");
    set_obvious_short("A small red hammer");
    set_short("%^RED%^Elazo's Rel%^BLUE%^iab%^RED%^le Hammer of "+
    "%^BLUE%^Qui%^RED%^ck%^BLUE%^ness%^RESET%^");

    set_long("%^RESET%^This weapon is made from a solid piece "+
    "of %^BLUE%^adamantium%^RESET%^ "+
    "that has somehow been dyed a %^RED%^deep red%^RESET%^ hue.  "+
    "It is small, not quite two "+
    "feet in length from the head to the end of the handle.  "+
    "The double-head of the hammer is "+
    "slightly rounded and has several %^BOLD%^%^BLACK%^spikes%^RESET%^ "+
    "protruding from it, "+
    "making the %^RED%^inflicted wounds%^RESET%^ much more "+
    "severe.  A %^YELLOW%^bright yellow%^RESET%^ "+
    "line runs down the entire length of the handle, giving "+
    "the weapon a strikingly %^CYAN%^"+
    "bright%^RESET%^ appearance.  The handle ends in a "+
    "mushroomed tip which serves "+
    "as a means to keep the hammer from slipping from "+
    "the hands of the wielder.%^RESET%^");

    set_lore("%^CYAN%^Legand has it that there once lived a gluttoness "+
    "man named Elazo.  He become far more wealthy than "+
    "what he could handle, being an expert "+
    "in small hammers he had forged for himself a hammer "+
    "that fit his hands perfectly.  He became greedy and imprisoned "+
    "several mages, forcing them to create hammers for him, "+
    "much at his leisure, all in the same likeness.  The same "+
    "legends say that by the time "+
    "of his death each room of his mansion had several.  "+
    "It's unknown exactly how he died, "+
    "perhaps, some say, the hammer failed him.  "+
    "The hammer you hold is one of those "+
    "told of in those legends.%^RESET%^");
    set_property("enchantment",3);
    set_item_bonus("dexterity",2);
    set_value(2000);
    set_weapon_speed(1);
    set_wield((:TO,"wield_me":));
    set_unwield("%^CYAN%^You feel yourself slow down as you "+
    "release the handle of the hammer.%^RESET%^");
    set_hit((:TO,"special":));
}

int wield_me() 
{
    tell_object(ETO,"%^CYAN%^You feel yourself hastened as you "+
    "grab the handle of the hammer!%^RESET%^");
    return 1;
}

int special(object targ) 
{
    int chance;
    chance = random(1000);

    if(chance > 500 && chance < 700) 
    {
        tell_object(ETO,"%^BLUE%^Your attack becomes a blur to you "+
        "as you strike " +targ->QCN+"%^BLUE%^ with an "+
        "unnatural quickness!%^RESET%^");

        tell_object(targ,ETOQCN + "%^BLUE%^'s attack becomes a blur "+
        "as " +ETO->QS+"%^BLUE%^ strikes you with an unnatural "+
        "quickness!");

        tell_room(EETO,ETOQCN + "%^BLUE%^'s attack becomes a blur as "+
        ETO->QS + "%^BLUE%^ strikes " +targ->QCN + "%^BLUE%^ "+
        "with an unnatural quickness!%^RESET%^",({targ,ETO}));

        ETO->execute_attack();
        if(chance == 649 && TO->query_property("enchantment") >= 2) 
        {
            ETO->execute_attack();
        }
        return 0;
        //return targ->do_damage(targ->return_target_limb(),roll_dice(1,4));
    }
}
