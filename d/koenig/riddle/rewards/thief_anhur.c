//thief_anhur.c - reward for Riddle Quest.  ~Circe~ 5/27/08
#include <std.h>
#include "../../nereid.h"
inherit NHAT;

void create(){
   ::create();
   set_name("battle veil");
   set_id(({"veil","battle veil","battle veil of the warhawk","mask","linen mask","black linen mask"}));
   set_short("%^BOLD%^%^BLACK%^Battle Veil of the %^RED%^Warhawk%^RESET%^");
   set_obvious_short("A black linen mask");
   set_long("%^BOLD%^%^BLACK%^Made from supple, silent black linen, "+
      "this mask is designed to cover the wearer's head much like "+
      "the headpieces of desert wanderers.  A single piece of linen "+
      "wraps around the top and supports a veil that covers the "+
      "the wearer's entire face, revealing only the %^RESET%^eyes "+
      "%^BOLD%^%^BLACK%^through a narrow slit.  Worked into the "+
      "linen winding around the head is a subtle design of "+
      "%^RESET%^%^RED%^hawks %^BOLD%^%^BLACK%^stitched in "+
      "muted red.%^RESET%^");
   set_lore("Veils such as this one were created to be worn "+
      "by members of the elite fighting and scouting forces "+
      "dedicated to Anhur and known as the Warhawk's Eyes.  "+
      "Rumors of their existence are whispered throughout the "+
      "realms, but no known member of the group has ever been "+
      "captured and revealed to be a member.  The veils have "+
      "spread to others, but they are still used exclusively "+
      "by those who follow Anhur.  The Warhawk's Eyes are a "+
      "highly respected group who are called in to perform "+
      "difficult tasks, such as scouting out the enemy's "+
      "encampments or taking out a particularly difficult "+
      "figure.");
   set_property("lore difficulty",12);
   set_remove((:TO,"remove_func":));
}

int remove_func(){
   tell_room(EETO,"%^BOLD%^%^BLACK%^"+ETOQCN+" unwraps the "+
      "linen and removes "+ETO->QP+" veil.%^RESET%^",ETO);
   tell_object(ETO,"%^BOLD%^%^BLACK%^You unwrap the veil and "+
      "lower it, feeling a bit too exposed.%^RESET%^");
   return 1;
}
