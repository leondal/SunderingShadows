#include <std.h>
#include <move.h>
#include "../tecqumin.h"

inherit ROOM;

string long_desc();
string base_desc;

void create() {
  ::create();
  set_indoors(0);
  set_property("light", 2);
  set_terrain(BEACH);
  set_travel(FOOT_PATH);
  set_property("no teleport", 1);
  set_name("A secret beach");
  set_short("%^BOLD%^%^YELLOW%^On an island beach");
  set_long( (: TO, "long_desc" :) );
  base_desc = "%^BOLD%^%^YELLOW%^You are on the beach of a small, secret"
           +" island in the middle of a %^BOLD%^%^GREEN%^j%^RESET%^"
           +"%^GREEN%^u%^BOLD%^%^GREEN%^ng%^RESET%^%^GREEN%^l%^BOLD%^"
           +"%^GREEN%^e %^RESET%^%^BLUE%^river%^BOLD%^%^YELLOW%^. Beyond"
           +" the sand, the %^RESET%^%^GREEN%^trees %^BOLD%^%^YELLOW%^"
           +"are dense, but a path leads off to the north." ;
  add_item("canoe", (:TO, "canoe_desc" :) );
  add_item("canoes", (:TO, "canoe_desc" :) );
  set_smell("default","The air is heavy with %^CYAN%^humidity%^ORANGE%^"
                    +" and the heady scent of %^GREEN%^j%^BOLD%^"
                    +"%^GREEN%^u%^RESET%^%^GREEN%^ngle %^ORANGE%^plant"
                    +" life");
  set_listen("default","You can hear the water flowing swiftly by.");
  set_exits( ([ "northeast" : ROOMS + "beach2" ,
                "northwest" : ROOMS + "beach3",
                "north"     : ROOMS + "fountain_of_youth"]) );
}
void init() {
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
      if (canoe1->query_launched()==2)
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


string long_desc(){
  string result;
  result = base_desc;
  switch(count_canoes())
  {
  case 1:
    result += "%^RESET%^%^ORANGE%^ There is a canoe pulled up on the shore here.";
    break;
  case 2:
    result += "%^RESET%^%^ORANGE%^ Two canoes are pulled up on the shore here.";
    break;
  }
  return result;
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
      if (canoe1->query_launched() == 2) canoes ++;
    }
  }
  if (!catch ( ROOMS + "canoe2"))
  {
    canoe2 = find_object_or_load(ROOMS + "canoe2");
    if (objectp(canoe2))
    {
      if (canoe2->query_launched() == 2) canoes ++;
    }
  }
  return canoes;
}
