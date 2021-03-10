//updated by Circe 4/24/04 to new desc, current code, etc.
#include <std.h>
inherit "/d/common/obj/armour/fullplate";

string OWNER;

void init() {
    ::init();
    if(interactive(TP) && TP==ETO && !OWNER) OWNER = TPQN;
}

void create() {
    ::create();
    set_name("armor of the crimson wave");
    set_id( ({"armor of the crimson wave", "armour", "armour of the crimson wave", "plate", "armor", "crimson", "crimson wave", "midnight"}) );
    set_obvious_short("%^RED%^Red plate armor%^RESET%^");
    set_short("%^RED%^Armor of the Crimson Wave%^RESET%^");
    set_long(
      "%^RED%^This well-crafted suit of armor has a dark red "+
      "hue and is highly %^BOLD%^reflective%^RESET%^%^RED%^.  "+
      "It almost seems as if it were formed from %^BOLD%^blood "+
      "%^RESET%^%^RED%^itself, as it has the same luster and "+
      "color.  It has been hardened past the point of steel and "+
      "seems as strong as adamantium.  The armor is constructed "+
      "unusually, as it is "+
      "made of several interlocking body plates that attach "+
      "themselves by unseen mechanisms.%^RESET%^"
    );
    set_lore("It is said that this unusual armor is indeed "+
      "made of blood.  The blood was enchanted by an altered "+
      "version of a spell that turns glass as hard as steel but "+
      "was used instead on a pool of blood.  The master craftsman "+
      "who made this armor was able to create this ghastly and "+
      "unusual set of plates with the help of an archmage.");
/*
This medium armor is painted a dark red and is highly reflective.  It looks like it were forged of blood itself as it has the same luster and color.  It is built of several interlocking body plates.
Old desc
*/
    set_value(32000);
    set_size(-1);
    set_property("enchantment",3);
    set_item_bonus("strength",2);
    set_wear((:TO, "extra_wear":));
    set_remove((:TO,"extra_unwear":));
}

int extra_wear() {
    if((string)TP->query_name() != OWNER) {
	tell_object(ETO,"%^RED%^The armor shreeks then explodes into "+
         "a million billion itty bitty pieces as a voice whispers in "+
         "your head, %^RESET%^You are not worthy!");
	TO->remove();
	return 0;
    }

    if((int)TP->query_level() < 25) {
	tell_object(ETO,"You are not ready for this armor.");
	return 0;
    }

    tell_object(ETO,"%^BOLD%^%^RED%^You connect the interlocking "+
       "plates of the Armor of the Crimson Wave.");
    tell_room(EETO,"%^BOLD%^%^RED%^"+ETOQCN+" begins connecting the "+
       "interlocking plates of "+ETO->QP+" armor.",ETO);
    return 1;
}

int extra_unwear(){
   tell_object(ETO,"%^RED%^You disconnect the plates, and they seem "+
      "to stack themselves much smaller than you would have imagined!");
   tell_room(EETO,"%^RED%^The plates of "+ETOQCN+"'s armor seem "+
      "to stack themselves as "+ETO->QS+" removes them.",ETO);
   return 1;
}