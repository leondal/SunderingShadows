#include <std.h>
      
inherit VAULT;
      
void create() {
    vault::create();
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("no sticks", 1);
   set_property("no teleport",1);
    set_light(2);
    set_indoors(1);
    set_short("Exchanger's Office");
    set_long(
@OLI
	This is the exchange. Many people often come 
here to invest in the ores that the city produces. The room 
is finely furnished with comfortable chairs. There is a desk 
with a young man looking to sell you vouchers for the ore.
<buy voucher>
	There is a door to the south that obviously leads to 
some form of office. It is guarded by a large person carrying 
a club. Nobody seems to pay attention to anybody else in here.
OLI
     );
  set_smell("default","This room smells musty and sweaty.");
 set_listen("default"," ");
     set_exits((["south":"/d/tharis/Tharis/office1",
	         "north":"/d/tharis/Tharis/estreet1",
                 "west":"/d/tharis/Tharis/market7"
]));
      set_items(([
"desk":"This desk is cluttered with papers.  Behind it sits a teller of sorts.",
"chair":"These chairs look very comfortable."
        ] ));
set_door("door","/d/tharis/Tharis/market7","east",0);
set_pre_exit_functions(({"south"}),({"guard"}));
  }
 void reset(){
 ::reset();
	if(!present("teller"))
	new("/d/tharis/monsters/teller")->move(TO);
	if(!present("guard"))
	new("/d/tharis/monsters/eguard")->move(TO);
}
int guard(){
	if(present("guard")){
		write("The large, guard blocks your passage.");
		write("He shakes his head angrily");
		return 0;
	}
	else return 1;
}
