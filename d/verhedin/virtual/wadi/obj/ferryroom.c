#include <std.h>
#define EOB environment(boat)
#define VALID_DIRECTIONS ({"west","east","north","south","dock","out"})
#define START_DOCK "/d/verhedin/virtual/wadi/nabat.dock"
#define BOAT "/d/verhedin/virtual/wadi/obj/nabatferry"

inherit ROOM;

void steering(string str);
void Travel();
void make_room();

int in_dock,current,wait;
string dir;
string *routes;
object ob;

object boat;
string room;
string *path;

int clean_up(){return 1;}

void create(){
  ::create();
    set_indoors(0);
    set_light(2);
    set_short("A ferry boat");
    set_long(
@MELNMARN
%^BOLD%^You are on a ferry boat%^RESET%^
  There are two sailors who run the ferry. It
is a fair sized boat that can carry up to ten
passengers. The front of the boat is where
the passengers ride.
MELNMARN
);
    set_smell("default","You smell the fresh ocean breeze.");
    set_listen("default","You hear the sound of the river lapping against the ferry boat.");
	make_room();
}

void make_room() {
	set_exits(([]));
	boat = find_object_or_load(BOAT);
    current = 0;
    in_dock = 1;
	add_exit(START_DOCK,"out");
    while(remove_call_out("Travel") != -1) remove_call_out("Travel");
}

void init(){
    ::init();
    if(wizardp(TP)) return;
    if(avatarp(TP) && TP->query_invis()) return;
    while(remove_call_out("Travel") != -1) remove_call_out("Travel");
}

void Travel(){
  int repeat;
  string direction;
  
  wait = 0;
  if(sscanf(path[current], "%d%s", repeat, direction) == 2) {
    while(repeat--) {
//      tell_object(find_player("thorn"), "\nSteering to the "+direction+"\n");
	  steering(direction);
	}  
  }
  else {
//    tell_object(find_player("thorn"), "\nSteering to the "+path[current]+"\n");
  	steering(path[current]);
  }
  current++;
  if(current >= sizeof(path)) { current = 0; }
  if(in_dock) { add_exit(base_name(EOB), "out"); }
  if(wait) {
//    tell_object(find_player("thorn"), "\nWaiting...\n");
    while(remove_call_out("Travel") != -1) remove_call_out("Travel");  	
  	call_out("Travel",60);
  }
  else {
    while(remove_call_out("Travel") != -1) remove_call_out("Travel");  	
  	call_out("Travel",5);
  }
  return;
}

void steering(string str) {
   object roomob;
   string tmp;

   switch(str) {
   case "west":
   case "w":
      room = EOB->query_exit("west");
	  dir = "west";
      tmp = room;
      break;
   case "east":
   case "e":
      room = EOB->query_exit("east");
      tmp = room;
	  dir = "east";
      break;
   case "north":
   case "n":
     room = EOB->query_exit("north");
     tmp = room;
      break;
   case "south":
   case "s":
      room = EOB->query_exit("south");
	  dir = "south";
      tmp = room;
      break;
   case "dock":
   case "d":
	  tmp = EOB->query_exit("dock");
	  dir = "into the dock";
	  in_dock = 1;
      tell_room(TO,
	    "%^MAGENTA%^BOLD%^The ferryman shouts:%^RESET%^We will be docking shortly.");
      break;
   case "out":
   case "o":
	  tmp = room;
	  TO->set_exits(([]));
	  dir = "out of the dock";
      tell_room(TO,
	    "%^MAGENTA%^BOLD%^The ferryman shouts:%^RESET%^We are now leaving dock!");
	  in_dock = 0;
	  break;
   case "wait":
   case "t":
      wait = 1;
      tell_room(TO,
	    "%^MAGENTA%^BOLD%^The ferryman shouts:%^RESET%^We will be waiting here for a minute.");
      return;
   }

   roomob = find_object_or_load(tmp);
   tell_room(EOB,"%^BOLD%^%^CYAN%^A ferryboat sails "+dir);
   boat->move(roomob);
   tell_room(TO,"%^BOLD%^Outside the ferry you see:");

   tell_room(TO,(string)environment(boat)->query_long()+"%^GREEN%^"+
     environment(boat)->query_smell("default")+"\n%^YELLOW%^"+
     environment(boat)->query_listen("default")+"\n");
   tell_room(environment(boat),"%^BOLD%^%^YELLOW%^A ferryboat enters the area.");
}

object query_boat() { return boat; }

void set_path(string *arg) {
	path = arg;
    make_room();
	call_out("Travel",1); 	
	return;
}

void set_room(string str) {
	room = str;
}
