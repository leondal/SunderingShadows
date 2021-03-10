//updating the old files to use the new exp functions for standardized
//exp values. ~Circe~ 2/4/13

#include <std.h>
#include "../valley.h"
inherit WEAPONLESS;


void add_stuff();

void create()
{
    ::create();
    set_name("wolfwere");
    set_id(({ "wolfwere", "wolf", "monster", "wolf were", "wolf-were", "were wolf", "werewolf", "were-wolf" }));
    set_short("A sly wolf");
    set_long(
        "The wolfwere looks like the hybrid of a human and a wolf." +
        " He walks erect, standing on elongated paws with massive" +
        " thighs that maintain his balance. He has claws for feet" +
        " and hands. Although his body is humanoid, he has the head" +
        " of a wolf. Large ivory fangs glimmer with saliva and the" +
        " creature has a hungry look in his eyes."
        );
    set_gender("male");
    set_race("wolfwere");
    set_body_type("quadruped");
    set_hd(15, 5);
    set_max_level(25);
    set_size(2);
    set_alignment(9);
    set_overall_ac(3);
    set_property("weapon resistance", 2);
    set_property("no bows", 1);
    set_max_hp(random(40) + 120);
    set_hp(query_max_hp());
//	set_exp(13400);
    set_new_exp(15, "normal");
    set_mob_magic_resistance("very low");
    set("aggressive", 25);
    set_property("swarm", 1);
    set_attack_limbs(({ "right forepaw", "left forepaw" }));
    set_attacks_num(2);
    set_base_damage_type("slashing");
    set_damage(2, 6);
    set_funcs(({ "bite" }));
    set_func_chance(40);
    set_level(20);
    set_class("fighter");
    set_mlevel("fighter", 15);
    set_stats("strength", 18);
    add_money("electrum", random(2000));
    add_money("silver", random(4000));
    add_money("copper", random(6000));
    add_money("copper", random(8000));
    add_stuff();
}

void bite(object targ)
{
    int roll, ac;

    roll = random(20);
    ac = targ->query_ac();

    if (roll > -1 * ac) {
        tell_object(targ, "%^RED%^The wolfwere bites you savagely" +
                    " with his powerful jaws.");
        tell_room(ETO, "%^RED%^The wolfwere bites " + targ->query_cap_name() + "" +
                  " savagely with his powerful jaws.", targ);
        targ->do_damage("torso", random(7) + 6);
    }else {
        tell_object(targ, "%^RED%^The wolfwere snaps at you with" +
                    " his powerful jaws.");
        tell_room(ETO, "%^RED%^The wolfwere snaps at " + targ->query_cap_name() + "" +
                  " with his powerful jaws.", targ);
    }
}

void add_stuff()
{
    object ob;
    //::reset();
// adding TO argument to the present check since I suspect the bug in the header may be related to trying to check ETO also  *Styx* 12/20/05
    if (!present("scroll", TO)) {
        if (random(2)) {
            ob = new("/d/magic/scroll");
            ob->set_spell(random(2) + 7);
            ob->move(TO);
        }
    }
    if (!present("gem")) {
        if (!random(3)) {
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

            case 376..399:
// fixed from 400 which was outside the range = illegal index *Styx* 12/12/05
                new(OBJ + "gem")->move(TO);
                new(OBJ + "gem")->move(TO);
                new(OBJ + "gem")->move(TO);
                new(OBJ + "gem")->move(TO);
                break;
            }
        }
    }
    if (!present("jewelry")) {
        if (!random(5)) {
            switch (random(200)) {
            case 0..100:
                new(OBJ + "jewelry")->move(TO);
                break;

            case 101..175:
                new(OBJ + "jewelry")->move(TO);
                new(OBJ + "jewelry")->move(TO);
                break;

            case 176..199:
// fixed from 200 which was outside the range = illegal index *Styx* 12/12/05
                new(OBJ + "jewelry")->move(TO);
                new(OBJ + "jewelry")->move(TO);
                new(OBJ + "jewelry")->move(TO);
                break;
            }
        }
    }
}
