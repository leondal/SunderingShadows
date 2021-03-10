
#include "../outpost.h"
#include <daemons.h>
#include <std.h>
inherit MONSTER;
create (){
  ::create ();
  set_moving(0);
  set_name("dalvin");
  set_id(({
  "captain","captain of the Outpost","dalvin",
  }));
  set_property("swarm",1);
  set_property("no dominate",1);
  set_property("no bows",1);
  set_mob_magic_resistance("average");
  set_property("magic",1);
   set_short("Dalvin, Captain of Torm Outpost");
  set_property("bounty hunter",1);
  add_damage_bonus(7);
  set_long("Dressed in %^CYAN%^p%^BOLD%^o%^RESET%^%^CYAN%^l%^BOLD%^i%^RESET%^%^CYAN%^sh%^BOLD%^e%^RESET%^%^CYAN%^d "+
  "%^BOLD%^%^BLACK%^f%^RESET%^u%^BOLD%^%^BLACK%^ll-pl%^RESET%^a%^BOLD%^%^BLACK%^te %^RESET%^a%^BOLD%^%^BLACK%^rm%^RESET%^o%^BOLD%^%^BLACK%^r "+
  "%^RESET%^Dalvin is a formidable man to behold. His features are those of a hardened veteran, which is emphasized "+
  "by the long scar he has across his right cheek. He is busy standing over a table with a map and several other documents placed them them.");
set_property("swarm",1);
set_gender("male");
  set_race("half-elf");
  add_search_path("/cmds/fighter/");
  add_search_path("/cmds/mortal/");
set_body_type("human");
  set_hd(30,1);
set_size(2);
  set_class("fighter");
  set_mlevel("fighter",30);
  set_property("full attacks",3);
  set_stats("strength",18);
set_stats("intelligence", 13);
set_stats("dexterity", 17);
set_stats("charisma", 16);
set_stats("wisdom", 10);
set_stats("constitution", 14);
set_alignment(1);
  set_max_hp(550);
  set_hp(550);
  set_exp(10000);
set("aggressive", 0);
  set_overall_ac(-15);
   set_emotes(1,({
  "Dalvin hmms and say: %^CYAN%^Have we heard anything from our last caravan to the Ruins? They are running late!",
  "Dalvin slams his mailed fist into the table and yells: %^CYAN%^Dammit, to the Hells with the Gnolls! Thats another shipment of goods lost!",
  "Dalvin shifts through some of the documents on the table and makes some notes.",
  "Dalvin tell a nerby guard: %^CYAN%^Send message back to Torm. we will need more supplies within a week. Especially the water is going fast!",
  
  }),0);
  add_money("gold",random(1000));
  add_money("platinum",random(1000));
  new(OBJ"torm_sword")->move(TO);
  command("wield sword");
  new("/d/common/obj/armour/fullplate")->move(TO);
  new(OBJ"torm_shield")->move(TO);
  force_me("speech %^ORANGE%^talk with %^BOLD%^authority");
  set_spoken("wizish");
  
  present("plate",TO)->set_property("monsterweapon",1);
 command("wearall");
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
  string *bounty, *evil;
  ::init();
  
  if(wizardp(TP)) return 1;
  bounty = (string *)KILLING_D->query_bounties();
  evil = KILLING_D->query_evil_bounties();
  if(member_array(TP->query_name(),bounty) != -1) {  
    force_me("say you! "+TP->QCN+" You are wanted in Torm. I order you to sail back and turn yourself in right now!");
    force_me("emote growls");
	force_me("say I would have you escorted back in chains if I had the men to spare!");
  }
  if(member_array(TP->query_name(),evil) != -1) {
    force_me("say Your evil acts are well known and you must be punished!!");
    call_out("rush_em",1,TP);
  }
}



void catch_say(string msg){
    if(!interactive(TP)) { return; }
   call_out("reply_func",1,msg,TP);
}


