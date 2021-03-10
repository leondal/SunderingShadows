//slide1.c

#include <std.h>
#define MESSAGE ({"Your foot slips as you enter!",\
  "You begin sliding downward!",\
  "You hear Water falling all around you.",\
  "You feel you sodden body fall further",\
  "You hit a small ledge and bounce off!",\
  "You breath in water and start to sputter",\
  "COUGH!",\
  "COUGH!",\
  "COUGH!",\
  "You need air!",\
  "You gasp!",\
  "The dirty water tears at your eyes!",\
  "You hear distantly below you the waters crashing into something!",\
  "Your lungs burn!",\
  "Your heart hurts",\
  "You crash again into the wall!",\
  "Pain rushes through your whole body!",\
  "Below you, you hear the water rushing up at you."\
					})

inherit ROOM;

int flag;

void create(){
    set_terrain(BUILT_TUNNEL);
    set_travel(SLICK_FLOOR);
    set_property("no sticks", 1);
	set_property("light",-10);
	set_property("indoors",1);
  set_property("no attack",1);
  set_property("no teleport",1);
	set("short","The downward slide");
	set("long","If you are seeing this contact Tristan cuz somethings broke!");
	set_exits(([]));
	set_items(([]));
	}
	
void init(){
	write("%^BOLD%^%^YELLOW%^"+MESSAGE[0]);
	call_out("limbo",1,TP, 1);
	}
	
void limbo(object ob, int flag){
	if(flag < sizeof(MESSAGE)){
		tell_object(ob,"%^BOLD%^%^RED%^"+MESSAGE[flag]+"\n\n");
		flag++;
		call_out("limbo",2,ob,flag);
	}
	else 
		ob->move_player("/d/tharis/Tharis/slide2");
}
	
