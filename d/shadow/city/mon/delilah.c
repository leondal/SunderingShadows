//Octothorpe (1/17/17)
//Shadow, Delilah Comp Vendor
//Designed by Ivyes
//Adapted from /d/attaya/newseneca/mon/octavia.c

#include <std.h>
#include "../defs.h"
inherit "/std/comp_vend.c";

void buff_up(object myself, object target, int stage);
void summon_familiar(object myself, object familiar);

void create()
{
   object ob;
   ::create();
   set_name("delilah");
   set_id(({
      "delilah","Delilah","proprietor","shopkeep"
   }));
   set("aggressive",0);
   set_short("%^BOLD%^%^GREEN%^Delilah Ilan, %^RESET%^%^GREEN%^"+
      "Proprietor of Sticks and Stones%^RESET%^");
   set_long("%^RESET%^%^GREEN%^Delilah is a small woman, well past "+
      "her prime. She has clung to a shadow of her former beauty "+
      "though, with her curiously %^BOLD%^vivid green eyes %^RESET%^"+
      "%^GREEN%^and %^BOLD%^%^RED%^cherry red lips%^RESET%^%^GREEN%^. "+
      "Her %^BOLD%^%^BLACK%^dark hair %^RESET%^%^GREEN%^has started "+
      "to show signs of %^BOLD%^%^BLACK%^g%^RESET%^r%^BOLD%^%^BLACK%^"+
      "ay%^RESET%^in%^BOLD%^%^BLACK%^g%^RESET%^%^GREEN%^, adding a "+
      "hint of sophistication to her long, straight locks. Her "+
      "movements carry a strange, %^BOLD%^serpentine %^RESET%^"+
      "%^GREEN%^grace. It is rumored that Delilah runs her shop on a "+
      "'%^WHITE%^Don't ask, Don't Tell%^GREEN%^' policy, often catering "+
      "to %^BOLD%^%^BLACK%^seedier %^RESET%^%^GREEN%^clients that "+
      "require some of the more controversial components.%^RESET%^");
   set_gender("female");
   set_alignment(6);
   set_race("human");
   set_class("mage");
   set_hd(40,8);
   set_level(40);
   set_guild_level("mage",40);
   set_body_type("human");
   set_property("no bump",1);
   set_components(100);
   set_spell_chance(100);
   set_spells(({
      "fireball","lightning bolt","acid arrow","powerword stun","incendiary cloud","magic missile"
   }));
   set_property("strength","spells");
   ob = new(MON"cat.c");
   ob->set_property("my_master",TO);
   TO->set_property("my_familiar",ob);
   call_out("summon_familiar",1,TO,ob);
}

void summon_familiar(object myself, object familiar)
{
   if((!objectp(familiar)) || (!objectp(TO)) || (!objectp(ETO))) return;
   familiar->move(environment(myself));
   tell_room(ETO,capitalize(familiar->query_name()) + " hops up onto "+
      "a cushioned pedestal.");
   call_out("buff_up",1,myself,familiar,1);
   call_out("buff_up",6,myself,myself,2);
   return;
}

void buff_up(object myself, object target, int stage)
{
   if((!objectp(target)) || (!objectp(myself)) || (!objectp(environment(myself)))) return;
   if(!present(target,environment(myself))) return;
   switch(stage++)
   {
      case 1:
         new("/cmds/spells/a/_armor.c")->use_spell(myself,(string)target->query_name(),40,120,"mage");
         call_out("buff_up",0,myself,target,stage);
         break;
      case 2:
         new("/cmds/spells/s/_stoneskin.c")->use_spell(myself,(string)target->query_name(),40,120,"mage");
         break;
      default:
         break;
   }
   return;
}