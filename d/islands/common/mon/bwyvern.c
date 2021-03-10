//updated by ~Circe~ 10/7/09 to current code
#include <std.h>
inherit WEAPONLESS;

void create(){
   ::create();
   set_name("black wyvern");
   set_id(({"black wyvern","wyvern","shadowy wyvern","shadowy black wyvern"}));
   set_short("Shadowy black wyvern");
   set_long("%^BOLD%^%^BLACK%^This wyvern is a large dragon-like creature "+
      "that has been specially bred by the Kinnesaruda as guardians.  "+
      "It is about fifteen feet long, half that length being made up "+
      "of its thin, sinuous tail.  With a twenty foot wingspan, this "+
      "creature can easily take flight, attacking with its menacing "+
      "claws and fangs.  "+
      "Lacking the intelligence of most dragons and bred with an "+
      "animalistic desire to hunt and kill, only the undead are safe "+
      "from these menaces.  The black wyvern is said to be the most "+
      "deadly of wyverns.%^RESET%^");
   set_gender("male");
   set_race("wyvern");
   set_body_type("dragon");
   set_property("swarm",1);
   set_hd(35,12);
   set_class("fighter");
   set_mlevel("fighter",35);
   set_overall_ac(-10);
   set_size(4);
   set_moving(1);
   set_speed(10);
   set_stats("strength",19);
   set_stats("intelligence",6);
   set_stats("dexterity",19);
   set_stats("charisma",6);
   set_stats("wisdom",5);
   set("aggressive",26);
   set_alignment(5);
   set_hp(300+random(200));
   set_exp(11500);
   set_funcs(({"fire"}));
   set_func_chance(50);
   set_attacks_num(2);
   set_damage(1,12);
   set_attack_limbs(({"left foreclaw","right foreclaw"}));
   add_money("gold",220+random(340));
}

void init(){
   if(!TP->query_true_invis()) {
      tell_room(ETO,"%^RED%^The wyvern senses your movement and attacks!%^RESET%^");
      if(TP->query_invis()) {
         TP->set_invis();
      }
      kill_ob(TP,1);
   }
}


void fire(object targ){
   if(!targ) return 0;
   if(random(25)> targ->query_stats("charisma")){
      tell_room(environment(targ),"%^BOLD%^%^BLACK%^The black wyvern shrieks, "+
         "and shadowy wisps stab into "+targ->QCN+" like daggers!%^RESET%^",targ);
      tell_object(targ,"%^BOLD%^%^BLACK%^The black wyvern shrieks, and "+
         "shadowy wisps stab into you like daggers!%^RESET%^");
      targ->do_damage("torso",random(30)+15);
      return 1;
   }else{
      tell_object(targ,"%^BOLD%^%^BLACK%^The black wyvern shrieks "+
         "violently at you, but nothing happens!%^RESET%^");
      tell_room(environment(targ),"%^BLUE%^The black wyvern shrieks violently "+
         "at "+targ->QCN+", but nothing happens!%^RESET%^",targ);
   }
}
