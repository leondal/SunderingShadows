// Extra-dimensional room for 2nd level
// Wizard spell, Rope Trick.
// Thorn@ShadowGate
// 6/24/95


#include <std.h>
#include <magic.h>

inherit ROOM;

object entry, rope;
string roomName;

void create() {
   ::create();
   set_light(1);
   set_short("An Extra-dimensional space");
   set_property("no sticks", 1);
   set_property("indoors", 1);
   set_property("no pocket space",1);
   set_terrain(CITY);
   set_travel(STAIRWAY);
   set_long(
@TRICK
You are in the middle of an extra_dimensional space created by the magic of a "rope trick" spell.  There are a few things you can do in here.
TRICK
   );
}

void init() {
   ::init();
   add_action("pull_up_rope", "pull");
   add_action("lower_rope", "lower");
}

void set_entry(object ob, object rp, string where) {
   entry = ob;
   rope = rp;
   roomName = where;
}

int pull_up_rope(string str) {
   object *inv;
   int x, people;

   if(str != "rope") return 0;
   inv = all_inventory(TO);
   for(x=0;x<sizeof(inv);x++) {
      if(living(inv[x])) people = people + 1;
   }
   if(people > 7) {
      write("The rope may not be taken in if there are more than 8 creatures in this space.\n");
      return 1;
   }
   tell_room(TO, TP->query_cap_name()+" pulls the rope into the space, making this room inaccessable from outside!", ({ TP }));
   tell_object(TP, "You pull the access rope into the space, making this room inacessible from outside!");
   rope->raise();
   TO->remove_exit("out");
   return 1;
}

int lower_rope(string str) {
   if(str != "rope") return 0;
   tell_room(TO, TP->query_cap_name()+" lowers the rope making this room accessable from outside!", ({ TP }));
   tell_object(TP, "You lower the access rope to the outside!");
   rope->lower();
   if(!objectp(entry))
	entry = find_object_or_load(roomName);
   TO->add_exit(base_name(entry), "out");
   return 1;
}

void destroy_space()
{
   object *inv;
   int x;

   inv = all_inventory(TO);
   if(!objectp(entry))
	entry = find_object_or_load(roomName);
   for(x=0;x<sizeof(inv);x++) inv[x]->move(entry);
   if(sizeof(inv)) tell_room(entry, wrap("You see something drop from the sky out of nowhere!\n"));
   "/daemon/virtual_room_d.c"->destroy_virtual_room(TO->query("my_virtual_name"), entry);
   TO->remove();
}
