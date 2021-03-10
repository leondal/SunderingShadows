#include <std.h>
#include "/d/common/common.h"
#include <daemons.h>
#include "../elf.h"
#define CITYLAW "Ashta'Rathai law"

inherit "/std/jailer";

int give_key(string str);
int guard_check(string str);

void create(){
    ::create();
    set_jail("/realms/hades/elf/guard1");
    set_cell("/realms/hades/elf/cell");
   set_property("official","Ashta'Rathai");
   set_property("knock unconscious",1);
    set_id(({"jailer", "guard", "Ashta'Rathai jailer", CITYLAW}));
    set_name("Ashta'Rathai jailer");
    set_short("Ashta'Rathai jailer");
    set_long("The jailer looks like he doesn't get much work."+
	"  He is well kept and wears light leather armor.  "+
	"He has a leather belt with several items hanging from"+
	" it.  This elf is slender but looks to have toned muscles."+
	"  He wears light leather boots that come to his knees.  "+
	"While his appearance is fair, he doesn't look friendly."
    );
    set_race("elf");
    set_gender("male");
    set_size(2);
    set_hd(20+(random(9)),6);
    set_hp(350+(random(50)));
    set_max_level(30);
    set_overall_ac(-15);
    set_alignment(1);
    set_class("fighter");
    set_stats("charisma",12);
    set_property("swarm",1);
    set_property("no bows", 1);  
    set_property("no dominate", 1);  
    new(OBJ"key")->move(TO);
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
	force_me("speak elven");
	set_new_exp(30,"normal");
    set_max_level(35);
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
        new(MON"guard2")->move(ETO);
        new(MON"guard2")->move(ETO);
        new(MON"guard2")->move(ETO);
    }
    return hold;
}

int guard_check(string str) {
   string *jailers;
   jailers = AREALISTS_D->query_jailer_names(JailLoc);
   if(strsrch(str, "cell door") == -1)
        return 0;
   if(member_array(TPQN,jailers) != -1 || TP->id(CITYLAW) ||
TP->query_true_invis())
      return 0;
   if(str == "lock on cell door") { 
      tell_room(ETP,"%^YELLOW%^The jailer catches "+TPQCN+" trying to pick "
         "the lock to the cell door!", TP);
      tell_object(TP,"%^YELLOW%^The jailer catches you trying to pick the "
         "lock and attacks!");
   }
   if(str == "cell door with key" || str == "cell door with Ashta'Rathai jail key")
{
      if(TP->query_true_invis())   return 0;
      tell_room(ETP,"%^YELLOW%^The jailer catches "+TPQCN+" trying to unlock "
         "the cell door!", TP);
      tell_object(TP,"%^YELLOW%^The jailer catches you trying to unlock "
         "the cell door and attacks!");
   }
   force_me("kill "+TPQN);
   command("block northwest");
   return 1;
}

 void die(object ob) {  
   //ppl that kill guards get marked

    if(!objectp(ob) && objectp(TO->query_current_attacker()) )
	  ob = TO->query_current_attacker();
    else {::die(TO); return;}
   log_file("elftown.log",ob->query_race() + 
        " killed the jailer on "+hour(time())+":"+
		(minutes(time()) >9?minutes(time()):"0"+minutes(time()))+
		" "+day(time())+", "+date(time())+
		" "+month(time())+", "+year(time())+" SG"+"\n");
	//tell_room(ETO,ob->query_name() + " killed the jailer.");
	if(!present("feeling999",ob))	
	  new(OBJ"target")->move(ob);
	
   ::die(TO);
}

