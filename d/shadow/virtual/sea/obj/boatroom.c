//boatroom.c
// adding emotes to the room, last change was 4/22/03, *Styx 10/25/03

#include <std.h>
#define EOB environment(boat)
#define VALID_DIRECTIONS ({"west","east","north","south","dock","out"})

#define MSGS ({ "%^BOLD%^%^CYAN%^A brisk wind comes up and waves begin tossing the boat around.%^RESET%^",\
	"%^CYAN%^Heavy waves crash over the bow and the wooden frame creaks from the strain.%^RESET%^",\
	"%^BOLD%^%^CYAN%^A gust of wind carries a blast of spray across the deck and drenches you in the process.%^RESET%^",\
	"%^ORANGE%^You hear a dull thud against the hull. \n\nWas it some flotsam?\n%^GREEN%^A large sea creature?\n\n%^ORANGE%^Are you running aground?\n\n\n%^BOLD%^Or was it perhaps something else you haven't thought of yet...?%^RESET%^",\
	"%^YELLOW%^You catch a glimpse of another boat nearby and the inhabitants seem to be looking your direction.\n\nIs that a %^RED%^pirate flag %^YELLOW%^you see them flying?%^RESET%^",\
	"%^MAGENTA%^You feel a thud against the hull and notice an enormous snake-like form slip under the water just past the stern.%^RESET%^",\
	"%^BOLD%^Seagulls swoop about overhead, diving to the water from time to time.\n\n%^RESET%^One lands on the mast long enough to leave a %^BOLD%^%^BLACK%^messy deposit%^RESET%^ on the deck.",\
	"%^BLUE%^The waves seem to be rising and begin pounding the hull.\n\n%^BOLD%^Some break over the side and wash across the deck, nearly washing you overboard!%^RESET%^",\
	"%^GREEN%^The boat seems to be getting slowed by dense seaweed and kelp near the surface here.%^RESET%^",\
	"%^BOLD%^Winds begin gusting heavily and the rising waves toss the boat to and fro.  The undulations make it impossible to stand without a firm grip on something.%^RESET%^",\
	"%^GREEN%^The boat rocks erratically on the waves.%^RESET%^",\
	"%^BOLD%^%^CYAN%^A brief gust of wind dampens everything in sight with sea spray as the boat jostles on the waves.%^RESET%^" })

inherit ROOM;
object boat;
string owner;
//int y,x;
string room;
void move_random();

void init() 
{
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
   set_property("no sticks", 1);
   set_terrain(BOATS);
   set_travel(SLICK_FLOOR);
   set_short("The inside of a small transport");
   set_long(
@OLI
        %^BOLD%^%^CYAN%^This is a small ship%^RESET%^
        This is the main deck of a small ship that people use to traverse
        the waves of the Saakrune Sea.  The occasional sea gull screams as
        it flies over head.  Water splashes in your face as you attempt to
        travel to your destination.  There is a list of instructions here.
OLI
           );
   set_smell("default","The salt fresh air blows into your face.");
   set_listen("default","Your hear waves crashing against the side of the boat.");
   owner = "noone";
/* added light = 2  since as someone pointed out, boats would have reasonably natural outdoor light and owners would have lanterns to light also, but I'm not going to add that at this point  *Styx*  4/5/02
*/
   set_property("light", 2);
   set_property("night light",2); // Ditto.
   set_property("night_light",2); // Or was it this. I forget, - g.
}

int read(string str) {
   if(TP->query_unconscious()){
      TP->send_paralyzed_message("info",TP);
      return 1;
   }
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
   string file, place,where;
   int x,y;

    if(!objectp(boat)) 
	{
      	boat = new("/d/shadow/virtual/sea/obj/boat.c");
      	boat->move(room);
      	room->set_had_players((int)boat->query_had_players());
    }

   if(TP->query_bound() || TP->query_unconscious() || TP->query_paralyzed()){
      TP->send_paralyzed_message("info",TP);
      return 1;
   }
   file = base_name(EOB);
   if(!sscanf(file,"/d/shadow/virtual/sea/%s.dock",place)) {
      if((sscanf(file,"/d/%s/virtual/%d,%d.sea",where,y,x) != 3) &&
         (sscanf(file,"/d/%s/virtual/sea/%d,%d.sea",where,y,x) != 3)) {
         write("Your location is unknown please contact a wiz.");
      } else {
         switch (where) {
         case "shadow": 
            where = "Saakrune Sea";
            break;
         case "dagger":
            where = "Dagger Sea";
            break;
         }
         write("%^BOLD%^You are located at "+x+","+y+" on the "+where+".");
      }
      return 1;
   }
   write("%^BOLD%^You are currently docked at "+capitalize(place)+".");
   return 1;
}

