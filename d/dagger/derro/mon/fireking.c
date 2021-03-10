//updated to current code ~Circe~ 7/31/19

#include <std.h>
#include "../derrodefs.h"

inherit MONSTER;

object ob, targ;

void create(){
   ::create();
   set_name("fire giant king");
   set_id(({"giant","fire giant","king","ravhas"}));
   set_race("giant");
   set_gender("male");
   set_short("%^BOLD%^%^RED%^Ravhas, king of the fire giants%^RESET%^");
   set_long("This massive creature is a sight to make you tremble with fear.   His massive frame is fully armored, and he has a great sword that takes two hands for this 18-foot-tall giant to wield.  This fire giant king is most upset about whats happened to his clan and doesn't look too happy to see anyone else here, let alone you!  Perhaps you could try to %^BOLD%^calm %^RESET%^%^CYAN%^him?%^RESET%^");
   set_ac(-5);
   set_mob_magic_resistance("average");
   set_mlevel(39);
   add_search_path("/cmds/fighter");
   set("aggressive","agggunc");
   set_alignment(9);
   set_hd(39,2);
   set_property("full attacks",1);
   set_stats("strength",24);
   set_stats("intelligence",13);
   set_stats("wisdom",15);
   set_stats("dexterity",18);
   set_stats("constitution",19);
   set_stats("charisma",13);
   set_guild_level("fighter",35);
   switch(random(5)){
      case 0: ob=new("/d/common/obj/rand/rand_shirts.c");
              ob->set_property("enchantment",1);
              ob->move(TO);
              break;
      default: ob=new(OBJ"fireplate.c");
               if(!random(2)) ob->set_property("monsterweapon",1);
               ob->move(TO);
               break;
   }
//The above was adjusted because the king cannot wear both magical plate and a
//magical shirt. ~Circe~ 1/4/13
   new(OBJ"steelhelm.c")->move(TO);
   //Added to put another Katana IG sometimes - Saide - 10/16/04
   switch(random(2)){
      case 0: new(OBJ"flameblade.c")->move(TO);
              break;
      default: new(OBJ"sildorekatana.c")->move(TO);
               break;
   }
   new(OBJ"greatcloak.c")->move(TO);
   if(!random(2)) present("helm",TO)->set_property("monsterweapon",1);
   if(!random(2)) present("sword",TO)->set_property("monsterweapon",1);
   command("wield sword");
   command("wear cloak");
   command("wear plate");
   command("wear helmet");
   command("wear shirt");
   add_money("gold",200+random(1000));
   set_hp(500);
   set_exp(20000);
   set("aggressive","agg_func");
   set_stabbed_func((:TO,"stabbed":));
   remove_property("swarm");
}

void init(){
   ::init();
   add_action("ask","ask");
   add_action("calm","calm");
}

void catch_say(string msg){
   call_out("reply_func",1,msg,TP);
}

void calm(string str){
   force_me("say Hmm ... you don't appear to be minions of the Derro.  I have little time for you, puny one.  If you have questions, ask them and be off with you before I burn you where you stand!");
   return;
}

void receive_given_item(object item){
   object *targ;
   int i,j;
   if(present("ornate secari",TO)){
      force_me("emote roars as he grabs the dagger and with one massive stroke smashes it with his flaming sword.");
      force_me("say BAH! I could've done the same if I could sneak past the ones who guard my door, but no matter.  I'll deal with them when I feel fit!");
      force_me("say Our home has no exits.  We sealed it off with a great block of stone that allows only those who befriend it through.");
      force_me("say Go talk with my earth priest. I hear the Derro have captured him, but he can tell you how to do the %^CYAN%^deed%^WHITE%^ required to leave.");
      ob=present("ornate secari",TO);
      ob->remove();
      targ=all_living(ETO);
      j=sizeof(targ);
      for(i=0;i<j;i++){
         if(!objectp(targ[i])) break;
            targ[i]->set("TRusted",1);
      }
      return;
   }
   return;
}

void ask(string str){
   tell_object(TP,"What would you like to ask him? You can simply speak aloud, and he will respond.");
   return;
}

