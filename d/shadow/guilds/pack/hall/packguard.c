#include <std.h>
inherit MONSTER;

void init() {
    ::init();
    add_action("no_kill","rush");
   add_action("no_kill","stab");
   add_action("no_kill","kill");
   add_action("no_kill","con");
   add_action("no_kill","rebuke");
   add_action("no_kill","cast");
   add_action("no_kill","throw");
   add_action("no_kill","smash");

}
create() {
    ::create();
set_name("dartanion");
 set_id( ({
"dartanion", "guardian"
 }) );
set("race", "undead");
 set_gender("male");
set("short",
"Dartanion the guardian of the Shades of Death"
 );
   set_long("
    Dartanion is a ten foot tall phantom warrior.  He looks down upon you with furious anger in his expression.  Dartanion is the sworn guardian of the Shades of Death and will allow no others to cross this bridge.
");
 set_level( 99 );
set_body_type("humanoid");
set("aggressive", 1);
   set_alignment( 9 );
   set_size( 2 );
    set_stats("intelligence", 25);
    set_stats("wisdom", 25);
    set_stats("strength", 24);
    set_stats("charisma", 25);
    set_stats("dexterity", 18);
    set_stats("constitution", 25);
    set_max_mp(500);
    set_max_hp(6000);
    set_hp(100000);
set_spell_chance(99);
set_spells(({
"chill touch",
"dispel magic",
"magic missile",
"freeze"
}));
    set_mp(query_max_mp());
set_exp(1);
 set_max_sp(query_hp());
 set_sp(query_max_sp());
 add_money("silver",random(1300));
 add_money("copper",random(20));
        set_emotes(40,({
     "Dartanion mumbles to the ancient spirits of evil..",
     "Dartanion raises his hands to the sky.",
     "%^RED%^Your heartrate picks up.",
}) ,1);
}
int no_kill(string str) {
    object targ;
    targ = this_player();
       command( "say You are pathetic,  "+this_player()->query_cap_name()+". ");
   write("%^BOLD%^%^BLUE%^Dartanion casts a spell and an aura of blue light surrounds you!\n");
say((string)this_player()->query_cap_name()+" is surrounded by an aura of blue light.\n");
write("You are magically teleported somewhere.\n");
this_player()->move_player("/d/shadow/room/city/forkroad.c");
        return 1;
}
