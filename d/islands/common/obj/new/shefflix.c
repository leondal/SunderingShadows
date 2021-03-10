#include <std.h>

inherit "/d/common/obj/weapon/scimitar.c";


void create()
{
    ::create();
    set_name("dark scimitar");
    set_id(({ "scimitar","sword", "dark scimitar" }));

    set_short("%^BOLD%^%^BLACK%^Sh%^CYAN%^le%^BLACK%^fflix's %^RESET%^D"+
        "%^BOLD%^%^BLACK%^ar%^RESET%^k %^BOLD%^%^CYAN%^Sc%^BLACK%^"+
        "imit%^CYAN%^ar%^RESET%^");

    set_obvious_short("%^BOLD%^%^BLACK%^A rune covered dark scimitar%^RESET%^");

    set_long("%^BOLD%^%^BLACK%^This dark scimitar is heavily covered with "+
        "%^BOLD%^%^YELLOW%^runes%^BOLD%^%^BLACK%^. The single bladed weapon"+
        " is wickedly curved, much like eastern assassin daggers. Its blade"+
        " is thick and heavy. It's covered with %^BOLD%^%^RED%^dark runes "+
        "%^BOLD%^%^BLACK%^. The runes appear to be set in such a way as to"+
        " %^BOLD%^%^BLUE%^lacerate %^BOLD%^%^BLACK%^as the blade slides "+
        "through, making stitching a wound much more difficult. The hilt "+
        "is lithe and fitted for a delicate hand, it however is longer "+
        "allowing a larger hand to still fit. The balance at first glance"+
        " appears to be blade heavy, but it holds well for a weapon with"+
        " such a heavily made blade.%^RESET%^\n");

    set("read","Shlefflix is master. Shlefflix is my master. Shlefflix shall master all by my hand.");
    set("langage","drow");

    set_value(250000);

    set_lore("This is a heavy drow weapon. The rune obviously appear to be drow. This is meant as a individual "
        "warriors weapon. It lacks the subtlty of typical drow weapons. Its as if drow made this weapon to "
        "polute the human world.");

    set_property("no curse",1);
    set_property("enchantment",7);

    set_item_bonus("attack bonus",7);
    set_item_bonus("dexterity",6);

    set_wield((:TO,"wield_func":));
    set_unwield((:TO,"unwield_func":));
    set_hit((:TO,"hit_func":));

    set_property("quest required","%^BOLD%^%^RED%^Defeated the great red wyrm Klauth!%^RESET%^");
    set_property("level required",35);
}


int wield_func()
{
    tell_object(ETO,"%^BOLD%^You heft the blade and feel Shlefflix's presence.%^RESET%^");
    return 1;
}


int unwield_func()
{
    tell_object(ETO,"%^BOLD%^Shlefflix's presence is lost to you.%^RESET%^");
    return 1;
}


int hit_func(object targ)
{
    if(!objectp(targ) || !objectp(ETO)) return 1;

    if(random(2))
    {
        switch(random(9))
        {
        case 0..4:

            tell_object(targ, "%^BOLD%^%^BLUE%^The dark scimitar rips into "+
                "your skin, lacerating deeply and sending waves of %^RED%^pain "+
                "%^BLUE%^through your body.");
            tell_room(EETO,"%^BOLD%^%^BLUE%^The dark scimitar rips into "+
                ""+targ->QCN+"'s skin, lacerating deeply and making %^RED%^"+
                ""+targ->QO+" wince from the pain.", targ);
            set_property("magic",1);
            targ->do_damage(targ->return_target_limb(),random(16)+15);
            set_property("magic",-1);
            break;

        case 5..6:

            tell_object(targ, "%^BOLD%^%^BLACK%^The scimitar slashes "+
                "quickly across your chest, cutting deeply before "+
                ""+ETO->QCN+" spins to %^RED%^SMASH %^BLACK%^you in "+
                "the jaw with the hilt of the blade, stunning you.");
            tell_room(EETO, "%^BOLD%^%^BLACK%^The scimitar slashes "+
                "quickly across "+targ->QCN+"'s chest, cutting deeply "+
                "before "+ETO->QCN+" spins to %^RED%^stun %^BLACK%^"+
                ""+targ->QO+" with a hit to the jaw with the hilt.",({targ, ETO}));
            tell_object(ETO, "%^BOLD%^%^BLACK%^The scimitar slashes "+
                "quickly across "+targ->QCN+"'s chest, cutting deeply "+
                "before you spin to %^RED%^stun %^BLACK%^"+targ->QO+" "+
                "with a hit to the jaw with the hilt.");
            set_property("magic",1);
            targ->do_damage(targ->return_target_limb(),random(14)+13);
            set_property("magic",-1);
            targ->set_paralyzed(6,"%^BOLD%^You are recovering from that hit.");
            break;

        case 7..8:

            tell_object(targ, "%^RED%^"+ETO->QCN+" slips to the side "+
                "and thrusts up, flashing the blade in a weaving "+
                "pattern and cutting you multiple times.");
            tell_room(EETO, "%^RED%^"+ETO->QCN+" slips to the side, "+
                "and thrusts up, flashing the blade in a weaving "+
                "pattern, cutting "+targ->QCN+" multiple times.",({targ, ETO}));
            tell_object(ETO, "%^RED%^You tumble to the side and "+
                "thrust up, flashing the blade in a weaving pattern, "+
                "cutting "+targ->QCN+" multiple times.");
            ETO->execute_attack();
            break;

        default:
            break;
        }
    }
    return roll_dice(3,6);
}
