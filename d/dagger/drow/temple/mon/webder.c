#include <std.h>
#include "/d/dagger/drow/temple/short.h"
inherit MONSTER;
int xx;
void make_me();
void create() {
    :: create();
    set_name("drider");
    set_id(({
      "drider","spider"
      }));
    set_short("%^RESET%^%^RED%^Drider%^RESET%^");
    set_long(
        "%^RESET%^%^RED%^The Drider appears as a mutated cross between a "
   "drow elf and a spider. The upper part of its body is of "
        "drow looks and proportions, but the lower half is the body "
        "of a giant spider. The lower body has 6 legs well the upper "
        "body has two humanoid arms. The entire lower body is covered "
        "in a spindly course hair. Legends tell that driders were drow "
        "who displeased Lloth and were transformed into their present "
        "lower form of drow/spider existance."
    );
    set_gender("male");
    set_hd(18,2);
    set_size(2);
    set_wielding_limbs(({"right hand","left hand"}));
    set_overall_ac(-5);
    set_hp(130);
    set_property("no bump",1);
    set_mob_magic_resistance("average");
    set_max_hp(130);
    set_exp(11000);
    set_body_type("humanoid");
    set_race("drider");
    set_class("fighter");
    set_stats("strength",19);
    set_stats("constitution",18);
    set_stats("dexterity",19);
    set_stats("wisdom",16);
    set_stats("intelligence",15);
    set_stats("charisma",5);
    new( OPATH "whip.c" )->move(TO);
    command("wield whip in right hand");
    new( OPATH "whip.c" )->move(TO);
    command("wield whip in left hand");
    new( "/d/shadow/obj/potion/extra_heal.c" )->move(TO);
    new( "/d/shadow/obj/potion/extra_heal.c" )->move(TO);
    new( "/d/shadow/obj/potion/extra_heal.c" )->move(TO);
    make_me();
    add_money("gold",random(400));
    set("aggressive","agg_fun");
    set_funcs(({"moves"}));
    set_func_chance(35);
    set_emotes(5, ({
        "%^RED%^The drider rips into your flesh!%^RESET%^",
        "%^BLUE%^The drider lunges at you!%^RESET%^",
    }),1);
}
int moves() {
    object ob = this_object();
    object targ = ob->query_current_attacker();
    xx=random(2)+1;
    switch(xx) {
    case 1:
    tell_object(targ,
        "%^GREEN%^The Drider fires a spindle of webbing towards "
        "you!%^RESET%^"
    );
    tell_room(environment(targ),
        "%^GREEN%^The Drider fires a spindle of webbing towards "
        +targ->query_cap_name()+"!%^RESET%^"
    ,targ);
    if("daemon/saving_d"->saving_throw(ob,"rod_staff_wand")) {
        tell_object(targ,
            "%^MAGENTA%^The webbing entangles you!%^RESET%^"
        );
        tell_room(environment(targ),
            "%^MAGENTA%^The webbing entangles "
            +targ->query_cap_name()+"!%^RESET%^"
        ,targ);
        targ->set_paralyzed(30+random(20),
            "%^GREEN%^You are entangled in the webbing an cannot move!"
            "%^RESET%^"
        );
    } else {
        tell_object(targ,
            "%^MAGENTA%^You quickly jump out of the way!%^RESET%^"
        );
        tell_room(environment(targ),
            "%^MAGENTA%^"+targ->query_cap_name()+
            " quickly jumps out of the way!%^RESET%^"
        ,targ);
    }
    return 1;
    case 2:
    tell_object(targ,
        "%^BOLD%^%^RED%^The Drider sinks his spider-like fangs deep into "
        "your neck causing you to feel dizzy and drained!"
        "%^RESET%^"
    );
    tell_room(environment(targ),
        "%^BOLD%^%^RED%^The Drider sinks his spider-like fangs deep into "
        +targ->query_cap_name()+"'s neck!%RESET%^"
    ,targ);
    targ->do_damage("head",roll_dice(2,12));
    targ->add_poisoning(random(3)+1);
    return 1;
    }
}
void make_me() {
    if(random(10) < 1) {
	if(random(6) < 3) {
	    new( OPATH "sticks.c" )->move(TO);
        } else {
	    new( OPATH "stickd.c" )->move(TO);
        }
    } else {
        new( OPATH "hlstick.c" )->move(TO);
    }
}
int agg_fun(object ob) {
    if ((string)TP->query_name() == "grazzt") {
        force_me ("bow");
        return 1;
    } else {
        force_me("kill "+TP->query_name());
        force_me("scream "+TP->query_name());
        tell_object(TP,
            "%^BOLD%^%^RED%^The drider spits a %^GREEN%^green%^RED%^ "
            "substance in your face!%^RESET%^"
        );
        TP->do_damage("head",random(10)+10);
        TP->add_poisoning(5);
        TO->set_magic_round();
        TO->set_disable();
        return 1;
    }
}
