#include <std.h>
#include <magic.h>
#include "../dojo.h"
inherit MONSTER;

int talking, waiting, mylevel;
string opponent;
object equipment;
void set_my_difficulty(int mylevel);

void create() {
   ::create();
   set_name("Akasha");
   set_short("%^BOLD%^%^WHITE%^Akasha, the master of spirit%^RESET%^");
   set_id(({"akasha","Akasha","master","master of spirit"}));
   set_long("%^RESET%^%^GREEN%^Akasha is the very image of serenity.  Whether still or in motion, she retains flawless "
"composure that fails to betray even a trace of anger, arrogance or fear.  Tall and %^ORANGE%^olive-skinned%^GREEN%^, "
"her hair is of purest %^RESET%^snow-white%^GREEN%^, as is the kimono that sits in impeccably placed folds about her "
"frame.  Her %^BOLD%^%^BLACK%^dark-eyed gaze %^RESET%^%^GREEN%^is calm and measuring as it takes in her surroundings, "
"meeting each new visitor with a level stare.  A smooth staff of %^BOLD%^%^WHITE%^white oak %^RESET%^%^GREEN%^rests in "
"her hands, which she handles as easily as if it were merely an extension of her own limbs.%^RESET%^");
   set_race("human");
   set_body_type("human");
   set_class("fighter");
   set_mlevel("fighter",26);
   set_guild_level("fighter",26);
   set_alignment(5);
   set_gender("female");
   set_size(2);
   set_exp(1);
   set_overall_ac(-60);
   set_hd(21,8);
   set_max_hp(9001);
   set_hp(query_max_hp());
   set("aggressive",0);
   set_wielding_limbs(({"right hand","left hand"}));
   set_property("full attacks",1);
   set_property("no bows",1);
   set_property("no death",1);
   set_property("no disarm",1);
   set_property("no hold", 1);
   set_property("no paralyze", 1);
   set_property("no knockdown", 1);
   set_property("knock unconscious",1);
   set_property("no steal",1);
   set_mob_magic_resistance("average");
   set_spoken("wizish");
   command("speech speak calmly");
   talking = 0;
   opponent = "";
   set_funcs(({ "serenity","serenity" }));
   set_func_chance(20);
//   set_monster_feats(({ "parry" }));
   equipment = new(OBJ"bostaff");
   equipment->set_property("monsterweapon",1);
   equipment->move(TO);
}

int query_talking() { return talking; }

void init() {
   ::init();
   if(TP->query_true_invis()) return;
   if(!talking && opponent == "") {
     mylevel = (int)TP->query_level();
     if(mylevel < 21) call_out("punt",3);
     else {
       talking = 1;
       waiting = 12;
       opponent = TPQN;
       if(mylevel > 40) mylevel = 40;
       set_my_difficulty(mylevel);
       call_out("speech1",3);
     }
   }
   if(opponent != "" && opponent != (string)TPQN) { //kick out any extras that manage to get in somehow
     if(!userp(TP)) {
       force_me("emoteat "+TPQN+" %^BOLD%^%^WHITE%^$M fixes $N with a level stare.%^RESET%^");
       write("");
       force_me("say %^BOLD%^'%^RESET%^Only one may approach.%^BOLD%^'%^RESET%^");
       force_me("emoteat "+TPQN+" %^BOLD%^%^WHITE%^$M extends an open palm towards $N, who disappears!%^RESET%^");
       TP->move_player("/d/shadowgate/void");
       TP->remove();
       return;
     }
     else {
       force_me("emoteat "+TPQN+" %^BOLD%^%^WHITE%^$M fixes $N with a level stare.%^RESET%^");
       write("");
       force_me("say %^BOLD%^'%^RESET%^Only one may approach. You must wait.%^BOLD%^'%^RESET%^");
       force_me("emoteat "+TPQN+" %^BOLD%^%^WHITE%^$M extends an open palm towards $N, and $S suddenly find $Oself in the main "
"chamber!%^RESET%^");
       TP->move_player(ROOMS+"stairs");
       return;
     }
   }
}

void punt() {
   force_me("emoteat "+TPQN+" %^BOLD%^%^WHITE%^$M shakes her head.%^RESET%^");
   write("");
   force_me("say %^BOLD%^'%^RESET%^You have much yet to learn. Return when you are better prepared.%^BOLD%^'%^RESET%^");
   force_me("emoteat "+TPQN+" %^BOLD%^%^WHITE%^$M makes a passing gesture, and $N suddenly find $Oself in the main "
"chamber!%^RESET%^");
   TP->move_player(ROOMS+"stairs");
   mylevel = 21;
}

void speech1() {
   force_me("emoteat akasha %^BOLD%^%^WHITE%^$M rises smoothly to her feet.%^RESET%^");
   write("");
   force_me("say %^BOLD%^'%^RESET%^So, you have come to test yourself.%^BOLD%^'%^RESET%^");
   force_me("emoteat akasha %^BOLD%^%^WHITE%^The staff slides smoothly through $M's hands into a sturdy grip.%^RESET%^");
   force_me("wield bo staff");
   write("");
   force_me("say %^BOLD%^'%^RESET%^Step forward, then, and prove that you are worthy.%^BOLD%^'%^RESET%^");
   talking = 0;
}

