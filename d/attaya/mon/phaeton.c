#include <std.h>
inherit MONSTER;
object ob;

void create() {
    ::create();
    set_name("phaeton");
    set_id(({"phaeton","knight","undead"}));
    set_short("Phaeton the Guardian of the Tomb");
    set_long("Phaeton is a tall undead warrior of the Tyva Vvox clan.  He is the lord of the burial grounds on Attaya...  He is also the commander of the Midnight Corps...");
    set_race("undead");
    set_gender("male");
    set_hd(50,6);
    set_size(2);
   set_overall_ac(-15);
    set_class("fighter");
    set_guild_level("fighter",50);
   set_max_hp(2500);
   set_hp(2500);
    set_wielding_limbs(({"right hand","left hand"}));
    set_body_type("humanoid");
    set_property("swarm",1);
    set_property("full attacks",1);
    set_property("no_bump",1);
    set_property("magic", 1);
   set_property("no death",1);
   set_property("no hold", 1);
   set_property("no paralyze", 1);
    set_stats("constitution",22);
    set("aggressive","aggfunc");
   set_mob_magic_resistance("average");
    set_alignment(2);
    set_exp(51216);
    new("/d/attaya/obj/azure.c")->move(TO);
    command("wear armour");
    new("/d/attaya/obj/boots.c")->move(TO);
    command("wear boots");
   new("/d/attaya/obj/ice_hammer.c")->move(TO);
   command("wield hammer");
    new("/d/attaya/obj/shelm.c")->move(TO);
    command("wear helmet");
    new("/d/attaya/obj/falchion.c")->move(this_object());
    command("wield sword");
    set_funcs(({"fire"}));
    set_func_chance(20);
      set_resistance("negative energy",20);
      set_resistance("positive energy",-20);
}

void die(object ob) {
    message("environment",
      "%^BOLD%^%^MAGENTA%^Phaeton shrieks horribly and mutters a curse from the grave before falling to his knees and the onto his side!"
      ,environment(TO));
    :: die(ob);
}

int aggfunc() {
    string mrace=TP->query_race();
    if (mrace == "undead") {
	force_me ("say Greetings, kindred.");
	return 1;
    } else {
	if(wizardp(TP)) return 1;
	TP->kill_ob(TO,0);
	force_me("cackle");
	force_me("say %^BOLD%^%^RED%^I shall tear you apart!");
    }
}

void fire(object targ) {
    string dam;
    if("daemon/saving_d"->saving_throw(targ,"paralyzation_poison_death")) {
	dam="hurts";
    } else {
	dam="blasts";
    }
    tell_object(targ,"%^BOLD%^%^BLUE%^ A sphere of blue flame appears around Phaeton for a moment before he gathers the energies into his hands and "+dam+ " you!");
    tell_room(environment(targ),"%^BOLD%^%^BLUE%^A sphere of blue flame appears around Phaeton for a moment before he gathers the energies into his hands and blasts them at "+targ->query_cap_name()+"!%^RESET%^",targ);
    if(dam=="blasts") {
	targ->do_damage("torso",roll_dice(6,6));
	tell_object(targ,"%^RED%^A bone-shattering wave of energy tears through you!\n");
    } else {
	targ->do_damage("torso",roll_dice(3,6));
    }
    return 1;
}

void heart_beat() {
    int i,max;
    object ob;
    object here,*inv;

    ::heart_beat();
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    here = ETO;
    for(i=0, max = sizeof(inv=all_inventory(here)); i<max; i++) {
	if(living(inv[i]) && !userp(inv[i]) && (string)inv[i]->query_race() == "snake") {
		tell_room(ETO,"Phaeton pops the "+inv[i]->query_cap_name()+" into his mouth and chews it up.");
		tell_room(ETO,"Phaeton spits snake bones out onto the floor.");
		inv[i]->remove();
	    }
	}
	  if((int)TO->query_hp() < 100) {
	      TO->add_hp(random(3)+1);
	      return;
	  } else {
	      return;
	  }
      }
