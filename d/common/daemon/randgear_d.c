/* ***  NOTES ****
A daemon to randomize (basic) weapons within types on mobs
including an option to randomly magically enchant them (+1, 2, or 3)

Arguments for the "arm_me"(TO,"edgedm",20,2,5) in the mob file are -
"edgedm" = lower case of array name (from geardefin.h) to be chosen from
(1st) number(up to 100) of the % chance of being enchanted.
(2nd) number(max is 3) of plusses to give the item, although curses can offset +'s
(3rd) number(use as % chance, up to 100) of the item being set to be a monsterweapon
Since the last 3 arguments are integers, omitting them doesn't error and
simply gives either no chance of enchantments, or the % chance of a +1 (or for the added third integer no chance of it being a monsterweapon)

Usage for a mob (if #include "/d/common/common.h") is RANDGEAR->arm_me(TO,..)
otherwise "/d/common/daemon/randgear_d"->arm_me(blah..) or armor_me(blah..)
to use for a room to use on a created monster - 
mon=new(MON+bigbunny); RANDGEAR->arm_me(mon,...);
The "arm_me" function is for items in /d/common/obj/weapon/ 
  "armor_me" is for /d/common/obj/armour/
  (filename = array member) 
Do be careful about balance issues with enchantments, especially on armor since it sizes to the mob.
by Styx, implemented July-Sept. 2001 with help from Garrett
Added argument for chance of making it a monsterweapon too per suggestion from Aelith *Styx* 3/15/02

adjusted to let it be used in room searches rather than just on mobs *Styx* 11/26/03, last change was 4/23/02

*** END NOTES ***
*/

#include <std.h>
#include "/d/common/common.h"
#include "/d/common/daemon/geardefin.h"

inherit DAEMON;

// enchant = 0; not needed - will default to 0 per Garrett
// per Garrett need to have the variables defined within each function so that
// a) they don't store and 
// b) won't accidently pass an unintended value

#define WPNLIST ([ "edgeds": EDGEDS, "edgedm":EDGEDM, "edgedl":EDGEDL, "polearm":POLEARM, "clubm":CLUBM, "blunts":BLUNTS, "bluntm":BLUNTM, "bluntl":BLUNTL, "tool":TOOL, ]) 

#define ARMORLIST ([ "armorlt":ARMORLT, "armornp":ARMORNP, "armorpl":ARMORPL, "armorcl":ARMORCL, "shield":SHIELD ])

// Be SURE to add new arrays in geardefin.h to the mapping for 
// #define WPNLIST, etc. above

void arm_me(object me, string which, int chance, int plus, int monweap) {
   string wpn;
   object ob;
   string *list;
   list = WPNLIST[which];
   wpn = list[random(sizeof(list))];
   ob = new(CWEAP""+wpn);
   if(chance > random(100)) {
	ob->set_property("enchantment", 1);
	if(plus == 2) ob->set_property("enchantment", 1);
        if(plus > 2)  ob->set_property("enchantment", 2);
	ob->set_long(ob->query_long()+"\nThis one seems very well made and "
	   "in extraordinary condition.");
        ob->set_value(ob->query_value()+(100 * (random(plus)+1)) );
   }
   ob->move(me);
   if(me->is_monster()) {  // added this check 11/26/03 *Styx*
      if(monweap > random(100)) 
         ob->set_property("monsterweapon", 1);
//inelegant solution to the problem with mobs not being able to wear shields after the order of limbs changed
//stop-gap until we figure out something better ~Circe~ 7/22/19
      if((which == "edgeds" || which == "edgedm" || which == "clubm" || which == "blunts" || which == "bluntsm") && member_array("left hand",(me->query_wielding_limbs()))){
         if(!me->query_weapon("left hand")){
            me->force_me("wield "+ob->query_name()+" in left hand");
         }else{
            me->force_me("wield "+ob->query_name()+"");
         }
      }else{
         me->force_me("wield "+ob->query_name()+"");
      }
   }
}

void armor_me(object me, string which, int chance, int plus, int monweap) {
   string armor;
   object ob;
   int size;
   string *list;
   list = ARMORLIST[which];
   armor = list[random(sizeof(list))];
   ob = new(CARMOUR""+armor);
   if(chance > random(100)) {
	ob->set_property("enchantment", 1);
	if(plus == 2) ob->set_property("enchantment", 1);
	if(plus > 2) ob->set_property("enchantment", 2);
	ob->set_long(ob->query_long()+"\nThis seems very well made and in "
          "extraordinary condition.");
        ob->set_value(ob->query_value()+(100 * (random(plus)+1)));
   }
   ob->move(me);
   if(me->is_monster()) {  // added this check 11/26/03 *Styx*
	size = me->query_size();
	ob->set_size(size);    // the gear in /d/common should have a default size
	if(monweap > random(100)) 
           ob->set_property("monsterweapon", 1);
 	me->force_me("wear "+ob->query_name());
   }
}

//leave this section in until I've changed all the original mobs to use arm_me

void equip_me(object me, string which, int chance, int plus) {
string wpn;
object ob;
string *list;
   list = WPNLIST[which];
   wpn = list[random(sizeof(list))];
	ob = new(CWEAP""+wpn);
	if(chance > random(100)) {
		ob->set_property("enchantment", 1);
		if(plus == 2) ob->set_property("enchantment", 1);
      if(plus > 2) ob->set_property("enchantment", 2);
		ob->set_long(ob->query_long()+"\nThis one seems very well made and "
		   "in extraordinary condition.");
      ob->set_value(ob->query_value()+100);
	}
	ob->move(me);
 	me->force_me("wield "+ob->query_name());
}
