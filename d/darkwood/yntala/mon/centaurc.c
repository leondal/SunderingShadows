#include <std.h>
#include "../yntala.h"
inherit WEAPONLESS;
void create (){

::create ();
   set_name("Centaur child");
   set_id(({"Centaur Child","centaur child","centaur","child"}));
   set_short("%^RESET%^%^MAGENTA%^Centaur child%^RESET%^");
   set_long("%^RESET%^%^GREEN%^This young centaur looks much like"
" the others but smaller.  It has a slender horselike body that"
" leads up into a childish torso and baby-like face.  It has wide"
" %^ORANGE%^brown eyes %^GREEN%^that gaze around its"
" surroundings in wonder, and long, flowing %^ORANGE%^brown hair"
" %^GREEN%^that rests gently on its shoulders.");
   set_race("centaur");
   set_gender("male");
   set_body_type("centaur");
   set_overall_ac(-1);
   set_hd(12,2);
   set_size(2);
   set_stats("intelligence",18);
   set_stats("strength",18);
   set_stats("wisdom",13);
   set_stats("dexterity",14);
   set_stats("constitution",15);
   set_stats("charisma",11);
   set_money("gold",random(100));
   set_money("silver",random(100));
   set_money("copper",random(50));
   set_money("electrum",random(75));
   set_class("thief");
   set_exp(50);
   set_alignment(4);
   set_moving(1);
   set_nogo(({INRMS+"thornroom"}));
   set_speed(8);
   set_damage(1,6);
   add_limb("left hoof","left foreleg",0,0,0);
   add_limb("right hoof","right foreleg",0,0,0);
   set_attack_limbs(({"right hoof","left hoof"}));
   set_base_damage_type("bludgeoning");
   set_hp(random(50)+100);
   set_max_hp(query_hp());  
   set_thief_skill("hide in shadows",95);
   add_search_path("/cmds/thief");
   set_property("full attack",1);
   set("aggressive","aggfunc");
   set_mlevel("thief",6);
    set_achats(10, ({"%^GREEN%^The centaur shrieks in fear!%^RESET%^",
"%^RESET%^%^GREEN%^The child tries to dodge your blows!%^RESET%^"}) );
    set_emotes(1, ({"%^RESET%^%^ORANGE%^The centaur child gallops across the %^GREEN%^grassy %^BOLD%^%^GREEN%^meadow.%^RESET%^",
"%^GREEN%^The small centaur tries to mimic the actions of the older members of its tribe.  It rears up and then charges across the meadow.%^RESET%^",
"%^BOLD%^%^GREEN%^The centaur child throws a stick high into the air and then catches it.%^RESET%^",
"%^GREEN%^The child practices moving stealthily around the %^BOLD%^%^GREEN%^meadow, %^RESET%^%^GREEN%^darting in and out of the %^BOLD%^%^BLACK%^shadows %^RESET%^%^GREEN%^created by the few trees.%^RESET%^",
}), 0);
}

void die(object ob) {
   tell_room(ETO,
"%^BOLD%^%^RED%^The centaur writhes in pain as it cries out for its mother before collapsing to the ground.%^RESET%^");
:: die(ob);
}

int aggfunc() {
   string mrace=TP->query_race();
     if(mrace == "centaur") {
      switch(random(10)){
          case 0..6:
          break;
          case 7:
             force_me("speak elven");
             force_me("speech say in a childish voice");
             force_me("emoteat "+TPQN+ " gallops up to $N.");
             force_me("say %^RESET%^%^GREEN%^Hello there, it so nice to see you!");
             force_me("emoteat "+TPQN+ " smiles brightly before returning to its play.");
           break;
           case 8:
              force_me("emoteat "+TPQN+ " waves to $N excitedly before continuing its play.");
           break;
           case 9:
              force_me("speak elven");
              force_me("speech say in an innocent voice");
              force_me("emoteat "+TPQN+ " gallops up to $N excitedly.");
              force_me("say Have you come to trade something neat?");
              force_me("emoteat "+TPQN+ " looks up at $N questioningly before galloping away
again.");
           break;
       }
        return 1;
   }
      if(mrace == "elf") {
      switch(random(10)){
          case 0..6:
          break;
          case 7:
             force_me("speak elven");
             force_me("speech say in a childish voice");
             force_me("emoteat "+TPQN+ " gallops up to $N.");
             force_me("say %^GREEN%^Hello there, it so nice to see elves around here.");
             force_me("emoteat "+TPQN+ " smiles brightly before returning to its play.");
           break;
           case 8:
              force_me("speak elven");
              force_me("speech say in awe");
              force_me("say An elf!");
              force_me("emoteat "+TPQN+ " waves to $N excitedly before continuing its play.");
           break;
           case 9:
              force_me("speak elven");
              force_me("speech say in an innocent voice");
              force_me("emoteat "+TPQN+ " gallops up to $N excitedly.");
              force_me("say Have you come to trade something neat?");
              force_me("emoteat "+TPQN+ " looks up at $N questioningly before galloping away again.");
           break;
       }
        return 1;
   }
   if(mrace == "half-elf") {
      switch(random(10)){
         case 0..6:
         break;
         case 7:
            force_me("speak elven");
            force_me("speech say in a childish voice");
            force_me("emoteat "+TPQN+ " looks up at $N curiously.");
            force_me("say %^GREEN%^wow.%^RESET%^");
            force_me("emoteat "+TPQN+ " circles $N before poking $O with a curious expression on its face.");
            force_me("emote tilts its head slightly before shrugging and returning to its play.");
         break;
         case 8:
            force_me("speak elven");
            force_me("speech say with pure childish innocence");
            force_me("emoteat "+TPQN+ " stops playing and looks at $N while tilting its head slightly.");
            force_me("say What are you?");
            force_me("emoteat "+TPQN+ " looks at $N again warily before quickly disappearing.");
            set_hidden(1);
         break;
         case 9:
            force_me("speak elven");
            force_me("speech say in a childs voice");
            force_me("emoteat "+TPQN+ " wrinkles its nose as it looks at $N.");
            force_me("say You are the funniest looking elf I've ever seen.");
            force_me("emoteat "+TPQN+ " ignores $N and continues playing.");
         break;
      }
   return 1;
   }
   else {
      force_me("emoteat "+TPQN+ " shrieks in fear as it sees $N and attempts to %^BOLD%^%^BLACK%^hide %^RESET%^in the %^GREEN%^trees.%^RESET%^");
      set_hidden(1);
   }
}
