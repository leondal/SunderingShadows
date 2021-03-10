// converted to use new guardsman inherit

#include <std.h>
#include "/d/common/common.h"
#include <daemons.h>

#define CITYLAW "shadow law"

inherit "/std/jailer";

int give_key(string str);
int guard_check(string str);

void create(){
    ::create();
    set_jail("/d/shadow/room/city/jail_main");
    set_cell("/d/darkwood/tabor/room/jail_cell");
    set_property("official","Shadow");
    set_property("knock unconscious",1);
    set_id(({"jailer", "guard","Copernicus", "copernicus" ,"Shadow jailer", CITYLAW}));
    set_name("Shadow jailer");
    set_short("%^RESET%^%^RED%^Copernicus%^BLUE%^, Shadow jailer");
    set_long("The jailer looks like he has slept in his clothes and gear
a few too many times.  He obviously hasn't shaved in a few days and his
dark hair is rather unkempt.  A heavy chain hangs from a wide, heavy
leather belt and the key in his hand is attached to the other end. 
Massive corded biceps bulge between the thick, rough leather vest he wears
and leather bracers on his lower arms.  Heavy leather boots come to his
knees and Altogether his appearance makes his surly attitude that much
more disconcerting.  Heavily scarred, he's obviously seen his share of
combat and probably knows how to handle himself.  He does, however, look
quite ready to jail about anyone and might even take a prisoner off your
hands."
        );
    set_race("human");
    set_gender("male");
    set_size(2);
    set_hd(20+(random(9)),6);
    set_hp(350+(random(50)));
    set_max_level(30);
    set_overall_ac(-15);
    set_exp(1000);
    set_alignment(2);
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
        new("/d/shadow/mon/guardnew")->move(ETO);
	new("/d/shadow/mon/guardnew")->move(ETO);
	new("/d/shadow/mon/guardnew")->move(ETO);
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
      tell_room(ETP,"%^YELLOW%^The jailer catches "+TPQCN+" trying to pick "
         "the lock to the cell door!", TP);
      tell_object(TP,"%^YELLOW%^The jailer catches you trying to pick the "
         "lock and attacks!");
   }
   if(str == "cell door with key" || str == "cell door with skeleton key") {
      if(TP->query_true_invis())   return 0;
      tell_room(ETP,"%^YELLOW%^The jailer catches "+TPQCN+" trying to unlock "
         "the cell door!", TP);
      tell_object(TP,"%^YELLOW%^The jailer catches you trying to unlock "
         "the cell door and attacks!");
   }
   force_me("kill "+TPQN);
   command("block south");
   return 1;
}
