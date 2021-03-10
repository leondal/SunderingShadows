#include <std.h>
#include <magic.h>
inherit OBJECT;

int defender;
void remove_me();
void notify_me();

void create() {
   ::create();
   set_name("templeward");
   set("id", ({ "templewardxxx"}) );
   set("short", "");
   set("long", "");
   set_weight(0);
   set_property("no animate",1);
   set_heart_beat(1);
}

void init() {
   ::init();
   if(userp(ETO)) call_out("notify_me",1);
   add_action("switch_me","templeward");
   add_action("help_me","help");
}

void heart_beat() 
{
   if(!objectp(TO)) return;
   if(!objectp(ETO)) { remove_me(); return; }
   if(!userp(ETO)) { remove_me(); return; }
   if(!objectp(EETO)) { remove_me(); return; }
   if(!EETO->is_temple()) { remove_me(); return; }
   if(sizeof(ETO->query_attackers())) EETO->trigger_ward();
}

int save_me(string file) { return 1; }

int switch_me(string str) {
   if(!userp(ETO)) TO->remove();
   if(ETO != TP) return 0;
   if(!str) return notify_fail("%^BOLD%^%^CYAN%^You can declare yourself with "
"%^YELLOW%^<templeward defender>%^CYAN%^ or %^YELLOW%^<templeward "
"bystander>%^CYAN%^.%^RESET%^\n");
   if(str == "defender") {
     tell_object(TP,"%^BOLD%^%^CYAN%^You concentrate for a moment, making it "
"clear by your thoughts that you stand as a protector of this place.  Somehow, "
"you get the feeling you have been understood.%^RESET%^");
     defender = 1;
     return 1;
   }
   if(str == "bystander") {
     tell_object(TP,"%^BOLD%^%^CYAN%^You concentrate for a moment, making it "
"clear by your thoughts that you are simply a bystander here, should combat "
"break out.  Somehow, you get the feeling you have been understood.%^RESET%^");
     defender = 0;
     return 1;
   }
   if(str == "check") {
     if(defender) tell_object(TP,"%^BOLD%^%^CYAN%^You are currently understood "
"to be a defender of this temple.%^RESET%^");
     else tell_object(TP,"%^BOLD%^%^CYAN%^You are currently understood to be a "
"bystander in this temple.%^RESET%^");
     return 1;
   }
   return notify_fail("Please see <help templeward> for syntax.\n");
}

void remove_me() 
{
   if(!objectp(TO)) return;
   if(!objectp(ETO)) 
   {
       TO->remove();
       return;
   }
   if(!objectp(EETO))
   {
       TO->remove();
       return;
   }
   if(userp(ETO) && base_name(EETO) != "/d/magic/room/templeward") tell_object(ETO,"%^BOLD%^%^CYAN%^A shiver runs "
"through you as you pass outside the ward, and its presence fades from you.%^RESET%^");
   TO->remove();
}

void notify_me() {
   tell_object(ETO,"%^BOLD%^%^CYAN%^The tingling sensation of a protective ward "
"passes over you.  You instinctively get the feeling that if you bring your "
"intentions to mind, they will be heeded.  Please see %^YELLOW%^<help "
"templeward>%^CYAN%^ for syntax.%^RESET%^\n");
}

int is_combatant() { return defender; }

int help_me(string str) {
   if(!str) return 0;
   if(str != "templeward") return 0;
   tell_object(TP,"%^BOLD%^%^WHITE%^By default, you will be considered an "
"uninvolved bystander if any combat begins within a temple.  Should combat "
"break out, only those within the direct combat, and those who indicate that "
"they are defenders of the temple, will be captured by the protective ward.\n\n"
"%^BOLD%^%^WHITE%^Please use %^YELLOW%^<templeward defender>%^WHITE%^ if you "
"wish to be involved in any potential temple defense.  %^YELLOW%^<templeward "
"bystander>%^WHITE%^ may be used later to return you to neutral status within "
"the temple.  %^YELLOW%^<templeward check>%^WHITE%^ will notify you of your "
"current status.  Leaving temple grounds will reset you to the status of a "
"bystander.%^RESET%^");
   return 1;
}