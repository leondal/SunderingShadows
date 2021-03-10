//slide1.c

#include <std.h>
#define MESSAGE ({"The trapped door flies upward by you!",\
  "You find yourself in a void, dark and nothing!",\
  "You hear Water falling all around you.",\
  "The darkness consumes you.",\
  "You realize that There is nothing around you, %^ORANGE%^NOTHING!!",\
  "You fall DOWN!",\
  "DOWN!",\
  "     DOWN!",\
  "          DOWN!",\
  "               DOWN!!",\
  "                     DOWN!!",\
  "                           DOWN!",\
  "You hear distantly below you the waters crashing into water",\
  "You gradually feel other things falling past you!!",\
  "You hear a %^YELLOW%^ROOOAR%^RED%^!!!",\
  "A hungry ROAR of anticipation shakes the limbo you are in!",\
  "You feel the spray of other objects and debris."\
					})

inherit ROOM;

int flag;

void create(){
// ::create() and ::init() were missing - it bugged so I'm putting them in *Styx* 12/31/02
        ::create();
	set_property("light",-10);
	set_property("indoors",1);
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("no sticks", 1);
   set_property("no attack",1);
   set_property("no teleport",1);
	set("short","The downward slide");
	set("long","If you are seeing this contact Tristan cuz somethings broke!");
	set_exits(([]));
	set_items(([]));
	}
	
void init(){
        ::init();
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
		ob->move_player("/d/tharis/Tharis/cavern");
}
	
