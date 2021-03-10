
#include <std.h>
#define MESSAGE ({"%^BOLD%^%^BLUE%^You plunge into the waters and they tear at your limbs!",\
  "You are being pulled in four directions at once.",\
  "You are being pulled down deeper.",\
  "%^BOLD%^%^BLUE%^You need air.",\
  "You surface briefly and take a gasp of air..",\
  "The darkness looms ahead.",\
  "%^BLUE%^You go over a waterfall into blackness!",\
  "It is completely dark and you are falling in a veil of stinging water.",\
  "You feel weightless, and all at once have a hundred tons of water bearing down on you.",\
  "%^RED%^You feel your body slam against a slippery wall.",\
  "Your legs go numb.",\
  "The water has changed direction and is flowing like a river again.",\
  "You see the glimers of light ahead in the water.",\
  "%^YELLOW%^You break through and see the beautiful sky again!",\
  "%^BOLD%^%^BLUE%^And the ocean about three HUNDRED feet below you.",\
  "You shut your eyes as you freefall with the waterfall into the ocean.",\
  "The surface closes in on you in seconds!",\
  "%^BLUE%^You pass out.",\
  "",\
  "",\
  "",\
   "%^RESET%^After an unknown period of time you open your eyes and find yourself on the beach.",\
})

inherit "/d/attaya/tower/spec/tower";

int flag;

void create(){
    ::create();
	set_property("light",-4);
	set_property("indoors",1);
  set_property("no attack",1);
  set_property("no teleport",1);
	set("short","The life passes in front of your eyes");
       set_long("
%^BOLD%^%^BLUE%^Water is all around you!
");
set_listen("default", "The water is deafening as it crashes around you and carries you into silence.");
	set_exits(([]));
        set_items(([
]));
}
	
void init(){
	write("%^BOLD%^%^YELLOW%^"+MESSAGE[0]);
	call_out("fire",1,TP, 1);
	}
	
void fire(object ob, int flag){
	if(flag < sizeof(MESSAGE)){
		tell_object(ob,"%^BOLD%^%^RED%^"+MESSAGE[flag]+"\n\n");
		flag++;
		call_out("fire",3,ob,flag);
	}
	else 
		ob->move_player("/d/attaya/beach22");
}
	
