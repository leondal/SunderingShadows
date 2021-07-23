#include <std.h>
inherit ARMOUR;

int tracker;

void create(){
::create();

set_name("boots");
set_id(({"boots","phantom boots","knee-high boots"}));
set_short("%^RESET%^P%^ORANGE%^h%^BOLD%^%^BLACK%^a%^RESET%^nt"+
"%^BOLD%^%^BLACK%^o%^RESET%^m B%^ORANGE%^o%^BOLD%^%^BLACK%^"+
"o%^RESET%^ts");
set_obvious_short("%^RESET%^a g%^ORANGE%^r%^BOLD%^%^BLACK%^a"+
"%^RESET%^y set of knee-high boots");

set_long("%^BOLD%^%^BLACK%^These strange boots come up to "+
"the knee and can be worn with the knee flap either raised "+
"or turned down.  The odd %^RESET%^g%^ORANGE%^r%^BOLD%^"+
"%^BLACK%^a%^RESET%^y %^BOLD%^%^BLACK%^material is at once "+
"like a thin sheath of textured %^RESET%^h%^ORANGE%^i"+
"%^BOLD%^%^BLACK%^d%^RESET%^e %^BOLD%^%^BLACK%^and at the "+
"other it as soft and fluid as the most expensive %^BLUE%^"+
"s%^RESET%^%^BLUE%^i%^BOLD%^%^BLACK%^l%^BLUE%^k%^BLACK%^.  "+
"Somewhat stretchy, the material easily slides up the leg "+
"stretching to accomidate any size calf.%^RESET%^");

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
"often lighter then anything found in this world.  Some "+
"even provide enhanced movements and are prized for the "+
"mobility and lightness they imbue.\n\n"+
"From the 'Lore of Alternate Realms' by Ikordis Malarn");
set_property("lore difficulty",14);

set_weight(4);
set_value(0);
set_type("clothing");
set_limbs(({ "left foot","right foot" }));
set_size(-1);
   while ((int)TO->query_property("enchantment") != 1) {
     TO->remove_property("enchantment");
     TO->set_property("enchantment",1);
   }
//set_property("enchantment",1);
set_wear((:TO,"wear_fun":));
set_remove((:TO,"remove_fun":));
   set_overallStatus(220);
   set_property("no disenchant",1);
}

int wear_fun(){

tell_room(EETO,"%^BOLD%^%^BLACK%^"+ETO->QCN+" slips the "+
"%^RESET%^g%^ORANGE%^r%^BOLD%^%^BLACK%^a%^RESET%^y%^BOLD%^"+
"%^BLACK%^ boots on and smoothes down the knee flap."+
"%^RESET%^",ETO);

tell_object(ETO,"%^BOLD%^%^BLACK%^The %^RESET%^g%^ORANGE%^r"+
"%^BOLD%^%^BLACK%^a%^RESET%^y%^BOLD%^%^BLACK%^ boots feel "+
"light as air!  Almost like you could take %^WHITE%^"+
"flight%^BLACK%^.%^RESET%^");
return 1;
}

int remove_fun(){

tell_room(EETO,"%^BOLD%^%^BLACK%^"+ETO->QCN+" removes the "+
"%^RESET%^g%^ORANGE%^r%^BOLD%^%^BLACK%^a%^RESET%^y%^BOLD%^"+
"%^BLACK%^ boots.%^RESET%^",ETO);

tell_object(ETO,"%^BOLD%^%^BLACK%^You feel more solid as "+
"you remove the %^RESET%^g%^ORANGE%^r%^BOLD%^"+
"%^BLACK%^a%^RESET%^y%^BOLD%^%^BLACK%^ boots.%^RESET%^");
return 1;
}

int flight(string str){
if(TP->query_bound() || TP->query_unconscious()){
TP->send_paralyzed_message("info",TP);
return 1;
}

if(!TO->query_worn()){
notify_fail("%^BOLD%^%^BLACK%^How can you fly without "+
"wearing your boots?%^RESET%^");
return 1;
}

if(tracker > time()){
tell_object(TP,"%^BOLD%^%^BLACK%^You've already flown "+
"enough for one day.  Try walking.%^RESET%^");
return 1;
}

tracker = time() + 14400;
tell_object(TP,"%^BOLD%^%^BLACK%^You concentrate for a "+
"moment and soon feel light as air.%^RESET%^");
new("/cmds/spells/l/_levitate")->use_spell(TP,TP,20,100,"mage");
return 1;
}

void init(){
   ::init();
   add_action("flight","flight");
}