//Adapted from rope trick rope by -N for use with bards 08/10
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
   set_name("cottage");
   set_id( ({ "cottage","small cottage","entrance","shelter","secure shelter" }) );
   set_short("a small cottage");
   set_long(
@SHELTER
%^ORANGE%^This is a small cottage, made of wood from what you can tell. Even as you watch, it wavers as though through steam or intense heat, or as though it were not entirely real. Still, it would likely offer some shelter from threats in the surrounding area. You could likely %^MAGENTA%^<access cottage>%^ORANGE%^ to go inside and investigate. If you are the one who created the portal, you may also %^MAGENTA%^<dismiss cottage>%^ORANGE%^.
SHELTER
   );
   set_property("no animate",1);
   set_value(0);
   set_weight(100000);
   rt_room = new(SPELL_OBJ_DIR+"shelter_room");
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
   add_action("do_magic", "access");
   add_action("dismiss", "dismiss");
}

int do_magic(string str) {
   object ob;

   if(str != "cottage") return 0;
   if(!lowered) return 0;
   if(TP->query_disable()) return notify_fail("You cannot enter the cottage at this time.\n");
   if(TP->query_bound() || TP->query_tripped() || TP->query_unconscious()) {
      TP->send_paralyzed_message("info",TP);
   }
   if(lowered == 0) {
      tell_object(TP, "The cottage door is locked from inside!");
      return 0;
   }
   tell_object(TP, "You open the door to the cottage, entering the small but cosy space within!");
   tell_room(entry_place,TPQCN+" opens the cottage door and steps inside.",TP);
   tell_room(rt_room, TPQCN+" opens the cottage door and steps inside.",TP);
   TP->move(rt_room);
   TP->force_me("look");
   return 1;
}

int dismiss(string str) {
   object ob;

   if(str != "cottage") return 0;
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
      tell_room(rt_room,"The cottage door is locked.");
      return;
   }
   lowered = 0;
   tell_room(entry_place, "The cottage door's lock clicks.\n");
}

void lower() {
   if(lowered == 1) {
      tell_room(rt_room, "The portal is already unlocked.");
      return;
   }
   lowered = 1;
   tell_room(entry_place, "The cottage door's lock clicks.");
}
