#include <std.h>
inherit "/d/common/obj/armour/shield";

void create()
{
    ::create();
    set_name("shaped stone shield");
    set_id(({ "shield", "medium shield", "sone shield", "shaped shield", "shaped stone shield" }));
    set_short("%^CYAN%^Tecqumin %^ORANGE%^shield of%^RESET%^ stone");
    set_obvious_short("%^RESET%^%^ORANGE%^A %^RESET%^stone %^ORANGE%^shield");
    set_long("This round shield is shaped from stone. It is thick and rugged and looks like"
             + " it should be too heavy to lift, but the powerful enchantments cast upon it make it"
             + " light enough to wield. Staps of leather serve to hold it on the wearer's arm.");
    set_value(22950);
    while ((int)TO->query_property("enchantment") != 7) {
        TO->remove_property("enchantment");
        TO->set_property("enchantment", 7);
    }
    set_item_bonus("damage resistance", 10);
    set_item_bonus("spell damage resistance", 25);
    set_item_bonus("shieldMiss", 30);
    set_wear((: TO, "wear_it" :));
    set_lore("The stone shields of the %^CYAN%^Tecqumin%^RESET%^ were carefully shaped."
             + " Mostly they were thin enough to be liftable, which significantly reduced their"
             + " protective capacity. However, a rare few were given powerful%^MAGENTA%^"
             + " enchantments %^RESET%^that allowed them to be made thick without becoming so"
             + " heavy. These shields offered unbelievable protection. This is one of those.");
}

int wear_it()
{
    if ((int)ETO->query_level() < 41) {
        tell_object(ETO, "You can't seem to settle the shield properly on your arm.");
        return 0;
    }
    if (member_array("Fettered the %^MAGENTA%^U%^BLUE%^nf%^MAGENTA%^e%^BLUE%^tt%^MAGENTA%^e%^BLUE%^red", ETO->query_quests()) == -1 && member_array("Drove %^MAGENTA%^The %^BLUE%^U%^MAGENTA%^nf%^BLUE%^e%^MAGENTA%^tt%^BLUE%^e%^MAGENTA%^r%^BLUE%^e%^MAGENTA%^d %^RESET%^back into the %^BOLD%^%^BLACK%^vo%^RESET%^i%^BOLD%^%^BLACK%^d%^RESET%^!", ETO->query_quests()) == -1 && member_array("%^RED%^Defeated %^RESET%^%^BLUE%^The%^MAGENTA%^ U%^BLUE%^n%^MAGENTA%^f%^BLUE%^e%^MAGENTA%^tt%^BLUE%^e%^MAGENTA%^r%^BLUE%^e%^MAGENTA%^d", ETO->query_quests()) == -1) {
        tell_object(ETO, "%^BOLD%^%^WHITE%^You have not earned the right to use this item!%^RESET%^");
        return 0;
    }
    write("The shield settles comfortably onto your arm");
    tell_room(environment(ETO), "" + ETO->query_cap_name() + " wears the heavy looking stone shield lightly.", ETO);
    return 1;
}
