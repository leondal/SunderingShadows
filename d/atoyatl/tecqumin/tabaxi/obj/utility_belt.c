#include <std.h>
#include <move.h>
#include "../../tecqumin.h"

inherit PARMOUR;

object * standard_items;
int LAST_REFRESH = 0;

void create(){
        ::create();
        LAST_REFRESH = 0;
        set_name("utility belt");
        set_id(({"pouch", "belt", "utility belt", "khaki belt", "khaki utility belt", "belt pouch", "khaki belt pouch" }));
        set_short("%^GREEN%^T%^ORANGE%^a%^GREEN%^b%^ORANGE%^a%^GREEN%^x%^ORANGE%^i E%^GREEN%^x%^ORANGE%^p%^GREEN%^l%^ORANGE%^o%^GREEN%^r%^ORANGE%^e%^GREEN%^r%^ORANGE%^'%^GREEN%^s %^ORANGE%^u%^GREEN%^t%^ORANGE%^i%^GREEN%^l%^ORANGE%^i%^GREEN%^t%^ORANGE%^y %^GREEN%^b%^ORANGE%^e%^GREEN%^l%^ORANGE%^t%^RESET%^");
        set_obvious_short("a %^GREEN%^k%^ORANGE%^h%^GREEN%^a%^ORANGE%^k%^GREEN%^i%^RESET%^ utility belt");
        set_long(
@AVATAR
This %^GREEN%^k%^ORANGE%^h%^GREEN%^a%^ORANGE%^k%^GREEN%^i utility b%^RESET%^e%^GREEN%^lt%^RESET%^ has a number of pouches and hooks for various explorers' tools and implements, as well as storage for other bits and pieces someone might need. As standard, it will hold a %^ORANGE%^coil of rope%^RESET%^, a %^BOLD%^%^WHITE%^machete%^RESET%^, a %^BOLD%^%^WHITE%^lantern%^RESET%^ and %^BOLD%^%^BLACK%^oil%^RESET%^, some %^ORANGE%^climbing tools%^RESET%^, %^BOLD%^%^CYAN%^water%^RESET%^, and %^ORANGE%^trail rations. 
AVATAR
        );
        set_weight(5);
   set_value(0);
        set_lore(
@AVATAR
The invention of a very curious Tabaxi explorer at some time in the past, these belts make sure that the wearer is (almost) never without his or her essential supplies. Interestingly, the standard items on the belt seem to renew themselves from time to time.

AVATAR
        );
        set_property("lore difficulty",33);
//        standard_items = ({});
//        refresh_items();
        set_max_internal_encumbrance(calculate_internal_encumbrance());
        set_type("clothing");
        set_limbs(({ "waist" }));
        set_size(-1);
        TO->set_property("enchantment",7);
        set_wear((:TO,"wear_func":));
   set_overallStatus(100);
}

int isMagic(){ return 1; }

int calculate_internal_encumbrance(){
  int enc, count, i;
  string * items;
  object ob;
  enc = 15;
  items =  ({ "rope", "machete", "bullseye", "oil", "climbing tools", "rations", "water canteen" });
  count = sizeof(items);
  for (i=0;i<count;i++)
  {
    ob = present(items[i], TO);
    if (objectp(ob))
    {
      enc += ob->query_weight();
    }
  }
  return enc;
}

void report(string str){
//  "/daemon/reporter_d.c"->report("lujke", str);
}

object get_standard_item(string what){
  object ob, * removals, result;
  int i, count;
  count = sizeof(standard_items);
  if (count<1) return 0;
  removals = ({});
  result = 0;
  report ("About to get standard items. Initial number of items: " + count);
  for (i=count-1;i>=0;i--)
  { 
    report ("item " + i);
    if (!objectp(standard_items[i]))
    {
      report ("not a valid item. Adding to removals");
      removals += ({standard_items[i]});
//      standard_items -= ({standard_items[i]});
      continue;
    }
    report ("checking if it is the one we are looking for");
    if (standard_items[i]->id(what))
    {
      result = standard_items[i];
    }
  }
  count = sizeof(removals);
  if (count>0)
  {
    for (i=0;i<count;i++)
    {
      if (member_array(removals[i], standard_items)!=-1)
      {
        standard_items -= ({removals[i]});
      }
    }
  }
  return result;
}

void set_last_refresh(int t){
  LAST_REFRESH = 0;
}

void refresh_items(){
  string * items, * names;
  int i, count;
  object ob;
  items = ({"/d/common/obj/misc/rope", TABAXOBJ + "machete", "/d/common/obj/misc/bullseye", "/d/common/obj/misc/oil", "/d/common/obj/misc/climb_tool", "/d/antioch/antioch2/obj/iron_rations", TABAXOBJ + "canteen"});
  names = ({ "rope", "machete", "bullseye", "oil", "climbing tools", "rations", "water canteen" });
  count = sizeof(names);
  if (count>0)
  {
    for (i=0;i<count;i++)
    {
      ob = get_standard_item(names[i]);
      if (objectp(ob)) continue;
      ob = present(names[i], TO);
      if (!objectp(ob))
      {
        ob = new(items[i]);
        if (objectp(ob))
        {
          ob->move(TO); 
          if (sizeof(standard_items)<1) standard_items = ({});
          standard_items+=({ob});
        }
      }
    }
  }
}

void init(){
  ::init();
  if (time() > LAST_REFRESH + 1200)
  {
    refresh_items();
  }
  set_max_internal_encumbrance(calculate_internal_encumbrance());
}

int wear_func(){
        tell_room(environment(ETO),ETO->QCN + " %^RESET%^buckles on " + ETO->QP + " utility belt and looks like a proper explorer",ETO);
        tell_object(ETO,"You buckle on the belt and feel like a proper explorer");
        return 1;
}


