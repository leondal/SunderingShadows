#include "/d/shadow/mon/melnmarn.h"
#define SAVE_D "/daemon/saving_d.c"
inherit WEAPONLESS;

int thaco, ac, roll, hit;
string name, *limbs;
create()
{
	::create();
                set_name("gargantua");
                set_id( ({"gargantua", "reptile", "reptilian"}) );
                set_race("gargantua");
		set_body_type("human");
                set_size(4);
		set_gender("male");
		set_class("fighter");
                set_short("A Reptilian Gargantua");
		set_long(
@STOP
You look over a gigantic beast of unproportional
size and strength.  It hovers 100-200 feet tall.
You are astonished just by the mere sight of a beast
as massive as this.
STOP
);
                set_max_hp(400);
                set_hp(400);
                set_exp(43000);
		set_level(20);
                set_stats("strength",25);
                set_stats("intelligence",6);
		set_stats("wisdom",8);
		set_stats("dexterity",10);
                set_stats("constitution",25);
                set_stats("charisma",7);
		set("aggressive",5);
                set_alignment(8);
                set_overall_ac(2);

                set_attacks_num(3);
                set_damage((random(39)+1)+(random(55)+6));
                set_attack_limbs( ({"right claw","left claw"}) );
                set_funcs( ({"attack","trample","tail"}) );
                set_func_chance(100);
}


void attack(object targ)
	{
	 name=targ->query_cap_name();
	 ac=targ->query_ac();
         thaco=5;
	 roll=random(20)+1;
	 hit= ac + roll;
	 if((hit >= thaco || roll == 20) && roll != 1){
                tell_object(targ,"%^BOLD%^%^RED%^Reptilian Gargantua scratches you"
			+" with his left claw.%^RESET%^");
                tell_room(environment(TO),"%^BOLD%^%^RED%^Reptilian Gargantua scratches "
			+name+ " with his left claw.%^RESET%^", targ);
                targ->cause_typed_damage(targ, targ->return_target_limb(), roll_dice(1, 28) + 2, "slashing");
	      }
	 if((hit < thaco || roll == 1) && roll != 20)
                {tell_object(targ,"%^BOLD%^%^CYAN%^Reptilian Gargantua misses you"
			+" with his left claw.%^RESET%^");
                tell_room(environment(TO),"%^BOLD%^%^RED%^Gargantua misses "
			+name+ " with his left claw.%^RESET%^", targ);
		 }
	 roll=random(20)+1;
	 hit = ac + roll;
	 if((hit >= thaco || roll == 20) && roll != 1){
                tell_object(targ,"%^BOLD%^%^RED%^Gargantua scratches you"
			+" with his right claw.%^RESET%^");
                tell_room(environment(TO),"%^BOLD%^%^RED%^Gargantua scratches "
			+name+ " with his right claw.%^RESET%^", targ);
                targ->cause_typed_damage(targ, targ->return_target_limb(), roll_dice(1, 28) + 2, "slashing");
	      }
	 if((hit < thaco || roll == 1) && roll != 20)
		{tell_object(targ,"%^BOLD%^%^CYAN%^Manscopion misses you"
			+" with his right claw.%^RESET%^");
                 tell_room(environment(TO),"%^BOLD%^%^RED%^Gargantua misses "
			+name+ " with his right claw.%^RESET%^", targ);

		 }

	 roll=random(20)+1;
	 hit = ac + roll;
	 if((hit >= thaco || roll == 20) && roll != 1){  
                tell_object(targ,"%^BOLD%^%^RED%^Reptilian Gargantua"
                        +" bites you viciously!%^RESET%^");
                        
                tell_room(environment(TO),"%^BOLD%^%^RED%^Reptilian "
                        +"Gargantua bites "+name+"!%^RESET%^", targ);

                targ->cause_typed_damage(targ, targ->return_target_limb(), roll_dice(1, 55) + 5, "piercing");
		
	     }
	 if((hit < thaco || roll == 1) && roll != 20){
                tell_object(targ,"%^BOLD%^%^CYAN%^Reptilian Gargantua"
                        +" fails to bite you!%^RESET%^");
                 tell_room(environment(TO),"%^BOLD%^%^RED%^Reptilian Gargantua"
                        +" fails to bite " +name+ "!%^RESET%^", targ);
		}

         return;
	 
}

void trample(object targ)
{
        object *people=({}), current;
        int i;
        tell_room(ETO, "%^BOLD%^RED%^The reptilian gargantua"
             +" stands upright on its forelegs!%^RESET%^");
        
        for(i=0;i<sizeof(all_inventory(ETO));i++)
        {            
            current = all_inventory(ETO)[i];
            if( !living(current) || current == TO )
                continue;
            name=current->query_cap_name();
            if(!(SAVE_D->saving_throw(current,"paralyzation_poison_death")))
            {
               tell_room(environment(TO),"%^BOLD%^%^YELLOW%^The gargantua"
                   +" tramples over " +name+ "!%^RESET%^", current);
               tell_object(current, "%^BOLD%^%^YELLOW%^The gargantua tramples"
                   +" over you!");

               if (member_array(current, query_attackers()) < 0)
                   TO->kill_ob(current, 1);

               current->cause_typed_damage(current, current->return_target_limb(), roll_dice(1, 91) + 9, "bludgeoning");
            }
            else
            {
                 tell_room(environment(TO),"%^BOLD%^%^CYAN%^As the gargantua"
                        +" tramples through, " +name+ " dives out of the way"
                        +" just in time!%^RESET%^", current);
                 tell_object(current, "%^BOLD%^%^CYAN%^You see the gargantua"
                        +" trampling towards you!\nBut luckily for you,"
                        +" you were fortunate enough to get out of its"
                        +" path! %^RESET%^");
            }
  
        }
        return;
}

void tail(object targ)
{
    object *people=({}), current;
    int i;
    people=TO->query_attackers();
    tell_room(ETO,"%^BOLD%^%^RED%^The gargantua begins sweeping his"
        +" tail vicously!");
        for(i=0;i<sizeof(people);i++)
        {
            current = people[i];
            name=current->query_cap_name();
            if(!(SAVE_D->saving_throw(current,"paralyzation_poison_death")))
            {
                tell_room(ETO, "%^BOLD%^%^RED%^The gargantua's tail"
                        +" strikes " +name+ "!%^RESET%^", current);
                tell_object(current, "%^BOLD%^%^RED%^The gargantua strikes"
                        +" you with his tail!%^RESET%^");
                current->cause_typed_damage(current, current->return_target_limb(), roll_dice(1, 73) + 7, "bludgeoning");
            }
            else
            {
                tell_room(ETO, "%^BOLD%^%^YELLOW%^ " +name+ " jumps"
                        +" over the gargantua's tail as it sweeps"
                        +" underneath him!%^RESET%^", current);
                tell_object(current,"%^BOLD%^%^YELLOW%^You instinctively"
                        +" jump over the gargantua's tail as it sweeps"
                        +" under you!%^RESET%^");
            }
        }
        return;
}
