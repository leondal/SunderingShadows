#include <std.h>
inherit "/d/common/obj/weapon/dagger";

create() {
    ::create();
    set_name("dagger");
    set_id(({ "longdagger", "long dagger", "black dagger", "dagger" }));
    set_short("%^BLUE%^Black dagger%^RESET%^");
    set_long(
        "This is one of the standard %^BOLD%^%^BLUE%^black "
        "longdaggers%^RESET%^ used by the lower ranks of the Drow "
        "Regime. However it still is an amazingly crafted weapon and "
        "emanates magical properties. Traces of "
        "%^YELLOW%^electricity%^RESET%^ seem to run "
        "up and down its blade."
        );
    set_property("enchantment", 1);
    set_wield((: TO, "drow" :));
    set_hit((: TO, "extra_hit" :));
}
int drow()
{
    if ((int)ETO->query_highest_level() < 8 && (string)ETO->query_race() != "Drow") {
        notify_fail("You may not wield this dagger!");
        return 0;
    }
    if ((int)ETO->query_alignment() != 9 && (string)ETO->query_race() != "drow" && (string)ETO->query_race() != "Drow") {
        write(
            "You feel a %^BOLD%^%^YELLOW%^shock%^RESET%^ run through your "
            "body as you wield the dagger!"
            );
        ETO->cause_typed_damage(ETO, ETO->return_target_limb()
                                , random(13), "electricity");

        return 1;
    }
    return 1;
}

int extra_hit(object ob)
{
    object vic;
    int dam;
    vic = ETO->query_current_attacker();
    if (!objectp(vic)) {
        return 0;
    }
    dam = 0;
    if (random(10) < 5) {
        dam = 0;
    } else {
        if (random(15) > 1) {
            message("my_action",
                    "%^BOLD%^%^BLUE%^You cackle wildly as "
                    "you slash your foe!%^RESET%^"
                    , ETO);
            message("other_action", "%^BOLD%^%^BLUE%^"
                    + ETO->query_cap_name() +
                    " cackles wildly while slashing with a dagger!%^RESET%^"
                    , environment(vic), (({ ETO, vic })));
            message("my_action", "%^BOLD%^%^BLUE%^"
                    + ETO->query_cap_name() +
                    " cackles wildly while slashing at your flesh!"
                    "%^RESET%^"
                    , vic);
            dam = random(6) + 1;
            if ((int)ETO->query_alignment() == 9) {
                dam = dam * (((int)ETO->query_level() / 8) + 1);
            }
        } else {
            if (random(150) < 1) {
                message("my_action", "%^BOLD%^%^YELLOW%^"
                        "The dagger suddenly transforms into a bolt of pure "
                        "energy as it enters your victim's skull!"
                        "%^RESET%^"
                        , ETO);
                message("other_action", "%^BOLD%^%^YELLOW%^"
                        "A bright flash fills the air!%^RESET%^"
                        , environment(vic), (({ ETO, vic })));
                message("my_action", "%^BOLD%^%^YELLOW%^"
                        "The dagger wielded by " + ETO->query_cap_name() +
                        " suddenly transforms into a bolt of energy which "
                        "penetrates your skull!%^RESET%^"
                        , vic);
                vic->do_damage("head", 100);
                TO->remove();
                dam = 0;
            } else {
                message("my_action", "%^YELLOW%^"
                        "The dagger flashes with electrical energy "
                        "shocking you and your foe!%^RESET%^"
                        , ETO);
                message("other_action", "%^YELLOW%^"
                        "The dagger wielded by " + ETO->query_cap_name() +
                        " flashes with electrical energy as it strikes "
                        + vic->query_cap_name() + "!"
                        , environment(vic), (({ ETO, vic })));
                message("my_action", "%^YELLOW%^"
                        "The dagger wielded by " + ETO->query_cap_name() +
                        " flashes with electrical energy as it strikes "
                        "you!%^RESET%^"
                        , vic);
                dam = random(8) + 7;
                if ((int)ETO->query_hp() > 20) {
                    ETO->do_damage("torso", random(3) + 1);
                }
            }
        }
    }
    return dam;
}
