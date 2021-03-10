//boat.c

#include <std.h>
#define DOCKS ([ "shadow":({36,0}), "deku":({16,20}), "laerad":({36,20}),\
              "hmquest":({16,45}), "attaya":({43,28}), "eldebaro":({51,7}),\
              "aramanth":({58,23}), "tonerra":({26,40}), "undead":({16,8}),\
              "argentrock":({10,34}), "dino":({20,30}), "pirate":({55,0}),\
              "dallyh":({13,22}) ])
inherit OBJECT;

object boat_room;
string owner;

void create()
{
  set_name("small boat");
  set_property("no animate",1);
  set_short("Small boat");
  set_id(({"boat","small boat","ship","small ship","rentboat","rent boat"}));
  set_long("This is a small boat for transporting players and materials");
  set_weight(100000);
  call_out("make_me",1);
  enable_commands();
  owner = "noone";
}

void init()
{
  ::init();
  add_action("board","board");
}

void set_inside(object room)
{ 
  boat_room = room;
}

object query_room() { return boat_room; }

int clean_up(){return 1;}

void make_me()
{
  string file, place;
  int x,y;
  if(!objectp(ETO))
    {
      call_out("make_me",1);
      return;
    }

  file = base_name(ETO);
  if(file[0..16] != "/d/shadow/virtual")
    TO->remove();
  seteuid(getuid(TO));
  if(!objectp(boat_room))
    {
      boat_room = new("/d/shadow/virtual/sea/obj/boatroom");
      boat_room->set_boat(TO);
    }
  if((sscanf(file,"/d/shadow/virtual/%d,%d.sea",y,x)) ||
     (sscanf(file,"/d/shadow/virtual/sea/%d,%d.sea",x,y)))
    {
      boat_room->set_x(x);
      boat_room->set_y(y);
    }
  else
    {
      if(sscanf(file,"/d/shadow/virtual/sea/%s.dock",place))
	{
	  if(member_array(place, keys(DOCKS)) != -1)
	    {
	      boat_room->set_x(DOCKS[place][1]);
	      boat_room->set_y(DOCKS[place][0]);
	    }
	  else
	    {
	      log_file("/d/shadow/virtual/sea/obj/new_docks",
		       "New dock found: "+place+"\n");
	      remove();
	    }
	}
    }	
}

int board(string str)
{
  if(!id(str)) return 0;
  tell_room(ETP,"%^BOLD%^"+TPQCN+" boards a small boat",TP);
  write("%^BOLD%^You board a boat");
  TP->move_player(boat_room);
  return 1;
}
	
void remove()
{
   if(objectp(boat_room)){
     if(present("player",boat_room)) return;
  }
  if(boat_room && objectp(boat_room))
    boat_room->remove();
  return ::remove();
}

void set_owner(string str)
{
  owner = str;
  add_id(str+"'s boat");
  
  boat_room->set_owner(str);
}

string query_owner()
{
  return owner;
}
