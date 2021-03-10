#include <std.h>
inherit OBJECT;

void create()
{
    ::create();
    set_name("portable smithy");
    set_id(({ "smithy", "portable smithy", "anvil", "forge", "bench", "smithyx" }));
    set_short("%^BOLD%^%^BLACK%^A portable smithy%^RESET%^");
    set_long("%^BOLD%^%^BLACK%^This portable smithy consists of a metal anvil, a simple coal forge with a manual bellows, a tank filled with oil for quenching weapons and armor, and all the necessary hand tools for shaping metal including tongs, hammers, and heavy gloves. You can %^BOLD%^%^WHITE%^<breakdown> %^BOLD%^%^BLACK%^the smithy when you're done with it.%^RESET%^");
    set_weight(1500000);
    set("value", 0);
    set_property("no animate", 1);
    set_property("no offer", 1);
}

void breakdown_func()
{
    if (!objectp(TP)) {
        return;
    }
    if (sizeof(TP->query_attackers())) {
        tell_object(TP, "You are much too busy to breakdown the smithy right now!");
        return 1;
    }
    tell_object(TP, "%^BOLD%^%^BLACK%^You press a button along the base of the anvil and the smithy begins to magically pack itself away. In a matter of moments it has returned itself to its canvas bag.%^RESET%^");
    tell_room(ETO, "%^BOLD%^%^BLACK%^" + TP->QCN + " presses a button along the base of the anvil and the smithy begins to magically pack itself away. In a matter of moments it has returned itself to its canvas bag.%^RESET%^", TP);
    new("/d/common/obj/misc/tools/portable_smithy_bag")->move(ETO);
    TO->remove();
    return 1;
}

void init()
{
    ::init();
    add_action("breakdown_func", "breakdown");
    return;
}
