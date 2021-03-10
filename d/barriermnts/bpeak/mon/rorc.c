#include <std.h>
#include "../bpeak.h"
inherit MONSTER;


object obj;
void create (){

::create ();
   set_name("Orc");
   set_id(({"orc"}));
   set_short("%^RESET%^%^ORANGE%^A stinking orc%^RESET%^");
   set_long("%^RESET%^%^GREEN%^This ugly creature has %^BOLD%^%^BLACK%^scraggly"
" black hair %^RESET%^%^GREEN%^that falls over his primitive face.  He has a"
" low forehead, pig-like nose and prominent lower %^RESET%^teeth %^GREEN%^that curve"
" up over his upper lip.  His posture is huanched and his skin is an ugly"
" %^BOLD%^%^BLACK%^grey %^RESET%^%^GREEN%^in color.  By the way he is dressed,"
" he does not appear to be high in rankings.  Most of his belongings are made out"
" of extremely crude hides, and the boots he wears are torn and badly in need of"
" repair.%^RESET%^");
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
   set_exp(2000);
   set_alignment(9);
   set_hp(random(250)+200);
   set_max_hp(query_hp()); 
   add_search_path("/cmds/fighter"); 
   set_max_level(45);
   set_property("full attacks",1);
   set_func_chance(50);
   set_funcs(({"parry"}));
   set("aggressive",19);
   set_moving(1);
   set_speed(12); 
   set_nogo(({INRMS+"ce1",INRMS+"bledge","/d/barriermnts/bforest/rooms/fpath1"}));
   obj=new("/d/common/obj/weapon/battle_axe.c");
   obj->move(TO);
   obj->set_property("enchantment",3);
   obj->set_property("monsterweapon",1);  
   command("wield axe");
   if(random(3) < 1){
     new("/d/barriermnts/bforest/obj/hspear.c")->move(TO);
     command("unwield axe");
     command("wield spear");
   }
   if(random(10) < 1){
     new("/d/barriermnts/bpeak/obj/wcloakm.c")->move(TO);
     command("wear cloak");
   }
}
void parry(object target) {
   force_me("parry");
   return 1;
}          

