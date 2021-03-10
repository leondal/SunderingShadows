// Ellgarsh al-Radin
// Thorn@ShadowGate
// 970309
// Changed into an NPC with quests - 001116
// Town of Azha
// alradin.c

#include <std.h>
#include "/d/tsarven/include/southern.h"
#include "/d/azha/azha.h"

#define FATIMA_QUEST_LEVEL 15
#define DAGGER_QUEST_LEVEL 20
#define THANATOS_QUEST_LEVEL 25

#define FATIMA_QUEST "Rescue of Fatima D'Vastari"
#define DAGGER_QUEST "Dagger of Syndic"
#define THANATOS_QUEST "The Lich Prince of Azha"

inherit NPC;

int flag;
int NOT_DONE;
object brooch;

int wait(int x);

void create()
{
  object ob, ob2;

  ::create();
  set_name("al-Radin");
  set_id( ({ "alradin","ellgarsh","al-radin","radin" }) );
  set("race", "elf");
  set_gender("male");
  set("short", "Ellgarsh al-Radin");
  set_property("assassin", 1);
  set_property("no steal", 1);
  set_mob_magic_resistance("average");
  set_long(
@AZHA
  Anyone who has ever been to Azha knows this elf, formerly a frequent
guest at the Celestial Emperor tavern.  His hair is a dark brown and
tied back in a long pony tail.  There is one long, slim braid of hair
that falls in front of his left ear and down to the middle of his neck. 
His luminous green eyes are set like shining jewels in his thin, pale
face.  As one might expect, his nearly colorless lips are set in an what
might be called a soft sneer. Below that, its hard to tell much about
his body, as it is covered entirely in loose fitting black and grey
clothing. He appears to be without any weapons, but you probably
shouldn't bet on that.
AZHA
  );
  set_level(36);
  set_body_type("human");
  set_class("thief");
  set("aggressive", 0);
  set_alignment(5);
  set_size(2);
  set_hd(36, 8);
  set_exp(10000);
  remove_property("swarm");
  set_speed(55);
  set_stats("intelligence",15);
  set_stats("wisdom",11);
  set_stats("strength",16);
  set_stats("charisma",18);
  set_stats("dexterity",21);
  set_stats("constitution",17);
  set_max_mp(0);
  set_hp(400);
  set_max_hp(query_hp());
  set_max_sp(query_hp());
  set_sp(query_max_sp());
  add_money("silver",random(100));
  add_money("gold",random(60));
  add_money("copper",random(10));
  add_search_path("/cmds/thief");
  set_thief_skill("pick pockets", 95);
  set_thief_skill("hide in shadows", 95);
  set_thief_skill("move silently", 95);
  ob=new("/d/tharis/obj/wrist_sheath");
  ob->set_property("monsterweapon",1);
  ob->move(TO);
  force_me("wear sheaths");
  ob2=new("/d/attaya/obj/screamer");
  ob2->set_property("monsterweapon",1);
  ob2->move(TO);
  ob=new("/d/azha/obj/gmr_ring");
  ob->move(TO);
  command("wear ring");
  ob=new("/d/common/obj/sheath/sheath_medium");
  ob->move(TO);
  command("wear sheath");
  ob=new("/d/azha/equip/fort/runeblade");
  ob->move(TO);
  command("sheath rune");
  brooch=new("/d/azha/obj/alradinbrooch");
  brooch->set_property("monsterweapon",1);
  brooch->set_owner(TO);
  brooch->move(TO);

  command("put dagger in sheath");
  add_dbs(({"alradin"}));
  remove_std_db();
  flag = 0;
  NOT_DONE = 0;
  set_funcs(({"special_fcn"}));
  set_func_chance(60);
}

// Causes the execution of a function to stop for x
// heartbeats.  
// Al-Radin's particular speech patterns.
int talk(string str) {
  force_me("say %^GREEN%^BOLD%^"+str);
  return 1;
}

heart_beat() {
  object atkr,ob;

  if(!objectp(TO) || !objectp(ETO)) return;
  ::heart_beat();
  atkr = query_current_attacker();
  if(!atkr) {
    flag = 0;
	if(query_hp() < query_max_hp()) heal(2);
    if(ob=present("runesword"))
      TO->force_me("sheath rune");
    return;
  }
  else { 
  	TO->force_me("draw rune");
  	set_scrambling();
  }
}

