#include <std.h>
#include "/d/dagger/drow/short.h"
inherit MONSTER;
int xx;
void create() {
    :: create();
    set_name("kraznoth");
    set_id(({
      "elite","drow","weaponsmith","kraznoth","drow weaponsmith"
      }));
    set_short("%^RESET%^%^RED%^Kraznoth, the Drow Weaponsmith%^RESET%^");
    set_long(
	"%^BOLD%^%^BLACK%^The drow weaponsmith's sole job is to forge "
	"armour and weapons for the Drow Regime."
	"He has a clean shaven head which is unusual for drow and is covered "
	"in muscles.%^RESET%^"
    );
    set_gender("male");
    set_hd(16,5);
    set_size(2);
    set_wielding_limbs(({"right hand","left hand"}));
    set_overall_ac(-5);
    set_hp(135);
    set_property("no bump",1);
    set_mob_magic_resistance("average");
    set_max_hp(135);
    set_exp(4000);
    set_body_type("humanoid");
    set_race("drow");
    set_class("fighter");
    set_guild_level("fighter",15);
    set_stats("strength",20);
    set_stats("constitution",20);
    set_stats("dexterity",20);
    set_stats("wisdom",17);
    set_stats("intelligence",17);
    set_stats("charisma",17);
    set_alignment(9);
    set_funcs(({"moves"}));
    set_func_chance(25);
    add_money("gold",200);
    set_emotes(1,({
	"The drow weaponsmith bangs with hammer to sword.",
	"The drow weaponsmith tests some steel.",
	"The drow weaponsmith looks you over."
    }),0);
    new ( OPATH "marmor.c" );
    command("wear armour");
    new ( OPATH "blsword.c" );
    command("wield sword in left hand");
    new ( OPATH "blbow.c" );
    command("wield bow in right hand");
}
int moves() {
    object ob = this_object();
    object targ = ob->query_current_attacker();
    xx=random(3)+1;
    switch(xx) {
    case 1:
    tell_object(targ,
	"%^RED%^The Drow sweeps his leg beneath your feet knocking you to "
	"the ground!%^RESET%^"
    );
    tell_room(environment(targ),
	"%^RED%^The Drow sweeps his leg beneath "
	+targ->query_cap_name()+"'s feet knocking them to the "
	"ground!%^RESET%^"
    ,targ);
    targ->do_damage("torso",roll_dice(1,6));
    targ->set_paralyzed(50,
	"%^RED%^As you try to stand, the Drow knocks you down "
	"again!%^RESET%^"
    );
    return 1;
    case 2:
    tell_object(targ,
	"%^BOLD%^%^RED%^The Drow mutters, `Slyssthizth Muh hauh diabuoli!' "
	"and an intense pain shoots up you spine to the base of your "
	"cranium!%^RESET%^"
    );
    tell_room(environment(targ),
	"%^BOLD%^%^RED%^The Drow mutters, `Slyssthizth Muh hauh diabuoli!' "
	"and "+targ->query_cap_name()+" screams out in "
	"pain!%^RESET%^"
    ,targ);
    targ->do_damage("head",roll_dice(4,12));
    return 1;
    case 3:  
    tell_object(targ,
	"%^GREEN%^%^BOLD%^The Drow tackles you to the ground pinning "
	"you!%^RESET%^"
    );
    tell_room(environment(targ),
	"%^GREEN%^%^BOLD%^The Drow tackles "
	+targ->query_cap_name()+" to the ground pinning them!%^RESET%^"
    ,targ);
    targ->set_paralyzed(100,
	"%^GREEN%^The Drow has you pinned!"
    );
    TO->set_paralyzed(100,"Bug report if this message is seen!");
    return 1;
    }
return 1;
}
void die(object ob) {
    message("environment",
	"%^GREEN%^%^BOLD%^The Weaponsmith screams in rage as he dies!"
	"%^RESET%^"
    ,environment(TO));
    ::die(ob);
}
