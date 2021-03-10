#include <std.h>
#include "../bpeak.h"
#include <daemons.h>
inherit MONSTER;

object obj;
    


void create (){

::create ();
   set_name("Hill giant guard");
   set_id(({"giant","guard","Guard","hill giant","Hill Giant","Hill giant"}));
   set_short("%^RESET%^%^ORANGE%^A very large hill giant%^RESET%^");
   set_long("%^RESET%^%^ORANGE%^This giant stands nearly ten and a half feet tall,"
" even with his massive shoulders haunched.  He has dark brown hair that is"
" shaggily cut and matches his ruddy skin tone.  His overly bushy eyebrows set low"
" on his large forehead, shadowing his dark brown eyes.  His face looks as though"
" it is pulled into a constant frown and his jowels hang low.  His hairy arms look"
" almost uproportionally long and end in very large hands that are dirty from"
" constantly handling dirt and rocks.%^RESET%^");
   set_race("giant");
   set_gender("male");
   set_body_type("humanoid");
   set_hd(21,2);
   set_overall_ac(-5);
   set_size(3);
   set_stats("intelligence",6);
   set_stats("strength",19);
   set_stats("wisdom",10);
   set_stats("dexterity",18);
   set_stats("constitution",18);
   set_stats("charisma",7);
   set_exp(5000);
   set_alignment(9);
   set_hp(random(250)+150);
   set_max_hp(query_hp()); 
   add_search_path("/cmds/fighter"); 
   set_max_level(35);
   set_property("full attacks",1);
   set_money("gold",random(500));
   set_money("silver",random(200));
   set_money("copper",random(50));
   set_money("electrum",random(200));
   obj=new(OBJD+"gclub");
   obj->move(TO);
   obj->set_property("monsterweapon",1);
   command("wield club");
   //obj=new("/d/common/obj/potion/healing");
   //obj->move(TO);
   //obj->set_uses(30);
   set_property("add kits",15);
   set("aggressive",19);
}      
void heart_beat(){
   ::heart_beat();
   if(sizeof(all_living(find_object_or_load(INRMS+"bcliff6"))) > 0){
      switch(random(5)){
         case 0:  
            tell_room(ETO,"%^BOLD%^%^BLACK%^The hill giant looks over the edge of the cliff and begins hurling rocks over the edge!%^RESET%^");
            find_object_or_load(INRMS+"bcliff6")->ouch();
         break;
         case 1..4:
         break;
      }
   }
   if (!objectp(TO)) return;
   if (!objectp(ETO)) return;
   /*if(query_hp()<100  && present("vial",TO)){
   command("open vial");
   command("drink vial");
   command("drink vial");
   command("drink vial");
   command("drink vial");
   command("drink vial");
   command("offer bottle");
   command("offer bottle");
   command("offer bottle");
   command("offer bottle");
   command("offer bottle");
   }*/
}
