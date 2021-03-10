#include <std.h>
#include "../koenig.h"

inherit MONSTER;

void create (){
 object hat;
::create ();
   
   set_name("Ogre Mage");
   set_id(({"ogre","Ogre","ogremage","ogre mage"}));
   set_short("An ugly ogre-mage");
   set_long("%^RESET%^%^GREEN%^This creature's large frame is"
" covered in a putred green colored skin. His tiny beady eyes are"
" %^BOLD%^%^BLACK%^black %^RESET%^%^GREEN%^with"
" %^BOLD%^%^WHITE%^pure white pupils. %^RESET%^%^GREEN%^His"
" %^RESET%^ivory horns %^GREEN%^jut out of the top of his head,"
" and serve to contrast his %^BOLD%^%^BLACK%^jet-black teeth"
" %^RESET%^%^GREEN%^and %^BOLD%^%^BLACK%^claws. %^RESET%^"
"%^GREEN%^His muscles are huge and out of proportion, giving him"
" a bulky, deformed look. By the way he carries himself though,"
" it is clear that he is the leader here.%^RESET%^");
   set_race("ogre-mage");
   set_gender("male");
   set_body_type("human");
   set_overall_ac(2);
   set_hd(15,2);
   set_size(3);
   set_stats("intelligence",16);
   set_stats("strength",18);
   set_stats("wisdom",10);
   set_stats("dexterity",13);
   set_stats("constitution",18);
   set_stats("charisma",4);
   set_money("gold",random(90));
   set_class("mage");
   set_hp(random(50)+100);
   set_max_hp(query_hp());  
   set_exp(1500);
   set_alignment(9);
   set("aggressive",19);
   set_mlevel("mage",13);
   set_guild_level("mage",13);
   set_spell_chance(95);
   set_spells(({"cone of cold","fireball","hideous laughter"}));
   set_mob_magic_resistance("average");
   set_func_chance(50);
   set_funcs(({"bodyslam","swordsweep","headcrusher"}));
   set_achats(5, ({"%^BOLD%^%^BLACK%^The ogre-mage sneers disdainfully at you before moving
in for the kill!%^RESET%^",
   "%^RESET%^Drool drips from the ogre-mages teeth as he chuckles darkly.",
   "%^RESET%^The ogre-mage's eyes %^YELLOW%^glow %^RED%^red %^RESET%^as he ducks down low and thrusts his
weapon towards you again.",
}) );
   set_emotes(2,({
      "%^RESET%^%^BLUE%^The ogre mage rakes his claws along the armrest of his chair and
barks some sort of orders out.%^RESET%^",
      "%^BOLD%^%^BLACK%^The ogre mage dances along with his sword, making sweeping motions
at an invisible target.%^RESET%^",
      "%^RED%^The ogre mage seems to take delight in playing with a skull.%^RESET%^",
}),0);
   RANDGEAR->armor_me(TO,"armorlt",70,1,0);
   RANDGEAR->arm_me(TO,"edgedl",20,1,50);
   RANDGEAR->armor_me(TO, "armorcl", 70, 1, 0);
   hat = new("/d/common/obj/rand/rand_leath_head");
   hat->set_property("enchantment",1);
   hat->set_size(3);
   hat->move(TO);
   force_me("wearall");
}
void bodyslam(object target) {
   tell_room(ETO,"%^BOLD%^%^BLACK%^%^The ogre-mage lifts "+target->query_cap_name()
   +" off of "+target->query_possessive()+
   " feet, spins him around, and tosses "+target->query_objective()+
   " across the room!",target);
   tell_object(target, 
   "%^BOLD%^%^BLACK%^The ogre mage picks you up, spins"+
   " you around and then throws you effortlessly across"+
   " the room where you land with a dull thud!");
   return roll_dice(1,8)+1;
}
void swordsweep(object target) {
   if(!"daemon/saving_d"->saving_throw(target,"paralyzation_poison_death"))
{
   tell_room(ETO,"%^RESET%^%^RED%^The ogre-mage sweeps his sword under"
   +target->query_cap_name()+"s legs, knocking "+
   target->query_objective()+"off of "+target->query_possessive()+
   " feet!",target);
   tell_object(target, "%^RESET%^%^RED%^The ogre-mage spins"+
   " around and sweeps his sword under your"+
   " feet, knocking you to the ground!");
   target->set_paralyzed(15,"You are trying to get to your feet.");
   return roll_dice(1,6)+1;
   return 1;
   }
   tell_room(ETO,"%^RESET%^%^RED%^The ogre-mage sweeps his sword under"
   +target->query_cap_name()+"s feet, but "+target->query_subjecctive()+
   "backflips away just in time!",target);
   tell_object(target, "%^RESET%^%^RED%^You muster up all"+
   " of your inner strength and tuck your legs into a "+
   "backflip just as the ogre-mage tries to sweep his sword"+
   "under your feet!");
   return 1;
}
void headcrusher(object target) {
   if(!"daemon/saving_d"->saving_throw(target,"paralyzation_poison_death"))
{
   tell_room(ETO,"%^BOLD%^%^RED%^The ogre_mage cackles demonically as"+
   " he brings his sword down stoutly over "+
   target->query_cap_name()+"s head!",target);
   tell_object(target, "%^BOLD%^%^RED%^The ogre-mage cackles demonically"+
   " as he brings the hilt of his sword down squarely over your head,"+
   " making you see double!\n...Darn, that hurt.%^RESET%^");
   target->set_paralyzed(15,"You are still seeing double.");
   return roll_dice(2,8)+1;
   return 1;
   }
   tell_room(ETO,"%^BOLD%^%^RED%^The ogre-mage brings the hilt "+
   "of his sword down hard towards "+target->query_cap_name()+
   "s head, but "+target->query_subjective()+
   " manages to dive out of the way!",target);
   tell_object(target, "%^BOLD%^%^RED%^You dive out "+
   "of the way just as the ogre-mage slams "+
   "the hilt of his sword over the place where your head use to be!");
   return 1;
}
