#include <std.h>
inherit MONSTER;
int xx,y;
void create() {
    :: create();
    set_name("air elemental");
    set_id(({
      "elemental","air","air elemental"
      }));
    set_short("%^BOLD%^%^CYAN%^Air elemental%^RESET%^");
    set_long(
      "%^RESET%^%^RED%^The Air Elemental appears as a swirling tornado. "
      "These creatures from the Elemental Plane of Air generally are summoned "
      "by powerful mages or through devices. They are often trapped into "
      "objects for use upon their release at a later time. And they generally "
      "are not in a good mood once summoned.%^RESET%^"
    );
    set_gender("female");
    set_hd(12,2);
    set_size(3);
    set_overall_ac(-1);
    set_hp(90);
set_property("magic",1);
    set_property("no bump",1);
    set_mob_magic_resistance("average");
    set_max_hp(90);
    set_exp(1000);
    set_body_type("snake");
    set_wielding_limbs(({"head","tail"}));
    set_race("Elemental");
    set_class("fighter");
    set_guild_level("fighter",12);
    set_stats("strength",18);
    set_stats("constitution",17);
    set_stats("dexterity",18);
    set_stats("wisdom",16);
    set_stats("intelligence",16);
    set_stats("charisma",14);
    set("aggressive",20);
    new("/d/dagger/drow/obj/wind.c")->move(TO);
    command("wield wind in head");
    new("/d/dagger/drow/obj/wind.c")->move(TO);
    command("wield wind in tail");
    set_funcs(({"moves"}));
    set_func_chance(25);
    set_emotes(5, ({
	"%^CYAN%^The howl of the air elemental shakes your foundations!%^RESET%^",
	"%^CYAN%^%^BOLD%^The wind swirls about you!%^RESET%^",
	"%^CYAN%^%^BOLD%^You resist the power of the tornado's strength!"
    }),1);
}
int moves() {
object ob = this_object();
object targ = ob->query_current_attacker();
    xx=random(2)+1;
    y = random(6)+1;
    switch(xx) {
    case 1:
	tell_object(targ,
	    "%^CYAN%^The Air Elemental summons a minor tornado around your "
	    "body!%^RESET%^"
        );
	tell_room(environment(targ),
	    "%^CYAN%^The Air Elemental summons a minor tornado around "
	    +targ->query_cap_name()+"'s body!%^RESET%^"
	,targ);
	new("/d/dagger/drow/obj/tornado.c")->move(targ);
	return 1;
    case 2:
        tell_object(targ,
      "%^BOLD%^%^CYAN%^The Air Elemental uses its wind power "
	    "and scoops you off the ground!\n%^YELLOW%^The wind lets you free "
	    "at a height of "+y+"0 feet.\nYou plummet back towards the "
	    "ground!%^RED%^\nYou hit the ground with a dull THUD!%^RESET%^"
	);
	tell_room(environment(targ),
	    "%^BOLD%^%^CYAN%^The Air Elemental uses the powers of the wind "
	    "and scoops "+targ->query_cap_name()+" off the "
	    "ground!\n%^YELLOW%^The wind lets "+targ->query_cap_name()+" free "
	    "at a height of "+y+"0 feet.\n"+targ->query_cap_name()+" plummets "
	    "back towards the ground!\n%^RED%^"+targ->query_cap_name()+" hits "
	    "the ground with a dull THUD!%^RESET%^"
	,targ);
	targ->do_damage("head",roll_dice(y,6));
	return 1;
    }
    return 1;
}
void die(object ob) {
    message("environment",
	"%^CYAN%^%^BOLD%^The Air Elemental dissipates!%^RESET%^"
    ,environment(TO));
    ::die(ob);
}
