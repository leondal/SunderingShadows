#include <std.h>
#include <daemons.h>
#include "../yntala.h"
inherit WEAPONLESS;


void create (){

::create ();
   set_name("Yanlaidaer");
   set_id(({"female centaur","Yanlaidaer","yanlaidaer","centaur","cleric"}));
   set_short("%^RESET%^%^ORANGE%^A female centaur%^RESET%^");
   set_long("%^RESET%^%^ORANGE%^This is a tall and stately female"
" centaur with long %^YELLOW%^g%^RESET%^%^ORANGE%^o%^YELLOW%^ld"
"%^RESET%^%^ORANGE%^e%^YELLOW%^n %^RESET%^%^ORANGE%^hair that"
" flows down her back.  She has warm brown eyes and a kind smile,"
" but something about her posture shows she is very protective of"
" her meadow.  The coat on her horse-like body %^RESET%^gleams"
" %^ORANGE%^in the %^YELLOW%^sunlight, %^RESET%^%^ORANGE%^and it"
" is obvious that she is very well taken care of.");
   set_race("centaur");
   set_gender("female");
   set_body_type("centaur");
   set_hd(19,2);
   set_overall_ac(-8);
   set_size(2);
   set_stats("intelligence",15);
   set_stats("strength",18);
   set_stats("wisdom",18);
   set_stats("dexterity",14);
   set_stats("constitution",15);
   set_stats("charisma",11);
   set_money("gold",random(1000));
   set_money("silver",random(100));
   set_money("copper",random(50));
   set_money("electrum",random(75));
   set_class("cleric");
   set_exp(2500);
   set_alignment(4);
   set_hp(random(200)+100);
   set_max_hp(query_hp());  
   set("aggressive","aggfunc");
   set_mlevel("cleric",19);
   set_damage(2,6);
   add_limb("left hoof","left foreleg",0,0,0);
   add_limb("right hoof","right foreleg",0,0,0);
   set_attack_limbs(({"right hoof","left hoof"}));
   set_base_damage_type("bludgeoning");
   set_spell_chance(95);
   set_spells(({"call lightning","limb attack","sticks into snakes","create treant","cause critical wounds"}));
    set_achats(10, ({"%^MAGENTA%^The female centaur looks at you angrily.%^RESET%^",
"%^RESET%^%^GREEN%^The female centaur rears up on her hind legs, causing her hair to fly wildly behind her.%^RESET%^"}) );
    set_emotes(1, ({"%^RESET%^%^ORANGE%^The female centaur brushes a few strands of her long hair over her shoulder.%^RESET%^",
      "%^GREEN%^The female centaur glances up at the playing children and smiles.%^RESET%^",
      "%^RESET%^The %^RESET%^%^ORANGE%^centaur %^RESET%^tends to some fish cooking over the %^RED%^fire%^RESET%^.",
      "RESET%^%^GREEN%^The %^ORANGE%^centaur %^GREEN%^takes some %^ORANGE%^firewood %^GREEN%^from the stack and stokes the %^RED%^fire.%^RESET%^",
}), 0);
}

void die(object ob) {
   tell_room(ETO,
"%^MAGENTA%^The centaur looks up at you with pleading eyes and stretches her hand out towards what remaining children there are before collapsing on the ground.%^RESET%^");
:: die(ob);
}

