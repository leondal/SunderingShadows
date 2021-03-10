//updated to inherit from hide armor - Odin 3/29/2020
#include <std.h>

inherit "/d/common/obj/armour/hide.c";

string owner;
int uses;

int query_uses()
{
    return uses;
}

void create()
{
    ::create();
    set_name("Carapace of the Scorpion Lord");

    set_id(({ "body armor", "armor", "hide", "scorpion armor", "carapace", "carapace of the scorpion lord", "carapace armor" }));

    set_short("%^BOLD%^%^BLACK%^Carapace of the %^RESET%^%^GREEN%^Sc%^BOLD%^%^BLACK%^o%^RESET%^%^GREEN%^rp"
              "%^BOLD%^%^BLACK%^i%^RESET%^%^GREEN%^on %^BOLD%^%^GREEN%^L%^RESET%^%^GREEN%^or%^BOLD%^%^GREEN%^d%^RESET%^");

    set_obvious_short("%^BOLD%^%^BLACK%^Black carapace body armor%^RESET%^");

    set_long("%^BOLD%^%^BLACK%^This suit of body armor is made of a strange hide, hardened near to the strength"
             " of metal.  All pieces of it fit perfectly together and allow completely free movement.  Designs cover the"
             " armor, almost seeming to extend outward slightly from the actual armor.  Eight legs wrap around the center"
             " of the armor, encasing the wearer.  The image of a %^RESET%^%^WHITE%^bone %^BOLD%^%^BLACK%^ridge connects each"
             " of the eight legs along the back of the armor.  At the bottom of the armor in the back a segmented tail starts,"
             " wraping around the armor once in an upwards spiral and going over the left shoulder leaving the end of the"
             " tail just over the left breast of the armor. Each leg and the tail are outlined with a faint dark"
             " %^RESET%^%^GREEN%^green%^BOLD%^%^BLACK%^.  A symbol is pictured on the stinger of the tail.  A circle,"
             " created by a scorpions tail and a curved dagger, connecting hilt to stinger and blade tip to base.  The"
             " tail and dagger are dyed %^RESET%^%^BLUE%^blue %^BOLD%^%^BLACK%^with hints of %^RESET%^%^RED%^red"
             " %^BOLD%^%^BLACK%^along the stinger and blade tip, with center of the circle remaining black.%^RESET%^\n");

    set_value(150000);

    set_lore("%^BOLD%^%^BLACK%^This armor has been rumored to have been around for quite some time, and was owned"
             " by a deadly desert warrior who could call upon the aid of scorpions by willing them to come to him.  Little"
             " else is known of the warrior, or his fate.%^RESET%^");

    set_property("no curse", 1);
    set_property("enchantment", 7);

    set_item_bonus("constitution", 6);
    set_item_bonus("strength", 6);
    set_item_bonus("endurance", 6);

    set_wear((: TO, "wear_func" :));
    set_remove((: TO, "remove_func" :));

    uses = random(1000) + 1000;

    set_property("quest required", "%^BOLD%^%^RED%^Defeated the great red wyrm Klauth!%^RESET%^");
    set_property("level required", 35);
}

int wear_func()
{
    tell_room(EETO, "%^BOLD%^%^BLACK%^The armor seems to take on an eerie presence as " + ETO->QCN + " wears it and the area is suddenly filled with the smell of fear and dark places.%^RESET%^", ETO);
    tell_object(ETO, "%^BOLD%^%^BLACK%^A strange yet oddly familiar feeling overcomes you as you slip on the armor.%^RESET%^");
    return 1;
}

int remove_func()
{
    tell_room(EETO, "%^BOLD%^%^BLACK%^" + ETO->QCN + " seems more placid as " + ETO->QS + " takes the armor off.%^RESET%^", ETO);
    tell_object(ETO, "%^BOLD%^%^BLACK%^Taking off the armor leaves you feeling vulnerable and open.%^RESET%^");
    return 1;
}

void init()
{
    ::init();
    add_action("will", "will");
}

int will(string str)
{
    object ob;
    int i;

    if (!objectp(ETO)) {
        return 0;
    }

    if (str == "scorpions" || str == "the scorpions" || str == "the scorpions to come" || str == "the scorpions to come to me") {
        if (uses < 1) {
            tell_object(TP, "%^BOLD%^%^BLACK%^The armor has no more magic.%^RESET%^");
            return 1;
        }

        if (present("prscorpion", EETO)) {
            tell_object(TP, "%^RESET%^%^ORANGE%^There are already scorpions protecting you!%^RESET%^");
            return 1;
        }

        if (!TO->query_worn()) {
            tell_object(ETO, "%^BOLD%^%^BLACK%^You must be wearing the armor to command the beasts of the dark!%^RESET%^");
            return 1;
        }


        tell_object(TP, "%^BOLD%^%^BLACK%^You close your eyes and put your mind somewhere else.  Slowly the ground shivers and begins to crack, and little black scorpions begin to crawl out of the cracks!%^RESET%^");
        tell_room(EETO, "%^BOLD%^%^BLACK%^As " + ETOQCN + " closes " + ETO->QP + " eyes and begins to chant some gutteral language, tiny cracks begin to form, from which several small scorpions scamper out to aid " + ETO->QO + "!%^RESET%^", ETO);

        for (i = 0; i < 5; i++) {
            ob = new("/d/islands/common/obj/new/scorp.c");
            ob->move(EETO);
            ob->force_me("protect " + ETO->query_name());
            ETO->add_follower(ob);
        }

        uses--;
        return 1;
    }

    if (!str) {
        tell_object(TP, "%^BOLD%^%^BLACK%^You mean will the scorpions to you?%^RESET%^");
    }

    return 0;
}

int query_size()
{
    if (living(ETO)) {
        return ETO->query_size();
    }else {
        return 1;
    }
}
