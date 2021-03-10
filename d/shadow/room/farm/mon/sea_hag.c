#include <std.h>
#include <daemons.h>
#include "../farm.h";
inherit WEAPONLESS;

void create(){
   ::create();
   set_name("sea hag");
   set_id(({"Muirgena","hag","sea hag","witch","muirgena","crone"}));
   set_short("Muirgena, the sea hag");
   set_long(
      "This hideous creature looks at first glance to be an extremely "+
      "ugly old crone.  Her flesh is %^GREEN%^sickly %^CYAN%^and "+
      "%^YELLOW%^yellow%^RESET%^%^CYAN%^, giving her a jaundiced "+
      "appearance.  She is covered in %^RESET%^warts%^CYAN%^ and "+
      "%^RED%^open sores %^CYAN%^oozing %^YELLOW%^puss%^RESET%^"+
      "%^CYAN%^.  Her long, matted hair is %^GREEN%^m%^CYAN%^o"+
      "%^GREEN%^t%^CYAN%^t%^GREEN%^l%^CYAN%^e%^GREEN%^d green"+
      "%^CYAN%^, giving it the appearance of %^GREEN%^dying seaweed"+
      "%^CYAN%^.  She is dressed in %^ORANGE%^rotting rags %^CYAN%^"+
      "that reveal more of her diseased flesh than you would like "+
      "to see, and she moves with a strange %^BOLD%^fluidity "+
      "%^RESET%^%^CYAN%^that seems to belie her age.  Her eyes "+
      "are her most arresting feature.  It seems as if you see your "+
      "own %^BOLD%^%^BLACK%^death %^RESET%^%^CYAN%^in their "+
      "bottomless gaze.");
   set_gender("female");
   set_race("hag");
   set_body_type("human");
   set_hd(15,3);
   set_max_level(16);
   set_alignment(9);
   set_overall_ac(0);
   set_max_hp(random(50)+150);
   set_hp(query_max_hp());
   set_exp(2000);
   set_level(15);
   set_class("thief");
   set_mlevel("thief",15);
   set_guild_level("thief",15);
   set_mob_magic_resistance("average");
   set_stats("intelligence",16);
   set_stats("wisdom",12);
   set_stats("strength",14);
   set_stats("charisma",4);
   set_stats("dexterity",18);
   set_stats("constitution",15);
   set_scrambling(1);
   set("aggressive",25);
   set_attack_limbs(({"right hand","left hand"}));
   set_damage(1,6);
   set_attacks_num(2);
   add_money("gold",random(500)+400);
   set_funcs(({"rake","rake","rake","rake","rake","rake","rake","rake","stare","ugly","ugly","ugly","ugly","ugly"}));
   set_func_chance(30);
   set_property("swarm",1);
}

int rake(object targ){
   if(!objectp(targ)) return 0;
   if(!objectp(TO)) return 0;
   tell_object(targ,"%^GREEN%^The hag rakes you with her putrid "+
      "claws!\n%^RED%^Your skin burns!");
   tell_room(ETO,"%^GREEN%^The hag rakes "+targ->QCN+" with her "+
      "putrid claws!",targ);
   targ->do_damage(targ->return_target_limb(),roll_dice(2,6));
   return 1;
}

int stare(object targ){
int curhp;
   if(!objectp(targ)) return 0;
   if(!objectp(TO)) return 0;
   if(!"daemon/saving_d"->saving_throw(targ,"spell",0)) {
      curhp = targ->query_hp();
      curhp = curhp/2;
      tell_object(targ,"%^BOLD%^%^GREEN%^The hag fixes her unearthly "+
         "stare on you, and you look in horror upon your own death!");
      tell_room(ETO,"%^BOLD%^%^GREEN%^The hag fixes her gaze upon "+
         ""+targ->QCN+", and "+targ->QS+" turns white!",targ);
      targ->do_damage("head",curhp);
      return 1;
   }else{
      tell_object(targ,"%^GREEN%^The hag fixes her gaze upon you, but "+
         "you avert your eyes!");
      tell_room(ETO,"%^GREEN%^The hag fixes her gaze upon "+targ->QCN+", "+
         "but "+targ->QS+" averts "+targ->QP+" eyes!",targ);
      return 1;
   }
}

int ugly(object *baddies){
   int i;
   baddies = TO->query_attackers();
   if(!baddies) return 0;
   if(!objectp(TO)) return 0;
   tell_room(ETO,"%^YELLOW%^The hag parts her %^GREEN%^sickly "+
      "green hair%^YELLOW%^, revealing her horrific face!");
   for(i=0;i<sizeof(baddies);i++){
      if(!objectp(baddies[i])) continue;
      if(!objectp(TO)) continue;
      if((int)baddies[i]->query_stats("constitution") < random(22)){
         tell_object(baddies[i],"%^RED%^You are horrified by what you see!");
         baddies[i]->do_damage(baddies[i]->return_target_limb(),roll_dice(1,6));
         baddies[i]->set_paralyzed(3+random(3),"You are shaking from the sight!");
      }else{
         tell_object(baddies[i],"%^RED%^You resist the disgusting "+
            "appearance of the hag!");
      }
   }
   return 1;
}
void die(object ob) {
    new(OBJ"seafan")->move(TO);
    ::die(ob);
}
