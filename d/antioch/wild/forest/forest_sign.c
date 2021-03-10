//  Created by Grolim, for ShadowGate
//  Coded 13 April, 1995
//  Forest around Antioch

#include <std.h>
inherit OBJECT;

int get() { 
    if(query("get sign")) write(query("get sign"));
    return 0;
}

void create() {
  ::create();
  set_name( "sign" );
  set_id( ({"sign"}) );
  set_short( "A sign" );
  set_long(
	"The sign says:\n"
	"  Turn back stranger!  You will find nothing\n"
	"  but death in here!  If you are a mighty\n"
	"  warrior and think that you can free the\n"
	"  forest from the horrors in it we will\n"
	"  be forever grateful to you, but\n"
	"  remember that you have been warned!\n"
    );
  set_weight(10000);
}
