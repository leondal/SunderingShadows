#include <std.h>
#include <daemons.h>

inherit WEAPONLESS;

int bleed_em(object targ);

void create(){
   ::create();
   set_name("Cuan'savinos");
   set_id(({"hound","dog","three-headed dog","three headed dog","Cuan'savinos","cuan'savinos","cuan","hound of the nine hells"}));
   set_short("%^BOLD%^%^BLACK%^Cuan'savinos%^RESET%^%^RED%^, "+
      "Hound of the %^BOLD%^Nine Hells%^RESET%^");
   set_long("%^RESET%^%^RED%^This snarling hound is a force to "+
      "be reckoned with.  Though he stands only four feet at the "+
      "shoulder, it is clear that this is anything but a normal "+
      "mastiff.  %^BOLD%^Scarlet eyes %^RESET%^%^RED%^that burn "+
      "with the %^BOLD%^f%^YELLOW%^i%^RED%^r%^WHITE%^e%^RED%^s of "+
      "h%^BLACK%^e%^RED%^ll %^RESET%^%^RED%^glower above the "+
      "%^RESET%^snapping jaws %^RED%^on each of his three heads "+
      "while a writhing mass of %^GREEN%^ve%^BOLD%^n%^RESET%^"+
      "%^GREEN%^om%^BOLD%^%^BLACK%^o%^RESET%^%^GREEN%^us sn"+
      "%^YELLOW%^a%^RESET%^%^GREEN%^k%^BOLD%^e%^RESET%^%^GREEN%^s "+
      "%^RED%^forms a mane down his muscular back.  Curled into a "+
      "snarl, each mouth reveals a vicious set of %^BOLD%^%^WHITE%^"+
      "teeth %^RESET%^%^RED%^with canines reaching half a foot in "+
      "length and tinged in some red substance horribly "+
      "reminiscent of %^BOLD%^blood%^RESET%^%^RED%^.  Each of the "+
      "beast's paws are tipped with %^BOLD%^%^BLACK%^curving claws "+
      "%^RESET%^%^RED%^sharpened to needle-like points that seem "+
      "ready to rip into the flesh of anyone who dares wander too "+
      "close.  Rather than being covered in fur, the hulking body "+
      "seems to be plated with thick %^BOLD%^%^BLACK%^b%^RESET%^l"+
      "%^BOLD%^%^BLACK%^a%^RESET%^c%^BOLD%^%^BLACK%^k %^RESET%^s"+
      "%^BOLD%^%^BLACK%^c%^RESET%^a%^BOLD%^%^BLACK%^l%^RESET%^e"+
      "%^BOLD%^%^BLACK%^s %^RESET%^%^RED%^that glitter like "+
      "%^BOLD%^%^BLACK%^obs%^WHITE%^i%^BLACK%^dian%^RESET%^%^RED%^.  "+
      "Adding to the horrifying appearance is a long, sleek tail "+
      "tipped with a %^BOLD%^%^BLACK%^viper's %^RESET%^%^RED%^"+
      "hissing mouth.%^RESET%^");
   set_hd(34,8);
   set_hp(2050);
   set_max_hp(2050);
   set_class("fighter");
   set_class("mage");
   set_guild_level("fighter",34);
   set_guild_level("mage",34);
   set_mlevel("fighter",34);
   set_mlevel("mage",34);
   set_exp(70000);
   set_overall_ac(-30);
   set_race("hell hound");
   set_body_type("quadruped");
   add_limb("left head","torso",0,0,0);
   add_limb("right head","torso",0,0,0);
   add_limb("left mouth","left head",0,0,0);
   add_limb("right mouth","right head",0,0,0);
   add_limb("tail","torso",0,0,0);
   set_attack_limbs(({"right mouth","left mouth","mouth","right forepaw","left forepaw","tail"}));
   set_attacks_num(3);
   set_damage(1,20);
   set_property("full attacks",1);
   set_hit_funcs((["mouth":(:TO,"mouth_attack":),"right mouth":(:TO,"mouth_attack":),"left mouth":(:TO,"mouth_attack":),"tail":(:TO,"tail_attack":),"right forepaw":(:TO,"paw_attack":),"left forepaw":(:TO,"paw_attack":)]));
   set_base_damage_type("slashing");
   set("aggressive",20);
   set_funcs(({"fire"}));
   set_func_chance(20);
   set_gender("male");
//   add_money("gold",random(20000));
//   add_money("platinum",random(1000));
   set_alignment(3);
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
   if(!random(3)){
      tell_object(targ,"%^BOLD%^%^BLACK%^The snarling, snapping "+
         "%^RED%^jaws%^BLACK%^ of the hell hound close upon you, "+
         "%^RED%^shredding %^BLACK%^your flesh!%^RESET%^");
      tell_room(ETO,"%^BOLD%^%^BLACK%^The hell hound bites "+targ->QCN+" "+
         "viciously, %^RED%^shredding %^BLACK%^"+targ->QP+" "+
         "flesh!%^RESET%^",({targ,TO}));
      return roll_dice(3,25);
   }
   return roll_dice(2,15);
}

