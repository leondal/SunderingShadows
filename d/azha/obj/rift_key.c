// A Rift Key
// Thorn@ShadowGate
// 970302
// riftkey.c
// set to resize to player for all sizes. Nienne, 09/07.
#include <std.h>
inherit "/std/armour";

int uses, open;
object user, to, from;
string short;
string file;

int riftgate(string str);
int open_rift();
int close_rift();
int query_uses();



void create() {
   ::create();
   set_property("rift key", 1);
   set_name("little key");
   set_id(({"key", "rift key","little key on a cord", "little key"}));
   set("short","a little key on a cord");
   set_long(
@AZHA
  You are looking at a little key, like one you might open a
dollhouse door with.  Although it looks like it may be made of
gold with some tiny chips of gemstones, it is so small that it
is probably worth more for its workmanship than its materials.
The key itself is suspended from a silvery cord that allows the
possesor to wear the key from their neck.
  There is one tiny word etched into the key itself, <riftgate>.

AZHA
);
   set_type("clothing");
   set_ac(0);
   set_weight(5);
   set("value", 945);
   set_limbs(({ "neck" }));
   uses = random(4)+2;
   open = 0;
}

void init(){
   ::init();
    if(!objectp(TP)) return;
    if(!objectp(ETO)) return;
    if(TP != ETO) return;
    if(interactive(TP)) { set_size(TP->query_size()); }
   add_action("riftgate", "riftgate");
}
	
int riftgate(string str){
   int i, all;
   string temp;

   if(TP->query_bound() || TP->query_unconscious()){
      TP->send_paralyzed_message("info",TP);
      return 1;
   }
 
   if(!uses) {
      tell_object(user, "The little key is swallowed into a tiny rift gate and is no more!");
      close_rift();
      if(!TO->remove()) destruct(TO);
      return 1;
   }
   switch(str) {
   case "close":
      if(!open) break;
      tell_object(user, "You tap the edge of the shimmering rift gate with the key and it closes.");
      tell_room(to, user->query_cap_name()+" taps the edge of the gate with the key.",({user}));
      close_rift();
      break;
   case "open":
      if((!file) || (!short)) break;
      if(open) break;
      if(environment(TP)->query_property("no teleport"))
         return notify_fail("There is too much magical interference here.\n");
      else {
         from = environment(TP);
         to = find_object_or_load(file);
         if (to->query_property("no teleport"))
            return notify_fail("There is too much magical interference.\n");
	 else{
            user = TP;
            open_rift();
	 }
      }
      break;
   case "set":
       if(ETP->is_flight_room()) { return 1; }
      if(environment(TP)->query_property("no teleport"))
            return 1;
      else
         file = base_name(environment(TP));
         short = environment(TP)->query_short();
      break;
   case "uses":
      tell_object(user, "The key has at most "+uses+" uses left.\n");
      break;
   default:
      write(
@RIFT
%^BOLD%^GREEN%^Rift Key Help%^RESET%^

riftgate...................these instructions
riftgate set...............set this room as destination
riftgate open..............open a rift gate to this place
riftgate close.............close the rift gate
***Note: Once a rift is open, until the time it is closed,
anything or anybody can pass through it.


RIFT
      );
      if((!file) || (!short)) {
        write("None.\n");
        return 1;
      }
      write("Programmed Destination:  --------> "+short+"\n");
      break;
   }
   return 1;
}

int open_rift(){
   if(!random(5)){
      write("The rift gate sputters and blows up in your hand.");
      TP->cause_typed_damage(TP, "torso", random(25), "force");
      TO->remove();
   }
   tell_object(user, "You tap the air in front of you with the key and a shimmering rift portal appears out of nowhere.");
   tell_room(from, user->query_cap_name()+" taps thin air with a little key and a rift portal appears from nowhere!",({user}));
   tell_room(to, "A bright point of light appears from nowhere and suddenly it opens into a shimmering rift portal!!");
   to->add_exit(base_name(from), "rift");
   from->add_exit(base_name(to), "rift");
   open = 1;
   uses--;
   set_heart_beat(10);
   return 1;
}

int close_rift(){
   set_heart_beat(0);
   tell_room(to, "The rift gate rapidly shrinks and collapses into nothingness!");
   tell_room(from, "The dimensional rift gate in front of you flashes and then shrinks into oblivion!");
   to->remove_exit("rift");
   from->remove_exit("rift");
   to = 0; from = 0; open = 0;
   return 1;
}

int heart_beat(){
   if(uses <= 0) {
      set_heart_beat(0);
      close_rift();
      if(!TO->remove()) destruct(TO);
      return 1;
   }
   uses--;
   return 1;
}

int query_uses() { return uses; }
