//http://www.popartuk.com/g/l/lgSM0074.jpg - inspiration for sea monster
#include <std.h>
#include <daemons.h>
#include "../seneca.h"

inherit WEAPONLESS;

void create(){
   ::create();
   set_name("Aysu");
   set_id(({"monster","terror","sea monster","aysu","Aysu","terror of the night sea","Terror of the Night Sea"}));
   set_short("%^BOLD%^%^CYAN%^Aysu%^BLUE%^, %^BLACK%^Terror "+
      "%^BLUE%^of the %^BLUE%^N%^BLACK%^i%^BLUE%^g%^BLACK%^h"+
      "%^BLUE%^t %^BLACK%^S%^BLUE%^e%^BLACK%^a%^RESET%^");
   set_long("%^RESET%^%^CYAN%^Beautiful and terrifying at once, "+
      "this monstrous %^BOLD%^sea serpent %^RESET%^%^CYAN%^is "+
      "covered in glittering scales that %^BOLD%^%^BLUE%^s%^CYAN%^"+
      "h%^BLACK%^i%^WHITE%^m%^GREEN%^m%^BOLD%^e%^RESET%^%^CYAN%^r "+
      "with %^BOLD%^ir%^BLUE%^i%^CYAN%^de%^GREEN%^s%^CYAN%^ce"+
      "%^WHITE%^n%^CYAN%^t %^BLUE%^b%^CYAN%^l%^BLUE%^u%^CYAN%^e"+
      "%^BLUE%^s%^RESET%^%^CYAN%^, %^BOLD%^%^BLACK%^b%^RESET%^l"+
      "%^BOLD%^%^BLACK%^a%^RESET%^c%^BOLD%^%^BLACK%^k%^RESET%^s"+
      "%^CYAN%^, %^BOLD%^%^WHITE%^w%^RESET%^h%^BOLD%^i%^RESET%^t"+
      "%^BOLD%^e%^RESET%^s%^CYAN%^, and %^BOLD%^%^GREEN%^g%^RESET%^"+
      "%^GREEN%^r%^BOLD%^e%^RESET%^%^GREEN%^e%^BOLD%^n%^RESET%^"+
      "%^GREEN%^s%^CYAN%^.  The diamater of her cylindrical body "+
      "is easily taller than most fully grown men, and despite her "+
      "coils, her tail disappears into the depths of the sea.  Her "+
      "%^RESET%^underbelly %^CYAN%^is much lighter in color and "+
      "presumably softer than the rest of her body, though the "+
      "apparent toughness does little to inspire confidence.  Most "+
      "awe-inspiring is the gigantic head that rests atop a "+
      "somewhat slender neck, its gaping %^RED%^jaws %^CYAN%^filled "+
      "with row upon row of sharp, needle-like %^BOLD%^%^WHITE%^teeth"+
      "%^RESET%^%^CYAN%^.  Transluscent %^BOLD%^fins%^RESET%^%^CYAN%^ "+
      "fan out to either side of the creature's jaws, forming a "+
      "frame for her wide, glistening eyes that sparkle with %^BOLD%^"+
      "%^BLACK%^malice%^RESET%^%^CYAN%^.%^RESET%^");
   set_hd(34,8);
   set_hp(2550);
   set_max_hp(2550);
   set_class("fighter");
   set_class("mage");
   set_guild_level("fighter",34);
   set_guild_level("mage",34);
   set_mlevel("fighter",34);
   set_mlevel("mage",34);
   set_exp(70000);
   set_overall_ac(-30);
   set_race("sea monster");
   set_body_type("snake");
   set_attack_limbs(({"mouth"}));
   set_attacks_num(3);
   set_damage(1,20);
   set_property("full attacks",1);
   set_hit_funcs((["mouth":(:TO,"mouth_attack":)]));
   set_base_damage_type("slashing");
   set("aggressive",20);
   set_funcs(({"squeeze","sonic"}));
   set_func_chance(40);
   set_gender("female");
   set_alignment(9);
   set_mob_magic_resistance("average");
   set_property("no death",1);
   set_property("no hold", 1);
   set_property("no paralyze", 1);
   set_property("no steal",1);
}

