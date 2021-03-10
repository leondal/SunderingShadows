#include <std.h>
#include "/d/common/common.h"
#include <daemons.h>

#define CITYLAW "antioch law"

inherit "/std/jailer";

int give_key(string str);
int guard_check(string str);

void create(){
    ::create();
    set_jail("/d/antioch/antioch2/rooms/jail_main");
    set_cell("/d/antioch/antioch2/rooms/jail");
    set_property("official","antioch");
    set_property("knock unconscious",1);
    set_id(({"jailer", "guard","Lucius", "lucius" ,"antioch jailer", CITYLAW}));
    set_name("antioch jailer");
    set_short("Lucius, the Antioch Jailer");
    set_long("This jailer is the picture of disciplined confidence. He is clean
    shaven with with well-kept blonde hair. He has the armor and trappings of the
    royal guard of the city of Antioch, silver chain armor with a silver sword. This
    is no mere ruffian but a seasoned, professional soldier. His face is handsome but
    stern and unwavering. He takes his job extremely seriously: to uphold the law and
    safety of the city of Antioch."
        );
    set_race("human");
    set_gender("male");
    set_size(2);
    set_hd(60);
    set_hp(roll_dice(query_hd(),40));
    set_max_level(50);
    set_overall_ac(-40);
    set_exp(1000);
    set_alignment(1);
    set_class("fighter");
    set_stats("charisma",12);
    set_property("swarm",1);
    set_property("no bows", 1);  // added 2/8/03 
    set_property("no dominate", 1);  // added 2/8/03 
    new("/d/shadow/obj/special/jail_key")->move(TO);
    force_me("wear key");
    new("/d/common/obj/armour/coif")->move(TO);
    command("wear coif");
    switch(random(3)) {
        case 0:
        RANDGEAR->arm_me(TO, "edgedm", 30, 2, 75);
        RANDGEAR->armor_me(TO, "shield", 30, 1, 75);
            break;
        case 1:
        RANDGEAR->arm_me(TO, "edgedl", 30, 2, 75);
            break;
        case 2:
        RANDGEAR->arm_me(TO, "bluntm", 30, 2, 75);
        RANDGEAR->arm_me(TO, "blunts", 30, 2, 75);
            break;
    }
}

void reset() {
   object ob;
   ::reset();
   if(ob = present("skeleton key", TO))
      if(!ob->query_worn())
        command("wear key");
}

void init() {
   ::init();
   if(base_name(ETO) == JailFile) {
      add_action("guard_check", "pick");
      add_action("guard_check", "unlock");
   }
   add_action("no_way","rush");
   add_action("no_way","stab");
}

int kill_ob(object ob, int i){
    int hold;
    hold = ::kill_ob(ob,i);
    if (hold) {
        tell_room(ETO, "The jailer yells loudly for help.");
        new("/d/antioch/antioch2/mons/patrol_guard")->move(ETO);
        new("/d/antioch/antioch2/mons/patrol_guard")->move(ETO);
        new("/d/antioch/antioch2/mons/patrol_guard")->move(ETO);
    }
    return hold;
}

int guard_check(string str) {
   string *jailers;
   jailers = AREALISTS_D->query_jailer_names(JailLoc);
   if(strsrch(str, "cell door") == -1)
        return 0;
   if(member_array(TPQN,jailers) != -1 || TP->id(CITYLAW) || TP->query_true_invis())
      return 0;
   if(str == "lock on cell door") { 
      tell_room(ETP,"The jailer catches "+TPQCN+" trying to pick "
         "the lock to the cell door!", TP);
      tell_object(TP,"The jailer catches you trying to pick the "
         "lock and attacks!");
   }
   if(str == "cell door with key" || str == "cell door with skeleton key") {
      if(TP->query_true_invis())   return 0;
      tell_room(ETP,"The jailer catches "+TPQCN+" trying to unlock "
         "the cell door!", TP);
      tell_object(TP,"The jailer catches you trying to unlock "
         "the cell door and attacks!");
   }
   force_me("kill "+TPQN);
   command("block south");
   return 1;
}
