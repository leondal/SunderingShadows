#include <std.h>
#include "../undead.h"

inherit CREATURE;

object caught, stomach;

int cast;

void set_caught(object targ);

void create()
{
	::create();
	set_name("Behir");
	set_id(({"Behir","behir","monster","magical beast"}));
	set_short("A Behir");
	set_long("This is a long snake like creature. It has a dozen legs protruding from "
        "it's sinuous reptilian body. This crodilian-headed creature has a blue "
        "under-belly. There are two large horns bending over the head. The extremely "
        "hard scales are of a dusty blue color. An extremely fast animal. He lunges "
        "quickly to kill you.");
	set_overall_ac(4);
	set_hd(15,8);
	set_hp(300);
    set_exp(8000);
    set_new_exp(25,"normal");
    set("aggressive",19);
	set_size(4);
	set_funcs(({"attack"}));
	set_func_chance(50);
	set_race("behir");
	set_gender("male");
	set_body_type("snake");
    set_damage(1,8);
    set_attacks_num(6);
    set_base_damage_type("piercing");
    set_property("full attacks",1);
	add_limb("jaws","mouth",0,0,0);
	add_limb("leg 1","leg 1",0,0,0);
	add_limb("leg 2","leg 2",0,0,0);
	add_limb("leg 3","leg 3",0,0,0);
	add_limb("leg 4","leg 4",0,0,0);
	add_limb("leg 5","leg 5",0,0,0);
	add_limb("leg 6","leg 6",0,0,0);
	add_limb("leg 7","leg 7",0,0,0);
	add_limb("leg 8","leg 8",0,0,0);
	add_limb("leg 9","leg 9",0,0,0);
	add_limb("leg 10","leg 10",0,0,0);
	add_limb("leg 11","leg 11",0,0,0);
	add_limb("leg 12","leg 12",0,0,0);
    set_attack_limbs(({"jaws","leg 1","leg 2","leg 3","leg 4","leg 5","leg 6",
                       "leg 7","leg 8","leg 9","leg 10","leg 11","leg 12"}));
	set_property("swarm",1);
	set_stats("strenght",20);
	set_stats("dexterity",21);
	set_stats("intelligence",21);
	add_money("gold",random(150));
	cast = 0;
	stomach = new(MON"behir_stomach");
	stomach->set_owner(TO);
}

void attack(object targ)
{
    if(!cast)
    {
        tell_object(targ,"%^BOLD%^%^YELLOW%^A bolt of lightning shoots from the "
		    "Behir toward you!\n");
        tell_room(ETO,"%^BOLD%^%^YELLOW%^A 20' bolt of lightning "
		    "shoots from the Behir at "+targ->QCN+"!",targ);
        tell_room(ETO,"%^BOLD%^%^YELLOW%^The bolt slams into "+targ->QCN+"!",targ);
        tell_object(targ,"%^BOLD%^%^YELLOW%^The bolt slams into you!\n");

        if(ROLLSAVE(targ,SP))
        {
            set_property("magic",1);
		    targ->do_damage(targ->return_limb(),roll_dice(2,6));
            set_property("magic",-1);
            return;
        }

        set_property("magic",1);
        targ->do_damage(targ->return_limb(),roll_dice(4,6));
		set_property("magic",-1);
        cast = 1;
        call_out("reset_cast",60);
        return;
    }

    if(!random(20))
    {
        if(targ->query_size() < 3)
        {
		    tell_room(ETO,"%^BOLD%^%^RED%^The Behir rushes at "+targ->QCN+" and catches "
                ""+targ->QO+" off guard enough to swallow "+targ->QO+" "+targ->QO+" whole!",targ);
			tell_object(targ,"%^BOLD%^%^RED%^The Behir rushes at you and catches you in it's mouth!  "
				"It then manages to swallow you whole!\n");
            set_caught(targ);
            targ->move_player(stomach);
			tell_object(targ,"%^BOLD%^%^RED%^You feel that survival in here will not be long!\n");
			return;
		}


        if(caught)
        {
			if(targ != caught)
            {
                tell_object(caught,"%^BOLD%^The behir continues to squeeze the "
                    "spikes of it underbelly into you!!\n");
                tell_object(targ,"%^BOLD%^The Behir hisses at you as it continues to "
                    "squeeze "+caught->QCN+"!\n");
			    tell_room(ETO,"%^BOLD%^%^RED%^The behir continues to squeeze "
                    ""+caught->QCN+"!",caught);
            }
			caught->do_damage(caught->return_limb(),roll_dice(1,6));
			caught->do_damage(caught->return_limb(),roll_dice(1,6));
			caught->do_damage(caught->return_limb(),roll_dice(1,6));
			caught->do_damage(caught->return_limb(),roll_dice(1,6));
			caught->do_damage(caught->return_limb(),roll_dice(1,6));
			caught->do_damage(caught->return_limb(),roll_dice(1,6));
			tell_object(caught,"%^BOLD%^Having stabbed you the behir releases his grip!\n");
			tell_room(ETO,"%^BOLD%^"+caught->QCN+" is released by the behir!",caught);
			set_func_chance(0);
			execute_attack();
			set_func_chance(100);
			set_caught(0);
			return;
		}

		set_func_chance(0);
		execute_attack();

        if(!caught)	{ execute_attack(); set_func_chance(102); return; }
	}

}


void heart_beat()
{
	object *inven;
	int i,j;

	if(query_hp() < 1)
    {
		if(stomach)
        {
			inven = all_inventory(stomach);
			i = sizeof(inven);
			for(j = 0; j < i;j ++)
            {
				if(living(inven[j]))
                {
					tell_object(inven[j],"%^BOLD%^As the behir dies you fall from the stomach as friends cut the stomach open!\n");
					inven[j]->move_player(ETO);
					inven[j]->add_attacker(TO);
					TO->add_attacker(inven[j]);
				}
                else
                {
					tell_room(ETO,"%^BOLD%^"+inven[j]->query_short()+" falls from the stomach of the behir!");
					inven[j]->move(ETO);
				}
			}
			stomach->remove();
		}
	}
		::heart_beat();
}

void reset_cast()               { cast = 0; }

void set_caught(object targ)    { caught = targ; return; }
object query_caught()           { return caught;}
