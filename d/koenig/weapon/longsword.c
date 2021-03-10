#include <std.h>
inherit "/std/weapon";

create() {
    ::create();
   set_id(({ "sword", "longsword", "long sword", "long" }));
   set_name("long");
   set_short("A long sword");
   set_long(
	"This is a shiny, well kept long sword. "
   );
   set_weight(4);
   set_size(2);
   set("value", 15);
   set_wc(1,8);
   set_large_wc(1,12);
   set_type("slash");
   set_wield( (: TO, "test" :) );
   set_unwield( (: TO, "test" :) );
   set_hit("The Sword slices hard!.");
   set("read", "Can you read this?");
}

int test(string str){
    return "testing 1.....2.......3.......5...";
}

