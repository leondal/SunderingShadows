//Adapted from rope trick room by
//~Circe~ for use with psions 7/20/05

#include <std.h>
#include <magic.h>

inherit ROOM;

object entry, rope;
string roomName;

void create() {
   ::create();
   set_light(1);
   set_short("%^BOLD%^%^BLUE%^a small demiplane%^RESET%^");
   set_property("no sticks", 1);
   set_property("no pocket space",1);
   set_property("indoors", 1);
   set_terrain(CITY);
   set_travel(STAIRWAY);
   set_long(
@GENESIS
%^BOLD%^%^BLUE%^A Small Demiplane%^RESET%^
%^RESET%^%^CYAN%^You stand within the middle of... %^BOLD%^%^WHITE%^n%^RESET%^%^WHITE%^o%^WHITE%^t%^BOLD%^%^WHITE%^hing.%^RESET%^%^CYAN%^ All around you, air flows, but you see nothing other than a misty haze. Strangely, you do not feel weightless, yet you do not sink or rise. It is a rather odd place, disconcerting to some, but it seems stable enough for a time.%^RESET%^

%^ORANGE%^<secure portal>%^RESET%^
    This closes the portal to the Prime Material plane, blocking anyone else from entering.

%^ORANGE%^<expand portal>%^RESET%^
    This reconnects the demiplane with the Prime Material plane, allowing people to enter or leave.out: This is the exit to the Prime Material plane, so long as the portal is open.
GENESIS
   );
}

void init() {
   ::init();
   add_action("pull_up_rope", "secure");
   add_action("lower_rope", "expand");
}

void set_entry(object ob, object rp, string where) {
  entry = ob;
  rope = rp;
  roomName = where;
}

int pull_up_rope(string str) {
   object *inv;
   int x, people;

   if(str != "portal") return 0;
   inv = all_inventory(TO);
   for(x=0;x<sizeof(inv);x++) {
      if(living(inv[x])) people = people + 1;
   }
   if(people > 7) {
      tell_object(TP,"The demiplane is not large enough to close the portal with "+
         "more than eight people in the space.");
      return 1;
   }
   tell_room(TO, TPQCN+" secures the portal, making this demiplane "+
      "inaccessible from outside!",TP);
   tell_object(TP, "You secure the portal, making this demiplane "+
      "inaccessible from outside.");
   rope->raise();
   TO->remove_exit("out");
   return 1;
}

int lower_rope(string str) {
   if(str != "portal") return 0;
   tell_room(TO, TPQCN+" opens the portal, granting access to "+
      "the Prime Material plane.",TP);
   tell_object(TP,"You open the portal to the Prime Material plane.");
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
   if(sizeof(inv)) tell_room(entry, wrap("You see something drop from the sky out of nowhere!\n"));
   "/daemon/virtual_room_d.c"->destroy_virtual_room(TO->query("my_virtual_name"), entry);
   TO->remove();
}
