/*  NOTES 
A daemon to randomize items to find on searching or on mobs on Deku

Added psion components.  Circe 6/13/07

Added mid scroll and high scroll options to adapt for higher level areas.  Use sparingly.  Circe

Adding food and drink as options for use in areas people get stuck in where the totally random stuff could be truly useful or even lifesaving *Styx* 5/26/06

To use this in a room, you should set it up like:
"/d/common/daemon/randstuff_d"->find_stuff(TO,"magic",random(20))
where the arguments mean:
1) TO to carry the object into the function.
2) "magic" = which items (case of the switch) you want to be found
   Cases of the switch are: "stuff", "component", "psi_component", "scroll", "kit", "potion", "coins", "highscroll", "midscroll"
3) (optional) random(number) quantity to be found for uses of kits, qty of a
     component, etc.  Can be a non-random of course also.
I set some maximums with each for each to help avoid unreasonable amounts 
  from typos, etc.  For coins, the qty will be for gold coins.
Some types will ignore qty and the others have a default amount if it returns
  zero from a random or isn't set at all.

To use on a created monster:
   mon = new(MON+bigbunny); 
   "/d/common/daemon/randstuff_d"->find_stuff(mon,"random",100);

END NOTES  */

#include <std.h>
#include "/d/common/common.h"

inherit DAEMON;

int make_food();
int make_drink();

#define PSI_COMPS ({"aventurine","bloodstone","carnelian","leopard agate","sunstone","apatite","wemic tears","adamite","malachite","mottled jasper","unakite","flowstone","tektite","yellow calcite"})

#define COMPS ({ "adders stomach", "aluminum chaff", "bat guano", "bit of bone", "blessed leather", "clear crystal", "dart", "dragon scale", "drop of blood", "dung scrapings", "earth from grave", "iron rod", "eyelash", "eyelash of ogre-mage", "feather", "firefly", "gum arabic", "minute tarts", "pearl", "piece of bone", "phosphorus", "phosphorescent moss", "piece of iron", "piece of reed", "pinch of special dust", "powdered rhubarb leaf", "powdered silver", "spider web", "sulfur", "talc", "tiny bag", "zinc" })

#define STUFF ({ "beacon", "bullseye", "climb_tool", "fishing_rod", "flint", "oil", "rope", "sack", "thief_tools", "wood", "darkbeacon", "darkoil", "soap" }) 

#define RAND ({ "stuff", "component", "psi_component", "scroll", "kit", "kit", "kit", "potion", "coins", "coins", "misc", "food", "drink" })

#define MISC ({"/d/azha/obj/mr_ring", "/d/azha/obj/mr_ring", "/d/azha/obj/gmr_ring.c", "/d/antioch/valley/obj/gem", "/d/antioch/valley/obj/gem", "/d/newbie/obj/misc/gem" })

