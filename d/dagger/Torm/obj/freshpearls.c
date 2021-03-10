#include <std.h>
inherit "/std/armour";

void create()
{
   ::create();
   set_name("freshwater pearls");
   set_short("A strand of freshwater pearls");
   set_id(({"pearls","freshwater paerls","strand of pearls","strand of freshwater pearls","pearl necklace"}));
   set_long("This is a beautiful strand of tiny freshwater pearls. They are"+
   " a bright white in color, but are not round like the salt water pearls."+
   " Instead each is unique and more oblong in shape, but they are all smooth"+
   " and pretty.");
   set_weight(1);
   set_type("ring");
   set_limbs(({"neck"}));
   set_value(150);
   set_wear("%^BOLD%^You slip the delicate strand of freshwater pearls around your neck.");
   set_size(random(3)+1);
}
