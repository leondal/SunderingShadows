#include <std.h>
#include <daemons.h>
#include "/d/islands/argentrock/argabbr.h"

inherit MONSTER;

object* names = ({}), * vortices = ({});
int count, flag;

void create()
{
    object obj;
    int i;
    ::create();
    set_name("batlin the mad mage");
    set_id(({ "man", "batlin", "mage", "mad mage", "batlin the mad mage" }));
    set_short("%^RESET%^%^CYAN%^Batlin the %^CYAN%^M%^RED%^a%^CYAN%^d M%^RED%^a%^CYAN%^g%^CYAN%^e%^RESET%^");
    set_long("This old mage has very long greyish beard and moustache. His whiskers cover almost half of his face. Two black eyes shine with wisdom and knowledge. Yet, his movement does not seem to be hindered by his age. Effusions of magical energy diffuse out of his body. Concentrating on his experiments, he is ignoring everything else in the room. He is a loyal follower of the demon princes. He has contributed his whole life to the demon princes. In return he is gifted the great knowledge in demonic magic and spells which differs a great deal from the nature of existing magic of the known realms.");
    set_gender("male");
    set_race("human");
    set_body_type("humanoid");

    set_alignment(8);
    set("aggressive", 2);
    set_size(2);

    set_class("mage");
    set_hd(68, 8);
    set_guild_level("mage", 68);

    set_overall_ac(-70);

    set_stats("intelligence", 30);
    set_stats("wisdom", 26);
    set_stats("strength", 26);
    set_stats("charisma", 12);
    set_stats("dexterity", 16);
    set_stats("constitution", 24);

    set_new_exp(60, "boss");
    set_mob_magic_resistance("high");

    set_property("spell damage resistance", 10);
    set_property("no death", 1);
    set_property("magic", 1);
    set_property("no animate", 1);
    set_property("no steal", 1);
    set_property("no bow", 1);
    set_property("weapon resistance", 3);
    //set_property("cast and attack", 1);
    set_property("function and attack", 1);
    set_monster_feats(({
      "spell penetration","greater spell penetration"
    }));

    set_max_hp(5500);
    set_hp(query_max_hp());

    set_emotes(2,
               ({ "%^MAGENTA%^Batlin says%^RESET%^: Where did I put my spellbook?",
                  "%^MAGENTA%^Batlin says%^RESET%^: I need to gather more components.",
                  "%^MAGENTA%^Batlin says%^RESET%^: One wormheart, some bloodmoss ...",
                  "%^MAGENTA%^Batlin says%^RESET%^: Where is that spider web?",
                  "%^MAGENTA%^Batlin says%^RESET%^: I can use some corpses again.",
                  "%^MAGENTA%^Batlin says%^RESET%^: Better lock up the cells ...",
                  "%^MAGENTA%^Batlin says%^RESET%^: Black pearl is hard to find!" }), 0);
    add_money("gold", 50000 + random(10000));

    set_funcs(({ "daemonic_surprise",
                 "mind_blast",
                 "energy_strike" }));

    set_func_chance(30);

    set_spells(({ "mind fog",
                  "globe of invulnerability",
                  "typhoon",
                  "weird",
                  "waves of exhaustion",
                  "prismatic burst",
                  "sunburst",
                  "sleet storm",
		  "greater dispel magic" })); //mad mage should be smart enough to dispel -Ts

    set_spell_chance(90);

    obj = new(OBJ + "elemental_staff")->move(TO);
    command("wield staff");
    obj = new("/d/islands/argentrock/obj/robes");
    obj->move(TO);
    command("wear robe");
    obj = new(OBJ + "obsidian_ring");
    obj->move(TO);
    obj->set_property("monsterweapon", 1);
    command("wear ring");

    for (i = 0; i < random(15); i++) {
        obj = new("/d/magic/scroll");
        obj->set_spell(9);
        obj->move(TO);
    }

    names = ({});
    count = 0;
}

int set_paralyzed(int num, string str)
{
    return 0;
}

int set_tripped(int num, string str)
{
    return 0;
}

