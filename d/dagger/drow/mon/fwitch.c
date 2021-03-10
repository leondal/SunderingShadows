#include <std.h>
inherit MONSTER;
int xx,y;
void create() {
    :: create();
    set_name("fire witch");
    set_id(({
      "witch","fire","fire witch"
      }));
    set_short("%^BOLD%^%^RED%^Fire witch%^RESET%^");
    set_long(
      "%^RESET%^%^RED%^The Fire witch appears as a pillar of flame with "
      "the shape and body of a female human. Two jet black eyes are inset "
   "into what would be its head.%^RESET%^"
    );
    set_gender("female");
    set_hd(29,4);
    set_size(2);
    set_overall_ac(-1);
    set_max_hp(200);
   set_max_level(20);
    set_hp(200);
    set_property("no bump",1);
    set_mob_magic_resistance("average");
    set_exp(5500);
    set_body_type("humanoid");
    set_wielding_limbs(({"right hand","left hand"}));
    set_race("witchen");
    set_class("fighter");
    set_guild_level("fighter",29);
    set_mlevel("fighter",29);
    set_stats("strength",17);
    set_stats("constitution",17);
    set_stats("dexterity",17);
    set_stats("wisdom",16);
    set_stats("intelligence",16);
    set_stats("charisma",14);
    set_alignment(9);
    set("aggressive",20);
    new("/d/dagger/drow/obj/flames.c")->move(TO);
    command("wield flames in right hand");
    new("/d/dagger/drow/obj/fireball.c")->move(TO);
    command("wield fireball in left hand");
    set_funcs(({"moves"}));
    set_func_chance(35);
    set_emotes(6, ({
	"%^RED%^The fire burns into your soul!%^RESET%^",
	"%^RED%^%^BOLD%^The heat is unbearable!%^RESET%^",
	"%^RED%^%^BOLD%^Your hair ignites!"
    }),1);
}
int moves() {
object ob = this_object();
object targ = ob->query_current_attacker();
    xx=random(2)+1;
    y = random(10)+1;
    switch(xx) {
    case 1:
	tell_object(targ,
	    "%^RED%^The Fire Witch mutters an incantation!%^RESET%^"
        );
	tell_room(environment(targ),
	    "%^RED%^The Fire Witch mutters an incantation and points at "
	  +targ->query_cap_name()+"'s body!%^RESET%^"
	,targ);
	new("/d/dagger/drow/obj/vomit.c")->move(targ);
	return 1;
    case 2:
       set_property("magic",1);
        tell_object(targ,
	    "%^BOLD%^%^RED%^The Fire Witch summons a pillar of fire around "
	    "your body!\n%^YELLOW%^You scream as the flames burn your body! "
	    "%^RESET%^"
	);
	tell_room(environment(targ),
	    "%^BOLD%^%^RED%^The Fire Witch summons a pillar of fire "
	    "around "+targ->query_cap_name()+"'s body!"
	    "\n%^YELLOW%^"+targ->query_cap_name()+" screams as the flames "
	    "burn their body!%^RESET%^"
	,targ);
	targ->do_damage("torso",roll_dice(y,5));
       remove_property("magic");
	return 1;
    }
    return 1;
}
