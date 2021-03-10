//Added Callista miniquest query - Octothorpe 2/1/10
// updated dex bonus from the new system. Nienne, 09/07.

#include <std.h>
inherit "/d/common/obj/armour/studded";

void create(){
   ::create();
   set_name("leather bodice");
   set_id(({"bodice","body armor","armor","leather","mesh","calarmor"}));
   set_short("%^RESET%^%^MAGENTA%^Callista's Bodice%^RESET%^");
   set_obvious_short("%^RESET%^%^MAGENTA%^A revealing leather "+
      "bodice%^RESET%^");
   set_long("%^BLUE%^This suit of leather armor is form-fitting and "+
      "specifically designed for the female body. The front panel of "+
	  "the armor is made from stiff, inflexible, %^MAGENTA%^violet "+
	  "leather%^BLUE%^ that is sure to provide good protection. %^BOLD%^"+
	  "%^WHITE%^Titanium%^RESET%^%^BLUE%^ clasps up the front of the "+
	  "bodice allow the armor to be buckled closed.  The armor is cut "+
	  "rather low and is rather revealing of the female's torso.  The "+
	  "cups of the bodice are covered with a soft %^MAGENTA%^velvet"+
	  "%^BLUE%^, in a matching hue.  The strapless armor though often "+
	  "leaves others to wonder how well something this skimpy might "+
	  "protect in battle.  Something about this bodice makes you feel "+
	  "like you want to %^BOLD%^<%^RESET%^%^BLUE%^jiggle%^BOLD%^> "+
      "%^RESET%^%^BLUE%^in them.%^RESET%^\n");
   set_lore("This leather and mesh bodice is the armor that the duelist "+
      "Callista is rumored to have worn when she was last seen in "+
	  "Seneca a couple centuries ago.  Being a warrior of stealth "+
	  "and speed, Callista prized herself on being able to move with "+
	  "ease in combat, but still having a good amount of protection.  "+
	  "The armor is designed to play with a women's body to prey on "+
	  "the lustful nature of men, and proves that the apple hasn't "+
	  "fallen too far from Magus Prime's tree.");
   set_size(2);
   set_value(15000);
   set_property("lore",24);
   set_property("enchantment",5);
   set_wear((:TO,"wear_func":));
   set_remove((:TO,"remove_func":));
}

void init(){
   ::init();
   add_action("jiggle","jiggle");
}

int wear_func(){
   object ob;
   /* Borrowed idea for body type check from /d/antioch/valley/obj/nymph_dress2_in.c.  Removed well-built from restricted list of body types. - Octothorpe 2/2/10 */
   if((string)TP->query_gender() != "female" || member_array((string)ETO->query_body_type(),({"plump","hardy","stocky","portly","stout","brawny","massive","rotund","heavy"})) != -1 ){
      tell_object(ETO,"Your body will not fit into this.");
      return 0;
   }
   if(base_name(ETO) == "/d/attaya/mon/callista") return 1;
   if(base_name(ETO) != "/d/attaya/mon/callista"){
      if((int)ETO->query_highest_level() < 25 || member_array("Deadly Beauty, Defeated Callista",ETO->query_mini_quests()) == -1) {   
        tell_object(ETO,"%^MAGENTA%^This bodice refuses to be worn by "+
		   "one as weak as yourself!");
		return 0;
      }
   }
   /* Borrowed from /d/attaya/senund/obj/emdagger.c & rubysword.c, since I couldn't come up with a better way to do it which wouldn't be thwarted by wear order. - Octothorpe 2/2/10 */
   if((ob = present("pants of the enchantress",ETO)) && living(ETO) && ob != TO){
      set_item_bonus("dexterity",2);
   }
   else{
      set_item_bonus("dexterity",1);
   }
   tell_room(EETO,"%^MAGENTA%^"+ETOQCN+" buckles herself into the "+
      "strapless leather bodice that molds to her curves.",ETO);
   tell_object(ETO,"%^MAGENTA%^You buckle yourself into the "+
      "strapless leather bodice, feeling the leather mold to "+
	  "your curves.");
   return 1;
}

int remove_func(){
	tell_room(EETO,"%^MAGENTA%^"+ETOQCN+" loosens the buckles of the "+
	   "bodice, slipping out of the form fitting leather.",ETO);
	tell_object(ETO,"%^MAGENTA%^You loosen the buckles of the bodice, "+
	   "slipping out of the leather with a wistful sigh.");
	return 1;
}

int jiggle(string str){
   if(!str){
      tell_object(ETO,"%^MAGENTA%^You jiggle your bosom, giggling as "+
         "you show off your ample cleavage.");
      tell_room(EETO,"%^MAGENTA%^"+ETOQCN+" jiggles her bosom, laughing "+
         "seductively as she shows off her ample cleavage.",ETO);
      return 1;
   }
}