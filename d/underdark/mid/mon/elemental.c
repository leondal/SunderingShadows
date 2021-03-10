#include <std.h>
#include "../../defs.h"
inherit "/d/magic/mon/priest_eelemental.c";

int following;

void create(){
   ::create();
}

void init(){
   object ob;
   ::init();
   if(!following) {
     if(ob = present("svirfneblin priest",ETO)) {
       ob->add_follower(TO);
       ob->add_protector(TO);
       following = 1;
     }
   }
}
