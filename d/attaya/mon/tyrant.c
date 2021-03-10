#include <std.h>
inherit WEAPONLESS;
void create() {
    ::create();
    set_name("tyrant");
    set_id(({"tyrant","grand tyrant","undead"}));
    set_short("Grand Tyrant");
    set_long(
      "In your travels, few creatures have filled you with as much dread from gazing upon them as the Tyrant.  It is a huge humanoid creature with decaying, worm eaten flesh and a long, razor sharp, jagged blade where each hand should be!"
      +"The tyrant stands nearly sixteen feet tall.  It's eyes look human and show an all too familiar look of desparation.  It wants only one thing..."
      +"%^RED%^To tear your body into tiny unrecognizable pieces so that it can forget that you were ever here..."
    );
    set_race("tyrant");
    set_hd(14,20);
    set_level(25);
    set_size(5);
    set_overall_ac(-16);
    set_class("fighter");
    set_guild_level("fighter",25);
    set_max_hp(730);
    set_hp(730);
    set_wielding_limbs(({"left hand","right hand"}));
    add_limb("left bone blade","left bone blade",96,1,4);
    add_limb("right bone blade","right bone blade",96,1,4);
    add_limb("fangs","fangs",96,1,4);
    set_attacks_num(3);
    set_attack_limbs(({"left bone blade", "right bone blade", "fangs"}));
    set_base_damage_type("piercing");
    set_damage(3,8);
    set_body_type("humanoid");
    set_property("swarm",1);
    set_property("no bump",1);
    set_stats("strength",20);
    set_stats("dexterity",16);
    set_stats("constitution",17);
    set("aggressive","aggfunc");
    set_mob_magic_resistance("low");
    set_exp(30000);
    set_alignment(9);
    set_emotes(3,({
	"%^CYAN%^The Tyrant shrieks horribly!",
	"The Tyrant stares at you!",
      }),0);
}
void die(object ob) {
    message("environment",
      "%^BOLD%^%^CYAN%^The Tyrant lets out a bone cracking scream and collapses to its knees.\n"
      "With it's final strength, the Tyrant looks up at you.  You can see a glint of remorse in it's human like eyes...\n"
      "%^BOLD%^%^GREEN%^The Tyrant suddenly shifts to human form, and a sad faced young woman looks up at you.\n"
      "%^RESET%^She tries to speak but lacks the energy.\n"
      ,environment(TO));
    set_name("young woman");
    :: die(ob);
}
int aggfunc() {
    string mrace=TP->query_race();
    if(wizardp(TP)) return 1;
    if (mrace == "poltergeist") {
	force_me ("emote shrieks horribly");
	return 1;
    } else {
	TP->kill_ob(TO,0);
	force_me("emote %^BOLD%^%^CYAN%^shrieks loudly and flexes!");
    }
}
