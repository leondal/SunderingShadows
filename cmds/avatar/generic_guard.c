#include <std.h>
#include <daemons.h>

#define VALID_CLASSES   ({ "fighter", "mage", "thief", "bard", "paladin", "ranger", "cavalier", "antipaladin", "cleric", "assassin", "psion" })
#define SEARCH_PATHS    ([ "fighter" : ({ "/cmds/fighter" }), "mage" : ({ "/cmds/wizard" }), "thief" : ({ "/cmds/thief" }), "bard" : ({ "/cmds/bard", "/cmds/wizard" }), "paladin" : ({ "/cmds/cavalier", "/cmds/paladin", "/cmds/priest" }), "ranger" : ({ "/cmds/ranger", "/cmds/priest" }), "cavalier" : ({ "/cmds/cavalier" }), "antipaladin" : ({ "/cmds/cavalier", "/cmds/antipaladin", "/cmds/priest" }), "cleric" : ({ "/cmds/priest" }), "assassin" : ({ "/cmds/assassin" }), "psion" : ({ "/cmds/psion", "/cmds/psionics" }) ])
#define DIVINE_CLASSES  ({ "ranger", "paladin", "antipaladin", "cleric" })
#define ARCANE_CLASSES  ({ "bard", "mage" })
#define STATS           ({ "strength", "dexterity", "constitution", "intelligence", "wisdom", "charisma" })
#define MONEY           ({ "platinum", "gold", "electrum", "silver", "copper" })

inherit WEAPONLESS;

nosave int FLAG, FLAG2, SMART, DROP, TARGETING, BLINKED = 0, AGG;
string* TARGETS = ({}), * monster_classes = ({}), * DONT_TARGET = ({});

void create()
{
    ::create();
    set_name("Guard");
    set_id(({ "guard" }));
    set_race("human");
    set_body_type("human");
    set_gender((random(2) ? "male" : "female"));
    set_size(5);
    set_short("a generic guard");
    set_long("This is a generic guard description, it's really not very impressive.");
    set_hd(30, 1);
    set_level(30);
    set_class("fighter");
    set_mlevel("fighter", 30);
    set_max_hp(100);
    set_hp(100);
    set_exp(1000);
    set_overall_ac(0);
    set_stats("strength", 15);
    set_stats("dexterity", 15);
    set_stats("intelligence", 15);
    set_stats("wisdom", 15);
    set_stats("constitution", 15);
    set_stats("charisma", 15);
    set_property("full attacks", 1);
    set_damage(1, 6);
    set_base_damage_type("slashing");
    set_property("knock unconscious", 1);
    set_thief_skill("move silently", 95);
    set_thief_skill("hide in shadows", 95);
}

void set_monster_name(string str)
{
    if (!stringp(str)) {
        return;
    }
    TO->set_name(str);
    return;
}

void set_monster_ids(string* ids)
{
    if (!pointerp(ids)) {
        return;
    }
    TO->set_id(ids);
    return;
}

void add_monster_id(string str)
{
    if (!stringp(str)) {
        return;
    }
    TO->add_id(str);
    return;
}

void set_monster_race(string str)
{
    if (!stringp(str)) {
        return;
    }
    str = lower_case(str);
    if (member_array(str, RACE_D->query_races()) == -1) {
        return;
    }
    TO->set_race(str);
    TO->set_body_type(str);
    return;
}

void set_monster_gender(string str)
{
    if (!stringp(str)) {
        return;
    }
    str = lower_case(str);
    TO->set_gender(str);
    return;
}

void set_monster_size(int num)
{
    if (!intp(num)) {
        return;
    }
    if (num < 1) {
        num = 1;
    }
    if (num > 5) {
        num = 5;
    }
    TO->set_size(num);
    return;
}

void set_monster_short(string str)
{
    if (!stringp(str)) {
        return;
    }
    TO->set_short(str);
    return;
}

void set_monster_long(string str)
{
    if (!stringp(str)) {
        return;
    }
    TO->set_long(str);
    return;
}

void set_monster_classes(string* classes)
{
    if (pointerp(classes)) {
        monster_classes = classes;
    }
    return;
}

void set_monster_class(string str)
{
    string* classes, * paths;
    int i, j;
    if (!stringp(str)) {
        return;
    }
    str = lower_case(str);
    if (member_array(str, VALID_CLASSES) == -1) {
        return;
    }
    TO->set_class(str);
    classes = TO->query_classes();
    for (i = 0; i < sizeof(classes); i++) {
        if (member_array(classes[i], monster_classes) == -1) {
            TO->remove_class(classes[i]);
            continue;
        }
        paths = SEARCH_PATHS[classes[i]];
        for (j = 0; j < sizeof(paths); j++) {
            TO->add_search_path(paths[j]);
        }
    }
    if (TO->is_class("thief")) {
        TO->set_thief_skill("move silently", 95);
        TO->set_thief_skill("hide in shadows", 95);
    }

    return;
}

