#include <std.h>

inherit OBJECT;

void dest_effect();

void create()
{
    ::create();
    set_id(({ "table", "food table", "jail cuisine", "cuisine", "jail food" }));
    set_name("jail food");
    set_short("%^RESET%^%^ORANGE%^A simple table covered in food and drink%^RESET%^");
    set_long("%^ORANGE%^This simple two foot square table is clean, at least.  Atop it sit a number of peasant quality foods including a loaf of bread, a wedge of cheese, a hunk of butter, and a dish of pickled onions.  A simple, pewter pitcher of fresh water along with matching tankards sit nearby.  It appears to be magically enchanted to refill itself at certain hours. \n\nType <nourish> to eat from the table.");
    set_weight(100000);
    set("value", 0);
    set_property("no animate", 1);
    set_property("no offer", 1);
}

void nourish_func()
{
    if (!objectp(TP)) {
        return;
    }
    if (sizeof(TP->query_attackers())) {
        tell_object(TP, "You are much too busy to eat right now!");
        return 1;
    }
    if (!(int)TP->add_stuffed(50000) && !(int)TP->add_quenched(50000)) {
        tell_object(TP, "You are already much too full for anymore food or drink.");
        return 1;
    }
    TP->add_stuffed(50000);
    TP->add_quenched(50000);
    TP->set_condition(0);
    tell_object(TP, "You eat and drink your fill of the simple cuisine and feel better.  The bread wasn't that stale, the cheese wasn't too moldy, and the water wasn't too stagnant.");
    return 1;
}

void init()
{
    ::init();
    add_action("nourish_func", "nourish");
    return;
}
