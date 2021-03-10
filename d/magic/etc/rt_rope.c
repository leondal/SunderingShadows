// Altered rope for 2nd level wizard spell
// Rope Trick.
// Thorn@ShadowGate
// 6/24/95

#include <std.h>
#include <magic.h>
#include <rooms.h>

inherit OBJECT;

int lowered, theProf;
object rt_room, caster;
object spellobj, entry_place;
string roomName;

void end_magic();
void start_magic(object entry, int prof, string room);
int dismiss(string str);
int do_magic(string str);
object query_spellobj();
void set_spellobj(object ob);

void create() {
   ::create();
   set_name("rope");
   set_id( ({ "rope", "rt_rope", "standing rope" }) );
   set_short("A rope standing on-end in mid-air");
   set_long(
@TRICK
This is a rope that appears to be standing straight up....
with nothing holding it up!!!  It looks like you can <ascend>
rope.  If you cast the spell that made the rope do this,
you can <dismiss> rope.
TRICK
   );
    set_property("no animate",1);
   set_value(0);
   set_weight(100000);
   rt_room = new(SPELL_OBJ_DIR+"rt_room");
   rt_room->set_had_players();
   lowered = 1;
}

void set_spellobj(object ob) {
   spellobj = ob;
   caster = spellobj->query_caster();
}

object query_spellobj() { return spellobj; }

void init() {
   ::init();
   add_action("do_magic", "ascend");
   add_action("dismiss", "dismiss");
}

int do_magic(string str) {
   object ob;

   if(str != "rope") return 0;
   if(!lowered) return 0;
   if(TP->query_disable())
      return notify_fail("You cannot climb the rope at this time.\n");
   if(TP->query_bound() || TP->query_tripped() || TP->query_unconscious()) {
      TP->send_paralyzed_message("info",TP);
   }
   tell_object(TP, "You ascend the rope into an extra-dimensional space!\n");
   tell_room(entry_place,TP->query_cap_name()+" climbs the rope.",TP);
   tell_room(rt_room, TP->query_cap_name()+" climbs up from below.",TP);
   TP->move(rt_room);
   TP->force_me("look");
   return 1;
}

int dismiss(string str) {
   object ob;

   if(str != "rope") return 0;
   if(TP != caster) return 0;
   spellobj->dest_effect();
   return 1;
}

void start_magic(object entry, int prof, string room) {
   roomName = room;
   entry_place = entry;
   theProf = prof;
   rt_room->add_exit(file_name(entry), "out");

   rt_room->remove_property("teleport proof");
   rt_room->remove_property("no teleport");

   if(ETO->query_property("no teleport"))
       rt_room->set_property("no teleport",1);
   else if(ETO->query_property("teleport proof"))
       rt_room->set_property("teleport proof",ETO->query_property("teleport proof"));
   else
       rt_room->set_property("teleport proof",spellobj->query_clevel());

   rt_room->set_entry(entry, TO, room);
   set_heart_beat(5);
}

void end_magic() {
   if(objectp(rt_room))  rt_room->destroy_space();
}

void raise() {
   if(lowered == 0) {
      tell_room(rt_room,"The rope is already up.");
      return;
   }
   lowered = 0;
   tell_room(entry_place, "The rope is pulled up and disappears into empty space above you!\n");
   TO->move(rt_room);
}

void lower() {
   if(lowered == 1) {
      tell_room(rt_room, "The rope is already lowered.");
      return;
   }
   lowered = 1;
   if(!objectp(entry_place))
	entry_place = find_object_or_load(roomName);
   tell_room(entry_place, "You see a rope drop down from the empty space above you!\n");
   TO->move(entry_place);
}


void heart_beat(){
    if (theProf < random(100)) {
        end_magic();
    }
}
