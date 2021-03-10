#include <std.h>
inherit "/std/trainer";

int count;

void create(){
   ::create();
   set_name("rhoc tord");
   set_id(({"rhoc","rhoc tord","tord","ranger"}));
   set_short("%^RESET%^%^GREEN%^Rhoc Tord, retired ranger%^RESET%^");
   set_long("%^RESET%^%^GREEN%^This gangly old ranger sits in the archery, "
"observing and occasionally taking part in a challenge. His leathered face and "
"deep wrinkles show his age. He sits and makes arrows with most of his spare "
"time, his hands constantly in motion as he whittles the slender shafts of wood"
". When he is not caught up in his fletching, he can often be seen instructing "
"the younger rangers of the guild in combat. He will gladly sell to you the arrows he makes, only "
"asking enough money for the materials and a drink.%^RESET%^");
   set_hd(50,10);
   set_hp(2000);
   set_race("human");
   set_gender("male");
   set_alignment(4);
   set_class("ranger");
   new ("/d/common/obj/lrweapon/longbow")->move(TO);
   new ("/d/common/obj/lrweapon/larrows")->move(TO);
   set("speech string","crack");
   set("describe string","in a high tone");
   remove_std_db();
   set_property("no steal",1);
}

void do_training(){}

void init(){
   ::init();
   add_action("buy","buy");
   add_action("challenge","challenge");
}

int buy(string str){
   if (!str || str != "arrows") {
      command("say I only have these arrows, which I am happy to sell to "
"other rangers for training.");
      return 1;
   }
   if (!TP->is_class("ranger") && !TP->is_class("druid")) {
      command("say You not be one of the nature folk. Run along before they realize you're "
"here.");
      return 1;
   }
   if (!TP->query_funds("gold",10)) {
      command("say Sorry young one, but you just don't have the money.");
      command("emote shakes his head sadly");
      return 1;
   }
   if (!present("arrows",TO)) {
      command("say My appologies, but I seem to have grown lax in my fletching "
"work.");
      return 1;
   }
   TP->use_funds("gold",10);
   command("give arrows to "+TP->query_name());
   if (present("arrows", TO)) {
      command("shrug");
      command("drop arrows");
   }
   command("say There ya are, now practice on. We always need good archers.");
   command("emote sits down and starts working on a new arrow-head.");
   new ("/d/common/obj/lrweapon/larrows")->move(TO);
   return 1;
}

int challenge(string str){
   if (count) {
      command("say Can't ya see I'm in the middle of something?");
      return 1;
   }
   command("emote raises an interested eyebrow");
   command("say You're on");
   command("wield bow");
   call_out("do_shot",1,0);
   return 1;
}

void do_shot(int counter){
   command("shoot ranger's north 20");

   if (counter == 20) {
      command("grin");
      command("say There's your mark. "+count+" hits "+counter+" shots, see "
"if ya can beat that.");
      command("unwield bow");
      count = 0;
      new ("/d/common/obj/lrweapon/larrows")->move(TO);
      return 1;
   }
   counter++;
   call_out("do_shot",4,counter);
}


void receive_message(string cl, string msg){
   ::receive_message(cl, msg);

   if (strlen(msg) > 14 ) {
      if (msg[0..9] == "You hit Ma") {
         count++;
      }
   }
}
