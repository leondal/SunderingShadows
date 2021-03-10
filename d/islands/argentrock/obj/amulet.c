#include <std.h>
inherit "/d/common/obj/jewelry/necklace";

void create()
{
    ::create();
    set_name("bloodstone amulet");
    set_id(({ "amulet", "bloodstone amulet", "amulet of the abyss" }));
    set_short("%^RESET%^%^RED%^am%^BOLD%^u%^RESET%^%^RED%^let of the a%^BOLD%^b%^RESET%^%^RED%^yss%^RESET%^");
    set_obvious_short("%^RESET%^%^RED%^blo%^BOLD%^o%^RESET%^%^RED%^dstone a%^BOLD%^m%^RESET%^%^RED%^ulet%^RESET%^");
    set_lore("The new rulers of argentrock, the fey'ri give these" +
             " amulets to fighters that have proven themselves by deed as" +
             " well as word.  The dracophoenix is the symbol of a clan" +
             " of fey'ri.  The fires of hell are used to create these" +
             " amulets.  Woe to those that encounter someone gifted with such a thing. ");
    set_property("lore difficulty", 30);
    set_long("%^RED%^This is an amulet on a %^RESET%^silver chain." +
             "%^RED%^  The amulet is a %^BOLD%^bloodstone%^RESET%^%^RED%^ that has been carved into " +
             "the shape of a %^BOLD%^dracophoenix%^RESET%^%^RED%^.  It has several rubies for" +
             " eyes and seems to pulsate with a hellish magic.%^RESET%^");

    set_size(-1);
    set_value(5000);
    set_wear((: TO, "wear_me" :));
    set_property("enchantment", 4 + random(2));
    set_item_bonus("fire resistance", 40);
    set_item_bonus("divine resistance", -20); //this was light resistance, which does nothing, changing it to divine and upping it - Odin 3/27/2020
    set_item_bonus("negative energy resistance", 40);
    set_item_bonus("positive energy resistance", 20); //negative poisitive energy resistance is actually, as it makes you easier to heal, going to change to positive so it eats the first 20 points of a heal you take - Odin 3/27/2020
}

int wear_me()
{
    tell_object(ETO, "%^RED%^You secure the amulet around your neck and feel the evil power fill you");
    ETO->set_property("evil item", 1);
    return 1;
}
