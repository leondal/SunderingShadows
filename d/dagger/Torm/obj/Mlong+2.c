// set to run from standard inherit. Nienne, 08/07.
#include <std.h>
inherit "/d/common/obj/weapon/longsword.c";

create() {
    ::create();
   set_id(({ "sword", "longsword", "long sword", "long","mithril sword","mithril longsword","mithril long sword","gilded longsword", }));
   set_name("gilded longsword");
   set_short("A%^YELLOW%^ gilded%^BOLD%^%^WHITE%^ mithril%^RESET%^ longsword");
    set_long(
      "%^BOLD%^"
      "  This is a bright silvery mithril longsword."
   "  It was forged by the Dwarves of Mt. Sholkum in the Dagger Reaches."
      "  Dwarven runes line the center of the blade and it glows with strength."
   "  From the gold glittering on the hilt and the runes it's obviously the weapon of an officer."
      "  On the hilt is the crest of the Army of the Dagger Reaches."
    );
//    set_weight(7);
//    set_size(2);
    set("value", 100);
//    set_wc(1,8);
//    set_large_wc(1,12);
//    set_type("slashing");
    set_property("enchantment",2);
    set_wield((:TO,"extra_wield":));
    set_hit((:TO,"extra_hit":));
}
int extra_wield(){
    if(!ETO) return 0;
  if(!interactive(TP)) return 1;
    if((int)ETO->query_level()<15){
  write("You don't feel you've earned the right to this officer's sword just yet.");
  tell_room(environment(ETO),""+ETO->query_cap_name()+" sighs as "+ETO->query_subjective()+" looks at a fine blade in "+ETO->query_possessive()+" hands.",ETO);
	return 0;
    }
    write("You admire the fine gold work as you wield the sword.");
  tell_room(environment(ETO),ETO->query_cap_name()+" admires the fine gold runes on their longsword for a moment.",ETO);
    return 1;
}
int extra_hit(object ob){
   if(!objectp(ob)) return 1;
    if(!random(3)){
	tell_object(ETO,"%^YELLOW%^The fine blade cuts deeply into "+ob->query_cap_name()+"!");
	tell_object(ob,"%^YELLOW%^"+ETO->query_cap_name()+"s sword slashes deeply into you!");
   tell_room(environment(ETO),"%^YELLOW%^"+ETO->query_cap_name()+" slashes deeply into "+ob->query_cap_name()+" with a gold gilded sword!",(({ETO,ob})));
	return (random(4)+1);
    }
    return 1;
}
