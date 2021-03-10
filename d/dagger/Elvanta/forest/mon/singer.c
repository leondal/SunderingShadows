//  Created by Demonforce, for ShadowGate
//  Coded on 27 Dec, 1995
//  Poet for Antioch Castle

#include <std.h>
#include </d/antioch/areadefs.h>
inherit MONSTER;

void init(){
	::init();
	add_action("cast_func", "cast");
	add_action("stab_func", "stab");
	add_action("throw_func", "throw");
add_action("yes", "yes");
add_action("no", "no");
}
create() {
   ::create();
set_name("singer");
set_id(({"singer", "a singer", "elf", "flute player"}));
set("race", "elf");
     set_gender("female");
set_short("A lovely elf");
set("long", "She sits here enchanting those who pass her by.\n");
  set_level(6);
  set_body_type("human");
set("aggressive", 1);
set_alignment(1);
  set_size(2);
set_stats("intelligence", 20);
set_stats("wisdom", 15);
set_stats("strength", 15);
set_stats("charisma", 12);
set_stats("dexterity", 20);
set_stats("consititution", 15);
set_hd(18,3);
set_hp(75);
set_exp(500);
  set_max_hp(query_hp());
add_money("silver",random(100));
add_money("copper",random(500));
  set_emotes(10, ({
"%^MAGENTA%^The poet says%^RESET%^: Do you like singing, or poems?"
    }), 0);
}
     int yes(string str) {
     write("Good, i'll sing you something.\n");
     write("It's called the golden bird.\n");
write("%^MAGENTA%^The poet sings%^RESET%^<%^RED%^come%^RESET%^> come little bird.  Don't be wounded don't be hurt.\n");
     write("I like that song.\n");
return 1;
}
     int no(string str) {
     write("%^MAGENTA%^The poet shouts%^RESET%^: It's you that is missing out, not me!\n");
return 1;
}
void do_stuff(){
	if(interactive(TP)){
	set("aggressive",18);
	call_out("attack",5,TP);
}
}
int stab_func(string str){
	write("%^RED%^The singer glares at you");
	return 1;
}
int cast_func(string str){
	write("%^RED%^The singer stops singing long enough to grin evilly at you");
	return 1;
}
int throw_func(string str){
	write("%^RED%^The singer continues to ignore you as much as possible");
	return 1;
}
