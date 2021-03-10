#include <std.h>
#include <move.h>
#include "../tecqumin.h"

inherit CANYON_RIVERBANK;

string long_desc();

string base_desc;

void create() {
  ::create();
  base_desc = "%^ORANGE%^You are on a %^RESET%^muddy %^BLUE%^riverbank %^ORANGE%^at"
    +" the bottom of a long canyon. The narrow bank meets the"
    +" %^BOLD%^%^YELLOW%^canyon wall%^RESET%^%^ORANGE%^ to the east, and the fast"
    +" flowing %^BOLD%^%^BLUE%^river%^RESET%^%^ORANGE%^ to the" 
    +" west. A small path is cut into the side of the canyon wall to the north.";
  set_long( (:TO, "long_desc" :) );
  add_item("canoe", (:TO, "canoe_desc" :) );
  add_item("canoes", (:TO, "canoe_desc" :) );
  set_exits((["north": JUNG_ROOM + "canyon_riverbank"  ]));
}

void init(){
  ::init();
  add_action("enter_me", "enter");
}

int enter_me(string str){
  object canoe1, canoe2;
  if (interact("canoe", str))
  {
    if (count_canoes()<1)
    {
      return notify_fail("There's nothing here for you to enter");
    }
    tell_room(TO, TPQCN + " enters a canoe pulled up on the shore", TP);
    tell_object(TP, "You enter the canoe");
    canoe1= find_object_or_load(ROOMS + "canoe1");
    if (objectp(canoe1))
    {
      if (canoe1->query_launched()==0)
      {
        TP->move_player(ROOMS + "canoe1");
        return 1;
      }
    }
    TP->move(ROOMS + "canoe2");
  } else {
    return notify_fail("enter what?");
  }
  return 1;
}

string canoe_desc(){
  switch(count_canoes())
  {
  case 1:
    return "The canoe is pulled up on the shore. You could probably <enter> it if you wanted to.";
    break;
  case 2:
    return "The canoes are pulled up on the shore. You could probably <enter> one of them if you wanted to.";
    break;
  }
  return "Canoe? There's no canoe here.";
}

int count_canoes(){
  int canoes;
  object canoe1, canoe2;
  canoes = 0;
  if (!catch ( ROOMS + "canoe1"))
  {
    canoe1 = find_object_or_load(ROOMS + "canoe1");
    if (objectp(canoe1))
    {
      if (canoe1->query_launched() == 0) canoes ++;
    }
  }
  if (!catch ( ROOMS + "canoe2"))
  {
    canoe2 = find_object_or_load(ROOMS + "canoe2");
    if (objectp(canoe2))
    {
      if (canoe2->query_launched() == 0) canoes ++;
    }
  }
  return canoes;
}

string long_desc(){
  string result;
  result = base_desc;
  switch(count_canoes())
  {
  case 1:
    result += "%^RESET%^ There is a canoe pulled up on the shore here.";
    break;
  case 2:
    result += "%^RESET%^ Two canoes are pulled up on the shore here.";
    break;
  }
  return result;
}

