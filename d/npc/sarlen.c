//Psychic for Newbietown, Styx & Garrett 8/25/01
//added a nogo for him.  He was wandering into the trainer's and 
//attacking newbies who were just training :P  Circe 12/8/03

#include <std.h>

inherit "/std/psychic.c";

void create(){
   ::create();
   set_name("Sarlen Drenmas");
   set_short("Sarlen Drenmas, wandering mentalist of Offestry");
   set_id(({"Sarlen drenmas","sarlen drenmas", "sarlen","Sarlen", "mentalist", "psychic"}));
   set_long(
@STYX
Sarlen is a rather serious, almost grim-looking, fellow with wizened features and a furrowed brow, perhaps from concentrating so much in using his psychic ability.  He dresses rather plainly and keeps his %^BOLD%^%^BLACK%^sable hair and beard %^RESET%^%^CYAN%^cropped short and neat which makes him look even more gaunt.  He provides his services for a fee but seems to enjoy helping the struggling young adventurers as they learn their way around.
STYX
);
   set_race("human");
   set_gender("male");
   set_hd(5,1);
   set_exp(1);
   set_stats("intelligence",25);
   set_body_type("human");
   set_overall_ac(9);
//overriding the pricing in the augmentPrice function for newbies
   set_price( 100 );
   set_speed(150);
   set_nogo(({"/d/newbie/rooms/town/trainer"}));  //added by Circe to stop the murder of helpless newbies.

//   "daemon/place_d"->place_in("/d/newbie/rooms/town/",TO);
}

int augmentPrice(object player){
   int cha;
   cha = player->query_stats("charisma");
   if(newbiep(player)) price = 30;
   if(!newbiep(player))price = 100;
   switch (cha) {
   case 0..3:
      return price*2;
   case 4..6:
      return (price*17)/10;
   case 7..10:
      return (price*15)/10;
   case 11..13:
      return (price*12)/10;
   case 14..16:
      return price;
   case 17..19:
      return (price*4)/5;
   case 20..25:
      return price/2;
   }
}

int kill_ob(object who, int i){
   ::kill_ob(who,i);

   force_me( "glare "+TPQCN);
   force_me("emote scowls at "+TPQCN+" and concentrates.");
   TP->force_me("emote staggers back and struggles suddenly as "+TP->query_possessive()+" clothing constricts.");
   TP->force_me("emote grabs "+TP->query_possessive()+" head and screams.");
   TP->do_damage("head",random(50));
   TP->force_me("fall");
   TP->set_paralyzed(10,"You scream and grab your head as it pounds painfully.");
   TP->set_bound(30,"Your clothes have tightened, binding you fast.");
   remove_attacker(TP);
}
