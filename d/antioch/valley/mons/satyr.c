//updating the old files to use the new exp functions for standardized
//exp values. ~Circe~ 2/4/13

#include <std.h>
#include "../valley.h"
inherit V_WANDER;

void seduce_woman(object targ);

void create()
{
    ::create();
    set_name("satyr");
    set_id(({ "satyr", "monster", "faun", }));
    set_short("A mischevious faun");
    set_long(
        "This is a rather well built satyr. He is half-goat, half-man," +
        " fur covers from his waist to his feet, which actually end in" +
        " hooves. His upper body is very well toned, his arms and chest" +
        " are thick with muscles and his abs are clearly defined. His" +
        " hair is long and flowing with a little curl to it, a lovely" +
        " chestnut brown. He has a well trimmed goatee. His eyes are a" +
        " warm chocolate and his smile is pleasant. If it weren't for" +
        " those two horns on his head he'd look almost angelic."
        );
    set_gender("male");
    set_race("faun");
    set_body_type("human");
    set_hd(15, 5);
    set_max_level(20);
    set_overall_ac(5);
    set_alignment(8);
    set_max_hp(random(100) + 75);
    set_hp(query_max_hp());
    set_mob_magic_resistance("average");
    set_property("swarm", 1);
    set_attack_limbs(({ "right hand", "left hand" }));
    set_attacks_num(2);
    set_base_damage_type("slashing");
    set_damage(1, 8);
    set_level(15);
    set_class("bard");
    set_mlevel("bard", 15);
    set_stats("intelligence", 18);
    set_stats("charisma", 20);
    set_spells(({
        "sleep",
        "color spray",
        "prismatic spray",
    }));
    set_spell_chance(30);
//	set_exp(8000);
    set_new_exp(15, "normal");
    add_money("gold", random(500));
    if (!random(5)) {
        new(OBJ + "pipes")->move(TO);
    }
    set_funcs(({ "charm" }));
    set_func_chance(20);
    set_emotes(4, ({ "The satyr plays a lovely melody on his pipes." }), 0);
}

void charm(object targ)
{
    if ((string)targ->query_gender() == "female") {
        if (!"/daemon/saving_throw_d.c"->will_save(targ, -13)) {
            tell_object(targ, "%^RED%^%^BOLD%^The satyr graces you" +
                        " with a charming smile and you can't help but return it.");
            tell_room(ETO, "%^RED%^%^BOLD%^" + targ->query_cap_name() + "" +
                      " smiles at the satyr and seems oblivious to the world.", targ);
            targ->set_paralyzed(200, "You can't seem to focus on" +
                                " anything but the satyr's charming smile.");
            return 1;
        }else {
            tell_object(targ, "%^RED%^The satyr tries to win you over" +
                        " with his charm, but you're not fooled.");
            return 1;
        }
    }
    return;
}

void init()
{
    ::init();
    if (interactive(TP) && (string)TP->query_gender() == "female") {
        seduce_woman(TP);
    }
}

void seduce_woman(object targ)
{
    if ((mixed*)TO->query_attackers() != ({ })) {
        return;
    }

    if (targ->query_stats("charisma") < 16) {
        return;
    }

    if (targ->query_invis()) {
        return;
    }

    tell_object(targ, "The satyr graces you with a very charming" +
                " smile.");
    tell_room(ETO, "The satyr smiles at " + targ->query_cap_name() + ".", targ);
    if (!"/daemon/saving_throw_d.c"->will_save(targ, -13)) {
        tell_object(targ, "The satyr reaches out and takes your" +
                    " hand, very gingerly he kisses the inside of your wrist" +
                    " and then smiles up into your eyes.");
        tell_room(ETO, "The satyr reaches out and takes " + targ->query_cap_name() + "'s" +
                  " hand, he kisses the inside of her wrist gently and then" +
                  " smiles up at her.", targ);
        targ->force_me("drop all");
        TO->force_me("get all");
        tell_object(targ, "%^BOLD%^%^MAGENTA%^You give the satyr anything he wants.");
        targ->set_paralyzed(random(50) + 100, "You don't want to leave the" +
                            " satyr's side.");
        return 1;
    }else {
        tell_object(targ, "The satyr reaches out to take your hand" +
                    " but you pull away from him and he looks deeply sorrowful.");
        tell_room(ETO, "The satyr reaches out to take " + targ->query_cap_name() + "'s" +
                  " hand, but she pulls away from him.", targ);
        return 1;
    }
    return;
}
