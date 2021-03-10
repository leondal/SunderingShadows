#include <std.h>
inherit "/std/armour";

void create()
{
   ::create();
   set_name("brooch");
   set_short("Brooch of Stalking");
   set_obvious_short("A bronze brooch");
   set_id(({"brooch","bronze brooch","stalking amulet"}));
   set_long("This is a bronze brooch.  Upon it is"+
   " etched several trees in a masterful fashion. "+
   " There are several small moonstones that line "+
   "the outside of the brooch.  A few strange runes"+
   " glow slightly on the back of the brooch.");
   set_lore("Elven hunters use these brooches to help"+
   " them stalk their game.  The enchanters in "+
   "Ashata'Rathai created these to reward good "+
   "hunters and to augment their skill.  Simply"+
   " _stalk_ to activate the enchantment upon the brooch.");
	set_property("lore difficulty",35);
   set_weight(2);
   set_limbs(({"neck"}));
   set_type("ring");
   set_value(1000);
}

void init() {
    ::init();
    add_action("stalk","stalk");
}
void stalk(string str){
   if(!objectp(ETO)){
   return 1; 
   }
   if(!TO->query_worn()){ 
        tell_object(ETO,"%^GREEN%^You must be wearing the brooch!");
   return 1; 
   }
   if (ETO->query_skill("survival") < 15) {
   tell_object(ETO,"%^GREEN%^Your unskilled self seems"+
   " to not know the ways of the wild enough to use this.");
   return 0;
   }
   tell_object(ETO,"%^GREEN%^You allow yourself to succumb to the call of the wilds "
"and disappear into the nature that surrounds you!");
   tell_room(EETO,"%^GREEN%^"+ETOQCN+" simply disappears into the "
    "surrounding wilderness!",ETO);
new("/cmds/spells/m/_meld_into_nature.c")->use_spell(ETO,ETO->query_name(),
10,100,"ranger");
   ETO->use_stamina(100);
   return 1;
}
