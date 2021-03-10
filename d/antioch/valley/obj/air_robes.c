//Added Lore - Cythera 4/05
#include <std.h>
#include "../valley.h"
inherit "/std/armour";

void create()
{
    ::create();
    set_name("%^BOLD%^%^CYAN%^Shift of Air%^RESET%^");
    set_id(({ "shift", "robe", "shift of air", "sylph shift", "+
		" "dress", "sylph dress", "air dress", "blue dress", "+
		" "robes", "air robe", "air robes" }));
    set_short("%^BOLD%^%^CYAN%^Shift of Air%^RESET%^");
    set_long(
        "%^BOLD%^%^WHITE%^The shift is made of a %^CYAN%^pale blue" +
        " %^WHITE%^silken fabric that is very" +
        " see-through. It is more of a negligee than anything else" +
        " and wouldn't be worn out in public by any proper lady. A" +
        " small sleeve crosses over the left shoulder and the rest" +
        " of the shift flows down, though not very far at all. This" +
        " shift doesn't look like it could protect you from anything," +
        " not even a slight breeze.%^RESET%^"
        );
    set_size(2);
    set_value(100);
    set_weight(3);
//       set_ac(-5);
    set_limbs(({ "torso" }));
    set_type("clothing");
    set_property("enchantment", 2 + random(2));
    set_wear((: TO, "wearme" :));
    set_lore("Crafted from ethereal silk, the Shift of Air is " +
             "a favorite garment for the sylphs.  The fey creatures" +
             " of the air lack a sense of modesty that other people " +
             "have, which would explain this racy garment.  The pale" +
             " blue silk allows the sylph to blend in with the sky as" +
             " they fly, and feel the wind across their skin.  Such a" +
             " garment though should be reserved for fey creatures, as " +
             "any woman wearing this in public would earn a bad reputation.");
    set_property("lore", 7);
}

void init()
{
    ::init();
    add_action("twirl", "twirl");
}

int wearme()
{
    tell_object(ETO, "You feel naughty as you slip on the" +
                " %^BOLD%^%^CYAN%^Shift of Air.  The urge to twirl overcomes you.");
    tell_room(environment(ETO), "" + ETO->query_cap_name() + "" +
              " slips into the %^BOLD%^%^CYAN%^Shift of Air.", ETO);
    return 1;
}

int twirl(string str)
{
    if (ETO->query_bound() || ETO->query_unconcious() || ETO->query_paralyzed() || ETO->query_tripped()) {
        TP->send_paralyzed_message("info", TP);
        return 1;
    }
    if (query_worn() && (string)ETO->query_gender() == "female") {
        tell_object(ETO, "%^BOLD%^%^CYAN%^You twirl and your" +
                    " shift swirls around you beautifully.");
        tell_room(environment(ETO), "%^BOLD%^%^CYAN%^" + ETO->query_cap_name() + "" +
                  " twirls around and " + ETO->query_possessive() + " shift swirls" +
                  " around " + ETO->query_objective() + " enchantingly.", ETO);
        return 1;
    }
}
