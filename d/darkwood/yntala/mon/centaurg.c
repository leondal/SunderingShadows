#include <std.h>
#include "../yntala.h"


inherit MONSTER;
void create (){
object ob;
::create ();
   set_name("Centaur Guard");
   set_id(({"Centaur Guard","centaur guard","centaur","guard"}));
   set_short("%^RESET%^%^ORANGE%^Centaur guard%^RESET%^");
   set_long("%^RESET%^%^GREEN%^This forest creature has the upper"
" torso much like that of a human, but the lower body of a horse. "
" His %^BOLD%^%^BLACK%^dark hair %^RESET%^%^GREEN%^is long and"
" braided, tied at the back of his head with a %^ORANGE%^leather"
" %^GREEN%^thong.  His eyes are warm and caring, though he seems to"
" be ever watchful.  Two %^ORANGE%^sheaths %^GREEN%^criss-cross"
" his back, and his long flowing tail has %^BOLD%^%^WHITE%^white"
" %^RESET%^f%^BOLD%^%^WHITE%^e%^RESET%^at%^BOLD%^%^WHITE%^h"
"%^RESET%^er%^BOLD%^%^WHITE%^s %^RESET%^%^GREEN%^braided into it"
" for added decoration.  His well muscled body looks as though it"
" is ready for any intruder, and held in each of his slender hands"
" is a longsword ready for action.%^RESET%^");
   set_race("centaur");
   set_gender("male");
   set_body_type("centaur");
   set_hd(20,2);
   set_overall_ac(-6);
   set_size(2);
   set_stats("intelligence",18);
   set_stats("strength",18);
   set_stats("wisdom",13);
   set_stats("dexterity",14);
   set_stats("constitution",15);
   set_stats("charisma",11);
   set_money("gold",random(1000));
   set_money("silver",random(100));
   set_money("copper",random(50));
   set_money("electrum",random(75));
   set_class("ranger");
   set_exp(2500);
   set_alignment(4);
   set("aggressive","aggfunc");
   set_mlevel("ranger",20);
   set_hp(random(200)+50);
   set_max_hp(query_hp());  
   set_achats(10, ({"%^GREEN%^The centaur rears up on his hind legs and gets ready to move in again!%^RESET%^",
"%^RESET%^%^GREEN%^The centaur circles around behind you before raising his swords high again.%^RESET%^"}) );
   set_emotes(1, ({"%^RESET%^%^ORANGE%^The centaur adjusts the straps to his weapon sheaths.%^RESET%^",
"%^GREEN%^The centaur's eyes warily scan the horizon.%^RESET%^",
"The %^RESET%^%^ORANGE%^centaur %^RESET%^paces back and forth, glancing out towards the %^GREEN%^forest %^RESET%^nervously.",
}), 0);
   RANDGEAR->arm_me(TO,"edgedm",90,1,90);
   RANDGEAR->arm_me(TO,"edgedm",90,1,90);
  }
void die(object ob) {
   tell_room(ETO,
"%^MAGENTA%^The centaur looks up at you with pleading eyes before collapsing on the ground.%^RESET%^");
:: die(ob);
}
int aggfunc() {
    string mrace=TP->query_race();
      if(mrace == "centaur") {
               force_me("speak elven");
               force_me("emoteat "+TPQN+ " turns to $N.");
               force_me("say Greetings friend and welcome to our home.  Please feel free to trade
any items you might have with us.");
               command("emoteat "+TPQN+ " smiles warmly and bows before $N.");
       return 1;
       }
            if(mrace == "elf"||"nymph"||"dryad"||"deva") {

         switch(random(5)) {
            case 0..3:
            break;
            case 4:
               force_me("speak elven");
               force_me("emoteat "+TPQN+ " turns to $N.");
               force_me("say %^GREEN%^Greetings friend and welcome to our home.  Please feel free to trade any items you might have with us.");
               command("emoteat "+TPQN+ " smiles warmly and bows before $N.");
            break;
          }
       return 1;
       }
       if(mrace == "half-elf") {
         switch(random(5)) {
            case 0..3:
            break;
            case 4:
               force_me("speak elven");
               force_me("emoteat "+TPQN+ " turns to $N and blinks disbelievingly.");
               force_me("say %^GREEN%^I've not seen one of your kind before. You look like you are both elf and human.%^RESET%^");
               force_me("emoteat "+TPQN+ " hmms and looks to $N again.");
               force_me("emote shakes his head slightly.");
               force_me("say %^GREEN%^I am sorry, I will have to ask you to leave.%^RESET%^");
               command("emote sighs and bows.");
            break;
         }
      return 1;
      }
	         if(mrace == "squole") {
         switch(random(5)) {
            case 0..3:
            break;
            case 4:
               force_me("speak elven");
               force_me("emoteat "+TPQN+ " turns to $N and blinks disbelievingly.");
               force_me("emoteat "+TPQN+ " hmms and looks to $N again.");
               force_me("emote shakes his head slightly.");
               force_me("say %^GREEN%^I am sorry, I will have to ask you to leave.%^RESET%^");
               command("emote sighs and bows.");
            break;
         }
      return 1;
			 }
      if(mrace == "voadkyn") {
         switch(random(5)) {
            case 0..3:
            break;
            case 4:
               force_me("speak elven");
               force_me("emoteat "+TPQN+ " turns to $N.");
               force_me("say %^GREEN%^Greetings Voadkyn and welcome to our home.%^RESET%^");
               command("emote smiles and bows."); 
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
               force_me("emoteat "+TPQN+ " turns to $N.");
               force_me("say %^GREEN%^I am sorry human, but your kind is not allowed in here. Please leave.%^RESET%^");
               command("emote bows.");
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
               force_me("emoteat "+TPQN+ " turns to $N.");
               force_me("say %^GREEN%^I am sorry dwarf, but your kind is not allowed in here. Please leave.%^RESET%^");
               command("emote bows.");
            break;
         }
       return 1;
       }
       if(mrace == "halfling") {
          switch(random(5)) {
             case 0..3:
             break;
             case 4:
                force_me("speak elven");
                force_me("emoteat "+TPQN+ " turns to $N.");
                force_me("say %^GREEN%^Greetings halfling.%^RESET%^");
                command("emote nods slightly.");
             break;
         }
       return 1;
       }
       if(mrace == "gnome") {
          switch(random(5)) {
             case 0..3:
             break;
             case 4:
                force_me("speak elven");
                force_me("emoteat "+TPQN+ " turns to $N.");
                force_me("say %^GREEN%^Greetings gnome.%^RESET%^");
                command("emote nods slightly.");
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
               force_me("emoteat "+TPQN+ " turns to $N.");
               force_me("say %^GREEN%^Greetings big one and I apologize, but I must ask you to leave.%^RESET%^");
               command("emoteat "+TPQN+ " bows before $N respectfully.");
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
                 force_me("emoteat "+TPQN+ " turns to $N and bows slightly.");
                 force_me("say %^GREEN%^I must ask you to leave furry one.");
                 command("say You will make the young ones nervous.%^RESET%^");
              break;
          }
      }
      else {
        force_me("speak elven");
        force_me("say %^GREEN%^Be gone from our forests!%^RESET%^");
        force_me("say %^GREEN%^Your kind has done enough damage already!%^RESET%^");
        command ("kill "+TPQN);
     }
}
