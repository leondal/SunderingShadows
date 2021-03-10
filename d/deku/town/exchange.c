#include <std.h>
      
inherit ROOM;
      
void create() {
  ::create();
  set_light(2);
  set_indoors(1);
  set_terrain(WOOD_BUILDING);
  set_travel(DIRT_ROAD);
  set_short("Exchanger's Office");
  set_long(
@OLI
You are within the Verbobone Exchange.  Many villagers often
come here to invest their money in the natural resources that
the city produces.  This timber structure is finely furnished
with comfortable chairs.  There is a desk with a young man
looking to sell vouchers to you.  If you would like to buy
a voucher, type %^YELLOW%^<buy voucher>%^RESET%^.
There is a door to the north that obviously leads to an office.
OLI
     );
  set_smell("default","This room smells musty and sweaty.");
 set_listen("default"," ");
     set_exits((["north":"/d/deku/town/office1",
	"south":"/d/deku/town/road7"
]));
      set_items(([
"desk":"This desk is cluttered with papers.  A teller of sorts sits behind it.",
"chair":"These chairs look very comfortable."
        ] ));
	set_pre_exit_functions(({"north"}),({"guard"}));
    if(!present("teller"))
        find_object_or_load("/d/deku/monster/b_teller")->move(TO);
	if(!present("guard"))
        new("/d/deku/monster/bankguard")->move(TO);
}

void reset(){
 ::reset();
	if(!present("teller"))
        find_object_or_load("/d/deku/monster/b_teller")->move(TO);
	if(!present("guard"))
        new("/d/deku/monster/bankguard")->move(TO);
}

int guard(){
	if(present("guard")){
		write("The large guard blocks your passage.");
		write("He shakes his head angrily.");
		return 0;
	}
	return 1;
}
