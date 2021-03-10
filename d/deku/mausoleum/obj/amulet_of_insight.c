#include <std.h>
inherit ARMOUR;

void create()
{

    ::create();
    set_name("small crystal amulet");
    set_id(({ "amulet", "small crystal amulet", "crystal amulet", "amulet of insight",
    "insight amulet"}));

    set_short("%^BOLD%^%^CYAN%^Am%^RESET%^%^CYAN%^u%^BOLD%^l%^RESET%^"+
    "%^CYAN%^e%^BOLD%^t %^RESET%^%^CYAN%^of %^BOLD%^I%^RESET%^%^CYAN%^"+
    "n%^BOLD%^s%^RESET%^%^CYAN%^i%^BOLD%^g%^RESET%^%^CYAN%^h%^BOLD%^t"+
    "%^RESET%^");

    set_obvious_short("%^BOLD%^%^CYAN%^small crystal amulet%^RESET%^");

    set_property("repairtype",({ "jewel" }));

    set_long("%^BOLD%^%^CYAN%^The cord of this amulet is a very thin "+
    "almost invisible thread of mat%^WHITE%^e%^CYAN%^rial. However, it is "+
    "apparently incredibly stout. A small %^RESET%^%^CYAN%^blue crystal%^BOLD%^ "+
    "hangs from the thread, it gl%^WHITE%^i%^CYAN%^mm%^WHITE%^e%^CYAN%^rs "+
    "faintly and gives off a slight, almost %^WHITE%^inperceptible%^CYAN%^ "+
    "warmth. The crystal jagged and oddly shaped, with multiple edges which "+
    "have all been rounded off in order to make the crystal less likely to "+
    "cut into the wearer.%^RESET%^");

    set_lore("%^BOLD%^%^CYAN%^This amulet is known as an amulet of "+
    "insight. There were hundreds of them created, though the original "+
    "creator has always been unknown. Some suggest that maybe it was created "+
    "by Aorus Devar, others think that maybe he was given them by some unknown "+
    "other entity in order to secure some type of alliance. The history of them "+
    "is very unclear. What is known is that they have the ability to connect "+
    "with whoever possesses them, gaining a powerful insight. The crystal "+
    "attunes to this insight and powers itself in such a way to benefit "+
    "the possessor.%^RESET%^");

	set_weight(2);
	set_value(1000);
	set_type("clothing");
	set_limbs(({ "neck" }));
	set_size(-1);
	set_property("enchantment",3);
    set_wear((:TO,"wearme":));
    set_remove((:TO,"removeme":));

}

void init()
{
    ::init();
    if (interactive(ETO)) {
        if (TO->add_item_owner(ETOQN)) {
            tell_object(ETO, "%^BOLD%^%^WHITE%^You feel the amulet " +
                        "attuning itself to you!%^RESET%^");
            switch ((string)ETO->query_class()) {
            case "fighter": case "barbarian":
                set_item_bonus("strength", 2);
                set_item_bonus("damage resistance", 2);
                break;
            case "monk": case "cleric": case "druid": case "inquisitor":
                set_item_bonus("wisdom", 2);
                set_item_bonus("spell damage resistance", 10);
                break;
            case "thief": case "ranger":
                set_item_bonus("dexterity", 2);
                set_item_bonus("stealth", 2);
                break;
            case "paladin": case "cavalier": case "warlock": case "sorcerer":case "oracle":
                set_item_bonus("charisma", 2);
                set_item_bonus("influence", 2);
                break;
            default:
                set_item_bonus("intelligence", 2);
                set_item_bonus("spellcraft", 2);
                break;
            }
        }
    }
}

int wearme()
{
    if(ETO->query_highest_level() < 20) {
        tell_object(ETO,"%^BOLD%^%^BLACK%^You are not powerful "+
        "enough to wear the amulet!%^RESET%^");
        return 0;
    }
    if(!TO->query_owns_item(ETOQN) && ETO->is_player())
    {
        tell_object(ETO,"%^BOLD%^%^WHITE%^The amulet "+
        "is attuned to another!%^RESET%^");
        return 0;
    }
    tell_object(ETO,"%^BLUE%^You feel a power seep out from "+
    "the amulet and augment your own!%^RESET%^");
    return 1;
}

int removeme()
{
    tell_object(ETO,"%^BLUE%^You feel the power augmented power "+
    "fade away... leaving you somewhat disconcerted!%^RESET%^");
    return 1;
}
