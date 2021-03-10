#include <std.h>
#include "keep.h"
inherit ROOM;

int FLAG;

void create()
{
   ::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
   set_property("indoors",1);
   set_property("light",1);
   set_short("A secret passage");
   set_long(
   "You have come to a dead end of a secret passage. A large woven %^BOLD%^%^RED%^rug%^RESET%^ covers the"+
   " floor here. There is a desk on the west side of the room with a chair, and"+
   " a small %^RED%^couch%^RESET%^ on the east side. You imagine that this is where the people who"+
   " used the passage met in secret to discuss things. A large wooden chest is on"+
   " the south side of the room, it is partially open and appears to be filled with"+
   " some rather molded books and such that are now worthless."
   );
   set_smell("default","The passage is filled with dust.");
   set_listen("default","Everything is fairly quiet.");
   set_items(([
   "floor" : "Most of the floor is covered by a large woven rug.",
   "rug" : "%^BOLD%^%^RED%^The rug is a beautiful piece of work done in a geometric"+
   " design with beautiful shades of red and orange, it displays a large sun in the"+
   " very center. It is worn out and a bit faded and now covered in dust.%^RESET%^",
   "desk" : "A plain desk sits on the west side of the room with a simple chair. It"+
   " could have been used for someone to take notes on secret meetings, or forge"+
   " documents, but you will probably never know.",
   "chair" : "A simple wooden chair is sitting next to the desk, it is slightly"+
   " padded but the cushions are very worn out.",
   "couch" : "%^RED%^A small wine colored couch is on the eastern side of the room,"+
   " it also appears worn and is rather moldy and dusty now.%^RESET%^",
   "chest" : "A large wooden chest has been placed against the south wall of the"+
   " room. It is slightly open and is filled with mildewed books. You notice a"+
   " few scratches on the floor around the chest.",
   "scratches" : "There are a few scratch marks that you can see on the floor"+
   " near the chest where the rug doesn't quite cover, almost as though it had"+
   " been moved at one point.",
   ]));
   set_exits(([
   "north" : ROOMS+"keep36",
   ]));
}

void reset()
{
  ::reset();
   FLAG = 0;
  remove_exit("down");
  set_exits((["north" : ROOMS+"keep36"]));
  remove_item("trap door");
  remove_item("stairs");
  add_item("chest","A large wooden chest has been placed against the south wall of the"+
   " room. It is slightly open and is filled with mildewed books. You notice a"+
   " few scratches on the floor around the chest.");
}

void init()
{
   ::init();
   add_action("move","move");
   add_action("lift","lift");
   add_action("shut","shut");
}

void move(string str)
{
   if(str != "chest") {
      tell_object(TP,"Move what?");
      return 1;
   }
   if(FLAG == 1) {
      if(member_array("down",ETP->query_exits()) != -1) {
         tell_object(TP,"You can't move the chest over with the trap door open.");
         return 1;
      }
      tell_object(TP,"You move the chest back over to cover the trap door.");
      tell_room(ETP,""+TPQCN+" drags the chest over to cover up the trap door.",TP);
      FLAG = 0;
      remove_item("trap door");
      add_item("chest","A large wooden chest has been placed against the south wall of"+
      " the room. It is slightly open and is filled with mildewed books. You notice a"+
      " few scratches on the floor around the chest.");
      return 1;
   }
   else {
      tell_object(TP,"You drag the chest to the side, revealing a trap door!");
      tell_room(ETP,""+TPQCN+" drags the chest over to the side, revealing a trap door.",TP);
      add_item("trap door","There is a trap door on the south side of the room."+
      " Perhaps you could lift it open.");
      add_item("chest","A large wooden chest has been placed against the south wall of"+ 
      " the room. It is slightly open and is filled with mildewed books. You notice"+
      " that it has been moved to the side to reveal a trap door.");
      FLAG = 1;
      return 1;
   }
}

void lift(string str)
{
   if(str != "door" && str != "trap door") {
      tell_object(TP,"Lift what?");
      return 1;
   }
   if(FLAG != 1) {
      tell_object(TP,"What "+str+"?");
      return 1;
   }
   if(member_array("down",ETP->query_exits()) != -1) {
      tell_object(TP,"The trap door is already open!");
      return 1;
   }
   tell_object(TP,"You lift the trap door, revealing some stairs leading down.");
   tell_room(ETP,""+TPQCN+" lifts the trap door, revealing some stairs leading down.",TP);
   add_exit(ROOMS+"basement1","down");
   add_item("trap door","The trap door has been opened and reveals a set of stairs"+
   " leading down.");
   add_item("stairs","The stone stairs look sturdy, they lead down into darkness.");
   return 1;
}

void shut(string str)
{
   if(str != "door" && str != "trap door") {
      tell_object(TP,"Shut what?");
      return 1;
   }
   if(member_array("down",ETP->query_exits()) != -1) {
       tell_object(TP,"You shuts the trap door.");
      tell_room(ETP,""+TPQCN+" shuts the trap door.",TP);
      add_item("trap door","There is a wooden trap door in the floor that is shut. Perhaps you could lift it open?");
      remove_item("stairs");
      remove_exit("down");
      return 1;
   }
   else {
      tell_object(TP,"What exactly are you trying to shut??");
      return 1;
   }
}
