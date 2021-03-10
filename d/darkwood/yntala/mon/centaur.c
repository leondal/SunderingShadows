//Added feats - Octothorpe 7/7/10

#include <std.h>
#include "../yntala.h"
inherit MONSTER;
void create (){

::create ();
   set_name("Centaur");
   set_id(({"Centaur","centaur"}));
   set_short("%^RESET%^%^ORANGE%^ A brown centaur%^RESET%^");
   set_long("%^RESET%^%^ORANGE%^This is one of many centaurs that"
" you may find in this glade.  His torso is well defined, and his"
" coat is kept clean and neat.  He has brown hair that flows to"
" his shoulders and he looks as though he is ready for just about"
" anything.  Like most of his kin, he holds a sword in each of his"
" hands.%^RESET%^");
   set_race("centaur");
   set_gender("male");
   set_body_type("centaur");
   set_hd(14,2);
   set_overall_ac(-5);
   set_size(2);
   set_stats("intelligence",18);
   set_stats("strength",18);
   set_stats("wisdom",13);
   set_stats("dexterity",14);
   set_stats("constitution",15);
   set_stats("charisma",11);
   set_money("gold",random(200));
   set_money("silver",random(100));
   set_money("copper",random(50));
   set_money("electrum",random(75));
   set_class("ranger");
   set_exp(500);
   set_max_level(15);
   set_hp(random(150)+100);
   set_max_hp(query_hp());  
   set_alignment(4);
   set("aggressive","aggfunc");
   set_mlevel("ranger",14);
   set_achats(10, ({"%^GREEN%^The centaur rears up on his hind legs and gets ready to move in again!%^RESET%^",
      "%^RESET%^%^GREEN%^The centaur circles around behind you before raising his swords high again.%^RESET%^"}) ); 
   set_emotes(1, ({"%^GREEN%^The centaur warily scans the area, keeping an eye on the children.%^RESET%^",
      "The %^RESET%^%^ORANGE%^centaur %^RESET%^looks to the center of the area and smiles softly.",
      "%^RESET%^%^GREEN%^The %^ORANGE%^centaur %^GREEN%^works quietly on pruning back the branches of the trees.%^RESET%^",
      "%^BOLD%^%^GREEN%^The %^RESET%^%^ORANGE%^centaur %^BOLD%^%^GREEN%^kneels down and gathers some %^RED%^b%^RESET%^%^RED%^er%^MAGENTA%^r%^RED%^ie%^BOLD%^%^RED%^s.%^RESET%^",
}), 0);
   new(LGSW+"longsword.c")->move(TO);
   command("wield longsword");
   new(LGSW+"longsword.c")->move(TO);
   command("wield longsword");
      set_monster_feats(({
      "ambidexterity",
	  "two weapon fighting",
	  "improved two weapon fighting",
	  "unassailable parry",
	  "whirl"
   }));
   set_funcs(({"whirlit"}));
   set_func_chance(30);
  }
void die(object ob) {
   tell_room(ETO,
"%^MAGENTA%^The centaur looks up at you with pleading eyes before collapsing on the ground.%^RESET%^");
:: die(ob);
}
int aggfunc() {
   string mrace=TP->query_race();
      if(mrace == "elf"||"centaur"||"nymph"||"dryad"||"deva") {
         switch(random(5)) {
            case 0..3:
            break;
            case 4:
               force_me("emoteat "+TPQN+ " turns to $N and nods warmly before continuing with his business.");
            break;
         }
      return 1;
	}
      if(mrace == "half-elf"||"squole") {
         switch(random(5)) {
            case 0..3:
            break;
            case 4:
               force_me("emoteat "+TPQN+ " turns to $N and blinks disbelievingly before just shaking his head and turning back to his work.");
            break;
         }
      return 1;
      }
      if(mrace == "voadkyn") {
         switch(random(5)) {
            case 0..3:
            break;
            case 4:
               force_me("emoteat "+TPQN+ " doesn't seem to notice $N.");
            break;
         }
      return 1;
	}
      if(mrace == "human") {
         switch(random(5)) {
            case 0..3:
            break;
            case 4:
               force_me("speak elven");
               force_me("emoteat "+TPQN+ " turns to $N and blinks.");
               force_me("say %^GREEN%^I am sorry human, but your kind is not allowed in here. Please leave.%^RESET%^");
               force_me("emoteat "+TPQN+ " turns back to tending the meadows edge.");
            break;
          }
      return 1;
	}
      if(mrace == "dwarf") {
         switch(random(5)) {
            case 0..3:
            break;
            case 4:
               force_me("speak elven");
               force_me("emoteat "+TPQN+ " looks to $N curiously.");
               force_me("say %^GREEN%^How did you get in? Would you please find your way back out before you give the children a scare?%^RESET%^");
               command("emote turns back to what he was doing, shaking his head slightly.");
            break;
         }
      return 1;
      }
      if(mrace == "halfling") {
         switch(random(5)) {
            case 0..3:
            break;
            case 4:
               force_me("emoteat "+TPQN+ " doesn't seem to notice $N.");
            break;
          }
      return 1;
	}
      if(mrace == "gnome") {
         switch(random(5)) {
            case 0..3:
            break;
            case 4:
               force_me("emoteat "+TPQN+ " doesn't seem to notice $N.");
            break;
         }
      return 1;
	}
      if(mrace == "firbolg") {
         switch(random(5)) {
            case 0..3:
            break;
            case 4:
               force_me("speak elven");
               force_me("emoteat "+TPQN+ " turns to $N and frowns slightly.");
               force_me("say %^GREEN%^Have you spoken to the guard outside yet?%^RESET%^");
               force_me("emote just shakes his head and goes back to what he was doing.");
            break;
         }
      return 1;
      }
      if(mrace == "wemic" || mrace == "beastman") {
         switch(random(5)) {
            case 0..3:
            break;
            case 4:
               force_me("speak elven");
               force_me("emoteat "+TPQN+ " turns to $N and pats $O on the head.");
               force_me("say %^GREEN%^I must ask you to leave furry one.");
               force_me("say You will make the young ones nervous.%^RESET%^");
               force_me("emote turns back to what he was doing.");
            break;
         }
      }
      else {
        force_me("speak elven");
        force_me("say %^GREEN%^How did you get in here?%^RESET%^");
        force_me("say %^GREEN%^We shall make sure you do no more damage!%^RESET%^");
        command ("kill "+TPQN);
    }
}

void whirlit(object targ){
   if(!objectp(targ)) return;
   if(!objectp(TO)) return;
   TO->force_me("whirl "+targ->query_name());
}
