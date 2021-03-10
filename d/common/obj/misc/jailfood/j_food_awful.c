#include <std.h>

inherit OBJECT;

void dest_effect();

void create()
{
    ::create();
    set_id(({ "platter", "food platter", "jail cuisine", "cuisine", "jail food" }));
    set_name("jail food");
    set_short("%^RESET%^%^ORANGE%^A wooden platter with bread and water%^RESET%^");
    set_long("%^ORANGE%^This square wooden platter looks like some pig recently defecated in it, then urinated on it, then defecated in it again.  Among the muck sits a maggoty, moldy chunk of what looks like bread and a wooden cup of nasty, slimy water.  It appears to be magically enchanted to refill itself at certain hours, but it certainly doesn't clean itself. \n\nType <nourish> to eat from the table.");
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
    tell_object(TP, "After deciding the huger pains in your stomach and the dry feeling in your mouth are too much to bear, you resolutely approach the platter.  You take some time to pick away most of the maggots from the bread, hold your nose, and eat it.  It begins to upset your stomach almost immediately, so you chase it down with the cup of slimy water.  That doesn't sit well either, and you gag for a few seconds before managing to keep it all down.  You're not entirely certain death by starvation wouldn't be better.");
    return 1;
}

void init()
{
    ::init();
    add_action("nourish_func", "nourish");
    return;
}