int paw_attack(object targ){
   if(!objectp(TO)) return 1;
   if(!objectp(ETO)) return 1;
   if(!objectp(targ)) return 1;
   if(!random(2)){
      tell_object(targ,"%^RESET%^%^RED%^The %^BOLD%^hell hound "+
         "%^RESET%^%^RED%^swipes at you "+
         "with a massive paw, its claws making your skin burn as "+
         "it knocks you off balance!%^RESET%^");
      tell_room(ETO,"%^RESET%^%^RED%^The %^BOLD%^hell hound "+
         "%^RESET%^%^RED%^swipes at "+targ->QCN+" with a massive "+
         "paw, knocking "+targ->QO+" off balance!%^RESET%^",({targ,TO}));
      targ->set_tripped(roll_dice(1,4),"You are stunned from the might of the hell hound's paw!");
      return roll_dice(2,20);
   }
   return roll_dice(2,10);
}

int tail_attack(object targ){
   if(!objectp(TO)) return 1;
   if(!objectp(ETO)) return 1;
   if(!objectp(targ)) return 1;
   if(!random(4)){
      tell_object(targ,"%^RESET%^%^GREEN%^The tail of the hell hound "+
         "suddenly whips around, its %^BOLD%^viper %^RESET%^%^GREEN%^"+
         "mouth striking you!%^RESET%^");
      tell_room(ETO,"%^RESET%^%^GREEN%^The tail of the hell hound "+
         "suddenly whips around, its %^BOLD%^viper %^RESET%^%^GREEN%^"+
         "mouth striking "+targ->QCN+"!%^RESET%^",({targ,TO}));
      call_out("bleed_em",2,targ);
      return roll_dice(2,30);
   }
   return roll_dice(2,10);
}

int bleed_em(object targ){
   if(!objectp(targ)) return 1;
   if(!objectp(TO)) return 1;
   if(!objectp(ETO)) return 1;
   tell_object(targ,"%^BOLD%^%^GREEN%^The bite of the viper tail "+
      "burns like %^RESET%^%^GREEN%^acid %^BOLD%^through your veins!%^RESET%^");
   set_property("magic",1);
   targ->do_damage("torso",random(26)+25);
   set_property("magic",-1);
   return 1;
}

int fire(){
   object *targets,targ;
   int i;
   if(!objectp(TO)) return 1;
   if(!objectp(ETO)) return 1;
   targets = TO->query_attackers();
   tell_room(ETO,"%^BOLD%^%^BLACK%^Eyes smoldering with %^RED%^fl"+
      "%^YELLOW%^a%^RED%^me%^BLACK%^, the hell hound opens his "+
      "gaping maw and spews forth a cloud of %^RED%^f%^YELLOW%^i"+
      "%^RED%^re%^BLACK%^, scorching all in its path!%^RESET%^",TO);
   if(sizeof(targets)){
      for(i=0;i<sizeof(targets);i++){
         targ = targets[i];
         if(!objectp(targ)) continue;
         tell_object(targ,"%^BOLD%^%^RED%^You feel the heat of the "+
            "flames blister your flesh!%^RESET%^");
         if(!SAVING_D->saving_throw(targ,"spell",0))
            targ->do_damage(targ->return_target_limb(),roll_dice(30,4));
         else
            targ->do_damage(targ->return_target_limb(),roll_dice(30,2));
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
