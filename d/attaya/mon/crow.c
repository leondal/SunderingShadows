
#include <std.h>
inherit MONSTER;

create (){
    ::create ();
    set_name("crow");
    set_id( ({"crow"}) );
    set_short("phantasmic crow");
    set_long(
      "It is a large black crow that is partially transparent.  In patches, skin and feather are torn back to reveal bones and eyeless sockets.\n It is horrible."
    );
    set_gender("male");
    set("race", "undead crow");
    set_body_type("fowl");
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
    set_hp(50);
    set_exp(500);
    set_emotes(20,({
	"The phantasmic crow ruffles it's feathers.",

	"The phantasmic crow watches you.",
	"%^CYAN%^The phantasmic crow caws loudly and menacingly.",
      }),0);
    set_funcs( ({"peck"}) );
    set_func_chance(65);
    set_wielding_limbs( ({"left hand","right hand"}) );
    add_money("gold", 20 + random(140));
}


void peck(object targ)
{
    if(!targ) return 0;
    if(random(25) > targ->query_stats("dexterity")){
	tell_room(environment(targ), "%^RED%^The hideous crow pecks at "+targ->query_cap_name()+" and inflicts considerable pain!",targ);
	tell_object(targ, "%^BOLD%^%^RED%^The hideous crow pecks at you, inflicting considerable pain!");
	targ->do_damage("head", random(30)+25);
	return 1;

    } else {

	tell_object(targ, "%^BOLD%^%^RED%^The hideous crow divebombs you and you quickly put up a block!");
	tell_room(environment(targ), "%^RED%^The hideous crow divebombs "+targ->query_cap_name()+".");

    }
}
