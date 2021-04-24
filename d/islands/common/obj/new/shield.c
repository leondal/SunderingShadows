// it was totally broke, yanked 2 properties and now it's working again.
// Since they were kinda overkill anyway, leaving them off.
// Think the shieldMiss shouldn't be set as item_bonus. N, 4/15
#include <std.h>

inherit "/d/common/obj/armour/shield";


void create()
{
    ::create();
    set_name("Therdall's shield");

    set_id(({ "shield", "medium shield", "shield of the king", "shield of therdall skycast", "therdall's shield" }));

    set_short("%^RESET%^%^CYAN%^The %^BOLD%^shield %^RESET%^%^CYAN%^of %^BOLD%^Therdall S%^WHITE%^k%^CYAN%^y%^WHITE%^c%^CYAN%^a%^WHITE%^s%^CYAN%^t%^RESET%^");

    set_obvious_short("%^RESET%^%^CYAN%^An oval %^BOLD%^sky blue s%^WHITE%^h%^CYAN%^ie%^WHITE%^l%^CYAN%^d %^RESET%^%^CYAN%^with a %^BOLD%^%^RED%^rampant"
                      " %^RESET%^%^ORANGE%^li%^BOLD%^o%^RESET%^%^ORANGE%^n%^RESET%^");

    set_long("%^RESET%^%^CYAN%^This %^BOLD%^s%^WHITE%^h%^CYAN%^ie%^WHITE%^l%^CYAN%^d %^RESET%^%^CYAN%^seems to"
             " %^YELLOW%^r%^WHITE%^a%^ORANGE%^d%^WHITE%^i%^ORANGE%^a%^WHITE%^t%^ORANGE%^e %^RESET%^%^CYAN%^an"
             " %^BOLD%^au%^MAGENTA%^r%^CYAN%^a %^RESET%^%^CYAN%^of %^BOLD%^power %^RESET%^%^CYAN%^that is almost tangible."
             " The %^BOLD%^%^WHITE%^a%^RESET%^d%^BOLD%^ama%^RESET%^n%^BOLD%^ti%^RESET%^u%^BOLD%^m %^CYAN%^s%^WHITE%^h%^CYAN%^ie%^WH"
             "ITE%^l%^CYAN%^d %^RESET%^%^CYAN%^has a beautiful design etched into its surface of a %^MAGENTA%^r%^BOLD%^e%^RESET%^%^"
             "MAGENTA%^g%^BOLD%^a%^RESET%^%^MAGENTA%^l %^ORANGE%^li%^BOLD%^o%^RESET%^%^ORANGE%^n%^CYAN%^, %^BOLD%^%^RED%^rampant"
             " %^RESET%^%^CYAN%^in roaring pose, covering the face of the %^BOLD%^s%^WHITE%^h%^CYAN%^ie%^WHITE%^l%^CYAN%^d %^RESET%^%^C"
             "YAN%^on a background of %^BOLD%^sky blue%^RESET%^%^CYAN%^. The %^BOLD%^s%^WHITE%^h%^CYAN%^ie%^WHITE%^l%^CYAN%^d %^RESET%^%^CYAN%^is"
             " worn by the wearer with nothing more than a %^ORANGE%^leather strap%^CYAN%^, but that %^ORANGE%^strap %^CYAN%^seems to hold the %^BOLD"
             "%^s%^WHITE%^h%^CYAN%^ie%^WHITE%^l%^CYAN%^d %^RESET%^%^CYAN%^to the wearer's arm securely. Nothing else about this oval %^BOLD%^s%^WHITE"
             "%^h%^CYAN%^ie%^WHITE%^l%^CYAN%^d %^RESET%^%^CYAN%^can be detected by casual observation.%^RESET%^");


    set_lore("This magnificent shield was crafted by dwarven smiths as only master smiths of that race are known to make."
             " The shield was made for a knight named Therdall Skycast and was carried into countless battles in defense of"
             " the Akadi faith. When wearing the shield legends say Therdall became all but invincable, able to sustain b"
             "lows that would cripple the average fighter and continue fighting unfazed. It is said Therdall fell in battle"
             " defending the temple from attack by a mass of Talassan zealots. His solo defense of the temple is still spoken"
             " of by the devout in awe. The shield was never found when his body was laid to rest with honors.");

    set_value(229500);

    set_property("no curse",1);
    set_property("enchantment",7);

    set_item_bonus("spell damage resistance",25);
    set_item_bonus("constitution",6);

    set_wear((:TO,"wear_it":));
    set_remove((:TO,"remove_it":));
    set_struck((:TO,"struck":));

    set_property("quest required","%^BOLD%^%^RED%^Defeated the great red wyrm Klauth!%^RESET%^");
    set_property("level required",35);
}

int wear_it()
{
    tell_object(ETO, "%^BOLD%^%^WHITE%^You feel the power of the shield flowing into your body.%^RESET%^");
    tell_room(EETO, "%^BOLD%^%^WHITE%^" + ETO->QCN + " seems much more confident with the shield.%^RESET%^", ETO);
    return 1;
}

int remove_it()
{
    write("%^BOLD%^%^CYAN%^You feel the raw energy of the shield seeping from your skin.%^RESET%^");
    return 1;
}

int struck(int damage, object what, object who)
{
    if(!random(2))
    {
        tell_room(EETO, "%^BOLD%^%^CYAN%^The lion on " + ETO->QCN + "'s shield suddenly releases a roar that appears to repel blows!%^RESET%^", ({ who, ETO }));
        tell_object(who, "%^BOLD%^%^CYAN%^As you try to hit " + ETO->QCN + ", the shield roars at you, repelling your blow!%^RESET%^");
        tell_object(ETO, "%^BOLD%^%^CYAN%^The shield roars and pushes the oncoming blow backward!%^RESET%^");
        return 0;
    }
    return damage;
}
