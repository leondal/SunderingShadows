#include <std.h>
#include <magic.h>
#include <rooms.h>

inherit OBJECT;

int lowered, theProf;
object rt_room, caster;
object spellobj, entry_place;
string roomName;

void create()
{
   ::create();
   set_name("portal");
   set_id( ({ "door","demiplane_portal","entrance","portal","old door","an old door" }) );
   set_short("%^RESET%^%^ORANGE%^an %^ORANGE%^old %^BOLD%^%^ORANGE%^d%^RESET%^%^ORANGE%^oor");
   set_long(
"%^ORANGE%^This is an eerie and old wooden door, standing alone in its frame on iron hinges without any wall supporting it.

You can <enter door> and appear somewhere else.
You can <dismiss door> if you know what you're doing."
   );
   set_property("no animate",1);
   set_value(0);
   set_weight(100000);
   lowered = 1;
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

   if(present(str,ETO)!=TO)
       return 0;
   if(!lowered)
       return 0;

   if(TP->query_disable())
       return notify_fail("You cannot enter the door at this time.\n");

   if(TP->query_bound() || TP->query_tripped() || TP->query_unconscious())
   {
      TP->send_paralyzed_message("info",TP);
   }
   TP->move(rt_room);
   TP->force_me("look");

   tell_object(TP, "%^ORANGE%^You step through the door and appear somewhere else.");
   tell_room(entry_place,"%^BOLD%^%^GREEN%^"+TPQCN+" steps through the portal.",TP);
   tell_room(rt_room, "%^BOLD%^%^GREEN%^"+TPQCN+" enters through the door.",TP);
   return 1;
}

int dismiss(string str) {
   object ob;

   if(present(str,ETO)!=TO)
       return 0;
   if(TP != caster)
       return 0;

   tell_room(ETO,"%^ORANGE%^The old door fades into non-existence.");
   spellobj->dest_effect();
   return 1;
}

void start_magic(object entry, string room) {
   roomName = room;
   entry_place = entry;
   rt_room = new("/d/magic/room/demiplane_plane");

   rt_room->set_had_players();
   rt_room->remove_property("teleport proof");
   rt_room->set_property("teleport proof",spellobj->query_clevel());
   rt_room->set_castname(caster->query_name());
   rt_room->restore_space();
   rt_room->add_exit(file_name(entry), "door");
   rt_room->set_entry(entry, TO, room);
}

void end_magic() {
   if(objectp(rt_room))  rt_room->destroy_space();
}

void raise() {
   if(lowered == 0) {
      tell_room(rt_room,"%^ORANGE%^The door is already closed.");
      return;
   }
   lowered = 0;
   tell_room(entry_place, "%^ORANGE%^The %^ORANGE%^d%^BOLD%^%^ORANGE%^o%^RESET%^%^ORANGE%^or%^ORANGE%^ disappears.");
   TO->move(rt_room);
}

void lower() {
   if(lowered == 1) {
      tell_room(rt_room, "%^ORANGE%^The door to material plane is already open.");
      return;
   }
   lowered = 1;
   if(!objectp(entry_place))
       entry_place = find_object_or_load(roomName);
   tell_room(entry_place, "%^ORANGE%^You see a door materializes in the place!");
   TO->move(entry_place);
}
