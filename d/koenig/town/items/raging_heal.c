#include <std.h>
inherit POTION;
int num;

  int side_effect();
void create() {
  ::create();
  set_name("raging heal");
  set_id( ({"vial","strong heal","vial of healing"}) );
  set_short("%^BOLD%^%^WHITE%^A small glass vial%^RESET%^");
  set_long("%^RESET%^A %^ORANGE%^r%^RED%^e%^ORANGE%^ddis%^RED%^h-g%^ORANGE%^o%^RED%^ld%^RESET%^ colored potion swirls in the small vial.");
  set_lore("You seem to recall that this particular potion is quite good at healing, but it's not without some strange side-effects.");
  set("color", "redishgold");
  set("effect_time", 0);
  set_value(100);
  set_weight(2);  // added by Styx 6/21/03, thanks to a bug report telling us
}
int do_effect() {
  int healing;
    set("effect_time",(random(5)*60));
    if(drinker->query_hp() < drinker->query_max_hp()) {
    healing = random(8) + random(8) + random(8) + 3;
    tell_object(drinker, "%^BOLD%^%^CYAN%^You begin to feel refreshed.\n");
    tell_object(drinker, "You have gained back "+healing+" hit points.\n");
    say("%^BOLD%^%^CYAN%^"+TPQCN+" drinks the potion and looks refreshed.\n");
    drinker->add_hp(healing);
} else {
  tell_object(drinker, "You feel no different from before.\n");
  say(TPQCN+" drinks the potion but appears uneffected.\n");
}
    call_out("side_effect",5);
}
int side_effect() {
  object *inven;
  int i,j;
  tell_object(drinker,"%^RESET%^%^RED%^You begin to feel an uncontrollable %^BOLD%^RAGE%^RESET%^%^RED%^!%^RESET%^\n");
  say("%^RED%^"+TPQCN+" drinks the potion and becomes enraged!\n");
    inven=all_inventory(environment(drinker));
  j=sizeof(inven);
  for(i=0;i<j;i++) {
  if(living(inven[i])) {
   if(inven[i] != drinker) drinker->kill_ob(inven[i],1);
}
}
  return 1;
}
int do_wear_off() {
    object *attackers;
    tell_object(drinker,"You suddenly feel sedate.");
    tell_room(environment(drinker),drinker->query_cap_name()+" suddenly "+
        "looks sedate.",drinker);
    attackers=drinker->query_attackers();
    for(num=0;num<sizeof(attackers);num++) {
        attackers[num]->cease_all_attacks();
    drinker->cease_all_attacks();
    }
  return 1;
}
