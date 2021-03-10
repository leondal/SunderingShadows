
#include <std.h>

inherit "/d/attaya/spec/cliff2";

void create(){
	::create();
	set_name("Obsidian staircase.");
    set_long(::query_long()+"
You climb the small ladder and almost lose your balance. The %^BLACK%^statues%^WHITE%^ rise on either side of you now. You are almost level with their heads! Ledges lie above you and below you. The world seems to stretch out away from you in every direction as if you were its center. It is both a wonderful feeling, and a scary one.");
       set_exits(([
          "up":"/d/attaya/cliff72",
          "down":"/d/attaya/cliff34",
]));
	
set_items((["statues": "The tall female statues still seem to glare at you.  You half expect them to come to life and eat you or something nasty and unpleasant like that."]));
}

