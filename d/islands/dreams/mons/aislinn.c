//difficulty adapted from Muln and adjusted from there
//by Circe 3/19/05 for the dream area
//difficulty increased a bit and drops adjusted ~Circe~ 10/14/19

#include <std.h>
#include <daemons.h>
#include "../defs.h"

inherit WEAPONLESS;

void hit_something();

void create(){
    object ob;
    int dlvl;
    ::create();
    set_name("aislinn");
    set_id(({"dragon","dream","prismatic","dream dragon","prismatic dragon","aislinn","dragon of dreams","dreammon"}));
    set_short("Aislinn, Dragon of Dreams");
    set_long("%^BOLD%^%^MAGENTA%^S%^RESET%^%^MAGENTA%^h%^BOLD%^i%^RESET%^%^MAGENTA%^m%^BOLD%^m%^RESET%^%^MAGENTA%^e%^BOLD%^r%^RESET%^%^MAGENTA%^i%^BOLD%^n%^RESET%^%^MAGENTA%^g forth from the %^BOLD%^%^CYAN%^air %^RESET%^%^MAGENTA%^itself is the lithe, sinuous form of a %^BOLD%^%^CYAN%^p%^BLUE%^r%^GREEN%^i%^YELLOW%^s%^RED%^m%^MAGENTA%^a%^CYAN%^t%^BLUE%^i%^GREEN%^c %^BOLD%^%^MAGENTA%^dragon%^RESET%^%^MAGENTA%^!  Her slender body glides through the %^BOLD%^%^CYAN%^air %^RESET%^%^MAGENTA%^shrouded by a %^BOLD%^%^WHITE%^dream-like haze %^RESET%^%^MAGENTA%^that makes her true form difficult to detect.  Delicate %^YELLOW%^wisps %^RESET%^%^MAGENTA%^of %^ORANGE%^s%^YELLOW%^c%^WHITE%^i%^YELLOW%^n%^RESET%^%^ORANGE%^t%^RESET%^i%^ORANGE%^l%^YELLOW%^l%^WHITE%^a%^YELLOW%^t%^RESET%^%^ORANGE%^i%^RESET%^n%^ORANGE%^g %^YELLOW%^golds %^RESET%^%^MAGENTA%^mask her face, all but hiding her %^BOLD%^luminous orbs %^RESET%^%^MAGENTA%^of %^CYAN%^g%^BOLD%^l%^BLUE%^e%^RESET%^%^CYAN%^a%^BOLD%^m%^BLUE%^i%^RESET%^%^CYAN%^n%^BOLD%^g %^BLUE%^blue%^RESET%^%^MAGENTA%^.  Her %^BOLD%^%^BLUE%^eyes %^CYAN%^t%^BLUE%^w%^CYAN%^i%^BLUE%^n%^CYAN%^k%^BLUE%^l%^CYAN%^e %^RESET%^%^MAGENTA%^with %^BOLD%^hidden secrets%^RESET%^%^MAGENTA%^ and %^CYAN%^stolen knowledge%^MAGENTA%^ above a %^RESET%^wicked grin %^MAGENTA%^revealing rows of %^BOLD%^%^WHITE%^barbed teeth %^RESET%^%^MAGENTA%^that make her seem anything but gentle.  Her slender body floats on the %^BOLD%^%^CYAN%^air%^RESET%^%^MAGENTA%^, making her short legs seem almost frivolous.  Each leg ends in an outstretched %^RESET%^clawed foot %^MAGENTA%^that looks frighteningly real.  Her %^BOLD%^%^CYAN%^diaphonous wings %^RESET%^%^MAGENTA%^shift in size and shape - now a %^YELLOW%^butterfly's wings%^RESET%^%^MAGENTA%^, now slim and long as a %^GREEN%^dragonfly's%^MAGENTA%^.  Her body writhes around her, seeming to swim through the %^BOLD%^%^CYAN%^air %^RESET%^%^MAGENTA%^and bringing into focus her unusual tail - a tail that splits into two ends, one a %^BOLD%^%^WHITE%^glistening white%^RESET%^%^MAGENTA%^, the other %^BOLD%^%^BLACK%^dark as the abyss%^RESET%^%^MAGENTA%^.%^RESET%^");
    set_race("dragon");
    set_gender("female");
    set_alignment(6);
    set_size(4);
    set_class("mage");
    set_class("thief");
    dlvl = 40+random(11);
    set_hd(dlvl,8);
    set_mlevel("mage",dlvl);
    set_mlevel("thief",dlvl);
    set_hp((dlvl * 75) + random(dlvl));
    set_guild_level("mage",dlvl);
    set_guild_level("thief",dlvl);
    set_attack_bonus(12);
    set_mob_magic_resistance("average");
    set_property("no dominate",1);
    set_property("no death",1);
    set_property("no rush",1);
    set_property("swarm",1);
    set_property("no bows",1);
    set_property("no steal",1);
    set_stats("strength",23);
    set_stats("dexterity",18);
    set_exp(60000);
    set_overall_ac(-13);
    add_limb("mouth", "head", 0, 0, 0);
    set_attack_limbs(({"right foreclaw","left foreclaw","tail","mouth"}));
    set_attacks_num(3);
    set_base_damage_type("slashing");
    set_damage(3,8);
    set_funcs(({"breath","breath","breath","wings","nightmare"}));
    set_func_chance(80);
    set_hit_funcs((["tail" : (:TO,"sting":) ]));
    ob = new("/d/common/obj/brewing/herb_special_inherit");
    ob->set_herb_name("dream fragment");
    ob->move(TO);
}

