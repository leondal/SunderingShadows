#include <std.h>
#include "../../tecqumin.h"
inherit "/d/common/obj/weapon/shortsword";

int delay;

void create(){
   ::create();
   set_id(({"sword","machete","shortsword"}));
   set_name("heavy machete");
   set_obvious_short("%^RESET%^a heavy bladed machete%^RESET%^");
   set_short("explorer's machete");
   set_long("This heavy bladed machete is almost half a metre long,"
     +" with a blade that is broader toward the tip. A small ridge"
     +" between handle and blade serves to guard against fingers"
     +" slipping onto the edge, but it seems designed more for"
     +" hacking down foliage than for combat.");
   set_lore(
      "The tabaxi explorers spend long days travelling through the"
    +" jungle, and while their innage woodcraft and agility lets"
    +" them bypass many obstacles, sometimes there is no quicker"
    +" way to go than to hack through the foliage. They are also"
    +" renowned for their ability to find things in the jungle,"
    +" and it is rumoured that some of their machetes bear"
    +" enchantments that help with this. Perhaps you could try"
    +" using it to %^BOLD%^%^YELLOW%^find something?");
   set_property("lore difficulty",45);
   set_value(35000+random(7600));
   set_property("enchantment",7);
   delay = 15;
}

string get_recognized_name(object who, string name){
  object * ppl;
  string nm;
  int i, count;
  ppl = children("/std/user.c");
  nm = who;
  for (i=0;i<count;i++){
    nm = ppl[i]->query_name();
    if (who->isKnown(nm))
    {
      nm = who->knownAs(nm);
      break;
    }
  }
  return nm;
}

void init(){
        ::init();
   add_action("find_me", "find");
}

int query_delay(){
  return delay;
}

void set_delay(int d){
  delay = d;
}
int find_me(string str){
  if (TP!= ETO) return notify_fail("You have to be holding the machete to use that ability");
  if (!stringp(str)) return notify_fail("Locate what?");
  if (time() < TP->query_property("tossed machete") + delay) return notify_fail("It is too soon to do that again");
  if (!objectp(EETO)) return notify_fail("There seems to be a problem with the room you are in");
  tell_object(ETO, "You throw the machete up in the air and watch as it tumbles end over end");
  tell_room(EETO, ETO->QCN + "throws " + ETO->QP + " machete up in the air. It tumbles end over end", ETO);
  TP->set_property("tossed machete", time());
  call_out("locate2", 2, str, ETO, EETO);
  return 1;
}

void locate2(string str, object tosser, object room){
  object ob, * rooms;
  string * path, * temppath, direction;
  if (tosser!=ETO){
    report ("machete search failed because the tosser does not have the machete");
    return;
  }
  if (!objectp(EETO))
  {
    tell_object(ETO, "The machete's enchantment fails because the room you are standing in seems to be broken");
    return;
  }
  if (EETO != room)
  {  
    tell_object(ETO, "Your movement has disrupted the machete's enchantment, and you seem to have left it behind");
    if (objectp(room))
    {
      tell_room(room, "The machete clatters to the floor");
      move(room);
    }
    return;
  }
  if (!interact("greater", base_name(TO)) && !interact("atoyatl", base_name(EETO)))
  {
    tell_object(ETO, "The spirits of the machete are not strong enough to function this far from home");
    tell_room(EETO, "The machete clatters to the floor");
    move(EETO);
    return;
  } 
  str = get_recognized_name(tosser, str);
  report ("machete tring to find a " + str);
  ob = "/daemon/pathfinder_d.c"->far_present(EETO, str, 5);
  if (!objectp(ob) || !objectp(environment(ob)))
  {
    report ("object not located");
    notfound(str);
    return;
  }
  temppath = ({});
  rooms = ({});
  path = ({});
  path = "/daemon/pathfinder_d.c"->findpath (room, environment(ob), temppath, path, rooms, 5, 1);
  if (sizeof(path)<1){
    report ("object found, but no path to it available");
    notfound(str);
    return;
  }
  direction = path[0];
  tell_room(EETO, "The machete lands cleanly on the floor, with its tip pointing toward the %^CYAN%^" + direction + "%^RESET%^ exit.");
  if (objectp(EETO)) move(EETO);
}

void notfound(string str){
  tell_room(EETO, "The machete lands tip first in the floor");
  tell_object(ETO, "Seems the spirits were unable to locate any " + str);
  if (objectp(EETO)) move(EETO);
  return;
}

void report(string str){
  "/daemon/reporter_d"->report("lujke", str);
}

