#include <std.h>
#include <daemons.h>
#include "/d/deku/inherits/graveyard.h"
inherit WEAPONLESS;
int time, x;
string* stats_affected;
int stench();

void create()
{
    ::create();
    set_name("Zombie Lord");
    set_id(({ "lord", "zombie", "zombie lord" }));
    set_gender("male");
    set_race("human");
    set_short("A decaying human");
    set_long("%^BOLD%^%^GREEN%^This man is the victim of some " +
             "some horrific tragedy or curse.  His %^CYAN%^azure" +
             "%^BOLD%^%^GREEN%^ eyes shine with intelligence and life, " +
             "but his nude body is decaying quickly.  His flesh is a " +
             "%^RESET%^sickly gray%^BOLD%^%^GREEN%^ color and has a very " +
             "coarse and leathery texture.  The hair that hangs from " +
             "the top of his head is matted with sweat and what " +
             "appears to be %^RESET%^%^RED%^gore%^BOLD%^%^GREEN%^.  " +
             "His mouth is twisted into an unnatural grin, revealing " +
             "blood-stained and flesh ridden teeth.  His hands are " +
             "kept always in very tight clenched fists.  A nauseating " +
             "odor of rot hangs in the air around him, making it " +
             "difficult and even dangerous to breath in his presence.%^RESET%^");
    set_alignment(6);
    set("aggressive", "stench");
    set_hd(24, 1);
    set_guild_level("mage", 24);
    set_mlevel("mage", 24);
    set_hp(575 + random(51));
    set_new_exp(20, "high");
    set_stats("strength", 18);
    set_stats("wisdom", 12);
    set_stats("intelligence", 19);
    set_stats("dexterity", 14);
    set_stats("charisma", 4);
    set_stats("constitution", 12);
    set_property("no death", 1);
    set_property("full attacks", 1);
    set_mob_magic_resistance("average");
    set_property("weapon resistance", 1);
    set_attack_limbs(({ "left hand", "right hand" }));
    set_attacks_num(4);
    set_damage(4, 6);
    set_spell_chance(20);
    set_spells(({ "lightning bolt", "chain lightning" }));
    time = 1;
    x = random(10);
    if (x >= 8) {
        new(GY_OBJS + "mummified_hand")->move(TO);
    }
    if (x >= 4 && x < 8) {
        new(GY_OBJS + "stench_necklace")->move(TO);
    }else {
        add_money("gold", 1500 + random(1501));
    }
    stats_affected = ({});
    command("wear necklace");
}

void heart_beat()
{
    ::heart_beat();
    if (!objectp(TO)) {
        return;
    }
    if (!objectp(ETO)) {
        return;
    }
    if (TO->query_current_attacker() != 0) {
        if (time == 0) {
            stench();
            time = 30 + random(21);
        }
        time--;
    }
    if (time > 1) {
        time = 1;
    }
}

int do_affect(object victim)
{
    int x;
    x = random(100);
    switch (x) {
    case 0..90:
        tell_object(victim, "%^BOLD%^%^GREEN%^The odor causes your stomach to lurch and you begin vomitting!%^RESET%^");
        tell_room(ETO, victim->QCN + "%^BOLD%^%^GREEN%^ begins vomitting!%^RESET%^", victim);
        victim->set_paralyzed(12 + random(15), "%^BOLD%^%^GREEN%^Your body is trembling and you continue to vomit!%^RESET%^");
        return 1;

        break;

    case 91..95:
        tell_object(victim, "%^BOLD%^%^GREEN%^You feel physically " +
                    "weakened by the powerful odor!%^RESET%^");
        victim->cause_typed_damage(victim, "head", roll_dice(10, 10), "negative energy");
        break;

    case 96..99:
        tell_object(victim, "%^BOLD%^%^GREEN%^You feel ill, " +
                    "but manage to resist vomitting, as the odor of rot " +
                    "continues its assault!%^RESET%^");
        victim->cause_typed_damage(victim, "head", roll_dice(8, 10), "negative energy");
        break;
    }
}

int stench()
{
    object* people;
    int x;
    if (!objectp(TO)) {
        return 0;
    }
    if (!objectp(ETO)) {
        return 0;
    }
    people = all_living(ETO);
    people -= ({ TO });
    for (x = 0; x < sizeof(people); x++) {
        if (people[x]->query_true_invis()) {
            continue;
        }
        tell_object(people[x], "%^BOLD%^%^GREEN%^You take a deep breath and are assaulted by the odor of rot emitted by the human!%^RESET%^");
        TO->force_me("kill " + people[x]->query_name());
        if (people[x]->will_save(28)) {
            do_affect(people[x]);
        }
    }
}
