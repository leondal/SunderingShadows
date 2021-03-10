#include <std.h>
inherit MONSTER;

void init() {
    ::init();
    add_action("no_kill","rush");
   add_action("no_kill","stab");
add_action("no_kill","steal");
   add_action("no_kill","con");
   add_action("no_kill","rebuke");
   add_action("no_kill","cast");
   add_action("no_kill","throw");
   add_action("no_kill","smash");

}
void create() {
    ::create();
set_name("soulman");
 set_id( ({
"soulman", "lucius", "proprietor"
 }) );
set("race", "human");
 set_gender("male");
set("short",
"Lucius Soulman, Funery Proprietor"
 );
   set_long("
Lucius Soulman, the  Proprietor of the Death Emporium, is always waiting to serve you. He has one slight problem tho..he is kind of slow because his body is gradually falling apart. He truly wishes he wasn't brought back to life. He has dedicated his life to helping others plan their TOTAL death.
");
 set_level( 30 );
set_property("swarm",1);
set_body_type("humanoid");
set("aggressive", 7);
   set_alignment( 8 );
   set_size( 2 );
    set_stats("intelligence", 25);
    set_stats("wisdom", 25);
    set_stats("strength", 24);
    set_stats("charisma", 15);
    set_stats("dexterity", 18);
    set_stats("constitution", 15);
    set_max_mp(500);
    set_max_hp(500);
    set_hp(1000);
set_exp(1000);
 set_max_sp(query_hp());
 set_sp(query_max_sp());
 add_money("silver",random(1300));
 add_money("gold",random(1000));
        set_emotes(2,({
"%^ORANGE%^Welcome to my humble store. Please feel free to look around...While you still have time!%^RESET%^",
"%^BOLD%^%^BLUE%^You notice bits of flesh hanging off of Soulman's face.%^RESET%^",
"%^MAGENTA%^Soulman says%^RESET%^: I have learned that Death isn't nearly as painful as life.",

}),0);

}
