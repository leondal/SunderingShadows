#include <std.h>
inherit "/d/common/obj/misc/sack.c";

void create()
{
    ::create();
    set_id(({ "bag", "sack", "bag of holding" }));
    set_name("bag");
    set_short("%^BLUE%^Bag of permanent holding%^RESET%^");
    set_obvious_short("%^BLUE%^%^BOLD%^A blue bag decorated with %^YELLOW%^r%^WHITE%^u%^YELLOW%^nes%^RESET%^");
    set_weight(5);

    set_long("%^WHITE%^%^BOLD%^This is a small bag that you can put things in, made of some unknown, but quite "
             "resiliant, %^BLUE%^cobalt-blue cloth%^WHITE%^.  Around the opening of the bag appear %^YELLOW%^orn%^WHITE%^a"
             "%^YELLOW%^te ru%^WHITE%^n%^YELLOW%^es%^WHITE%^ within the cloth, perhaps dyed there.  As you reach you notice "
             "there is a lot more space in here than a normal bag of this size.%^RESET%^");

    set_lore("%^WHITE%^%^BOLD%^The great archmage Arkhiesan Korr is claimed to have been the first to have "
             "found the means by which to make a bag of holding permanent.  Part of the original Brotherhood of the Sixteen "
             "Sigils, he continued his research in secret after their group was disbanded.  His completed research, "
             "however, was never found or disclosed, as very shortly after the discovery, he was reputed to have been eaten "
             "by a great red wyrm.%^RESET%^");

    set_property("lore difficulty", 14);
    set_value(100000);
    set_property("no animate", 1);
    set_max_internal_encumbrance(100);
}

int isMagic()
{
    return 1;
}
