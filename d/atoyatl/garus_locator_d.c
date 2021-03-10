#include <std.h>
#include <daemons.h>

inherit DAEMON;

object garus;
int last_move;
int last_dismissed;

void create() {
  if (!objectp(garus)) garus = new("/d/atoyatl/tecqumin/mons/garus");
  ::create();
}

void clean_up() {
  // This function added to prevent data being removed by the inherited
  // clean_up function.
  return;
}

void dismiss(){
  last_dismissed = time();
}

int query_last_dismissed(){
  return last_dismissed;
}

int query_last_move(){
  return last_move;
}

object query_garus(){
  if (!objectp(garus)) garus = new("/d/atoyatl/tecqumin/mons/garus");
  return garus;
}

void check_for_garus(object where){
  object room, * critters;
  int i, count, flag;
  if (!objectp(where))
  {
    report("location not valid for garus check");
    return;
  }
  if (!objectp(garus)){
    report("Garus not valid for garus check");
    garus = new("/d/atoyatl/tecqumin/mons/garus");
  }
  critters = all_living(where);
  count = sizeof(critters);
  if(last_move > time() - (2400 * 7)){
    report("Garus check ending due to recent last_move time");
    return;
  }
  if (last_dismissed > time() - 1200){
    report("Garus check ending due to recent last_dismissed time");
    return;
  }

  if (count<1)
  {
    return;
  }
  flag = 0;
  for (i=0;i<count;i++)
  {
    if
(!critters[i]->id("player")||critters[i]->query_true_invis()||critters[i]->
query_level()<38)
    {

      continue;
    }
    flag = 1;
    break;
  }
  if (flag == 0)
  {
    return;
  }
  if (objectp(garus) && objectp(environment(garus)) )
  {
    room = environment(garus);
    if (!present("player", room))
    {
      if (base_name(where) == "/d/attaya/newseneca/rooms/inn_entrance"){
        tell_room(where, "An old sailor wanders past on his way to the lounge bar");
        where = find_object_or_load("/d/attaya/newseneca/rooms/inn_bar");
      }
      tell_room(where, "An old sailor wanders in");
      garus->move(where);
    }
  } else {
    report("Unable to move garus because either he or his environment is invalid");
    if (!objectp(garus)) garus = new("/d/atoyatl/tecqumin/mons/garus");
    tell_room(where, "An old sailor wanders in");
    garus->move(where);
  }
}

void report(string str){

}

void initiate_garus_check(object where){
  object * critters;
  int i, count;
  critters = all_living(where);
  count = sizeof(critters);
  if (count<1) return;
  for (i=0;i<count;i++)
  {
    if (userp(critters[i]) && critters[i]->query_level()>38)
    {
      check_for_garus(where);
      return;
    }
  }
}
