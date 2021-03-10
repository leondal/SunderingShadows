#include <std.h>
// Increasing Exp Dinji 8-26-07
inherit MONSTER;

void create() {
    :: create();
    set_name("drow");
    set_id(({  "elite","drow","warrior","drow elite","elite drow","drowmon"  }));
    set_short("%^RESET%^%^RED%^Elite drow%^RESET%^");
    set_long(
        "%^RESET%^%^RED%^The Elite Drow of underdark are feared by "
        "humanoids throughout the lands. Highly trained in combat "
        "maneuvers and ruthless in battle they rival even the "
        "powerful Drow priests for deadly prowess. The Elite Drow are "
        "female in nature similar to the priests. Furthermore, "
        "these diabolical beings generally are put in positions of power "
        "over entire squads of Drow."
    );
    set_gender("female");
    set_hd(16,5);
    set_size(2);
   set_max_level(22);
    set_wielding_limbs(({"right hand","left hand"}));
    set_overall_ac(-5);
   set_hp(350);
    set_mob_magic_resistance("average");
    set_property("no bows",1);
   set_max_hp(350);
    set_exp(12000);
   set_max_level(25);
    set_body_type("human");
    set_property("swarm",1);
    set_race("drow");
    set_class("fighter");
    set_guild_level("fighter",15);
    set_stats("strength",20);
    set_stats("constitution",20);
    set("aggressive",25);
    set_stats("dexterity",20);
    set_stats("wisdom",17);
    set_stats("intelligence",17);
    set_stats("charisma",17);
    set_alignment(9);
    new("/d/dagger/drow/obj/elitesword.c")->move(TO);
    command("wield sword in left hand and right hand");
    if(!random(8))
	new("/d/dagger/drow/obj/drow_gem")->move(TO);
    set_funcs(({"moves"}));
    set_func_chance(25);
    set_emotes(2, ({
	"The elite drow looks you over with disgust.",
	"The female elite drow cackles evilly, sending chills down your spine.",
	"%^BLUE%^The elite drow spins around at you!%^RESET%^",
        "%^RED%^The elite drow tests the steel of her blade on your skull!%^RESET%^"
    }),0);
}

int moves() {
    int xx;
    object ob = this_object();
    object targ = ob->query_current_attacker();
    xx=random(3)+1;
    switch(xx) {
    case 1:
    tell_object(targ,
	"%^RED%^The Drow sweeps her leg beneath your feet knocking you to "
	"the ground!%^RESET%^"
    );
    tell_room(environment(targ),
	"%^RED%^The Drow sweeps her leg beneath "
	+targ->query_cap_name()+"'s feet knocking them to the "
	"ground!%^RESET%^"
    ,targ);
    targ->do_damage("torso",roll_dice(1,6));
    targ->set_paralyzed(50,
	"%^RED%^As you try to stand, the Drow knocks you down again!%^RESET%^");
    return 1;
    case 2:
    tell_object(targ,
	"%^BOLD%^%^RED%^The Drow mutters, `Slyssthizth Muh hauh diabuoli!' "
	"and an intense pain shoots up your spine to the base of your cranium!%^RESET%^");
    tell_room(environment(targ),
	"%^BOLD%^%^RED%^The Drow mutters, `Slyssthizth Muh hauh diabuoli!' "
	"and "+targ->query_cap_name()+" screams out in pain!%^RESET%^",targ);
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
    targ->set_paralyzed(random(50),
	"%^GREEN%^The Drow has you pinned!"
    );
    TO->set_paralyzed(50,"Bug report if this message is seen!");
    return 1;
    }
return 1;
}
