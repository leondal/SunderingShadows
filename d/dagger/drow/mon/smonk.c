#include <std.h>
inherit MONSTER;
int xx;
void create() {
    :: create();
    set_name("shadow monk");
    set_id(({
	"shadow","monk","shadow monk"
    }));
   set_short("%^BOLD%^%^BLACK%^Shadow Monk%^RESET%^");
    set_long(
      "%^BLACK%^%^BOLD%^The features of the shadow monk a hard to make "
      "out as he blends with the shadows perfectly. All that can been "
      "seen of him is that he is humanoid. Two "
      "%^RED%^glowing red%^BLACK%^ eyes peer out of the darkness which "
      "forms his body.%^RESET%^"
    );
    set_gender("male");
    set_hd(19,7);
    set_size(2);
    set_wielding_limbs(({"right hand","left hand"}));
    set_overall_ac(-3);
    set_hp(120);
    set_property("no bump",1);
    set_mob_magic_resistance("average");
    set_max_hp(120);
    set_exp(10000);
    set_body_type("human");
    set_race("human");
    set_class("fighter");
    set_guild_level("fighter",19);
    set_stats("strength",20);
    set_stats("constitution",20);
    set_stats("dexterity",23);
    set_stats("wisdom",18);
    set_stats("intelligence",18);
    set_stats("charisma",17);
    set_alignment(9);
    set_funcs(({"moves"}));
    set_func_chance(40);
    set_emotes(3, ({
	"%^BLACK%^%^BOLD%^The shadows thicken around you.%^RESET%^",
	"%^BLACK%^%^BOLD%^Something in the shadows shifts from view "
	"as you turn to look at it.%^RESET%^",
	"%^BLACK%^%^BOLD%^You feel a cold chill.%^RESET%^",
	"%^BLUE%^%^BOLD%^The shadow monk chuckles politely.%^RESET%^"
    }),0);
   if(random(20) < 2){
      new("/d/dagger/drow/obj/velvet_mask.c")->move(TO);
      command("wear mask");
      }
}
int moves() {
    object ob = this_object();
    object targ = ob->query_current_attacker();
    xx=random(4)+1;
    switch(xx) {
    case 1:
    tell_object(targ,
	"%^BLACK%^%^BOLD%^The shadow monk leaps from the ground in a "
	"flash!\nThe shadow monk buries his foot into your face stunning "
	"you!%^RESET%^"
    );
    tell_room(environment(targ),
	"%^BLACK%^%^BOLD%^The shadow monk leaps from the ground in a "
	"flash!\nThe shadow monk buries his foot into "
	+targ->query_cap_name()+"'s face stunning them!%^RESET%^"
    ,targ);
    targ->do_damage("head",roll_dice(4,6));
    targ->set_paralyzed(40,
	"%^BLACK%^%^BOLD%^You are still reeling from the blow!%^RESET%^"
    );
    return 1;
    case 2:
    tell_object(targ,
	"%^BLACK%^%^BOLD%^The shadow monk spins around violently!\nThe "
	"shadow monk smashes you in the chest with a quick spin "
	"kick!%^RESET%^"
    );
    tell_room(environment(targ),
	"%^BLACK%^%^BOLD%^The shadow monk spins around violently!\nThe "
	"shadow monk smashes "+targ->query_cap_name()+
	" in the chest with his foot!%^RESET%^"
    ,targ);
    targ->do_damage("torso",roll_dice(3,6));
    targ->set_paralyzed(20,
	"%^BLACK%^%^BOLD%^You are gasping for air and clutching your chest "
	"in pain!%^RESET%^"
    );
    return 1;
    case 3:  
    tell_object(targ,
	"%^BLACK%^%^BOLD%^The shadow monk launches a blinding series of fist "
	"attacks!%^RESET%^"
    );
    tell_room(environment(targ),
	"%^BLACK%^%^BOLD%^The shadow monk launches a blinding series of "
	"fist attacks at "
	+targ->query_cap_name()+"!%^RESET%^"
    ,targ);
    tell_object(targ,
	"%^BLACK%^%^BOLD%^The shadow monk strikes you with his clenched "
	"fist!"
    );
    tell_room(environment(targ),
	"%^BLACK%^%^BOLD%^The shadow monk strikes "+targ->query_cap_name()+ 
	"with his clenched fist!%^RESET%^"
    ,targ);
    targ->do_damage("torso",roll_dice(1,4));
    tell_object(targ,
	"%^BLACK%^%^BOLD%^The shadow monk strikes you with his clenched "
	"fist!"
    );
    tell_room(environment(targ),
	"%^BLACK%^%^BOLD%^The shadow monk strikes "
	+targ->query_cap_name()+" with his clenched fist!%^RESET%^"
    ,targ);
    targ->do_damage("torso",roll_dice(1,4));
    tell_object(targ,
	"%^BLACK%^%^BOLD%^The shadow monk strikes you with his clenched "
	"fist!"
    );
    tell_room(environment(targ),
	"%^BLACK%^%^BOLD%^The shadow monk strikes "
	+targ->query_cap_name()+" with his clenched fist!%^RESET%^"
    ,targ);
    targ->do_damage("torso",roll_dice(1,4));
    tell_object(targ,
	"%^BLACK%^%^BOLD%^The shadow monk strikes you with his clenched "
	"fist!"
    );
    tell_room(environment(targ),
	"%^BLACK%^%^BOLD%^The shadow monk strikes "
	+targ->query_cap_name()+" with his clenched fist!%^RESET%^"
    ,targ);
    targ->do_damage("torso",roll_dice(1,4));
    tell_object(targ,
	"%^BLACK%^%^BOLD%^The shadow monk strikes you with his clenched "
	"fist!"
    );
    tell_room(environment(targ),
	"%^BLACK%^%^BOLD%^The shadow monk strikes "
	+targ->query_cap_name()+" with his clenched fist!%^RESET%^"
    ,targ);
    targ->do_damage("torso",roll_dice(1,4));
    tell_object(targ,
	"%^BLACK%^%^BOLD%^The shadow monk strikes you with his clenched "
	"fist!"
    );
    tell_room(environment(targ),
	"%^BLACK%^%^BOLD%^The shadow monk strikes "
	+targ->query_cap_name()+" with his clenched fist!%^RESET%^"
    ,targ);
    targ->do_damage("head",roll_dice(2,4));
    tell_object(targ,
	"%^BLACK%^%^BOLD%^The shadow monk strikes you with his clenched "
	"fist!"
    );
    tell_room(environment(targ),
	"%^BLACK%^%^BOLD%^The shadow monk strikes "
	+targ->query_cap_name()+" with his clenched fist!%^RESET%^"
    ,targ);
    targ->do_damage("head",roll_dice(3,4));
    return 1;
    case 4:
    tell_object(targ,
	"%^BLACK%^%^BOLD%^The shadow monk throws a shadow at you!\nThe "
	"shadow grips you in blindness!%^RESET%^"
    );
    tell_room(environment(targ),
	"%^BLACK%^%^BOLD%^The shadow monk throws a shadow at "
	+targ->query_cap_name()+"!%^RESET%^"
    ,targ);
    targ->set_paralyzed(100,
	"%^BLACK%^%^BOLD%^The shadows blind you in darkness!%^RESET%^"
    );
    return 1;
    }
return 1;
}
