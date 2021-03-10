#include <std.h>
inherit "/d/common/obj/weapon/longsword";
int max;
create()
{
    ::create();
    set_name("longsword");
    set_id(({ "longsword", "long sword", "sword" }));
    set_short("longsword");
    set_long(
        "This is a standard longsword seen wielded by the many "
        "goblins within the lands of Shadow. Judging by its  blade, "
        "it has had much use."
        "%^RESET%^"
        );
    set_value(25);
    set_wield((: TO, "extra_wield" :));
    set_unwield((: TO, "extra_unwield" :));
    set_hit((: TO, "extra_hit" :));
}
int extra_wield()
{
    write("%^RED%^"
          "The longsword begins to hum."
          "%^RESET%^"
          );
    say("%^RED%^"
        "The longsword held by "
        + TPQCN +
        " begins to hum."
        "%^RESET%^"
        , TP);
    if ((string)TP->query_race() == "goblin" && userp(TP)) {
        write("%^YELLOW%^You feel the power of the Goblin %^RED%^Red%^YELLOW%^ Army flow through you!%^RESET%^");
        say("%^YELLOW%^" + TPQCN + " howls with a urgent rage of bloodlust!%^RESET%^");
        max = (int)TP->query_highest_level() / 5;
        if (max > 4) {
            max = 4;
        }
        remove_property("enchantment");
        max = (int)TP->query_lowest_level() / 5;
        if (max > 5) {
            max = 5;
        }
        set_property("enchantment", max);
        while (query_property("enchantment") < 0) {
            remove_property("enchantment");
            set_property("enchantment", max);
        }
    }
    return 1;
}

int extra_unwield()
{
    write("%^RED%^"
          "The longsword ceases its strange humming."
          "%^RESET%^"
          );
    say("%^RED%^"
        "The longsword wielded by "
        + ETO->query_cap_name() +
        " ceases its strange humming."
        "%^RESET%^"
        , TP);
    TO->remove_property("enchantment");
    return 1;
}

int extra_hit(object ob)
{
    object vic;
    int dam;
    vic = ETO->query_current_attacker();
    if (!objectp(vic)) {
        return random(5) - random(8);
    }
    if (random(8) > 2) {
        return random(2) - random(random(query_wc() / 2));
    }
    ;
    message("my_action", "%^BOLD%^%^RED%^"
            "With a scream of anger you slash deep into your opponent's "
            "flesh!"
            "%^RESET%^"
            , ETO);
    message("other_action", "%^BOLD%^%^RED%^"
            + ETO->query_cap_name() +
            " slashes deep into "
            + vic->query_cap_name() +
            "'s flesh!"
            "%^RESET%^"
            , environment(vic), (({ ETO, vic })));
    message("my_action", "%^BOLD%^%^RED%^"
            + ETO->query_cap_name() +
            " slashes deep into your flesh!"
            "%^RESET%^"
            , vic);
    dam = random(5) + 1;
    if ((string)ETO->query_race() == "goblin" && userp(ETO)) {
        write("%^YELLOW%^You deliver the wrath of the Goblin %^RED%^Red%^YELLOW%^ Army upon your foe!%^RESET%^");
        tell_room(environment(query_wielded()), "%^YELLOW%^" + ETO->query_cap_name() + "  screams with bloodlust!%^RESET%^", ETO);
        dam = dam + random((int)ETO->query_level() / 3 + 2);
    }
    return dam;
}

int save_me(string file)
{
    return ::save_me(file);
}

void init()
{
    ::init();

    remove_property("enchantment");
}
