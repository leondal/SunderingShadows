// A Golden Pass Key
// Thorn@ShadowGate
// 970921
// passkey.c

#include <std.h>
inherit "/std/Object";

int uses;
string key;

int passkey(string str);
int query_uses();



create() {
  ::create();
  set_property("magic iron pass key", 1);
  set_name("an iron key");
  set_id(({
  "key", "pass key",
  "iron key", "iron pass key"
  }));
  
  if(!key) set("short","an iron key");
  else set_short("An iron key ["+key+"]");
  set_long(
@AZHA
  You are holding what seems to be a fairly unremarkable iron
passkey that one would use to open a door or gate with.  You
would love to know what this key opens.
AZHA
);
  set_weight(2);
  set("value", 5);
  uses = random(4)+2;
}

init()
{
        add_action("passkey", "passkey");
}

int passkey(string str)
{

  if(!uses) {
    tell_object(TP, "The iron key fades out of "+
                "existence");
    if(!TO->remove()) destruct(TO);
    return 1;
  }
  if(!str) {
    tell_object(TP, "Specify a door to unlock.");
    return 0;
        }
          if(ETP->is_room() && !ETP->query_property("no iron key")) {
          key = ETP->query_door_key(str);
          if(!key) return notify_fail("Sorry, that is not the name of a door in this room");
          TO->set_id(({ "key", "pass key", "iron key", "iron pass key", key }));
          TO->set_short("An iron key ["+key+"]");
          uses--;
        }
  return 1;
}

int query_uses() { return uses; }

string query_type() { return ""; }
