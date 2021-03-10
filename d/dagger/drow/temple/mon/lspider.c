#include <std.h>
#include "/d/dagger/drow/temple/short.h"
inherit MONSTER;
int xx;
void create() {
    :: create();
    set_name("spider");
    set_id(({
      "large spider","spider"
      }));
    set_short("%^RESET%^%^RED%^Large spider%^RESET%^");
    set_long(
        "%^RESET%^%^RED%^The Spider before you is a "
        "montrosity. It must be one of the rare types that "
        "Drow breed and raise as mounts. You can see the "
   "poison dripping from its mandibles as a look "
   "of hate fills its alien eyes."
    );
    set_gender("male");
    set_hd(15,3);
    set_size(3);
    set_wielding_limbs(({"right hand","left hand"}));
    set_overall_ac(-4);
    set_hp(120);
    set_property("no bump",1);
    set_mob_magic_resistance("average");
    set_max_hp(120);
    set_exp(8000);
    set_body_type("arachnid");
    set_race("spider");
    set_class("fighter");
    set_stats("strength",19);
    set_stats("constitution",18);
    set_stats("dexterity",19);
    set_stats("wisdom",16);
    set_stats("intelligence",15);
    set_stats("charisma",5);
    new( "/d/shadow/obj/potion/extra_heal.c" )->move(TO);
    new( "/d/shadow/obj/potion/extra_heal.c" )->move(TO);
    set("aggressive","agg_fun");
    set_funcs(({"moves"}));
    set_func_chance(20);
    set_emotes(5, ({
        "%^RED%^The spider gnaws into your flesh!%^RESET%^",
        "%^BLUE%^The spider shoots webbing at you, but misses!%^RESET%^",
    }),1);
}
int moves() {
    object ob = this_object();
    object targ = ob->query_current_attacker();
    xx=random(2)+1;
    switch(xx) {
    case 1:
    tell_object(targ,
        "%^GREEN%^The Spider fires a spindle of webbing towards "
        "you!%^RESET%^"
    );
    tell_room(environment(targ),
        "%^GREEN%^The Spider fires a spindle of webbing towards "
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
        targ->set_paralyzed(10+random(30),
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
        "%^BOLD%^%^RED%^The Spider sinks his fangs deep into "
        "your neck causing you to feel dizzy and drained!"
        "%^RESET%^"
    );
    tell_room(environment(targ),
        "%^BOLD%^%^RED%^The Spider sinks his fangs deep into "
        +targ->query_cap_name()+"'s neck!%RESET%^"
    ,targ);
    targ->do_damage("head",roll_dice(2,12));
    targ->add_poisoning(random(3)+1);
    return 1;
    }
}
int agg_fun(object ob) {
    if(TP->query_invis()) return 1;
    if ((string)TP->query_name() == "grazzt") {
        force_me ("bow");
        return 1;
    } else {
        force_me("kill "+TP->query_name());
        force_me("scream "+TP->query_name());
        tell_object(TP,
            "%^BOLD%^%^RED%^The Spider spits a %^GREEN%^green%^RED%^ "
            "substance in your face!%^RESET%^"
        );
        TP->do_damage("head",random(10)+10);
        TP->add_poisoning(5);
        TO->set_magic_round();
        TO->set_disable();
        return 1;
    }
}
