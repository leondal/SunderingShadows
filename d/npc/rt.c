// Rollo Taylor, wandering tailor of Shadow
// Thorn@ShadowGate
// 23 July 2000
// /d/npc/rollo.c

#include <std.h>
#include <daemons.h>
#include "/d/npc/rollo.h"

#define SHDIR "/d/shadow/room/city/"

inherit "/std/npc.c";

int wait(int x);

object OBJ;
int STARTED;
object workingFor;
string TYPE;
int ENUMBER;
string COLOR;
string EMBLEM;
string CUSTOM;
int NODYE;
int NOEMB;
int DONE;
int WAIT_TIMER = 0;

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
clothes.  Of course, this makes sense as he is a master tailor who makes
his living making alterations to clothing, sewing emblems and repairing
worn apparel.  Master Rollo will be happy to do any of these services
for you if you let him know that you need a tailor.
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
 ob = new("/d/shadow/obj/armor/robe.c");
 ob->set_short("a fine %^RED%^BOLD%^crimson silk robe%^RESET%^");
 ob->set("monsterweapon",1);
 ob->move(TO);
 command("wear robe");
 ob = new("/d/shadow/obj/misc/rollorates.c");
 ob->set("monsterweapon",1);
 ob->move(TO);
 ob = new("/d/shadow/obj/misc/rolloemblist.c");
 ob->set("monsterweapon",1);
 ob->move(TO);
 ob = new("/d/npc/obj/rollokit.c");
 ob->set("monsterweapon",1);
 ob->move(TO);
}

void init(){
 string name;
 ::init();
 add_action("start_func", "letsdoit");
 add_action("wait_for", "waitfor");
 add_action("dye_func", "dyeitbaby");
 add_action("get_func", "gogeta");
 add_action("done_func", "rocknroll");
 add_action("nodye_func", "nodye");
 add_action("sew_func", "sewwhat");
 add_action("thread_func", "threadof");
 add_action("next_func", "nextemblem");
 
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

void heart_beat(){
 object ob,*killers;
 int i;
 ::heart_beat();
 if(WAIT_TIMER) WAIT_TIMER--;
 if(!objectp(TO) || !objectp(ETO)) return;
 if((ob = present("cityguard",ETO)) && (query_hp() == query_max_hp())){
    tell_room(ETO,"The guard goes back to his own work.");
    ob->move("/d/shadowgate/void");
    ob->remove();
 }
 if(query_hp() < 45 && !present("cityguard 2",ETO)){
    command("yell HELP!!!");
    tell_room(ETO,"You see a guard rush in to help the Town crier.");
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

int working_for(string str) {
  STARTED = 1;
  workingFor = find_player(str);
  return 1;
}

int give_up() {
  STARTED = 0;
  CUSTOM = 0;
  COLOR = 0;
  if(OBJ) {
    force_me("offer "+TYPE);
  }
  OBJ = 0;
  TYPE = 0;
  workingFor = 0;
  force_me("say All that work for nothing!");
  wait(1);
  force_me("grumble");
  return 1;
}

int start_func(string player) {
  if(!STARTED) {
    workingFor = find_player(lower_case(player));
    STARTED = 1;
    force_me("say Right!  Let's get started.  What would you like to design?");
    force_me("say A robe?  A cloak?  Perhaps a silk robe?");
    return 1;
  }
  else {
    force_me("say I'm a little busy right now, "+player+".");
    return 1;
  }
  return 1;
}

int waitfor(string time) {
  int x;
  sscanf(time, "%d", x);
  remove_call_out("give_up");
  call_out("give_up", x);
  return 1;
}

int get_func(string item) {
  object ob;
  if(OBJ) {
    force_me("say I'm already working with something!");
    return 1;
  }
  if(!STARTED) {
    force_me("say You want to design something, eh?");
    wait(1);
    force_me("say Perhaps you should say that you would like to "+
	  "design something.");
    wait(1);
    force_me("smile");
    return 1;
  }
  OBJ = new(TAILOR_LIST[item]);
  OBJ->move(TO);
  TYPE = item;
  CUSTOM = "a "+TYPE;
  
  // If this item cannot have any further customization done to it
  // then give it up.
  if(DONE) {
    TO->done_func();
    return 1;
  }
  
  // If this item can have a custom logo on it, but not be colored itself,
  // then skip over the dying part.
  if(NODYE) {
    force_me("say Well, you've picked an item of clothing that you "+
	  "can't dye...");
    force_me("say ...but I can still sew an emblem or two on it.");
    wait(1);
    force_me("smile "+workingFor->query_name());
    wait(1);
    force_me("say Would you say that you would like an emblem or is "+
	  "the item done?");
    return 1;
  }
  return 1;
}


int dye_func(string color) {
  // If this item can have a custom logo on it, but not be colored itself,
  // then refuse their request and present their options again.
  if(NODYE) {
    force_me("say You've picked an item of clothing that you "+
	  "can't dye...");
    wait(1);
    force_me("say ...I thought I mentioned that.");
    wait(1);
    force_me("shrug");
    wait(1);
    force_me("say So, would like an emblem or is the item "+
	  "done?");
    return 1;
  }
  // If the object is present in the tailor's inventory, then work on it.
  if(present(OBJ, TO)) {
    CUSTOM = "a "+COLORS[color]+" "+TYPE;
    COLOR = color;
    force_me("say You got it!  One "+CUSTOM+" coming up!");
    OBJ->set_short(CUSTOM);
    return 1;
  }
  else if(STARTED) {
    force_me("say My goodness!  I am forgetful today.  "+
	  "I seem to have...umm...");
    wait(1);
    force_me("say ...misplaced your item.");
    wait(2);
    force_me("say Wait!  Here it is!");
    OBJ = new(TAILOR_LIST[TYPE]);
    OBJ->move(TO);
    CUSTOM = "a "+TYPE;
    wait(1);
    force_me("emote whews.");
    wait(1);
    force_me("say Now where was I?");
    wait(1);
    CUSTOM = "a "+COLORS[color]+" "+TYPE;
    OBJ->set_short(CUSTOM);
    force_me("say Ahh, yes...one "+CUSTOM+" all done!");
    wait(1);
    force_me("say Now, would like an emblem or is the item done?");
    return 1;
  }
  else {
    force_me("say Dye this!");
    wait(1);
    force_me("cackle");
    return 1;
  }   
  return 0;
}

int done_func() {
  int CHARGE;
  if(STARTED && OBJ) {
    CHARGE = BASE_PRICE + PRICES[TYPE];
    force_me("say We're all set!  That will be "+CHARGE+" gold!");
    wait(1);
    if(!(int)workingFor->force_me("give "+CHARGE+"gold coins to tailor")) {
      force_me("say Seems like you are a bit short, eh?");
      wait(1);
      force_me("say Oh well....");
      wait(1);
      give_up();
      return 1;
    }
    force_me("say Here you go....");
    force_me("give "+TYPE+" to "+workingFor->query_name());
    wait(1);
    force_me("say Thanks for your business!");
  }
  else return 0;
}

void nodye_func() {
  NODYE = 1;
}

void sew_func(string emb) {
  EMBLEM = emb;   
}

int thread_func(string color) {
  if(!ENUMBER) CUSTOM = "%^RESET%^GREEN%^ with the sign of ";
  else CUSTOM += " and ";
  CUSTOM += "a "+COLORS[color]+" "+EMBLEM+"%^RESET%^";
  ENUMBER++;
  return 1;
}

int next_func() {
  return 1;
}

// Causes the execution of a function to stop for x
// heartbeats.  
int wait(int x) {
  while(WAIT_TIMER);
  return 1;
}
