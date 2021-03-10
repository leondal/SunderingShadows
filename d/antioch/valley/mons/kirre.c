//updating the old files to use the new exp functions for standardized
//exp values. ~Circe~ 2/4/13
//Changed over to psion from a mage - Cythera 8/05

#include <std.h>
#include "../valley.h"
inherit WEAPONLESS;

void create()
{
    object ob;
    ::create();
    set_name("kirre");
    set_id(({ "kirre", "monster", "tiger", "animal"}));
    set_short("A stealthy kirre");
    set_long(
        "At first glance, this eight foot long cat looks like a" +
        " large tiger. The stripes are similar, but the colors are" +
        " wrong, this cat has brown and gray stripes. %^YELLOW%^Yellow%^RESET%^%^CYAN%^" +
        " eyes stare at you watchfully. A %^RED%^red%^CYAN%^ tongue" +
        " rests between sharp canine teeth. Two black horns are also" +
        " protruding from its head. The cat's tail switches back" +
        " and forth slowly and some deadly looking barbs are on it." +
        " The kirre flexes her front paws, extending her razor" +
        " sharp claws. In fact, the kirre has eight sets of" +
        " razor sharp claws..."
        );
    set_gender("female");
    set_race("cat");
    set_body_type("quadruped");
    set_hd(20, 8);
    set_max_level(25);
    set_overall_ac(3);
    set_size(3);
    set_alignment(8);
    set_max_hp(random(200) + 200);
    set_hp(query_max_hp());
    set("aggressive", 25);
    set_property("swarm", 1);
    set_property("no bows", 1);
    set_level(20);
    set_class("fighter");
    set_mlevel("fighter", 20);
    set_class("psion");
    set_mlevel("psion", 20);
    set_guild_level("psion", 20);
    add_search_path("/cmds/psion");
    add_search_path("/cmds/psionics");
    add_limb("tail", "torso", 0, 0, 0);
    add_limb("teeth", "head", 0, 0, 0);
    add_limb("left paw", "torso", 0, 0, 0);
    add_limb("right paw", "torso", 0, 0, 0);
    add_limb("horns", "head", 0, 0, 0);
    add_limb("tail", "torso", 0, 0, 0);
    set_attack_limbs(({ "right forepaw", "left forepaw", "teeth", "left paw", "right paw", "tail", "horns" }));
    set_attacks_num(7);
    set_base_damage_type("slashing");
    set_damage(1, 4);
//	set_exp(19000);
    set_new_exp(20, "normal");
    set_hit_funcs(([
                       "tail" : (: TO, "barbs" :),
                       "mouth" : (: TO, "bite" :),
                       "horns" : (: TO, "horn" :),
                   ]));
    set_spell_chance(40);
    set_spells(({
        "mind thrust",
        "energry bolt",
        "ultrablast",
        "power leech"
    }));
    set_property("swarm", 1);
    set_property("aggressive", 18);
    set_mob_magic_resistance("average");
    set_property("no dominate", 1);
    set_funcs(({ "blast", "crush" }));
    set_func_chance(40);
    add_money("gold", random(1000) + 50);
    set_emotes(10, ({
        "The kirre growls loudly.",
        "The kirre swishes her tail back and forth.",
        "The kirre gets ready to pounce!",
    }), 1);
    if (!random(15)) {
        ob = new("/d/common/obj/brewing/herb_special_inherit");
        ob->set_herb_name("fur");
        ob->move(TO);
    }
}

int barbs(object targ)
{
    targ->do_damage("torso", random(2) + 1);
    return 1;
}

int horn(object targ)
{
    targ->do_damage("torso", random(4) + 1);
    return 1;
}

int bite(object targ)
{
    targ->do_damage("torso", random(2) + 1);
}

void blast(object targ)
{
    int roll, intx;
    roll = random(20);
    intx = targ->query_stats("intelligence");

    if (roll > intx) {
        tell_object(targ, "%^BOLD%^%^MAGENTA%^The kirre blasts" +
                    " your mind with a thought!");
        tell_room(ETO, "" + targ->query_cap_name() + " looks a little" +
                  " dazed.", targ);
        targ->do_damage("torso", random(20) + 6);
        targ->set_paralyzed(25, "You are still reeling from the blast.");
    }else {
        tell_object(targ, "%^BOLD%^%^MAGENTA%^The kirre attempts" +
                    " to psionically blast your mind but you resist!");
    }
}

void crush(object targ)
{
    int roll, intx;
    roll = random(20);
    intx = targ->query_stats("intelligence");

    if (roll > intx - 5) {
        tell_object(targ, "%^YELLOW%^The kirre growls deeply and" +
                    " you feel your mind being pulverized by a psychic crush.");
        tell_room(ETO, "The kirre growls deeply and " + targ->query_cap_name() + "" +
                  " screams in pain.", targ);
        targ->do_damage("torso", random(30) + 10);
        targ->set_paralyzed(50, "You are too stunned!");
    }else {
        tell_object(targ, "%^YELLOW%^The kirre growls deeply and" +
                    " you feel her trying to blast your mind with a psychic" +
                    " crush that you barely manage to resist.");
        tell_room(ETO, "The kirre growls deeply and " + targ->query_cap_name() + "" +
                  " frowns in concentration and begins to sweat.", targ);
    }
}
