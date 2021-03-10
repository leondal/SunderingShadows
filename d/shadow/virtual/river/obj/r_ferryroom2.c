// just a second

#include <std.h>

#define DNSTREAM ({"s","s","s","se", "s","s","se","s","s","s","s","s","s", "s", "se", "s", "s", "se", "s", "s", "s","se","se","s","s","s","se","se", "se", "e", "se", "dock" })

#define UPSTREAM ({"nw","w","nw","nw", "nw","n","n","n","nw","nw","n","n", "n","nw", "n", "n", "nw", "n","n","n","n","n","n","n","nw","n","n","nw", "n", "n", "n", "dock" })

inherit "/d/shadow/virtual/river/obj/r_ferryroom1";

void create() {
   ::create();
   set_exits(([]));
   add_exit("/d/shadow/virtual/river/tabor.dock","out");
   current = 11;
   vcurrent = 30;
   in_dock = 1;
   dir = "shadow";
   ferry = "/d/shadow/virtual/river/obj/riverferry2";
   remove_call_out("Travel");
   remove_call_out("Docking");
}

/********** this is duplicated from the inherit, doh me.... *Styx* 10/11/05
 noticed it when I was speeding them up so let's get rid of it
Travel() {
   string go_dir;
   remove_exit("out");
   ob = find_object_or_load(ferry);
   switch (dir) {
	case "tabor":
	   go_dir = DNSTREAM[nextdir];
	   do_loc(go_dir);
	   nextdir++;
	   if(go_dir == "dock") {
		nextdir = 0;
	        call_out("Docking",speed);
		return;
  	   }
	   break;
	case "shadow":
	   go_dir = UPSTREAM[nextdir];
	   do_loc(go_dir);
	   nextdir++;
	   if(go_dir == "dock") {
		nextdir = 0;
	        call_out("Docking",speed);
		return;
  	   }
	   break;
	default:  // this is to set it back to base in case it gets bugged and reloaded
	   dir = "shadow";  
	   nextdir = 0;
	   call_out("Docking",1);
	   return;
   }
   in_dock = 0;
   tell_room(environment(ob),"%^BOLD%^%^YELLOW%^A ferry boat leaves the area.");
   ob->move(sprintf("/d/shadow/virtual/river/%d,%d.river",vcurrent,current));
   tell_room(TO,"%^BOLD%^%^MAGENTA%^The ferry sails along on the river headed "+exit_dir+".\n"
	   "%^BOLD%^%^YELLOW%^Beyond the ferry, you can see this:\n" );
   tell_room(TO,(string)environment(ob)->query_long()+
	   "%^GREEN%^"+environment(ob)->query_smell("default")+
	   "\n%^YELLOW%^"+environment(ob)->query_listen("default")+"\n");
   while(remove_call_out("Travel") != -1) 
      remove_call_out("Travel");
   call_out("Travel",speed);
}

Docking() {
    in_dock = 1;
    tell_room(environment(ob),"%^BOLD%^%^YELLOW%^A ferry boat leaves the area.");
  	tell_room(TO,"%^BOLD%^%^MAGENTA%^The ferry sails along on the river.\n"
	   "%^BOLD%^%^YELLOW%^Beyond the ferry, you can see this:\n" );
  	tell_room(environment(ob),"%^BOLD%^%^YELLOW%^A ferry boat enters the area.");
    switch (dir) {
      case "tabor":
	    ob->move("/d/shadow/virtual/river/tabor.dock");
	    add_exit("/d/shadow/virtual/river/tabor.dock","out");
	    tell_room(TO,"%^BOLD%^%^GREEN%^Now docking south of Tabor.");
   	    dir = "shadow";
	    current = 11;
	    vcurrent = 30;
	    break;
      case "shadow":
	    ob->move("/d/shadow/virtual/river/shadow.dock");
	    add_exit("/d/shadow/virtual/river/shadow.dock","out");
            tell_room(TO,"%^BOLD%^%^GREEN%^Now docking west of Shadow.");
   	    dir = "tabor";
	    current = 0;
	    vcurrent = 0;
	    break;
 
    }
    nextdir = 0;
    tell_room(environment(ob),"%^BOLD%^%^YELLOW%^A ferry boat enters the area.");
    tell_room(TO,(string)environment(ob)->query_long()+"%^RESET%^"
	"%^GREEN%^"+environment(ob)->query_smell("default")+"\n%^YELLOW%^"
	+environment(ob)->query_listen("default")+"\n");
    remove_call_out("Docking");
    call_out("Travel",60);
}
*/