void heart_beat()
{
    object* live = ({});
    int i;
    ::heart_beat();
    if (!objectp(TO)) {
        return;
    }
    if (!objectp(ETO)) {
        return;
    }
    if (!flag) {
        if (sizeof(TO->query_attackers())) {
            flag = 1;
            live = all_living(ETO);
            live = filter_array(live, "is_non_immortal", FILTERS_D);
            if (!sizeof(names)) {
                names = ({});
            }
            names -= ({ 0 });
            for (i = 0, sizeof(live) > 0; i < sizeof(live); i++) {
                if (!objectp(live[i])) {
                    continue;
                }
                TO->kill_ob(live[i], 0);
                if (live[i]->is_merc()) {
                    live[i]->say("Fuck this shit, I'm out.");
                    live[i]->force_me("emote drops a smokebomb and disappears.");
                    live[i]->fire_me();
                }
                if ((member_array(live[i], names) == -1)) {
                    if (interactive(live[i]) || live[i]->is_merc()) {
                        //call_out("vortex",1,vic);
                        vortex(live[i]);
                        names += ({ live[i] });
                        names = distinct_array(names);
                    }
                }
            }
        }
    }
    if (query_hp() < query_max_hp()) {
        TO->do_damage("torso", -roll_dice(10, 20));
    }
    if (query_hp() < 900) {
        if (count < 0) {
            count = 12;
            set_func_chance(0);
            call_out("imbalance", 0.1);
            set_func_chance(25);
        }
        count--;
        return;
    }
    TO->check_them();
}

void check_them()
{
    object* stuff;
    int i, num, said;
    if (!objectp(TO)) {
        return;
    }
    if (!objectp(ETO)) {
        return;
    }
    stuff = all_living(ETO);
    stuff -= ({ TO });
    num = sizeof(stuff);
    said = 0;
    if (sizeof(TO->query_attackers())) {
        for (i = 0; i < num; i++) {
            if (!objectp(stuff[i])) {
                continue;
            }
            if (!userp(stuff[i]) && !interactive(stuff[i]) && !stuff[i]->is_merc()) {
                if (!said) {
                    command("say DIE! You brainless creature, your presence here is a mistake!");
                    tell_room(ETO, "%^BOLD%^BLUE%^Batlin chants a short phrase.");
                }
                said = 1;
                stuff[i]->die();
            }
        }
    }else {
        if (base_name(ETO) == PATH + "arghouse11") {
            if (member_array("door", ETO->query_exits()) == -1) {
                tell_room(ETO, "%^BLUE%^The door reappears as the battle " +
                          "ceases.");
                ETO->reset();
            }
            names = ({});
            flag = 0;
            for (i = 0, sizeof(vortices) > 0; i < sizeof(vortices); i++) {
                if (!objectp(vortices[i])) {
                    continue;
                }
                vortices[i]->remove();
            }
            vortices -= ({ 0 });
            return;
        }
    }
}

void vortex(object vic)
{
    object* exits, obj;
    if (!objectp(vic)) {
        return;
    }
    if (!objectp(TO)) {
        return;
    }
    if (!objectp(ETO)) {
        return;
    }
    names += ({ vic });
    distinct_array(names);
    if (!present(vic, ETO)) {
        return;
    }
    tell_room(ETO, "%^BOLD%^CYAN%^Batlin gathers some reagents and chants " +
              "a short phase.");
    tell_room(ETO, "%^B_RED%^CYAN%^A large black death vortex rises from " +
              "nowhere and drives towards " + vic->query_cap_name() + "!!", vic);
    tell_object(vic, "%^B_RED%^CYAN%^A large black death vortex rises " +
                "from nowhere and drives towards you!!");
    obj = new(OBJ + "vortex");
    vortices += ({ obj });
    obj->set_target(vic);
    obj->move(ETO);
    if (base_name(ETO) == PATH + "arghouse11") {
        exits = ETO->query_exits();
        if (!sizeof(exits)) {
            return;
        }
        if (member_array("door", exits) != -1) {
            tell_object(ETO, "%^RED%^Batlin raises his hands and completes a " +
                        "circular motion. The door behind you disappears!");
            command("say Now fight for your life!");
            ETO->remove_exit("door");
        }
    }
}

void daemonic_surprise(object vic)
{
    if (!objectp(vic)) {
        return;
    }
    if (!objectp(TO)) {
        return;
    }
    if (!objectp(ETO)) {
        return;
    }
    tell_room(ETO, "%^BOLD%^CYAN%^Batlin gathers some reagents and chants " +
              "a short phase.");
    tell_room(ETO, "%^RED%^As he finishes the chant, a red shadowy thing " +
              "flashes across your eyes.");
    if (!vic->will_save(20 + roll_dice(1, 25))) {
        tell_object(vic, "%^RED%^You suddenly feel tremedous pain and " +
                    "scream! An image of a demon appears and vanishes.");
        tell_room(ETO, "%^RED%^" + vic->query_cap_name() + " suddenly screams " +
                  "in pain!", vic);
        vic->do_damage(vic->return_target_limb(), roll_dice(5, 20));
    }
}

