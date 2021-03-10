//sewer22.c

#include <std.h>

inherit ROOM;

int pried;

void create(){
	::create();
    set_terrain(BUILT_TUNNEL);
    set_travel(SLICK_FLOOR);
    set_property("no sticks", 1);
	set_name("The crusher");
	set_property("light",0);
	set_property("indoors",1);
	set_property("no teleport",1);
	set("short","The sewers under Tharis");
	set("long",
@OLI
	%^BOLD%^%^YELLOW%^A drop pit%^RESET%^
This is where the water has been rushing. From all sides water rushes down 
on you. The east and west sides have been barred with great iron gates. The 
water, although deep enough to drown an unconcious person, will not harm 
you. It's obvious you can't go east or west. You wonder if you will be able
to force your way out of the pit with the force of the water. You notice as
you wade around that the floor echoes slightly even with the muffling of 
several feet of water. Obviously  very large cavern is below this drain.
Maybe a lake or river where the waste goes.
OLI
	);
	set_exits(([
		"south":"/d/tharis/Tharis/sewer24",
		"north":"/d/tharis/Tharis/sewer22"
		
		]));
	set_listen("default","Your boots splash through the the water."+
				"You also hear murmurs from the town above");
	set_smell("default","The smell of decay and refuse reach your nostrils");
	set_items(([
		"walls":"The walls are dark. They are covered with a surprisingly thin layer of slime.",
		"floor":"The floor has a crevice in it. It looks like the floor might be in two pieces",
		"crevice":"This crevice looks as if you pried at it it might open.",
		"gate":"They are so firmly attached you think you'd have an easier time going through the floor."
	]));
	set_pre_exit_functions(({"south","north"}),({"GoThroughDoor","GoThroughDoor"}));
	call_out("crusher",120);
}	

void reset(){
	::reset();
	pried = 0;
}

void init(){
	::init();
	if(pried) TP->move_player("/d/tharis/Tharis/fall1");
	tell_room(TO,"%^BOLD%^%^BLUE%^SPLASH!!!!!!!");
	add_action("fall","pry");
}

int GoThroughDoor(){
	string verb;
	
	verb = query_verb();
	
	tell_room(TO,"%^BOLD%^"+TPQCN+" struggles to climb out of the pit while the water slams into "+TP->query_objective()+"!",TP);
	write("%^BOLD%^You struggle to climb out of the pit!");
	call_out("dis",4,TP);
	return 0;
}

void dis(object ob){
	tell_room(TO,"%^BOLD%^"+ob->query_cap_name()+" Slips and lands back in the water!",ob);
	tell_object(ob,"%^BOLD%^You slip and fall back into the water!");
	tell_room(TO,"%^BOLD%^%^BLUE%^SPLASH");
	}
	
int fall(string str){
	if(!str) return notify_fail("Pry what?\n");
	if(str != "floor" && str != "crevice") return notify_fail("You can't pry that!\n");
	
	write("%^BOLD%^You begin to pry at the floor with whatever tools you can find!");
	tell_room(TO,"%^BOLD%^"+TPQCN+" starts prying at the floor with various tools!");
	call_out("budge",5,1);
	return 1;
}

void budge(int n){
	object *inven;
	int i,j;
	
	inven = all_inventory(TO);
	switch (n){
		case 1: 
			tell_room(TO,"%^BOLD%^The floor below you begins to creak!");
			n++;
			call_out("budge",4,n);
			break;
		case 2:
                       tell_room(TO,"%^BOLD%^A large gap is forming and you begin to see a ledge form in the floor!");
			n++;
			call_out("budge",4,n);
			break;
		case 3:
			tell_room(TO,"%^BOLD%^The floor slowly seems to be giving out!");
			n++;
			call_out("budge",4,n);
		case 4:
			tell_room(TO,"%^BOLD%^%^YELLOW%^THE FLOOR SUDDENLY OPENS WITH A CRASH!");
			tell_room(TO,"%^BOLD%^%^YELLOW%^YOU ARE SENT PLUMMETING DOWNWARD INTO THE DARK!!!");
			j = sizeof(inven);
			for(i = 0;i <j;i++){
				if(interactive(inven[i])) 
					inven[i]->move_player("/d/tharis/Tharis/fall1");
				else inven[i]->move("/d/tharis/Tharis/fall1");
			}
			pried = 1;
	}
}
	
void crusher(){
	tell_room(TO,"%^BOLD%^You hear a loud %^GREEN%^CLICK%^WHITE%^");
	call_out("next1",5);
	}
	
void next1(){
	tell_room(TO,"%^BOLD%^You hear a low rumbling that shakes the room!");
	call_out("next2",5);
	}
	
void next2(){
	tell_room(TO,"%^BOLD%^You think that the room looks a little smaller!");
	call_out("next3",5);
	}
	
void next3(){
	tell_room(TO,"%^BOLD%^SUDDENLY!!! %^CYAN%^   The north and south wall are closing in on you!");
	call_out("next4",5);
	}
	
void next4(){
	tell_room(TO,"%^BOLD%^The trapped substances around you begin to pile up!");
	call_out("next5",5);
	}
	
void next5(){
	tell_room(TO,"%^BOLD%^You feel your claustraphobia taking over!");
	call_out("next6",5);
	}
	
void next6(){
	object *inven;
	int i,j;
	tell_room(TO,"%^BOLD%^The walls begin to squeeze you!!");
	inven = all_inventory(TO);
	j = sizeof(inven);
	for(i=0;i<j;i++){
		if(living(inven[i])){
			inven[i]->do_damage(inven[i]->return_target_limb(),random(10));
			inven[i]->add_attacker(TO);
			inven[i]->continue_attack();
		}
	}
	call_out("next7",5);
}

void next7(){
	object *inven;
	int i,j;
	inven = all_inventory(TO);
	tell_room(TO,"%^BOLD%^The walls begin to crush with their force!!");
	
	j = sizeof(inven);
	for(i=0;i<j;i++){
       if(!objectp(inven[i])) continue;
		if(living(inven[i])){
			inven[i]->do_damage(inven[i]->return_target_limb(),random(20));
			inven[i]->add_attacker(TO);
			inven[i]->continue_attack();
		}
	}
	call_out("next8",5);
}

void next8(){
	object *inven;
	int i,j;
	inven = all_inventory(TO);
	tell_room(TO,"%^BOLD%^You feel ribs breaking as the wall crushes you as it moves on its path!!");
	
	j = sizeof(inven);
	for(i=0;i<j;i++){
		if(living(inven[i])){
			inven[i]->do_damage(inven[i]->return_target_limb(),random(30));
			inven[i]->add_attacker(TO);
			inven[i]->continue_attack();
		}
	}
	call_out("next9",5);
}

void next9(){
	object *inven;
	int i,j;
	inven = all_inventory(TO);
	tell_room(TO,"%^BOLD%^%^RED%^You feel the life crushed out of you as the walls crush your heart and lungs!!");
	
	j = sizeof(inven);
	for(i=0;i<j;i++){
		if(living(inven[i])){
			inven[i]->do_damage(inven[i]->return_target_limb(),10000);
			inven[i]->add_attacker(TO);
			inven[i]->continue_attack();
		}
	}
	call_out("next10",5);
}
void next10(){
	object *inven;
	int i,j;
	inven = all_inventory(TO);
	tell_room(TO,"%^BOLD%^SUDDENLY,!!");
	j = sizeof(inven);
	for(i=0;i<j;i++)
       {
       if (living(inven[i])) continue;
		inven[i]->remove();
       }
		
	call_out("crusher",120);
}

