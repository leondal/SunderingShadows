#include "/d/islands/giant/giant.h";

inherit WEAPON;

void create(){
   ::create();
   set_id(({"club","studded club"}));
   set_name("studded club");
   set_short("%^WHITE%^%^BOLD%^A Steel Studed Club%^RESET%^");
   set_long(
@TERRATO
   This is a large wooden club with raised steel
studds attached to the head, a crude weapon, but very
effective.
TERRATO
   );
   set_weight(15);
   set_size(3);
   set("value",700);
   set_wc(1,10);
   set_large_wc(3,7);
   set_type("bludgeoning");
   set_hit((:TO, "hit_fun":));
}
int hit_fun(object targ){

   if(random(5) == 4){
      tell_object(TP, "%^RED%^The club bashes your foe's skull in!%^RESET%^");
      tell_object(targ, "%^RED%^The club wielded by "+TPQCN+" bashes your skull in!%^RESET%^");
      tell_room(ETP, "%^RED%^"+TPQCN+"'s club bashes "+TP->query_possessive()+" foe's skull in!%^RESET%^", (({targ,TP})));
      return (random(4)+1);
   }
   return 0;
}
