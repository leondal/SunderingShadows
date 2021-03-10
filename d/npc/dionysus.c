//Dionysus

#include <std.h>
#include <daemons.h>
#include <move.h>
#define MAPPING_D "/daemon/mapping_d.c"

inherit "/std/npc";

int mugs;
string *owner = ({"margath","bryanna","obsidian"});

void create(){
   ::create();
   set_name("dionysus");
   set_short("Dionysus, Rhapsody Barkeep");
   set_id(({"barkeep","dionysus","Dionysus"}));
   set_long(
@OLI
Dionysus stands behind the bar, a large hulk of a man. Thick, meaty forearms
rest upon the countertop, as an ever-vigilant gaze sweeps the length of the
inn and back. His expression is pinched, the kind one finds extremely
difficult to read. He rarely speaks and appears to always be listening, a
trait prized among barkeeps. Occasionally wiping the countertop with a
towel as he takes order after order, he appears to be attending diligently
to the patrons.
OLI
   );
   set_race("human");
  set_guild_level("fighter",30);
   set_wielding_limbs(({"right hand","left hand"}));
   set_attack_limbs(({"right hand","left hand"}));
   set_attacks_num(3);
   enable_commands();
//   set("aggressive",1);
  remove_property("swarm");
   set_gender("male");
   set_hd(30,8);
   set_hp(250);
   set_exp(1);
   set_stats("strength",25);
   set_stats("dexterity",25);
   set_stats("constitution",25);
   set_db("dionysus");
   set_body_type("human");
   set_need_addressed(1);
}

void reset(){
   ::reset();
   mugs = 3;
}

void init(){
   ::init();
   add_action("buy_func","buy");
}

int buy_func(string str){
   object obj;
   string *list1,*list2;
   if(base_name(ETO) != "/d/darkwood/room/rhapsody") return 0;
// added by Styx to avoid letting the comment tell a thief they are hidden
   if(TP->query_hidden())  TP->force_me("step");
   if(TP->query_invis() && member_array(TPQN,owner) == -1) {
      force_me("say How can I hand you stuff if I can't see you?");
      return 1;
   }
   list2 = MAPPING_D->query_keys("rhapsody_unwanted");
   list1 = KILLING_D->query_bounties();
   list1 -= owner;
   if(member_array(TPQN,list2) != -1){
      if(random(2)){
         force_me("say We're not serving you until you pay up for damages "+
            "or make peace with you know who.");
         return 1;
      }
      else{
         force_me("say Surely you don't think we've forgotten what you did?");
         force_me("roll and turns away");
         return 1;
      }
   }
   else if(member_array(TPQN,list1) != -1){
      switch(random(4)){
         case 0:
            force_me("say You know I can't serve you as long as you're "+
               "wanted by the law.");
            break;
         case 1:
            force_me("say If the law is after you, how do we know you're "+
               "not going to kill someone in here too?");
            break;
         case 2:
            force_me("say Please take your business elsewhere until you "+
               "pay your debt to society, we don't want any trouble in here.");
            force_me("emote points to the door.");
            break;
         case 3:
            force_me("say We don't want the Magistrate coming after us for "+
               "harboring criminals, so I have to ask you to leave.");
      }
      return 1;
   }
   else if(str == "ode to torment"){
      if(!mugs && member_array(TPQN,owner) != -1){
         write("No more Ode of Torment in stock.");
         return 1;
      }
      if(mugs && member_array(TPQN,owner) != -1){
         obj = new("/d/darkwood/obj/ode_to_torment");
         tell_object(TP,"You draw yourself an ode of torment");
         if(obj->move(TP)){
            write("You cannot carry it!\nYou drop a "+str+".\n");
            say(TPQCN+" drops a "+str+".\n",TP);
            obj->move(ETP);
         }
         mugs--;
         return 1;
      }
      if(!mugs){
         force_me("say Ode of torment is sold out.");
         return 1;
      }
      if(!TP->query_funds("gold",500)){
         tell_object(TP,"You don't have enough money.");
         return 1;
      }
      else{
         TP->use_funds("gold",500);
         mugs--;
         obj = new("/d/darkwood/obj/ode_to_torment");
         tell_object(TP,"Dionysus gives you a ode of torment");
         tell_room(ETO,"Dionysus collects some gold from "+TPQCN,TP);
         if(obj->move(TP)){
            write("You cannot carry it!\nYou drop a "+str+".\n");
            say(TPQCN+" drops a "+str+".\n",TP);
            obj->move(ETP);
         }
         return 1;
      }
   }
   else return 0;
}

void receive_given_item(object ob){
   if((string)ob->query_short() == "An empty bottle" ||
      (string)ob->query_name() == "bottle"){
      if(!random(10))
         force_me("say Thank you "+TPQCN+", the bottle will be recycled.");
      force_me("emote puts away the empty bottle.");
      ob->remove();
   }
}