void find_stuff(object me, string which, int qty) {
int i;
object ob;
string *list;
object item;
//NOTE - Do NOT change any of the existing cases below because they might be called 
//by something, but adding new ones (along with a defined list) is fine.
  if(which == "random")   which = RAND[random(sizeof(RAND))];
   switch(which) {
     case "component" : 
        ob = new("d/magic/store_comp");
        i = random(sizeof(COMPS));
        ob->set_name(COMPS[i]);
        ob->set_id(({COMPS[i],"component"}));
        ob->set_short(capitalize(COMPS[i])+" (a spell component)");
        if(qty > 0 && qty < 50) {ob->set_comp_quantity(qty); break; }
        ob->set_comp_quantity(random(10)+1);
        break;
     case "psi_component" : 
        ob = new("d/magic/store_psi_comp");
        i = random(sizeof(PSI_COMPS));
        ob->set_name(PSI_COMPS[i]);
        ob->set_id(({PSI_COMPS[i],"component","crystal"}));
        ob->set_short(capitalize(PSI_COMPS[i])+" (a psionic crystal)");
        if(qty > 0 && qty < 50) {ob->set_comp_quantity(qty); break; }
        ob->set_comp_quantity(random(10)+1);
        break;
     case "scroll" : 
       ob = new("/d/magic/scroll");
       ob->set_spell(random(4)+1);
       break;
     case "highscroll" : 
       ob = new("/d/magic/scroll");
       ob->set_spell(random(5)+4);
       break;
     case "midscroll" : 
       ob = new("/d/magic/scroll");
       ob->set_spell(random(4)+3);
       break;
     case "kit" :
        ob = new(HEALKIT);
        if(qty > 0 && qty < 50) {
          ob->set_uses(qty); 
          ob->move(me);
          break; 
        }
        ob->set_uses(random(10)+4);
        ob->move(me);
        break;
     case "potion" :
       	if(!random(4)) {ob = new(CPOTION"invisible"); break; }
        if(!random(4)) {ob = new(CPOTION"det_invis"); break; }
        if(!random(4)) {ob = new(CPOTION"cure_poison"); break; }
        if(!random(4)) {ob = new(CPOTION"paralyze"); break; }
        if(!random(4)) {ob = new(CPOTION"cure_blindness"); break; }
        ob = new(CPOTION"hurt");  break;
     case "stuff" :
       item = STUFF[random(sizeof(STUFF))];
       ob = new(CMISC""+item);
       break;
     case "coins" :
       ob = new("/std/obj/coins");
       if(qty > 0 && qty < 500) { 
         ob->set_money("gold", qty);
         break;
       } 
       ob->set_money("gold", random(200)+50);
       ob->set_money("silver", random(200));
       break;
    case "misc":
       item = MISC[random(sizeof(MISC))];
       ob = new(item);
       break;
    case "food" : 
       ob = make_food();
       break;
    case "drink" :
       ob = make_drink();
       break;
 
 //default in case of a typo or otherwise invalid argument
     default :
       item = STUFF[random(sizeof(STUFF))];
	    ob = new(CMISC""+item);
	    break;
    }
    ob->move(me);
}

void treas_chest(object me, int gems, int gold) {
   object obj;
   object money;
   if(gold > 1000)  gold = 1000;
   if(gems > 5) gems = 5;
   obj = new("/d/common/obj/misc/treas_chest");
   obj->set_key("chestkey");
   obj->set_short("A large treasure chest");
   obj->set_name("treasure chest");
   money = new("/std/obj/coins");
   money->set_money("gold",random(100)+gold);
   money->set_money("electrum",random(200)+gold);
   money->set_money("silver",random(500)+gold);
   money->move(obj);
   if(gems){
     switch(gems){
       case 0:
         new("/d/antioch/valley/obj/gem")->move(obj);
       case 1:
         new("/d/antioch/valley/obj/gem")->move(obj);
       case 2:
         new("/d/antioch/valley/obj/gem")->move(obj);
         break;
       case 3:
         new("/d/newbie/obj/misc/gem")->move(obj);
       default:
         new("/d/newbie/obj/misc/gem")->move(obj);
         break;
      }
   }
//   obj->toggle_closed();
   obj->set_closed(1);
   obj->set_lock("unlocked");
   obj->set_lock_difficulty(50);
   obj->move(me);
}

int make_food() {
   object food;
   food = new("/std/food.c");
   food->set_name("scrap of food");
   food->set_short("%^BOLD%^%^BLACK%^A dark scrap of food%^RESET%^");
   food->set_id(({"food","scrap","scrap of food"}));
   food->set_long("This is a scrap of food that, lucky for you, still looks edible."
	"  It looks like it might have once been a piece of jerky although "
	"it could also have been any number of other things that simply "
	"dried out and turned rather blackish brown." );
   food->set_weight(1);
   food->set_value(0);
   food->set_destroy();
   food->set_strength(10);
   food->set_my_mess("You chew briefly on the dry scrap of food and swallow hard to get it down.");
   food->set_your_mess("chews briefly on the dry scrap of food and then swallows hard to get it down.");
   return food;
}

int make_drink() {
   object drink;
   drink = new("std/drink");
   drink->set_name("water");
   drink->set_id( ({ "drink", "liquid", "clear liquid" }) );
   drink->set_short("A bottle of clear liquid");
   drink->set_long("This is a small bottle containing a few ounces of "
	"clear liquid.  Closer examination leads you to conclude it's "
	"probably water but there's probably no way to know for sure "
	"without drinking it and seeing what happens."); 
   drink->set_type("water");
   drink->set_weight(1);
   drink->set_value(0);
   drink->set_destroy();
   drink->set_strength(10);
   drink->set_empty_name("bottle");
   drink->set_my_mess("You take a swig of the liquid and it does taste like water.");
   drink->set_your_mess("takes a swig of the clear liquid and looks relieved.");
   return drink;
}
