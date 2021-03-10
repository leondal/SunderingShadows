#include <std.h>
#include "../bpeak.h"
inherit WEAPONLESS;
string emoteMessage;
void create (){

::create ();
   set_name("Dire Wolf");
   set_id(({"Dire Wolf","dire wolf","wolf"}));
   set_short("%^BOLD%^%^BLACK%^A shaggy wolf%^RESET%^");
   set_long("%^BOLD%^%^BLACK%^This large and shaggy wolf seems to be ill treated."
"  His fur is a dull black in color with lighter %^RESET%^grey"
" %^BOLD%^%^BLACK%^markings on his back.  There are several scar marks across his"
" body as though he has been beaten many times.  His shoulders seem to always stay"
" haunched and his head is lowered.  His eyes glow a dull %^YELLOW%^yellow"
" %^BLACK%^and %^RESET%^drool %^BOLD%^%^BLACK%^constantly drips from his"
" mouth.%^RESET%^");
   set_race("wolf");
   set_gender("male");
   set_body_type("quadruped");
   set_hd(14,2);
   set_overall_ac(-5);
   set_size(2);
   set_stats("intelligence",2);
   set_stats("strength",18);
   set_stats("wisdom",12);
   set_stats("dexterity",15);
   set_stats("constitution",18);
   set_stats("charisma",6);
   set_class("fighter");
   set_exp(2000);
   set_alignment(3);
   set_damage(1,6);
   set_hp(random(100)+100);
   set_max_level(35);
   set_max_hp(query_hp());  
   set_property("full attacks",1);
   set("aggressive",25);
   add_limb("left claws","left forepaw",0,0,0);
   add_limb("right claws","right forepaw",0,0,0);
   add_limb("teeth","mouth",0,0,0);
   set_attack_limbs(({"right claws","teeth","left claws"}));
   set_base_damage_type("slashing");
   set_achats(2, ({"%^BOLD%^%^BLACK%^The wolf glares at you as he lunges at you again.%^RESET%^",
"%^BOLD%^%^BLACK%^The wolf snarls visciously as he bares his %^RESET%^teeth %^BOLD%^%^BLACK%^at you!%^RESET%^",
"%^BOLD%^%^BLACK%^The wolf paces around you before lunging at you again.%^RESET%^"}) );
     set_emotes(1, ({"%^BOLD%^%^BLACK%^The wolf raises its nose to the air and sniffs.",
"%^RESET%^The %^BOLD%^%^BLACK%^wolf %^RESET%^lays on the ground and begins licking its many %^RED%^wounds.%^RESET%^"}), 0);

}
void receive_message(string msg_type,string msg){
   ::receive_message(msg_type,msg);
   if(msg_type == "emote"){
      if(present("giant",ETO)) {
         if(strsrch(msg,"beats the wolf severely with his club.") != -1) {
            emoteMessage="emote 's hair stands on end as he snarls at the giant.";
        }
         if(strsrch(msg,"takes another bite of his food and then throws the wolf the bone.") != -1) {
            emoteMessage="emote takes the %^BOLD%^%^WHITE%^bone %^RESET%^to a corner and lays down, chewing on it.";
         return ;
        }
      return ;
      }
   return ;
   }
}      
void heart_beat(){
   ::heart_beat();
   if (!objectp(TO)) return;
   if (!objectp(ETO)) return;
   if(emoteMessage){
      force_me(emoteMessage);
      emoteMessage=0;
   return;
   }
   if(present("giant",ETO)) {
      if(sizeof(TO->query_attackers()) == 0) {
         switch(random(100)){
            case 0:
               force_me("emote whines at the giants feet.");
            break ;
            case 1:
               force_me("emote %^BOLD%^%^BLACK%^lays quietly at the giants feet.%^RESET%^");
            break ;
            case 2:
               force_me("emote %^RESET%^%^ORANGE%^begs the giant for some food%^RESET%^.");
            break ;
            case 4..99:
            break ;
         }
      }
      if(sizeof(TO->query_attackers()) > 0) {
         switch(random(100)){
            case 0:
               force_me("emote stays close to the giants side and snarls at you savagely, baring its teeth.");
            break ;
            case 1:
               force_me("emote %^BOLD%^%^BLACK%^defends the giant with its very life!%^RESET%^");
            break ;
            case 2..99:
            break ;
         }
      }
   }
}
