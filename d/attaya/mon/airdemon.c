
#include <std.h>
inherit MONSTER;

create (){
    ::create ();
    set_name("airdemon");
    set_id(({"airdemon","demon"}));
    set_short("Airdemon");
    set_long(
      "The Airdemon is a powerful demonic warrior that is almost completely transparent.  It has glowing blue eyes that are visible amidst a hardly visible form."
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
    set_stats("wisdom", 25);
    set("aggressive", 19);
    set_alignment(4);
    set_invis();
    add_search_path( "cmds/thief" );
    set_hp(230);
    set_exp(3500);
    set_emotes(20,({
	"%^RED%^The airdemon's eyes glow brightly!",
	"%^RED%^The airdemon displays it's razor sharp teeth.",
	"%^RED%^The airdemon shrieks horribly!"
      }),0);
    set_funcs( ({"fireball"}) );
    set_func_chance(65);
    set_wielding_limbs( ({"left hand","right hand"}) );
    add_money("gold", 20 + random(140));
      set_resistance("electricity",20);
      set_resistance("acid",-20);
}


void fireball(object targ)
{
    if(!targ) return 0;
    if(random(35) > targ->query_stats("intelligence")){
	tell_room(environment(targ), "%^CYAN%^Airdemon glows as it compresses the air in "+targ->query_cap_name()+"'s lungs making it impossible for "+targ->query_subjective()+" to breathe!",targ);
	set_invis();
	tell_object(targ, "%^BOLD%^%^CYAN%^Airdemon glows and you feel your lungs tighten up as the air inside is compressed!");
	targ->do_damage("head", random(2)+25);
	return 1;

    } else {
	tell_room(environment(targ), "%^BOLD%^%^CYAN%^Airdemon glows briefly!");

	set_invis();

    }
}
