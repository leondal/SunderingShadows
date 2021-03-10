//gcube.c

#include <std.h>

inherit MONSTER;

object room;

void create(){
	::create();
	
        set_name("gelatinous cube");
	set_id(({"cube","gelatinous cube","jelly"}));
set_short("%^RESET%^%^CYAN%^gelatinous cube%^RESET%^");
set_long("%^RESET%^%^CYAN%^This cube of %^RESET%^translucent ooze%^RESET%^%^CYAN%^ "+
	"is almost as wide as the sewer corridors it passes through. As it moves it sucks "+
	"up material, %^RESET%^%^BOLD%^bones%^RESET%^%^CYAN%^, %^RESET%^%^ORANGE%^rats"+
	"%^RESET%^%^CYAN%^, and anything else it can eat. You can see various things "+
	"still trapped within the ooze. It has no visible head or behind, and seems to "+
	"clean the sewers with a single mindedness, and you're in its way.%^RESET%^");
	set_hd(9,3);
	set_hp(40);
	set_funcs(({"my_hit"}));
	set_func_chance(102);
	set_overall_ac(3);
	set_exp(3000);
	add_money("gold",random(25));
	add_money("silver",random(25));
	add_money("electrum",random(25));
	add_money("copper",random(5));
        set_property("strength","electricity");
	set("aggressive",20);
	set_race("cube");
	add_limb("body","body",80,0,3);
	room = new("/d/tharis/obj/cuberoom");
}

void my_hit(object targ){
	
	if(random(20)+1 > (int)("daemon/bonus_d"->monster_thaco( TO->query_hd() ) )- (int)(targ->query_ac())){
		tell_room(environment(TO),"%^BOLD%^The gelatinous cube touches "+targ->query_cap_name()+"!",targ);
		tell_object(targ,"%^BOLD%^The cube touches you! It's acids eating at your skin!\n");
		targ->do_damage("torso",random(6)+2);
		if(!"daemon/saving_d"->saving_throw(targ, "paralyzation_poison_death",0)){
			targ->set_paralyzed(100,"You are paralyzed in the gelatinous cube");
			tell_object(targ,"%^BOLD%^%^YELLOW%^You are paralyzed by the cube's touch!\n");
			tell_room(environment(TO),"%^BOLD%^%^YELLOW%^"+targ->query_cap_name()+" is paralyzed by the cube!",targ);
			tell_object(targ,"%^BOLD%^%^YELLOW%^The cube overwhelms you and start digesting you.\n");
			tell_room(environment(TO),"%^BOLD%^%^YELLOW%^"+targ->query_cap_name()+" is overwhelmed by the cube",targ);
			if(interactive(targ))
				targ->move_player(room);
			else
				room->move_here(targ);
		}
	} else {
		tell_room(environment(TO),"%^BOLD%^The gelatinous cube misses "+targ->query_cap_name()+"!",targ);
		tell_object(targ,"%^BOLD%^The cube misses you\n");
	}
}
void heart_beat(){
	object *inven;
	int i,j;
   if(!objectp(room))         room = new("/d/tharis/obj/cuberoom");      
	if(query_hp() < 1) {
		if(room){
			inven = all_inventory(room);
			i = sizeof(inven);
			for(j = 0; j < i;j ++){
				if(interactive(inven[j])){
					tell_object(inven[j],"%^BOLD%^As the cube dies you fall to the ground... free!\n");
					inven[j]->move_player(environment(TO));
					inven[j]->add_exp(950);
				} else {
					inven[j]->move(environment(TO));
					tell_room(environment(TO),inven[j]->query_short()+" falls from the dying cube!");
				}
			}
			room->remove();
		}
	}
	::heart_beat();
    if(objectp(TO)&&objectp(ETO)){
	inven = all_inventory(environment(TO));
	i = sizeof(inven);
	for(j = 0; j<i;j++){
		if(inven[j] == TO) continue;
		else if(living(inven[j])) kill_ob(inven[j],1);
		else{
			tell_room(environment(TO),"%^BOLD%^The Cube consumes "+inven[j]->query_short()+"!");
			room->move_here(inven[j]);
		}
    }
	}

}

void clean_up() {return;}

void set_paralyzed(int time, string message){ return;}
