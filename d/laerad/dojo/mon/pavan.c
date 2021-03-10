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
   set_name("Pavan");
   set_short("%^YELLOW%^Pavan, the master of winds%^RESET%^");
   set_id(({"pavan","Pavan","master","master of winds"}));
   set_long("%^RESET%^%^GREEN%^Pavan's appearance is somewhat unusual, though perhaps in another place her clothes are "
"common garb.  Her straight, %^BOLD%^%^BLACK%^ebon-black hair %^RESET%^%^GREEN%^is pinned back in two long tails, with "
"the ends and her fringe flaring free with her movements.  A small cloth band covers her chest with an %^RED%^open jacket "
"%^GREEN%^that flares as the air catches it, likewise the tasseled ends of her %^MAGENTA%^long sash %^GREEN%^and the "
"%^RESET%^puffy half-length pants %^GREEN%^she wears only add to her chaotic style of motion.  She carries herself in "
"sudden bursts, like her energy has been pent up for far too long.  Her %^ORANGE%^dark eyes %^GREEN%^gleam with mischief "
"as she sizes you up, often absently twirling one of the twin pair of wooden tonfas, of which one is gripped lightly in "
"each hand.%^RESET%^");
   set_race("half-elf");
   set_body_type("human");
   set_class("thief");
   set_mlevel("thief",21);
   set_guild_level("thief",21);
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
   set_spoken("wizish");
   command("speech voice lightly");
   talking = 0;
   opponent = "";
   set_funcs(({ "spin","spin" }));
   set_func_chance(20);
   set_monster_feats(({ "scramble","spring attack","combat reflexes" }));
   equipment = new(OBJ"tonfa");
   equipment->set_property("monsterweapon",1);
   equipment->move(TO);
   equipment = new(OBJ"tonfa");
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
       force_me("emoteat "+TPQN+" %^RESET%^%^ORANGE%^Shaking her head, $M points at $N.%^RESET%^");
       write("");
       force_me("say %^YELLOW%^'%^RESET%^Hey, one at a time!%^YELLOW%^'%^RESET%^");
       force_me("emoteat "+TPQN+" %^RESET%^%^ORANGE%^$M grins mischeviously as $N disappears!%^RESET%^");
       TP->move_player("/d/shadowgate/void");
       TP->remove();
       return;
     }
     else {
       force_me("emoteat "+TPQN+" %^RESET%^%^ORANGE%^$M grins at $N and waggles a scolding finger.%^RESET%^");
       write("");
       force_me("say %^YELLOW%^'%^RESET%^Just one at a time, you have to wait!%^YELLOW%^'%^RESET%^");
       force_me("emoteat "+TPQN+" %^RESET%^%^ORANGE%^$M waves her hand towards $N, and $S suddenly find $Oself in the main "
"chamber!%^RESET%^");
       TP->move_player(ROOMS+"centre");
       return;
     }
   }
}

void punt() {
   force_me("emoteat "+TPQN+" %^RESET%^%^ORANGE%^$M giggles and waves $N back.%^RESET%^");
   write("");
   force_me("say %^YELLOW%^'%^RESET%^Far too weak for my likings.%^YELLOW%^'%^RESET%^");
   force_me("emoteat "+TPQN+" %^RESET%^%^ORANGE%^$M claps her hands, and $N suddenly find $Oself in the main "
"chamber!%^RESET%^");
   TP->move_player(ROOMS+"centre");
   mylevel = 21;
}

void speech1() {
   force_me("emoteat pavan %^RESET%^%^ORANGE%^$M shoots you a grin.%^RESET%^");
   write("");
   force_me("say %^YELLOW%^'%^RESET%^So, you think you can beat me?%^YELLOW%^'%^RESET%^");
   force_me("emoteat pavan %^RESET%^%^ORANGE%^$M spins one of the tonfas easily in her hand and then grasps it securely"
".%^RESET%^");
   force_me("wield Amihan Bantay");
   force_me("wield Amihan Bantay 2");
   write("");
   force_me("say %^YELLOW%^'%^RESET%^Let's see what you've got!%^YELLOW%^'%^RESET%^");
   talking = 0;
}

