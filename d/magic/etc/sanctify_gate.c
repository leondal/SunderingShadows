//Adapted from rope trick rope by
//~Circe~ for use with psions 7/20/05
// Ganked again by Ares for sanctify for clerics
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
   set_name("gate");
   set_id( ({ "gate","iron gate","entrance","sanctify gate" }) );
   set_short("a simple gate made from iron");
   set_long(
@TEXT
This is a standing iron gate that looks much like one would
expect to see in a large stone fence.  The posts of the gate
are made from rough cut stone, and it appears to open to
nowhere.  To enter the gate, type <enter gate>, the caster
may also <dismiss gate> to release the spell.
TEXT
   );
   set_property("no animate",1);
   set_value(0);
   //for whatever reason this disappeared - not sure if it's a frequent problem or rare - Saide
   set_no_clean(1);
   set_weight(100000);
   rt_room = new(SPELL_OBJ_DIR+"sanctify_room");
   rt_room->set_had_players();
   lowered = 1;
}

void set_diety(string diety)
{
    rt_room->set_desc(diety);
}

void set_spellobj(object ob) {
   spellobj = ob;
   caster = spellobj->query_caster();
}

object query_spellobj() { return spellobj; }

void init() {
   ::init();
   add_action("do_magic", "enter");
   add_action("dismiss", "dismiss");
}

int do_magic(string str) {
   object ob;

   if(str != "gate") return 0;
   if(!lowered) return 0;
   if(TP->query_disable())
      return notify_fail("You cannot enter the gate at this time.\n");
   if(TP->query_bound() || TP->query_tripped() || TP->query_unconscious()) {
      TP->send_paralyzed_message("info",TP);
   }
   tell_object(TP, "You step through the gate into a small demiplane!");
   tell_room(entry_place,TPQCN+" steps through the gate.",TP);
   tell_room(rt_room, TPQCN+" enters the demiplane through the gate.",TP);
   TP->move(rt_room);
   TP->force_me("look");
   return 1;
}

int dismiss(string str) {
   object ob;

   if(str != "gate") return 0;
   if(TP != caster) return 0;
   spellobj->dest_effect();
   return 1;
}

void start_magic(object entry, int prof, string room)
{
    roomName = room;
    entry_place = entry;
    rt_room->add_exit(file_name(entry), "out");

    rt_room->remove_property("teleport proof");
    rt_room->remove_property("no teleport");
    if (ETO->query_property("no teleport")) {
        rt_room->set_property("no teleport", 1);
    } else if (ETO->query_property("teleport proof")) {
        rt_room->set_property("teleport proof", ETO->query_property("teleport proof"));
    } else {
        rt_room->set_property("teleport proof", spellobj->query_clevel());
    }

    rt_room->set_entry(entry, TO, room);
}

void end_magic() {
   if(objectp(rt_room))  rt_room->destroy_space();
}

void raise() {
   if(lowered == 0) {
      tell_room(rt_room,"The gate is already closed.");
      return;
   }
   lowered = 0;
   tell_room(entry_place, "The gate closes, leaving no trace of the space beyond.\n");
   TO->move(rt_room);
}

void lower() {
   if(lowered == 1) {
      tell_room(rt_room, "The gate is already open.");
      return;
   }
   lowered = 1;
   if(!objectp(entry_place))
	entry_place = find_object_or_load(roomName);
   tell_room(entry_place, "You see a gate appear out of nowhere!");
   TO->move(entry_place);
}
