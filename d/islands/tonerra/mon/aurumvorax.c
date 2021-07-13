//Added set_max_level to retard cycling - Octothorpe 6/4/09
//ankheg.c

#include <std.h>
#include "/d/islands/tonerra/areadefs.h"

inherit WEAPONLESS;

object caught;
int blah;

void create(){
   ::create();
   set_name("aurumvorax");
   set_id(({"aurumvorax","Aurumvorax"}));
   set_short("%^RESET%^%^ORANGE%^g%^BOLD%^i%^RESET%^%^ORANGE%^lded "+
      "a%^BOLD%^u%^RESET%^%^ORANGE%^rumv%^BOLD%^o%^RESET%^%^ORANGE%^rax%^RESET%^");
   set_long("%^ORANGE%^This small catlike animal is the size of a "+
      "badger and has eight legs.  It is covered with a coarse coat "+
	  "g%^BOLD%^o%^RESET%^%^ORANGE%^lden hair and has small %^RESET%^s"+
	  "%^BOLD%^i%^RESET%^lv%^BOLD%^e%^RESET%^r %^ORANGE%^eyes with "+
	  "g%^BOLD%^o%^RESET%^%^ORANGE%^lden pupils. Its eight powerful "+
	  "legs end in three inch long copper claws.%^RESET%^");
   set_hd(16+random(10),8);
   set_hp(roll_dice(query_hd(),15));
   //set_exp(query_hd()*325);
   set_new_exp(query_hd(), "normal");
   set_max_level(25);
   set_overall_ac(-10);
   set_body_type("quadruped");
   add_limb("right front middle leg","body",0,0,0);
   add_limb("right rear middle leg","body",0,0,0);
   add_limb("left front middle leg","body",0,0,0);
   add_limb("left rear middle leg","body",0,0,0);
   add_limb("mouth","head",0,0,0);
   set_attack_limbs(({"mouth"}));
   set_hit_funcs((["mouth":(:TO,"crushing":)]));
   set_damage(2,4);
   set_attacks_num(1);
   set_alignment(5);
   set_gender("female");
   set_race("aurumvorax");
   add_money("silver",random(5000));
   set_base_damage_type("piercing");
   set_stats("strength",20);
   set_speed(50);
   set_new_exp(25,"very high");
}

int crushing(object targ)
{
	string tlim;
   	if(!objectp(targ)) return 0;
   	caught = targ;
	tlim = targ->return_target_limb();
   	tell_object(targ,"%^RED%^The aurumvorax has locked its jaws onto "+
      "your "+tlim+"!%^RESET%^");
   	tell_room(ETO,"%^RED%^"+targ->QCN+"'s "+tlim+" "+
      "is caught in the locked jaws of the aurumvorax!%^RESET%^",targ);
	targ->set_paralyzed(30, "%^RED%^The aurumvorax has locked its "+
	"jaws onto your "+tlim+"!%^RESET%^");
   //targ->set_disable(100,TO);
   blah = 4;
   return random(4);
}

void heart_beat(){
   if(!objectp(TO)) return;
   if(!objectp(caught) || caught->query_ghost() || !present(caught,ETO)){
      set_attacks_num(1);
      set_attack_limbs(({"mouth"}));
	  caught = 0;
   }
   else{
      set_attacks_num(8);
	  set_attack_limbs(({"right front middle leg","right foreleg","left foreleg","left rear leg","right rear leg","left front middle leg","right rear middle leg","left rear middle leg"}));
   }
   ::heart_beat();
}

void init(){
   ::init();
//	if(!wizardp(TP))   changing to exclude true invis avatars too *Styx* 12/21/03, last change 6/16/02
   if(!TP->query_true_invis())
   kill_ob(TP,1);
}
