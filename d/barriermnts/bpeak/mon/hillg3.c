#include <std.h>
#include "../bpeak.h"
#include <daemons.h>
inherit MONSTER;

object obj;
    


void create (){

::create ();
   set_name("Hill giant guardian");
   set_id(({"giant","guard","Guard","hill giant","Hill Giant","Hill giant"}));
   set_short("%^RESET%^%^ORANGE%^A very large hill giant%^RESET%^");
   set_long("%^RESET%^%^ORANGE%^This giant stands nearly ten and a half feet tall,"
" even with his massive shoulders haunched.  He has dark brown hair that is"
" shaggily cut and matches his ruddy skin tone.  His overly bushy eyebrows set low"
" on his large forehead, shadowing his dark brown eyes.  His face looks as though"
" it is pulled into a constant frown and his jowels hang low.  His hairy arms look"
" almost uproportionally long compared to the rest of his body.%^RESET%^");
   set_race("giant");
   set_gender("male");
   set_body_type("humanoid");
   set_overall_ac(-5);
   set_hd(15,2);
   set_size(3);
   set_stats("intelligence",6);
   set_stats("strength",19);
   set_stats("wisdom",10);
   set_stats("dexterity",18);
   set_stats("constitution",18);
   set_stats("charisma",7);
   set_exp(4500);
   set_alignment(9);
   set_hp(random(250)+150);
   set_max_hp(query_hp()); 
   set_max_level(35);
   add_search_path("/cmds/fighter");
   set_funcs(({"rush","parry","flash"}));
   set_func_chance(30);
   set_property("full attacks",1);
   set_money("gold",random(200));
   set_money("silver",random(100));
   set_money("copper",random(50));
   set_money("electrum",random(1000));
   obj=new(OBJD+"gclub");
   obj->move(TO);
   obj->set_property("monsterweapon",1);
   command("wield club");
   //obj=new("/d/common/obj/potion/healing");
   //obj->move(TO);
   //obj->set_uses(15);
   set_property("add kits",10);
   set("aggressive",19);
} 
void rush(object target) {
   force_me("rush "+target->query_name()+"");
   return 1;
} 
void parry(object target) {
   force_me("parry");
   return 1;
}  
void flash(object target) {
   force_me("flash "+target->query_name()+"");
   return 1;
}                
void heart_beat(){
   ::heart_beat();
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
