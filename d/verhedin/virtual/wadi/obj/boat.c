// boat.c for Verhedin

#include <std.h>

#define WADI_AL_EMIR "/d/verhedin/virtual/wadi/"+
#define DOCKS ([ "nabat":WADI_AL_EMIR "0,2.wadi",\
                 "quay":WADI_AL_EMIR"9,4.wadi",\
                 "verhedin":WADI_AL_EMIR "11,1.wadi", \
                 "cove1":WADI_AL_EMIR "4,3.wadi", \
                 "cove2":WADI_AL_EMIR "14,4.wadi", \
                 "ninor":WADI_AL_EMIR "20,1.wadi", \
                 "chainhouse1":WADI_AL_EMIR "8,2.wadi", \
                 "chainhouse2":WADI_AL_EMIR "11,3.wadi", \
                 "chainhouse3":WADI_AL_EMIR "12,1.wadi", \
                 "pargineast":WADI_AL_EMIR "15,4.wadi",\
                 "parginwest":WADI_AL_EMIR "16,1.wadi" ])

inherit OBJECT;

object boat_room;
string owner;

void create() {
   set_name("small Tsarvani boat");
   set_property("no animate",1);
   set_short("Small Tsarvani boat");
   set_id(({"boat","small boat","ship","small ship", "tsarvani boat"}));
   set_long("This is a small Tsarvani boat of for transporting players and materials");
   set_weight(100000);
   call_out("make_me",1);
   enable_commands();
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

void make_me() {
   string file, place;
   int x,y;
   if(!objectp(ETO)) {
      call_out("make_me",1);
      return;
   }

   file = base_name(ETO);
   if(file[0..18] != "/d/verhedin/virtual")
      TO->remove();
   seteuid(getuid(TO));
   if(!objectp(boat_room)) {
      boat_room = new("/d/verhedin/virtual/wadi/obj/boatroom");
      boat_room->set_boat(TO);
   }
   if(sscanf(file,"/d/verhedin/virtual/wadi/%s.dock",place)) {
      if(member_array(place, keys(DOCKS)) != -1) {
         boat_room->set_room(DOCKS[place]);
      }
      else {
         log_file("/d/verhedin/virtual/wadi/obj/new_docks",
                  "New dock found: "+place+"\n");
         remove();
      }

   }
   else {
      boat_room->set_room(file);
   }
}

int board(string str) {
   if(!id(str)) return 0;
   tell_room(ETP,"%^BOLD%^"+TPQCN+" boards a small Tsarvani boat",TP);
   write("%^BOLD%^You board a boat");
   TP->move_player(boat_room);
   return 1;
}

void remove() {
   if(objectp(boat_room)) {
      if(present("player",boat_room)) return;
   }
   if(boat_room && objectp(boat_room))
      boat_room->remove();
   return ::remove();
}

void set_owner(string str) {
   owner = str;
   add_id(str+"'s Tsarvani boat");

   boat_room->set_owner(str);
}

string query_owner() {
   return owner;
}
