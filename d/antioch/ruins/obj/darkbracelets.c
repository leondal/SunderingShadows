// str bonus changed to work on new stat system. Nienne, 09/07. Also changed cap to 21, equivalent +3 item. And added lore.
//Changed to lvl 15 cap due to enchantment level change Octothorpe 5/11/09
#include <std.h>
#include "/d/antioch/ruins/ruins.h"
inherit "/std/armour";

void create() {
    ::create();
    set_name("Shadow Bracelets");
    set_short("%^BOLD%^%^BLACK%^Shadow bracelets%^RESET%^");
    set_obvious_short("%^BOLD%^%^BLACK%^Dark black bracelets%^RESET%^");
    set_id(({"bracelets","bracelets of power","Bracelets of Power","shadow bracelets","dark bracelets"}));
    set_property("repairtype",({ "jewel" }));
    set_long("%^BOLD%^%^BLACK%^These twin bracelets are matching cuffs of pure darkness.  "
        "Power seems to shift through the shadows that compose them.  One can only imagine "
        "where such a thing would come from.%^RESET%^");
    set_lore("Originally known as Bracelets of Power, these items are a twisted reflection of "
        "their original form.  Jealous of the success of the Mystrans in creating such an item, "
        "the darker forces of Shar's fold managed to secure a copy of the original bracelets.  "
        "However, being unable to retrieve his notes on their creation, many decades of study "
        "still failed to yield a copy warped enough to serve their own ends. No proof was ever "
        "found that they actually did manage this, even after so long, but with the recent "
        "appearance of items such as this, it leads one to wonder if it truly was they that "
        "finally succeeded.");
    set_property("lore",14);
    set_weight(5);
    set_value(2000);
    set_ac(0);
    set_property("enchantment",3);
    set_item_bonus("strength",1);
    set_type("clothing");
    set_size(-1);
    set_limbs(({"left arm","right arm"}));
    set_wear((:TO,"wearme":));
    set_remove((:TO,"removeme":));
}

int wearme() {
    if(ETO->query_highest_level() < 15) {
        tell_object(ETO,"You are not experienced enough to use this equipment.");
        return 0;
    }
    if(ETO->query_property("good item")) {
       tell_object(ETO,"The bracelets refuse to be worn while you're using such holy items.");
       return 0;
    }
    tell_object(ETO,"You feel the bracelets strengthen your arms as you slip them over your wrists.");
    ETO->set_property("evil item",1);
    return 1;
}

int removeme() {
    tell_object(ETO,"You feel weak once more as you remove the bracelets.");
    ETO->set_property("evil item",-1);
    return 1;
}