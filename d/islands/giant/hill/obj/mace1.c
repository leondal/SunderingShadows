#include "/d/islands/giant/giant.h";

inherit WEAPON;

void create(){
   ::create();
   set_id(({"mace","giant mace"}));
   set_name("spiked mace");
   set_short("%^RESET%^%^BOLD%^A large spiked mace");
   set_long(
@TERRATO
   This mace has a large boulbous head covered with small spikes.  The
mace is of good construction and seems to have seen much use.  It is
plattered with the %^RED%^blood%^RESET%^ of fallen foes.
TERRATO
   );
   set_weight(15);
   set_size(3);
   set("value",700);
   set_wc(1,10);
   set_large_wc(3,7);
   set_type("bludgeoning");
   set_prof_type("mace");
   set_hit((:TO, "hit_fun":));
}
int hit_fun(object targ){

   if(random(5) == 4){
      tell_object(TP, "%^RED%^The mace bashes your foe's skull in!%^RESET%^");
      tell_object(targ, "%^RED%^The mace wielded by "+TPQCN+" bashes your skull in!%^RESET%^");
      tell_room(ETP, "%^RED%^"+TPQCN+"'s mace bash's "+TP->query_possessive()+" foe's skull in!%^RESET%^", (({targ,TP})));
      return (random(4)+1);
   }
   return 0;
}