int aggfunc() {
   string mrace=TP->query_race();
         if(mrace == "centaur") {       
               force_me("speak elven");
               force_me("emoteat "+TPQN+ " turns to $N.");
               force_me("say %^RESET%^%^GREEN%^Greetings friend, but I am afraid I've only got this cloak to trade at
the moment, have you brought me the dark one from those evil beings infesting this forest?");
               command("emoteat "+TPQN+ " smiles warmly and bows before $N.");
      return 1;
        }
         if(mrace == "elf"||"nymph"||"dryad"||"deva") { 
         switch(random(5)) {
            case 0:
            break;
            case 1..4:
               force_me("speak elven");
               force_me("emoteat "+TPQN+ " turns to $N.");
               force_me("say %^GREEN%^Greetings friend, but I am afraid I've only got this cloak to trade at the moment, have you brought me the dark one from those evil beings infesting this forest?");
               command("emoteat "+TPQN+ " smiles warmly and bows before $N.");
            break;
         }
      return 1;
	}
      if(mrace == "half-elf"||"squole") {
         switch(random(5)) {
            case 0:
            break;
            case 1..4:
               force_me("speak elven");
               force_me("emoteat "+TPQN+ " turns to $N and blinks.");
               force_me("say %^GREEN%^How did you get past the guard?%^RESET%^");
               force_me("emoteat "+TPQN+ " hmms and looks to $N again.");
               force_me("emote shakes her head slowly.");
               force_me("say %^GREEN%^I do not know how you got in, but if he let you in, I suppose you are alright.  I am afraid I've only got this cloak to trade at the moment, have you brought me the dark one from those evil beings infesting this forest?");
               command("emote sighs and bows.");
            break;
         }
      return 1;
      }
      if(mrace == "voadkyn") {
         switch(random(5)) {
            case 0:
            break;
            case 1..4:
               force_me("speak voadkyn");
               force_me("emoteat "+TPQN+ " turns to $N.");
               force_me("say %^GREEN%^Greetings voadkyn, and welcome to our home.  I am afraid I've only got this cloak to trade at the moment, have you brought me the dark one from those evil beings infesting this forest?");
               command("emote smiles and bows."); 
            break;
         }
      return 1;
      }
      if(mrace == "human") {
         switch(random(5)) {
            case 0:
            break;
            case 1..4:
               force_me("speak elven");
               force_me("emoteat "+TPQN+ " turns to $N and frowns slightly.");
               force_me("say %^GREEN%^I am sorry human, but I'd not trade with your kind. I do not know how you got past the guard, but please leave.%^RESET%^");
               command("emote bows.");
            break;
          }
      return 1;
      }
      if(mrace == "dwarf") {
         switch(random(5)) {
            case 0:
            break;
            case 1..4:
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
            case 0:
            break;
            case 1..4:
               force_me("speak halfling");
               force_me("emoteat "+TPQN+ " turns to $N.");
               force_me("say %^GREEN%^Greetings halfling, but I am afraid I've only got this cloak to trade at the moment, have you brought me the dark one from those evil beings infesting this forest?");
               command("emote nods slightly.");
            break;
         }
      return 1;
      }
      if(mrace == "gnome") {
         switch(random(5)) {
            case 0:
            break;
            case 1..4:
               force_me("speak gnomish");
               force_me("emoteat "+TPQN+ " turns to $N.");
               force_me("say %^GREEN%^Greetings gnome, but I am afraid I've only got this cloak to trade at the moment, have you brought me the dark one from those evil beings infesting this forest?");
               command("emote nods slightly.");
            break;
         }
      return 1;
      }
      if(mrace == "firbolg") {
         switch(random(5)) {
            case 0:
            break;
            case 1..4:
               force_me("speak elven");
               force_me("emoteat "+TPQN+ " turns to $N and looks up.");
               force_me("say %^GREEN%^Greetings tall one.  I am afraid I've only got this cloak to trade at the moment, have you brought me the dark one from those evil beings infesting this forest?");
               command("emoteat "+TPQN+ " bows before $N respectfully.");
            break;
         }
      return 1;
      }
      if(mrace == "wemic" || mrace == "beastman") {
         switch(random(5)) {
            case 0:
            break;
            case 1..4:
               force_me("speak elven");
               force_me("emoteat "+TPQN+ " turns to $N and bows slightly.");
               force_me("say %^GREEN%^I must ask you to leave.");
               command("say You will make the young ones nervous.%^RESET%^");
               force_me("emote motions to the playing children in the distance.");
             break;
         }
      }
      else {
         force_me("speak elven");
         force_me("say %^GREEN%^Be gone from our forests!%^RESET%^");
         force_me("say %^GREEN%^I do not know how you got past the guard, but you will not get past me!%^RESET%^");
         command ("kill "+TPQN);
     }
}
void receive_given_item(object obj){
   string name;
   object obj2;
   if(!objectp(obj)) return;
   name = obj->query_name();
   if(name == "%^BOLD%^%^BLACK%^Cloak of Midnight%^RESET%^") {
      obj->remove();
      obj2 = new("/d/darkwood/yntala/obj/forestcloak");
      force_me("say Ah, I am glad to be rid of this, so long have these beings been corrupting our forest.");
      force_me("emote turns to you with a pleased expression.");
      force_me("say It is good to see people have not given up on the once beautiful Yntala Forests.  For your help,"
" I will trade you the cloak of the forests.  It is a special cloak that allows you to"
" blend in to the surrounding forests when you %^BOLD%^lift the hood.  %^RESET%^It is dear to us, please guard it carefully.");
      if((int)obj2->move(TP) != 0) {
         obj2->move(ETO);
         return 1;
      }
   }
   else{
      force_me("say This is not what I am looking for, I am looking to see that you are helping destroy the evil in this forest.  Please bring me back the cloak the yuan-ti wear as proof of that.");
   }
}
