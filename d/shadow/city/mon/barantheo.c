//Titania (6/29/19)
//Shadow, Barantheo Comp Vendor
//Designed by Ivyes
//Adapted from /d/attaya/newseneca/mon/octavia.c

#include <std.h>
#include "../defs.h"
inherit "/std/comp_vend.c";

void buff_up(object myself, object target, int stage);

void create()
{
   object ob;
   ::create();
   set_name("barantheo");
   set_id(({
      "barantheo","Barantheo","proprietor","shopkeep"
   }));
   set("aggressive",0);
   set_short("%^RESET%^%^ORANGE%^Barantheo Moustachio, "+
   "Proprietor of the Mad Hat%^WHITE%^");
   set_long("%^RESET%^%^CYAN%^Barantheo is a %^BOLD%^round "+
   "%^RESET%^%^CYAN%^little gnome, with a big nose and and an "+ 
   "even bigger %^BOLD%^%^BLACK%^handlebar moustache%^RESET%^%^CYAN%^. "+ 
   "He is quite dapper in his %^BOLD%^%^BLACK%^top hat "+ 
   "%^RESET%^%^CYAN%^and %^BOLD%^%^BLACK%^fitted suit%^RESET%^%^CYAN%^, "+ 
   "complete with a %^BOLD%^%^WHITE%^silver-rimmed monocle "+ 
   "%^RESET%^%^CYAN%^set over a %^BOLD%^%^BLUE%^bright blue "+ 
   "eye%^RESET%^%^CYAN%^. He stands behind the counter, "+ 
   "looking eager to serve. Every now and then, a beady little "+ 
   "%^WHITE%^nose %^CYAN%^pokes out from beneath his "+ 
   "%^BOLD%^%^BLACK%^big hat%^RESET%^%^CYAN%^.%^WHITE%^");
   set_gender("male");
   set_alignment(6);
   set_race("gnome");
   set_class("mage");
   set_hd(40,8);
   set_level(40);
   set_guild_level("mage",40);
   set_body_type("gnome");
   set_property("no bump",1);
   set_components(100);
   set_spell_chance(100);
   set_spells(({
      "fireball","lightning bolt","acid arrow","powerword stun","incendiary cloud","magic missile"
   }));
   set_property("strength","spells");
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