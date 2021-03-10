

//monsters by the House of Svaha

#include <std.h>

inherit MONSTER;

void create() {
	::create();

set_name("giant tick");
set_id(({"giant tick", "tick"}));
set_short("giant tick");
set_long(
@DESC
%^ORANGE%^This gargantuan bug looks much the same as its smaller relative.
Sort of an oval body, jet black, with a detachable head, to burrow into 
your skin.  As the bug latches on to you a hollow mouthtube inserts into 
your skin, causing severe pain, and a certain amount of loss of blood
as the insect sucks your lifeblood away.
DESC
);

set_race("insect");
set_gender("female");
set_body_type("insect");
set_size(1);
set_class("fighter");
set("aggressive", 2);
set_alignment(5);
set_overall_ac(6);

set_stats("intelligence",5);
set_stats("wisdom", 5);
set_stats("strength",5);
set_stats("charisma",5);
set_stats("dexterity",5);
set_stats("constitution", 5);

set_hd(4,4);
set_exp(50);
set_hp(75);



add_money("silver", (100));
add_money("copper", (250));

}
void suck(object target) {
	int dam1;
	object me = this_object();
	object tar = me->query_current_attacker();
	tell_room(environment(target),"The tick sticks its mouthtube deeply into "+tar->query_possessive() +" flesh!");
	tell_object(tar,"The tick starts to suck out life giving blood.");
	dam1 = (roll_dice(2,8)+2);
	tar->cause_typed_damage(tar, tar->return_target_limb(), dam1, "piercing");
	return 1;
}

