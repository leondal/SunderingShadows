#include <std.h>

inherit OBJECT;

int flag;
void create()
{
  ::create();
  set_name("boulder");

  set_id( ({ "boulder" }) );
  set_short("%^BOLD%^%^BLACK%^A big boulder%^RESET%^");
  set_long("%^BOLD%^%^BLACK%^This is a fairly heavy looking boulder. It sits here, blocking your path. Maybe you can pick it up and put it elsewhere.%^RESET%^");
  set_weight(10);
}

void init()
{
  ::init();
  add_action("get2", "get");
}

int get2(string str)
{
  object ob;

  if( str != "boulder" && str != "all" )
    return 0;

   if(flag) return 0;
  say(TPQCN +" tries to pick up the boulder, and it vanishes leaving a geonid "
            "behind!\n");
  write("As you pick up the boulder, it vanishes leaving a geonid behind!\n");
  ob  = new("/d/koenig/town/mon/geonid.c");
  ob -> move(environment(TP));
  TP -> kill_ob(ob);
    flag = 1;
  call_out("remove", 1);
  return 1;
}
