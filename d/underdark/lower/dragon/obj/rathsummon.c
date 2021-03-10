#include <std.h>
#include <magic.h>
#include <daemons.h>
#include "../lair.h"
inherit OBJECT;

int tracker;
void start_me();

void create() {
   ::create();
   set_name("rath-summon");
   set("id", ({ "rath-summon"}) );
   set("short", "");
   set("long", "");
   set_weight(100000);
   set_property("no animate",1);
   tracker = 0;
}

void start_me() {
   object *fighterz, myrath, myarkhon;
   int i, j;

   fighterz = all_living(ETO);
   fighterz = filter_array(fighterz,"is_non_immortal",FILTERS_D);
   switch(tracker) {
     case 0:
       tell_room(ETO,"\n%^BOLD%^%^RED%^Arkhon sweeps his tail before him, sending you tumbling! He rears back, sorely "
"wounded, and lets out a snarl:%^RESET%^ Rath'argh, your master requires your aid!%^RESET%^");
       for(i = 0;i< sizeof(fighterz); i++) {
         if((string)fighterz[i]->query_name() == "Arkhon Bloodscale") fighterz[i]->remove_property("no paralyze");
         fighterz[i]->set_paralyzed(50,"%^BOLD%^%^WHITE%^You are trying to get back up!%^RESET%^");
       }
       for(i = 0;i< sizeof(fighterz); i++) {
         for(j = 0;j< sizeof(fighterz); j++) {
           if(fighterz[i] != fighterz[j]) fighterz[i]->remove_attacker(fighterz[j]);
         }
       }
       tracker++;
       call_out("start_me",2);
       break;
     case 1:
       tell_room(ETO,"\n%^BOLD%^%^CYAN%^As his forepaws hit the stone again with a rumble, the %^BOLD%^%^BLACK%^s%^RESET%^"
"ha%^BOLD%^%^BLACK%^dows %^BOLD%^%^CYAN%^shift and a slender figure appears.  The folds of his dark cloak settle to "
"reveal a drow, who smirks and dips into a bow:%^RESET%^ With pleasure, my lord.");
       for(i = 0;i< sizeof(fighterz); i++) {
         if(!fighterz[i]->query_paralyzed())
           fighterz[i]->set_paralyzed(50,"%^BOLD%^%^WHITE%^You are trying to get back up!%^RESET%^");
       }
       tracker++;
       call_out("start_me",2);
       break;
     case 2:
       tell_room(ETO,"\n%^BOLD%^%^CYAN%^Arkhon's tapered maw curls into a horrible, draconic parody of a grin, and he "
"advances once again upon you!%^RESET%^\n");
       for(i = 0;i< sizeof(fighterz); i++) {
         if(!fighterz[i]->query_paralyzed())
           fighterz[i]->set_paralyzed(50,"%^BOLD%^%^WHITE%^You are trying to get back up!%^RESET%^");
       }
       tracker++;
       call_out("start_me",2);
       break;
     default:
       if(!(myarkhon = present("arkhon",ETO))) {
         tell_room(ETO,"%^BOLD%^%^BLUE%^Error - please contact an imm.%^RESET%^");
         TO->remove();
         return;
       }
       for(i = 0;i< sizeof(fighterz); i++) fighterz[i]->set_paralyzed(0);
       myarkhon->set_property("no paralyze",1);
       for(i = 0;i< sizeof(fighterz); i++) {
         if(fighterz[i] != myarkhon) {
           myarkhon->add_attacker(fighterz[i]);
           fighterz[i]->add_attacker(myarkhon);
         }
       }
       myrath = new(MON"rathargh");
       myrath->move(ETO);
       new("/cmds/spells/s/_stoneskin")->use_spell(myrath,"rathargh",40,100,"mage");
       TO->remove();
       break;
   }
   return;
}

int drop() { return 1; }
int save_me(string file) { return 1; }
int is_detectable() { return 0; }
int query_invis() { return 1; }