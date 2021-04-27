#include <std.h>
inherit "/d/common/obj/weapon/claw.c";
create()
{
    ::create();
    set_name("dagger");
    set_id(({ "dagger", "dagger of shadows" }));
    set_short("%^RESET%^%^CYAN%^Dagger of shadows%^RESET%^");
    set_long("%^BLUE%^"
             "This weapon is incredibly hard to visualize as "
             "it appears to be nothing more than a piece of a shadow."
             "%^RESET%^"
             );
    set_value(0);
    set_wield((: TO, "extra_wield" :));
    set_unwield((: TO, "extra_unwield" :));
    set_hit((: TO, "extra_hit" :));
    set_property("monsterweapon", 1);
}
int extra_wield()
{
    if ((string)TP->query_name() != "something" || interactive(TP)) {
        write("%^CYAN%^The shadow melts in your hand!%^RESET%^");
        TO->remove();
        return 0;
    } else {
        return 1;
    }
}

int extra_unwield()
{
    return 1;
}

int extra_hit(object ob)
{
    object vic;
    int dam;
    vic = ETO->query_current_attacker();
    if (random(8) > 4) {
        return 1;
    }
    message("other_action", "%^BLUE%^"
            + ETO->query_cap_name() +
            " is suddenly surrounded by numerous swirling shadows!"
            "%^RESET%^"
            , environment(vic), (({ ETO, vic })));
    message("my_action", "%^BLUE%^"
            "The %^BOLD%^shadows%^RESET%^%^CYAN%^ envelop you!%^RESET%^"
            , vic);
    dam = roll_dice(2, 6);
    return dam;
}
