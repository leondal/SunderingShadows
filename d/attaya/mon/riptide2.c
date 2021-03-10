#include <std.h>
inherit MONSTER;

create() {
    ::create();
    set_name("riptide");
    set_id( ({
	"riptide", "boatman"
      }) );
    set("race", "undead");
    set_gender("male");
    set("short",
      "Riptide the Boatman"
    );
    set_long(
      "%^BOLD%^%^BLUE%^Ancient spirits slip aside to reveal Riptide, the mythical boatman of the River of Flame.  He grins at you.  It has been said that those he has taken across have never returned."
    );
    set_level( 30 );
    set_body_type("humanoid");
    set_alignment( 7 );
    set_size( 2 );
    set_stats("intelligence", 25);
    set_stats("wisdom", 25);
    set_stats("strength", 24);
    set_stats("charisma", 25);
    set_stats("dexterity", 18);
    set_stats("constitution", 25);
    set_max_mp(500);
    set_spell_chance(99);
    set_spells(({
	"chill touch",
	"dispel magic",
	"magic missile",
	"freeze"
      }));
    set_mp(query_max_mp());
    set_hd(5, 1);
    set_max_hp(query_hp());
    set_exp(500);
    set_max_sp(query_hp());
    set_sp(query_max_sp());
    add_money("silver",random(1300));
    add_money("copper",random(20));
    set_emotes(5,({
	"Riptide nods to you.",
	"%^BOLD%^%^CYAN%^Riptide whispers to you: %^RESET%^Simply motion to me and I shall assume the form of the mist and carry you back to the main part of the island",
	"%^BOLD%^%^CYAN%^Riptide whispers to you: %^RESET%^It is much safer there.",
	"Riptide turns and peers out into the river of flames."
      }) ,0);
}
void init() {
    ::init();
    add_action("motion_riptide", "motion");
}
int motion_riptide(string str) {
    write("%^BOLD%^You motion to Riptide and a large sailing ship appears before you.\n");
    say((string)this_player()->query_cap_name()+" motions to Riptide the Boatman.\n");
    write("Riptide pulls you aboard and the magical vessel begins it's journey across the River of Flame.\n");
    say((string)this_player()->query_cap_name()+"'s Vanishes onto a magical sailing ship.  It is consumed by flames and vanishes.\n");
    write("Riptide turns and looks at you eerily.\n");
    say((string)this_player()->query_cap_name()+"'s vessel stops here...  Riptide aboard his ship grins at Riptide aboard yours.\n");
    this_player()->move_player("/d/attaya/crossover2.c");
    return 1;
}
