//Runs from inherit properly now. Nienne, 08/07
#include <std.h>

inherit "/d/common/obj/armour/bracers";


int is_metal()
{
    return 0;
}

void create()
{
    ::create();
    set_name("green bracers");
    set_id(({ "bracers", "bracers of the serpent" }));

    set_short("%^BOLD%^%^GREEN%^Bracers of the %^RESET%^%^GREEN%^" +
              "S%^CYAN%^e%^BOLD%^%^GREEN%^r%^RESET%^%^GREEN%^p%^BOLD%^" +
              "%^GREEN%^e%^RESET%^%^CYAN%^n%^GREEN%^t%^RESET%^");

    set_obvious_short("%^BOLD%^%^GREEN%^A pair of jade bracers%^RESET%^");

    set_long("%^GREEN%^These bracers are made out of finely crafted" +
             " %^BOLD%^jade%^RESET%^%^GREEN%^ that has been formed into" +
             " a thick body serpent.  The serpent's body %^CYAN%^coils" +
             "%^GREEN%^ around the wearers arm three times before ending" +
             " in a smooth curved tail that rests close to the elbows.  " +
             "The diamond shaped head of the serpent faces downwards, " +
             "brushing against the back of the hands.  The jade is scored" +
             " with criss-cross groves that are filled in with %^BOLD%^%^WHITE%^" +
             "molten silver%^RESET%^%^GREEN%^, giving an illusion of scales.  Two small " +
             " %^ORANGE%^t%^YELLOW%^o%^RESET%^%^ORANGE%^pa%^YELLOW%^z" +
             "%^RESET%^%^ORANGE%^es%^GREEN%^ mark the eyes of this fantastic"
             " and life-like piece of work.\n%^RESET%^");

    set_value(300000);

    set_lore("The Bracers of the Serpents are rumored to have been made by a mage with a fondness for snakes "
             "name Xelthestliana.  The magess took the serpent up as her totem symbol, even to the point of always "
             "having at least one with her were ever she traveled.  There are reports even that Xelthestliana was "
             "able to alter and shape her spells so they took on serpent like qualities.");

    set_property("no curse", 1);
    set_property("enchantment", 7);

    set_item_bonus("spell penetration", 4);
    set_item_bonus("wisdom", 6);

    set_wear((: TO, "wear_func" :));
    set_remove((: TO, "remove_func" :));
    set_struck((: TO, "strike_func" :));

    set_property("quest required", "%^BOLD%^%^RED%^Defeated the great red wyrm Klauth!%^RESET%^");
    set_property("level required", 35);
}

int wear_func()
{
    ::check();
    tell_room(EETO, "%^GREEN%^A pair of jade serpents slighter" +
              " around " + ETOQCN + "'s forearms, locking themselves in place.", ETO);
    tell_object(ETO, "%^GREEN%^The bracers slither around your forearms as " +
                "they set themselves in place.");
    return 1;
}

int remove_func()
{
    tell_room(EETO, "%^GREEN%^A pair of jade serpents " +
              "slither off of " + ETOQCN + " 's forearms.", ETO);
    tell_object(ETO, "%^GREEN%^The serpents heed your wishes and " +
                "begin to slither off of your forearms.");
    return 1;
}

int strike_func(int damage, object what, object targ)
{
    tell_object(ETO, "%^GREEN%^You hear a faint slithering in your ear, " +
                "imparting you with fragments of knowledge.");

    switch (random(2)) {
    case 0..1:
        new("/cmds/spells/a/_acid_breath")->use_spell(ETO, targ, ETO->query_base_character_level(), 100, "mage");
        break;

    case 5..6:
        new("/cmds/spells/a/_acid_orb")->use_spell(ETO, targ, ETO->query_base_character_level(), 100, "mage");
        break;

    default:
        new("/cmds/spells/a/_acid_arrow")->use_spell(ETO, targ, ETO->query_base_character_level(), 100, "mage");
        break;
    }
    return damage;
}
