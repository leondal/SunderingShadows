#include <std.h>
inherit MONSTER;

void init() {
    ::init();
    add_action("no_kill","rush");
    add_action("no_kill","stab");
    add_action("no_kill","kill");
    add_action("no_kill","con");
    add_action("no_kill","rebuke");
    add_action("no_kill","say");
    add_action("no_kill","cast");
    add_action("no_kill","throw");
    add_action("no_kill","east");
    add_action("no_kill","tell");

}
create() {
    ::create();
    set_name("cloaked nomad");
    set_id( ({
	"nomad", "cloaked nomad"
      }) );
    set("race", "undead");
    set_gender("female");
    set("short",
      "A shadowy cloaked female nomad"
    );
    set_long(
      "This is a wandering nomad who has come to this dark altar to perform a ritual of immortality.  Her body is hidden beneath a long cloak.\n She has the powers of the gods behind her it would seem."
    );
    set_level( 30 );
    set_body_type("humanoid");
    set("aggressive", 1);
    set_alignment( 7 );
    set_size( 2 );
    set_stats("intelligence", 25);
    set_stats("wisdom", 25);
    set_stats("strength", 24);
    set_stats("charisma", 25);
    set_stats("dexterity", 18);
    set_stats("constitution", 25);
    set_max_mp(500);
    set_max_hp(10000);
    set_hp(10000);
    set_spell_chance(99);
    set_spells(({
	"chill touch",
	"dispel magic",
	"magic missile",
	"freeze"
      }));
    set_mp(query_max_mp());
    set_exp(100000);
    set_max_sp(query_hp());
    set_sp(query_max_sp());
    add_money("silver",random(1300));
    add_money("copper",random(20));
    set_emotes(5,({
	"The nomad mumbles to the ancient spirits of evil..",
	"The nomad raises her hands to the sky.",
	"The nomad rocks back and forth on her knees.",
	"%^BOLD%^The symbols on the altar glow brightly!",
	"%^CYAN%^The undead around you shriek loudly!",
	"%^RED%^Your heartrate picks up.",
      }) ,0);
}
int no_kill(string str) {
    object targ;
    targ = this_player();
    command( "say You have just become a sacrifice,  "+this_player()->query_cap_name()+". ");
    write("%^BOLD%^%^BLUE%^The Nomad casts a spell and an aura of blue light surrounds you!\n");
    say((string)this_player()->query_cap_name()+" is surrounded by an aura of blue light.\n");
    write("You are magically teleported somewhere.\n");
    this_player()->move_player("/d/attaya/cliff61.c");
    return 1;
}
