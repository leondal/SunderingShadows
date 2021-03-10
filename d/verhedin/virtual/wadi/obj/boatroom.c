//boatroom.c for Verhedin

#include <std.h>
#define EOB environment(boat)
#define VALID_DIRECTIONS ({"west","east","north","south","dock","out"})

inherit ROOM;
object boat;
string owner;
//int y,x;
string room;

void init() {
   ::init();
   add_action("steer","steer");
   add_action("location","location");
   add_action("read","read");
   add_action("scan","scan");
   add_action("lower","lower");
}

void create() {
   ::create();
   set_name("boatroom");
   set_light(2);
   set_short("The inside of a small transport");
   set_long(
@OLI
%^BOLD%^This is a small Tsarvani ship%^RESET%^
  This is the main deck of a small ship that people use to traverse
the waves of the Tsarvani waterways. Water splashes in your face
you give your orders to the crew.
  There is a list of instructions here that you can read.
OLI
           );
   set_smell("default","The fresh air blows into your face");
   set_listen("default","Your hear waves lapping against the side of the boat.");
   owner = "noone";
}

int read(string str) {
   if(!str || (str != "list" && str != "instructions"))
      return 0;

   write(
@OLI
  steer <direction>   ----  Will steer the boat in that direction
  steer dock will enter a dock
  steer out will leave a dock
  location   -------------  Will give you the location of the boat
  scan    ----------------  Will show you what's around the boat
  lower gangplank --------  Will lower the gangplank at any dock
OLI
        );
  return 1;
}

int location(string str) {
   string file, place,where,blah;
   int x,y;

   file = base_name(EOB);
   if((sscanf(file,"/d/%s/virtual/wadi/%s.dock",blah,place)) < 2) {
      if((sscanf(file,"/d/%s/virtual/%d,%d.wadi",where,x,y) != 3) &&
         (sscanf(file,"/d/%s/virtual/wadi/%d,%d.wadi",where,x,y) != 3)) {
         write("Your location is unknown please contact a wiz.");
      } else {
         switch (where) {
         case "verhedin":
            where = "Wadi al-Emir";
            break;
         case "tsarven":
            where = "Bay of Serenity";
            break;
         }
         write("%^BOLD%^You are located at "+x+","+y+" on the "+where+".");
      }
      return 1;
   }
   write("%^BOLD%^You are currently docked.");
   return 1;
}

int steer(string str) {
   string *exits;

   if(owner != "noone")
      if((string)TPQN != owner)
         return notify_fail("This boat is owned by "+
		 capitalize(owner)+",the crew will not respond to you.\n");
   if(find_call_out("steering") != -1) return 1;
   str = lower_case(str);
   if(member_array(str, VALID_DIRECTIONS) == -1)
      return notify_fail("You can't sail in that direction!\n");
   if(!objectp(boat)) {
      boat = new("/d/verhedin/virtual/wadi/obj/boat.c");
      boat->move(room);
   }
   exits = EOB->query_exits();
   if(member_array(str, exits) == -1 && str != "out")
      return notify_fail("You can't sail in that direction, no ocean!\n");
   if(str == "out" && !EOB->is_dock())
      return notify_fail("You can't sail in that direction!\n");
   if(EOB->is_dock() && str != "out")
      return notify_fail("You must sail out of the dock first!\n");
   tell_room(TO,"%^BOLD%^%^CYAN%^"+TPQCN+" steers the ship "+str,TP);
   write("%^BOLD%^%^CYAN%^You steer the ship "+str);
   remove_exit("gangplank");
   call_out("steering",2,str);
   return 1;
}

void steering(string str) {
   object roomob;
   string tmp;

   switch(str) {
   case "west":
      room = EOB->query_exit("west");
      tmp = room;
      break;
   case "east":
      room = EOB->query_exit("east");
      tmp = room;
      break;
   case "north":
     room = EOB->query_exit("north");
     tmp = room;
      break;
   case "south":
      room = EOB->query_exit("south");
      tmp = room;
      break;
   case "dock":
      tmp = EOB->query_exit("dock");
      break;
   case "out":
      tmp = room;
   }
   roomob = find_object_or_load(tmp);
   tell_room(EOB,"%^BOLD%^%^CYAN%^A boat sails "+str);
   boat->move(roomob);
   tell_room(TO,"%^BOLD%^The boat sails "+str);

tell_room(TO,(string)environment(boat)->query_long()+"%^GREEN%^"+
    environment(boat)->query_smell("default")+"\n%^YELLOW%^"+
    environment(boat)->query_listen("default")+"\n");
    tell_room(environment(boat),"%^BOLD%^%^YELLOW%^A boat enters the area.");
}

void set_boat(object ob) {
   boat = ob;
}
void set_room(string str){
   room = str;
}

object query_boat() {return boat;}

int scan(string str) {

tell_room(TO,(string)environment(boat)->query_long()+"%^GREEN%^"+
          environment(boat)->query_smell("default")+
          "\n%^YELLOW%^"+environment(boat)->query_listen("default")+"\n");

   return 1;
}

int lower(string str) {
   if(!str || str != "gangplank") return notify_fail("Lower what?\n");

   if(EOB->is_dock()) {
      tell_room(TO,"%^BOLD%^The gangplank has been lowered!");
      add_exit(base_name(EOB),"gangplank");
   }
   else
      return notify_fail("You can't do that in the middle of the ocean!\n");
   return 1;
}

void set_owner(string str) {
   owner = str;
}

string query_owner() {return owner;}

void clean_up() {return 1;}