void die(object ob) {
   object foe;
   foe = find_player(opponent);
   if(foe && userp(foe) && present(foe,ETO)) {
     set_hp(query_max_hp());
     remove_paralyzed();
     force_me("emoteat pavan %^RESET%^%^ORANGE%^$M jumps back and spreads her fingers as if asking you to wait.%^RESET%^");
     write("");
     force_me("say %^YELLOW%^'%^RESET%^It's ok, that's enough! I know when I'm beat. You did well!%^YELLOW%^'%^RESET%^");
     force_me("emoteat pavan %^RESET%^%^ORANGE%^$M waves her hand towards you, and you suddenly find yourself in the main "
"chamber again!%^RESET%^");
     foe->move_player(ROOMS+"centre");
     if(!present("dojoairtoken",foe)) {
       tell_object(foe,"%^YELLOW%^A gleaming golden token flashes into existance in your hand.%^RESET%^");
       new(OBJ"airtoken")->move(foe);
     }
   }
   opponent = "";
   mylevel = 21;
   set_my_difficulty(mylevel);
   force_me("unwield tonfa");
   force_me("unwield tonfa 2");
   if(waiting) waiting = 0;
}

void heart_beat() {
   object foe;
   ::heart_beat();
   foe = find_player(opponent);
   if(waiting) waiting--;
   if(waiting == 1 && (member_array(foe,TO->query_attackers()) == -1) && present(foe,ETO)) {
     force_me("emoteat pavan %^RESET%^%^ORANGE%^$M grins and shakes her head.%^RESET%^");
     write("");
     force_me("say %^YELLOW%^'%^RESET%^Doesn't look like you're ready.  Come back when you are!%^YELLOW%^'%^RESET%^");
     force_me("emoteat pavan %^RESET%^%^ORANGE%^$M waves her hand towards you, and you suddenly find yourself in the main "
"chamber again!%^RESET%^");
     foe->move_player(ROOMS+"centre");
   }
   if(opponent != "" && (!foe || !present(foe,ETO))) {
     force_me("emoteat pavan %^RESET%^%^ORANGE%^$M relaxes her stance and grins to herself.%^RESET%^");
     opponent = "";
     mylevel = 21;
     set_my_difficulty(mylevel);
     force_me("unwield tonfa");
     force_me("unwield tonfa 2");
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
     force_me("emoteat "+foe->query_name()+" %^RESET%^%^ORANGE%^$M claps her hands, and you suddenly find yourself fully "
"recovered!%^RESET%^");
     force_me("emoteat pavan %^RESET%^%^ORANGE%^$M rests her hand on her hip.%^RESET%^");
     write("");
     force_me("say %^YELLOW%^'%^RESET%^That's just no good. But you can try again later!%^YELLOW%^'%^RESET%^");
     foe->move_player(ROOMS+"centre");
     foe->general_exp_adjust_perc(-5);   //exp loss here, 5%; only half a death
     tell_object(foe,"%^BOLD%^%^WHITE%^You feel weary from your attempt!  %^BOLD%^%^RED%^You feel you have lost some experience.%^RESET%^");
   }
}

int storm(object targ) {
   object dustobj;
   if(!objectp(TO)) return 0;
   if(!objectp(targ)) return 0;
   force_me("emoteat "+targ->query_name()+" %^RESET%^%^ORANGE%^$M leaps from the floor to whirl gracefully through the "
"air, raining down several blows against $np head in rapid succession!%^RESET%^");
   if(dustobj = present("silence-dust-obj",targ)) dustobj->remove();
   new(OBJ"silenceobj")->move(targ);
   return 1;
}

void set_my_difficulty(int mylevel) {
   set_mlevel("thief",mylevel);
   set_guild_level("thief",mylevel);
   set_hd(mylevel,8);
   set_max_hp(mylevel*35);
   set_hp(query_max_hp());
   set_overall_ac(10-mylevel);
   set_attack_bonus(mylevel/5);
   set_skill("stealth",(mylevel+5));
   set_skill("athletics",mylevel);
}