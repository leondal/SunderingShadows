//Coded by Lujke

#include <std.h>
inherit "/d/common/obj/weapon/mclub.c";

void create()
{
    ::create();
    set_name("macquahuitl club");
    set_id(({ "club", "macquahuitl", "macquahuitl club" }));
    set_short("%^RED%^Mac%^BOLD%^q%^RESET%^%^RED%^ua%^ORANGE%^h%^RED%^ui"
              + "%^BOLD%^t%^RESET%^%^RED%^l%^ORANGE%^ club%^RESET%^");

    set_obvious_short("%^RESET%^%^ORANGE%^wood club lined with %^BLACK%^"
                      + "%^BOLD%^obsidion blades%^RESET%^");

    set_long("%^RESET%^%^ORANGE%^Crafted from a hard wood that has been"
             + " carved into a heavy club, this looks to be a very impressive"
             + " weapon. The handle has been wrapped in several layers of"
             + " %^YELLOW%^skins%^RESET%^%^ORANGE%^ and %^BLACK%^"
             + "%^BOLD%^leathers%^RESET%^%^ORANGE%^, providing a sturdy and"
             + " stable grip. The entire length of the club is lined with"
             + " %^BLACK%^%^BOLD%^square blades of obsidion%^RESET%^"
             + "%^ORANGE%^ sharpened to %^WHITE%^%^BOLD%^razor edges%^RESET%^"
             + "%^ORANGE%^. This provides the weapon with an incredible"
             + " slashing attack, and would leave a %^RED%^nasty wound"
             + "%^RESET%^%^ORANGE%^.");
    set_value(500);
    while ((int)TO->query_property("enchantment") != 7) {
        TO->remove_property("enchantment");
        TO->set_property("enchantment", 7);
    }
    set_wield((: TO, "wield_func" :));
    set_unwield((: TO, "unwield_func" :));
    set_hit((: TO, "hit_func" :));
}

int wield_func()
{
    if (!objectp(ETO) || !objectp(EETO)) {
        return 0;
    }
    tell_object(ETO, "As your grip tightens on the " + query_short()
                + ", you feel a %^RED%^strength%^RESET%^ grow in you.");
    tell_room(EETO, "As " + ETO->QCN + " wields the " + query_short() + ", the"
              + " light gleams off the %^BLACK%^%^BOLD%^obsidio"
              + "n%^RESET%^ and " + ETO->QS + " smiles.", ETO);
    return 1;
}

int unwield_func()
{
    if (!objectp(ETO) || !objectp(EETO)) {
        return 0;
    }
    tell_object(ETO, "You release your grip on the " + query_short()
                + ", flexing your fingers.");

    tell_room(EETO, ETO->QCN + "$N releases the " + query_short() + ", almost"
              + " reluctantly flexing " + ETO->QP + " fingers.", ETO);
    return 1;
}

int hit_func(object target)
{
    object wielder, room;
    wielder = ETO;
    room = EETO;
    if (!objectp(wielder) || !objectp(target) || !objectp(room)) {
        return 0;
    }
    if (random(10) >= 6) {
        tell_object(wielder, "%^RED%^You swing the " + query_short() + " in a"
                    + " wide arc, cutting a swath along " + target->QCN
                    + "'s neck.%^RESET%^");
        tell_object(target, wielder->QCN + "%^RESET%^%^RED%^ cuts a vicious"
                    + " gash along your neck with the " + query_short()
                    + "%^RESET%^");

        tell_room(room, "%^RED%^" + wielder->QCN + "%^RESET%^%^RED%^ swings"
                  + " widely, cutting across " + target->QCN + "%^RESET%^"
                  + "%^RED%^'s neck, causing " + target->QO + " to double"
                  + " over in pain.%^RESET%^", wielder, target);
        return roll_dice(5,10);
    }
    if (random(20) >= 18) {
        tell_object(wielder, "%^BLACK%^%^BOLD%^You step forward and jab the"
                    + " heavy point of the " + query_short() + " into "
                    + target->QCN + "'s gut%^RESET%^");
        tell_object(target, wielder->QCN + "%^BLACK%^%^BOLD%^Your vision"
                    + " swims as " + wielder->QCN + "%^BLACK%^%^BOLD%^"
                    + " jabs your stomach sharply with the "
                    + query_short() + "%^RESET%^");

        tell_room(room, "%^BLACK%^%^BOLD%^" + wielder->QCN + "%^BLACK%^"
                  + "%^BOLD%^ jabs " + target->QCN + "%^BLACK%^%^BOLD%^"
                  + " with the heavy point of the " + query_short()
                  + "%^BLACK%^%^BOLD%^, causing " + target->QO
                  + " to stagger back%^RESET%^", wielder, target);
        target->set_paralyzed(roll_dice(3,6), "You are badly winded!");
        return 1;
    }
}
