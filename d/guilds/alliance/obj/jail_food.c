#include <std.h>

inherit OBJECT;

void dest_effect();

object caster, casting_spell;
int duration, FLAG;

void create()
{
    ::create();
    set_id(({ "table", "banquet table", "banquet", "feast", "heroes feast" }));
    set_name("Jail Cuisine");
    set_short("%^RESET%^%^ORANGE%^A simple table covered in food and drink%^RESET%^");
    set_long("%^ORANGE%^This simple four foot square table is adorned by a simple, muslin tablecloth.  Atop it sit various hearty dishes including fish and potatoes, chicken and rice soup, beef and vegetable stew, a loaf of fresh bread, a large wedge of cheddar cheese, fresh greens, roasted ears of corn, and a hunk of butter.  A simple, pewter pitcher of fresh water along with matching tankards sit nearby, along with a decent bottle of wine.  As you give a second look at the table before you, more of the same dishes materialize. \n\nType <feast> to eat from the table.");
    set_weight(100000);
    set("value", 0);
    set_property("no animate", 1);
    set_property("no offer", 1);
}

void feast_func()
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
    tell_object(TP, "You eat and drink your fill of the simple, yet filling cuisine and feel "
                "refreshed and revitalized.");
    return 1;
}

void init()
{
    ::init();
    add_action("feast_func", "feast");
    return;
}
