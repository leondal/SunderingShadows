#include <std.h>
inherit DAEMON ;

int clean_up() { TO->remove(); return 1; }

int is_wizard(object ob) {
  if(!objectp(ob)) return 0;
  if(!userp(ob)) return 0;
  if(wizardp(ob)) return 1;
  return 0;
}

int is_avatar(object ob) {
  if(!objectp(ob)) return 0;
  if(!userp(ob)) return 0;
  if(avatarp(ob)) return 1;
  return 0;
}

int is_userp(object ob) {
  if(!objectp(ob)) return 0;
  if(!userp(ob)) return 1;
  return 0;
}

int is_objectp(object ob) {
  if(!objectp(ob)) return 0;
  if(objectp(ob)) return 1;
  return 0;
}

object * avatars() { return filter_array(users(),"is_avatar", TO); }
object * wizards() { return filter_array(users(),"is_wizard", TO); }


void local_message(string type, string what, object * recievers, object * excluded) {
  message(type,what,recievers,excluded);
}

void users_message(string type, string what, object * excluded) {
  message(type,what,users(),excluded);
}

void wizards_message(string type, string what, object * excluded) {
  message(type,what,wizards(),excluded);
}

void and_wizards_message(string type, string what,object * receivers, object * excluded) {
  message(type,what,distinct_array(wizards()+receivers),excluded);
}
void and_avatars_message(string type, string what,object * receivers, object *
excluded) {
  message(type,what,distinct_array(avatars()+receivers),excluded);
}
void avatars_message(string type, string what, object * excluded) {
  message(type,what,avatars(),excluded);
}

void first_death_message(string type, string what, object * receivers, object * excluded) {
     avatars_message(type, "%^BOLD%^%^WHITE%^Imm:"+what, ({ }));
     local_message(type, what, receivers - avatars() , excluded);
}
void delay_death_message(string type, string what, object * excluded) {
     avatars_message(type, "%^BOLD%^%^WHITE%^Mortal:"+what, ({ }));
     users_message(type, what, excluded + avatars() );
}

void delay_message(int delay, string type, string what, object * recievers, object * excluded)
{
    call_out("local_message", delay, type, what, recievers, excluded);
}

void delay_subject_message(object subject, int delay, string type, string what, object * recievers, object * excluded)
{
    call_out("subject_message", delay, subject, type, what, recievers, excluded);
}

/**
 * This one uses messids property to track which feats are cleared in
 * combat_d after combat ends. If such feat is cleared message for it
 * won't be displayed.
 */
void delay_messid_message(object ob, int  messid, int delay, string type, string what, object * recievers, object * excluded)
{
    if(!objectp(ob))
        return;
    ob->set_property("messids",({messid}));
    call_out("messid_message", delay, ob, messid, type, what, recievers, excluded);
}

void messid_message(object ob, int messid, string type, string what, object * recievers, object * excluded)
{
    int * messids;
    if(!objectp(ob))
        return;
    messids = ob->query_property("messids");
    if(!arrayp(messids))
        return;

    if(member_array(messid,messids)!=-1)
    {
        message(type,what,recievers,excluded);
        ob->remove_property_value("messids",({messid}));
    }
}

void subject_message(object subject, string type, string what, object * recievers, object * excluded)
{
    if(objectp(subject))
        message(type,what,recievers,excluded);
}
