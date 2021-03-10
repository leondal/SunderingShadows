#include <std.h>

inherit OBJECT;

object owner;

void create() {
    ::create();
    set_id( ({"brooch", "mithril brooch" }) );
    set_name("%^BLACK%^BOLD%^mithril brooch%^RESET%^");
    set("short", "%^BLACK%^BOLD%^mithril brooch set with %^RESET%^GREEN%^emeralds%^RESET%^");
    set_long(
@THORN
This is a fine work of art, most likely of elven manufacture.  It is
made of mithril silver with a large emerald in the center.  Around the
center stone is a circle of runes along with a circle of smaller
emeralds. 
THORN
    );
    set_weight(1);
    set_value(1500);
    set_property("magic",1);
}

void set_owner(object ob) {
  owner = ob;
}

void init() {
    ::init();
 	add_action("hello_reaction", "hello");
	add_action("fatima_quest", "fatima");
 	add_action("dagger_quest", "dagger");
 	add_action("thanatos_quest", "thanatos");
 	add_action("fatima_award", "faward");
 	add_action("dagger_award", "daward");
 	add_action("thanatos_award", "taward");
}

int hello_reaction(string str) {
  owner->hello_reaction(str);
  return 1;
}

int fatima_quest(string str) {
  owner->fatima_quest(str);
  return 1;
}

int dagger_quest(string str) {
  owner->dagger_quest(str);
  return 1;
}

int thanatos_quest(string str) {
  owner->thanatos_quest(str);
  return 1;
}

int fatima_award(string str) {
  owner->fatima_award(str);
  return 1;
}

int dagger_award(string str) {
  owner->dagger_award(str);
  return 1;
}

int thanatos_award(string str) {
  owner->thanatos_award(str);
  return 1;
}

