#include <std.h>
#include "../tharis.h"
#define MESSAGE ({"The trap door flies upward by you!",\
  "You find yourself in a void, dark and nothing!",\
  "You hear water falling all around you.",\
  "The darkness consumes you.",\
  "You realize that there is nothing around you, %^ORANGE%^NOTHING!!",\
  "You fall DOWN!",\
  "DOWN!",\
  "     DOWN!",\
  "          DOWN!",\
  "               DOWN!!",\
  "You hear distantly below you the waters crashing into water.",\
  "You gradually feel other things falling past you!!",\
  "You hear a %^YELLOW%^ROOOAR%^RED%^!!!",\
  "A hungry ROAR of anticipation shakes the limbo you are in!",\
  "You feel the spray of other objects and debris."\
})
inherit ROOM;

int flag;

void create(){
    ::create();
    set_property("light",-10);
    set_property("indoors",1);
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("no sticks", 1);
    set_property("no attack",1);
    set_property("no teleport",1);
    set_name("A long drop");
    set_short("A long drop");
    set_long("You are falling!");
    set_exits(([]));
    set_items(([]));
}
	
void init(){
      ::init();
	write("%^BOLD%^%^YELLOW%^"+MESSAGE[0]);
	call_out("limbo",1,TP, 1);
}
	
void limbo(object ob, int flag){
      if(!objectp(ob)) return;
      if(TO != environment(ob)) return;
	if(flag < sizeof(MESSAGE)){
		tell_object(ob,"%^BOLD%^%^RED%^"+MESSAGE[flag]+"\n\n");
		flag++;
		call_out("limbo",2,ob,flag);
	}
	else ob->move_player(SEWERS"cavern");
}