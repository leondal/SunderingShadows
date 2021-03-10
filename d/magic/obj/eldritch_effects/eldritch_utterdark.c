#include <std.h>
#include <magic.h>
inherit OBJECT;

object myvictim;
int myduration;

void create() {
   ::create();
   set_name("");
   set("id", ({ "eldritch_utterdark_xxx"}) );
   set("short", "");
   set("long", "");
   set_weight(0);
   set_property("no animate",1);
   set_property("no steal", 1);
   set_heart_beat(1);
   myduration = 0;
}

void activate(int duration) {
   if(!objectp(ETO)) { TO->remove(); return; }
   if(!living(ETO)) { TO->remove(); return; }
   if(duration < 1) { TO->remove(); return; }
   if(duration < myduration) return; // this should allow the duration to be updated!

   myvictim = ETO;
   myduration = duration;
   if(myvictim->query_property("utterdarked")) return;
   myvictim->add_stat_bonus("strength",-4);
   myvictim->set_property("utterdarked", 1);
}

void heart_beat() {
   if(!objectp(myvictim)) { TO->remove(); return; }
   if(ETO != myvictim) { TO->remove(); return; }

   myduration--;
   if(myduration < 1) {
     tell_object(myvictim,"%^CYAN%^The weakness finally eases from your limbs, and your strength returns.%^RESET%^");
     myvictim->add_stat_bonus("strength",4);
     myvictim->set_property("utterdarked", -1);
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