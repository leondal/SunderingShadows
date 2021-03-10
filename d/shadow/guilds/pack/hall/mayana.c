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
create() {
    ::create();
set_name("mayana");
 set_id( ({
"mayana", "officer"
 }) );
set("race", "elf");
 set_gender("female");
set("short",
"Mayana Vasquez, Product Control Officer"
 );
   set_long("
Mayana Vasquez, is the product control officer of the Shades of Death. She is a comely human. Her eyes are brown and they shine with a dark evil. Her long hair trails after her as she walks. She wears her guild ring proudly and is ever ready to defend the Pack from invasion.
");
 set_level( 30 );
set_property("swarm",1);
set_body_type("humanoid");
set("aggressive", 7);
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
set_exp(100000);
 set_max_sp(query_hp());
 set_sp(query_max_sp());
 add_money("silver",random(1300));
 add_money("copper",random(20));
        set_chats(2,({
"%^RED%^%^BOLD%^Mayana says:%^RESET%^ How can I help you fellow guild member?",
"%^BOLD%^%^BLUE%^Mayana grins very evilly!",
"%^MAGENTA%^Mayana calls on the spirits of evil to bless you.%^RESET%^",
}) ,0);
}
int no_kill(string str) {
    object targ;
    targ = this_player();
       command( "say You are pathetic,  "+this_player()->query_cap_name()+". ");
   write("%^BOLD%^%^BLUE%^!\n");
say((string)this_player()->query_cap_name()+" is surrounded by an aura of blue light.\n");
        return 1;
}
