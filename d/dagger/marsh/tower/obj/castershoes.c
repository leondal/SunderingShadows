// updated to be more for item standards. N, 7/19
#include <std.h>
inherit ARMOUR;
void make_me();


#define COLORS ({"%^BOLD%^%^BLACK%^pitch black",\
"%^BOLD%^%^WHITE%^snow white",\
"%^BOLD%^%^RED%^cardinal red",\
"%^RESET%^%^RED%^blood red",\
"%^RESET%^%^ORANGE%^sunset orange",\
"%^RESET%^%^ORANGE%^walnut brown",\
"%^YELLOW%^goldenrod",\
"%^BOLD%^%^GREEN%^jade green",\
"%^RESET%^%^GREEN%^forest green",\
"%^BOLD%^%^BLUE%^cerulean blue",\
"%^RESET%^%^BLUE%^midnight blue",\
"%^RESET%^%^CYAN%^slate blue",\
"%^BOLD%^%^CYAN%^teal",\
"%^RESET%^%^MAGENTA%^violet",\
"%^BOLD%^%^MAGENTA%^bright pink",\
"%^BOLD%^%^BLACK%^charcoal gray",\
"%^BOLD%^%^GREEN%^emerald green",\
"%^BOLD%^%^BLUE%^sapphire blue",\
"%^RESET%^s%^BOLD%^i%^RESET%^l%^BOLD%^v%^RESET%^e%^BOLD%^r",\
"%^ORANGE%^g%^BOLD%^o%^RESET%^%^ORANGE%^l%^BOLD%^d",\
"%^BOLD%^%^RED%^ruby red",\
"%^BOLD%^%^WHITE%^light cream",\
"%^BOLD%^%^BLACK%^raven black",\
"%^BOLD%^%^CYAN%^sky blue",\
"%^MAGENTA%^wine",\
"%^BOLD%^%^MAGENTA%^pale pink",\
"%^CYAN%^sea-green"})
#define types ({"slippers","shoes","sandals"})

void create(){
      ::create();
   make_me();
   set_lore("The footwear of the those that tread within Demongate are rumored to be amongst some of the best designed in the realms."
" This is not only because of their superb craftsmanship and finest materials, but also because much care has been taken to embue them with "
"magical qualities from master enchanters.\n");
   set_property("lore difficulty",7);
   set_weight(2);
   set_value(300);
   set_type("clothing");
   set_limbs(({"right foot","left foot"}));
   set_size(-1);
   set_item_bonus("caster level",2);
   set_item_bonus("bonus_spell_slots", 2);
   set_property("enchantment",5);
set_wear((:TO,"wear_func":));
set_remove((:TO,"remove_func":)); 
      set_struck((:TO,"strikeme":));
}
void make_me(){
int i,x;
   string type, COLOR;
    i = random(sizeof(COLORS));
       COLOR = COLORS[i];
    x = random(sizeof(types));
       type = types[x];
   ::create();
   switch(type){
case "slippers":
TO->set_long("Crafted from the %^RESET%^%^MAGENTA%^finest %^ORANGE%^suede%^RESET%^, these slippers have been "
                "dyed "+COLOR+"%^RESET%^.  Light leather lines the soles of the slippers,"
                 " and soft %^BOLD%^%^WHITE%^fleece %^RESET%^lines the rounded toes.  Two long matching "+COLOR+" ribbons %^RESET%^can be used to wrap around"
                 " the wearers ankles to secure this %^BOLD%^%^CYAN%^dainty footwear %^RESET%^in place.\n");
   TO->set_name("Glory slippers");
   TO->set_short("%^YELLOW%^Glories %^RESET%^"+COLOR+" suede slippers%^RESET%^");
   TO->set_obvious_short("%^RESET%^"+COLOR+" suede slippers%^RESET%^");
   TO->set_id(({"slippers","suede slippers"}));
break;
case "shoes":
      TO->set_long("Crafted from %^RESET%^%^MAGENTA%^finest %^ORANGE%^suede %^RESET%^these shoes have been dyed"
" "+COLOR+"%^RESET%^.  The padded %^ORANGE%^leather soles %^RESET%^of the shoes"
" help to ensure the feet are kept safe from harm.  Pieced"
" together in sections, the seams of the shoes help to offer"
" a perfect tight fit.  The pointed toes shoes lace up the "
"front, letting the wearer determine just how tight to lace "
"them.  \n"); 
   TO->set_name("Glory shoes");
   TO->set_short("%^YELLOW%^Glories %^RESET%^"+COLOR+" suede shoes%^RESET%^");
   TO->set_obvious_short("%^RESET%^"+COLOR+" suede shoes%^RESET%^");
   TO->set_id(({"shoes","suede shoes"}));   
      break;
case "sandals":
      TO->set_long("Crafted from the %^RESET%^%^MAGENTA%^finest %^ORANGE%^woven suede strips%^RESET%^, these sandals "
"have been dyed "+COLOR+"%^RESET%^.  The %^ORANGE%^hard leather soles %^RESET%^of the"
" sandals help to ensure the feet are kept safe from harm.  The "
"%^ORANGE%^suede strips %^RESET%^work to mold around ones foot, offering a tight fit."
"  Three suede strips slip into three %^BOLD%^%^WHITE%^mithril"
"%^RESET%^ buckles, offering further control of fit to these sandals.\n");
   TO->set_name("Glory sandals");
   TO->set_short("%^YELLOW%^Glories %^RESET%^"+COLOR+" suede sandals%^RESET%^");
   TO->set_obvious_short("%^RESET%^"+COLOR+" suede sandals%^RESET%^");
   TO->set_id(({"sandals","suede sandals"}));
      break;
}
TO->add_id("randshoesxxx");
}
int wear_func(){
  // ETO->set_property("bonus_spell_slots",1);
    //ETO->set_property("magic resistance",10);
    return 1;
}
int remove_func(){
   //ETO->set_property("bonus_spell_slots",-1);
   //ETO->set_property("magic resistance",-10);
return 1;
}
int strikeme(int damage, object what, object who){
        if(!random(4)){
        tell_room(environment(query_worn()),"%^RESET%^%^CYAN%^"+ETOQCN+" looks rejuvenated as a strange %^BOLD%^mist %^RESET%^%^CYAN%^swirls around "+ETO->query_objective()+".",ETO);
        tell_object(ETO,"%^RESET%^%^CYAN%^A fine %^BOLD%^mist %^RESET%^%^CYAN%^rises from the shoes, leaving you feeling rejuvenated.");
        ETO->do_damage("torso",-1*random(20)+5);
        return 0;  
        }
    return damage;
}
