//Added Lore - Cythera 4/05
#include <std.h>
#include "../ruins.h"
inherit "/d/common/obj/armour/fullplate";

int OWNED;
string owner;

void create()
{
        ::create();
        set_name("%^BOLD%^%^WHITE%^Diamond Fullplate%^RESET%^");
        set_short("%^BOLD%^%^WHITE%^Diamond Fullplate%^RESET%^");
        set_obvious_short("%^BOLD%^%^WHITE%^A suit of plate made from diamond%^RESET%^");
        set_id(({"plate","diamond fullplate","diamond plate",
		"Diamond Fullplate","full plate","fullplate","armor"}));
     set_long(
      "%^WHITE%^%^BOLD%^This beautiful suit of fullplate appears to have been"+
      " crafted out of solid diamond! It is incredibly lovely, the diamond has"+
      " been cut to perfection, hiding the areas where the pieces join together"+
      " with ingeniously cut facets in the stone. The smooth suit of armor is"+
      " on the thin side, the diamond shell forming to the contours of its "+
      "owner's body.  Though the armor is not thick like steel plate mail, there"+
      " is no question in the protective power that the diamond grants it.  "+
      "It is truly a work of art,"+
      " and undoubtedly magic had a hand in its making. %^RESET%^"      );
     set_lore("This splendid suit of armor was created for the "+
          "White Blade, Enriqes Thaldale.  Earning his nickname the"+
          " White Blade by the massive two handed bastard sword Enriqes"+
          " wielded in battle, he was a fearsome sight to behold in battle"+
          " it is said. Pledging himself to the service of Helm the Guardian,"+
          " Enriqes served as the personal bodyguard for a half-elf priestess"+
          " of Lathander named Shalam Zarathal.  Shalam was an unusual "+
          "priestess, even in the faith of the Morninglord.  While her "+
          "fellow clerics and priests armored themselves with plate and "+
          "chain, Shalam rejected the use of armor.  Claiming to follow an"+
          " obscure order called Mystics, Shalam felt the armor and arms that"+
          " her fellow priests wore only put people on the edge.  Though Shalam"+
          " was no fool, she knew that she would require the a bodyguard as she"+
          " traveled the lands carrying the message of Lathander.  Enriqes the "+
          "White Blade and Shalam found themselves dragged into many adventures "+
          "and quests of great importance.  Shalam came to rely on Enriqes fully"+
          " in their travels, for he always thought about her safety above hers."+
          "  To honor his dedication as a guardian, it is said that Shalam herself"+
          " gathered the diamonds for the armor and used her divine powers to fashion"+
          " a suit of armor for her loyal bodyguard. - The Way of the Guardian - "+
          "Yaman Hedgewood");
        set_property("lore",14);
        set_value(20000);
        set_property("enchantment",2);
        set_item_bonus("damage resistance",1);
        set_item_bonus("sight bonus",1);
        set_wear((:TO,"wearme":));
        set_remove((:TO,"removeme":));
        set_struck((:TO,"strikeme":));
}

void init()
{
        ::init();
        if(!interactive(TP)) return;
      if(stringp(owner)) return;
        if(interactive(TP) && (ETO == TP) /*&& !OWNED*/) {
                owner = (string)TP->query_name();
                //OWNED = 1;
        }
}

int wearme()
{
        if((string)ETO->query_name() != owner) {
                tell_object(ETO,"%^BOLD%^The Diamond Fullplate shimmers in rage as you"+
                " attempt to steal it from its rightful owner!\n"+
                "%^RESET%^The brilliant light of the fullplate has blinded you!");
                tell_room(environment(ETO),"%^BOLD%^The Diamond Fullplate shines"+
                " brightly as "+ETO->query_cap_name()+" tries to put it on.",ETO);
                ETO->set_blind(1);
                return 0;
        }
        if(ALIGN->is_evil(ETO)) {
                tell_object(ETO,"The Diamond Fullplate refuses the foul touch"+
				" of your hands!");
                tell_room(environment(ETO),"The Diamond Fullplate"+
				" disappears as "+ETO->query_cap_name()+""+
                " tries to master it!",ETO);
                TO->remove();
                return 0;
        }
   if(ETO->query_property("evil item")) {
      tell_object(ETO,"The diamond plate refuses to be worn while you are
using such evil items!");
      return 0;
   }
        if(ALIGN->is_good(ETO)) {
                tell_object(ETO,"%^BOLD%^You feel the strength of the hard diamond"+
                " supporting your cause.");
                tell_room(environment(ETO),"%^BOLD%^There is almost an audible click"+
                " as the Diamond Fullplate locks into place around "+ETO->QCN+"'s"+
                " body.",ETO);
      ETO->set_property("good item",1);
                return 1;
        }
        tell_object(ETO,"%^BOLD%^You almost feel overwhelmed by the hard and"+
        " unyielding diamond as it surrounds you.");
   ETO->set_property("good item",1);
        return 1;
}

int removeme()
{
  if(ALIGN->is_good(ETO)) {
   tell_object(ETO,"The diamond plate almost seems reluctant to leave you,"+
         " but it complies.");
   ETO->set_property("good item",-1);
   return 1;
        }
  tell_object(ETO,"You feel freed from the weight of the Diamond Fullplate.");
  ETO->set_property("good item",-1);
  return 1;
}

int strikeme(int damage, object what, object who)
{
  if(!random(3)) {
    if(objectp(what)) {
       tell_object(ETO,"%^RESET%^%^CYAN%^The Diamond Fullplate seems impervious to"+
         " the blows of the "+what->query_short()+".");
       return (-1)*(damage/4);
           }
       tell_object(ETO,"%^BOLD%^%^CYAN%^The Diamond Fullplate repels the"+
         " blows that "+who->query_cap_name()+" makes against you!");
       tell_object(who,"%^BOLD%^%^CYAN%^"+ETO->QCN+"'s diamond"+
         " plate seems to repel your blows!");
       tell_room(environment(query_worn()),"%^BOLD%^%^CYAN%^"+ETO->QCN+"'s"+
         " diamond plate seems to repel "+who->QCN+"'s blows!",({who,ETO}));
       return (-1)*damage;
        }
       return 1;
}

void set_owner(string str)
{
        owner = str;
        //OWNED = 1;
}

string query_owner() { return owner; }
int is_metal() { return 0; } //not metal
