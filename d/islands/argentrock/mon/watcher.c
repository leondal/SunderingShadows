//fey'ri watcher
#include <std.h>
#include <daemons.h>
#include "../argabbr.h"
inherit MONSTER;

void create()
{ ::create();
  set_name("Watcher");
  set_id(({"elf","watcher","monster","fey'ri"}));
  set_short("%^RESET%^%^GREEN%^A rugged e%^BOLD%^l%^RESET%^%^GREEN%^f-l%^BOLD%^i%^RESET%^%^GREEN%^ke figure%^RESET%^");
  set_long("%^GREEN%^This elf is covered to head to toe in thick woodland"+
  " clothing.  He has a green hood that covers most of his face."+
  "  He wears some simple leather shoes and has a simple belt "+
  "that holds up his green pants.  He looks quite agile and "+
  "stealthy.  Likely this creature is more at home in the woods"+
  " than anywhere else.  He wields a deadly looking %^RESET%^glaive%^GREEN%^ covered in thorns.%^RESET%^");
  set_property("magic",1);
  set_race("elf");
  set_gender("male");
  set("aggressive","aggfunc");
  set_class("ranger");
  set_class("fighter");
  set_level(50);
  set_mlevel("fighter",40);
  set_mlevel("ranger",40);
  add_search_path("/cmds/feats");
  add_search_path("/cmds/ranger");
  add_search_path("/cmds/fighter");
  set_hd(60,10);
  set_hp(random(2000)+2000);
  set_overall_ac(-15);
  set_alignment(9);
  set_stats("intelligence",15);
  set_stats("wisdom",16);
  set_stats("strength",23);
  set_stats("charisma",8);
  set_stats("dexterity", 23);
  set_stats("constitution",19);
  add_money("gold",random(2000));
  set_property("full attacks",1);
  set_property("no death", 1);  //added per aevar's suggestion
  set_mob_magic_resistance("low");
  set_resistance("fire",50);
  set_monster_feats(({"power attack","rush","combat reflexes",
  "blade block","impale","light weapon","strength of arm",
  "sweepingblow","knockdown","whirl","sunder"}));
  set_parrying(1);
  add_damage_bonus(8);
  set_property("damage resistance",4);
  set_funcs(({"strik"}));
  set_func_chance(40);
  set_property("add kits",random(15)+15);
  new(OBJ+"glaive")->move(TO);
  new(OBJ+"headband")->move(TO);
  new(OBJ+"shoes")->move(TO);
  new(OBJ+"belt")->move(TO);
  new(OBJ+"breeches")->move(TO);
  new(OBJ+"amulet")->move(TO);
  command("wield glaive");
  command("mystyle dervish");
  command("wearall");
  command("speech whisper coldly");
  set_new_exp(39,"boss");
  add_money("gold",random(5000));
}
void aggfunc()
{  //he didn't seem to agro, so added this.
    if(!objectp(TP)) { return; }
    if(TP->query_true_invis()) { return; }
    TO->kill_ob(TP,1);
	force_me("say %^BOLD%^%^GREEN%^You are not worthy.  Today is your death.");
}
void strik(object targ)
{  int x;
   if(!objectp(TO)) return 1;
   if(!objectp(ETO)) return 1;

	else{
   tell_object(targ,"%^GREEN%^Watcher moves with incredible"+
   " speed striking you %^RED%^repeatedly%^GREEN%^ and forcing you back towards the %^BLUE%^cliff.");
   tell_room(ETO,"%^GREEN%^The elf strikes"+
   " "+targ->query_cap_name()+" %^RED%^repeatedly,%^GREEN%^ "+
   "sending them back %^BOLD%^further to the edge%^RESET%^%^GREEN%^ with each strike.",targ);
   for(x=0;x<random(5)+3;x++)
       targ->cause_typed_damage(targ,0,roll_dice(7,10),"slashing");

   if(!"/daemon/saving_throw_d.c"->reflex_save(targ,-30)){
    targ->move("/d/islands/argentrock/inherit/sea");
    tell_object(targ,"%^CYAN%^You loose your footing and are"+
	   " sent %^BOLD%^%^BLUE%^flying into the sea");
    tell_room(ETO,"%^CYAN%^The elf lands a brutal blow on "+
    " "+targ->query_cap_name()+" that sends them flying"+
    " into the %^BLUE%^sea%^CYAN%^ with a %^BOLD%^splash.",targ);
	targ->cause_typed_damage(targ,0,roll_dice(7,10),"slashing");
      }
  }
   return 1;
}
void set_paralyzed(int time,string message){
 int x;
 force_me("emote %^CYAN%^shakes off the stun and continues attacking.");
 for(x=0;x<random(5)+1;x++)
 execute_attack();

 return 1;}
void set_tripped(int time,string message){
int x;
 force_me("emote is %^GREEN%^flung%^RESET%^ from his feet"+
  " but %^GREEN%^flips%^RESET%^ over and continues attacking.");
 for(x=0;x<random(5)+1;x++)
   execute_attack();
}
void heart_beat(){
  object *attackers;
  int x;
  ::heart_beat();
  if(!objectp(TO))return;
  if( query_hp() < query_max_hp() )
      TO->do_damage( "torso",-(random(6) + 1) );
  if(!objectp(query_current_attacker())) { return ; }
  if(query_attackers()==({ })) return;
  force_me("flash");
  switch (random(7)){
       case 0: force_me("say how dare you set foot on our sacred sacturary.");
        break;
       case 1: force_me("say You never should have come here.");
        break;
       case 2: force_me("say You will die like all of the others.");
        break;
       case 3: force_me("say I will gut you like the hog you are.");
        break;
       case 4: force_me("say Your body will be fish food, no one will ever find it.");
        break;
       case 5: force_me("say Your kind will never be worthy.");
        break;
	   case 6: force_me("say This tresspass will be your death.");
        break;
        }

  attackers = query_attackers();
  x = sizeof (attackers);
  if(random(5)==0)
   new("/cmds/spells/d/_dispel_magic.c")->use_spell(TO,0,60,100);
  if(!present("summoned monster",ETO))
   new("/cmds/spells/s/_summon_natures_ally_iv.c")->use_spell(TO,0,60,100);

  if(random(2)==0) force_me("sweepingblow");
  if(random(2)==0) force_me("impale "+attackers[random(x)]->query_name()+"");
  if(random(2)==0)
    force_me("rush "+attackers[random(x)]->query_name());
  else if(random(2)==0) force_me("knockdown "+attackers[random(x)]->query_name()+"");
  if(random(2)==0) force_me("sunder "+attackers[random(x)]->query_name()+"");
  return;
}
void die(object ob){

 object *ppl;
 object obj;
 int i;
 string queststring;

    queststring = "%^GREEN%^Defeated argentrock's watcher";
    ppl = ({});
    ppl = filter_array(all_living(ETO),"is_non_immortal_player",FILTERS_D);


    for(i=0;i<sizeof(ppl);i++) {

        if(member_array(queststring,ppl[i]->query_mini_quests()) ==-1)
          ppl[i]->set_mini_quest(queststring,3100000,queststring);

      }
 tell_room(ETO,"\n%^BOLD%^%^CYAN%^As the watcher dies his ilusion fades, he is actually a %^RED%^fey'ri.\n");
 set_race("fey'ri");
 obj = new("/d/common/obj/brewing/herb_special_inherit");
 obj->set_herb_name("corrupted fey lifeblood");
 obj->move(TO);
 return ::die(ob);
}
