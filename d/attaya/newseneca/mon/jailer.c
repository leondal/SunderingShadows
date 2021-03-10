//jailer.c ~Circe~ 11/22/07 for new Seneca
#include <std.h>
#include "/d/common/common.h"
#include <daemons.h>
#include "../seneca.h"

#define CITYLAW "seneca law"
#define HAIR ({"%^YELLOW%^blond","%^ORANGE%^brown","%^BOLD%^%^BLACK%^black","%^BOLD%^silver","%^RED%^auburn"})
#define EYES ({"%^BOLD%^%^BLUE%^blue","%^BOLD%^%^GREEN%^green","%^ORANGE%^brown","%^BOLD%^%^BLACK%^gray","%^ORANGE%^ha%^GREEN%^z%^ORANGE%^el"})

inherit "/std/jailer";

int give_key(string str);
int guard_check(string str);

void create(){
   string MYHAIR,MYEYES;
   ::create();
   MYHAIR = HAIR[random(sizeof(HAIR))];
   MYEYES = EYES[random(sizeof(EYES))];
   set_jail_location("Seneca");
   set_jail("/d/attaya/newseneca/rooms/jail_main");
   set_cell("/d/attaya/newseneca/rooms/jail_cell");
   set_property("official","Seneca");
   set_property("knock unconscious",1);
   set_id(({"jailer","guard","Seneca jailer",CITYLAW}));
   set_name("Seneca Jailer");
   set_short("Seneca Jailer");
   set_long("Wearing the official uniform of the Seneca guard, "+
      "this jailer has close-cropped "+MYHAIR+" hair%^RESET%^"+
      "%^CYAN%^ and "+MYEYES+" eyes%^RESET%^%^CYAN%^.  "+
      "The guard's %^BOLD%^%^BLUE%^uniform %^RESET%^%^CYAN%^"+
      "is trimmed in %^BOLD%^%^RED%^red%^RESET%^%^CYAN%^ in a "+
      "manner that seems to add definition to his muscular "+
      "physique.  On the right shoulder is a an embroidered "+
      "%^BOLD%^%^WHITE%^eagle %^RESET%^%^CYAN%^in flight, "+
      "the symbol of the %^BOLD%^Seneca Guard%^RESET%^%^CYAN%^.  "+
      "Unlike many cities in the realms, Seneca has "+
      "no aging soldiers guarding any area due to threat of "+
      "invasion by Intruder.  Each soldier takes a turn at "+
      "jail duty, just as each takes a turn manning the walls.\n\n"+
      "%^RESET%^See <help jail> for more information on this place.\n");
    set_race("human");
    set_gender("male");
    set_hd(20+(random(9)),6);
    set_hp(350+(random(50)));
    set_max_level(30);
    set_overall_ac(-15);
    set_exp(1000);
    set_alignment(2);
    set_class("fighter");
    set_stats("charisma",12);
    set_property("swarm",1);
    set_property("no bows", 1);  
    set_property("no dominate", 1);   
    new("/d/attaya/newseneca/obj/seneca_key")->move(TO);
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
        new("/d/attaya/newseneca/mon/city_guard")->move(ETO);
        new("/d/attaya/newseneca/mon/city_guard")->move(ETO);
        new("/d/attaya/newseneca/mon/city_guard")->move(ETO);
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
   command("block north");
   return 1;
}
