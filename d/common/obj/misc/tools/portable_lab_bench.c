#include <std.h>
inherit OBJECT;

void create()
{
    ::create();
    set_name("portable lab bench");
    set_id(({ "lab", "lab bench", "portable lab", "alchemy lab", "bench", "enchanting lab", "labx" }));
    set_short("%^RESET%^%^ORANGE%^A portable lab bench%^RESET%^");
    set_long("%^RESET%^%^ORANGE%^This sturdy wooden workbench measures seventy-two inches long by thirty inches deep, and appears to have an adjustable height.  Atop it sit all manner of vials, flasks, burners and such necessary for alchemical work along with various materials and tools necessary for enchanting. You can %^BOLD%^%^WHITE%^<packup> %^RESET%^%^ORANGE%^the lab up when you're done with it.%^RESET%^");
    set_weight(100000);
    set("value", 0);
    set_property("no animate", 1);
    set_property("no offer", 1);
}

void packup_func()
{
    if (!objectp(TP)) {
        return;
    }
    if (sizeof(TP->query_attackers())) {
        tell_object(TP, "You are much too busy to collapse the lab right now!");
        return 1;
    }
    tell_object(TP, "%^RESET%^%^ORANGE%^You press a button on the side of the lab bench and it begins to magically pack itself away. In a matter of moments it has returned itself to its wooden case.%^RESET%^");
    tell_room(ETO, "%^RESET%^%^ORANGE%^" + TP->QCN + " presses a button on the side of the lab bench and it begins to magically pack itself away. In a matter of moments it has returned itself to its wooden case.%^RESET%^", TP);
    new("/d/common/obj/misc/tools/portable_lab_case")->move(ETO);
    TO->remove();
    return 1;
}

void init()
{
    ::init();
    add_action("packup_func", "packup");
    return;
}
