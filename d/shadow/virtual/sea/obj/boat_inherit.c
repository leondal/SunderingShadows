//changing this over to a boat inherit file - hopefully should mean that fixing 
//any bugs in the future are about a 1000 times easier - Saide, December 2016.

#include <std.h>
#define SHADOW_SEA "/d/shadow/virtual/sea/"+
#define DAGGER_SEA "/d/dagger/virtual/sea/"+
#define DOCKS ([ "shadow":SHADOW_SEA "36,0.sea",\
  "deku":SHADOW_SEA "16,20.sea",\
  "laerad":SHADOW_SEA "36,20.sea",\
  "hmquest":SHADOW_SEA "16,45.sea",\
  "attaya":SHADOW_SEA "43,28.sea",\
  "eldebaro":SHADOW_SEA "51,7.sea",\
  "dallyh":SHADOW_SEA "13,22.sea",\
  "aramanth":SHADOW_SEA "58,23.sea",\
  "tonerra":SHADOW_SEA "26,40.sea",\
  "undead":SHADOW_SEA "16,8.sea",\
  "torm":DAGGER_SEA "5,1.sea",\
  "ovadexel":SHADOW_SEA"46,21.sea",\
  "argentrock":SHADOW_SEA "10,34.sea",\
  "dino":SHADOW_SEA "20,30.sea",\
  "raiders":DAGGER_SEA "20,19.sea",\
  "pirate":SHADOW_SEA "55,0.sea",\
  "tonovi":DAGGER_SEA "10,3.sea",\
  "coralsea":SHADOW_SEA "62,8.sea",\
  "spring":SHADOW_SEA "50,50.sea",\
  "fall":SHADOW_SEA "65,35.sea",\
  "winter":SHADOW_SEA "2,19.sea",\
   "rilynath":SHADOW_SEA "49,0.sea",\
"ice":SHADOW_SEA "16,30.sea",  ])

inherit OBJECT;
object boat_room;
string owner;

void create() {
   ::create();  // can't think of a good reason it shouldn't.... *Styx* 2/20/05
   set_name("small boat");
   set_property("no animate",1);
   set_short("Small boat");
   set_id(({"boat","small boat","ship","small ship"}));
//   set_long("This is a small boat for transporting players and materials.");
//description change by Circe 9/16/04 in response to a typo report that
//it should be more IC
   set_long("This boat appears sea-worthy despite its small size.  "+
      "It is manned by a small crew of sailors who take orders "+
      "from the owner alone.  It may be used to transport "+
      "people and goods across the sea.");
   set_weight(100000);
   call_out("make_me",1);
   owner = "noone";
}

void init() {
   ::init();
   add_action("board","board");
}

void set_inside(object room) {
   boat_room = room;
}

object query_room() {return boat_room;}

int clean_up() {return 1;}

void make_me() 
{
   string file, place;
   int x,y;
   if(!objectp(ETO)) {
      call_out("make_me",1);
      return;
   }

   file = base_name(ETO);
   if(file[0..16] != "/d/shadow/virtual" && file[0..16] != "/d/dagger/virtual") 
   {
      TO->remove();
      return;
   }
   seteuid(getuid(TO));

// removing the old exit since it's now at a new place per bug reports *Styx* 2/20/05
   if(objectp(boat_room))
      boat_room->remove_exit("gangplank");

   if(!objectp(boat_room)) {
      boat_room = new("/d/shadow/virtual/sea/obj/boatroom");
      boat_room->set_boat(TO);
   }
   /*
   if((sscanf(file,"/d/shadow/virtual/%d,%d.sea",y,x)) ||
      (sscanf(file,"/d/shadow/virtual/sea/%d,%d.sea",x,y))) {
      boat_room->set_x(x);
      boat_room->set_y(y);
   }
   else
   */
   if(sscanf(file,"/d/shadow/virtual/sea/%s.dock",place)) {
      if(member_array(place, keys(DOCKS)) != -1) {
         //boat_room->set_x(DOCKS[place][1]);
         //boat_room->set_y(DOCKS[place][0]);
         boat_room->set_room(DOCKS[place]);
      }
      else {
         log_file("/d/shadow/virtual/sea/obj/new_docks",
                  "New dock found: "+place+"\n");
         remove();
      }
   }
   else {
      boat_room->set_room(file);
   }
}

int board(string str) 
{
    if(!objectp(TP)) return 0;
    if(!stringp(str))
    {
        tell_object(TP, "Board what?");
        return 1;
    }
    if(!id(str))
     if (TO != present(str,ETO))
       return 0;
    tell_room(ETP,"%^BOLD%^"+TPQCN+" boards a small boat.",TP);
    write("%^BOLD%^You board a boat.");
    TP->move_player(boat_room);
    return 1;
}

void remove()
{
   if(objectp(boat_room)) {
      if(present("player",boat_room)) return;
   }
   if(boat_room && objectp(boat_room))
      boat_room->remove();
   return ::remove();
}

void set_owner(string str) {
   owner = str;
   add_id(str+"'s boat");

   boat_room->set_owner(str);
}

string query_owner() {
   return owner;
}

int id(string str){
    string name;
    int i = ::id(str);
    if (i) return i;
    if (sscanf(str, "%s's boat",name) == 1){
      name = TP->realName(name);
      return ::id(name+"'s boat");
     }
     return i;
}