int steer(string str) 
{
   	string *exits;
	if(!objectp(TP)) return 0;
   	if(!objectp(TO)) return 0;
	if(!stringp(room)) return 0;
	
	if(TP->query_bound() || TP->query_unconscious() 
	|| TP->query_tripped() || TP->query_paralyzed())
	{
      	TP->send_paralyzed_message("info",TP);
      	return 1;
   	}

   	if(owner != "noone" && (string)TPQN != owner)
	{
		tell_object(TP, "This is not your boat.  The crew will not respond to you.");
		return 1;
	}

    if(TP->query_property("shapeshifted"))
        return notify_fail("You can't do that while shapeshifted");

//return notify_fail("This boat is owned by "+capitalize(owner)+", the crew will not respond to //you.\n");

   	if(find_call_out("steering") != -1) return 1;
    if(!stringp(str))
    {
        tell_object(TP, "Steer in which direction?");
        return 1;
    }
   	str = lower_case(str);
   	if(member_array(str, VALID_DIRECTIONS) == -1)
      	return notify_fail("You can't sail in that direction!\n");
   	if(!objectp(boat)) 
	{
      	boat = new("/d/shadow/virtual/sea/obj/boat.c");
      	boat->move(room);
      	room->set_had_players((int)boat->query_had_players());
/* well, maybe not since it won't update, but leaving this until I'm sure it isn't something like this and just needs a check for room to be set....
  room is a string, not an object, so I suspect that was the cause of the bugs if the boat object or room was cleaned up *Styx* 1/2/04, last change 4/03
      boat->move(find_object_or_load(room));  // hopefully this will work better
*/
      //"/d/shadow/virtual/sea/"+y+","+x+".c");
   	}
	if(!objectp(EOB)) 
	{
		tell_object(TP, "The environment for your boat is messed up "+
		"tell Saide or bug report this directly.");
		return 1;
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

void steering(string str) 
{
   //string room;
   object roomob;
   string tmp;

   	if(!objectp(boat)) { return; }
   	if(!objectp(EOB)) 
	{
		tell_object(TO, "Apparently your boat no longer has "+
		"a valid environment.  Bug report this or let Saide "+
		"know.");
		return;
	}
  
   	switch(str) 
	{
   		case "west":
	      	//x -= 1;
	      	room = EOB->query_exit("west");
		      tmp = room;
      		//room = "/d/shadow/virtual/sea/"+y+","+x+".sea";
		      break;
   		case "east":
		     // x += 1;
		     // room = "/d/shadow/virtual/sea/"+y+","+x+".sea";
			room = EOB->query_exit("east");
		      tmp = room;
		      break;
		case "north":
			//  y -= 1;
			// room = "/d/shadow/virtual/sea/"+y+","+x+".sea";
     			room = EOB->query_exit("north");
     			tmp = room;
      		break;
   		case "south":
     			// y += 1;
      		room = EOB->query_exit("south");
      		tmp = room;
      		//room = "/d/shadow/virtual/sea/"+y+","+x+".sea";
      		break;
   		case "dock":
      		tmp = EOB->query_exit("dock");
      		break;
   		case "out":
      		tmp = room;
      		//room = "/d/shadow/virtual/sea/"+y+","+x+".sea";
   	}
	
   	if(!objectp(roomob = find_object_or_load(tmp)))
   	{
		tell_room(TO, "The "+str+" direction does not "+
		"lead to a valid room.  Please bug report this "+
		"or notify Saide.  Report %^BOLD%^%^CYAN%^"+
		str+"%^RESET%^ as the direction your boat "+
		"tried to move in your report.");
		return;
   	}

   	tell_room(EOB,"%^BOLD%^%^CYAN%^A boat sails "+str);
   	boat->move(roomob);
   	roomob->set_had_players((int)boat->query_had_players());
   
	tell_room(TO,"%^BOLD%^The boat sails "+str);

   	tell_room(TO,(string)environment(boat)->query_long()+
	"%^GREEN%^"+environment(boat)->query_smell("default")+
	"\n%^YELLOW%^"+environment(boat)->query_listen("default")+"\n");

   	tell_room(environment(boat),"%^BOLD%^%^YELLOW%^A boat enters the area.");
}

void set_boat(object ob) {
   boat = ob;
}
/*
void set_x(int i) {
   x = i;
}

void set_y(int i) {
   y = i;
}
*/

void reset() {
   ::reset();
// adding random messages & moving for more realism & fun *Styx* 1/2/04, last chg. 4/03
   if(random(3))
	tell_room(TO, MSGS[random(sizeof(MSGS))] );
   move_random();
}

void set_room(string str){
   room = str;
}
  
object query_boat() {return boat;}

int scan(string str) 
{
   if(TP->query_bound() || TP->query_unconscious() || TP->query_tripped()){
      TP->send_paralyzed_message("info",TP);
      return 1;
   }
    if(!objectp(boat)) 
    {
        boat = new("/d/shadow/virtual/sea/obj/boat.c");
      	boat->move(room);
      	room->set_had_players((int)boat->query_had_players());
    }
   tell_room(TO,(string)environment(boat)->query_long()+"%^GREEN%^"+environment(boat)->query_smell("default")+"\n%^YELLOW%^"+environment(boat)->query_listen("default")+"\n");
   return 1;
}

int lower(string str) {
   if(TP->query_bound() || TP->query_unconscious() || TP->query_tripped()){
      TP->send_paralyzed_message("info",TP);
      return 1;
   }

   if(TP->query_property("shapeshifted"))
       return notify_fail("You can't do that while shapeshifted");

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

   // and also this function to randomly toss them around *Styx*  1/2/04
void move_random() {
   string drift;
   string *exits;
   if(!objectp(TO))  return;
   if(!objectp(boat)) return;
   if(find_call_out("steering") != -1) return;//added to check if boat was already being steered during the reset.  This was causing the boats to wind up in a valid locations - Ares /12/22/04
   exits = EOB->query_exits();
   if(!sizeof(exits))  return;
   switch(exits[random(sizeof(exits))]) {
	case "out" : 	if(EOB->is_dock()) 
			   drift = "out";	break;
	case "dock" :				break;
	case "west" :	drift = "west";		break;
	case "east" :	drift = "east";		break;
	case "north":  	drift = "north";	break;
	case "south":  	drift = "south";	break;
	default: break;
   }
   if(!find_object_or_load(EOB->query_exit(drift))->is_virtual() || 
	!find_object_or_load(EOB->query_exit(drift))->is_water())
      return;
   if(drift && stringp(drift)) {
	tell_room(TO, "\n%^CYAN%^A very large wave tosses the boat around and it drifts off course.\n");
	steering(drift);
   }
   if(!random(3))  call_out("move_random", 5);
}