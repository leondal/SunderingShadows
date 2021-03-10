#include <std.h>
#include "../bpeak.h"

inherit MONSTER;



void create (){

::create ();
   set_name("Ogre Warrior");
   set_id(({"ogre","Ogre","ogre warrior","ogre1"}));
   set_short("A large ogre");
   set_long("%^RESET%^Long %^BOLD%^%^BLACK%^greasy black hair %^RESET%^falls over"
" this creatures huanched shoulders.  He wears many stinking %^ORANGE%^skins,"
" %^RESET%^hiding most of his skin from view.  What is visible though is covered by"
" large warts that give off their own rancid smell that makes it nearly impossible"
" to be around him. He stands nearly nine feet tall and his large muscles further"
" confirm that he would be no easy target.  His face is always crumpled into a"
" frown, and his large teeth curve up over his upper lip, nearly touching his"
" snout-like nose.");
   set_race("ogre");
   set_gender("male");
   set_body_type("human");
   set_overall_ac(-8);
   set_hd(15,2);
   set_size(3);
   set_stats("intelligence",6);
   set_stats("strength",18);
   set_stats("wisdom",10);
   set_stats("dexterity",13);
   set_stats("constitution",18);
   set_stats("charisma",4);
   set_money("gold",random(200));
   set_hp(random(50)+200);
   set_max_hp(query_hp()); 
   set_max_level(25); 
   set_exp(4000);
   set_alignment(9);
   add_search_path("/cmds/fighter");
   set_moving(1);
   set_speed(12);
   set_nogo(({INRMS+"stwy3"})); 
   set_func_chance(15);
   set_funcs(({"rush"}));
   set("aggressive",19);
   set_property("full attacks",1);
   set_achats(5, ({"%^BOLD%^%^BLACK%^The ogre swings his club wildly over his head before attacking you again!%^RESET%^",
"%^BOLD%^%^BLACK%^The ogre lunges for you!%^RESET%^"}) );
      new(OBJD+"avenger")->move(TO);
      command("wield sword");
}
void rush(object target) {
   force_me("rush "+target->query_name()+"");
   return 1;
}
