#include <std.h>
inherit MONSTER;

create (){
    ::create ();
    set_name("io");
    set_id( ({"Io", "io", "icarus", "warrior", "shadow"}) );
    set_short("%^BOLD%^%^WHITE%^Io,%^BLUE%^ Emissary of the Icarus Empire%^RESET%^");
    set_long(
      "Io is a loyal follower of the Icarus Empire.  He is their emmisary to the Kinnesaruda.  Little is known about the secretive Icarus organization.\n Though usually hidden from the eyes of his attackers by a means of telepathic overlook, Io occasionally displays a true form of a strong man with long gray hair and a faded black suit of leather."
    );
    set_gender("male");
    set("race", "human");
    set_body_type("human");
    set_property("swarm",1);
   set_hd(40,0);
   set_overall_ac(-28);
   set_size(2);
   set_stats("strength", 27);
    set_stats("intelligence", 25);
    set_stats("dexterity", 19);
    set_stats("charisma", 6);
    set_stats("wisdom", 25);
    set_class("fighter");
    set_wielding_limbs(({"right hand","left hand"}));
   new("/d/attaya/obj/z_boots")->move(TO);
   command("wear boots");
   new("/d/attaya/obj/shorts.c")->move(TO);
   command("wear shorts");
   new("/d/attaya/obj/silkvest")->move(TO);
   command("wear vest");
   new("/d/attaya/obj/falchion")->move(TO);
   command("wield sword in right hand");
   new("/d/attaya/obj/falchion")->move(TO);
   command("wield sword in left hand");
   new("/d/attaya/obj/shimmeringcape")->move(TO);
   command("wear cape");
    set_mob_magic_resistance("low");
    set_property("magic", 1);
    set_property("full attacks", 1);
    set("aggressive", 19);
    set_alignment(4);
    set_invis();
    add_search_path( "cmds/thief" );
   set_hp(2000);
    set_exp(20000);
    add_money("gold", 20 + random(600));
    set_emotes(40,({
	"Someone looks you over.",
	"Someone grins at you.",
      }),0);
    set_funcs( ({"fireball"}) );
    set_func_chance(40);
    add_money("gold", 20 + random(140));
}


void fireball(object targ)
{
    if(!targ) return 0;
    if(random(30) > targ->query_stats("dexterity")){
	tell_room(environment(targ), "%^BLUE%^An unseen force lifts "+targ->query_cap_name()+" into the air and slams them down against the floor!",targ);
	tell_object(targ, "%^BOLD%^%^BLUE%^An unseen force lifts you into the air and smashes you against the ground!");
         targ->do_damage("torso", random(120)+80);
	return 1;

    } else {

	tell_object(targ, "%^BOLD%^%^BLUE%^An unseen force grabs you by the neck and smashes you against the wall!");
	tell_room(environment(targ), "%^BLUE%^An unseen force grabs "+targ->query_cap_name()+" by the neck and slams them against the wall.");

         targ->do_damage("head", random(60)+40);
    }
}
