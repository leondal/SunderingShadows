#include <std.h>
inherit MONSTER;

void create() {
    ::create();
    set_name("judatac");
    set_id(({"judatac","knight","undead","guard","rear guard"}));
    set_short("Judatac the Rear Guard");
    set_long("Judatac is a tall undead warrior of the Tyva Vvox clan.  He is the commander of the rear guard, protecting the citadel of undead from a rear assault.");
    set_race("undead");
    set_gender("male");
    set_hd(50,6);
    set_size(2);
   set_overall_ac(-19);
    set_class("fighter");
    set_guild_level("fighter",50);
   set_max_hp(2800);
    set_hp(2800);
    set_wielding_limbs(({"right hand","left hand"}));
    set_body_type("humanoid");
    set_property("swarm",1);
    set_property("full attacks",1);
    set_property("no_bump",1);
    set_stats("constitution",22);
    set("aggressive","aggfunc");
    set_mob_magic_resistance("very low");
   set_property("no death", 1);
    set_property("magic", 1);
    set_alignment(2);
    set_exp(50000);
    new("/d/attaya/obj/azure.c")->move(TO);
    command("wear armour");
    new("/d/attaya/obj/boots.c")->move(TO);
    command("wear boots");
    new("/d/attaya/obj/shelm.c")->move(TO);
    command("wear helmet");
    new("/d/attaya/obj/rgauntlets.c")->move(TO);
    command("wear gauntlets");
    new("/d/attaya/obj/falchion.c")->move(this_object());
    command("wield sword in right hand");
    new("/d/attaya/obj/gcutlass.c")->move(TO);
    command("wield sword in left hand");
    set_funcs(({"fire"}));
    set_func_chance(20);
      set_resistance("negative energy",20);
      set_resistance("positive energy",-20);
}

void die(object ob) {
    message("environment", "%^BOLD%^%^MAGENTA%^Judatac shrieks horribly and mutters a curse from the grave before falling to his knees and dying!",ETO);
    :: die(ob);
}

int aggfunc() {
    if(wizardp(TP)) return 1;
    TP->kill_ob(TO,0);
    force_me("say %^BOLD%^You will not leave here alive!");
}

void fire(object targ) {
    string dam;
    if("daemon/saving_d"->saving_throw(targ,"paralyzation_poison_death")) {
	dam="hurts";
    } else {
	dam="blasts";
    }
    tell_object(targ,"%^BOLD%^A sphere of fire appears around Judatac for a moment before he gathers the energies into his hands and "+dam+ " you!");
    tell_room(environment(targ),"%^BOLD%^A sphere of fire appears around Judatac for a moment before he gathers the energies into his hands and blasts them at "+targ->query_cap_name()+"!%^RESET%^",targ);
    set_property("magic",1);
    if(dam=="blasts") {
	targ->do_damage("torso",roll_dice(6,6));
	tell_object(targ,"%^RED%^A bone-shattering wave of energy tears through you!\n");
    } else {
	targ->do_damage("torso",roll_dice(3,6));
    }
    remove_property("magic");
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
		tell_room(ETO,"Judatac pops the "+inv[i]->query_cap_name()+" into his mouth and swallows it whole.");
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
