// The Shadow Tailor

#include <std.h>
#include <daemons.h>

inherit "/std/npc.c";

#define SHDIR "/d/shadow/room/city/"

void create(){
   object ob;
   string name;
   ::create();
   set_db("tailor");
   set_random_act_db("tailorrandom");
   set_random_act_chance(2);
   name = "taylor";
   set_name("tailor");
   set_id(({"taylor","tailor","rollo"}));
   set_short("%^RESET%^%^YELLOW%^Rollo Taylor, wandering tailor%^RESET%^");
   set_long(
@THORN
%^YELLOW%^Rollo Taylor is a young man dressed in fashionable, well serviced
clothes.  Of course, this makes sense as he is a master tailor who
makes his living making alterations to clothing, sewing emblems and
repairing worn apparel.  Master Rollo will be happy to do any of these
services for you if you let him know that you need a tailor.
THORN
   );
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
   set_stats("strength",14);
   set_stats("constitution",13);
   set_stats("dexterity",17);
   set_stats("wisdom",12);
   set_stats("intelligence",16);
   set_stats("charisma",16);
   set_alignment(5);
   set("aggressive",0);
   set_property("alignment adjustment",-50);
   remove_property("swarm");
   set_speed(25);
   ob = new("/d/npc/obj/robe.c");
   ob->set_short("a fine %^RED%^BOLD%^crimson silk robe%^RESET%^");
   ob->set("monsterweapon",1);
   ob->move(TO);
   command("wear robe");
   ob = new("/d/npc/obj/rollorates.c");
   ob->move(TO);
}

void init(){
   string name;
   ::init();
   if(TP->query_invis()) return;
   if(!userp(TP) && !TP->is_townsman()) return;
   add_action("buy_func","buy");
   if(!name = TP->query_vis_name()) name = TP->query_name();
   if(!query_interact() && random(4) &&
      member_array(name,KILLING_D->query_bounties()) != -1){
      if(random(2)) force_me("ack");
      if(random(2)) force_me("emote slinks away quickly.");
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
            force_me("say Good day, "+TPQCN+".");
            force_me("say You wouldn't happen to need a tailor, would you?");
            force_me("smile");
            break;
         case 1:
            force_me("emote studies "+TPQCN+"'s clothing carefully.");
            force_me("say I'm not one to be critical...");
            force_me("ponder");
            force_me("say ...but I think you would look much better in a tone on tone combination.");
            force_me("nod");
            force_me("say Definitely tone on tone.");
           break;
         case 2:
            force_me("say Just so you know, "+TPQCN+", all you have to do...");
            force_me("say ...is say you need a tailor, and I will be at your service!");
            force_me("bow "+TPQN);
            break;
         case 3:
            force_me("emote studies "+TPQCN+"'s clothing carefully.");
            force_me("say The Viking look went out of style last year, "+TPQCN+".");
            force_me("tsk");
            force_me("say A successful adventurer is a well dressed adventurer!");
            force_me("nod");
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
               force_me("say I am at your service, "+TPQCN+"!");
            }
            break;
         default:
            force_me("emote studies "+TPQCN+"'s clothing carefully.");
            force_me("tsk "+TPQN);
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
      ob->force_me("protect tailor");
      ob->force_me("protect tailor");
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
               force_me("hum");
               break;
            case 1:
               force_me("bow");
               break;
            case 2:
               force_me("say A tailor's work is never done.");
         }
         command(exit);
      }
   }
   // resetting the global variable 'moving' in /std/monster.c
   moving=0;
}
