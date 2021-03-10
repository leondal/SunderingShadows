
#include <std.h>
inherit MONSTER;

create (){
    ::create ();
    set_name("waterdemon");
    set_id(({"waterdemon","demon"}));
    set_short("Waterdemon");
    set_long(
      "The Waterdemon is a powerful demonic warrior with an aura of water about it.  It's bones are exposed in places and it's entire head lacks skin entirely except a stripe down the back of it's head where a mane of sepia hair starts.\n It has tiny blue eyes recessed within large sockets that seem to pierce you with their gaze."
    );
    set_gender("male");
    set_property("magic",1);
    set("race", "demonic entity");
    set_moving( 1 );
    set_speed( 5 );
    set_body_type("human");
    set_property("swarm",1);
    set_class("paladin");
    set_hd(20,0);
    set_overall_ac(-8);
    set_size(3);
    set_stats("strength", 25);
    set_stats("intelligence", 25);
    set_stats("dexterity", 19);
    set_stats("charisma", 6);
    set_stats("wisdom", 25);
    set("aggressive", 19);
    set_alignment(4);
    set_invis();
    add_search_path( "cmds/thief" );
    set_hp(230);
    set_exp(3500);
    set_emotes(20,({
	"%^RED%^The waterdemon's eyes glow brightly!",
	"%^RED%^The waterdemon displays it's razor sharp teeth.",
	"%^RED%^The waterdemon shrieks horribly!"
      }),0);
    set_funcs( ({"fireball"}) );
    set_func_chance(65);
    set_wielding_limbs( ({"left hand","right hand"}) );
    add_money("gold", 20 + random(140));
      set_resistance("cold",20);
      set_resistance("fire",-20);
}


void fireball(object targ)
{
    if(!targ) return 0;
    if(random(35) > targ->query_stats("intelligence")){
	tell_room(environment(targ), "%^BLUE%^Waterdemon hurls a sphere of compressed water at "+targ->query_cap_name()+" and a wave of spray rushes past you!",targ);
	set_invis();
	tell_object(targ, "%^BOLD%^%^BLUE%^Waterdemon hurls a sphere of compressed water at your head!");
	targ->do_damage("head", random(2)+25);
	return 1;

    } else {

	tell_object(targ, "%^BOLD%^%^BLUE%^Waterdemon hurls a sphere of compressed water at your head, but it disperses into spray as it approaches!");
	tell_room(environment(targ), "%^BLUE%^Waterdemon hurls a sphere of compressed water at "+targ->query_cap_name()+" but it disperses into spray before it strikes them.",targ);
	set_invis();

    }
}
