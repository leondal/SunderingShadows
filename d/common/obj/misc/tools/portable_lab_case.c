#include <std.h>
inherit OBJECT;

void create()
{
    ::create();
    set_name("Portable Lab Case");
    set_id(({ "case", "wooden case", "alchemy case", "lab case", "portable lab case" }));
    set_short("%^RESET%^%^ORANGE%^A sturdy wooden case%^RESET%^");
    set_long("%^RESET%^%^ORANGE%^This sturdy wooden case measures twenty four inches long by twelve inches wide by another twelve inches tall.  The interior is absolutely crammed with various enchanting materials, vials, beakers and other alchemical equipment one would need to equip a fully funcioning alchemy or enchanting lab. Oddly enough, the interior of this case appears far more voluminous than you would have otherwise suspected. Looks like you me able to %^BOLD%^%^WHITE%^<unpack> %^RESET%^%^ORANGE%^the lab somewhere.%^RESET%^");
    set_weight(20);
    set_value(2000000);
}

void unpack_func()
{
    if (!objectp(TP)) {
        return;
    }
    if (sizeof(TP->query_attackers())) {
        tell_object(TP, "You are much too busy to unpack the lab right now!");
        return 1;
    }
    if (!ETO->is_room()) {
        tell_object(TP, "You need to set the case down before you begin unpacking it.");
        return 1;
    }
    tell_object(TP, "%^RESET%^%^ORANGE%^As you press a button on the handle of the wooden case, it opens and begins unpacking itself.  In a matter of moments it has set up a fully functioning laboratory bench that might be used for alchemy or enchanting.%^RESET%^");
    tell_room(ETO, "%^RESET%^%^ORANGE%^As " + TP->QCN + " presses a button on the handle of the wooden case, it opens and begins unpacking itself.  In a matter of moments it has set up a fully functioning laboratory bench that might be used for alchemy or enchanting.%^RESET%^", TP);
    new("/d/common/obj/misc/tools/portable_lab_bench")->move(ETO);
    TO->remove();
    return 1;
}

void init()
{
    ::init();
    add_action("unpack_func", "unpack");
    return;
}