void energy_strike(object vic)
{
    if (!objectp(vic)) {
        return;
    }
    if (!objectp(TO)) {
        return;
    }
    if (!objectp(ETO)) {
        return;
    }
    tell_room(ETO, "%^BOLD%^CYAN%^Batlin gathers some reagents and chants " +
              "a short phase.");
    tell_room(ETO, "%^BLUE%^As he finishes the chant, you sense tremedous " +
              "flow of energy in the room.");
    if (!vic->will_save(30 + roll_dice(1, 20))) {
        tell_object(vic, "%^BLUE%^A bundle of energy strikes you like a " +
                    "sword. You scream in pain!");
        tell_room(ETO, "%^BLUE%^" + vic->query_cap_name() + " suddenly screams " +
                  "in pain!", vic);
        vic->do_damage(vic->return_target_limb(), roll_dice(5, 20));
    }
}

void mind_blast(object vic)
{
    if (!objectp(vic)) {
        return;
    }
    if (!objectp(TO)) {
        return;
    }
    if (!objectp(ETO)) {
        return;
    }
    tell_room(ETO, "%^BOLD%^CYAN%^Batlin gathers some reagents and chants " +
              "a short phase.");
    tell_room(ETO, "%^CYAN%^Batlin concentrates for a moment.");
    if (!vic->will_save(30 + roll_dice(1, 20))) {
        tell_object(vic, "%^CYAN%^You feel a strange assult on your brain, " +
                    "an awfully strong power grows in your head, you start to lose " +
                    "control of your mind and your body!");
        tell_room(ETO, "%^CYAN%^" + vic->query_cap_name() + " suddenly looks " +
                  "odd, " + vic->query_possessive() + "+ face looks twisted, some " +
                  "expression of extreme pain appears.", vic);
        vic->do_damage(vic->return_target_limb(), roll_dice(4, 20));
        vic->set_paralyzed(random(20) + 10, "%^CYAN%^Your mind is in chaos.");
    }
}

void imbalance()
{
    int i, all;
    object* living;
    if (!objectp(TO)) {
        return;
    }
    if (!objectp(ETO)) {
        return;
    }
    living = all_living(ETO);
    living -= ({ TO });
    all = sizeof(living);
    command("say You are good so far.");
    command("say Now let fate decide who the winner is!");
    command("say Prepare yourself ...");
    tell_room(ETO, "%^BOLD%^CYAN%^Batlin gathers some reagents and chants " +
              "a short phase.\n%^RED%^He chants the spell of imbalance!\n\n");
    call_out("do_it", 5);
    for (i = 0; i < all; i++) {
        living[i]->cease_all_attacks();
        living[i]->set_paralyzed(5, "For some reason you cannot move!");
    }
}

void do_it()
{
    int i, all;
    object* living;
    if (!objectp(TO)) {
        return;
    }
    if (!objectp(ETO)) {
        return;
    }
    living = all_living(ETO);
    living -= ({ TO });
    all = sizeof(living);
    tell_room(ETO, "%^B_RED%^ORANGE%^The room starts shaking voilently.\n" +
              "The air around you seems to vaporize.\nThe floor opens.\nYour " +
              "sight begins to blur.\n\n\n...\n\n... ...\n\n... ... ...\n\n\n\n");
    message("broadcast", "%^RED%^A tremble passes from beneath your feet " +
            "to your body as you hear a loud sound of an earthquake coming from a " +
            "distance.", users(), all_living(ETO));

    for (i = 0; i < all; i++) {
        if (!objectp(living[i])) {
            continue;
        }
        if (!userp(living[i]) && !interactive(living[i]) && !living[i]->is_merc()) {
            living[i]->die();
        }
        if (wizardp(living[i])) {
            continue;
        }
        if (avatarp(living[i])) {
            continue;
        }
        living[i]->add_attacker(TO);
        living[i]->continue_attack();
        switch (random(50)) {
        case 0:
            tell_object(living[i], "%^BOLD%^RED%^Your god has abandoned " +
                        "you. Your soul has been taken over to the demon princes.\n\n" +
                        "%^BOLD%^CYAN%^An expression of triumph across Batlin's " +
                        "face.\n");
            living[i]->add_attacker(TO);
            living[i]->set_hp(-10);
            living[i]->do_damage("torso", 100);
            living[i]->continue_attack();
            break;

        case 1..20:
            tell_object(living[i], "%^BOLD%^BLUE%^Your god decided to " +
                        "assist you in your fight with the demonic power.\n\n" +
                        "Batlin grins evilly.");
            living[i]->set_hp(1);
            living[i]->do_damage("torso", -19);
            living[i]->add_attacker(TO);
            living[i]->continue_attack();
            break;

        case 21..49:
            tell_object(living[i], "%^BOLD%^CYAN%^Your prayers go unanswered" +
                        ".\n\n%^BOLD%^CYAN%^Batlin grins evilly.");
            living[i]->set_hp(1);
            living[i]->do_damage("torso", -4);
            living[i]->add_attacker(TO);
            living[i]->continue_attack();
            break;

        case 50:
            tell_object(living[i], "%^GREEN%^Your god trusted in you and " +
                        "helps you in resisting the pagan power!\n\n" +
                        "%^BOLD%^CYAN%^Batlin seems disappointed.\n");
            break;
        }
    }
}

