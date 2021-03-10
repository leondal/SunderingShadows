#include <std.h>
inherit MONSTER;
int xx;
void create() {
    :: create();
   set_name("Drow emissary");
    set_id(({
   "drow","emisary","drow emisary","emissary","drow emissary","drowmon"
    }));
   set_short("%^BLUE%^Drow emissary%^RESET%^");
    set_long(
           "%^BLUE%^The drow emissary wears a long dark robe. He sits at the "
    	"desk scribbling notes on papers that lay before him. "
    	"He is of noble drow descent and is here to deal with "
    	"%^RED%^Grazzt%^BLUE%^ on part of the drow regime "
    	"in the aquisition of immortal powers for his people to purchase and "
    	"utilize.%^RESET%^"
    );
    set_gender("male");
    set_race("drow");
    set_hd(19,3);
    set_size(2);
    set_wielding_limbs(({"right hand","left hand"}));
    set_overall_ac(0);
    set_hp(280);
    set_property("no bump",1);
    set_mob_magic_resistance("average");
    set_max_hp(280);
    set_exp(10000);
    set_body_type("human");
    set_class("fighter");
    set_guild_level("fighter",19);
    set_stats("strength",21);
    set_stats("constitution",19);
    set_stats("dexterity",22);
    set_stats("wisdom",20);
    set_stats("intelligence",20);
    set_stats("charisma",19);
    set_alignment(9);
    new("/d/dagger/drow/obj/tablet.c")->move(TO);
    set_funcs(({"moves"}));
    set_func_chance(40);
    set_emotes(3, ({
	"The emisary scribbles on the papers before him.",
	"The emisary looks up from his writings, shakes his head, and "
	"says, `Bah, he would take one look at that and scream Out Of "
	"Balance.'",
	"The emisary peers up.",
	"The emisary says, `Yes? You want something?'"
    }),0);
    new("/d/dagger/drow/obj/bldagger.c")->move(this_object());
    command("wield dagger in left hand");
}
int moves() {
    object ob = this_object();
    object targ = ob->query_current_attacker();
    xx=random(4)+1;
    switch(xx) {
    case 1:
    tell_object(targ,
	"%^RED%^%^BOLD%^The emisary points a finger towards "
	"you!\n%^MAGENTA%^You are racked with pain and vomit "
	"uncontrollably!%^RESET%^"
    );
    tell_room(environment(targ),
	"%^RED%^%^BOLD%^The emisary points a finger towards " 
	+targ->query_cap_name()+"!"
    ,targ);
    targ->do_damage("head",roll_dice(8,6));
    targ->set_paralyzed(40,
	"You are vomiting uncontrollably!"
    );
    return 1;
    case 2:
    tell_object(targ,
	"%^BOLD%^%^BLUE%^The emisary creates a glimmering blue sphere "
	"around you!\n%^YELLOW%^You vanish in a blinding flash!"
    );
    tell_room(environment(targ),
	"%^BLUE%^%^BOLD%^The emisary creates a glimmering blue sphere "
	"around "
	+targ->query_cap_name()+
   "!%^YELLOW%^The sphere and its contents vanish in a blinding "
	"flash!"
    ,targ);
    targ->move_player("/d/dagger/drow/rooms/city1.c");
    return 1;
    case 3:  
    tell_object(targ,
	"%^MAGENTA%^%^BOLD%^The emisary creates a purple sphere around "
	"you!"
    );
    tell_room(environment(targ),
	"%^MAGENTA%^%^BOLD%^The emisary creates a purple sphere around "
	+targ->query_cap_name()+"!"
    ,targ);
    tell_object(targ,
	"%^MAGENTA%^%^BOLD%^The sphere pulses causing you "
	"pain!\n%^BOLD%^%^CYAN%^The sphere grows larger!"
    );
    tell_room(environment(targ),
	"%^BOLD%^%^MAGENTA%^"
	+targ->query_cap_name()+" screams in pain!"
    ,targ);
    targ->do_damage("torso",roll_dice(1,3));
    tell_object(targ,
	"%^MAGENTA%^%^BOLD%^The sphere pulses causing you "
	"pain!\n%^BOLD%^%^CYAN%^The sphere grows larger!"
    );
    tell_room(environment(targ),
	"%^BOLD%^%^MAGENTA%^"
	+targ->query_cap_name()+" screams in pain!"
    ,targ);
    targ->do_damage("torso",roll_dice(1,6));
    tell_object(targ,
	"%^MAGENTA%^%^BOLD%^The sphere pulses causing you "
	"pain!\n%^BOLD%^%^CYAN%^The sphere grows larger!"
    );
    tell_room(environment(targ),
	"%^BOLD%^%^MAGENTA%^"
	+targ->query_cap_name()+" screams in pain!"
    ,targ);
    targ->do_damage("torso",roll_dice(1,12));
    tell_object(targ,
	"%^MAGENTA%^%^BOLD%^The sphere pulses causing you "
	"pain!\n%^BOLD%^%^CYAN%^The sphere grows larger!"
    );
    tell_room(environment(targ),
	"%^BOLD%^%^MAGENTA%^"
	+targ->query_cap_name()+" screams in pain!"
    ,targ);
    targ->do_damage("torso",roll_dice(1,20));
    tell_object(targ,
	"%^MAGENTA%^%^BOLD%^The sphere pulses causing you "
	"pain!\n%^BOLD%^%^CYAN%^The sphere grows smaller."
    );
    tell_room(environment(targ),
	"%^BOLD%^%^MAGENTA%^"
	+targ->query_cap_name()+" screams in pain!"
    ,targ);
    targ->do_damage("torso",roll_dice(1,12));
    tell_object(targ,
	"%^MAGENTA%^%^BOLD%^The sphere pulses causing you "
	"pain!\n%^BOLD%^%^CYAN%^The sphere grows smaller."
    );
    tell_room(environment(targ),
	"%^BOLD%^%^MAGENTA%^"
	+targ->query_cap_name()+" screams in pain!"
    ,targ);
    targ->do_damage("torso",roll_dice(1,6));
    tell_object(targ,
	"%^MAGENTA%^%^BOLD%^The sphere pulses causing you "
	"pain!\n%^BOLD%^%^CYAN%^The sphere vanishes."
    );
    tell_room(environment(targ),
	"%^BOLD%^%^MAGENTA%^"
	+targ->query_cap_name()+" screams in pain!"
    ,targ);
    targ->do_damage("torso",roll_dice(1,3));
    return 1;
    case 4:
    tell_object(targ,
	"%^RED%^The emisary creates a red time sphere around "
	"you!%^RESET%^"
    );
    tell_room(environment(targ),
	"%^RED%^The emisary creates a red time sphere around "
	+targ->query_cap_name()+"!%^RESET%^"
    ,targ);
    targ->set_paralyzed(100,
	"%^RED%^Time has stopped for you!"
    );
    return 1;
    }
return 1;
}
