#include <std.h>
#include "../farm.h"
inherit CELLAR;
	void create(){ 
	::create();
	set_exits(([ "south" : ROOMDIR"cellar6",
			]));
}
void reset(){
   ::reset();
   if(!present("hildegard")){
      new(MON"hildegard")->move(TO);
   }
}
