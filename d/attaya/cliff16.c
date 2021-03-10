
#include <std.h>

inherit "/d/attaya/spec/atemple";

void create(){
	::create();
    set_long(::query_long()+"%^RESET%^%^BOLD%^%^BLACK%^The long hall ends here. A tunnel cuts into the northern wall and climbs straight up into blackness! A large ornate %^BLACK%^d%^WHITE%^oorw%^BLACK%^a%^WHITE%^y%^BLACK%^ stands to the west. A %^BLACK%^w%^ORANGE%^ell %^ORANGE%^lit %^ORANGE%^i%^BLACK%^n%^ORANGE%^door %^ORANGE%^hallway%^BLACK%^ starts behind it. The columns here are replaced with totem poles displaying countless %^WHITE%^sk%^BLACK%^u%^BLACK%^l%^BLACK%^l%^WHITE%^s%^BLACK%^ that give you an eerie feeling in the dim light. The floor beneath you is littered with bones.%^RESET%^%^RESET%^
");
       set_exits(([
          "south":"/d/attaya/cliff15",
          "west":"/d/attaya/cliff55",
          "up":"/d/attaya/cliff17",
]));
}

void reset(){
	int num, i;
	::reset();
	
	if(!present("guardian")){
		num = random(4)+1;
		for(i=0;i<num;i++)
			new("/d/attaya/mon/guardian")->move(TO);
	}
	
}
