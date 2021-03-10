#include <std.h>

inherit TOWNSMAN;

//Simic Ullaphyl

int current_price;
int current_haggler;
int flag = 0;

void create(){
   ::create();

   set_name("Simic Ullaphyl");
   set_short("Simic Ullaphyl, hemp maker extraordinaire");
   set_id(({"simic","Simic","Simic Ullaphyl","Ullaphyl","ullaphyl", "rope maker","hemp maker"}));
   set_long(
@OLI
   This grizzled of man has gnarled hands. His joints are obviously stiff 
from years of weaving fine rope. His outfit consists of a once dark tunic, 
now faded thoroughly, breeches to his calves and high walking boots that 
have almost worn through on the right foot. He carries his goods with him. 
His reputation for quality rope extends far to the north in Daggerdale, and 
south beyond the Tharisian mountains. He is quite willing to haggle with you 
for his product.
OLI
   );
   set_race("human");
   set_gender("male");
   set_body_type("human");
   set_hd(84,8);
   set_max_hp(10);
   set_hp(10);
   set_exp(1);
   set_property("alignment adjustment",-10);
   set_alignment(4);
   set_speed(50);
   set_stats("strength",15);
   new("/d/common/obj/misc/rope")->move(TO);
   new("/d/common/obj/misc/rope")->move(TO);
   new("/d/common/obj/misc/rope")->move(TO);
   flag = 1;
}

void catch_say(string message){
   if (strsrch(message,"rope") != -1 || strsrch(message,"silver") != -1) {
      call_out("do_talk",1,TP,message);
   }
}

void do_talk(object tp,string message){
     string before;
     int amount;
     object rope;
     set_spoken(tp->query_spoken());
     if (strsrch(message,"rope") != -1) {
        if (objectp(current_haggler) && present(current_haggler,ETO)) {
           if (current_haggler == tp) {
              force_me("say We are currently haggling for my rope, please make me an offer in silver.");
              return;
           }
           force_me("say I'm sorry, "+tp->query_cap_name()+", I'm busy with "+current_haggler->query_cap_name()+".");
           return;
        } else {
           if (!present("rope",TO)) {
              force_me("say I'm sorry I am currently out of rope.");
              return;
           }
           current_haggler = tp;
           current_price = random(35)+35;
           force_me("say Please make an offer for this outstanding rope I have in silver.");
        }


     } else if (strsrch(message,"silver")!= -1){

        if (!rope = present("rope",TO)) {
           force_me("say I'm sorry I am currently out of rope.");

           current_haggler = 0;
           current_price = 0;
           return;
        }

        if (objectp(current_haggler) && present(current_haggler,ETO)) {
           if (current_haggler != tp) {
            force_me("say I'm sorry, "+tp->query_cap_name()+", I'm busy with "+current_haggler->query_cap_name()+".");
              return;
           }
        } else {
           force_me("say Please ask me about rope, I seem to have become confused in my old age.");
           return;
        }
       if (sscanf(message,"%s%d silver",before,amount) != 2) {
          force_me("say I'm sorry, I didn't understand what you offered me in silver.");
          return 1;
       }
       if (amount >= current_price) {
          force_me("say That will do just fine. Now do you have the funds?");
          if (tp->query_funds("silver",amount)) {
             force_me("say Ahh, you do. Good.");
             tp->use_funds("silver",amount);
             force_me("drop rope");
             force_me("say I'll just leave this right here for you.");
          } else {

             force_me("say Scoundrel, offering what you cannot pay!, be gone.");
          }
          current_price = 0;
          current_haggler = 0;

       } else {
          force_me("laugh");
          force_me("say No that is simply not enough.");
       }
     }


}
/*  Was spamming the debug.log for some reason, something with geteuid in reset(), I moved it into heart_beat instead -Ares
void reset(){
   ::reset();
   if (flag && !present("rope 3")) {
      force_me("emote proudly runs his gnarled hands over a newly finished piece of strong rope.");
      new("/d/common/obj/misc/rope")->move(TO);
   }
}
*/
void heart_beat(){
   ::heart_beat();
   if (!objectp(TO)) {
      return;
   }
   if(!random(1000))
   {
        if (flag && !present("rope 3")) 
        {
            force_me("emote proudly runs his gnarled hands over a newly finished piece of strong rope.");
            new("/d/common/obj/misc/rope")->move(TO);
        }
   }
   if (!random(500)) {
      switch(random(5)){
      case 0:
         force_me("emote whistles to himself as he weaves long strands of hemp together.");
         break;
      case 1:
         force_me("emote laughs to himself as he remembers the old times.");
         force_me("emote mutters to himself, yes the days are gone, the seas are tamed and my life draws slowly to its end.");
         break;
      case 2:
         force_me("emote grins at you and shows you his rope.");
         force_me("say That thar be some good rope. Learned long ago to me by old ship master.");
         force_me("say Yessir that old coot was a good fellow, disappeared one day, but not before he learned me this.");
         force_me("say you ever heard of old Krink? No? Shame ...");
         force_me("emote gazes off.");
         break;
      case 3:
         force_me("emote prances about a little, until he leans over wheezing.");
         force_me("emote grins to you as he wheezes.");
         force_me("say Have to try every now and then.");
         break;
      case 4:
         force_me("emote pats you on the head.");
         force_me("say Yessir, where would this city be without my rope. The ships wouldn't sail. The trade wouldn't come. The flags wouldn't wave.");
         force_me("emote grins to himself.");
         force_me("say I'll be sad when I'm gone, for what will ya'll do without me...");
         break;
      }
   }
}