init()
{
  ::init();
  add_action("xstab", "stab");
  add_action("xrush", "rush");
  add_action("brooch", "brooch");
}

int xstab(string str)
{
  object ob;

  if(flag) return 0;
  if(member_array(str, query_id()) != -1) {
    write(
@RAD
%^YELLOW%^BOLD%^As you bare your weapon to stab Ellgarsh, he wheels around and catches
your hand!
%^RESET%^MAGENTA%^He smiles for a split second, his teeth flashing....

RAD
  );
    force_me("speech say with a soft growl");
    force_me("say %^GREEN%^BOLD%^Nice try.");
    ob=new("/d/attaya/obj/screamer");
    ob->set_property("monsterweapon",1);
    ob->move(TO);
    TO->force_me("wield dagger");
    flag = 1;
    TO->force_me("stab "+TPQN);
    return 1;
  }
return 0;
}

int xrush(string str)
{
  object ob;

  if(flag) return 0;
  if(!random(3)) return 0;
  TO->force_me("speech shout angrily");
  TO->talk("Damn you, "+TPQCN+"!  I won't be taken so easily!");
  ob=new("/d/attaya/obj/screamer");
  ob->set_property("monsterweapon",1);
  ob->move(TO);
  TO->force_me("wield dagger");
  flag = 1;
  TO->force_me("stab "+TPQN);
  return 1;
}

// override the void move_around() function in /std/monster.c
// disallowing town crier from leaving Shadow city
void move_around(){
   string *exits,exit,exitn;
   if(!TO) return;
   if(!objectp(ETO)) return;
   // he is in action right now, query_interact() != 0, no leaving
   if(query_interact()) return;
   if(query_unconscious()) return;
   if(query_bound()) return;
   ETO->setupExits();
   if(query_current_attacker()) return;
   if(ETO) exits = (string*)ETO->query_exits();
   else exits = 0;
   if(sizeof(exits)){
      exit = exits[random(sizeof(exits))];
      exitn = ETO->query_exit(exit);
      exitn->init();
      if( (exit != "temple") && (exitn != "/d/tharis/road/wroad30")
         && (exitn != "/d/tharis/barrow/rooms/bd1")
         && (exitn != "/d/tharis/road/wroad1") ){
         command("sneak "+exit);
      }
   }
   // resetting the global variable 'moving' in /std/monster.c
   moving=0;
}

int special_fcn(object targ){
    int num;

    num = random(2);
    switch(num){
    case 0:
	if(targ->query_property("powdered")){
	    command("smirk "+targ->query_name());
	    command("say Powder...how mundane.");
	    tell_object(targ, "%^RED%^al-Radin delivers a stunning axe kick to your shoulder!");
	    tell_room(ETO, "%^RED%^al-Radin raises his leg into the air and brings it down on "+targ->query_possessive()+" shoulder with great force!", ({targ}));
	    targ->cause_typed_damage(targ, "head", roll_dice(9, 8), "bludgeoning");
	} else {
	    command("sneer");
	    command("toss powder at "+targ->query_name());
	}
	return 1;
	break;
    case 1:
    if(!random(10)){
	    command("say Let's see how you like THIS!");
	    TO->cease_all_attacks();
	    command("stab "+targ->query_name());
	} else {
	    tell_object(targ, "al-Radin dives at you with his dagger, driving it deep into your leg!");
	    tell_room(ETO, "al-Radin dives at "+targ->query_cap_name()+" driving his sword deep into "+targ->query_possessive()+" leg!", ({targ}));
        targ->cause_typed_damage(targ, "torso", roll_dice(8, 10), "piercing");
	    command("say Die.");
	}
	return 1;
	break;
    }
}

// Interaction functions.  Work with the DB to allow our NPC to act
// intelligently.

