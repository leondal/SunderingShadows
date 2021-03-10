//Adapted from rope trick rope by
//~Circe~ for use with psions 7/20/05

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
   set_name("portal");
   set_id( ({ "portal","genesis_portal","entrance" }) );
   set_short("a portal hovering in the air");
   set_long(
@GENESIS
This is a small portal surrounded by a greenish glow.  It seems to lead somewhere, though you cannot quite tell where. Nothing is holding this portal in place, but you could likely <access portal> to go inside and investigate.  If you are the one who created the portal, you may also <dismiss portal>.
GENESIS
   );
   set_property("no animate",1);
   set_value(0);
   set_weight(100000);
   rt_room = new(SPELL_OBJ_DIR+"genesis_room");

   rt_room->remove_property("teleport proof");
   rt_room->remove_property("no teleport");

   rt_room->set_had_players();
   lowered = 1;
}

void set_spellobj(object ob) {
   spellobj = ob;
   caster = spellobj->query_caster();
}

object query_spellobj()
{
    return spellobj;
}

void init()
{
    ::init();
    add_action("do_magic", "access");
    add_action("dismiss", "dismiss");
}

int do_magic(string str)
{
    object ob;

    if (str != "portal") {
        return 0;
    }
    if (!lowered) {
        return 0;
    }
    if (TP->query_disable()) {
        return notify_fail("You cannot enter the portal at this time.\n");
    }
    if (TP->query_bound() || TP->query_tripped() || TP->query_unconscious()) {
        TP->send_paralyzed_message("info", TP);
    }
    tell_object(TP, "You step through the portal into a small demiplane!");
    tell_room(entry_place, TPQCN + " steps through the portal.", TP);
    tell_room(rt_room, TPQCN + " enters the demiplane through the portal.", TP);
    TP->move(rt_room);
    TP->force_me("look");
    return 1;
}

int dismiss(string str)
{
    object ob;

    if (str != "portal") {
        return 0;
    }
    if (TP != caster) {
        return 0;
    }
    spellobj->dest_effect();
    return 1;
}

void start_magic(object entry, int prof, string room) {
   roomName = room;
   entry_place = entry;
   rt_room->add_exit(file_name(entry), "out");
   rt_room->set_entry(entry, TO, room);
   if (ETO->query_property("no teleport")) {
       rt_room->set_property("no teleport", 1);
   } else if (ETO->query_property("teleport proof")) {
       rt_room->set_property("teleport proof", ETO->query_property("teleport proof"));
   } else {
       rt_room->set_property("teleport proof", spellobj->query_clevel());
   }
}

void end_magic()
{
    if (objectp(rt_room)) {
        rt_room->destroy_space();
    }
}

void raise()
{
    if (lowered == 0) {
        tell_room(rt_room, "The portal is already closed.");
        return;
    }
    lowered = 0;
    tell_room(entry_place, "The portal closes, leaving no trace of the space beyond.\n");
    TO->move(rt_room);
}

void lower()
{
    if (lowered == 1) {
        tell_room(rt_room, "The portal is already open.");
        return;
    }
    lowered = 1;
    if (!objectp(entry_place)) {
        entry_place = find_object_or_load(roomName);
    }
    tell_room(entry_place, "You see a portal open through the air!");
    TO->move(entry_place);
}
