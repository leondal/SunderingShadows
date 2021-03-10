//knight for avenging dead guards
#include <std.h>
#include <daemons.h>
#include "../seneca.h"
inherit MONSTER;

void create(){
 ::create();
  set_name("Berend");
  set_id(({"human","berend","knight"}));
  set_short("%^RESET%^Berend Hoeig, %^BOLD%^Holy Knight%^RESET%^");
  set_long("A strong looking man clad in heavy armor stands "+
  "here.  He has a strong jaw and bright blue eyes.  Locks "+
  "of blonde hair can be seen protruding from his helmet.  "+
  "It is said that he came to town to honor heroes and "+
  "follow in their footsteps making a name for himself "+
  "as the great avenger for those that would kill recklessly.  ");
  set_property("magic",1);
  set_race("human");
  set_body_type("human");
  set_gender("male");
  set_size(2);
  set_hd(50,10);
  set_class("paladin");
  set_class("fighter");
  set_level(45);
  set_mlevel("fighter",10);
  set_mlevel("paladin",35);
  set_guild_level("fighter",10);
  set_guild_level("mage",35);
  add_search_path("/cmds/feats");
  add_search_path("/cmds/paladin");
  add_search_path("/cmds/fighter");
  set_hp(random(2000)+1000);
  set_overall_ac(-20);
  set_alignment(1);
  set_stats("intelligence",9);
  set_stats("wisdom",16);
  set_stats("strength",25);
  set_stats("charisma",18);
  set_stats("dexterity", 12);
  set_stats("constitution",18);
  set_property("alignment adjustment",-10);
  set_property("magic",1);
  add_money("silver",random(2000));
  set_property("full attacks",1);
  set_mob_magic_resistance("average");
  set_property("no knockdown",1);
  set_property("no disarm",1);
  set_monster_feats(({"power attack","rush","combat reflexes",
  "counter","deflection","reflection","shieldbash","shieldwall",
  "knockdown","sunder","smite","charge","mounted combat","ride-by attack"}));
  set_parrying(1);
  add_damage_bonus(9);
  set_property("damage resistance",4);
  set_funcs(({"strik"}));
  set_func_chance(40);
  set_diety("tyr");
  set_property("add kits",random(15)+15);
  new(OBJ"clance")->move(TO);
  new(OBJ"shield")->move(TO);
  new("/d/common/obj/special/sp_randwpn")->move(TO);
  new("/d/shadow/room/city/cguild/paladin/hlycoif.c")->move(TO);
  "/d/common/daemon/randgear_d"->armor_me(TO, "armorpl", 20, 4, 95);
  command("wield lance");
  command("mystyle soldier");
  command("wearall");
  command("speech state proudly");
  call_out("horsey",0);


}
void horsey(){
 object ob;
  ob = new("/d/shadow/room/city/cguild/paladin/barded_war_horse.c");
  ob->set_owner(TO);
  ob->set_level((int)TO->query_level()+5);
  ob->set_size((int)TO->query_size());
  ob->move(ETO);
  ob->set_alignment(1);
  TO->force_me("mount horse");
  TO->force_me("summon celestial");
  if(objectp(ob) && objectp(TO)) { ob->add_protector(TO); }

}
void strik(object targ)
{  int x, damage;
   if(!objectp(TO)) return 1;
   if(!objectp(ETO)) return 1;
	damage = random(100)+100;
   tell_object(targ,"%^YELLOW%^Knight shouts at you and"+
   " a %^WHITE%^holy%^YELLOW%^ force slams into you.");
   tell_room(ETO,"%^YELLOW%^The Knight shouts at"+
   " "+targ->query_cap_name()+" with %^WHITE%^holy%^YELLOW%^ force.",targ);
    if(ALIGN->is_evil(targ)) damage = damage*1.5;
        targ->do_damage(targ->return_target_limb(),damage);

   if(!"/daemon/saving_throw_d.c"->will_save(targ,-35)){

    tell_object(targ,"%^CYAN%^You stand frozen in shock after hearing the holy voice");
	targ->set_paralyzed(10,"%^CYAN%^The knight's voice freezes you.");
      }

   return 1;
}
void set_paralyzed(int time,string message){
 int x;
 force_me("emote %^CYAN%^shakes off the stun and continues attacking.");
 for(x=0;x<random(5)+1;x++)
 execute_attack();

 return 1;}

void heart_beat(){
  object *attackers;
  int x;
  ::heart_beat();
  if(!objectp(TO))return;
  if(!TO->query_in_vehicle()){
  force_me("unwield lance");
  force_me("wield weapon");
  }
  if( query_hp() < query_max_hp() )
      TO->do_damage( "torso",-(random(6) + 1) );
  if(!objectp(query_current_attacker())) { return ; }
  if(query_attackers()==({ })) return;
  force_me("flash");
  switch (random(11)){
       case 0: force_me("say how dare you show your face here murderer.");
        break;
       case 1: force_me("say You never should have been born.");
        break;
       case 2: force_me("say You will die like all the dog you are.");
        break;
       case 3: force_me("say I will kill you for your crimes.");
        break;
       case 4: force_me("say Your body will be eaten by vultures, fitting for one like yourself.");
        break;
       case 5: force_me("say You have been weighed in the balance and come up lacking.");
        break;
	   case 6: force_me("say This world will suffer your existance no longer.");
        break;
	   case 7: force_me("say How can you live with the sins you've commited?");
        break;
	   case 8: force_me("say Your existance has been tolerated long enough.");
        break;
	   case 9: force_me("say By Tyr, I will avenge those you have slain.");
        break;
        }

  attackers = query_attackers();
  x = sizeof (attackers);
  switch(random(8)){
  case 0:
   new("/cmds/spells/d/_dispel_magic.c")->use_spell(TO,0,42,100);
   break;
  case 1:
    if(!TO->query_property("seeking_sword"))
     new("/cmds/spells/s/_seeking_sword.c")->use_spell(TO,0,45,100);
  break;
  case 2: force_me("smite "+attackers[random(x)]->query_name()+"");
  break;
  case 3: force_me("charge "+attackers[random(x)]->query_name()+"");
  break;
  case 4: force_me("shieldbash "+attackers[random(x)]->query_name()+"");
  break;
  case 5: force_me("rush "+attackers[random(x)]->query_name());
  break;
  case 6: force_me("knockdown "+attackers[random(x)]->query_name()+"");
  break;
  case 7: force_me("sunder "+attackers[random(x)]->query_name()+"");
  break;
  }
  return;
}