int hello_reaction(string str) {
  object player;
  string *quests;
  string pname;
  int tindex = 2;
  
  player = find_player(str);
  if(!player) return 0;
  pname = player->query_name();
  quests = player->query_quests();
  
  if(query_invis()) set_invis();
  if(player->query_stats("charisma") > 14)
    force_me("speech say in a friendly tone");
  else if(player->query_stats("charisma") < 9)
    force_me("speech say in an annoyed tone");
  
  call_out("force_me", tindex, "poke "+pname);
  tindex++;
  call_out("talk",tindex, "I'm Ellgarsh al-Radin, friend.");
  tindex += 3;

  if(player->query_highest_level() < 8) {
    force_me("speech say in a condescending tone");
    talk("I'm afraid I'm a little busy to talk to you.");
    wait(10);
	talk("Have a nice day.");
    force_me("nod "+pname);
    return 1;
  }
  else if(member_array(FATIMA_QUEST, quests) == -1) {
    call_out("talk",tindex, "Well met.");
    if(player->query_lowest_level() >= FATIMA_QUEST_LEVEL) {
      tindex += 4;
      call_out("talk",tindex,
        "I don't suppose that you might be able to help me with a certain matter?");
      tindex += 4;
      call_out("talk",tindex,
        "Of course, I don't expect you to do it out of the kindness of your heart.");
      tindex += 3;
      call_out("talk",tindex,
        "I pay do well, if kindness isn't your thing.  Never fear.");
      tindex++;
      call_out("force_me", tindex, "snicker");
      tindex += 4;
      call_out("talk",tindex,
        "Would you like to rescue someone for me?");
	  return 1;
	}
	wait(10);
	talk("When you have earned some more skill and experience, talk to me again.");
    wait(10);
	talk("I hope to see you again soon.  Until then.");
    force_me("bow "+pname);
	return 1;
  }
  else if(member_array(DAGGER_QUEST, quests) == -1) {
	talk("Hello again.  Long time no see.");
    force_me("chuckle");
	wait(1);
	talk("You did a fine job in getting Fatima back to me.  You have my thanks.");
    if(player->query_lowest_level() >= DAGGER_QUEST_LEVEL) {
      force_me("bow "+pname);
	  wait(1);
	  talk("I have a second task for you now, if you are willing.");
	  talk("The payment is higher this time, but the danger is great.");
      wait(1);
	  talk("Would you like to retrieve an item for me?");
	  return 1;
	}
	wait(1);
	talk("When you have earned some more skill and experience, talk to me again.");
	talk("Your past exploits make me anxious to work with you again.");
    wait(1);
	talk("Until then.");
    force_me("bow "+pname);
	return 1;
  }
  else if(member_array(THANATOS_QUEST, quests) == -1) {
    force_me("smile");
	talk("Its good to see you again.");
    if(player->query_lowest_level() >= THANATOS_QUEST_LEVEL) {
	  wait(1);
	  talk("I do have another task for you now, if you are willing.");
	  wait(1);
	  talk("The payment is higher this time, but the danger is extreme.");
	  talk("The time has come to end the Thuggists and their lord.");
      wait(1);
	  talk("Will you help me fight Thanatos?");
	  return 1;
	}
	wait(1);
	talk("When you have earned some more skill and experience, talk to me again.");
	talk("You do some excellent work and I expect you will soon be able to assist me.");
    wait(1);
	talk("Good day.");
    force_me("bow "+pname);
  }
  else if(member_array(THANATOS_QUEST, quests) != -1) {
	talk("Greetings!");
    force_me("smile broadly");
	wait(1);
	talk("Some day we have to get together over drinks and tell stories!");
	talk("I still can't believe we took on Thanatos and won!");
	wait(1);
    force_me("point "+pname);
	talk("A great hero like this must have more than a bard can handle!");
    force_me("laugh");
	return 1;
  }
  else {
	talk("I seem to be a bit out of sorts right now.  Must be that Feywine.");
    force_me("scratch");
	wait(1);
    force_me("burp");
  }
  return 1;
}

int fatima_quest(string str) {
  object player;
  
  player = find_player(str);
  if(!player) return 0;

  return 1;
}

int dagger_quest(string str) {
  object player;
  
  player = find_player(str);
  if(!player) return 0;

  return 1;
}

int thanatos_quest(string str) {
  object player;
  
  player = find_player(str);
  if(!player) return 0;

  return 1;
}

int fatima_award(string str) {
  object player;
  
  player = find_player(str);
  if(!player) return 0;

  return 1;
}

int dagger_award(string str) {
  object player;
  
  player = find_player(str);
  if(!player) return 0;

  return 1;
}

int thanatos_award(string str) {
  object player;
  
  player = find_player(str);
  if(!player) return 0;

  return 1;
}

int brooch(string str) {
  talk("You want my brooch?");
  if(!wizardp(TP)) return 0;
  brooch->move(TP);
  talk("Here you go, boss.");
  return 1;
 }
