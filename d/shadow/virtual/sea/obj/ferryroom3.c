#include <std.h>

inherit ROOM;
int in_dock,current, vcurrent;
string dir;
string *routes;
object ob;

int clean_up(){return 1;}


void create(){
    ::create();
  	set_indoors(0);
        set_name("ferryroom");
        set_property("no sticks", 1);
        set_terrain(BOATS);
        set_travel(SLICK_FLOOR);
	set_light(2);
 	set_short("A ferry boat.");
	set_long(
@MELNMARN
	%^BOLD%^You are on a ferry boat.%^RESET%^
There are two sailors who run the ferry. It
is a fair sized boat that can carry up to ten
passengers. The front of the boat is where
the passengers ride.
MELNMARN
);
	set_exits(([]));
        add_exit("/d/shadow/virtual/sea/undead.dock","out");
	set_smell("default","You smell the fresh ocean breeze.");
	set_listen("default","You hear the sounds of waves crashing against the ferry boat.");
        current = 8;
        vcurrent = 16;
	in_dock = 1;
       dir = "shadow";
	remove_call_out("Travel");
	remove_call_out("Docking");
}

void init(){
    ::init();
    if(wizardp(TP)) return;
    if(avatarp(TP) && TP->query_invis()) return;
    while(remove_call_out("Travel") != -1) remove_call_out("Travel");
  	call_out("Travel",60);
}

Travel(){
    object loc;
  	remove_exit("out");
  	ob = find_object_or_load("d/shadow/virtual/sea/obj/ferryboat3");

  	if(!in_dock){
	   switch (dir){
	   case "shadow":
	       if(current >= 1)
		  --current;
	       if(vcurrent <= 36)
		  ++vcurrent;
	       if(current < 1 && vcurrent > 36){
		   call_out("Docking",1);
		   return;
  	      	}
	      	break;
	    case "deku":
	       vcurrent--;
	       if(vcurrent < 16){
		  call_out("Docking",1);
		  return;
		  }
		  break;
	    case "laerad":
  		 current++;
       		 if(current > 20){
          	    call_out("Docking",1);
           	    return;
  		 }
		 break;
	   case "undead" :
	        current--;
		if(current < 8){
		   call_out("Docking",1);
		   return;
		}
		break;
	   }
	}
	in_dock = 0;
   	tell_room(environment(ob),"%^BOLD%^%^YELLOW%^A ferry boat leaves the area.");
  	ob->move(sprintf("/d/shadow/virtual/sea/%d,%d.sea",vcurrent,current));
  	tell_room(TO,"%^BOLD%^%^MAGENTA%^The ferry sails across the sea.\n%^BOLD%^%^YELLOW%^Beyond the ferry, you can see this:\n" );
  	tell_room(TO,(string)environment(ob)->query_long()+"%^GREEN%^"+environment(ob)->query_smell("default")+"\n%^YELLOW%^"+environment(ob)->query_listen("default")+"\n");
    while(remove_call_out("Travel") != -1) remove_call_out("Travel");
   	call_out("Travel",1);
}

Docking()
{
  	ob = find_object_or_load("d/shadow/virtual/sea/obj/ferryboat3");
    in_dock = 1;
    tell_room(environment(ob),"%^BOLD%^%^YELLOW%^A ferry boat leaves the area.");
  	tell_room(TO,"%^BOLD%^%^MAGENTA%^The ferry sails across the sea.\n%^BOLD%^%^YELLOW%^Beyond the ferry, you can see this:\n" );
  	tell_room(environment(ob),"%^BOLD%^%^YELLOW%^A ferry boat enters the area.");
      switch (dir){
      case "laerad":
	    ob->move("/d/shadow/virtual/sea/laerad.dock");
	    add_exit("/d/shadow/virtual/sea/laerad.dock","out");
	    tell_room(TO,"We are now docking on the island of Laerad.");
   	    dir = "deku";
	    current = 20;
	    vcurrent = 36;
	    break;
      case "deku":
		
	    ob->move("/d/shadow/virtual/sea/deku.dock");
	    add_exit("/d/shadow/virtual/sea/deku.dock","out");
            tell_room(TO,"We are now docking in the island of Deku.");
   	    dir = "undead";
	    current = 20;
	    vcurrent = 16;
	    break;
      case "undead":
	    ob->move("/d/shadow/virtual/sea/undead.dock");
     	    add_exit("/d/shadow/virtual/sea/undead.dock","out");
	    tell_room(TO,"We are now docking at the port of Sangri.");
 	    dir = "shadow";
   	    current = 8;
   	    vcurrent = 16;
	    break;
      case "shadow":
	    ob->move("/d/shadow/virtual/sea/shadow.dock");
     	    add_exit("/d/shadow/virtual/sea/shadow.dock","out");
       	    tell_room(TO,"We are now docking on the desert of Shadow.");
 	    dir = "laerad";
   	    current = 0;
	    vcurrent = 36;
}
   tell_room(environment(ob),"%^BOLD%^%^YELLOW%^A ferry boat enters the area.");
    tell_room(TO,(string)environment(ob)->query_long()+"%^GREEN%^"+environment(ob)->query_smell("default")+"\n%^YELLOW%^"+environment(ob)->query_listen("default")+"\n");

	remove_call_out("Docking");
   	call_out("Travel",60);
}


void set_dir(string str){dir = str;}

