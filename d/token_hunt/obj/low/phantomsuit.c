#include <std.h>
#include <std.h>
inherit "/d/common/obj/armour/robe.c";


void create(){
::create();

set_name("garment");
set_id(({"garment","suit","phantom suit"}));
set_short("%^RESET%^P%^ORANGE%^h%^BOLD%^%^BLACK%^a%^RESET%^nt"+
"%^BOLD%^%^BLACK%^o%^RESET%^m S%^ORANGE%^u%^BOLD%^%^BLACK%^"+
"i%^RESET%^t");
set_obvious_short("%^RESET%^a g%^ORANGE%^r%^BOLD%^%^BLACK%^a"+
"%^RESET%^y suit");
set_long("%^BOLD%^%^BLACK%^This garment is crafted of the "+
"strangest of materials.  At one time it seems like a thin "+
"sheath of textured %^RESET%^h%^ORANGE%^i%^BOLD%^%^BLACK%^d"+
"%^RESET%^e %^BOLD%^%^BLACK%^and at the other it as soft "+
"and fluid as the most expensive %^BLUE%^s%^RESET%^%^BLUE%^"+
"i%^BOLD%^%^BLACK%^l%^BLUE%^k%^BLACK%^.  A %^RESET%^g"+
"%^ORANGE%^r%^BOLD%^%^BLACK%^a%^RESET%^y %^BOLD%^%^BLACK%^"+
"hued material, the garment is designed as one piece and "+
"yet fits over both the legs and upper body creating a "+
"full suit.  The pants portion are %^BLUE%^b%^RESET%^"+
"%^BLUE%^i%^BOLD%^%^BLACK%^l%^RESET%^%^BLUE%^l%^BOLD%^owy"+
"%^BLACK%^, tapering from a narrow waist outward to wide "+
"cuffs that can be tucked into one's boots.  The torso "+
"portion is similarly designed in the sleeves, making "+
"them %^RESET%^l%^ORANGE%^o%^BOLD%^%^BLACK%^o%^RESET%^se "+
"%^BOLD%^%^BLACK%^and %^BLUE%^b%^RESET%^%^BLUE%^i%^BOLD%^"+
"%^BLACK%^l%^RESET%^%^BLUE%^l%^BOLD%^owing%^BLACK%^, "+
"though the shirt itself fits snuggly and is fastened by "+
"three %^RESET%^b%^ORANGE%^o%^BOLD%^%^BLACK%^n%^RESET%^e "+
"%^BOLD%^%^BLACK%^toggles along the left half of the "+
"breast.  What makes the garment strange is that when it "+
"is worn, the wearer only seems to partially be standing "+
"there.%^RESET%^");

set_lore("Beings of immense power, Thoughtslayers hail from a "+
"world well beyond the one in which we live.  A world of "+
"endlessly shifting and constantly changing reality.  At "+
"least when perceived by our mortal eyes.  Tough it is "+
"common to call them all 'thoughtslayers' this is a "+
"misnomer since there are as many different types of "+
"entities in their realm as there are in ours and not all "+
"are hostile.  At least, in so much as a cow is hostile "+
"to the grass it chews, except that the creatures of this "+
"other realm dine upon the thoughts and emotions of our "+
"minds eventually snuffing them out like a candle gone "+
"dry of wax.\n\n"+
"Of interest, when these creatures come to our realm they "+
"are often ethereal and garments made from their hides are "+
"often prized by those that walk between realms and "+
"shadows for this very reason.\n\n"+
"From the 'Lore of Alternate Realms' by Ikordis Malarn");
set_property("lore difficulty",14);
set_value(0);
set_size(-1);
   while ((int)TO->query_property("enchantment") != 2) {
     TO->remove_property("enchantment");
     TO->set_property("enchantment",2);
   }
set_item_bonus("stealth",1);
set_overallStatus(220);
set_wear((:TO,"wear_fun":));
set_remove((:TO,"remove_fun":));
set_property("no disenchant",1);
}

int wear_fun(){
//Was thief only, but changed to monk and bard per request - Octothorpe 2/4/17
//if(!ETO->is_class("thief") || !ETO->is_class("monk") || !ETO->is_class("bard")){ using || here means that if they are not all 3 of these classes it will fail to fit - Saide
if(!ETO->is_class("thief") && !ETO->is_class("monk") && !ETO->is_class("bard")) {
tell_object(ETO,"%^BOLD%^%^BLACK%^Seems the garment "+
"doesn't really fit you.%^RESET%^");
return 0;
}

tell_room(EETO,"%^BOLD%^%^BLACK%^"+ETO->QCN+" slips the "+
"%^RESET%^g%^ORANGE%^r%^BOLD%^%^BLACK%^a%^RESET%^y%^BOLD%^"+
"%^BLACK%^ suit on and seems to almost disappear!"+
"%^RESET%^",ETO);

tell_object(ETO,"%^BOLD%^%^BLACK%^The %^RESET%^g%^ORANGE%^r"+
"%^BOLD%^%^BLACK%^a%^RESET%^y%^BOLD%^%^BLACK%^ suit fits "+
"perfectly!%^RESET%^");

ETO->setenv("MINVIS","%^BOLD%^%^BLUE%^$N's garment ripples in "+
"an unfelt wind and then they are no more!%^RESET%^");
ETO->setenv("MVIS","%^BOLD%^%^BLUE%^Reality peels back slowly, "+
"revealing $N beside you!%^RESET%^");
return 1;
}

int remove_fun(){
tell_room(EETO,"%^BOLD%^%^BLACK%^"+ETO->QCN+" removes the "+
"%^RESET%^g%^ORANGE%^r%^BOLD%^%^BLACK%^a%^RESET%^y%^BOLD%^"+
"%^BLACK%^ suit.%^RESET%^",ETO);
tell_object(ETO,"%^BOLD%^%^BLACK%^Reality seems much more "+
"solid as you remove the %^RESET%^g%^ORANGE%^r%^BOLD%^"+
"%^BLACK%^a%^RESET%^y%^BOLD%^%^BLACK%^ suit.%^RESET%^");

ETO->setenv("MINVIS","$N seems to disappear.");
ETO->setenv("MVIS","$N appears out of the corner of your eye.");
return 1;
}