#include <std.h>
#include "/d/dagger/drow/keep/short.h"
inherit MONSTER;
void create() {
    ::create();
    set_name("drow");
    set_id(({"drow","soldier","drow soldier"}));
    set_short("Drow soldier");
    set_long(
       "%^BOLD%^%^BLUE%^The Drow soldier is a menacing sight "
       "indeed. Only the most elite of their class was selected "
	"for The Intrusion Project. Like all fo their brothers and "
	"sisters, these Drow are highly trained "
       "for war purposes and are known to be ruthless in "
       "combat. They follow their orders relentlessly and to the death "
       "with no questions asked.%^RESET%^"
    );
    set_race("Drow");
    set_gender("male");
    set_hd(10,6);
    set_size(2);
    set_overall_ac(2);
    set_class("fighter");
    set_guild_level("fighter",10);
    set_max_hp(105);
    set_hp(105);
    set_wielding_limbs(({"right hand","left hand"}));
    set_body_type("humanoid");
    set_property("swarm",1);
    set_property("no bump",1);
    set_stats("strength",19);
    set_stats("dexterity",18);
    set_stats("constitution",17);
    set("aggressive","aggfunc");
    set_alignment(9);
    set_mob_magic_resistance("average");
    set_exp(2000);
    set_emotes(5,({
       "The Drow soldier evil eyes glance around the room.",
       "The Drow soldier says: The Intrusion Project shall be a great victory.",
       "The Drow soldier appears to have detected you!"
    }),0);
    set_emotes(3,({
	"%^BOLD%^%^YELLOW%^The Drow chuckles as he lashes out!%^RESET%^",
	"%^BOLD%^%^RED%^Drow yells: Even if I perish, more will come!%^RESET%^"
    }),1);

}
void aggfunc() {
    object shape;
    string mrace=TP->query_race();
    if(objectp(shape = TP->query_property("shapeshifted"))) mrace = (string)shape->query_shape_race();
    if(TP->query_invis()) return 1;
    if((string)TP->query_true_name() == "grazzt") {
	 force_me("say My Lord we shall not fall!");
	 force_me("bow grazzt");
	 return 1;
    }
    if (mrace == "Drow") {
       force_me ("bow");
       return 1;
    } else {
       TP->kill_ob(TO,0);
        message("env",
	   "%^MAGENTA%^Drow yells: %^RESET%^You will never stop the swarm!"
	,environment(this_object()));
    }
    if(this_player()->query_lowest_level() > 21) {
        message("lloth",
	    "%^BOLD%^%^RED%^Lloth tells you:%^RESET%^ I have detected your great power! Feel my WRATH!"
        ,this_player());
        message("lloth",
	    "%^BOLD%^%^YELLOW%^A violent tremor of energy erupts around "
	    +this_player()->query_cap_name()+"'s feet!"  
	,environment(this_player()));
        this_player()->add_hp(-(((int)this_player()->query_hp())/2));
        this_player()->do_damage("torso",random(5));
    }
}
