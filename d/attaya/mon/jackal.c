
#include <std.h>
inherit MONSTER;

create (){
    ::create ();
    set_name("jackal");
    set_id( ({"jackal"}) );
    set_short("phantasmic jackal");
    set_long(
      "The phantasmic jackal has powerful jaws and sharp teeth.  It is a violent foe."
    );
    set_gender("male");
    set("race", "undead jackal");
    set_body_type("dog");
    set_property("swarm",1);
    set_hd(20,0);
    set_overall_ac(-4);
    set_size(1);
    set_stats("strength", 17);
    set_stats("intelligence", 25);
    set_stats("dexterity", 19);
    set_stats("charisma", 6);
    set_stats("wisdom", 25);
    set_class("fighter");
    set("aggressive",22);
    set_alignment(4);
    set_hp(70);
    set_exp(500);
    set_emotes(20,({
	"The phantasmic jackal growls at you.",

	"The phantasmic jackal paces about.",
	"%^CYAN%^The phantasmic jackal howls loudly.",
      }),0);
    set_funcs( ({"peck"}) );
    set_func_chance(30);
    set_wielding_limbs( ({"left hand","right hand"}) );
    add_money("gold", 20 + random(140));
}


void peck(object targ)
{
    if(!targ) return 0;
    if(random(35) > targ->query_stats("dexterity")){
	tell_room(environment(targ), "%^RED%^The jackal lunges at "+targ->query_cap_name()+" and inflicts considerable pain!",targ);
	tell_object(targ, "%^BOLD%^%^RED%^The jackal lunges at you, tearing your flesh with it's sharp teeth!");
	targ->do_damage("head", random(30)+25);
	return 1;

    } else {

	tell_object(targ, "%^BOLD%^%^RED%^The jackal lunges at you and you quickly put up a block!");
	tell_room(environment(targ), "%^RED%^The jackal lunges at "+targ->query_cap_name()+".");

    }
}
