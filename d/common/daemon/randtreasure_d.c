/*  NOTES
Created by Circe 12/30/04 - based on generators by Styx and Bane
This is a random treasure generator to be used wherever.  Note that this is a list of common gear that could go in any area.  Make sure, though, that if you are allowing the possibility of scrolls, you choose the right level - scroll, midscroll, or highscroll.  This list includes gear - not armor or weapons.  There is another daemon - /d/common/daemon/randgear_d.c to handle those.

%^BOLD%^***NOTE*** %^RESET%^If you include /d/common/common.h in your file, you can just use RANDTREAS->find_stuff(TO,"stuff",3)

To use this in a room, you should set it up like:
"/d/common/daemon/randtreasure_d"->find_stuff(TO,"magic",random(20))
where the arguments mean:

1) TO to carry the object into the function.
2) "magic" = which items (case of the switch) you want to be found
   Cases of the switch are: "stuff", "component", "psi_component", "scroll", "kit", "coins", "highscroll", "midscroll", and "random"
3) (optional) random(number) quantity to be found for uses of kits, qty of a
     component, etc.  Can be a non-random of course also.
I set some maximums with each for each to help avoid unreasonable amounts
  from typos, etc.  For coins, the qty will be for gold coins.
Some types will ignore qty and the others have a default amount if it returns
  zero from a random or isn't set at all.

To use on a created monster:
   mon = new(MON+bigbunny);
   "/d/common/daemon/randstuff_d"->find_stuff(mon,"random",100);

Added psion components.  Circe 10/2/07

END NOTES  */

#include <std.h>
#include "/d/common/common.h"

inherit DAEMON;

#define CPOT "/d/common/obj/potion/"+
#define CINS "/d/common/obj/instruments/"+
#define CSHE "/d/common/obj/sheath/"+

#define COMPS ({ "adders stomach", "aluminum chaff", "bat guano", "bit of bone", "blessed leather", "clear crystal", "dart", "dragon scale", "drop of blood", "dung scrapings", "earth from grave", "iron rod", "eyelash", "eyelash of ogre-mage", "feather", "firefly", "gum arabic", "minute tarts", "pearl", "piece of bone", "phosphorus", "phosphorescent moss", "piece of iron", "piece of reed", "pinch of special dust", "powdered rhubarb leaf", "powdered silver", "spider web", "sulfur", "talc", "tiny bag", "zinc", "charcoal", "incense stick" })

#define PSI_COMPS ({"aventurine","bloodstone","carnelian","leopard agate","sunstone","apatite","wemic tears","adamite","malachite","mottled jasper","unakite","flowstone","tektite","yellow calcite"})

#define STUFF ({"/d/common/obj/misc/tobacco/luxury_of_tharis_tobacco", CMISC"backpack", CMISC"bait", CMISC"bandage",\
CMISC"bandoleer", CMISC"basket", CMISC"beacon", "/d/common/obj/misc/tobacco/tsarven_tobacco",\
"/d/common/obj/misc/tobacco/dwarfs_pride_tobacco", CMISC"bullseye", CMISC"chest", CMISC"climb_tool",\
"/d/common/obj/misc/tobacco/pirates_booty_tobacco", CMISC"darkbeacon", CMISC"darkoil", CMISC"eyepatch",\
CMISC"flint", CMISC"fishing_pole", CMISC"fishing_rod", CMISC"lantern",\
"/d/common/obj/misc/tobacco/halflings_homeblend_tobacco", CMISC"lkchest", CMISC"oil", CMISC"pouch", CMISC"rope",\
CMISC"sack", CMISC"sbasket", CMISC"schest", CMISC"soap", CMISC"spouch",\
CMISC"ssack", CMISC"thief_tools", CMISC"torch", "/d/common/obj/misc/tobacco/white_dragon_tobacco",\
CMISC"wood", CMISC"gem", CMISC"gem", CMISC"gem", CMISC"gem",\
CMISC"gem", CMISC"deckofcards", CMISC"die", CMISC"pipe",\
CPOT"cure_poison", CPOT"det_invis", CPOT"extra_heal", CPOT"heal",\
CPOT"hurt", CPOT"invisible", CPOT"paralyze", CPOT"poison",\
CPOT"raging_heal", CPOT"weaken", CINS"bagpipes", CINS"banjolele",\
CINS"bones", CINS"bongodrums", CINS"clavichord", CINS"drum",\
CINS"fiddle", CINS"flute", CINS"handbell", CINS"harmonica",\
CINS"hautbois", CINS"instrument_case", CINS"lap-harp", CINS"lute",\
CINS"lyre", CINS"mandolin", CINS"panpipes", CINS"shawm", CINS"tabor",\
CSHE"sheath_randomizer", CSHE"sheath_randomizer", CSHE"sheath_randomizer",\
CSHE"sheath_randomizer", CSHE"sheath_randomizer", CSHE"sheath_randomizer",\
CSHE"shieldstrap", "/d/tharis/obj/paper", "/d/tharis/obj/parchment",\
"/d/common/obj/armour/lrobe", "/d/common/obj/armour/srobe",\
"/d/laerad/parnelli/asgard/sewer/obj/bone_ring",\
"/d/laerad/parnelli/asgard/sewer/obj/mushroom",\
"/d/shadow/juran/weaps/jet_ring", "/d/tharis/obj/rings/sg",\
"/d/tharis/obj/rings/so", "/d/dagger/Torm/obj/eyepatch",\
"/d/dagger/Torm/obj/rags", "/d/dagger/Torm/obj/papyrus",\
"/d/newbie/obj/misc/rock", "/d/azha/obj/mr_ring", "/d/azha/obj/gmr_ring",\
"/d/antioch/valley/obj/herb", "/d/antioch/valley/obj/herb2",\
"/d/antioch/valley/obj/rope_belt", "/d/tharis/obj/clothing/gloves",\
"/d/tharis/obj/clothing/plcloak"})

#define RAND ({"stuff", "stuff", "stuff", "stuff", "stuff", "kit", "coins", "comps", "psi_component","scroll"})

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
     case "scroll" :
       ob = new("/d/magic/scroll");
       ob->set_spell(random(4)+1);
       break;
     case "highscroll" :
       ob = new("/d/magic/scroll");
       ob->set_av_spell(random(5)+4);
       break;
     case "midscroll" :
       ob = new("/d/magic/scroll");
       ob->set_av_spell(random(4)+3);
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
     case "psi_component" :
        ob = new("d/magic/store_psi_comp");
        i = random(sizeof(PSI_COMPS));
        ob->set_name(PSI_COMPS[i]);
        ob->set_id(({PSI_COMPS[i],"component","crystal"}));
        ob->set_short(capitalize(PSI_COMPS[i])+" (a psionic crystal)");
        if(qty > 0 && qty < 50) {ob->set_comp_quantity(qty); break; }
        ob->set_comp_quantity(random(10)+1);
        break;
     case "stuff" :
       item = STUFF[random(sizeof(STUFF))];
       ob = new(item);
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
 //default in case of a typo or otherwise invalid argument
     default :
       item = STUFF[random(sizeof(STUFF))];
	    ob = new(item);
	    break;
    }
    ob->move(me);
}