//Changing him to use catch_say, but adding a hint for old players
void reply_func(string msg, object who){
   object current;
   object obj;
   string name;

   if (!objectp(who)) {
       return;
   }
   set_spoken("wizish");
   name = who->query_name();
   if(!msg || !objectp(who)) return;
   if(strsrch(msg,"Hi") != -1 || strsrch(msg,"hail") != -1 ||
      strsrch(msg,"reeting") != -1 || strsrch(msg,"ello") != -1 ||
      strsrch(msg,"Hail") != -1){
      force_me("say Do I look like I want to talk to you?");
      return;
   }
   if(strsrch(msg,"aptive") != -1){
      force_me("say Ahh, yes, my earth priest.  Lot of good he did convincing me to free %^RED%^the being%^RESET%^ from the lava.  "
         "Wounded after the thing attacked and then wandered into the %^BLUE%^Derro%^RESET%^'s clutches.");
      force_me("say Knows a lot, though ... he'd be the one who can show you the %^BOLD%^way out%^RESET%^.");
      return 1;
   }
   if(strsrch(msg,"way out") != -1){
      force_me("say The entrance to my kingdom was sealed with a block of stone that allows only those it knows through.  "
         "My earth priest knows how to befriend it ... and from what I hear, that bastard %^BLUE%^savant%^RESET%^ figured out a way as well.");
      return 1;
   }
   if(strsrch(msg,"the being") != -1){
      force_me("emote 's knuckles go white as he clutches his massive flaming sword!");
      force_me("say That thing was just too much! I've hunted dragons and fought the surface dwellers' armies for ages, "
            "but I've never come across anything of its likes.  Beware if you should cross its path. It destroyed my clan!");
      return 1;
   }
   if(strsrch(msg,"erro") != -1){
      force_me("say Those pale little bastards.  I thought mountain dwarves were bad enough, and then these little freaks burrow up from the "
         "depths for who knows what reason at the command of thier %^BLUE%^savant%^RESET%^.  They swarm all over the place, and "
         "they work well with the magic of the %^BLUE%^students%^RESET%^ of the %^BLUE%^savant%^ too well!");
      return 1;
   }
   if(strsrch(msg,"avant") != -1){
      force_me("say The savant is the master of the group here.  I don't know what he is up here for, but his magic powers are great, and his "
         "mind keen enough to take advantage of my dire circumstances.  Why he hasn't commanded his little maggots to swarm me here, "
         "I don't know, but they're happy to just swarm my kingdom, searching for something.");
      force_me("emote pauses and evaluates you.");
      force_me("say His death would make me trust you a little more than I should.  Bring me his %^BLUE%^secari%^RESET%^.");
      return 1;
   }
   if(strsrch(msg,"tudent") != -1){
      force_me("say Magic-using dwarves struggling to gain enough power to usurp thier master %^BLUE%^savant%^RESET%^.  "
         "They hold the masses of Derro warriors in thrall in their search for spells and devices of arcane power.");
      return 1;
   }
   if(strsrch(msg,"ecari") != -1){
      force_me("say The secaris are the daggers the %^BLUE%^Derro%^RESET%^ carry.  The ones the warriors carry are so "
         "pathectic as to be worthless, but the ones the %^BLUE%^savant%^RESET%^ and his %^BLUE%^students%^RESET%^ carry "
         "are empowered with magic power.  Give me the secari the %^BLUE%^savant%^RESET%^ carries, and I'll think more about letting you go.");
      return 1;
   }
   if(strsrch(msg,"deed") != -1){
      force_me("say Ask the captive about the deed.");
      return 1;
   }
}

void heart_beat(){
   int i,j;
   object *att;
   ::heart_beat();
   if(!objectp(TO) || !objectp(ETO)) return;
   if(present("secari",TO)){
      force_me("say Bah, this one is from the weak students.  Means nothing.");
      command("offer secari");
   }
   if(present("coins",ETO)) { command("get coins"); }
   if(present("derro",ETO)) { command("rush derro"); }
   if(query_hp()<490) { TO->add_hp(1); }
   if((att=(object *)TO->query_attackers()) !=({})){
      j=sizeof(att);
      for(i=0;i<j;i++){
         if(living(att[i]) && !userp(att[i])){
            if(!objectp(att[i])) continue;
            tell_room(ETO,"%^BOLD%^%^RED%^The king roars and "+att[i]->query_name()+" flees in terror!");
            att[i]->run_away();
         }
         if(att[i]->query_highest_level()>30){
            if(!objectp(att[i])) continue;
            call_out("force_me",2,"rush "+att[i]->query_name());
         }
      }
   }
}

void stabbed(){
   if(!objectp(TP) || !objectp(TO) || !objectp(ETO)) { return; }
   TP->set_disabled(5);
   tell_room(ETO,"%^BOLD%^%^RED%^The king's armor prevents the full force of "+TPQCN+"'s stab!%^RESET%^",TP);
   tell_object(TP,"%^BOLD%^%^RED%^The king's armor prevents the full force of your stab!%^RESET%^");
   if(query_hp()<100) set_hp(100);
   return;
}
