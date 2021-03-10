//Weapon hidden in the tree in the forest - centdagger.c

#include <std.h>
inherit "/d/common/obj/weapon/dagger.c";

void create() {
   ::create();
   set_id(({ "dagger", "pincer","crude dagger" })); /* player reference */
   set_name("dagger"); /* mud uses */
   set_short("%^RESET%^%^ORANGE%^Crude dagger%^RESET%^");
   set_long(
@STYX
%^ORANGE%^This is a particularly large and sharp looking pincer from a giant centipede.  Slightly curved between the base and the razor-sharp tip, it has barbs along the inner edge and is about six inches long.  The base where it was attached to the centipede is smooth and round and would provide a decent grip.  It looks like it would be a pretty effective weapon.%^RESET%^
STYX
   );
   set_weight(1);             /* in encumbrance */
   set_size(1);               /* 1-small 2-medium 3-large 4-huge */
   set_value(20);
   set_lore("This dagger was taken directly from the mouth "+
      "of a giant centipede.  Given the size of the dagger and "+
      "the obvious age, the centipede must have been ancient.  "+
      "Sages speculate that the barbs on the dagger might be "+
      "able to hold poison, but this is done rarely, as the "+
      "application in itself is dangerous.");
   set_property("lore difficulty",4);
//   set_cointype("copper")     /* specifies currency, defaults to gold */
   set_wc(1,4);               /* against small and medium */
   set_large_wc(1,3);         /* against large */
   set_type("piercing");  /* F/M/T types */
//   set_weapon_speed(4);       /* sets the speed of the weapon */
   set_hit( (:this_object(), "extra_hit":) );
}

int extra_hit(object ob)  {
    if(!objectp(ob)) return 1;
    if(random(8) < 2) {
        tell_object(ETO, "%^RED%^The barbs of the pincer make a ragged slash as you hit your opponent.");
        tell_object(ob, "%^RED%^"+ETO->query_cap_name()+"'s weapon makes a ragged slash as the sharp barbs scrape your exposed flesh.");
        tell_room(environment(query_wielded()), "%^RED%^The barbs on the pincer make a ragged slash on "+ob->query_cap_name()+"'s exposed flesh.", ({ob, ETO}) );
        return(1+random(3));
    }
}
