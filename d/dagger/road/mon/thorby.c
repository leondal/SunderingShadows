//set him to moving and changed his room because of too many people killing him
//repeatedly (also made him not repop as fast in the monsters_d.c)  *Styx* 3/23/02

#include "/d/dagger/road/short.h"

inherit "/d/dagger/road/mon/wonder.c";
object ob;
int timer;

int do_stealing();

void create()
{
    ::create();
    set_no_clean(1);
    timer = 0;
    set_name("Thorby");
    set_short("Thorby the master thief");
    set_long(
        "Thorby is a small human man, dressed well in studded leather coverings.  He is handsome, with dark hair under his small cap and dark soulful eyes, but what catches your eye the most is the sack on his belt, filled with gold, and the strange daggers in his hands."
        );
    set_id(({ "thorby", "Thorby", "thief", "master", "master thief" }));
    set_heart_beat(1);
    set_mob_magic_resistance("average");
    set_exp(15000);
    set_race("human");
    set_body_type("human");
    set_hd(40, 0);
    set_max_hp(1000);
    set_hp(TO->query_max_hp());
    set_class("thief");
    set_mlevel("thief", 40);
    set_guild_level("thief", 40);
    set_alignment(5);
    add_search_path("/cmds/thief");
    set_property("full attacks", 1);
    set_scrambling(1);
    set_skill("stealth", 40);
    set_skill("athletics", 40);
    set_skill("thievery", 40);
    set_stats("strength", 24);
    set_stats("constitution", 16);
    set_stats("dexterity", 24);
    set_stats("intelligence", 15);
    set_stats("charisma", 12);
    set_stats("wisdom", 13);
    set_property("add kits", 50);
    set_monster_feats(({
        "combat reflexes",
        "mobility",
        "evasion",
        "tools of the trade",
        "scramble",
        "spring attack",
        "ambidexterity",
        "two weapon fighting",
        "unassailable parry",
        "whirl",
        "improved whirl",
        "improved two weapon fighting",
        "weapon finesse",
    }));

    ob = new("/d/dagger/cave2/obj/blacksword.c");
    if (random(5)) {
        ob->set_property("monsterweapon", 1);
    }
    ob->move(TO);
    ob = new("/d/attaya/obj/screamer.c");
    ob->set_property("monsterweapon", 1);
    ob->move(TO);
    ob = new("/d/attaya/obj/screamer.c");
    ob->set_property("monsterweapon", 1);
    ob->move(TO);
    ob = new("/d/tharis/obj/wrist_sheath.c");
    ob->set_property("monsterweapon", 1);
    ob->move(TO);
    ob = new("/d/tharis/obj/bpowder.c");
    ob->set_property("monsterweapon", 1);
    ob->move(TO);
    ob = new("/d/laerad/obj/bracers6.c");
    if (random(100)) {
        ob->set_property("monsterweapon", 1);
    }
    ob->move(TO);
    new("/d/dagger/road/obj/studded+3.c")->move(TO);

    command("put dagger in sheath");
    command("wear bracers");
    command("wear studded");
    command("wield sword in left hand");
    command("wield dagger in right hand");
    command("wear sheaths");
    set_funcs(({ "special_fcn", "whirlit" }));
    set_func_chance(80);
    set_speed(80);
    set_moving(1);
}

void whirlit()
{
    TO->force_me("whirl");
}

void heart_beat()
{
    ::heart_beat();

    timer++;
    if (timer > 25) {
        timer = 0;
        if (!query_invis()) {
            if (query_attackers() == ({})) {
                set_invis();
            }
        }
        do_stealing();
    }
}

int special_fcn(object targ)
{
    int num;

    num = random(2);
    switch (num) {
    case 0:
        if (targ->query_property("powdered")) {
            command("growl " + targ->query_name());
            command("say Nasty stuff, that powder, eh?");
            tell_object(targ, "%^RED%^Thorby jumps and spins, kicking you in the head!");
            tell_room(ETO, "%^RED%^Thorby jumps into the air, spinning and kicking " + targ->query_cap_name() + " in the head!", ({ targ }));
            targ->do_damage("head", roll_dice(8, 8));
        } else {
            command("cackle");
            command("Try this on for size!");
            command("toss powder at " + targ->query_name());
        }
        return 1;

        break;

    case 1:
        if (!random(10)) {
            command("say Let's see how you like THIS!");
            TO->cease_all_attacks();
            command("stab " + targ->query_name());
        } else {
            tell_object(targ, "Thorby dives at you with his sword, driving it deep into your shoulder!");
            tell_room(ETO, "Thorby dives at " + targ->query_cap_name() + " driving his sword deep into " + targ->query_possessive() + " shoulder!", ({ targ }));
            targ->do_damage("torso", roll_dice(10, 10));
            command("say DIE DAMN YOU!");
        }
        return 1;

        break;
    }
}

int do_stealing()
{
    object* people, * list, person, * inven, item;
    string* names, name;
    int i;
    people = ({});
    list = ({});
    inven = ({});

    if (!objectp(TO)) {
        return 1;
    }
    if (!objectp(ETO)) {
        return 1;
    }
    if (TO->query_current_attacker()) {
        return 1;
    }
    people = all_living(ETO);
    for (i = 0; i < sizeof(people); i++) {
        if (!objectp(people[i])) {
            continue;
        }
        if (people[i] == TO || avatarp(people[i])) {
            continue;
        }else {
            list += ({ people[i] });
        }
        continue;
    }

    if (!pointerp(list) || !sizeof(list)) {
        return 2;
    }
    person = list[random(sizeof(list))];
    if (!present(person, ETO)) {
        return 1;
    }
    inven = ({});
    inven = all_inventory(person);
    list = ({});
    if (!pointerp(inven) || !sizeof(inven)) {
        return 1;
    }
    for (i = 0; i < sizeof(inven); i++) {
        if (!objectp(inven[i]) || !stringp(inven[i]->query_short())) {
            continue;
        }
        if (inven[i]->query_worn() || inven[i]->query_wielded()) {
            continue;
        }
        list += ({ inven[i] });
        continue;
    }
    if (random(2) || !sizeof(list)) {
        command("pp " + person->query_name());
    }else {
        item = list[random(sizeof(list))];
        names = item->query_id();
        name = names[0];
        command("steal " + name + " from " + person->query_name());
    }
    return 1;
}

int kill_ob(object victim, int which)
{
    if (query_invis()) {
        set_invis();
    }
    return ::kill_ob(victim, which);
}

void die(object ob)
{
    object targ;

    targ = TO->query_current_attacker();
    tell_room(ETO, "Thorby falls to his knees as you strike the fatal blow.\n");
    command("say Good show...  you are the better warrior.");
    if (objectp(targ)) {
        tell_room(ETO, "Thorby suddenly reaches up and grabs " + targ->query_cap_name() + " by the throat!", ({ targ }));
    }
    if (objectp(targ)) {
        tell_object(targ, "Thorby reaches up and grabs you by the throat!");
    }
    if (objectp(targ)) {
        command("whisper " + targ->query_name() + " you have won, but we shall meet again!!!");
    }
    command("emote coughs up blood");
    command("cackle");
    ::die(ob);
}