void remove_monster_class(string str)
{
    if (!stringp(str)) {
        return;
    }
    str = lower_case(str);
    if (member_array(str, TO->query_classes()) == -1) {
        return;
    }
    TO->remove_class(str);
    return;
}

void set_monster_level(int num)
{
    string* classes;
    int i;
    object ob;
    if (!intp(num)) {
        return;
    }
    if (ob = present("kit", TO)) {
        ob->remove();
        FLAG = 0;
    }
    classes = TO->query_classes();
    for (i = 0; i < sizeof(classes); i++) {
        TO->set_mlevel(classes[i], num);
        if (member_array(classes[i], DIVINE_CLASSES) != -1) {
            TO->set_guild_level("cleric", num);
        }
        if (member_array(classes[i], ARCANE_CLASSES) != -1) {
            TO->set_guild_level("mage", num);
        }
        if (classes[i] == "psion") {
            TO->set_guild_level("psion", num);
        }
        TO->set_guild_level(classes[i], num);
    }
    TO->set_nwp("riding", num + 1);
    TO->set_level(num);
    TO->set_hd(num, 12);
    return;
}

void set_monster_hp(int num)
{
    if (!intp(num)) {
        return;
    }
    TO->set_max_hp(num);
    TO->set_hp(TO->query_max_hp());
    return;
}

void set_monster_exp(int num)
{
    if (!intp(num)) {
        return;
    }
    TO->set_exp(num);
    return;
}

void set_monster_swarm(int num)
{
    if (!num) {
        TO->remove_property("swarm");
    }
    if (num) {
        TO->set_property("swarm", 1);
    }
    return;
}

void set_monster_aggressive(int num)
{
    if (!num) {
        TO->delete("aggressive");
    }
    if (num) {
        TO->set("aggressive", num);
    }
    return;
}

void set_monster_ac(int num)
{
    if (!num) {
        return;
    }
    TO->set_overall_ac(num);
    return;
}

void set_monster_stat(string str, int num)
{
    if (!stringp(str)) {
        return;
    }
    if (!intp(num)) {
        return;
    }
    if (member_array(str, STATS) == -1) {
        return;
    }
    TO->set_stats(str, num);
    return;
}

void set_monster_attacks(int num)
{
    if (!intp(num)) {
        return;
    }
    TO->set_attacks_num(num);
    return;
}

void set_monster_damage(int num)
{
    if (!intp(num)) {
        return;
    }
    TO->set_damage(1, num);
    return;
}

void set_monster_spells(string* str)
{
    if (!pointerp(str)) {
        return;
    }
    TO->set_spells(str);
    return;
}

void add_monster_spell(string str)
{
    string* spells;
    if (!stringp(str)) {
        return;
    }
    spells = TO->query_spells();
    if (!pointerp(spells)) {
        TO->set_spells(({ str }));
        return;
    }
    spells += ({ str });
    TO->set_spells(spells);
    return;
}

void set_monster_spell_chance(int num)
{
    if (!intp(num)) {
        return;
    }
    TO->set_spell_chance(num);
    return;
}

void set_monster_money(string str, int num)
{
    if (!stringp(str)) {
        return;
    }
    if (!intp(num)) {
        return;
    }
    if (member_array(str, MONEY) == -1) {
        return;
    }
    TO->add_money(str, random(num));
    return;
}

void set_monster_resistance(int num)
{
    if (!intp(num)) {
        return;
    }
    TO->remove_property("magic resistance");
    TO->set_property("magic resistance", num);
    return;
}

void set_smart(int num)
{
    object ob;
    if (!intp(num)) {
        return;
    }
    SMART = num;
    return;
}

string get_object_id(object ob)
{
    string* ids;
    if (!objectp(ob)) {
        return 0;
    }
    ids = ob->query_id();
    if (ob->is_player()) {
        return (string)ob->query_name();
    }else {
        return ids[0];
    }
}

int set_drop(int num)
{
    if (!intp(num)) {
        return 0;
    }
    DROP = num;
    return 1;
}

void set_guard_targets(string* names)
{
    if (!pointerp(names) || !sizeof(names)) {
        return;
    }
    TARGETS = names;
}

void set_allied_players(string* players)
{
    if (!pointerp(players) || !sizeof(players)) {
        return;
    }
    DONT_TARGET = players;
}

void toggle_targeting(int num)
{
    if (num) {
        TARGETING = 1;
    }else {
        TARGETING = 0;
    }
}

