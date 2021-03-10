//hangman_tree.c

#include <std.h>
#define ATTACK_LIMBS ({"vine 1","vine 2","vine 3","vine 4","vine 5","vine 6","vine 7","vine 8","vine 9"})
inherit WEAPONLESS;
object trunk;
int *hps;
mapping caught;
void make_me();
void init(){
	string *exits;
	int i,j;
	::init();
	
	exits = ETO->query_exits();
	
	j = sizeof(exits);
	for(i=0;i<j;i++)
		add_action("screw_over",exits[i]);
	
	
	if((string)TP->query_stats("charisma") < 18){
		if(!interactive(TP)) return 1;
               if(TO->query_invis()){
                       tell_room(ETO,"%^BOLD%^%^GREEN%^You see a Hangman tree rise from the forest and attack!");
                       TO->set_invis();
                }
               kill_ob(TP,1);
               }

}

void heart_beat(){
       if((object *)TO->query_attackers() == ({})){
               if(!query_invis()){
                       set_invis();
                       set_func_chance(80);
               }
       }
       ::heart_beat();
}

void create(){
        ::create();
        set_name("hangman tree");
        set_short("A gnarled hangman tree");
        set_id(({"tree","hangman","hangman tree","hangman_tree"}));
        set_long(
@OLI
        This gnarled old oak, has many long vines hanging from the heights
of its branches. You notice that there is a very sparce foliage, making
the tree look as if it's dying. You notice that the trunk opens at the
top where the gnarled limbs start to protrude. You remember stories your
mother told you about trees which eat flesh. You shiver to think about
what you might find in that hollowed trunk.
OLI
        );
        set_race("tree");
        add_limb("trunk","trunk",0,0,0);
    add_limb("right limb","trunk",0,0,0);
    add_limb("root","trunk",0,0,0);
    add_limb("left limb","trunk",0,0,0);
    add_limb("vine 1","trunk",0,0,0);
    add_limb("vine 2","trunk",0,0,0);
    add_limb("vine 3","trunk",0,0,0);
    add_limb("vine 4","trunk",0,0,0);
    add_limb("vine 5","trunk",0,0,0);
    add_limb("vine 6","trunk",0,0,0);
    add_limb("vine 7","trunk",0,0,0);
    add_limb("vine 8","trunk",0,0,0);
    add_limb("vine 9","trunk",0,0,0);
    set_attacks_num(3);
    set_overall_ac(3);
    set_attack_limbs(({"left limb","right limb"})+ATTACK_LIMBS);
    set_damage(1,3);
    make_me();
    set_stats("strength",14);
    set_funcs(({"attack"}));
    set_func_chance(102);
    trunk = new("/d/tharis/obj/trunk");
    trunk->set_owner(TO);
    caught = ([]);
    hps = allocate(10);
    set_invis();
    set_property("swarm",1);
   }


void make_me(){
        int i;

          i = random(200)+51;

        set_hd(i/6, 8);
        set_hp(i);
        set_exp(2000 + (6*i));
}

void die(object dohicky){
        object *inven;
        int i,j;

		if(!objectp(trunk)) return ::die(dohicky);
        inven = all_inventory(trunk);
        i = sizeof(inven);
        if(i){
                for(j = 0;j<i;j++){
                        inven[j]->move(ETO);
                        if(interactive(inven[j])){
                        	inven[j]->describe_current_room(1);
                        	add_attacker(inven[j]);
                        }
                  }
                trunk->remove();
        }
        tell_room(ETO,"%^BOLD%^As the hangman tree dies that which was contained inside falls to the ground!");
        return ::die(dohicky);

}

void attack(object targ){
        int i;
        string *vines, *tmp;

        set_func_chance(0);
        execute_attack();
        set_func_chance(102);
        if(random(20)+1 > (int)TO->Thaco(1,targ,0)){
              if(member_array(targ, keys(caught)) == -1){
                tell_room(ETO,"%^BOLD%^%^GREEN%^One of the vines manages to grasp "+targ->query_cap_name()+"!",targ);
                tell_object(targ,"%^BOLD%^%^GREEN%^              One of the vines manages to grasp you!");
                targ->do_damage(targ->return_target_limb(),3);
                vines = query_attack_limbs();
                i = random(sizeof(vines));
                tmp = vines;
                tmp -= ({vines[i]});
                caught[targ] = vines[i];
                call_out("do_damages",7, targ, 1, vines[i]);
              }
         }
}

