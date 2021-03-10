#include "../outpost.h"
#include <std.h>
inherit TOWNSMAN;


void do_greeting();
void do_departing();
int GREETING, DEPARTING;

create (){
  ::create ();
  set_moving(0);
  set_name("Sergeant Anton");
  set_id(({"segeant","torm guard","guard","soldier","anton",
  "torm city guard","sergeant","dayperson","torm guardsman"}));
  set_property("swarm",1);
  set_short("Sergeant Anton");
  set_long("%^ORANGE%^Anton is a weather-worn veteran. His gruff appreance and cool "+
  "%^BOLD%^%^BLACK%^st%^RESET%^ee%^BOLD%^%^BLACK%^l-gr%^RESET%^a%^BOLD%^%^BLACK%^y e%^RESET%^y%^BOLD%^%^BLACK%^es "+
  "%^RESET%^%^ORANGE%^makes it evident that he is a man who takes his responsibility very seriously. He's wearing "+
  "%^BOLD%^%^BLACK%^scale armor %^RESET%^%^ORANGE%^which has seen some combat after he has arrived on the island");
set_gender("male");
  if(!random(2)){
  set_race("human"); 
  } else {
  set_race("half-elf");
  }
set_body_type("human");
  set_hd(25,1);
set_size(2);
  set_class("fighter");
  set_mlevel("fighter",25);
 set_guild_level("fighter",25);
  set_property("full attacks",1);
  add_search_path("/cmds/fighter/");
  set_stats("strength",17);
set_stats("intelligence", 13);
set_stats("dexterity", 17);
set_stats("charisma", 16);
set_stats("wisdom", 10);
set_stats("constitution", 14);
set_alignment(1);
  set_max_hp(random(200)+300);
  set_hp(query_max_hp());
  set_exp(2000);
set("aggressive", 0);
  set_emotes(1,({"%^BOLD%^There is no where for a criminal to hide!!"}),1);
add_money("gold", 50 + random(100));
  set_overall_ac(5);
  new(OBJ"torm_sword")->move(TO);
  command("wield sword");
  new(OBJ"torm_scalemail")->move(TO);
  new(OBJ"torm_shield")->move(TO);
 command("wearall");
  present("shield",TO)->set_property("monsterweapon",1);
  present("sword",TO)->set_property("monsterweapon",1);
  
     set_monster_feats(({
      "parry",
	 "counter",
     "deflection",
     "reflection",
     "shieldbash",
     "shieldwall", 
	 "powerattack",
	  "rush"
   }));
}

void init(){
	::init();
	if(!interactive(TP)) return;
	if((mixed *)TO->query_attackers() != ({ })) return;

	if(GREETING == 1) {
		call_out("do_greeting",1,TP);
		return;
	}
	if(DEPARTING == 1) {
		call_out("do_departing",1,TP);
		return;
	}
}


void do_greeting(){
	force_me("say hello");
	if(high_mortalp(TP)){
		if(ALIGN->is_evil(TP)){
			force_me("emote %^CYAN%^tightens the grip on his sword.\n");
			force_me("say I know you "+TP->QCN+". We don't want no problem here. Do your business and leave without incident!\n");
			force_me("emote %^CYAN%^reluctantly stands aside to let "+TP->QCN+" pass");
			return;
		}
		force_me("emote %^CYAN%^smiles brightly\n");
		force_me("say It is a honor to welcome you to Torm Outpost here on Laerad, "+TP->QCN+". And it is a personal honor to meet one as famous as you!\n");
		force_me("say I am sure that Captain Dalvin would be honored to meet you as well!\n");
		force_me("emote %^CYAN%^rushes to the side to allow "+TP->QCN+" passage\n");
		return;
	}
	if(ALIGN->is_evil(TP)){
		force_me("emote %^CYAN%^eyes you carefully\n");
		force_me("say Greetings stranger. You are welcome to stay in Torm outpost as long as you cause no trouble\n");
	return;}
	force_me("emote %^CYAN%^smile\n");
	force_me("say Greetings traveller. Welcome to Torm Outpost, you are safe from the evils roaming the island here.\n");
	force_me("say Stay for as long as you wish. but we cannot afford many accommodations\n");
	force_me("say You should speak with Captain Dalvin. He can offer some information about the island\n");
return;}
	
void do_departing(){
	
	if(high_mortalp(TP)){
		if(ALIGN->is_evil(TP)){
				force_me("emote nods and watches nervously as you leave\n");
				force_me("say Good travels to you\n");
		return 1;}
		force_me("emote %^CYAN%^smiles and stands aside\n");
		force_me("say Thank you for your visit, I hope you will honour us with a visit in near future again\n");
		force_me("say I would say 'safe travels', but one such as you, I doubt you need my blessing anywhere!\n");
		force_me("emote %^CYAN%^snickers and waves enthusiastic\n");
	return 1;}
	if(ALIGN->is_evil(TP)){
		force_me("emote %^CYAN%^nods shortly\n");
		force_me("say Word of advice, get off this island. It ain't safe here\n");
		force_me("emote %^CYAN%^turns his attention elsewhere\n");
	return 1;}
	force_me("emote %^CYAN%^smiles and stand aside\n");
	force_me("say Safe travles out there. It is a dangerous island, come back if you need a safe place or are wounded\n");
return 1;}

void set_direction(string str)
{
	if(str == "northeast") {
		GREETING = 1;
		DEPARTING = 0;
		return;
	}
	if(str == "south") {
		DEPARTING = 1;
		GREETING = 0;
		return;
	}
}


void heart_beat(){
	::heart_beat();
  if(present("laeradmon") && !present("silvim")){
	   force_me("rush laeradmon");
   }
   if(query_hp()<query_max_hp()){
  TP->add_hp(roll_dice(1,4)+4);}
  /*int b;
  object *att;
  if(!objectp(TO)) return;
  att=TO->query_attackers();
  if(!(sizeof(att))) return 1;
  for(b=0;b<sizeof(att);b++){
    force_me("rush "+att[b]->query_name());
 
   } */
}