void breath(){
   object *live;
   object *fodder;
   object targ;
   int i = 0;
   int x;
   live = all_inventory(ETO);
   fodder = live;
   fodder = filter_array(fodder, "is_fodder",TO);
   live = filter_array(live, "is_non_immortal_player", FILTERS_D);
   live += fodder;
   for(i=0;i<sizeof(live);i++){
      targ = live[i];
      if(!objectp(targ)) continue;
      if(!"daemon/saving_throw_d"->reflex_save(targ,(30+random(21))*-1)){
         tell_object(targ,"%^BOLD%^%^MAGENTA%^A cloud of %^BOLD%^%^CYAN%^p%^BLUE%^r%^GREEN%^i%^YELLOW%^s%^RED%^m%^MAGENTA%^a%^CYAN%^t%^BLUE%^i%^GREEN%^c %^YELLOW%^hues %^MAGENTA%^pours forth from the dragon's mouth and slams into you!%^RESET%^");
         tell_room(ETO,"%^BOLD%^%^MAGENTA%^"+targ->QCN+" is hit with the %^BOLD%^%^CYAN%^p%^BLUE%^r%^GREEN%^i%^YELLOW%^s%^RED%^m%^MAGENTA%^a%^CYAN%^t%^BLUE%^i%^GREEN%^c %^YELLOW%^breath %^MAGENTA%^of the dragon!%^RESET%^",targ);
         TO->set_property("magic", 1);
         targ->do_damage(targ->return_target_limb(), roll_dice(12,10));
         if(!random(4)){
            targ->set_temporary_blinded(10,"You are blinded by the colors!");
         }
         TO->set_property("magic", -1);
         continue;
      }
      tell_object(targ,"%^MAGENTA%^A dazzling array of colors pours forth from the dragon's mouth, but you manage to dodge most of it!%^RESET%^");
      tell_room(ETO,"%^MAGENTA%^"+targ->QCN+" dives aside as a dazzling array of colors pours from the dragon's mouth!%^RESET%^",targ);
      TO->set_property("magic", 1);
      targ->do_damage("torso", roll_dice(10,10)/2);
      TO->set_property("magic", -1);
   }
}

void wings(){
   object obj;
   if(!objectp(TO)) return;
   if(present("prismatic wall",ETO)){
      hit_something();
      return;
   }
   tell_room(ETO,"%^YELLOW%^The dragon beats her diaphonous wings, sending glimmers of light around the room!%^RESET%^");
   tell_room(ETO,"%^BOLD%^%^WHITE%^The light coalesces into a prismatic wall, protecting the dragon!%^RESET%^");
   obj = new(OBJ"pris_wall");
   obj->set_myowner(TO);
   obj->surround(TO);
   obj->move(ETO);
   return;
}

void nightmare(object targ){
   object obj;
   if(!objectp(targ)) return;
   if(!objectp(TO)) return;
   if(targ->query_property("weirded")){
      hit_something();
      return;
   }
   tell_room(ETO,"%^BOLD%^%^BLACK%^From the mouth of the %^CYAN%^p%^BLUE%^r%^GREEN%^i%^YELLOW%^s%^RED%^m%^MAGENTA%^a%^CYAN%^t%^BLUE%^i%^GREEN%^c %^MAGENTA%^dragon %^BLACK%^spews forth an unnatural cloud of whirling shadows - the stuff of nightmares!%^RESET%^");
   tell_object(targ,"%^BOLD%^%^BLUE%^The shadows merge and form your greatest fear!%^RESET%^");
   tell_room(ETO,"%^BOLD%^%^BLUE%^The shadows hover near "+targ->QCN+"!%^RESET%^",targ);
   targ->set_property("weirded",1);
   obj = new(MON"nightmare_shade");
   obj->move(ETO);
   obj->force_me("kill "+targ->query_name()+"");
   targ->add_follower(obj);
   return;
}

int sting(object targ){
   tell_object(targ,"%^BOLD%^%^BLACK%^The dragon's barbed tail stings you, leaving you feeling groggy and shaken!%^RESET%^");
   tell_room(ETO,"%^BOLD%^%^BLACK%^The dragon's barbed tail stings "+targ->QCN+"!%^RESET%^",targ);
   if(!random(8)){
      targ->set_paralyzed(2+random(3),"You are feeling groggy from the sting!");
   }
   targ->do_damage("torso",roll_dice(8,10));
   return 1;
}


