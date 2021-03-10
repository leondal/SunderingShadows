#include <std.h>
#include "../bpeak.h"
#include <daemons.h>
inherit MONSTER;

object obj;
    


void create (){

::create ();
   set_name("Hill giant");
   set_id(({"giant","hill giant","Hill Giant","Hill giant"}));
   set_short("%^RESET%^%^ORANGE%^A female hill giant%^RESET%^");
   set_long("%^RESET%^%^ORANGE%^This female giant is simply large.  Her smashed"
" face gives her an almost primative look and her long scraggly brown hair is just"
" a couple shades darker than her skin.  She wears many stinking furs."
"  She is a little shorter than the males of the tribe, but"
" what she deesn't have in height, she makes up for in weight.  It is fairly"
" obvious that she does not go out on the raiding parties with the rest.%^RESET%^");
   set_race("giant");
   set_gender("female");
   set_body_type("humanoid");
   set_overall_ac(-6);
   set_hd(16,2);
   set_size(3);
   set_stats("intelligence",6);
   set_stats("strength",19);
   set_stats("wisdom",10);
   set_stats("dexterity",18);
   set_stats("constitution",18);
   set_stats("charisma",7);
   set_exp(4000);
   set_alignment(9);
   set_hp(random(250)+250);
   set_max_hp(query_hp()); 
   set_max_level(35);
   add_search_path("/cmds/fighter");
   set_funcs(({"rush","parry","flash"}));
   set_func_chance(20);
   set_property("full attacks",1);
   obj=new(OBJD+"basicc");
   obj->move(TO);
   obj->set_property("monsterweapon",1);
   command("wield club");
   //obj=new("/d/common/obj/potion/healing");
   //obj->move(TO);
   //obj->set_uses(15);
   set_property("add kits",10);
   set("aggressive",21);
   set_emotes(1, ({"%^RESET%^ The female giant throws some stuff into the corner of the room as she cleans off a table.",
"%^RESET%^%^ORANGE%^The female giant raises her club and smashes it against a wall angrily.%^RESET%^"}), 0);
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
   /*if(query_hp()<200  && present("vial",TO)){
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
