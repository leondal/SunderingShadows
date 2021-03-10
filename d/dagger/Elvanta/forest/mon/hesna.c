
#include <std.h>
#include "/d/shadow/mon/melnmarn.h"
#include </d/antioch/areadefs.h>
inherit MONSTER;

	void init(){
	::init();
	add_action("stab_func", "stab");
	add_action("cast_func", "cast");
	add_action("throw_func", "throw");
}
create() {
   ::create();
set_name("hesna");
  set_id( ({
"hesna", "statue"
  }) );
set("race", "statue");
set_gender("male");
  set("short",
"A statue of a gnome, named Hesna"
     );
  set("long",
"%^RED%^Carved from garnet, a statue of a gnome sits upon a carved log.  He looks to be comfortable, peering at a map.  His name is Hesna, and he was know far and wide throughout the lands for his ability to track.  His face shows the wear and tear of many lifetimes upon it, laughter lines combine with scars, and a ready smile is marred by missing teeth.%^RESET%^");
	set_level(20);
  set_body_type("human");
  set("aggressive", 18);
  set_alignment( 50 );
  set_size( 2 );
set_stats("intelligence", 20);
set_stats("wisdom", 19);
set_stats("strength", 19);
set_stats("charisma", 14);
set_stats("dexterity", 20);
set_stats("constitution", 25);
   set_max_mp(0);
   set_mp(query_max_mp());
set_hd(25,1);
add_money("gold", 1000);
set_exp(2500);
set_hp(120);
set_max_hp(query_hp());
  set_max_sp(query_hp());
  set_sp(query_max_sp());
set_wielding_limbs( ({"right hand", "left hand"}) );
new(WEAPONDIR+"two_hand_sword")->move(this_object());
command("wield sword in right hand and left hand");
new("/d/dagger/Elvanta/forest/items/armor/mithril")->move(this_object());
command("wear armor");
}
void do_stuff(){
	if(interactive(TP)){
	set("aggressive", 18);
	call_out("attack", 5,TP);
}
}
int stab_func(string str){
	write("%^BOLD%^GREEN%^Hesna stonily looks up and glares!");
	return 1;
}
int cast_func(string str){
	write("%^BOLD%^GREEN%^Sparks fly from Hesna's eyes!");
	return 1;
}
int throw_func(string str){
	write("%^BOLD%^GREEN%^Hesna sits unyielding!");
	return 1;
}
