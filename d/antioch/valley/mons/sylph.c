//updating the old files to use the new exp functions for standardized
//exp values. ~Circe~ 2/4/13

#include <std.h>
#include "../valley.h"
inherit V_WANDER;

void create()
{
    ::create();
    set_name("sylph");
    set_id(({ "sylph", "monster" }));
    set_short("A whimsical sylph");
    set_long(
        "A very beautiful woman stands before you. Her hair is a" +
        " pale blue in color and falls down to her waist, it seems" +
        " to be constantly blown by the wind. The dress she is" +
        " wearing matches her hair and is rather daring, being almost" +
        " entirely see-through. She giggles and flutters her wings," +
        " which blows a light wind against your face."
        );
    set_gender("female");
    set_race("sylph");
    set_body_type("human");
    set_hd(10, 2);
    set_max_level(20);
    set_size(2);
    set_overall_ac(2);
    set_alignment(4);
    set_max_hp(random(25) + 50);
    set_hp(query_max_hp());
    set_property("swarm", 1);
    set_attack_limbs(({ "right hand" }));
    set_attacks_num(1);
    set_base_damage_type("slashing");
    set_damage(1, 6);
    set_mob_magic_resistance("average");
    set_level(15);
    set_class("mage");
    set_mlevel("mage", 7);
    set_stats("charisma", 20);
    set_stats("intelligence", 18);
    set_spells(({
        "acid arrow",
        "prismatic spray",
        "fireball",
        "magic missile",
        "hideous laughter",
        "lightning bolt",
        "scorcher",
        "conjure air elemental",
    }));
    set_spell_chance(90);
//	set_exp(1450);
    set_new_exp(7, "normal");
    set_emotes(5, ({
        "The sylph flutters her wings.",
        "A sylph giggles merrily.",
        "The sylph laughs softly.",
        "%^BOLD%^%^CYAN%^The sylph twirls around gracefully, watching" +
        " her shift float around her.",
    }), 0);
    if (!random(4)) {
        new(OBJ + "air_robes")->move(TO);
        command("wear shift");
    }
    add_money("gold", random(100) + 25);
    set_wimpy(20);
    set_property("swarm", 1);
}

void run_away()
{
    tell_room(ETO, "%^BOLD%^%^CYAN%^The sylph flies away.");
    TO->set_invis();
    ::run_away();
}

void reset()
{
    ::reset();
    if (random(2)) {
        if (!present("gem")) {
            switch (random(400)) {
            case 0..300:
                new(OBJ + "gem")->move(TO);
                break;

            case 301..350:
                new(OBJ + "gem")->move(TO);
                new(OBJ + "gem")->move(TO);
                break;

            case 351..375:
                new(OBJ + "gem")->move(TO);
                new(OBJ + "gem")->move(TO);
                new(OBJ + "gem")->move(TO);
                break;

            case 376..400:
                new(OBJ + "gem")->move(TO);
                new(OBJ + "gem")->move(TO);
                new(OBJ + "gem")->move(TO);
                new(OBJ + "gem")->move(TO);
                break;
            }
        }
    }
}
