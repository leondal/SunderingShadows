#include <std.h>

inherit OBJECT;

int gold_value, bought_time;
string id_name;

void create() {
  ::create();
  set_id(({"contract","bond","paper","note"}));
  set_name("contract");
  set_short("A handwritten note");
  set_long("This is a contract between a party identified by "+
  "an emblem of a large white gloved hand, holding a "+
  "blue short sword, and an unnamed partner.");
   set_weight(1);
  set_value(0);
}

void set_bought_time(int x) {
    return bought_time = x;
}

void query_bought_time() {
    return bought_time;
}

void set_gold_value(int x) {
    return gold_value = x;
}

void query_gold_value() {
    return gold_value;
}

void set_id_name(string str) {
    return id_name = str;
}

void query_id_name() {
    return id_name;
}
