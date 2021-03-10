// newbie/obj/clothing/kobvest.c

#include <std.h>
inherit ARMOUR;

void create() {
::create();
   set_name("vest");
   set_short("%^RED%^A smelly ragged red vest%^RESET%^");
   set_id(({"vest","red vest"}));
   set_long(
@STYX
This vest is ragged, grungy, and smells like the kobold it was taken from, something between a wet dog and stagnant water.
STYX
   );
   set_lore("This disgusting vest was taken from one of the "+
      "reptilian kobolds.  Kobolds often wear bright colors, "+
      "which end up dull and dingy much like this vest due "+
      "to the kobold's general lack of hygiene.  Most races "+
      "consider these beings filthy.");
   set_property("lore difficulty",2);
   set_weight(3);
   set_type("clothing");
   set_limbs(({"torso"}));
   set_value(1);
   set_cointype("copper");
   set_wear((:TO,"wearme":));
   set_remove((:TO,"removeme":));
   set_ac(0);
}

int wearme() {
   if(!interactive(TP)) return 1;
    TP->add_stat_bonus("charisma",-2);
    TP->set("long","%^ORANGE%^"+capitalize(nominative(TP))+" smells like "
       "something between a wet dog and stagnant water.");
    tell_object(TP,"The smell nearly gags you as you wear the vest.");
    tell_room(ETP,TPQCN+" stinks and looks wretched in the ragged "
       "vest.",TP);
    return 1;
}

int removeme() {
    ETO->add_stat_bonus("charisma",2);
    ETO->set("long",0);
    tell_object(ETO,"You feel better but like you still need a bath as you "
      "remove the vest.");
    tell_room(EETO,ETO->QCN+" isn't quite as smelly after removing "
      "the vest.",ETO);
    return 1;
}

