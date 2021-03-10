// A Rift Key for Underground Seneca Area
// Bruenor@Shadowgate
// 11/29/02
// riftund.c
// Rift Gate orignally made by Thorn@ShadowGate
// 970302
// rift_key.c

#include <std.h>
#include "../areadefs.h"

inherit "/std/armour";

int uses, open;
object user, to, from;
string file2;
string short;

int riftgate(string str);
int open_rift();
int close_rift();
int query_uses();



create() 
{
   ::create();
   file2 = ROOMS+"entrance";
   short = file2->query_short();
   set_property("rift key", 1);
   set_name("little key");
   set_id(({"key", "rift key","little key on a cord", "little key"}));
   set_short("a little key on a cord");
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
   set_weight(0);
   set_size(-1);
   set("value", 945);
   set_limbs(({ "neck" }));
   uses = random(4)+2;
   open = 0;
}

init()
{
   ::init();
   add_action("riftgate", "riftgate");
}
        
int riftgate(string str){
   int i, all;
   string temp;

   if(ETO->query_bound() || ETO->query_unconscious()){
      ETO->send_paralyzed_message("info",ETO);
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
      tell_room(to, user->QCN+" taps the edge of the gate with the key.",({user}));
      close_rift();
      break;
   case "open":
      if(!short) break;
      if(open) break;
      if(EETO->query_property("no teleport"))
         return notify_fail("There is too much magical interference here.\n");
      else {
         from = EETO;
         to = find_object_or_load(file2);
            user = ETO;
            open_rift();
      }
      break;

   case "uses":
      tell_object(user, "The key has at most "+uses+" uses left.\n");
      break;
   default:
      write(
@RIFT
%^BOLD%^GREEN%^Rift Key Help%^RESET%^

riftgate...................these instructions
riftgate open..............open a rift gate to this place
riftgate close.............close the rift gate
***Note: Once a rift is open, until the time it is closed,
anything or anybody can pass through it.


RIFT
      );
      if(!short) {
        write("None.\n");
        return 1;
      }
      write("Programmed Destination:  --------> "+short+"\n");
      break;
   }
   return 1;
}

int open_rift()
{

   tell_object(user, "You tap the air in front of you with the key and and
a shimmering rift portal appears out of nowhere.");
   tell_room(from, user->QCN+" taps thin air with a little key
and a rift portal appears from nowhere!",({user}));
   tell_room(to, "A bright point of light appears from nowhere and suddenly
it opens into a shimmering rift portal!!");
   to->add_exit(base_name(from), "rift");
   from->add_exit(base_name(to), "rift");
   open = 1;
   uses--;
   set_heart_beat(10);
   return 1;
}

int close_rift(){
   set_heart_beat(0);
   tell_room(to, "The rift gate rapidly shrinks and collapses into
nothingness!");
   tell_room(from, "The dimensional rift gate in front of you flashes and
then shrinks into oblivion!");
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
