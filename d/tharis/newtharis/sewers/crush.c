#include <std.h>
#include "../tharis.h"
inherit STORAGE"sewer";
int pried;

void create(){
	::create();
      set_property("no sticks", 1);
	set_property("light",0);
	set_property("indoors",1);
	set_property("no teleport",1);
      set_property("no phase",1);
      set_name("The crusher");
      set_short("%^BLUE%^A deep pit of water%^RESET%^");
      set_long("%^BLUE%^This is where the water has been rushing, as from all sides water tumbles down on you. "
"The west side has been barred with %^RESET%^great iron gates%^BLUE%^. The water, although deep enough "
"to drown an unconcious person, will not harm you. It's obvious you can't go north or south, as the %^ORANGE%^walls "
"%^BLUE%^are slick and smooth. You wonder if you will be able to force your way out of the pit, as the the weight of "
"the falling water is heavy. You notice as you wade around that the %^ORANGE%^floor %^BLUE%^echoes slightly even with "
"the muffling of several feet of water. Obviously a very large cavern is below this drain, perhaps a lake or river "
"where the waste goes.\n");
	set_listen("default","Your boots splash through the the water. You also hear murmurs from the town above.");
	set_smell("default","The smell of decay and refuse reach your nostrils.");

	set_items(([
		"walls":"%^ORANGE%^The walls are dark. They are covered with a surprisingly thin layer of slime.",
		"floor":"%^ORANGE%^The floor has a crevice in it. It looks like the floor might be in two pieces.",
		"crevice":"%^BLUE%^There is a crevice in the very middle of the floor. It looks as if you could try to pry the floor open! Who knows where that might lead you...",
		"gate":"They are so firmly attached you think you'd have an easier time going through the floor."
	]));
	call_out("crusher",120);
      set_search("floor","It seems a little odd to you that there is a crevice in the middle of the floor.");
}	

void reset(){
	::reset();
	pried = 0;
}

void init(){
	::init();
      if(pried) TP->move_player(SEWERS"fall1");
	tell_room(TO,"%^BOLD%^%^BLUE%^SPLASH!!!!!!!");
	add_action("fall","pry");
}

int GoThroughDoor(){
	string verb;
	verb = query_verb();
	
	tell_room(TO,"%^BOLD%^"+TPQCN+" struggles to climb out of the pit while the water slams into "+TP->QO+"!",TP);
	write("%^BOLD%^You struggle to climb out of the pit!");
	call_out("dis",4,TP);
	return 0;
}

void dis(object ob){
	tell_room(TO,"%^BOLD%^"+ob->query_cap_name()+" slips and lands back in the water!",ob);
	tell_object(ob,"%^BOLD%^You slip and fall back into the water!");
	tell_room(TO,"%^BOLD%^%^BLUE%^SPLASH");
}
	
int fall(string str){
	if(!str) return notify_fail("Pry what?\n");
	if(str != "floor" && str != "crevice" && str != "the floor" && str != "the floor open") return notify_fail("You can't pry that!\n");
	
	write("%^BOLD%^You begin to pry at the floor with whatever tools you can find!");
	tell_room(TO,"%^BOLD%^"+TPQCN+" starts prying at the floor with various tools!");
	call_out("budge",4,1);
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
			call_out("budge",3,n);
			break;
		case 2:
                  tell_room(TO,"%^BOLD%^A large gap is forming and you begin to see a ledge form in the floor!");
			n++;
			call_out("budge",3,n);
			break;
		case 3:
			tell_room(TO,"%^BOLD%^The floor slowly seems to be giving out!");
			n++;
			call_out("budge",3,n);
		case 4:
			tell_room(TO,"%^BOLD%^%^YELLOW%^THE FLOOR SUDDENLY OPENS WITH A CRASH!");
			tell_room(TO,"%^BOLD%^%^YELLOW%^YOU ARE SENT PLUMMETING DOWNWARD INTO THE DARK!!!");
			j = sizeof(inven);
			for(i = 0;i <j;i++){
				if(interactive(inven[i])) inven[i]->move_player(SEWERS"fall1");
                        else inven[i]->move(SEWERS"fall1");
			}
			pried = 1;
	}
}
	
