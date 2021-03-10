//updating the old files to use the new exp functions for standardized
//exp values. ~Circe~ 2/4/13
//Added Leaf Fan to them - Cythera 4/05

#include <std.h>
#include <daemons.h>
#include "../valley.h"
inherit V_WANDER;

string str, type, color;
void seduce_man(object targ);

void create()
{
    object obj;
    ::create();
    set_name("nymph");
    set_id(({ "monster", "nymph" }));
    set_short("A beautiful nymph");
    switch (random(13)) {
    case 0:
        type = "blonde";
        break;

    case 1:
        type = "black";
        break;

    case 2:
        type = "red";
        break;

    case 3:
        type = "brown";
        break;

    case 4:
        type = "strawberry blonde";
        break;

    case 5:
        type = "auburn";
        break;

    case 6:
        type = "white";
        break;

    case 7:
        type = "sandy blonde";
        break;

    case 8:
        type = "silver";
        break;

    case 9:
        type = "sky-blue";
        break;

    case 10:
        type = "emerald green";
        break;

    case 11:
        type = "ebony";
        break;

    case 12:
        type = "golden";
        break;
    }
    switch (random(13)) {
    case 0:
        color = "blue";
        break;

    case 1:
        color = "green";
        break;

    case 2:
        color = "brown";
        break;

    case 3:
        color = "black";
        break;

    case 4:
        color = "hazel";
        break;

    case 5:
        color = "purple";
        break;

    case 6:
        color = "yellow";
        break;

    case 7:
        color = "violet";
        break;

    case 8:
        color = "gold";
        break;

    case 9:
        color = "azure";
        break;

    case 10:
        color = "chocolate";
        break;

    case 11:
        color = "emerald";
        break;

    case 12:
        color = "sapphire";
        break;
    }

    set_long(
        "There is truly no way to describe this lovely creature in" +
        " words or thoughts. She's the incarnation of beauty, a young" +
        " woman with a perfect hour glass figure, thick " + type + " hair," +
        " a perfect complexion. Her smile is dazzling, showing" +
        " perfect teeth behind her full, red lips. Her eyes seem" +
        " caring and are a lovely shade of " + color + ". The breeze" +
        " blows the most wonderful scent to you. From her stance you" +
        " can tell she is graceful and charming. She is the perfect" +
        " woman."
        );
    set_gender("female");
    set_race("nymph");
    set_body_type("human");
    set_hd(20, 4);
    set_max_level(23);
    set_size(2);
    set_max_hp(random(100) + 100);
    set_hp(query_max_hp());
    set_alignment(7);
    set_overall_ac(6);
    set_level(18);
    set_stats("charisma", 25);
    set_property("swarm", 1);
    set("aggressive", 10);
    set_mob_magic_resistance("average");
    set_class("fighter");
    set_mlevel("fighter", 20);
    set_property("full attacks", 1);
    //set_attack_limbs(({"right hand","left hand"}));
    //set_attacks_num(2);
    //set_base_damage_type("slashing");
    //set_damage(1,10);
    if (query_night() == 1) {
        if (!random(5)) {
            obj = new(OBJ + "nymph_dress");
            obj->set_property("monsterweapon", 1);
            obj->move(TO);
            command("wear dress");
        }else {
            new(OBJ + "flower_dress")->move(TO);
            command("wear dress");
        }
    }else {
        if (!random(5)) {
            obj = new(OBJ + "nymph_dress2");
            obj->set_property("monsterweapon", 1);
            obj->move(TO);
            command("wear dress");
        }else {
            new(OBJ + "flower_dress")->move(TO);
            command("wear dress");
        }
    }
    obj = new(OBJ + "leaffan");
    if (random(3)) {
        obj->set_property("monsterweapon", 1);
    }
    obj->move(TO);
    command("wield fan");
    set_funcs(({ "disrobe" }));
    set_func_chance(30);
    set_emotes(3, ({
        "The nymph giggles musically.",
        "The nymph bats her eyelashes at you.",
        "The nymph licks her lips and smiles.",
        "The nymph winks seductively.",
        "The nymph tickles you playfully.",
        "The nymph smiles teasingly.",
    }), 0);
//	set_exp(11000);
    set_new_exp(20, "normal");
}

