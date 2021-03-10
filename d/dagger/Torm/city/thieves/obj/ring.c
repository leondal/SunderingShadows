#include <std.h>

inherit "/d/common/obj/jewelry/ring.c";

void create(){
   ::create();
   set_name("Onyx Ring");
   set_id(({"ring","onyx ring","onyx","guild earring","packearring"}));
   set_obvious_short("%^BOLD%^%^BLACK%^an onyx ring%^RESET%^");
   set_short("%^BLACK%^%^BOLD%^An On%^RESET%^%^BOLD%^y%^BLACK%^%^BOLD%^x R%^RESET%^%^BOLD%^i%^BLACK%^%^BOLD%^ng%^RESET%^");
   set_long("This is a well constructed ring of some kind of"+
   " metal, perhaps an alloy of silver or platinum.  The band"+
   " is perfectly symmetrical, forming a flawless circle.  "+
   "Set at the top of the ring is a large spherical onyx "+
   "stone.  Upon closer inspection, it appears the stone was"+
   " magically created, as it has no bands of lighter material,"+
   " only pure darkness.  Its polished surface does not reflect "+
   "any color or light whatsoever, and staring at it for too long becomes disorienting.");
   set_lore("This is the signet ring of the Shades of Death, otherwise"+
   " known as the Pack, an old, now defunct guild dedicated to murder,"+
   " hedonism, and evil in general.  Normally only other guild members"+
   " would be able to identify an authentic guild symbol.  Whoever once "+
   "owned this specific ring has undoubtedly committed countless "+
   "atrocities and likely literally bathed in the blood of their "+
   "enemies.  The Shades of Death were comprised of many powerful "+
   "and infamous adventurers, led by an elven thief named Anna.  "+
   "Without exception, all members were evil to the core, and most "+
   "were dedicated to spreading their creed far and wide.  Despite "+
   "this, they were also zealously loyal to one another.   An attack"+
   " on one Pack member almost always resulted in immediate "+
   "retaliation by over a dozen others.   Wearing of the onyx ring "+
   "guild symbol by non-members also attracted lethal attention from"+
   " the Pack, who were known to attack first and ask questions later."+
   "  Legend tells of powerful magicks imbued into the stones which"+
   " would allow the guild's high commanders to instantly summon anyone"+
   " who wore a ring from anywhere in the multiverse, with or without"+
   " their consent.   Although some magic obviously still remains in "+
   "the ring, it is unlikely such power still exists in this world, "+
   "nor is it likely any high commanders yet live to make use of it,"+
   " so it is probably safe to wear..");

   set_property("lore difficulty",26);
   set_wear((:TO,"wear_fun":));
   set_remove((:TO,"remove_fun":));
   set_weight(1);
}
int wear_fun(){
   ETO->set_property("evil item",1);
   return 1;
}
int remove_fun(){
   ETO->set_property("evil item",-1);
   return 1;
}