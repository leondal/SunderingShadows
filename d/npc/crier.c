// town crier of Shadow city

#include <std.h>
#include <daemons.h>

inherit "/std/npc.c";

#define SHDIR "/d/shadow/room/city/"
// #define NAME_D "/realms/obsidian/daemon/name_d.c"

void create(){
   string name;
   ::create();
   set_db("crier");
   set_random_act_db("crierrandom");
   set_random_act_chance(5);
/*
   // utilizing the name daemon
   if((string)(name = NAME_D->query_name(base_name(TO))) == ""){
      NAME_D->setup_file(base_name(TO));
      name = NAME_D->query_name(base_name(TO));
   }
*/
   name = "ceaversol";
   set_name("town crier");
   set_id(({"man","crier","town crier",name}));
   set_short("%^RESET%^%^GREEN%^"+capitalize(name)+" the town crier%^RESET%^");
   set_long("%^GREEN%^"+capitalize(name)+" is the newest town crier "
      "of Shadow. He wanders the city of Shadow and the surrounding "
      "areas informing people of news of the land. He is also well "
      "known for his knowledge about the realms.");
   set_gender("male");
   set_hd(5,1);
   set_size(2);
   set_wielding_limbs(({"right hand","left hand"}));
   set_overall_ac(8);
   set_hp(50);
   set_max_hp(50);
   set_exp(10);
   set_body_type("human");
   set_race("human");
   set_class("fighter");
   set_guild_level("fighter",5);
   set_mlevel("fighter",5);
   set_stats("strength",16);
   set_stats("constitution",14);
   set_stats("dexterity",16);
   set_stats("wisdom",12);
   set_stats("intelligence",16);
   set_stats("charisma",18);
   set_alignment(5);
   set("aggressive",0);
   set_property("alignment adjustment",-50);
   remove_property("swarm");
   set_speed(30);
   new("/d/common/obj/armour/robe.c")->move(TO);
   command("wear robe");
}

void init(){
   string name;
   ::init();
   if(TP->query_invis()) return;
//   if(!userp(TP) && !TP->is_townsman()) return;
// bugs sometimes with the Shadow watch so we'll see if ignoring npcs fixes that  
// *Styx* 11/02 - Well, this change didn't get uploaded in Nov. but looking at 
// another bug T thought this would be the right fix, so here it is for real now.  6/14/03
   if(!userp(TP))   return;
   add_action("buy_func","buy");
   if(!name = TP->query_vis_name()) name = TP->query_name();
   if(!query_interact() && random(4) &&
      member_array(name,KILLING_D->query_bounties()) != -1){
      if(random(2)) force_me("ack");
      if(random(2)) force_me("say RUN!");
      run_away();
      return;
   }
   if(!query_interact() && roll_dice(2,20) < roll_dice(2,20)){
      if(member_array(name,KILLING_D->query_bounties()) != -1)
         return;
      set_interact();
      call_out("reset_interact",2);
      switch(random(5)){
         case 0:
            force_me("say How are you today "+TPQCN+"?");
            force_me("smile");
            break;
         case 1:
            force_me("say Hi "+TPQCN+"! Do you need a map of Shadow?");
            force_me("ponder");
            break;
         case 2:
            force_me("say Hey there "+TPQCN+"! Lovely weather today eh?");
            force_me("gwert "+TPQN);
            break;
         case 3:
            force_me("say Greetings "+TPQCN+"! What brings you to our lovely city today?");
            force_me("flip");
            break;
         case 4:
            if((string)TP->query_position() == "newbie"){
               force_me("say Hello! Are you new in town "+TPQCN+"?");
               force_me("cackle");
            }
            else if((string)TP->query_position() == "player"){
               force_me("say Hello! You look so familiar "+TPQCN+"!");
               force_me("smile "+TPQN);
            }
            else{
               force_me("bow "+TPQN);
               force_me("say When I grow up I want to be just like you "+TPQCN+"!");
            }
            break;
         default:
            force_me("say "+TPQCN+"!!! It has been so long!");
            force_me("hug "+TPQN);
            break;
      }
   }
}

int buy_func(string str){
   if(!str){
      notify_fail("Buy what?\n");
      return 0;
   }
   if(str != "map"){
      notify_fail("Buy what?\n");
      return 0;
   }
   if(TP->query_invis()) return 0;
   if((int)TP->query_money("gold") < 5) {
      set_spoken(TP->query_spoken());
      force_me("say You don't have 5 gold even!\n");
      return 1;
   }
   TP->add_money("gold",-5);
   new( "/d/shadow/obj/misc/map.c" )->move(TO);
   set_spoken(TP->query_spoken());
   force_me("say Thanks so much "+TPQCN+"!");
   force_me("say Here is your map!");
   force_me("give map to "+TPQN);
   force_me("smile "+TPQN);
   return 1;
}

void heart_beat(){
   object ob,*killers;
   int i;
   ::heart_beat();
   if(!objectp(TO) || !objectp(ETO)) return;
   if((ob = present("cityguard",ETO)) && (query_hp() == query_max_hp())){
      tell_room(ETO,"The guard goes back to his own work.");
      ob->move("/d/shadowgate/void");
      ob->remove();
   }
   if(query_hp() < 45 && !present("cityguard 2",ETO)){
      command("yell HELP!!!");
      tell_room(ETO,"You see a guard rushes in to help the Town crier.");
      ob = new("/d/shadow/mon/guard1");
      ob->move(ETO);
      ob->set_stats("strength",25);
      ob->set_stats("dexterity",25);
      ob->force_me("protect crier");
      ob->force_me("protect crier");
      ob->force_me("say I will protect our town folks!");
      killers = query_attackers();
      add_follower(ob);
      for(i=0;i<sizeof(killers);i++){
         ob->kill_ob(killers[i],1);
      }
   }
   if(query_hp() < query_max_hp()) heal(1);
}

// override the void move_around() function in /std/monster.c
// disallowing town crier from leaving Shadow city
void move_around(){
   string *exits,exit,exitn;
   if(!TO) return;
   if(!objectp(ETO)) return;
   // he is in action right now, query_interact() != 0, no leaving
   if(query_interact()) return;
   ETO->setupExits();
   if(query_current_attacker()) return;
   if(ETO) exits = (string*)ETO->query_exits();
   else exits = 0;
   if(sizeof(exits)){
      exit = exits[random(sizeof(exits))];
      exitn = ETO->query_exit(exit);
      exitn->init();
      if( (exit != "temple") && (exitn != SHDIR+"southgate")
         && (exitn != "/d/shadow/room/main/northgate")
         && (exitn != SHDIR+"eastgate") && (exitn != SHDIR+"westgate") ){
         switch(random(3)){
            case 0:
               force_me("tip");
               break;
            case 1:
               force_me("wave");
               break;
            case 2:
               force_me("say have a nice day");
         }
         command(exit);
      }
   }
   // resetting the global variable 'moving' in /std/monster.c
   moving=0;
}
/*
void die(object obj){
   // employ a new town crier (new name) cuz the old crier is dead
   NAME_D->set_name(base_name(TO));
   ::die(obj);
}
*/
