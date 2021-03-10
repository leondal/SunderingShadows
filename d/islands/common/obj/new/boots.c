#include <std.h>

inherit "/d/common/obj/clothing/shoes.c";

void create()
{
    ::create();
    
    set_name("boots");
    
    set_id(({"boots","red boots","way of the warrior"}));
    
    set_obvious_short("%^RESET%^%^RED%^dark red boots%^RESET%^");
    
    set_short("%^BOLD%^%^RED%^W%^RESET%^%^RED%^ay of the %^BOLD%^%^RED%^W%^RESET%^%^RED%^arrior%^RESET%^");
    
    set_long("%^RESET%^%^RED%^These dark red boots are crafted of fine old leather that does barely shows its age.  "
        "The insides are lined with the soft red furs of a mazique. There are no writings or runes along the "
        "boots anywhere, but there are several markings from years of use.");
    
    set_lore("These boots are rumored to have been seen on the feet of many warriors that have come to pass.  "
        "Some of the names are of great heroes and some notorius villians. Most names have faded to time, but "
        "some are still recent such as Beowulf, Daaku, Zeal, Sunder, Kaarell, and the list goes on. However, "
        "rumors will be rumors and it is quite certain that they were all just wearing a pair of similar boots, "
        "but when rumors spread myths arise and it is said that these boots had something to do with why they "
        "were so great. Even though it can not be proved the boots were even magical when they wore them, if they ever wore them.");

    set_property("no curse",1);
    set_property("enchantment",7);
    set_weight(2);

    set_item_bonus("strength",6);
    set_item_bonus("damage resistance",10);
    
    set_value(125000);
    
    set_size(-1);
    
    set_wear((:TO,"wear_func":));
    set_remove((:TO,"remove_func":));
   
    set_property("quest required","%^BOLD%^%^RED%^Defeated the great red wyrm Klauth!%^RESET%^");
    set_property("level required",35);
}


int wear_func()
{
    write("%^RESET%^%^RED%^You slide your feet into the boots and feel a sense of pride wash over you.%^RESET%^");
    return 1;
}


int remove_func()
{
    write("%^RESET%^%^RED%^You feel like you are missing something once you remove the boots.%^RESET%^");
    return 1;
}