void die(object ob)
{
    object* inv;
    int i;
    if (DROP) {
        inv = all_inventory(TO);
        for (i = 0; i < sizeof(inv); i++) {
            if (!objectp(inv[i])) {
                continue;
            }
            if (roll_dice(1, 100) < DROP) {
                inv[i]->remove_property("monsterweapon");
            }
        }
    }
    ::die(ob);
    return;
}

void heart_beat()
{
    object ob, * attackers, targ, * weapons = ({}), * inv = ({}), * allies;
    string id;
    int kits, i, j, counter;

    ::heart_beat();

    if (!objectp(TO)) {
        return;
    }
    if ((int)TO->query_hp() < 0) {
        TO->die();
        return;
    }

    allies = ({});

    for (i = 0; i < sizeof(DONT_TARGET); i++) {
        if (!objectp(find_player(DONT_TARGET[i]))) {
            continue;
        }
        allies += ({ find_player(DONT_TARGET[i]) });
    }

    if (sizeof(TO->query_attackers()) && sizeof(allies)) {
        attackers = (object*)TO->query_attackers();
        for (i = 0; i < sizeof(attackers); i++) {
            if (!objectp(attackers[i])) {
                continue;
            }
            if (member_array(attackers[i], allies) == -1) {
                continue;
            }
            for (j = 0; j < sizeof(allies); j++) {
                if (!objectp(allies[j])) {
                    continue;
                }
                attackers[i]->remove_attacker(allies[j]);
                allies[j]->remove_attacker(attackers[i]);
            }
        }
    }

    if (!objectp(TO)) {
        return;
    }

    if (!counter) {
        counter = 1;
    }else if (counter) {
        counter = 0;
    }

    if (!FLAG2) {
        FLAG2 = 1;
        TO->set_hp(TO->query_max_hp());
        if (is_class("paladin") || is_class("antipaladin") || is_class("cavalier")) {
            ob = new("/d/common/mounts/barded_war_horse.c");
            ob->set_owner(TO);
            ob->move(ETO);
            TO->set_in_vehicle(ob);
            ob = new("/d/common/obj/weapon/lance.c");
            ob->move(TO);
        }
        TO->force_me("wearall");
        inv = all_inventory(TO);
        for (i = 0; i < sizeof(inv); i++) {
            if (!objectp(inv[i])) {
                continue;
            }
            if (inv[i]->is_weapon()) {
                id = inv[i]->query_id();
                if (pointerp(id) && sizeof(id)) {
                    TO->force_me("wield " + id[0] + "");
                    TO->force_me("wield " + id[0] + " 2");
                }
            }
        }
    }
    if (sizeof(TO->query_attackers() && TO->query_hidden())) {
        TO->set_hidden(0);
    }
    if (TO->is_class("thief") && !(int)TO->query_hidden() && !sizeof(TO->query_attackers())) {
        TO->set_hidden(1);
    }

    attackers = (object*)TO->query_attackers();

    if (TARGETING && sizeof(TARGETS)) {
        for (i = 0; i < sizeof(TARGETS); i++) {
            if (targ = present(TARGETS[i], ETO)) {
                if (member_array(targ, attackers) != -1) {
                    continue;
                }
                force_me("kill " + TARGETS[i]);
            }
        }
    }

    if (sizeof(attackers)) {
        if (SMART) {
            ob = (object)TO->query_current_attacker();

            if (!ob->query_tripped() && !(int)ob->query_property("generic powdered")) {
                if (present("net", TO)) {
                    {
                        TO->force_me("wield net");
                        TO->force_me("throw net at " + get_object_id(ob) + "");
                        ob->set_property("generic powdered", 1);
                    }
                }else if (present("powder", TO)) {
                    if (!TO->is_class("paladin") || !TO->is_class("antipaladin") || !TO->is_class("cavalier")) {
                        TO->force_me("toss powder at " + get_object_id(ob) + "");
                        ob->set_property("generic powdered", 1);
                    }
                }
            }
            if (!BLINKED) {
                if (TO->is_class("mage") || TO->is_class("bard")) {
                    BLINKED = 1;
                    new("/cmds/spells/b/_blink.c")->use_spell(TO, get_object_id(ob), (int)TO->query_guild_level("mage"), 100);
                }
                if (TO->is_class("psion")) {
                    BLINKED = 1;
                    new("/cmds/spells/c/_concealing_amorpha.c")->use_spell(TO, get_object_id(ob), (int)TO->query_guild_level("psion"), 100);
                    new("/cmds/spells/t/_timeless_body.c")->use_spell(TO, get_object_id(ob), (int)TO->query_guild_level("psion"), 100);
                }
            }
            if ((int)ob->query_property("magic resistance") > 1 && !(int)ob->query_property("generic been lowered")) {
                if (TO->is_class("mage") || TO->is_class("bard")) {
                    new("/cmds/spells/l/_lower_resistance.c")->use_spell(TO, get_object_id(ob), (int)TO->query_guild_level("mage"), 100);
                    ob->set_property("generic been lowered", 1);
                }else if (TO->is_class("psion")) {
                    new("/cmds/spells/r/_resistance.c")->use_spell(TO, get_object_id(ob) + " to lower", (int)TO->query_guild_level("psion"), 100);
                    ob->set_property("generic been lowered", 1);
                }
            }
            if (TO->is_class("fighter")) {
                for (i = 0; i < sizeof(TO->query_attackers()); i++) {
                    if (i == 0) {
                        TO->force_me("rush attacker");
                    }else {
                        TO->force_me("rush attacker " + (i + 1) + "");
                    }
                }
                if (!TO->query_parrying()) {
                    TO->force_me("parry");
                }
            }
            if (TO->is_class("ranger")) {
                TO->force_me("whirl");
            }
            if (TO->is_class("thief")) {
                if (!TO->query_scrambling()) {
                    TO->force_me("scramble");
                }
            }
            if (TO->is_class("paladin") || TO->is_class("cavalier") || TO->is_class("antipaladin")) {
                if (TO->query_in_vehicle() && !ob->query_property("generic charged")) {
                    TO->force_me("wield lance");
                    TO->force_me("charge " + get_object_id(ob) + "");
                    ob->set_property("generic charged", 1);
                }
            }
            if (TO->is_class("assassin")) {
                TO->force_me("crit " + get_object_id(ob) + "");
            }
        }
    }else {
        BLINKED = 0;
    }

    return;
}

