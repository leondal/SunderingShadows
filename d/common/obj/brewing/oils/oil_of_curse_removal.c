#include <std.h>
inherit "d/common/obj/brewing/oils/weapon_oil_inherit.c";
int reversed;

void create()
{
    ::create();
    set_name("oil of curse removal");
    set_id(({ "bottle", "oil", "oil of curse removal", "gleaming oil" }));
    set_obvious_short("%^RESET%^%^ORANGE%^%^A small bottle of gl%^YELLOW%^e%^RESET%^%^ORANGE%^am%^YELLOW%^i%^RESET%^%^ORANGE%^ng oil%^RESET%^");
    set_short("%^RESET%^%^ORANGE%^O%^YELLOW%^i%^RESET%^%^ORANGE%^l %^YELLOW%^o%^RESET%^%^ORANGE%^f %^YELLOW%^C%^RESET%^%^ORANGE%^u%^YELLOW%^rs"
              "%^RESET%^%^ORANGE%^e R%^YELLOW%^e%^RESET%^%^ORANGE%^mo%^YELLOW%^v%^RESET%^%^ORANGE%^a%^YELLOW%^l%^RESET%^");
    set_long("%^RESET%^%^BOLD%^This small glass bottle sits easily in your hand, cylindrical and narrowing towards the neck, where it has been "
             "sealed with a thick %^RESET%^%^ORANGE%^cork%^BOLD%^%^WHITE%^. Inside lies a solution of gleaming %^YELLOW%^amber %^BOLD%^%^WHITE%^liquid, "
             "clinging to the transparent walls of the jar and leaving a thin %^RESET%^sheen %^BOLD%^%^WHITE%^where it rolls away.%^RESET%^");
    set_lore("%^CYAN%^Such a substance can be traced to the church of Kismet, who are so often sought out by hapless travellers and adventurers "
             "who had found themselves carelessly stuck to 'undesirable' items. The elven abjurist Alessauran Windspur led a team of the most accomplished "
             "priests and arcanists, to devise among them a substance that, when applied to a cursed item, would harmlessly unravel the corrupted lines of "
             "the weave within it. Not a faith to keep such potent magic from wide use, they offered the results that it might be "
             "shared among the masses, and it is now not particularly rare, though it can be often expensive for the obscure materials required to brew it.");
    set_weight(10);
    set_value(5000);
    reversed = 0;
}

int apply(string str)
{
    object target;
    int theenchant;

    if (!objectp(TO) || !objectp(ETO)) {
        return 0;
    }
    if (!objectp(target = ::apply(str, 0))) {
        return 1;
    }

    tell_object(ETO, "%^ORANGE%^You uncork the bottle, carefully pouring the gleaming "
                "liquid over the " + target->query_short() + "%^RESET%^%^ORANGE%^.%^RESET%^");
    tell_room(EETO, "%^ORANGE%^" + ETO->QCN + " uncorks a bottle, and carefully pours its "
              "gleaming liquid contents over " + ETO->QP + " " + target->query_short() + "%^RESET%^%^ORANGE%^.%^RESET%^", ETO);

    theenchant = (int)target->query_property("enchantment");
    if (reversed || !theenchant || theenchant > 0) {
        tell_object(ETO, "%^ORANGE%^The bright oil dulls to %^BOLD%^%^BLACK%^black %^RESET%^"
                    "%^ORANGE%^on contact with the air, and then drips away uselessly to the ground.%^RESET%^");
    }else {
        tell_object(ETO, "%^YELLOW%^Threads of light ripple across the surface of the oil "
                    "as it makes contact with the " + target->query_short() + " and soaks into it.%^RESET%^");
        target->remove_property("enchantment");
    }
    TO->remove();
    return 1;
}

void set_reversed(int mystatus)
{
    reversed = mystatus;
}
