#include <std.h>
#include "../bpeak.h"
inherit MONSTER;


object obj,ob;
void create (){

::create ();
   set_name("Orc captain");
   set_id(({"orc","orc captain"}));
   set_short("%^RESET%^%^ORANGE%^A large orc%^RESET%^");
   set_long("%^RESET%^%^GREEN%^This ugly creature has %^BOLD%^%^BLACK%^scraggly"
" black hair %^RESET%^%^GREEN%^that falls over his primitive face.  He has a"
" low forehead, pig-like nose and prominent lower %^RESET%^teeth %^GREEN%^that curve"
" up over his upper lip.  His posture is huanched and his skin is an ugly"
" %^BOLD%^%^BLACK%^grey %^RESET%^%^GREEN%^in color.  Two weapon sheaths are"
" strapped to his sides and large boots adorn his feet.  Crude armor is worn for"
" protection.%^RESET%^");
   set_race("orc");
   set_gender("male");
   set_body_type("humanoid");
   set_hd(20,2);
   set_overall_ac(-7);
   set_size(2);
   set_stats("intelligence",8);
   set_stats("strength",17);
   set_stats("wisdom",7);
   set_stats("dexterity",11);
   set_stats("constitution",12);
   set_stats("charisma",6);
   set_exp(3000);
   set_alignment(9);
   set_hp(random(250)+200);
   set_max_hp(query_hp()); 
   add_search_path("/cmds/fighter"); 
   set_max_level(45);
   set_property("full attacks",1);
   set_func_chance(20);
   set_funcs(({"parry"}));
   command("pose standing on guard");
   set("aggressive","aggfunc");
   set("aggressive",19);
   set_moving(1);
   set_speed(12); 
   set_nogo(({INRMS+"ce1",INRMS+"bledge","/d/barriermnts/bforest/rooms/fpath1"}));
   ob=new("/d/common/obj/weapon/khopesh.c");
   ob->set_property("enchantment",random(3)+1);
   ob->set_long("%^BOLD%^%^WHITE%^The blade of this sword curves into an elegant arch that extends out from a"
" battered, silver hilt.  Soft, supple %^RESET%^%^ORANGE%^leather %^BOLD%^%^WHITE%^loosely wraps the"
" %^RESET%^%^ORANGE%^grip, %^BOLD%^%^WHITE%^from which a %^RED%^j%^YELLOW%^e%^CYAN%^w%^GREEN%^"
"e%^BLUE%^l %^WHITE%^encrusted pommel"
" extends.  Small depictions of moons, stars and suns have been crudely etched along the length of the blade,"
" making this blade look as though perhaps it either has been altered, or was a poor attempt at replicating a"
" nicer sword.%^RESET%^");
   ob->move(TO);
   command("wield sword");
   //obj=new("/d/common/obj/potion/healing");
   //obj->move(TO);
   //obj->set_uses(20);
   set_property("add kits",15);
     set_emotes(1, ({"%^RESET%^ The orc captain glances around nervously.",
"%^RESET%^%^ORANGE%^The orc captain absently rests his hand on the hilt of his sword.%^RESET%^"}), 0);
}
int aggfunc() {
   force_me("emoteat %^BOLD%^%^RED%^"+TPQN+ " turns to $N and draws his sword.%^RESET%^");
   call_out("force_me",1,"rush "+TPQN+ "");
}
void parry(object target) {
   force_me("parry");
   return 1;
}          
void heart_beat(){
   ::heart_beat();
   if (!objectp(TO)) return;
   if (!objectp(ETO)) return;
   /*if(query_hp()<150  && present("vial",TO)){
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