/*
   void add_attacker(object newob)
   {
    kill_ob(newob,1);
    ::add_attacker(newob);
   }*/

private start_event()
{
    int power;//%
    power = 15 + random(5);
    WORLD_EVENTS_D->kill_event("Pacified archmage of Argentrock");
    WORLD_EVENTS_D->inject_event((["Pacified archmage of Argentrock" : (["start message" : "
%^CYAN%^Seas %^BOLD%^t%^RESET%^%^CYAN%^r%^BOLD%^e%^RESET%^%^CYAN%^m%^BOLD%^b%^RESET%^%^CYAN%^l%^BOLD%^e %^RESET%^%^CYAN%^as %^BOLD%^surge %^RESET%^%^CYAN%^of %^BOLD%^%^MAGENTA%^power %^RESET%^%^CYAN%^disperses from %^BOLD%^Argentrock!%^RESET%^
%^CYAN%^For the next two hours all experience gained will award an additional %^BOLD%^%^CYAN%^" + power + "%%^RESET%^%^CYAN%^!",
                                                                         "event type" : "exp bonus", "length" : 120, "notification" : power + "% Bonus Exp",
                                                                         "event name" : "Pacified archmage of Argentrock", "modifier" : power, "announce" : 1, "announce to" : "world" ]), ])
                                 );
}

void die(object ob)
{
    object* attackers;
    string qst;
    object* stuff;
    int i, num;
    if (!objectp(TO)) {
        return;
    }
    if (!objectp(ETO)) {
        return;
    }
    stuff = all_inventory(ETO);
    num = sizeof(stuff);

    qst = "%^BOLD%^%^RED%^Won %^RESET%^%^RED%^a %^BOLD%^%^CYAN%^fair %^RESET%^%^CYAN%^challenge %^RED%^against %^BOLD%^B%^CYAN%^a%^RED%^tl%^CYAN%^i%^RED%^n%^RESET%^";

    tell_room(ETO, "%^MAGENTA%^Batlin says%^RESET%^: Do you think you have won?! Do you dare to assume you are better than me?!");

    attackers = TO->query_attackers();
    if (sizeof(attackers) == 1) {
        tell_room(ETO, "Batlin chuckles...");
        tell_room(ETO, "%^MAGENTA%^Batlin whispers%^RESET%^: Well, you are better.... Congratulations...");
        tell_room(ETO, "%^MAGENTA%^Batlin whispers%^RESET%^: Be cursed forever...");
        start_event();
        if (objectp(attackers[0])) {
            attackers[0]->set_mini_quest(qst, 10000000, qst);
        }
    } else {
        tell_room(ETO, "Batlin chuckles with a smug grin...");
        tell_room(ETO, "%^MAGENTA%^Batlin whispers%^RESET%^: Picking on an old man in group... ");
        tell_room(ETO, "%^MAGENTA%^Batlin whispers%^RESET%^: You are worthless trash. You are cursed forever!");
    }

    if (!random(5)) {
        new("/d/common/obj/misc/tools/portable_lab_case.c")->move(TO);
    }

    //daemon princess ring phrase here
    command("unwear ring");
    command("offer ring");
    tell_room(ETO, "%^CYAN%^As Batlin vanishes away in a black oily mist, the magic in the room dissipates.");

    if (base_name(ETO) == PATH + "arghouse11") {
        tell_room(ETO, "%^BOLD%^RED%^The door reappears.");
        ETO->reset();
    }

    for (i = 0; i < num; i++) {
        if ((string)stuff[i]->query_name() == "black death vortex") {
            tell_room(ETO, "%^BOLD%^BLUE%^The vortex lost its power and " +
                      "vanishes.");
            stuff[i]->remove();
        }
    }
    ::die(ob);
    return;
}
