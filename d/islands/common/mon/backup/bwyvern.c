
#include <std.h>
inherit WEAPONLESS;

create (){
::create ();
set_name("wyvern");
set_id( ({"black wyvern", "wyvern"}) );
set_short("Shadowy black wyvern");
set_long("
    The wyvern is a large dragon-like creature that has been specially bred by the Kinnesaruda as guardians.  Lacking the intelligence of most dragons, and bred with an animalistic desire to hunt and kill, only the undead are safe from these menaces.
    The black wyvern is perhaps the most deadly of wyverns.
");
set_gender("male");
set("race", "wyvern");
set_body_type("dragon");
set_property("swarm",1);
set_hd(46,0);
set_overall_ac(-5);
set_size(4);
set_moving( 1 );
set_speed( 10 );
set_stats("strength", 19);
set_stats("intelligence", 6);
set_stats("dexterity", 19);
set_stats("charisma", 6);
set_stats("wisdom", 5);
set_class("fighter");
set("aggressive", 26);
set_alignment(4);
set_hp(300);
set_exp(8500);
set_funcs( ({"fire"}) );
set_func_chance(50);
  set_attacks_num(2);
  set_damage(1,12);
  set_attack_limbs(({"left foreclaw","right foreclaw"}));
add_money("gold", 20 + random(340));
}
void init(){
    if(!TP->query_true_invis()) {
        tell_room(ETO,"%^RED%^The wyvern senses your movement and attacks!");
        if(TP->query_invis()) {
            TP->set_invis();
        }
        kill_ob(TP,1);
    }
}


void fire(object targ)
{
  if(!targ) return 0;
  if(random(25) > targ->query_stats("charisma")){
   tell_room(environment(targ), "%^BOLD%^%^BLACK%^The black wyvern shrieks and shadowy wisps stab into "+targ->query_cap_name()+" like daggers!",targ);
  tell_object(targ, "%^BOLD%^%^BLACK%^The black wyvern shrieks and shadowy wisps stab into you like daggers!");
  targ->do_damage("torso", random(30)+15);
  return 1;

} else {

  tell_object(targ, "%^BOLD%^%^BLACK%^The black wyvern shrieks violently at you, but nothing happens!");
   tell_room(environment(targ), "%^BLUE%^The black wyvern shrieks violently at "+targ->query_cap_name()+" but nothing happens.",targ);

    }
}