void charm(object targ)
{
    if ((string)targ->query_gender() == "male") {
        if (!"/daemon/saving_throw_d.c"->fort_save(targ, -17)) {
            tell_object(targ, "%^BOLD%^%^RED%^The nymph smiles at" +
                        " you and your heart melts. How could you attack such" +
                        " a lovely creature?? She means you no harm!");
            tell_room(ETO, "%^BOLD%^%^RED%^The nymph smiles at" +
                      " " + targ->query_cap_name() + " and he gets a silly grin" +
                      " on his face.", targ);
            targ->force_me("drop all");
            targ->set_paralyzed(175, "You've been charmed by the nymph!");
            return 1;
        }else {
            tell_object(targ, "%^RED%^You aren't fooled by the" +
                        " nymph's charming demeanor.");
            return 1;
        }
    }
}

void disrobe(object targ)
{
    object ob;
    object* inv;
    int i;

    inv = all_living(ETO);

    if (!random(300)) {
        tell_room(ETO, "%^BOLD%^The nymph removes her clothes for" +
                  " a brief moment.\n");
        for (i = 0; i < sizeof(inv); i++) {
            if ((string)inv[i]->query_gender() == "male") {
                tell_object(inv[i], "%^BOLD%^%^MAGENTA%^Your heart starts" +
                            " pounding wildly at the lovely sight before you, you" +
                            " could never have imagined anything so perfect, so" +
                            " absolutely beautiful...\n\n%^RED%^You feel your heart" +
                            " explode in your chest.");
                inv[i]->do_damage("torso", 1000);
            }else {
                tell_object(inv[i], "Beautiful as the nymph is, you don't really" +
                            " care about seeing her naked.");
            }
        }
        return 1;
    }else {
        return 1;
    }
}

void init()
{
    object ob;

    ::init();
    if (ALIGN->is_evil(TP) && !TP->query_invis()) {
        kill_ob(TP, 1);
        return 1;
    }
    if (interactive(TP) && (string)TP->query_gender() == "male") {
        seduce_man(TP);
    }
}

void seduce_man(object targ)
{
    if ((mixed*)TO->query_attackers() != ({ })) {
        return;
    }

    if (targ->query_stats("charisma") < 15) {
        return;
    }

    if (targ->query_invis()) {
        return;
    }

    if ((int)targ->query_alignment() != 1 || (int)targ->query_alignment() != 7 || (int)targ->query_alignment() != 4) {
        return;
    }

    tell_object(targ, "The nymph smiles at you attractively and" +
                " puts her arms around your neck, playing with your hair.");
    tell_room(ETO, "The nymph smiles at " + targ->query_cap_name() + "" +
              " and puts her arms around his neck, playing with his hair.", targ);
    if (!"/daemon/saving_throw_d.c"->fort_save(targ, -17)) {
        tell_object(targ, "The nymph nibbles on your ear and pulls" +
                    " you closer, you can't resist this beautiful creature.");
        tell_room(ETO, "The nymph nibbles on " + targ->query_cap_name() + "'s" +
                  " ear and pulls him closer, he doesn't seem to be resisting.", targ);
        targ->force_me("drop all");
        TO->force_me("get all");
        tell_object(targ, "%^BOLD%^%^RED%^You shower the nymph with presents in" +
                    " an attempt to capture her heart.");
        targ->set_paralyzed(200, "You're not sure if the nymph would" +
                            " approve of you doing that.");
        return 1;
    }else {
        tell_object(targ, "The nymph tries to pull you closer to" +
                    " you and pouts as you resist her.");
        tell_room(ETO, "The nymph tries to pull " + targ->query_cap_name() + "" +
                  " closer to her and pouts as he seems to resist.", targ);
        return 1;
    }
}
