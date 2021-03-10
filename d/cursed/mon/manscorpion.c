#include "/d/shadow/mon/melnmarn.h";
inherit WEAPONLESS;

int thaco, ac, roll, hit, name;
create()
{
	::create();
		set_name("Manscorpion");
		set_id( ({"manscorpion", "scorpion", "man"}) );
		set_race("manscorpion");
		set_body_type("human");
		set_size(3);
		set_gender("male");
		set_class("fighter");
		set_short("A manscorpion");
		set_long(
@STOP
The manscorpion is part man and part scorpion.
He has a dark-skinned human torso, its abdomen is
protected by bony plates, and its ribs and backbone
protrude from the body.
STOP
);
		set_max_hp(96);
		set_hp(96);
		set_exp(4000);
		set_level(20);
		set_stats("strength",12);
		set_stats("intelligence",8);
		set_stats("wisdom",8);
		set_stats("dexterity",10);
		set_stats("constitution",10);
		set_stats("charisma",5);
		set("aggressive",5);
		set_alignment(6);
		set_attack_limbs(({"left claw","right claw","tail"}));
		set_overall_ac(5);
		set_funcs( ({"attack"}) );
		set_func_chance(100);
}


void attack(object targ)
	{
	 name=targ->query_cap_name();
	 ac=targ->query_ac();
	 thaco=13;
	 roll=random(20)+1;
	 hit= ac + roll;
	 if((hit >= thaco || roll == 20) && roll != 1){
		tell_object(targ,"%^BOLD%^%^RED%^Manscorpion scratches you"
			+" with his left claw.%^RESET%^");
		tell_room(environment(TO),"%^BOLD%^%^RED%^Manscorpion scratches "
			+name+ " with his left claw.%^RESET%^", targ);
		targ->cause_typed_damage(targ, targ->return_target_limb(), roll_dice(1, 4) + 1, "slashing");
	      }
	 if((hit < thaco || roll == 1) && roll != 20){
		tell_object(targ,"%^BOLD%^%^CYAN%^Manscopion misses you"
			+" with his left claw.%^RESET%^");
		tell_room(environment(TO),"%^BOLD%^%^RED%^Manscorpion misses "
			+name+ " with his right claw.%^RESET%^", targ);
		}
	 roll=random(20)+1;
	 hit = ac + roll;
	 if((hit >= thaco || roll == 20) && roll != 1){
		tell_object(targ,"%^BOLD%^%^RED%^Manscorpion scratches you"
			+" with his right claw.%^RESET%^");
		tell_room(environment(TO),"%^BOLD%^%^RED%^Manscorpion scratches "
			+name+ " with his right claw.%^RESET%^", targ);
		targ->cause_typed_damage(targ, targ->return_target_limb(), roll_dice(1, 4) + 1, "slashing");
	      }
	 if((hit < thaco || roll == 1) && roll != 20){
		 tell_object(targ,"%^BOLD%^%^CYAN%^Manscopion misses you"
			+" with his right claw.%^RESET%^");
		 tell_room(environment(TO),"%^BOLD%^%^RED%^Manscorpion misses "
			+name+ " with his right claw.%^RESET%^", targ);
		 }

	 roll=random(20)+1;
	 hit = ac + roll;
	 if((hit >= thaco || roll == 20) && roll != 1){
		tell_object(targ,"%^BOLD%^%^RED%^Manscorpion stings you"
			+" with his tail.%^RESET%^");
		tell_room(environment(TO),"%^BOLD%^%^RED%^Manscorpion stings "
			+name+ " with his tail.%^RESET%^", targ);
		targ->cause_typed_damage(targ, targ->return_target_limb(), roll_dice(1, 4), "piercing");
	     }
	 if((hit < thaco || roll == 1) && roll != 20){
		 tell_object(targ,"%^BOLD%^%^CYAN%^Manscopion misses you"
			+" with his tail.%^RESET%^");
		tell_room(environment(TO),"%^BOLD%^%^RED%^Manscorpion misses "
			+name+ " with his misses.%^RESET%^", targ);
		}
}
