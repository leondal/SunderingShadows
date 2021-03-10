#include <std.h>
#include <magic.h>
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
   if(!objectp(ETO)) { TO->remove(); return; }
   if(!living(ETO)) { TO->remove(); return; }
   if(duration < 1) { TO->remove(); return; }
   if(duration < myduration) return; // this should allow the duration to be updated!

   myvictim = ETO;
   myduration = duration;
   myvictim->add_stat_bonus("dexterity",-4);
}

void heart_beat() {
   if(!objectp(myvictim)) { TO->remove(); return; }
   if(ETO != myvictim) { TO->remove(); return; }

   myduration--;
   if(myduration < 1) {
     tell_object(myvictim,"%^CYAN%^The bone-deep chill finally fades, and your movements return to normal.%^RESET%^");
     myvictim->add_stat_bonus("dexterity",4);
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