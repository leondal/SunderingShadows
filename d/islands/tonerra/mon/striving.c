//greed.c

#include <std.h>

#include "/d/islands/tonerra/areadefs.h"

inherit WEAPONLESS;

void create(){
   ::create();

   set_name("he who strives");
   set_id(({"strive","striver","he","he who strives"}));
   set_short("he who strives");
   set_long(
@OLI
   This being always strives. The world is imperfect, and he will
go to all lengths to form it into his own image of perfection. The
way of the world is not his.

OLI
   );
   set_hd(35,8);
   set_hp(540);

   set_attacks_num(4);
   set_damage(2,5);
   set_stats("strength",18);
   set_mob_magic_resistance("average");
   set_property("weapon resistance",2);

   set_base_damage_type("bludgeoning");

   set_overall_ac(-14);
   set_attack_limbs(({"grasping right hand","grasping left hand"}));
   set_hit_funcs((["grasping right hand":(:TO,"pound":),"grasping left hand":(:TO,"pound":)]));
   set_exp(35000);
   set_body_type("human");
   set_gender("male");
   set_race("etherial emotion");
   set("aggressive",24);
   set_new_exp(25,"boss");
}

int pound(object rag){
   if(!objectp(rag)) return random(4);

   if(random(7)) return 0;

   if(rag->query_paralyzed()) return 5;
   tell_object(rag,"%^GREEN%^The striving one grabs hold of you and starts to bend you and shape you as he sees fit.\n");
   tell_room(ETO,"%^GREEN%^The striving one grabs "+rag->query_cap_name()+" and starts to mold and shape "+rag->query_objective()+" in his image.",rag);


   rag->set_paralyzed(16+ random(24),"You are being recovering from the manhandling you just got.");
   return random(5);
}

void die(object ob){

   object ob2;
   tell_room(ETO,"%^RED%^As the death blow is dealt the etherial emotion gels into a single shiny stone.");

   ob = new("/std/Object");
   ob->set_name("Gelled greed");
   ob->set_short("%^CYAN%^Gelled Greed");
   ob->set_long("This small crystal is a translucent stone evidentally the etherial emotion of greed catpured.");
   ob->set_id(({"gel","greed","gelled greed"}));
   ob->move(ETO);
   remove();
}
