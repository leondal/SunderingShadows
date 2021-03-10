#include <std.h>
inherit OBJECT;

void create()
{
    ::create();
    set_name("Portable Smithy Bag");
    set_id(({ "bag", "duffle bag", "smithy bag", "portable smithy bag", "canvas bag" }));
    set_short("%^BOLD%^%^BLACK%^A sturdy canvas bag%^RESET%^");
    set_long("%^BOLD%^%^BLACK%^This sturdy canvas duffle bag measures twenty four inches in diameter by another thirty-six inches tall.  The interior is absolutely crammed with various blacksmithing materials including an anvil, a forge with manual bellows, a small sack of coal, and various blacksmithing hammers and tongs; its obvious these materials comprise what anyone would need to equip a fully funcioning smithy. Oddly enough, the interior of this bag appears far more voluminous than you would have otherwise suspected. Looks like you me able to %^BOLD%^%^WHITE%^<setup> %^BOLD%^%^BLACK%^the smithy somewhere.%^RESET%^");
    set_weight(20);
}

void setup_func()
{
    if (!objectp(TP)) {
        return;
    }
    if (sizeof(TP->query_attackers())) {
        tell_object(TP, "You are much too busy to setup the smithy right now!");
        return 1;
    }
    if (!ETO->is_room()) {
        tell_object(TP, "You need to set the bag down before you begin setting it up.");
        return 1;
    }
    tell_object(TP, "%^BOLD%^%^BLACK%^As you pull a cord on the strap of the canvas bag, it opens and begins unpacking itself.  In a matter of moments it has set up a fully functioning smithy that might be used for making weapons, armor, or other metal objects.%^RESET%^");
    tell_room(ETO, "%^BOLD%^%^%^BLACK%^As " + TP->QCN + " pulls a cord on the strap of the canvas bag, it opens and begins unpacking itself.  In a matter of moments it has set up a fully functioning smithy that might be used for making weapons, armor, or other metal objects.%^RESET%^", TP);
    new("/d/common/obj/misc/tools/portable_smithy_bench")->move(ETO);
    TO->remove();
    return 1;
}

void init()
{
    ::init();
    add_action("setup_func", "setup");
    return;
}
