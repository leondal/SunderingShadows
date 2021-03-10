//Added miniquest query - Octothorpe 7/24/10

#include <std.h>
inherit OBJECT;

object room;
nosave int flag;

int charge, strength = 63; //strength is the higest level dimensional lock an archmage abjurer can set

void create()
{
    ::create();
    set_name("clay sphere");
    set_id(({ "sphere", "ball", "no tp", "clay sphere" }));
    set_short("%^RESET%^%^ORANGE%^Sphere of Protection%^RESET%^");
    set_obvious_short("%^RESET%^%^ORANGE%^small clay sphere%^RESET%^");
    set_long("%^ORANGE%^This is a small clay sphere that is completely " +
             "smooth, except for a single small divot scarring its surface. " +
             "The ball is quite heavy for its small size, seemingly made out " +
             "of extremely dense clay or affected by some source of magic.%^RESET%^");
    set_weight(10);
    set_value(55);
    set_lore("This ancient device hails from the ancient kingdom of " +
             "Zin'Charu, and were used to protect members of the magocracy " +
             "during vulnerable situations. Spheres such as these were " +
             "scattered over the realms after the fall of humanity's " +
             "first empire.  A handful were recovered by the burgeoning " +
             "Kingdom of Kinnesaruda to protect the king's conclaves from " +
             "unwanted interruptions. You suspect that you can activate the " +
             "magic of the sphere if you %^BOLD%^<press divot>%^RESET%^, " +
             "however its supply of magic is probably running low after " +
             "many centuries of existence.");
    set_property("lore", 20);
    charge = 450 + random(101);
    set_heart_beat(1);
}

void heart_beat()
{
    if (flag) {
        charge--;
    }
    if (flag && charge == 0) {
        flag = 0;
        tell_room(ETO, "%^ORANGE%^The whole sphere stops glowing, then vanishes.");
        room->set_property("teleport proof", -strength);
        TO->remove();
    }
}

void set_charge(int x)
{
    charge = x;
}

int query_charge()
{
    return charge;
}

void init()
{
    ::init();
    if (ETO->is_room()) {
        if (objectp(room)) {
            room->set_property("teleport proof", -strength);
        }
        room = ETO;
        room->set_property("teleport proof", strength);
    }else {
        if (objectp(room)) {
            room->set_property("teleport proof", -strength);
            room = 0;
        }
    }
    add_action("press", "press");
}

int press(string str)
{
    if (!str || str != "divot" || (int)ETO->query_highest_level() < 25 || member_array("Life force of the Kinnesaruda has faded, Intruder and Autarkis are defeated", ETO->query_mini_quests()) == -1) {
        tell_object(TP, "%^BOLD%^You run your hands over the sphere to " +
                    "no avail.");
        return 0;
    }
    if (flag) {
        tell_object(TP, "%^ORANGE%^You press the divot and the whole " +
                    "sphere stops glowing.");
        tell_room(ETP, "%^ORANGE%^" + TPQCN + " presses the divot and the " +
                  "whole sphere stops glowing.", TP);
        flag = 0;
        if (room) {
            room->set_property("teleport proof", -strength);
        }
        return 1;
    }else if (charge) {
        tell_object(TP, "%^BOLD%^You press the divot and the whole " +
                    "sphere starts to glow.");
        tell_room(ETP, "%^BOLD%^" + TPQCN + " press the divot and the " +
                  "whole sphere starts glowing.", TP);
        flag = 1;
        return 1;
    }
}

string query_short()
{
    string sh = ::query_short();
    if (flag && charge) {
        sh += " %^BOLD%^%^WHITE%^(glowing)%^RESET%^";
    }
    return sh;
}
