#include <std.h>
#include "../meadow.h"
inherit WEAPONLESS;

void create()
{
   object ob;
   ::create();
   set_name("weasel");
   set_short("A sly weasel");
   set_id(({"monster","weasel","sly weasel"}));
   set_long(
   "The weasel is a rather tiny but sleek animal. It has a nice brown coat"+
   " and its tail is tipped with black fur. Its nose twitches and it has"+
   " tiny whiskers. You notice that its teeth appear sharp, as well as its"+
   " claws, but it probably couldn't do that much damage. It is very fast,"+
   " darting from one spot to the next."
   );
   set_race("weasel");
   set_body_type("quadruped");
   set_size(1);
   set_gender("neuter");
   set_alignment(5);
   set_property("swarm",1);
   set("aggressive",15);
   set_hd(8,4);
   set_hp(random(15)+50);
   set_overall_ac(6);
   //set_class("fighter");
   //set_mlevel("fighter",8);
   add_limb("right claw","right forepaw",0,0,0);
   add_limb("left claw","left forepaw",0,0,0);
   set_damage(1,2);
   set_attacks_num(3);
   set_base_damage_type("slashing");
   set_attack_limbs(({"right claw","left claw","mouth"}));
   set_hit_funcs((["mouth" : "The weasel bites you with its sharp teeth."]));
   set_new_exp(4,"normal");
   set_emotes(6,({
   "The weasel chitters loudly at you.",
   "The weasel runs about skittishly.",
   "The weasel stares curiously at you.",
   "The weasel darts under a bush.",
   }),0);
   set_max_level(12);
    if(!random(15)) {
      ob = new("/d/common/obj/brewing/herb_special_inherit");
      ob->set_herb_name("fur");
      ob->move(TO);
    }
}

/*
void reset()
{
   ::reset();
   if(!random(5)) {
      new(OBJ+"wpelt")->move(TO);
   }
}
changed by Circe 6/4/07 to match the others so it won't spawn multiple pelts
*/
void die(object obj)
{
   if(!random(5)) new(OBJ+"wpelt")->move(TO);
   ::die(obj);
}