int mouth_attack(object targ){
   if(!objectp(TO)) return 1;
   if(!objectp(ETO)) return 1;
   if(!objectp(targ)) return 1;
   if(!random(2)){
      tell_object(targ,"%^BOLD%^%^RED%^The gaping maw of the sea "+
         "monster tear into you, shredding your skin before finally "+
         "releasing you!%^RESET%^");
      tell_room(ETO,"%^BOLD%^%^RED%^A pool of %^RESET%^%^RED%^blood "+
         "%^BOLD%^fans out around "+targ->QCN+" as the sea monster "+
         "rips into "+targ->QP+" flesh!%^RESET%^",({targ,TO}));
      targ->do_damage(targ->return_target_limb(),roll_dice(3,25));
      if(!random(5)){
         tell_room(ETO,"%^BOLD%^%^BLACK%^The %^RED%^blood%^BLACK%^ "+
            "in the water attracts a nearby shark!%^RESET%^");
         new(MON"dire_shark")->move(ETO);
         return 1;
      }
   }
   return roll_dice(2,20);
}

int squeeze(){
   object *targets,targ;
   int i;
   if(!objectp(TO)) return 1;
   if(!objectp(ETO)) return 1;
   targets = TO->query_attackers();
   targ = targets[random(sizeof(targets))];
   if(!objectp(targ)) return 1;
   tell_room(ETO,"%^BOLD%^%^BLUE%^Suddenly, the serpent's "+
      "tail snakes out of the %^BLACK%^blackness%^BLUE%^ of "+
      "the sea and coils around "+targ->QCN+"!%^RESET%^",({targ,TO}));
   tell_object(targ,"%^BOLD%^%^BLUE%^Suddenly, the serpent's "+
      "tail snakes out of the %^BLACK%^blackness%^BLUE%^ of "+
      "the sea and coils around you!%^RESET%^");
   if(!SAVING_D->saving_throw(targ,"spell",0)){
      targ->do_damage(targ->return_target_limb(),roll_dice(20,6));
      targ->set_tripped(roll_dice(1,4),"You are caught up in the coils of the serpent!");
   }else{
      targ->do_damage(targ->return_target_limb(),roll_dice(20,3));
   }
   return 1;
}

int sonic(){
   object *targets,targ;
   int i;
   if(!objectp(TO)) return 1;
   if(!objectp(ETO)) return 1;
   targets = TO->query_attackers();
   tell_room(ETO,"%^BOLD%^%^BLUE%^The serpent opens her mouth, "+
      "and her %^CYAN%^eyes %^BLUE%^flash%^RESET%^ "+
      "%^BOLD%^%^BLUE%^as she emits a horrifying shriek!%^RESET%^",TO);
   if(sizeof(targets)){
      for(i=0;i<sizeof(targets);i++){
         targ = targets[i];
         if(!objectp(targ)) continue;
         tell_object(targ,"%^BOLD%^%^CYAN%^You feel the force of the "+
            "scream rip through your mind!%^RESET%^");
         if(!SAVING_D->saving_throw(targ,"spell",0)){
            targ->do_damage(targ->return_target_limb(),roll_dice(30,4));
         }else{
            targ->do_damage(targ->return_target_limb(),roll_dice(30,2));
            targ->set_paralyzed(roll_dice(2,4),"You are recovering from the shriek!");
         }
      }
   }
}

void heart_beat(){
   ::heart_beat();
   if(!objectp(TO)) return;
   if(!objectp(ETO)) return;
   if(query_attackers() != ({}))
      add_hp(55);
    else set_hp(query_max_hp());
}

void set_paralyzed(int time, string mes){
   if(!PO->is_spell())
      return ::set_paralyzed(time,mes);
   return;
}

void set_bound(int xxx, string msg) {return 1;}

void set_tripped(int xxx, string msg) {return 1;}

int test_heart(){return 1;}
