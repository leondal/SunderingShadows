#include <std.h>
inherit WEAPONLESS;

void create(){
    ::create();
    set_name("sandling");
    set_id( ({"sandling"}) );
    set_short("sandling");
    set_long(
      "What you are looking at seems to be no more than a pile of sand, a large moving pile of sand."
    );
    set_gender("neuter");
    set_race("sandling");
    add_limb("pseudopod", "torso", 0,0,0);
    set_attack_limbs(({"pseudopod"}));
    set_attacks_num(2);
    set_damage(3,6);
    set_hd(20, 1);
    set_size(3);
    set_hp(350);
    set_alignment(5);
    set_invis();
    set("aggressive", 2);
}

void init(){
    ::init();
    if(!TO->query_invis()) return;
    tell_object(TP, "As you start to walk across a patch of sand, the sand around you starts to rise up and engulf you!");
    tell_room(ETO, TPQCN+" starts to walk across a patch of sand, and the sand suddenly rises up and engulfs "+TP->query_objective()+"!", TP);
    TP->set_paralyzed(40, "You are stuck in the sandling!");
    kill_ob(TP, 1);
    set("aggressive", 30);
}

void heart_beat(){
    ::heart_beat();
    if(query_invis()) return;
    if(query_attackers() != ({}) ) return;
    tell_room(ETO, "The sandling melts back into the ground.");
    TO->set_invis();
    if(present("corpse", ETO)){
      TO->run_away();
      TO->run_away();
    }
    set("aggressive", 2);
}
