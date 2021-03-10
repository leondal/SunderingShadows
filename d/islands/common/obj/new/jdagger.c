#include <std.h>

inherit "/d/common/obj/weapon/dagger.c";


void create()
{
    ::create();
    set_id(({ "dagger", "ghoul's dagger", "jewel hilted dagger", "Dagger of the Ghoul's Touch" }));

    set_name("Dagger of the Ghoul's Touch");

    set_obvious_short("%^BOLD%^%^BLACK%^dagger %^WHITE%^with a %^BOLD%^%^RED%^j%^RESET%^%^RED%^e%^BOLD%^w%^RESET%^%^RED%^e%^BOLD%^l%^RESET%^%^RED%^e%^BOLD%^d %^WHITE%^%^hilt%^RESET%^");

    set_short("%^BOLD%^%^RED%^D%^BOLD%^%^YELLOW%^a%^BOLD%^%^RED%^gger of the Gh%^BOLD%^%^YELLOW%^o%^BOLD%^%^RED%^ul's %^BOLD%^%^RED%^Touch%^RESET%^");

    set_long(
        "This dagger appears to be crafted from a very sturdy metal. It has no " +
        "scratches, nor any other mark that would appear as if it was ever used. " +
        "On the hilt are inset three gems. Two rubies on the ends of the hilt, " +
        "and a sizeable garnet in the center which seems to glow slightly.");

    set_lore(
        "This dagger was created by the lich known as Zanl'dal for the demon known" +
        " as grimtooth. Grimtooth lost the dagger when he was banished from the" +
        " prime material plane by the bladesinger Arvanariel Clearskies.");

    set_value(100000);

    set_property("no curse", 1);
    set_property("enchantment", 7);

    set_item_bonus("attack bonus", 7);
    set_item_bonus("damage bonus", 7);


    set_hit((: TO, "hit_func" :));
    set_wield((: TO, "wield_func" :));
    set_unwield((: TO, "unwield_func" :));

    set_property("quest required", "%^BOLD%^%^RED%^Defeated the great red wyrm Klauth!%^RESET%^");
    set_property("level required", 35);
}

int wield_func()
{
    tell_object(ETO, "The blade of the dagger becomes translucent, and you feel it drain your life slightly.");
    return 1;
}

int unwield_func()
{
    tell_object(ETO, "The blade of the dagger fades back into existance as you release your hold, and you feel stronger.");
    return 1;
}

int hit_func(object targ)
{
    int i;

    if (!objectp(TO)) {
        return 1;
    }
    if (!objectp(ETO)) {
        return 1;
    }
    if (!objectp(targ)) {
        return 1;
    }

    if (random(1000) < 500) {
        switch (random(1000)) {
        case 0..300:

            tell_room(EETO, "%^BOLD%^%^WHITE%^" + ETOQCN + " stabs " + targ->QCN + " and the flesh around the wound turns deathly pale .", ({ ETO, targ }));
            tell_object(ETO, "%^BOLD%^%^WHITE%^You stab " + targ->QCN + " and the flesh around the wound turns deathly pale!");
            tell_object(targ, "%^BOLD%^%^WHITE%^" + ETOQCN + " stabs you and the flesh around the wound turns deathly pale! ");
            targ->do_damage("torso", roll_dice(6, 10));
            break;

        case 301..600:

            tell_room(EETO, "%^BOLD%^%^BLACK%^" + ETOQCN + "'s dagger flickers as passes through " + targ->QCN + "'s flesh!", ({ ETO, targ }));
            tell_object(ETO, "%^BOLD%^%^BLACK%^Your blade flickers as you cut into " + targ->QCN + "'s flesh!");
            tell_object(targ, "%^BOLD%^%^BLACK%^" + ETOQCN + "'s blade flickers as it passes through your flesh!");
            targ->do_damage("torso", roll_dice(6, 10));
            break;

        case 601..800:

            tell_room(EETO, "%^BOLD%^%^RED%^" + ETOQCN + " creates a %^BOLD%^%^CYAN%^mirror image%^BOLD%^%^RED%^ and they attack in unison!", ({ ETO, targ }));
            tell_object(ETO, "%^BOLD%^%^RED%^Your dagger creates a %^BOLD%^%^CYAN%^mirror image%^BOLD%^%^RED%^ of you, and you both attack in unison!");
            tell_object(targ, "%^BOLD%^%^RED%^" + ETOQCN + " creates a %^BOLD%^%^CYAN%^mirror image%^BOLD%^%^RED%^ and they attack in unison!");
            ETO->execute_attack();
            ETO->execute_attack();
            return 1;

        case 801..998:

            tell_room(EETO, "%^BOLD%^%^GREEN%^" + ETOQCN + " arcs the dagger and the blade fizzles into a green mist to lash out!", ({ ETO, targ }));
            tell_object(ETO, "%^BOLD%^%^GREEN%^Your blade fizzles into a green mist as you arc it to lash out at " + targ->QCN + "!");
            tell_object(targ, "%^BOLD%^%^GREEN%^" + ETOQCN + "'s blade fizzles into a green mist and lashes out at you!");
            targ->do_damage("torso", roll_dice(6, 10));
            break;

        case 999:

            tell_room(EETO, "%^RESET%^%^RED%^" + ETOQCN + "'s eyes glaze over...", ({ ETO, targ }));
            tell_object(ETO, "%^RESET%^%^RED%^You feel a spirit over take you... %^BOLD%^%^CYAN%^Grimtooth whispers to you%^RESET%^: I got it from here!");
            tell_object(targ, "%^BOLD%^%^CYAN%^Someone whispers to you%^RESET%^: The best assassins leave no marks!");

            set_property("magic", 1);

            for (i = 0; i < 13; i++) {
                tell_object(targ, "%^BOLD%^%^RED%^You feel a stabbing sensation in your head!");
                targ->do_damage("torso", roll_dice(6, 10));
            }

            set_property("magic", -1);
            break;
        }
    }
    return roll_dice(3, 10);
}
