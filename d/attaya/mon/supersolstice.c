#include <std.h>

inherit MONSTER;

void create() {
    object ob;
    ::create();
    call_out("roam_fun",1);
    set_name("super solstice warrior");
    set_id(({"super solstice warrior","warrior","solstice warrior", "shadow", "solstice"}));
    set_short("Super Solstice warrior");

    set_long(
      "Phantom Solstice warriors are the elite guardians of the Kinnesaruda.  They search the darkness for invaders or those who foolishly wander into their territory.  They are relentless.\n %^BOLD%^%^BLUE%^The Super Solstice Warrior is a fast moving assassin.  It is unmatched in terms of skill and combat prowess.  Those foolish enough to wander into their domain usually don't live long.  They are still considered legendary to most."
    );
    set_race("undead");
    set_level(70);
    set_gender("male");
    set_hd(70,20);
    set_size(4);
    set_overall_ac(-10);
    set_class("thief");
    set_mlevel("thief",70);
    set_max_hp(query_hp());
    set_hp(500+random(450));
    set_wielding_limbs(({"right hand","left hand"}));
    set_body_type("human");
    set_property("swarm",1);
    set_property("no_bump",1);
    set_stats("strength",25);
    set_stats("dexterity",25);
    set_stats("constitution",17);
    set_thief_skill("move silently",95);
    set_thief_skill("hide in shadows",95);
    add_search_path( "cmds/thief" );
    set("aggressive","aggfunc");
    set_mob_magic_resistance("average");
	set_property("strong stab",1);
    set_exp(40000);
    set_alignment(5);
    set_emotes(15, ({
	"%^BOLD%^%^RED%^A powerful evil force flashes around the Super Solstice Warrior.",
	"The Super solstice warrior grins at you very evilly.",
	"%^CYAN%^You begin to feel weaker",
	"%^CYAN%^You begin to feel dizzy."
      }),1);
    new("/d/attaya/obj/screamer.c")->move(this_object());
    command("wield dagger in right hand");
    new("/d/tharis/obj/wrist_sheath.c")->move(this_object());
    command("wear sheaths");
    ob = new("/d/attaya/obj/screamer.c");
    ob->move(this_object());
    command("put dagger in sheath");
    set_invis();
    set_funcs(({"fire"}));
    set_func_chance(25);
    set_moving( 1 );
    set_speed ( 10 );
      set_resistance("negative energy",20);
      set_resistance("positive energy",-20);
}
void die(object ob) {
    message("environment",
      "%^BOLD%^%^YELLOW%^There is a brilliant flash of light that blinds you momentarily!"
      "%^RESET%^" ,environment(TO));
    force_me("say %^BOLD%^%^RED%^My GOD...  What on Earth are you that commands the elements?!  WHY WON'T YOU DIE?!" );
    ::die(ob);
}

int aggfunc() {
    string mrace=TP->query_race();
    if(wizardp(TP) || TP->query_true_invis())
	return 1;
    if (mrace == "undead" || TP->query_invis()) {
	command("grin");
    } else {
	command("say %^RED%^Ancient spirits of the Kinnesaruda...  Guide my hand in vengeance against this invader!");
	command("say %^BOLD%^%^RED%^ Death to all who oppose us!");
	call_out("stab",1,TP);
    }
}
void stab(object targ) {
    command("stab "+targ->query_name());
    set_invis();
}
void fire(object targ) {
    string dam;

    if(!objectp(targ)) return;
if("daemon/saving_d"->saving_throw(targ,"paralyzation_poison_death")) {
	dam="hurts";
    } else {
	dam="singes";
    }
    tell_object(targ,
      "%^BOLD%^%^RED%^The Super Solstice Warrior begins to glow.  Phantom fire flashes about you and "+dam+
      " you!%^RESET%^"
    );
    tell_room(environment(targ),
      "Super Solstice warrior casts %^RED%^phantom fire at "+targ->query_cap_name()+"!%^RESET%^"
      ,targ);
    set_property("magic",1);
    if(dam=="singes") {
	targ->do_damage("torso",roll_dice(3,6));
	remove_property("magic");
	tell_object(targ,
	  "%^BOLD%^You are blinded by a brilliant light and intense heat!"
	);
	targ->set_paralyzed(random(20)+15,
	  "%^MAGENTA%^You cannot see your opponent and stumble around blindly!%^RESET%^"
	);
    } else {
	if(!objectp(targ)) return;
	targ->do_damage("torso",roll_dice(1,6));
    }
    return 1;
}
void roam_fun(){
   if(!objectp(TO)) return;
   if(!objectp(ETO)) return;
   ETO->init();
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
        if(!objectp(inv[i])) continue;
	if(living(inv[i]) && !userp(inv[i]) && (string)inv[i]->query_race()== "snake") {
		tell_room(ETO,
		  "%^BOLD%^%^YELLOW%^Your "+inv[i]->query_cap_name()+" explodes for no apparent reason!");
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
	int test_heart(){ return 1;}
