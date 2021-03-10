#include <std.h>
#include <magic.h>
#include <skills.h>
inherit OBJECT;

object myvictim;
int myduration;

void create() {
   ::create();
   set_name("");
   set("id", ({ "eldritch_glacial_xxx"}) );
   set("short", "");
   set("long", "");
   set_weight(0);
   set_property("no animate",1);
   set_property("no steal", 1);
   set_heart_beat(1);
   myduration = 0;
}

void activate(int duration) {
   int i;
   if(!objectp(ETO)) { TO->remove(); return; }
   if(!living(ETO)) { TO->remove(); return; }
   if(duration < 1) { TO->remove(); return; }
   if(duration < myduration) return; // this should allow the duration to be updated!

   myvictim = ETO;
   myduration = duration;
   myvictim->add_attack_bonus(-2);
   myvictim->add_saving_bonus("all",-2);
   for(i=0;i<sizeof(VALIDSKILLS);i++) myvictim->add_skill_bonus(VALIDSKILLS[i],-2);
}

void heart_beat() {
   int i;
   if(!objectp(myvictim)) { TO->remove(); return; }
   if(ETO != myvictim) { TO->remove(); return; }

   myduration--;
   if(myduration < 1) {
     tell_object(myvictim,"%^ORANGE%^The supernatural fear finally fades from you.%^RESET%^");
     myvictim->add_attack_bonus(2);
     myvictim->add_saving_bonus("all",2);
     for(i=0;i<sizeof(VALIDSKILLS);i++) myvictim->add_skill_bonus(VALIDSKILLS[i],2);
     TO->remove();
   }
}

int save_me(string file) { return 1; }

int move(mixed dest) {
   if(ETO && objectp(ETO))
      if(interactive(ETO))
         return 0;
   ::move(dest);
}