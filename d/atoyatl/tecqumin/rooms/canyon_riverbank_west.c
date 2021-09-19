#include <std.h>
#include <move.h>
#include "../tecqumin.h"

inherit CANYON_RIVERBANK;

int canoe;

void create() {
  ::create();
  side = "west";
  set_exits((["up"   : JUNG_ROOM + "canyon_path7"    ]));
  add_item(({"canoe", "canoes"}), (:TO, "canoe_desc" :));
  canoe = 2;
  set_exits((["up"   : JUNG_ROOM + "canyon_path1"  ]));
}


void init(){
  ::init();
}

string long_desc(){
  string str;
  str = ::long_desc();
  return str;
}

