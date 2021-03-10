// ferry for inland river by Styx 5/2003
// Shadow - shadow.dock (0,0)  "northeast":"/d/shadow/room/forest/road16" 
// Tharis - tharis.dock (34,37)  "northeast":"/d/tharis/road/road7"
// Tabor - tabor.dock (11,30) "east":"/d/darkwood/tabor/road/road2"
// Bridge north of Tabor - /d/shadow/room/forest/road55
// Note - changes here to Travel() or Docking() also need made in r_ferryroom3
// Changed speed from 4 to 3 and made descr. only show up randomly *Styx* 10/11/05

#include <std.h>

#define DNSTREAM ({"s","s","s","se", "s","s","se","s","s","s","s","s","s", "s", "se", "s", "s", "se", "s", "s", "s","se","se","s","s","s","se","se", "se", "e", "se", "dock" })

#define UPSTREAM ({"nw","w","nw","nw", "nw","n","n","n","nw","nw","n","n", "n","nw", "n", "n", "nw", "n","n","n","n","n","n","n","nw","n","n","nw", "n", "n", "n", "dock" })

inherit ROOM;
int in_dock, current, vcurrent, nextdir, speed;
string dir, exit_dir, ferry;
//string *upstream, *dnstream;
object ob;

int clean_up() {return 0;} // return 0 should keep it from being called again too *Styx*

void create(){
   ::create();
   set_indoors(0);
   set_name("ferryroom");
   set_property("no sticks", 1);
   set_terrain(BOATS);
   set_travel(SLICK_FLOOR);
   set_light(2);
   set_short("Shadow-Tabor river ferry");
   set_long("%^BOLD%^You are on a river ferry boat%^RESET%^\n"
	"There are two sailors who run the ferry.  This is a fair-sized "
	"somewhat flat-bottomed boat designed for inland river travel.  "
	"It can carry several passengers.  The front of the boat is "	
	"where the passengers ride."
   );
   set_exits(([]));
//   write("ferryroom1 euid before add_exit = "+geteuid());
   add_exit("/d/shadow/virtual/river/shadow.dock","out");
   set_smell("default","You smell damp wood and the sweaty sailors.");
   set_listen("default","You hear the sounds of water lapping against the hull.");
   current = 0;
   vcurrent = 0;
   in_dock = 1;
   dir = "tabor";
   remove_call_out("Travel");
   remove_call_out("Docking");
   speed = 3;
   ferry = "/d/shadow/virtual/river/obj/riverferry1";
}


void init() {
   ::init();
//   write("ferryroom1 euid in init = "+geteuid());
//   if(!objectp(TP)) 		return;
   if(TP->query_true_invis()) 	return;
   if(!in_dock)			return;
/*   ob = find_object_or_load(ferry);
   switch( base_name(environment(ob)) ) {
      case "/d/shadow/virtual/river/tabor.dock" :
	dir = "shadow";
	break;
      case "/d/shadow/virtual/river/shadow.dock" :
	dir = "tabor";
	break;
      default:
	current = 0;
 	vcurrent = 0;
	dir = "shadow";
	call_out("Docking",1);
	return;
   }
    while(remove_call_out("Travel") != -1) 
	remove_call_out("Travel");
*/
    if(find_call_out("Travel") == -1)
       call_out("Travel",60);
}

int do_loc(string go_dir) {
  switch(go_dir) {
    case "s" :  vcurrent = vcurrent+1;	
		exit_dir = "south";	break;
    case "e" :  current =  current+1;	
		exit_dir = "east";	break;
    case "w" :  current =  current-1;	
		exit_dir = "west";	break;
    case "n" :  vcurrent = vcurrent-1;	
		exit_dir = "north";	break;
    case "nw":  vcurrent = vcurrent-1;
	        current =  current-1;	
		exit_dir = "northwest";	break;
    case "se":  vcurrent = vcurrent+1;
	        current =  current+1;	
		exit_dir = "southeast";	break;
    case "sw":  vcurrent = vcurrent+1;
	        current =  current-1;	
		exit_dir = "southwest";	break;
    case "ne":  vcurrent = vcurrent-1;
	        current =  current+1;	
		exit_dir = "northeast";	break;
    default: break;
  }
  return exit_dir;
}

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
   tell_room(TO,"%^BOLD%^%^MAGENTA%^The ferry sails along on the river headed "+exit_dir+".\n");
   if(random(2)) {
       tell_room(TO,"%^BOLD%^%^YELLOW%^Beyond the ferry, you notice this:\n" );
       tell_room(TO,(string)environment(ob)->query_long()+
	   "%^GREEN%^"+environment(ob)->query_smell("default")+
	   "\n%^YELLOW%^"+environment(ob)->query_listen("default")+"\n");
   }
   while(remove_call_out("Travel") != -1) remove_call_out("Travel");
   call_out("Travel",speed);
}

Docking() 
{
    if(!objectp(ob))
    {
        ob = find_object_or_load(ferry);
    }
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
    call_out("Travel",45);
}