void do_damages(object targ, int flag, string vine){
        string *vines, *tmp;
        if(!objectp(targ)) return;
        switch (flag) {
                case 1:
                        if(member_array(vine, query_limbs()) != -1 && present(targ->query_name(),ETO)){
                                tell_room(ETO,"%^BOLD%^%^GREEN%^The vine grasping "+targ->query_cap_name()+" starts to lift "+targ->query_objective()+" off the ground!",targ);
                                tell_object(targ,"%^BOLD%^%^GREEN%^You feel yourself being lifted from the ground!");
                                targ->do_damage(targ->return_target_limb(),3);
                                call_out("do_damages",7, targ, 2, vine);
                                return;
                        }
                        write("%^BOLD%^%^GREEN%^You fall as the vine holding you is severed!");
                        targ->remove_paralyzed();
                        map_delete(caught, targ);
                        return;
                        break;
                case 2:
                        if(member_array(vine, query_limbs()) != -1 && present(targ->query_name(),ETO)){
                                tell_room(ETO,"%^BOLD%^%^GREEN%^The vine grasping "+targ->query_cap_name()+" lifts "+targ->query_objective()+" further off the ground!",targ);
                                tell_object(targ,"%^BOLD%^%^GREEN%^You feel yourself being lifted further from the ground!");
                                targ->do_damage(targ->return_target_limb(),3);
                                call_out("do_damages",7, targ, 3, vine);
                                return;
                        }
                        write("%^BOLD%^%^GREEN%^You fall as the vine holding you is severed!");
                        map_delete(caught, targ);
                        targ->remove_paralyzed();
                        return;
                        break;
                case 3:
                        if(member_array(vine, query_limbs()) != -1 && present(targ->query_name(),ETO)){
                                tell_room(ETO,"%^BOLD%^%^GREEN%^The vine grasping "+targ->query_cap_name()+" lifts "+targ->query_objective()+" further off the ground!",targ);
                                tell_object(targ,"%^BOLD%^%^GREEN%^You feel yourself being lifted from the ground!");
                                targ->do_damage(targ->return_target_limb(),3);
                                call_out("do_damages",7, targ, 4, vine);
                                return;
                        }
                        write("%^BOLD%^%^GREEN%^You fall as the vine holding you is severed!");
                        map_delete(caught, targ);
                        targ->remove_paralyzed();
                        return;
                        break;
                case 4:
                        if(member_array(vine, query_limbs()) != -1 && present(targ->query_name(),ETO)){
                                tell_room(ETO,"%^BOLD%^%^GREEN%^The vine grasping "+targ->query_cap_name()+" has taken "+targ->query_objective()+" dangerously close to that trunk!",targ);
                                tell_object(targ,"%^BOLD%^%^GREEN%^You feel worry on how close to the trunk you have gotten!");
                                targ->do_damage(targ->return_target_limb(),3);
                                call_out("do_damages",7, targ, 5, vine);
                                return;
                        }
                        write("%^BOLD%^%^GREEN%^You fall as the vine holding you is severed!");
                        map_delete(caught, targ);
                        targ->remove_paralyzed();
                        return;
                        break;
                case 5:
                        if(member_array(vine, query_limbs()) != -1 && present(targ->query_name(),ETO)){
                       	 		map_delete(caught, targ);
                                tell_room(ETO,""+targ->query_cap_name()+" is dropped roughly into the hollowed trunk!",targ);
                                tell_object(targ,"You are dropped into the hollowed out trunk of the tree to be digested!");
                                targ->remove_paralyzed();
                                targ->move(trunk);
                                vines = query_attack_limbs();
                                vines += ({vine});
                                set_attack_limbs(vines);
                                return;
                        }
                        write("%^BOLD%^%^GREEN%^You fall as the vine holding you is severed!");
                        map_delete(caught, targ);
                        targ->remove_paralyzed();
                        return;
                        break;
        }
}

int do_damage(string limb, int damage){
        int num;
        string thing, *vines;
        
        if(member_array(TP, keys(caught)) != -1 && random(100) < 50)
        	limb = caught[TP];
        if(limb[0..3] == "vine"){
                if(sscanf(limb,"%s %d",thing, num) != 2)
                        return ::do_damage(limb, damage);
                else {
                        hps[num] += damage;
                        if(hps[num] > 24){
                                tell_room(ETO,"One of the vines is severed!");
                                remove_limb(limb);
                                vines = query_attack_limbs();
                                if(member_array(limb, vines) != -1){
                                        vines -= ({limb});
                                        set_attack_limbs(vines);
                                }
                        }
                }

                return 5;
         }
         return ::do_damage(limb, damage);
}


int screw_over(string str){
	if(member_array(TP,keys(caught) )!= -1){
		write("%^BOLD%^%^GREEN%^You struggle futilely against the vines!");
		tell_room(ETO,"%^BOLD%^%^GREEN%^"+TPQCN+" struggles to get loose of the vines!",TP);
		return 1;
	}
	return 0;
}

int kill_ob(object victim, int which){
	object *inven;
	int i,k;
	if(!swarm){
  	if(victim == TP && interactive(TP)){

           swarm = 1;
                inven = all_inventory(environment(TO));
                k = sizeof(inven);
                for(i=0;i<k;i++){
                        if(living(inven[i])){
			    if((string)inven[i]->query_stats("charisma") < 18){
                            	 if(inven[i] != TP)
                                 inven[i]->kill_ob(TP,1);
                             }
                        }
                }
        }
        swarm = 0;
     }
     if(query_invis())
     	set_invis();
	return ::kill_ob(victim,which);
}

int test_heart(){ return 1;}
