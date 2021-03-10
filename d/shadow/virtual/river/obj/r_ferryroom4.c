// changed to inherit ferryroom3 so we don't have to dual maintain Travel() and Docking()
// should recode it so that can be based on settings but... another day *Styx* 10/11/05

#include <std.h>

#define DNSTREAM ({ "s", "se", "e","e","se","se","e","e","e","e","e","se","se","e","e", "se", "e","e","e","e","se", "e","e","e", "dock" })

#define UPSTREAM ({ "w", "w", "w", "nw", "w", "w", "w", "w", "nw", "w", "w", "nw", "nw", "w", "w", "w", "w", "w", "nw", "nw", "w", "w", "nw", "n", "dock" })

/*
Tharis to the ocean....
#define PATH3_S ({"e","e","e","e","e", "ne","e","e","e", "se", "e", "e", "e", "se", "e", "ne","e","e","se", "e","e","e","e", "e", "e", "e", "e", "e", "e", "e", "e", "e", "e", "e", "e", "e" })
*/

inherit "/d/shadow/virtual/river/obj/r_ferryroom3";

void create(){
   ::create();
   set_short("Tabor-Tharis River Ferry");
   set_exits(([]));
   add_exit("/d/shadow/virtual/river/tharis.dock","out");
   current = 34;
   vcurrent = 38;
   in_dock = 1;
   dir = "tabor";
   ferry = "/d/shadow/virtual/river/obj/riverferry4";
   remove_call_out("Travel");
   remove_call_out("Docking");
}

/********** removing the duplication I can't believe I left in... *Styx* 10/11/05
Travel() {
   string go_dir;
   remove_exit("out");
   ob = find_object_or_load(ferry);
   switch (dir) {
	case "tharis":
	   go_dir = DNSTREAM[nextdir];
	   do_loc(go_dir);
	   nextdir++;
	   if(go_dir == "dock") {
		nextdir = 0;
	        call_out("Docking",speed);
		return;
  	   }
	   break;
	case "tabor":
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
	   dir = "tharis";  
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
   	    dir = "tharis";
	    current = 11;
	    vcurrent = 30;
	    break;
      case "tharis":
	    ob->move("/d/shadow/virtual/river/tharis.dock");
	    add_exit("/d/shadow/virtual/river/tharis.dock","out");
            tell_room(TO,"%^BOLD%^%^GREEN%^Now docking north of Tharis.");
   	    dir = "tabor";
	    current = 34;
	    vcurrent = 38;
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