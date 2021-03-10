#include "/d/islands/dallyh/fways.h"
inherit MONSTER;

object* oozelings;

void create()
{
    object ob;
    ::create();
    set_id(({ "spike", "demon", "spiked demon", "dallyhallyevil" }));
    set_name("spiked demon");
    set_short("%^BOLD%^%^BLACK%^Sp%^RESET%^%^RED%^i%^BOLD%^%^BLACK%^" +
              "k%^RESET%^%^RED%^e%^BOLD%^%^BLACK%^d D%^RESET%^%^RED%^e%^BOLD%^%^BLACK%^" +
              "m%^RESET%^%^RED%^o%^BOLD%^%^BLACK%^n%^RESET%^");

    set_long("%^BOLD%^%^BLACK%^This creature stands almost eight feet tall. " +
             "It's body looks noticeably %^BOLD%^%^CYAN%^feminine%^BOLD%^%^BLACK%^ with " +
             "supply breasts and curvy hips. However, beyond these base similarities " +
             "it appears far from human. It has a %^BOLD%^%^WHITE%^roundish%^BOLD%^%^BLACK%^ " +
             "face with two %^RESET%^%^RED%^deep red%^BOLD%^%^BLACK%^ eyes inset just above a " +
             "strikingly pointed nose below which rests an %^BOLD%^eternal scowl%^BOLD%^" +
             "%^BLACK%^. The top of its head is bald and %^RESET%^%^GREEN%^scaly%^BOLD%^%^BLACK%^ " +
             "with %^RESET%^%^RED%^sharp spikes%^BOLD%^%^BLACK%^ starting at the base of its " +
             "neck and extending down the length of its %^RESET%^crooked spine%^BOLD%^%^BLACK%^" +
             ". There are numerous %^RESET%^%^RED%^sharp spikes%^BOLD%^%^BLACK%^ that burst " +
             "forth from the rest of its %^RESET%^%^BLUE%^dark blue%^BOLD%^%^BLACK%^ flesh and " +
             "drip with a %^BOLD%^%^GREEN%^sizzling ooze%^BOLD%^%^BLACK%^. The rest of its " +
             "body looks terribly misfigured and twisted.%^RESET%^");

    set_body_type("human");
    set_gender("female");
    set_property("magic", 1);
    set_race("demon");
    set_overall_ac(-50);
    set_property("full attacks", 1);
    set_base_damage_type("bludgeoning");
    set_damage(4, 20);
    set("aggressive", 21);
    set_mob_magic_resistance("average");
    set_class("mage");
    set_guild_level("mage", 50 + random(7));
    set_moving(1);
    set_speed(50);
    set_class("fighter");
    add_search_path("/cmds/fighter");
    set_mlevel("fighter", 42 + random(7));
    set_hd(58, 12);
    set_hp(1000 + random(1000));
    set_new_exp(48, "high");
    set_spells(({
        "magic missile",
        "fireball",
        "lightning bolt",
        "hideous laughter",
        "cone of cold",
        "meteor swarm",
    }));
    set_spell_chance(50);
    add_money("platinum", random(1000) + 1000);
    set_monster_feats(({
       "spell penetration",
       "greater spell penetration",
    }));
}

void init()
{
    ::init();
    if (!objectp(TO)) {
        return;
    }
    if (!objectp(TP)) {
        return;
    }
    if (interactive(TP) && !wizardp(TP) && !TP->query_true_invis()) {
        force_me("kill " + TPQN);
        force_me("rush " + TPQN);
    }
}

void create_oozeling()
{
    int x, mod;
    object* to_remove = ({}), ooze;
    if (!objectp(TO) || !objectp(ETO)) {
        return;
    }
    if (!pointerp(oozelings)) {
        oozelings = ({});
    }
    for (x = 0; x < sizeof(oozelings); x++) {
        if (!objectp(oozelings[x])) {
            to_remove += ({ oozelings[x] });
            continue;
        }
        continue;
    }
    if (sizeof(to_remove)) {
        oozelings -= to_remove;
    }
    if (!intp(mod = TO->query("damage mod")) || mod < 1) {
        mod = 1;
    }
    if (sizeof(oozelings) > (3 * mod)) {
        return;
    }
    tell_room(ETO, "%^BOLD%^%^GREEN%^You watch in horror as some of the ooze plops from the %^RESET%^" +
              TO->query_short() + "%^BOLD%^%^GREEN%^....... \n\n" +
              "and begins moving!%^RESET%^");
    ooze = new(MMPATH "oozeling");
    ooze->move(ETO);
    oozelings += ({ ooze });
    return;
}

void heart_beat()
{
    ::heart_beat();
    if (!objectp(TO) || !objectp(ETO)) {
        return;
    }
    if (!pointerp(oozelings)) {
        oozelings = ({});
    }
    DYN_UP_D->dynamic_update(TO);
    if (random(10)) {
        return;
    }
    create_oozeling();
    return;
}
