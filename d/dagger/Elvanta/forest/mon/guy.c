
#include <std.h>
#include "/d/shadow/mon/melnmarn.h"
#include </d/antioch/areadefs.h>
inherit MONSTER;

void init() {
	::init();
	add_action("stab_func", "stab");
	add_action("cast_func", "cast");
	add_action("throw_func", "throw");
}
create() {
   ::create();
set_name("guy");
  set_id( ({
"guy", "statue"
  }) );
set("race", "statue");
set_gender("male");
  set("short",
"A statue of Guy, the great sword wielder"
     );
  set("long",
"%^BOLD%^GREEN%^A statue carved from the purest amber rests upon the green moss of these gardens.  Guy, the most sung of sword wielder is immortalized here, wielding his sword above his head, with a look of triumph upon his face.%^RESET%^");
	set_level(20);
  set_body_type("human");
  set("aggressive", 18);
  set_alignment( 50 );
  set_size( 2 );
     set_stats("intelligence", 14);
     set_stats("wisdom", 20);
	set_stats("strength", 25);
set_stats("charisma", 21);
	set_stats("dexterity", 20);
     set_stats("constitution", 22);
set_hd(25,1);
set_exp(1500);
add_money("gold", 1000);
set_hp(120);
set_max_mp(query_hd());
   set_mp(query_max_mp());
  set_max_hp(query_hd());
  set_max_sp(query_hp());
  set_sp(query_max_sp());
set_wielding_limbs( ({"right hand", "left hand"}) );
new(WEAPONDIR+"two_hand_sword")->move(this_object());
command("wield sword in right hand and left hand");
new("/d/dagger/Elvanta/forest/items/armor/mithril")->move(this_object());
command("wear armor");
}
void do_stuff() {
	if(interactive(TP)){
	set("aggressive", 18);
	call_out("attack", 5,TP);
}
}
int stab_func(string str){
	write("%^ORANGE%^Guy turns his head to glare at you");
	return 1;
}
int cast_func(string str){
	write("%^ORANGE%^The statue rotates towards you and glares");
	return 1;
}
int throw_func(string str){
	write("%^ORANGE%^The statue stands immovable");
	return 1;
}