void die(object ob) {
   object foe;
   foe = find_player(opponent);
   if(foe && userp(foe) && present(foe,ETO)) {
     set_hp(query_max_hp());
     remove_paralyzed();
     force_me("emoteat akasha %^BOLD%^%^WHITE%^$M takes a step back and lowers her weapon.%^RESET%^");
     write("");
     force_me("say %^BOLD%^'%^RESET%^You have done well, stranger. Go forth with the blessings of the spirits.%^BOLD%^'%^RESET%^");
//for some reason, emote at "+TPQN+" was bugging, so I adjusted to older code.
//~Circe~ 4/30/13
// still bugging; TP is not a valid object & needed to be changed to 'foe' which is picked up. N, 11/13
     tell_object(foe,"%^BOLD%^%^WHITE%^Akasha makes a passing gesture, and you suddenly find yourself back on the landing!%^RESET%^");
     tell_room(ETO,"%^BOLD%^%^WHITE%^Akasha makes a passing gesture, and "+foe->QCN+" suddenly finds "+foe->QO+"self back on the landing!%^RESET%^",foe);
     foe->move_player(ROOMS+"stairs");
     if(!present("dojospirittoken",foe)) {
       tell_object(foe,"%^BOLD%^A gleaming ivory token flashes into existance in your hand.%^RESET%^");
       new(OBJ"spirittoken")->move(foe);
     }
   }
   opponent = "";
   mylevel = 21;
   set_my_difficulty(mylevel);
   force_me("unwield bo staff");
   if(waiting) waiting = 0;
}

void heart_beat() {
   object foe;
   ::heart_beat();
   foe = find_player(opponent);
   if(waiting) waiting--;
   if(waiting == 1 && (member_array(foe,TO->query_attackers()) == -1) && present(foe,ETO)) {
     force_me("emoteat akasha %^BOLD%^%^WHITE%^$M lowers her head briefly.%^RESET%^");
     write("");
     force_me("say %^BOLD%^'%^RESET%^You are hesitant, stranger. Return when you are prepared.%^BOLD%^'%^RESET%^");
     force_me("emoteat "+foe->query_name()+" %^BOLD%^%^WHITE%^$M makes a passing gesture, and $N suddenly find $Oself in the main "
"chamber again!%^RESET%^");
     foe->move_player(ROOMS+"stairs");
   }
   if(opponent != "" && (!foe || !present(foe,ETO))) {
     force_me("emoteat akasha %^BOLD%^%^WHITE%^$M lowers her weapon and sinks smoothly back to sit upon the floor.%^RESET%^");
     opponent = "";
     mylevel = 21;
     set_my_difficulty(mylevel);
     force_me("unwield bo staff");
     if(waiting) waiting = 0;
     if(objectp(foe)) {
       foe->remove_attacker(TO);
       TO->remove_attacker(foe);
     }
   }
   if(objectp(foe) && present(foe,ETO) && (int)foe->query_hp() < 1) { // KO, kick them out
     foe->remove_attacker(TO);
     TO->remove_attacker(foe);
     foe->set_hp(foe->query_max_hp());
     foe->remove_paralyzed();
     force_me("emoteat "+foe->query_name()+" %^BOLD%^%^WHITE%^$M gestures briefly to $N, and $N suddenly find $Oself fully "
"recovered!%^RESET%^");
     force_me("emoteat akasha %^BOLD%^%^WHITE%^$M slides her hands to meet in the centre of the staff.%^RESET%^");
     write("");
     force_me("say %^BOLD%^'%^RESET%^This task is yet beyond you, stranger. Go, and return when you are better prepared.%^BOLD%^'%^RESET%^");
     foe->move_player(ROOMS+"stairs");
     foe->general_exp_adjust_perc(-5);   //exp loss here, 5%; only half a death
     tell_object(foe,"%^BOLD%^%^WHITE%^You feel weary from your attempt!  %^BOLD%^%^RED%^You feel you have lost some experience.%^RESET%^");
   }
}

int serenity(object targ) {
   if(!objectp(TO)) return 0;
   if(!objectp(targ)) return 0;
   force_me("emoteat "+targ->query_name()+" %^BOLD%^%^WHITE%^$M closes her eyes and moves as if entirely by instinct, her staff becoming a "
"mere extension of her body as she strikes out with perfect precision!%^RESET%^");
   TO->set_property("magic",1);
   targ->do_damage("torso",(roll_dice(mylevel,10))+mylevel);
   TO->set_property("magic",-1);
   return 1;
}

void set_my_difficulty(int mylevel) {
   mylevel = mylevel + 8;
   set_mlevel("fighter",mylevel);
   set_guild_level("fighter",mylevel);
   set_hd(mylevel,12);
   set_max_hp(mylevel*40);
   set_hp(query_max_hp());
   set_overall_ac((-1)*mylevel);
   set_attack_bonus(mylevel/5);
}
