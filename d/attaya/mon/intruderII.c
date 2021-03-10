
#include <std.h>
inherit MONSTER;

create() {
    ::create();
    set_name("spectre");
    set_id( ({
	"intruder", "spectre", "spectre of intruder"
      }) );
    set("race", "spectre");
    set_gender("male");
    set_short("Spectre of Intruder");
    set_long(
      "This is the spectoral presence of Intruder the Warrior General of the Kinnesaruda.  It's form shifts and waivers and you can see right through it!\n Intruder is a powerful undead warrior.  His golden armor is gashed from earlier battles but still shines in places.  His face displays malice beneath a coat of rotting leathery flesh and shiny black eyes. "
    );
    set_body_type("human");
    set_spell_chance(60);
    set_class("fighter");
    set_class("mage");
    set_mlevel("fighter", 40);
    set_mlevel("mage", 35);
    set_guild_level("mage", 35);
    set_guild_level("fighter", 40);
    set_overall_ac(-13);
    set_spells(({
	"cone of cold",
	"hideous laughter",
	"burning hands",
	"finger of death",
	"fireball",
	"chain lightning",
	"magic missile",
	"acid arrow"
      }));
    set("aggressive","aggfunc");
    set_mob_magic_resistance("very low");
    set_alignment(9);
    set_size( 3 );
    set_hp(300);
    set_sp(200);
    set_funcs( ({"grin"}) );
    set_func_chance(40);
    set_exp(5000);
}
void die(object ob) {
    message("environment",
      "%^BOLD%^%^CYAN%^Intruder whispers to you:%^RESET%^ Well...  It would appear you either have a strong desire to end your miserable little life as a warrior, or you are simply an idiot who knows not what they wandered into.  %^RED%^Proceed on your way to oblivion.  I am waiting for you in the tower."
      ,environment(TO));
    :: die(ob);
}
void grin(){
    force_me ("say %^RED%^You are no match for the Kinnesaruda.");
}
void mega(){
    force_me ("break seal");
}
void aggfunc() {
    string mrace=TP->query_race();
    if (mrace == "undead") {
	force_me ("grin");
	return 1;
    } else {
	if(wizardp(TP)) return 1;
	TP->kill_ob(TO,0);
	force_me("emote grins at you.");
	force_me("say %^RED%^I am but a shadow of my true self.!");
	force_me("say %^RED%^Let's see if you are worth your mettle.!");
	force_me("wave");
	force_me("cackle very evilly");
    }
}
