
#include <std.h>
inherit MONSTER;

create (){
::create ();
set_name("wyvern");
set_id( ({"red wyvern", "wyvern"}) );
set_short("Deep red wyvern");
set_long("
    The wyvern is a large dragon-like creature that has been specially bred by the Kinnesaruda as guardians.  Lacking the intelligence of most dragons, and bred with an animalistic desire to hunt and kill, only the undead are safe from these menaces.
");
set_gender("male");
set("race", "wyvern");
set_body_type("dragon");
set_property("swarm",1);
  set_property("full attacks",1);
set_class("fighter");
set_guild_level("fighter",30);
set_mlevel("fighter",30);
set_hd(40,10);
set_overall_ac(-5);
set_size(4);
set_moving( 1 );
set_speed( 20 );
set_stats("strength", 19);
set_stats("intelligence", 6);
set_stats("dexterity", 19);
set_stats("charisma", 6);
set_stats("wisdom", 5);
set_class("fighter");
set("aggressive", 26);
set_alignment(4);
set_hp(300);
set_exp(7500);
set_funcs( ({"fire"}) );
set_func_chance(50);
set_wielding_limbs( ({"left hand","right hand"}) );
add_money("gold", 20 + random(340));
add_money("platinum", 50 + random(200));
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
  if(random(25) > targ->query_stats("intelligence")){
    tell_room(environment(targ), "%^BOLD%^%^RED%^The red wyvern draws back its head and lets loose a tremendous breath of fire that burns "+targ->query_cap_name()+"!",targ);
   tell_object(targ, "%^BOLD%^%^RED%^The red wyvern draws back its head and lets loose a tremendous breath of fire that burns you!");
  targ->do_damage("torso", random(15)+15);
  return 1;

} else {

   tell_object(targ, "%^BOLD%^%^RED%^The red wyvern draws back its head and lets loose a tremendous breath of fire, but you are able to dodge out of the way!");
   tell_room(environment(targ), "%^RED%^The red wyvern draws back its head and lets loose a tremendous breath of fire at "+targ->query_cap_name()+" but they dodge out of the way",targ);

    }
}
