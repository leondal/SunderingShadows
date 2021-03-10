#include <std.h>
#include "../juran.h"

inherit "/std/fence";

create() {
   	::create();
    	set_name("Glitter");
    	set_id( ({ "monster","glitter","Glitter","shop keeper"}) );
    	set_short("Glitter, the fence");
   	set("aggressive", 0);
    	set_level(20);
   	set_long(
   		"Glitter is an ugly little goblin with uglier manners. He is "+
   		"dressed in a gaudy goblin fashion, but he seems to be decked "+
   		"out in a little more gold and gems than you have seen worn on "+
   		"one of his race.\n"+
        	"<help shop> will get you a list of shop commands.\n");
   	set_gender("male");
   	set_alignment(6);
   	set_class("thief");
   	set("race", "goblin");
   	set_body_type("humanoid");
  	set_size(1);
   	set_exp(100);
        set_property("no bump", 1);
    	set_hd(20);
      set_exp(100);
     	set_spoken("wizish");
     	remove_std_db();

}
