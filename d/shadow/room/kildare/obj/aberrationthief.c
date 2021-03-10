//aberration_thief.c - new monster for Kildare Glen
//expanding to include the sister everyone seems so interested in ;)
//~Circe~ 6/3/07

#include <std.h>
#include "/d/common/common.h"
#include "../kildare.h"

inherit MONSTER;

void make_me();
int dlvl;
object ob;

void create() {
   ::create();
   make_me();
   set_name("peryton aberration");
   set_race("peryton aberration");
   set_body_type("human");
   set_gender("female");
   dlvl = 8+random(4);
   set_alignment(9);
   set_overall_ac(0);
   set_hd(dlvl,6);
   set_level(dlvl);
   set_class("thief");
   set_mlevel("thief",dlvl);
   set_guild_level("thief",dlvl);
   set_hp(random(75)+125);
   set_max_hp(query_hp());
   set_scrambling(1); 
   set_overall_ac(0);
   ob = new(OBJ"pronged_claws");
   ob->move(TO);
   if(random(5)){
      ob->set_property("monsterweapon",1);
   }
   force_me("wield claws in right hand");
   RANDGEAR->arm_me(TO,"edgeds",50,1,65);
   if(!random(5)){
      ob = new(OBJ"leather_harness");
      ob->move(TO);
      if(!random(4)) ob->set_property("monsterweapon",1);
      force_me("wear harness");
   }else{
      ob = new(OBJ"rags");
      ob->move(TO);
      if(random(4)) ob->set_property("monsterweaon",1);
      force_me("wear rags");
   }
   set_property("swarm",1);
   set("aggressive",18);
   set_stats("strength",18);
   set_max_level(15);  
   set_exp(300*dlvl);   
   add_money("gold",random(150)+25);
   set_mob_magic_resistance("average");
}

void make_me(){
   switch(random(2)){
      case 0:  set_short("A twisted bird-woman");
               set_id(({"monster","peryton","aberration","peryton aberration","woman","bird woman","bird-woman"}));
               set_long("This twisted creation is a strange mixture of "+
                  "%^BOLD%^woman%^RESET%^%^CYAN%^, %^YELLOW%^bird%^RESET%^%^CYAN%^, "+
                  "and %^ORANGE%^stag%^CYAN%^.  She has the lower legs of "+
                  "a %^ORANGE%^stag%^CYAN%^, complete with vicious-looking "+
                  "%^BOLD%^%^BLACK%^black hooves%^RESET%^%^CYAN%^.  Her "+
                  "torso is that of a %^BOLD%^woman%^RESET%^%^CYAN%^, though "+
                  "it is covered with %^GREEN%^m%^CYAN%^o%^GREEN%^t%^CYAN%^t"+
                  "%^GREEN%^l%^CYAN%^e%^GREEN%^d feathers %^CYAN%^that "+
                  "give her a sickly, unkempt appearance.  Her face is "+
                  "dominated by a large %^YELLOW%^beak %^RESET%^%^CYAN%^"+
                  "and topped by %^ORANGE%^antlers %^CYAN%^peeking out "+
                  "from a strange mass of %^BOLD%^%^BLACK%^black curls "+
                  "%^RESET%^%^CYAN%^and %^GREEN%^green feathers%^CYAN%^.");
               add_limb("horns","head",0,0,0);
               add_limb("beak","head",0,0,0);
               break;
      default:  set_short("A twisted stag-woman");
               set_id(({"monster","peryton","aberration","peryton aberration","woman","stag woman","stag-woman"}));
               set_long("More stag than woman, this wretched creature "+
                  "has back legs like a %^ORANGE%^stag %^CYAN%^and "+
                  "front arms like a %^BOLD%^human woman%^RESET%^"+
                  "%^CYAN%^, but she walks on all fours.  Her "+
                  "face is a horrid mess of %^GREEN%^m%^CYAN%^o%^GREEN%^t%^CYAN%^t"+
                  "%^GREEN%^l%^CYAN%^e%^GREEN%^d feathers %^CYAN%^"+
                  "on a %^ORANGE%^stag's muzzle%^CYAN%^, and it is "+
                  "impossible to tell if she has any sort of "+
                  "expression - or thought - at all.  Useless "+
                  "%^RESET%^wings %^CYAN%^sprout from her back, "+
                  "serving to add to the confusion of what, "+
                  "exactly, she is.");
               add_limb("horns","head",0,0,0);
               add_limb("right wing","torso",0,0,0);
               add_limb("left wing","torso",0,0,0);
               break;
   }
}