void crusher(){
      if(!sizeof(all_living(TO)))  {
        call_out("crusher",120);
        return;
      }
	tell_room(TO,"%^BOLD%^You hear a loud %^GREEN%^CLICK%^WHITE%^.");
	call_out("next1",10);
}
	
void next1(){
	tell_room(TO,"%^BOLD%^You hear a low rumbling that shakes the room! The floor trembles under your feet, catching your attention.");
	call_out("next2",10);
}
	
void next2(){
	tell_room(TO,"%^BOLD%^You think that the room looks a little smaller!");
	call_out("next3",10);
}
	
void next3(){
	tell_room(TO,"%^BOLD%^SUDDENLY!!! %^CYAN%^   The north and south wall are closing in on you! Your foot catches on a crevice in the floor.");
	call_out("next4",10);
}
	
void next4(){
	tell_room(TO,"%^BOLD%^The trapped substances around you begin to pile up!");
	call_out("next5",10);
}
	
void next5(){
	tell_room(TO,"%^BOLD%^You feel your claustraphobia taking over! You try to tug your foot free of the crevice. Suddenly in your panic, it strikes you to try and pry the floor open!");
	call_out("next6",10);
}
	
void next6(){
	object *inven;
	int i,j;
	tell_room(TO,"%^BOLD%^The walls begin to squeeze you!!");
	inven = all_inventory(TO);
	j = sizeof(inven);
	for(i=0;i<j;i++){
            if(!objectp(inven[i])) continue;
		if(living(inven[i])){
                  if(inven[i]->query_true_invis()) continue;
			inven[i]->do_damage(inven[i]->return_target_limb(),random(10));
			inven[i]->add_attacker(TO);
			inven[i]->continue_attack();
		}
	}
	call_out("next7",15);
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
                  if(inven[i]->query_true_invis()) continue;
			inven[i]->do_damage(inven[i]->return_target_limb(),random(20));
			inven[i]->add_attacker(TO);
			inven[i]->continue_attack();
		}
	}
	call_out("next8",15);
}

void next8(){
	object *inven;
	int i,j;
	inven = all_inventory(TO);
	tell_room(TO,"%^BOLD%^You feel ribs breaking as the wall crushes you as it moves on its path!!");
	
	j = sizeof(inven);
	for(i=0;i<j;i++){
            if(!objectp(inven[i])) continue;
		if(living(inven[i])){
                  if(inven[i]->query_true_invis()) continue;
			inven[i]->do_damage(inven[i]->return_target_limb(),random(30));
			inven[i]->add_attacker(TO);
			inven[i]->continue_attack();
		}
	}
	call_out("next9",15);
}

void next9(){
	object *inven;
	int i,j;
	inven = all_inventory(TO);
	tell_room(TO,"%^BOLD%^%^RED%^You feel the life crushed out of you as the walls crush your heart and lungs!!");
	
	j = sizeof(inven);
	for(i=0;i<j;i++){
            if(!objectp(inven[i])) continue;
		if(living(inven[i])){
                  if(inven[i]->query_true_invis()) continue;
			inven[i]->do_damage(inven[i]->return_target_limb(),10000);
			inven[i]->add_attacker(TO);
			inven[i]->continue_attack();
		}
	}
	call_out("next10",15);
}

void next10(){
	object *inven;
	int i,j;
	inven = all_inventory(TO);
	tell_room(TO,"%^BOLD%^SUDDENLY, the room goes eerily still again as the walls slide back into place...");
	j = sizeof(inven);
	for(i=0;i<j;i++) {
        if(!objectp(inven[i])) continue;
        if(living(inven[i])) continue;
        inven[i]->move(SEWERS"cavern");
      }
	call_out("crusher",120);
}