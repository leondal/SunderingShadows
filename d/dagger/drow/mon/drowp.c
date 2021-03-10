#include <std.h>
inherit MONSTER;
void create() {
    ::create();
    call_out("roam_fun",1);
    set_name("drow assassin");
   set_id(({"drow","assassin","drow assassin","drowmon"}));
   set_short("%^BLUE%^Drow assassin%^RESET%^");
    set_long(
        "%^BOLD%^%^BLUE%^The Drow assassin is an evil foe indeed.  They "
        "are used by the Drow Regime for their skills in killing quickly and "
	"silently.  They are often sent to assassinate nobles and leaders "
	"of their enemies factions.  When not doing this they patrol the "
	"city in which they reside looking for intruders to practice their "
	"skills upon."
    );
    set_race("drow");
    set_gender("male");
    set_size(2);
    set_overall_ac(0);
    set_class("thief");
    set_mlevel("thief",20);
    set_guild_level("thief",20);
    set_hd(20,6);
    set_max_hp(125);
    set_hp(125);
    set_wielding_limbs(({"right hand","left hand"}));
    set_body_type("humanoid");
    set_property("swarm",1);
    set_property("no_bump",1);
    set_stats("strength",19);
    set_stats("dexterity",18);
    set_stats("constitution",17);
    set_thief_skill("move silently",95);
    set_thief_skill("hide in shadows",95);
    add_search_path( "cmds/thief" );
    set("aggressive","aggfunc");
    set_mob_magic_resistance("average");
    set_exp(5500);
    set_max_level(20);
    set_alignment(9);
    set_emotes(15, ({
	"%^BOLD%^%^BLACK%^The drow assassin lashes out at you!%^RESET%^",
	"%^BOLD%^%^GREEN%^The drow assassin twirls around suddenly!%^RESET%^",
	"%^BOLD%^%^BLUE%^The drow assassin says: %^RED%^Die already%^BLUE%^"
	"!%^RESET%^"
    }),1);
    new("/d/dagger/drow/obj/bldagger.c")->move(this_object());
    command("wield dagger in right hand");
    new("/d/dagger/drow/obj/bldagger.c")->move(this_object());
    command("wield dagger in left hand");
    new( "/d/dagger/drow/obj/cylinder.c" )->move(TO);
    set_invis();
    set_funcs(({"dart"}));
    set_func_chance(25);
    set_moving( 1 );
    set_speed ( 20 );
}
void aggfunc() {
    object shape;
    string mrace=TP->query_race();
    if(objectp(shape = TP->query_property("shapeshifted"))) mrace = (string)shape->query_shape_race();
   if(mrace == "drow" || (TP->query_invis() && !random(3))){
	command("grin");
    } else {
	command("say Now you die!");
        call_out("stab",1,TP);
    }
}
void stab(object targ) {
    command("stab "+targ->query_name());
    set_invis();
}
void dart(object targ) {
    string dam;
    if("daemon/saving_d"->saving_throw(targ,"poison")) {
	dam="hurts";
    } else {
	dam="poisons";
    }
    tell_object(targ,
	"%^GREEN%^The drow assassin reaches into his pocket and suddenly "
	"hurls a small dart at you! The dart strikes and "+dam+
	" you!%^RESET%^"
    );
    tell_room(environment(targ),
	"%^GREEN%^The drow assassin reaches into his pocket and suddenly "
	"hurls a small dart at "+targ->query_cap_name()+"!%^RESET%^"
    ,targ);
    if(dam=="poisons") {
	targ->do_damage("torso",roll_dice(3,6));
	tell_object(targ,
	    "%^GREEN%^You feel the darts venom cause your muscles to "
	    "stiffen as hard as stone!%^RESET%^"
	);
	targ->set_paralyzed(random(10)+15,
	    "%^GREEN%^The venom still siezes your muscles!%^RESET%^"
	);
    } else {
	targ->do_damage("torso",roll_dice(1,6));
    }
    return 1;
}
void roam_fun(){
    if(objectp(TO) && objectp(ETO))
        ETO->init();
}
