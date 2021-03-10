//Adapted from rope trick room by -N for use with bards 08/10
#include <std.h>
#include <magic.h>
inherit ROOM;

object entry, rope;
string roomName;

void create() {
   ::create();
   set_light(1);
   set_short("%^RESET%^%^ORANGE%^Inside a cosy cottage%^RESET%^");
   set_property("no pocket space",1);
   set_property("no sticks", 1);
   set_property("indoors", 1);
   set_terrain(CITY);
   set_travel(STAIRWAY);
   set_long(
"%^RESET%^%^ORANGE%^Inside a cosy cottage%^RESET%^\n"
"You stand within a small but cosy cottage.  A few aged wooden "
"chairs stand about, while a crackling fireplace warms the area.  "
"Windows open to several directions, but nothing can be seen "
"outside except a gray, misty haze.  Occasionally a wall shimmers "
"and wavers, as though it were not completely real, but the "
"building seems stable enough for a time.");
}

void init() {
   ::init();
   add_action("pull_up_rope", "lock");
   add_action("lower_rope", "unlock");
}

void set_entry(object ob, object rp, string where) {
   entry = ob;
   rope = rp;
   roomName = where;
}

int pull_up_rope(string str) {
   object *inv;
   int x, people;

   if(str != "cottage") return 0;
   inv = all_inventory(TO);
   for(x=0;x<sizeof(inv);x++) {
      if(living(inv[x])) people = people + 1;
   }
   if(people > 7) {
      tell_object(TP,"The cottage is not large enough to close the door and "+
         "lock it, with more than eight people inside.");
      return 1;
   }
   tell_room(TO, TPQCN+" locks the cottage door, making this dimension "+
      "inaccessible from outside!",TP);
   tell_object(TP, "You lock the cottage door, making this dimension "+
      "inaccessible from outside.");
   rope->raise();
   TO->remove_exit("out");
   return 1;
}

int lower_rope(string str) {
   if(str != "cottage") return 0;
   tell_room(TO, TPQCN+" unlocks the cottage door, granting access to "+
      "the Prime Material plane.",TP);
   tell_object(TP,"You unlock the cottage door, granting access to the "+
      "Prime Material plane.");
   rope->lower();
   if(!objectp(entry))
	entry = find_object_or_load(roomName);
   TO->add_exit(base_name(entry), "out");
   return 1;
}

void destroy_space() {
   object *inv;
   int x;

   inv = all_inventory(TO);
   if(!objectp(entry))
	entry = find_object_or_load(roomName);
   for(x=0;x<sizeof(inv);x++) inv[x]->move(entry);
   if(sizeof(inv)) tell_room(entry, wrap("The cottage shimmers one last time and then disappears!\n"));
   "/daemon/virtual_room_d.c"->destroy_virtual_room(TO->query("my_virtual_name"), entry);
   TO->remove();
}
