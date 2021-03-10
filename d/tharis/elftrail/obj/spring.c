#include <std.h>
inherit OBJECT;

create() {
   ::create();
   set_name("mirror");
   set_id(({"mirror","pool","spring"}));
   set_short("");
   set_property("no animate", 1);
   set_long((:TO,"spring_desc":));
   set("value", 1001);
   set_weight(100000);
   set_no_clean(1);
   set_heart_beat(1);
}

int get() { return 0; }
int drop() { return 1; }

string spring_desc(){
   if(TO->query_property("magic mirror"))
     return("The waters of this natural spring are sparkling and clear. Rising up from deep inside the earth, these "
"waters are bone chillingly cold.  A faint aura is present as a shimmer across the water's surface.");
   if(((int)TP->query_skill("spellcraft")+roll_dice(1,20)) > 40)
     return("The waters of this natural spring are sparkling and clear. Rising up from deep inside the earth, these "
"waters are bone chillingly cold.  The surface of the water is so clear, you suspect it could be used as a focus for "
"arcane scrying attempts.");
   return("The waters of this natural spring are sparkling and clear. Rising up from deep inside the earth, these "
"waters are bone chillingly cold.");
}

void heart_beat() {
   if ((string)TO->query_short() != "") TO->set_short("");
}