void reply_func(string msg){
   string name;
   
   if(!msg || !objectp(TP)){ return;}
   
   if(strsrch(msg,"gnoll") != -1 || strsrch(msg,"Gnolls") != -1 || strsrch(msg,"Gnoll") != -1 || strsrch(msg,"gnolls") != -1){
	   force_me("emote %^CYAN%^looks grim as he glances down to the documents on the table.\n");
	   force_me("say Yes. We are having quite a problem with the gnolls. They have showed up recently.\n");
	   force_me("emote %^CYAN%^snorts in disdain.\n");
	   force_me("say They showed up not long after the fall of Asgard. And now they feel strong enough to attack pretty much anything in their way!\n");
	   force_me("say If you kill a few of them, I would be grateful. They are hiding in a small camp in the north-eastern part of the plains.\n");
	   if(TP->query_level()<15){
		   force_me("say I would not talk you into your death. These gnolls are stronger than the Tlincallis and more numerous! Gather your strength before attacking their camp.");
	   }
   return;}
	   
	   if(strsrch(msg,"formian") != -1 || strsrch(msg,"Formian") != -1 || strsrch(msg,"hole") != -1 || strsrch(msg,"holes") != -1|| strsrch(msg,"antpeople") != -1 || strsrch(msg,"Antpeople") != -1)
	   {
		   force_me("emote %^CYAN%^nods towards one of the documents on the table.\n");
		   force_me("say Yes, it is true that there have been sightings of what could possibly be a formian hole.\n");
		   force_me("say Not many know of those 'Antpeople'. But I surely hope that it stays but a rumor, though one of my men swears he saw one.\n");
		   force_me("emote %^CYAN%^sighs and shakes his head.\n");
		   force_me("say This is one threat this island could be without, on top of everything else!\n");
	   return;}
	   if(strsrch(msg,"illithid") != -1 || strsrch(msg,"Illithid") != -1 || strsrch(msg,"mindflayer") != -1 || strsrch(msg,"Mindflayer") != -1){
		   force_me("emote %^CYAN%^looks worried and nods.\n");
		   force_me("say Yes. It is true there is a Illithid cave here on the island. Blessed the Protector that they do not walk on the surface .. Yet!\n");
		   force_me("say If that were to happen, I doubt that Asgard would ever be rebuilt!\n");
		   force_me("say There are even those who would let you know there is a dragon in those caves. I don't believe that though.\n");
		   if(TP->query_level()>25){
			   force_me("say If I were you, I would keep clear of that cave. Illithids are a threat not to be taken lightly!\n");
		   }
    return;}
		if(strsrch(msg,"asgard") != -1 || strsrch(msg,"Asgard") != -1 || strsrch(msg,"tarrasque") != -1 || strsrch(msg,"Tarrasque") != -1){
			force_me("emote %^CYAN%^sighs heavily and shakes his head.\n");
			force_me("say A terrible business that Tarrasque! Very few who ever see the beast lives to tell the tale!\n");
			force_me("say It simply 'walked' over the city of Asgard, trampling houses and castles as mere pebble on the road!\n");
			force_me("say Were it not for a lot of very brave and powerful adventurers, I doubt that the beast would have stopped before the whole island was destroyed!\n");
			force_me("say Not surprisingly, it was a cult of Talossian fanatics who summoned the beast somehow!\n");
			force_me("emote %^CYAN%^frowns angrily.\n");
			force_me("say Now we do the best we can to help the survivors over here, and hopefully make it a livable place again!");
		return;}
		if(strsrch(msg,"parnelli") != -1 || strsrch(msg,"Parnelli") != -1){
			force_me("emote %^CYAN%^looks saddened.\n");
			force_me("say I visited that forest quite often before the whole thing with the Tarrasque. Used to be such a lovely place!\n");
			force_me("say Now ... not so much! A lot of corruption is there now, shambling mounds roaming everywhere and making the restoration almost impossible!\n");
			force_me("say You can still reach the forest by the carriage house in the eastern part of the desert, I bet the defenders of the Ruins would appreciate the help!\n");
			if(TP->query_level()>20){
				force_me("say I would advise you from going there yet though. The corrupted beings there are quite powerful!\n");
			}
		return;}
		if(strsrch(msg,"plains") != -1 || strsrch(msg,"Plains") != -1|| strsrch(msg,"wasteland") != -1 ||strsrch(msg,"wastelands") != -1){
			force_me("say Yes, both the Wastelands and the Gods Plains are just east of here. Horrid places I tell you!\n");
			force_me("say the only civilized thing you will find there is Sir Silvim. A Holy knight on the hunt for his nemesis Arganon.\n");
			force_me("say Besides that, nothing. Destroyed lands, roamed by tlincallis, flailers, thri-kreens amongst others .. on the plains there are even Titans and Drakes! I would avoid them if I were you!\n");
		}
		if(strsrch(msg,"torm") != -1 || strsrch(msg,"Torm") !=  -1 || strsrch(msg,"outpost") != -1 || strsrch(msg,"Outpost") != -1){
			force_me("emote %^CYAN%^sighs hopelessly.\n");
			force_me("say Honestly, it is the Gnolls that made us come here in a larger force.\n");
			force_me("say We have always been sending supplies and re-enforcements to the survivors in the ruins of Asgard. But lately almost all of our shipments have been attacked by the Gnolls!\n");
			force_me("say So now we send an armorered patrol with every shipment from here and to the ruins. It is hard work, and not cheap.\n");
			force_me("say In past times, Torm and Asgard were sister cities. Though we were not so 'close' in later years, it is still humans who live there, and it is our duty to help our allies.\n");
		return;}
		if(strsrch(msg,"hello") != -1 ||strsrch(msg,"Hello") != -1 ||strsrch(msg,"hi") != -1 ||strsrch(msg,"Hi") != -1 ||strsrch(msg,"Greetings") != -1 ||strsrch(msg,"greetings") != -1){
			force_me("emote %^CYAN%^looks up from the documents on the table and smiles.\n");
			force_me("say Greeting traveler. Welcome to Laerad! The island that smells of rotten egg and will do everything it can to kill you!\n");
			force_me("emote %^CYAN%^chuckles a little to himself.\n");
			force_me("say Forgive me, being here for too long give you that kind of humor. Let me know if you need any information regarding the island.\n");
		return;}
		if(strsrch(msg,"Laerad") != -1 ||strsrch(msg,"laerad") != -1 ||strsrch(msg,"island") != -1 ||strsrch(msg,"Island") != -1){
			force_me("say Well. Just to the east of here you will find the 'wastelands' and the 'plains'. It is also here you will find the 'gnolls'.\n");
			force_me("say To the south of that there is the swamp, but I do not know much about that I am afraid.\n");
			force_me("say Further east, if you take the carriage ride, you will get to the 'parnelli' forest.\n");
			force_me("say In short, that is the island for you. I can tell you more if you have questions.\n");
		return;}
		force_me("emote %^CYAN%^shakes his head.\n");
		force_me("say That I don't know anything about.");
return;}
			
			


void rush_em(object ob){
  command("rush "+ob->query_name());
  TO->kill_ob(ob,1);
  
  
  return 1;
}
