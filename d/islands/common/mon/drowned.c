
#include <std.h>
inherit MONSTER;

create (){
::create ();
set_name("drowned");
set_id( ({"drowned"}) );
set_short("Drowned");
set_long("
    The drowned is an undead sailor whose corpse was carried beneath the Island of Attaya.  The waters there have a strange property for resurecting the tragic dead.  Sad shadows of their former selves, Drowned usually just stand and stare off into the ocean.
");
set_gender("male");
set("race", "undead");
set_body_type("human");
set_property("swarm",1);
set_hd(33,0);
   set_property("full attacks",1);
set_overall_ac(-8);
set_size(2);
set_stats("strength", 19);
set_stats("intelligence", 6);
set_stats("dexterity", 19);
set_stats("charisma", 6);
set_stats("wisdom", 5);
set("aggressive", 25);
set_alignment(4);
set_hp(random(500)+90);
set_exp(8000);
set_emotes(10,({
    "The drowned stares out over the sea.",
    "The drowned mumbles something about what lies beyond the sea.",
    "The drowned mumbles something about an ironclad.",
    "The drowned mumbles something about berries in the wild.",
    "The drowned mumbles something about families all being dead and water filling their skulls.",
    "The drowned mumbles something about sandy plains filled with bones.",
    "The drowned mumbles something about the %^RED%^Intruder%^RESET%^.",
    "The drowned seems to sob.",
    "The drowned makes a strange noise almost like singing.",
    "The drowned mumbles something about ships going down that shouldn't come back up.",
    "The drowned mumbles something about ancient spirits residing beneath Attaya.",
    "The drowned mumbles something about sirens.",
    "The drowned mumbles something about mountains of dead.",
    "The drowned mumbles somethong about fields of pain being home for hundreds.",
    "The drowned's eyes open wide!",
    
    "The drowned tosses a pebble into the ocean.",
    "The drowned mumbles something about destiny.",
    "The drowned mumbles something about time having no meaning.",
     "%^MAGENTA%^Drowned says%^RESET%^: Beware Intruder, puppet of Autarkis the ancient evil...",
     "%^MAGENTA%^Drowned says%^RESET%^: I had a girl once...",
     "%^MAGENTA%^Drowned says%^RESET%^: Why am I still here?  Why can't I just die?"
}),0);
set_funcs( ({"torment"}) );
set_func_chance(40);
set_wielding_limbs( ({"left hand","right hand"}) );
add_money("gold", 20 + random(140));
   set_resistance("negative energy",10);
   set_resistance("positive energy",-10);
}


void die(object ob) 
{
    string area;
    if(objectp(ETO))
    {
        area = base_name(ETO);
        if(strsrch(area, "eldebaro") != -1)
        {
            "/d/islands/common/eldebaro/kill_tracker_d.c"->register_death(all_living(ETO));
        }
    }    
    ::die(ob);
}



void torment(object targ)
{
  if(!targ) return 0;
  if(random(20) > targ->query_stats("dexterity")){
  tell_room(environment(targ), "%^CYAN%^Drowned curses "+targ->query_cap_name()+" with an ancient chant!",targ);
   tell_object(targ, "%^BOLD%^%^BLUE%^Drowned pulls you close and mutters an ancient chant into your ear!\n""%^RED%^Your heart sputters and a blood clot makes its way down your arm and into your wrist!");
  targ->do_damage("torso", random(10)+15);
  return 1;

} else {

  tell_object(targ, "%^BOLD%^Drowned begins to glow as a million tiny particles of light fill its body. ");
 targ->do_damage("torso", random(2)+8);
    tell_object(targ, "%^BOLD%^A pulse of energy flies from Drowned into your eyes! ");
 targ->do_damage("torso", random(2)+8);
    tell_object(targ, "%^BOLD%^A pulse of energy flies from Drowned into your eyes! ");
 targ->do_damage("torso", random(2)+8);
    tell_object(targ, "%^BOLD%^A pulse of energy flies from Drowned into your eyes! ");
 targ->do_damage("torso", random(2)+8);
   tell_object(targ, "%^BOLD%^A pulse of energy flies from Drowned into your eyes! ");
 targ->do_damage("torso", random(2)+8);
    tell_object(targ, "%^BOLD%^A pulse of energy flies from Drowned into your eyes! ");
      tell_room(environment(targ), "%^BOLD%^%^RED%^Drowned blasts "+targ->query_cap_name()+" with a powerful series of energy bolts.",targ);

    }
}
