#include <std.h>
inherit MONSTER;

void init(){
	::init();
	add_action("stab_func", "stab");
}

void create(){
	int resist;
	::create();

set_name("foo lion");
set_id(({"foo", "foo lion", "lion", "Foo Lion"}));
set_race("foo");
set_gender("female");
set_short("foo lion");
set_long("%^YELLOW%^This is a foo lion.  It has a large blunt head with wide-set bulging eyes and a huge outh with large fangs.  The body appears rather leonine with a long bush tipped tail.  The hind legs are canine-like but the front legs appear more lion-like.  The fur upon the foo lion is a tawny brown with a large mane and a tail of black.");
	set_level(22);
	set_body_type("quaduped");
	set_class("fighter");
	set("aggressive", 10);
	set_alignment(7);
	set_size(2);
	set_overall_ac(-1);
set_stats("intelligence", 18);
set_stats("wisdom", 18);
set_stats("strength", 18);
set_stats("charisma", 20);
set_stats("dexterity", 25);
set_stats("consititution", 25);
	set_hd(22,11);
	set_hp(100);
	set_max_hp(query_hp());
resist = 55 + random(30) + random(30);
set_property("magical resistance", resist);
set_exp(500);
add_money("gold", (250));
}
int stab_func(string str){
	write("%^YELLOW%^A deep roar issues from the open jaws of the maddened Foo Lion!");
	return 1;
}
