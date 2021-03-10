#include <std.h>
#include "/d/dagger/drow/temple/short.h"
inherit MONSTER;
int xx;
object ob;
void create() {
    :: create();
    set_name("drider");
    set_id(({
      "drider","spider","aberration"
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
      set_hd(11+random(12),2);
    set_size(2);
    set_alignment(9);
    set_wielding_limbs(({"right hand","left hand"}));
    set_overall_ac(-4);
    set_property("no bump",1);
    set_mob_magic_resistance("average");
    set_max_hp(query_hd()*14);
   set_max_level(30);
    set_hp(query_max_hp());
set_exp(1100*query_hd());
    set_body_type("humanoid");
    set_race("drider");
    set_class("fighter");
    set_stats("strength",19);
    set_stats("constitution",18);
    set_stats("dexterity",19);
    set_stats("wisdom",20);
    set_stats("intelligence",15);
    set_stats("charisma",5);
     set_property("full attacks",1);
   set_property("magic",1);
    new( OPATH "whip.c" )->move(TO);
    command("wield whip in right hand");
    new( OPATH "whip.c" )->move(TO);
    command("wield whip in left hand");
ob = new("/d/common/obj/potion/advanced_heal.c"); // altered by Lujke from the old /d/shadow/obj file for extra healing potions
ob->set_uses(3);
ob->move(TO);
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
     object *targs = ob->query_attackers();
     object targ;
   int i;
for(i=0;i<sizeof(targs);i++){
      targ = targs[i];
     if(Thaco(0,targ,0) > roll_dice(1,20)) continue;
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
        targ->set_paralyzed(20+random(20),
            "%^GREEN%^You are entangled in the webbing and cannot move!"
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
    case 2:
    tell_object(targ,
        "%^BOLD%^%^RED%^The Drider sinks his spider-like fangs deep into "
        "your neck causing you to feel dizzy and drained!"
        "%^RESET%^"
    );
    tell_room(environment(targ),
        "%^BOLD%^%^RED%^The Drider sinks his spider-like fangs deep into "
        +targ->query_cap_name()+"'s neck!%^RESET%^"
    ,targ);
    targ->do_damage("head",roll_dice(4,12));
    targ->add_poisoning(random(13)+13);
}
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
        TP->do_damage("head",random(35)+10);
        TP->add_poisoning(random(25));
    TP->set_paralyzed(22,"%^GREEN%^You are entangled!");
        TO->set_magic_round();
        TO->set_disable();
        return 1;
    }
}
