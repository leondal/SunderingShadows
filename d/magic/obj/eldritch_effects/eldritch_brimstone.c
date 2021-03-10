#include <std.h>
#include <magic.h>
inherit OBJECT;

object myvictim;
int myduration,active,dmgboost;

void create() {
   ::create();
   set_name("");
   set("id", ({ "eldritch_brimstone_xxx"}) );
   set("short", "");
   set("long", "");
   set_weight(0);
   set_property("no animate",1);
   set_property("no steal", 1);
   set_heart_beat(1);
   myduration = 0;
   active = 0;
}

void activate(int duration,int clevel) {
   if(!objectp(ETO)) { TO->remove(); return; }
   if(!living(ETO)) { TO->remove(); return; }
   if(duration < 1) { TO->remove(); return; }
   if(duration < myduration) return; // this should allow the duration to be updated!

   myvictim = ETO;
   myduration = duration;
   dmgboost = clevel/2; // let's start out trying a damage bonus of half caster level on all ticks. If it still sucks, boost to full clevel later.
}

void heart_beat() {
   int dmg;
   if(!objectp(myvictim)) { TO->remove(); return; }
   if(ETO != myvictim) { TO->remove(); return; }
   if(!active) { active = 1; return; } // was double-ticking first round, this should delay the first damage tick.

   dmg = roll_dice(2,6)+dmgboost;
   tell_object(myvictim,"%^RED%^Unnatural flames continue to cling to you, burning horribly!%^RESET%^");
   myvictim->cause_typed_damage(myvictim,"torso",dmg,"fire");
   myduration--;
   if(myduration < 1) {
     tell_object(myvictim,"%^RED%^The unnatural flames finally die off.%^RESET%^");
     tell_room(environment(myvictim),"%^RED%^The unnatural flames dissipate from "+myvictim->QCN+"'s skin.%^RESET%^",myvictim);
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