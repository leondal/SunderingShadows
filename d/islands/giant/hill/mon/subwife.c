#include "/realms/terrato/giant/giant.h"

inherit MONSTER;

void create() {
   ::create();
   set_name("Helen");
   set_id(({"wife","woman","slut","helen","giant","hill giant"}));
   set_short("%^ORANGE%^The Sub-Chief's Wife, Helen%^RESET%^");
   set_long(
@TERRATO
   %^ORANGE%^Helen is the wife and companion of Sub-Chief Browntooth
although she was forced by her family to marry him at a very young age
she has grown to love him very much and they live very happily together.
However, she is a bitter rival of Grethen, Glacor's Wife.  This has
been know to cause problems, but so far there has been no open fighting
between the two
TERRATO
   );
   set_race("giant");
   set_gender("female");
   set_body_type("human");
   set_hd(15,0);
   set_max_hp(120);
   set_hp(120);
   set_exp(9000);
   set_size(3);
   set_stats("strength",19);
   set_stats("intelligence",10);
   set_stats("wisdom",8);
   set_stats("dexterity",8);
   set_stats("constitution",18);
   set_stats("charisma",12);
   set_money("gold",320);
   set_class("fighter");
   set_guild_level("fighter",13);
   add_search_path("cmds/fighter");
   set_overall_ac(3);
   set_property("full attacks",1);
   set_alignment(3);
   set_emotes(20, ({
      "%^MAGENTA%^Helen says%^RESET%^: You will make a tasty treat for Browntooth's stew!",
   }),1);
   set("aggressive",25);
   new("/d/shadow/obj/weapon/two_hand_sword.c")->move(this_object());
   command("wield sword");
}


void heart_beat(){
   int i, j;
   object *att;
   ::heart_beat();

   if((att = (object *)(TO->query_attackers()))!= ({})){
      j = sizeof(att);
      for(i = 0;i <j;i++){
         call_out("force_me",2,"rush "+att[i]->query_name());
         }
      }
   }