// Overrides below here to deal with allies not getting attacked -Ares

int kill_ob(object victim, int which)
{
    object* allies = ({});
    int i;
    if (!objectp(victim)) {
        return 0;
    }
    for (i = 0; i < sizeof(DONT_TARGET); i++) {
        if (!objectp(find_player(DONT_TARGET[i]))) {
            continue;
        }
        allies += ({ find_player(DONT_TARGET[i]) });
    }
    if (member_array(victim, allies) != -1) {
        return 0;
    }
    ::kill_ob(victim, which);
}

void init()
{
    object* allies = ({});
    mixed tmp;
    int i;
    string* temp;

    if (!objectp(TO)) {
        return;
    }
    //::init();
    if (!objectp(TO)) {
        return;
    }
    temp = ({});
    if (!heart_beat_on || !query_heart_beat(TO)) {
        set_heart_beat(heart_beat_on = 1);
    }
    if (TP->query_invis() && !detecting_invis()) {
        if (wizardp(this_player())) {
            return;
        }
        if (random(101) < (int)this_player()->query_level()) {
            return;
        }
    }
    if (this_player()->query_ghost()) {
        return;
    }
    if (this_player()->is_player()) {
        if (tmp = query("aggressive")) {
            for (i = 0; i < sizeof(DONT_TARGET); i++) {
                if (!objectp(find_player(DONT_TARGET[i]))) {
                    continue;
                }
                allies += ({ find_player(DONT_TARGET[i]) });
            }

            if (intp(tmp) && tmp > (int)this_player()->query_stats("charisma")) {
                if (TP->query_invis()) { // changed to give mobs a way to attack invis players without needing to set init()
                    if (TP->query_true_invis()) {
                        return;
                    }
                    if (!query_property("invis attack")) {
                        return;
                    }
                }
                if (this_player()->query_property("draggee")) {
                    return;
                }                                                     // Added so hostil mobs no longer attack players getting dragged, hopefully to prevent accidental pkills -Ares
                if (member_array(this_player(), allies) != -1) {
                    return;
                }
                kill_ob(this_player(), 0);
                call_out("kill_msg", 1, this_player());
            } else
            if (stringp(tmp)) {
                call_other(this_object(), tmp);
            }
        }
    }
    if (norm_int) {
        temp += keys(norm_int);
        if (charmed_int) {
            temp += keys(charmed_int);
        }
        if (offend_int) {
            temp += keys(offend_int);
        }
        temp = distinct_array(temp);
        for (i = 0; i < sizeof(temp); i++) {
            add_action("check_action", temp[i], 1);
        }
    }
}

void add_attacker(object newob)
{
    object* allies = ({});
    int i;
    if (!objectp(newob)) {
        return;
    }
    for (i = 0; i < sizeof(DONT_TARGET); i++) {
        if (!objectp(find_player(DONT_TARGET[i]))) {
            continue;
        }
        allies += ({ find_player(DONT_TARGET[i]) });
    }
    if (member_array(newob, allies) != -1) {
        return;
    }

    ::add_attacker(newob);
}
