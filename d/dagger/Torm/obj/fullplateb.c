//Complete revamp of old Brass Plate - cause we need more plates
//Cythera
#include <std.h>
inherit "/d/common/obj/armour/field.c";

void create() {
    ::create();
  set_name("brass fullplate");
  set_id(({"armor","full plate","plate","fullplate","brass fullplate","platemail","brass plate mail","platemail"}));
  set_obvious_short("%^YELLOW%^A suit of %^RESET%^%^ORANGE%^brass%^BOLD%^ plate mail%^RESET%^");
  set_short("%^YELLOW%^Plate of %^BOLD%^%^CYAN%^Dragon's%^YELLOW%^ Courage%^RESET%^");
  set_long(
   "%^YELLOW%^This impressive set of fullplate armor is made of brass that has been"+
   " polished enough to make it appear to be %^RESET%^%^ORANGE%^g%^YELLOW%^o%^RESET%^%^ORANGE%^l%^YELLOW%^d."
   "  The pieces of the armor are definitely the work of a master armorer, and"+
   " an artisan from the %^CYAN%^reliefs%^YELLOW%^ engraved into the chest and shoulders."
   "  Where the edges of the plate leave off, gleaming %^WHITE%^mithril%^YELLOW%^"+
   " chain links give evidence to a second layer of protection underneath."
   "  A brass and silk tasset wraps around the waist of the armor.  The "+
   "%^CYAN%^p%^BLUE%^a%^CYAN%^l%^BLUE%^e %^CYAN%^b%^BLUE%^l%^WHITE%^u%^CYAN%^e"+
   " %^YELLOW%^silk is embroidered with images of majestic %^BLUE%^dragons%^YELLOW%^, adding "+
   "to the commanding presence of the armor.  Plates of brass stack together"+
   " to create impressive shoulder guards, with similiar %^CYAN%^reliefs%^YELLOW%^ "+
   "of dragons on a stylized background around the edges.  Though made of brass, this fullplate"+
  " looks very regal.%^RESET%^"
       );
  set_value(3000);
  set_property("enchantment",2);
  set_item_bonus("magic resistance",1);
  set_wear((:TO,"wear_func":));
  set_remove((:TO,"remove_func":));
}

int wear_func(){
                tell_room(EETO,"Donning the suit of full plate "+ETOQCN+""+
                        " looks noble and regal.",ETO);
        tell_object(ETO,"You strap yourself into the plate mail, feeling"+
                        " regal and noble.");
                        return 1;
}
int remove_func(){
        tell_room(EETO,""+ETOQCN+" removes "+ETO->QP+" armor, looking sl"+
                        "ightly less noble.",ETO);
        tell_object(ETO,"You remove the plate mail, feeling slightly "+
                        "less noble and regal.");
                        return 1;
}

