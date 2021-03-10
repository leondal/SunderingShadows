#include <std.h>
inherit "/d/common/obj/armour/fullplate";

void create()
{
    ::create();
    set_name("white dragon plate");
    set_id(({ "white dragon plate", "plate", "dragon plate", "+
		" "armor", "armour" }));
    set_short("%^BOLD%^%^WHITE%^Wh%^CYAN%^i%^WHITE%^t%^CYAN%^e %^WHITE%^D%^CYAN%^r%^WHITE%^ag%^CYAN%^o%^WHITE%^n P%^CYAN%^l%^WHITE%^a%^CYAN%^t%^WHITE%^e%^RESET%^");
    set_obvious_short("%^BOLD%^%^WHITE%^Fr%^CYAN%^o%^WHITE%^%^sted P%^CYAN%^l%^WHITE%^a%^CYAN%^t%^WHITE%^e%^RESET%^");
    set_long("%^BOLD%^%^WHITE%^Crafted from the hide and " +
             "scales of a White Dragon, this plate has an " +
             "impressive look to it.  The breastplate of this" +
             " armor is created by attaching overlapping scales" +
             " over a steel shell.  Underneath the breastplate," +
             " a suit of molded white dragon leather lays.  This" +
             " leather suit offers additional protection to the " +
             "wearer as well as some comfort from the metal, and" +
             " to cushion blows.  The impressive breastplate has" +
             " one large single %^BOLD%^%^CYAN%^i%^BLUE%^c%^CYAN%^y" +
             " blue%^WHITE%^ eye of a dragon magically attached to " +
             "the left breast.  This unblinking dragon's eyes has " +
             "been perfectly preserved, never to rot or spoil. A " +
             "skirt of pleated scaled dragon hide falls from " +
             "underneath the breastplate, offering protection to " +
             "the legs of the wearer.  The skirt is split open in " +
             "the front, for ease in riding.  A second section of " +
             "scaled white dragon hide lays under the split of the " +
             "skirt, serving as a protective shield for vital areas." +
             "  A layer of %^CYAN%^frost%^WHITE%^ cakes the armor, " +
             "giving it a chilling apperance.%^RESET%^\n");
    set_value(13500);
    set_property("enchantment", 4);
    set_item_bonus("cold resistance", 50);
    set_property("no curse", 1);
    set_lore("%^BOLD%^%^WHITE%^The White Dragon Plate was fashioned from Wynter," +
             " the eldest son of Muln.  Wynter was slain by a " +
             "traveling dragonslayer, who some claim has ties to"
             " Azha.  The dragonslayer took his prize from Wynter" +
             " and had this armor fashioned out the dragon's scales" +
             ". %^BOLD%^%^BLUE%^- A Cold Wynter's Tale - Freesia Greenmore");
    set_property("lore difficulty", 25);
    set_size(-1);
}

void init()
{
    ::init();
    set_wear((: TO, "wearit" :));
    set_remove((: TO, "remove_func" :));
}

int wearit()
{
    if ((int)ETO->query_highest_level() < 20) {
        notify_fail("%^BLUE%^%^BOLD%^The plate mail armor " +
                    "rejects someone as weak as you!");
        set_property("magic", 1);
        ETO->cause_typed_damage(ETO, "torso", roll_dice(1, 5) + 19, "cold");
        ETO->add_attacker(TO);
        ETO->continue_attack();
        ETO->remove_attacker(TO);
        remove_property("magic");
        return 0;
    }       else {
        tell_object(ETO, "%^BOLD%^You strap yourself into the platemail armor.");
        tell_room(environment(ETO), "%^BOLD%^" + ETO->QCN + "" +
                  " straps on the White Dragon Plate.", ETO);
        return 1;
    }
}

int remove_func()
{
    tell_object(ETO, "%^BOLD%^You remove the armor.");
    tell_room(environment(ETO), "%^BOLD%^" + ETO->QCN + "" +
              " removes the armor.", ETO);
    return 1;
}
