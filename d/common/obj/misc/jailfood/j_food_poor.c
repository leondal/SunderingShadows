#include <std.h>

inherit OBJECT;

void dest_effect();

void create()
{
    ::create();
    set_id(({ "table", "food table", "jail cuisine", "cuisine", "jail food" }));
    set_name("jail food");
    set_short("%^RESET%^%^ORANGE%^A simple table covered in food and drink%^RESET%^");
    set_long("%^ORANGE%^This simple two foot square table has definately seen better days.  Atop it sits an obviously stale loaf of bread and a simple, clay pitcher of stagnant water.  It appears to be magically enchanted to refill itself at certain hours. \n\nType <nourish> to eat from the table.");
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
    tell_object(TP, "You eat and drink your fill of the bread and water and feel better.  The bread was stale enough that it crunched in your teeth, and the water had a slight slimy taste to it.  You take a small comfort in knowing that at least you won't starve to death in here.");
    return 1;
}

void init()
{
    ::init();
    add_action("nourish_func", "nourish");
    return;
}
