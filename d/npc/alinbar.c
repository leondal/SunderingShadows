//alinbar
//added studying NWP to Alinbar 5/23/04 Circe

#include <std.h>
#include <daemons.h>
#define MAPPING_D "/daemon/mapping_d.c"

inherit "/std/npc";

void start_story();
void start_song();

string *list1,*list2,*owners = ({"margath","bryanna","obsidian"});

void create(){
  object ob;
   ::create();
   set_nwp("eavesdropping",5,500);
   set_nwp("studying",25);
   set_name("Alinbar Betome");
   set_short("Alinbar Betome");
   set_id(({"alinbar","Alinbar","Alinbar Betome","alinbar betome","betome"}));
  enable_commands();
//  set("aggressive",0);
  //set_property("swarm",1);
   set_base_damage_type("bludgeoning");
   set_long(
@OLI
   Alinbar Betome, this gaily clad minstrel, once traveled the realms 
collecting lore and legends. He entertained many in his days of travel. 
His age has caught up to him now. His face is creased with deep smile 
lines. He can now be found day in and day out telling stories and 
drinking at the Rhapsody Inn.  He still occasionally sings and dances, 
but he enjoys most telling folks about the better times when he 
watched history in the making and even helped mold it at times.
OLI
   );
   set_race("half-elf");
   set_body_type("human");
   set_class("bard");
   set_mlevel("bard",50);
   set_guild_level("mage",50);
   set_hd(50,1);
   set_hp(350);
//   set_hp(35000);
   set_max_hp(query_hp());
   set_exp(12);
   add_search_path("/cmds/bard");
   set_thief_skill("pick pockets",200);
   set_spell_chance(100);
   set_spells(({"magic missile","lightning bolt","ray of enfeeblement","lower resistance","web","web","cone of cold","powerword stun","disintegrate","greater shout","greater shout","powerword stun"}));
  ob=new("/d/dagger/tonovi/obj/lute.c"); 
  ob->set_value(0);
  ob->set_short("A worn and well loved lute");
  ob->move(TO); 
  TO->force_me("wield lute");
   new("/d/common/obj/armour/robe")->move(TO);
   force_me("wear robe");
   add_money("gold",600);
   remove_std_db();
   set_db("alinbar");
   set_random_act_db("alinbarrandom");
   set_random_act_chance(5);
   set_need_addressed(1);
    set_attack_limbs(({"right hand","left hand"}));
    set_wielding_limbs(({"right hand","left hand"}));
   set_attacks_num(1);
   set_no_clean(1);
}

void reset(){
   ::reset();
   list1 = KILLING_D->query_bounties();
   list1 -= owners;
   list2 = MAPPING_D->query_values("rhapsody_unwanted");
   list2 -= owners;
}

void heart_beat(){
	object *living=({});
	int x,i;
   ::heart_beat();
   if(!objectp(TO)) return;
   if(sizeof(query_attackers())) return;
   if(query_interact()) return;
   if((string)EVENTS_D->query_time_of_day() == "twilight" ||
      (string)EVENTS_D->query_time_of_day() == "night"){
      if(!random(1000)){
         start_story();
         return;
      }                
      if(!random(1000)){
         start_song();
         return;
      }
   }

	living = filter_array(all_living(ETO),"is_non_immortal","/daemon/filters_d.c");
	if(pointerp(living) && sizeof(living))
	{
		for(i=0;i<sizeof(living);i++)
		{
			if(!objectp(living[i])) { continue; }
			if(living[i]->id("barkeep")) { continue; }
			if(member_array(living[i],(object *)TO->query_attackers()) != -1) { continue; }
			if(sizeof(living[i]->query_attackers()))
			{
				TO->force_me("kill "+(string)living[i]->query_true_name()+"");
			}
		}
	}

   if(!random(500))
      switch(random(6)){
         case 0:
            x = random(sizeof(list1));
            if(sizeof(list1))
               force_me("say "+list1[x]+" has a law bounty so anyone "+
               "that kills that person gets a big cash reward. That's "+
               "why we can't have "+list1[x]+" in here. We don't want "+
               "the disruption and mess to clean up.");
            break;
         case 1:
            x = random(sizeof(list1));
            if(sizeof(list1) > 1){
               if(x == (sizeof(list1)-1)) x--;
               force_me("say "+list1[x]+" and "+list1[x+1]+" have their "+
               "name on that list of law bounties the Magistrate keeps "+
               "so if you see them, watch out.");
            }
            break;
         case 2:
            if(sizeof(list2))
               force_me("say "+list2[random(sizeof(list2))]+" must have "+
               "done something to disturb the peace because that fellow "+
               "isn't welcome here any more.");
            break;
         case 3:
            x = random(sizeof(list2));
            if(sizeof(list2) > 1){
               if(x == (sizeof(list2)-1)) x--;
               force_me("say "+list2[x]+" and "+list2[x+1]+" owe us for "+
               "damages before they're going to be served here again.");
            }
            break;
         case 4:
            x = random(sizeof(list2));
            if(sizeof(list2) > 1){
               if(x == (sizeof(list2)-1)) x--;
               force_me("say "+list2[x]+" and "+list2[x+1]+" abused our "+
               "hospitality or owe us damages so they've worn out their "+
               "welcome.");
            }
            break;
         case 5:
            if(sizeof(list2))
               force_me("say "+list2[random(sizeof(list2))]+" should talk "+
               "to the management about how to make amends. If you talk "+
               "to them, you might mention it.");
      }
}

void start_story(){
}

void start_song(){
}

int kill_ob(object ob,int i) {

 ::kill_ob(ob,i);
//  TO->force_me("calm "+ ob->query_name());
}
