#include <std.h>
inherit OBJECT;

int count;
void create()
{
    ::create();
    set_name("essence");
    set_id(({ "essence", "garlic essence", }));
    set_short("%^RESET%^%^ORANGE%^garlic essence%^RESET%^");
    set_long("%^ORANGE%^A strange glowing liquid flows in helices in this vial. You think you can <wear> it.");
    set_value(200);
    set_weight(1);
}

void init()
{
    :: init();
    add_action("wear_essence", "wear");
}

int wear_essence(string str)
{
    string long;
    if (str == "essence" || str == "garlic essence") {
        /* Retaining this for the future, when alchemy gets implemented */

        /* if (count > 10) { */
        /*     tell_object(TP, "The bottle is empty."); */
        /*     return 1; */
        /* } */
        tell_object(TP, "%^ORANGE%^You dab on the bottle, and the scent of mermeates your very soul.");
        TP->set_property("garlic_scent", 1);
        count++;
        return 1;
    }
    return 0;
}
