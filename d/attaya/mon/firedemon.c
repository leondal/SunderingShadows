
#include <std.h>
inherit MONSTER;

create (){
    ::create ();
    set_name("firedemon");
    set_id(({"firedemon","demon"}));
    set_short("Firedemon");
    set_long(
      "The Firedemon is a powerful demonic warrior with an aura of flame about it.  It's bones are exposed in places and it's entire head lacks skin entirely except a stripe down the back of it's head where a mane of sepia hair starts. It has tiny blue eyes recessed within large sockets that seem to pierce you with their gaze."
    );
    set_gender("male");
    set("race", "demonic entity");
    set_property("magic",1);
    set_mob_magic_resistance("high");
    set_body_type("human");
    set_property("swarm",1);
    set_class("paladin");
    set_hd(20,0);
    set_overall_ac(-8);
    set_size(3);
    set_stats("strength", 17);
    set_stats("intelligence", 25);
    set_property("magic",1);
    set_stats("dexterity", 19);
    set_stats("charisma", 6);
    set_stats("wisdom", 25);
    set("aggressive", 19);
    set_alignment(4);
    set_hp(130);
    set_exp(3500);
    set_emotes(20,({
	"%^RED%^The firedemon's eyes glow brightly!",
	"%^RED%^The firedemon displays it's razor sharp teeth.",
	"%^RED%^The firedemon shrieks horribly!"
      }),0);
    set_funcs( ({"fireball"}) );
    set_func_chance(65);
    set_wielding_limbs( ({"left hand","right hand"}) );
    add_money("gold", 20 + random(140));
      set_resistance("fire",20);
      set_resistance("cold",-20);
}


void fireball(object targ)
{
    if(!targ) return 0;
    if(random(35) > targ->query_stats("intelligence")){
	tell_room(environment(targ), "%^RED%^Firedemon hurls a fireball at "+targ->query_cap_name()+" and a wave of heat rushes past you!",targ);
	tell_object(targ, "%^BOLD%^%^RED%^Firedemon hurls a fireball at your head!");
	targ->do_damage("head", random(2)+25);
	return 1;

    } else {

	tell_object(targ, "%^BOLD%^%^RED%^Firedemon hurls a fireball at your head, but it fades away as it approaches!");
	tell_room(environment(targ), "%^RED%^Firedemon hurls a fireball at "+targ->query_cap_name()+" but it fades away before it strikes them.",targ);

    }
}
