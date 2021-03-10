//Removed references to old gods ~Circe~ 7/30/19
#include <std.h>
inherit "/d/common/obj/clothing/magerobe.c";

void create(){
	::create();
	set_name("robe of sunlight");
     set_id(({"robe","robe of sunlight","golden robe"}));
     set_short("%^RESET%^%^ORANGE%^Robes of %^YELLOW%^S%^RESET%^%^ORANGE%^u"+
        "%^YELLOW%^n%^WHITE%^l%^YELLOW%^i%^WHITE%^g%^RESET%^%^ORANGE%^h%^BOLD%^t%^RESET%^");
     set_obvious_short("%^YELLOW%^A thin golden robe%^RESET%^");
     set_long("%^ORANGE%^Glittering brightly the thin cloth of this robe radiates with %^RED%^warmth%^ORANGE%^ and %^BOLD%^%^WHITE%^light%^RESET%^%^ORANGE%^.  The %^YELLOW%^golden%^RESET%^%^ORANGE%^ cloth shifts slightly in hues of %^YELLOW%^yellow%^RESET%^%^ORANGE%^, %^BOLD%^%^WHITE%^white%^RESET%^%^ORANGE%^, and g%^YELLOW%^o%^RESET%^%^ORANGE%^ld%^YELLOW%^e%^RESET%^%^ORANGE%^n orange - each shade just as bright as the other.  The slim robe has a rounded neckline.  Cut down the front of the robe, are narrow but deep triangles, resembling the rays of a sun.  Cloth woven of pure %^YELLOW%^gold%^RESET%^%^ORANGE%^ offers coverage for the more modest folk who might wear this robe.  Over this robe a second layer melds seamlessly.  The outer robe is made from %^RESET%^semi-transparent %^ORANGE%^threads of %^YELLOW%^l%^WHITE%^i%^YELLOW%^g%^WHITE%^h%^YELLOW%^t%^RESET%^%^ORANGE%^.  The shapeless outer robe sways with even the slightest movement as it shimmers brightly.  Cut full, the semi-transparent robe gathers in %^YELLOW%^golden%^RESET%^%^ORANGE%^ pools of light and cloth.%^RESET%^\n");
      set_value(1500);
	set_lore("The Robe of Sunlight were made for a small order of sun elf mages devoted to Jarmila.  The Singers of Dawn's Golden Light spent most of their time working on spells that would work in harmony with nature, encouraging growth to areas affected by destruction.  The Dawnsingers - as they came to be known - fought bitterly against those who followed the the path of destruction and those of the Nilith the most.");
	set_property("lore difficulty",16);
	set_property("enchantment",3);
	set_ac(0);
      set_type("clothing");
      set_limbs(({"torso"}));
      set_max_internal_encumbrance(21);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
	set_struck((:TO,"strike_func":));
}
int wear_func(){
   if(member_array("%^BOLD%^%^CYAN%^Lucid Dreams%^RESET%^",ETO->query_mini_quests())== -1) {
      tell_object(ETO,"You have not earned the right to make use of this item.");
      return 0;
   }
  if((int)ETO->query_highest_level() < 25) {
    tell_object(ETO,"You are to weak to wear these robes!.");
        return 0;
   }
if((string)ETO->query_diety() == "jarmila") {
      	tell_object(ETO,"%^YELLOW%^Sliding into"+
			" the golden robe, a feeling of warmth washes over you.");
      	tell_room(environment(ETO),"%^YELLOW%^"+ETO->QCN+""+
      		" slides into "+ETO->QP+" golden robe, the "+
                  "cloth glowing with a bright radiance.",ETO);
				set_item_bonus("magic resistance",1);
                        set_item_bonus("sight bonus",5);

      return 1;
   	}else{
		tell_room(environment(ETO),"%^ORANGE%^"+ETOQCN+" slips in"+
			" a golden robe.",ETO);
		tell_object(ETO,"%^ORANGE%^You slip on the golden"+
			" robe, a slight wamrth seeps into your skin.%^RESET%^");
				set_item_bonus("magic resistance",1);
                        set_item_bonus("sight bonus",2);
	return 1;
	}
}
int remove_func(){
	if((string)ETO->query_diety() == "jarmila") {
      	tell_object(ETO,"%^YELLOW%^Sliding out of"+
			" the golden robe, the warmth fades away slowly.");
      	tell_room(environment(ETO),"%^YELLOW%^"+ETO->QCN+""+
      		" slides out of "+ETO->QP+" golden robe, the "+
			"glow of the cloth seems to lessen in intensity.",ETO);
	return 1;
	}
	else{
		tell_room(environment(ETO),"%^ORANGE%^"+ETOQCN+" slips "+
			"out of the golden robe.",ETO);
		tell_object(ETO,"%^ORANGE%^You slip out of the golden robe.");
        return 1;
	}
}
int strike_func(int damage, object what, object who){
	if(random(1000) < 125){
	tell_room(environment(query_worn()),"%^YELLOW%^Golden flames lick off "+
         "of "+ETOQCN+"'s robe, burning  "+
         ""+who->QCN+" in the process.",({ETO,who}));
	tell_object(ETO,"%^YELLOW%^Golden flames blaze to life in"+
        " your defense, burning "+who->QCN+".");
	tell_object(who,"%^YELLOW%^Golden flames blaze to life on"+
        " "+ETOQCN+"'s robe, burning you!");
			who->do_damage("torso",random(4)+6);
	}
}
