//Added miniquest query - Octothorpe 1/31/10
//updated by Circe 9/7/04 with new desc

#include <std.h>;
inherit "/std/armour";

void create(){
   ::create();
   set_name("breeches");
   set_id(({"breeches","pants","leather breeches","leather pants", "pants of the enchantress"}));
   set_obvious_short("%^RESET%^%^MAGENTA%^pu%^BOLD%^r%^RESET%^%^MAGENTA%^ple "+
      "leather breeches%^RESET%^");
   set_short("%^RESET%^%^MAGENTA%^Pants of the %^BOLD%^E%^RESET%^%^MAGENTA%^n"+
	"%^BOLD%^%^BLUE%^c%^MAGENTA%^h%^RESET%^%^MAGENTA%^a%^BOLD%^%^BLUE%^n"+
	"%^MAGENTA%^t%^RESET%^%^MAGENTA%^r%^BOLD%^%^BLUE%^e%^RESET%^"+
	"%^MAGENTA%^s%^BOLD%^s%^RESET%^");
   set_long("%^BLUE%^%^BOLD%^This pair of breeches is made from tight-"+
      "fitting supple %^RESET%^%^MAGENTA%^pu%^BOLD%^r%^RESET%^"+
	  "%^MAGENTA%^ple leather%^BOLD%^%^BLUE%^.  The leather is thin "+
      "and form-fitting, accentuating every aspect of the wearer's "+
      "legs - good or bad.  Only the most self-assured would "+
      "probably wear such pants - though they would likely look "+
      "quite nice in them.  Deep V cutouts that taper off past mid-"+
	  "thigh, on each side %^RESET%^%^ORANGE%^e%^BOLD%^%^WHITE%^x"+
	  "%^RESET%^p%^ORANGE%^o%^BOLD%^%^WHITE%^s%^RESET%^e%^BOLD%^"+
	  "%^BLUE%^ the legs.  A single %^BOLD%^%^WHITE%^silver ring"+
	  "%^BLUE%^, on either side, holds the seams together, creating "+
	  "an %^RESET%^%^MAGENTA%^enchanting%^BOLD%^%^BLUE%^ look. "+
	  "Something about these pants makes you feel like you want to "+
      "%^BOLD%^%^MAGENTA%^<%^RESET%^%^MAGENTA%^wiggle%^BOLD%^> "+
      "%^BOLD%^%^BLUE%^in them.%^RESET%^\n");
   set_lore("Once crafted by an enchantress of reputable power became "+
	"identified with a woman by the name of Tiergaina.  Tiergaina "+
	"was often seen as an outcast by her fellow mages.  While they "+
	"rather spend time holed up in their towers, she was constantly "+
	"looking for the next adventure, for ancient ruins, and places of "+
	"forgotten lore and power.  While the stuffy mages may have snubbed"+
	" Tiergaina, it was said that because of her explorations that her "+
	"magical power rapidly advanced beyond some of her fellow magi.  "+
	"Never one to be seen in long robes or a pointy hat, Tiergaina "+
	"adopted a personal style that was a mix of the utilitarian as well"+
	" as striking in appearance.  The Enchantress, as she was sometimes "+
	"referred as, though made one bitter enemy in her lifetime.  A woman "+
	"by the name of Callista.  When trouble began to brew and fall on "+
	"Attaya, it was said that Tiergaina was one of the first to travel "+
	"there, looking to stop her nemesis once and for all.");
   set_property("lore",22);
   set_type("clothing");
   set_limbs(({"right leg","left leg"}));
   set_property("enchantment",5);
   set_weight(2);
   set_size(2);
   set_value(12500);
   set_wear((:TO,"wearme":));
   set_remove((:TO,"unwearme":));
}

void init(){
   ::init();
   add_action("wiggle","wiggle");
}

int wearme(){
   object ob;
   /* Borrowed idea for body type check from /d/antioch/valley/obj/nymph_dress2_in.c.  Removed well-built from restricted list of body types. - Octothorpe 2/2/10 */
   if((string)TP->query_gender() != "female" || member_array((string)ETO->query_body_type(),({"plump","hardy","stocky","portly","stout","brawny","massive","rotund","heavy"})) != -1 ){
      tell_object(ETO,"Try as you might, you just can't fit "+
         "into the pants!");
      return 0;
   }
   if(base_name(ETO) == "/d/attaya/mon/callista") return 1;
   if(base_name(ETO) != "/d/attaya/mon/callista"){
      if((int)ETO->query_highest_level() < 25 || member_array("Deadly Beauty, Defeated Callista",ETO->query_mini_quests()) == -1) {
         tell_object(ETO,"The pants refuse to be worn by one as weak "+
		    "as you!");
            return 0;
      }
   }
   /* Borrowed from /d/attaya/senund/obj/emdagger.c & rubysword.c, since I couldn't come up with a better way to do it which wouldn't be thwarted by wear order. - Octothorpe 2/2/10 */
   if((ob = present("calarmor",ETO)) && living(ETO) && ob != TO){
   set_item_bonus("charisma",3);
   }
   else{
    set_item_bonus("charisma",2);
   }
   tell_object(ETO,"%^BOLD%^%^MAGENTA%^You slip into the tight "+
      "leather pants and notice how nice your legs look.");
   tell_room(EETO,"%^BOLD%^%^MAGENTA%^"+ETOQCN+" slips into the "+
      "tight leather pants, drawing your eyes briefly to her shapely "+
      "legs.",ETO);
   return 1;
}

int unwearme(){
   tell_object(ETO,"%^MAGENTA%^You remove the pants, missing them "+
      "already.");
   tell_room(EETO,"%^BOLD%^%^MAGENTA%^"+ETOQCN+" removes the pants "+
      "with a soft sigh.",ETO);
   return 1;
}

int wiggle(string str){
   if(!str){
      tell_object(ETO,"%^MAGENTA%^You wiggle your bottom, giggling as "+
         "you show off your shapely legs.");
      tell_room(EETO,"%^MAGENTA%^"+ETOQCN+" wiggles her hips, laughing "+
         "seductively as she shows off her shapely legs.",ETO);
      return 1;
   }
}