void heart_beat(){
  if (!objectp(TO)) return;
    ::heart_beat();
    if (!objectp(TO)) return;
    if(TO->query_hp() < TO->query_max_hp()){
	TO->add_hp(1+random(2));
    }
}

void set_paralyzed(string message, int time){return 1;}

int is_fodder(object obj){ 
    if(obj->id("dreammon")) return 0; 
    if(obj->is_player()) return 0;
    if(obj->id("summoned monster")) return 1;
    else return 0;
}

void die(object ob){
   object *ppl;
   int i;
   if(present("prismatic wall",ETO)){
      tell_room(ETO,"%^BOLD%^%^WHITE%^The wall shimmers and fades!%^RESET%^");
      present("wall",ETO)->remove();
   }
   ppl = all_living(ETO);
   for(i=0;i<sizeof(ppl);i++){
     if(!objectp(ppl[i])) continue;
     ppl[i]->remove_property("weirded");
   }
   tell_room(ETO,"%^BOLD%^%^CYAN%^The dragon shrieks and shimmers before falling to the ground lifeless!%^RESET%^");
   tell_room(ETO, "%^BOLD%^Motes of spirit lights flood into the void and head through the portal, their souls finding peace from these lucid dreams.  You see the spirits of Aidlon and Comadon float by, waving to you before they vanish into the violet orb.%^RESET%^");
   ppl = all_living(ETO);
   for(i=0;i<sizeof(ppl);i++){
      if(!userp(ppl[i])) continue;
      ppl[i]->set_mini_quest("%^BOLD%^%^CYAN%^Lucid Dreams%^RESET%^", 6200000,"%^MAGENTA%^Lucid %^BOLD%^%^CYAN%^D%^WHITE%^r%^BLUE%^e%^CYAN%^a%^WHITE%^m%^BLUE%^s%^RESET%^");
      tell_object(ppl[i], "\n%^CYAN%^%^BOLD%^Feeling a sense of accomplishment in letting the souls trapped here come to a rest, you feel like it is time for these lucid dreams to come to an end.%^RESET%^");
   }
//new loot setup - at least 3 items per kill, likely more
   switch(random(6)){
      case 0: new(OBJ"darkcassock")->move(TO);
              if(!random(3)){ new(OBJ"sunlight_robe")->move(TO); }
              break;
      case 1: new(OBJ"sunlight_robe")->move(TO);
              if(!random(3)){ new(OBJ"moonlight_robe")->move(TO); }
              break;
      case 2: new(OBJ"moonlight_robe")->move(TO);
              if(!random(3)){ new(OBJ"starrobe")->move(TO); }
              break;
      case 3: new(OBJ"starrobe")->move(TO);
              if(!random(3)){ new(OBJ"nightmare_robe")->move(TO); }
              break;
      case 4: new(OBJ"nightmare_robe")->move(TO);
              if(!random(3)){ new(OBJ"rainbowcassock")->move(TO); }
              break;
      default: new(OBJ"rainbowcassock")->move(TO);
               if(!random(3)){ new(OBJ"darkcassock")->move(TO); }
               break;
   }
   switch(random(4)){
      case 0: new(OBJ"dream_sword")->move(TO);
              break;
      case 1: new(OBJ"dream_mace")->move(TO);
              break;
      case 2: new(OBJ"dream_bow")->move(TO);
              break;
      default: new(OBJ"dream_staff")->move(TO);
               break;
   }
   if(!random(3)){
      switch(random(4)){
         case 0: new(OBJ"dream_sword")->move(TO);
                 break;
         case 1: new(OBJ"dream_mace")->move(TO);
                 break;
         case 2: new(OBJ"dream_bow")->move(TO);
                 break;
         default: new(OBJ"dream_staff")->move(TO);
                  break;
      }
   }
   switch(random(7)){
      case 0: new(OBJ"dhelm")->move(TO);
              break;
      case 1: new(OBJ"dhelm")->move(TO);
      case 2: new(OBJ"prism_bracers")->move(TO);
              break;
      case 3: new("/d/laerad/obj/bhelm")->move(TO);
              break;
      case 4: new("/d/laerad/obj/bhelm")->move(TO);
      case 5: new(OBJ"prism_bracers")->move(TO);
              break;
      default: new(OBJ"prism_bracers")->move(TO);
               break;
   }
   ::die(ob);
}

void hit_something(){
   object *ppl;
   object targ;
   int i,j;
   ppl = TO->query_attackers();
   i = sizeof(ppl);
   if(i < 1) return;
   j = random(i);
   targ = ppl[j];
   tell_object(targ,"%^BOLD%^%^RED%^The dragon bites you with ferocity, making your blood feel as if its on fire!%^RESET%^");
   tell_room(ETO,"%^BOLD%^%^RED%^The dragon bites "+targ->QCN+" with ferocity!%^RESET%^",targ);
   targ->do_damage(targ->return_target_limb(),roll_dice(6,10));
   return;
}
