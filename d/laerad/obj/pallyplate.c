//Octothorpe (7/28/09)
//Laerad, Paladin Full Plate

#include <std.h>
inherit "/d/common/obj/armour/fullplate.c";

void create(){
   ::create();
   set_name("paladin fullplate");
   set_id(({"full plate armor","fullplate","fullplate armor","plate armor","armor","plate"}));
   set_short("Full plate armor of the Order");
   set_obvious_short("%^BOLD%^%^WHITE%^suit of fl%^RESET%^%^CYAN%^a%^BOLD%^"+
      "%^WHITE%^wless full pl%^RESET%^%^CYAN%^a%^BOLD%^%^WHITE%^te "+
	  "armor%^RESET%^");
   set_long("This is the impressive, high gothic style armor of the "+
      "late middle ages and renaissance.  It is perfectly forged and "+
	  "fitted.  All the plate are interlocking and carefully angeld to "+
	  "deflect blows.  The metal plates are backed by padding and "+
	  "chainmail.  The weight is well distributed.  The armor is "+
	  "crafted exclusively by holy dwarven smiths and blessed by "+
	  "clerics of renown power lending it a quality of cooled "+
	  "temperature and light weight.  It is worn by the loyal "+
	  "order of Paladins found within the realms.");
   set_lore("Legend holds that at the beginning of time all the "+
      "paladins of old were united under an organization known merely "+
      "as the Order. In the stories the full plate of the Order was "+
      "specially crafted by holy dwarven smiths, and blessed by clerics "+
      "of great renown. Obviously the stories are mere fairly tales "+
      "though - the idea that holy knights of Helm and Bane would "+
      "tolerate each other in the same organization is preposterous, "+
      "but who are you to scoff at legend?");
   set_value(20000);
   set_size(-1);
   set_property("lore difficulty",18);
   set_property("enchantment",3);
   if((int)TO->query_property("enchantment") < 3){
      remove_property("enchantment");
      set_property("enchantment",3);
   }
   set_property("no alter",1);
   set_item_bonus("will",1);
   set_item_bonus("magic resistance",1);
   set_wear((:TO,"wearme":));
   set_remove((:TO,"removeme":));
}

int wearme(){
   string god = ETO->query_diety();
   if(!ETO->is_class("paladin")){
      tell_object(ETO,"%^RED%^This armor cannot be worn without the "+
	     "rites of holy knighthood!%^RESET%^");
      return 0;
   }
   if((int)ETO->query_lowest_level() < 15){
      tell_object(ETO,"%^RED%^You have not been in the service of "+
	     "your deity long enough to wear this armor!%^RESET%^");
      return 0;
   }
   switch(god){
      case "kismet":
	     TO->set_short("%^BOLD%^%^CYAN%^Pl%^RESET%^%^CYAN%^a%^BOLD%^t"+
		    "%^RESET%^%^CYAN%^e o%^BOLD%^f th%^RESET%^%^CYAN%^e "+
            "%^BOLD%^S%^RESET%^%^CYAN%^i%^BOLD%^b%^RESET%^%^CYAN%^y"+
		    "%^BOLD%^ll%^RESET%^%^CYAN%^i%^BOLD%^n%^RESET%^%^CYAN%^e"+
		    "%^RESET%^");
		 TO->set_obvious_short("%^RESET%^%^CYAN%^suit of cr%^BOLD%^"+
		    "y%^RESET%^%^CYAN%^st%^BOLD%^a%^RESET%^%^CYAN%^l full "+
		    "plate%^RESET%^");
	     TO->set_long("%^RESET%^%^CYAN%^This suit of exquisite full plate "+
		    "armor has been shaped out of a soild chunk of cy%^RESET%^"+
			"%^CYAN%^a%^BOLD%^n-colored crystal. Although made out of "+
			"an unconventional material, this plate appears to be more "+
			"than capable of providing the level of protection expected "+
			"from a suit of metallic plate. The suit lacks the "+
			"typical decorative embellishments found on most plate "+
			"armor, such as flutes and etching, but instead the edges "+
			"of the armor follows what appears to be the natural "+
			"contours of the crystal. The result is an unique, yet "+
			"stylish suit of armor appropriate for any use. The "+
			"breastplate is carved intaglio with a stylized eye, "+
			"marking its wearer as a knight of Auppenser.%^RESET%^");
		 break;
	  case "nilith":
	     TO->set_short("%^BOLD%^%^WHITE%^Pl%^CYAN%^a%^WHITE%^t%^CYAN%^"+
	        "e o%^WHITE%^f th%^CYAN%^e %^WHITE%^Sh%^CYAN%^a%^WHITE%^"+
	        "rds %^CYAN%^o%^WHITE%^f %^CYAN%^I%^WHITE%^c%^CYAN%^e%^RESET%^");
	     TO->set_obvious_short("%^BOLD%^%^CYAN%^suit of %^WHITE%^i"+
	        "%^CYAN%^c%^WHITE%^y %^CYAN%^full plate%^RESET%^");
	     TO->set_long("%^BOLD%^%^CYAN%^This suit of exquisite full plate "+
	        "armor has been shaped out of a solid chunk of %^WHITE%^i"+
	        "%^CYAN%^c%^WHITE%^e%^CYAN%^. Although made out of an "+
	        "unconventional material, this plate appears to be more "+
	        "than capable of providing the level of protection "+
	        "expected from a suit of metallic plate. The suit lacks "+
	        "the typical decorative embellishments found on most "+
	        "plate armor, such as flutes and etching, but instead "+
	        "the edges of the armor follows what appears to be the "+
	        "natural contours of the %^WHITE%^i%^CYAN%^c%^WHITE%^e"+
	        "%^CYAN%^. The result is an unique, yet stylish suit of "+
	        "armor appropriate for any use. The breastplate is carved "+
	        "intaglio with a snowflake on a heraldic lozenge, marking "+
	        "its wearer as a knight of Auril.%^RESET%^");
	     break;
	  case "lord shadow":
	     TO->set_short("%^BOLD%^%^BLACK%^Pl%^GREEN%^a%^BOLD%^%^BLACK%^"+
                "t%^GREEN%^e o%^BOLD%^%^BLACK%^f th%^GREEN%^e %^BOLD%^"+
	        "%^BLACK%^Kn%^GREEN%^i%^BOLD%^%^BLACK%^ghts %^GREEN%^o"+
	        "%^BOLD%^%^BLACK%^f th%^GREEN%^e %^BOLD%^%^BLACK%^Bl"+
	        "%^GREEN%^a%^BOLD%^%^BLACK%^ck G%^GREEN%^au%^BOLD%^%^BLACK%^"+
	        "ntl%^GREEN%^e%^BOLD%^%^BLACK%^t%^RESET%^");
	     TO->set_obvious_short("%^BOLD%^%^BLACK%^suit of bl%^GREEN%^a"+
	        "%^BOLD%^%^BLACK%^ck full plate%^RESET%^");
	     TO->set_long("%^BOLD%^%^BLACK%^This suit of exquisite full "+
	        "plate armor has been forged from a j%^RESET%^e%^BOLD%^"+
	        "%^BLACK%^t black metal. The metal bears a high %^WHITE%^"+
	        "gloss %^BOLD%^%^BLACK%^and readily reflects the environment "+
	        "around it. Across most of the armor there are engravings "+
	        "of dragons and hellhounds. The engravings seem to undulate "+
	        "in the light due to the armor's %^WHITE%^gloss%^BOLD%^"+
	        "%^BLACK%^. Embossed on the breastplate is a clenched fist "+
	        "with rays bursting forth, marking its wear as a knight "+
	        "of Bane.%^RESET%^");
	     break;
      case "nimnavanon":
	     TO->set_short("%^RESET%^%^RED%^Pl%^ORANGE%^a%^RED%^t%^ORANGE%^e "+
		    "o%^RED%^f th%^ORANGE%^e %^RED%^S%^ORANGE%^a%^RED%^rd"+
			"%^ORANGE%^o%^RED%^n%^ORANGE%^y%^RED%^x Kn%^ORANGE%^i"+
			"%^RED%^ghts%^RESET%^");
		 TO->set_obvious_short("%^RESET%^%^RED%^suit of s%^ORANGE%^"+
			"a%^RED%^rd%^ORANGE%^o%^RED%^n%^ORANGE%^y%^RED%^x full "+
			"plate%^RESET%^");
		 TO->set_long("%^RESET%^%^RED%^This suit of exquisite full plate "+
		    "armor has been shaped out of a soild chunk of s%^ORANGE%^"+
			"a%^RED%^rd%^ORANGE%^o%^RED%^n%^ORANGE%^y%^RED%^x.  "+
			"Although made out of an unconventional material, this "+
			"plate appears to be more than capable of providing the "+
			"level of protection expected from a suit of metallic "+
			"plate.  The suit lacks the typical decorative "+
			"embellishments found on most plate armor, such as flutes "+
			"and etching, rather it is decorated naturally through "+
			"the colored mineral bands of the s%^ORANGE%^a%^RED%^rd"+
			"%^ORANGE%^o%^RED%^n%^ORANGE%^y%^RED%^x.  The result is an "+
			"unique, yet stylish suit of armor appropriate for any "+
			"use.  The breastplate is carved intaglio with three "+
			"mountains, marking its wearer as a knight of Grumbar"+
			".%^RESET%^");
		 break;
	  case "kreysneothosies":
	     TO->set_short("%^RESET%^Pl%^CYAN%^a%^WHITE%^t%^CYAN%^e "+
		    "o%^WHITE%^f th%^CYAN%^e %^WHITE%^V%^CYAN%^i%^WHITE%^g"+
			"%^CYAN%^i%^WHITE%^l%^CYAN%^a%^WHITE%^nt %^CYAN%^Eye"+
			"%^WHITE%^s %^CYAN%^o%^WHITE%^f th%^CYAN%^e "+
			"%^WHITE%^G%^CYAN%^o%^WHITE%^d%^RESET%^");
		 TO->set_obvious_short("%^RESET%^suit of t%^BOLD%^i%^RESET%^"+
			"t%^BOLD%^a%^RESET%^n%^BOLD%^iu%^RESET%^m full "+
			"plate%^RESET%^");
         TO->set_long("%^RESET%^This suit of exquisite full plate "+
            "armor has been forged from flawless t%^BOLD%^i%^RESET%^"+
			"t%^BOLD%^a%^RESET%^n%^BOLD%^iu%^RESET%^m. The metal has "+
			"been buffed to a m%^BOLD%^i%^RESET%^rr%^CYAN%^o%^RESET%^r-l"+
			"%^BOLD%^i%^RESET%^ke shine. The armor is decorated with a "+
			"conserative amount of etchings and flutes to add a moderate "+
			"amount of flair, yet it remains a most utilitarian piece "+
			"of equipment. Embossed on the breastplate is a stylized "+
			"eye on a gauntlet, marking its wearer as a knight of "+
			"Helm.%^RESET%^");
		 break;
      case "lysara":
	     TO->set_short("%^RESET%^%^GREEN%^Pl%^RESET%^a%^GREEN%^t"+
		    "%^RESET%^e o%^GREEN%^f th%^RESET%^e %^GREEN%^Kn%^RESET%^i"+
		    "%^GREEN%^ghts %^RESET%^o%^GREEN%^f th%^RESET%^e E%^GREEN%^"+
		    "t%^RESET%^e%^GREEN%^rn%^RESET%^a%^GREEN%^l %^RESET%^O%^GREEN%^"+
		    "rd%^RESET%^e%^GREEN%^r%^RESET%^");
		 TO->set_obvious_short("%^RESET%^%^GREEN%^suit of gr%^BOLD%^ee"+
		    "%^RESET%^%^GREEN%^n full plate%^RESET%^");
         TO->set_long("%^RESET%^%^GREEN%^This suit of exquisite full "+
		    "plate armor has been forged from a curious b%^BOLD%^o"+
			"%^RESET%^%^GREEN%^ttle green metal. The metal bears a "+
			"high %^BOLD%^%^WHITE%^gloss %^RESET%^%^GREEN%^by nature "+
			"and readily reflects its surrounding environment. Across "+
			"most of the armor there are engravings of scarab beetles "+
			"that almost appear to sparkle due to the metallic %^BOLD%^"+
			"%^WHITE%^gloss%^RESET%^%^GREEN%^. The breastplate is "+
			"engraved with a skeletal arm holding a scale of justice, "+
			"marking its wearer as a knight of Kelemvor.%^RESET%^");
		 break;
	  case "kossuth":
	     TO->set_short("%^RESET%^%^ORANGE%^Pl%^RED%^a%^ORANGE%^t%^RED%^e "+
		    "o%^ORANGE%^f th%^RED%^e %^ORANGE%^Kn%^RED%^i%^ORANGE%^ghts "+
			"%^RED%^o%^ORANGE%^f th%^RED%^e %^ORANGE%^F%^RED%^i"+
			"%^ORANGE%^r%^RED%^e %^ORANGE%^Dr%^RED%^a%^ORANGE%^k"+
			"%^RED%^e%^RESET%^");
		 TO->set_obvious_short("%^RESET%^%^ORANGE%^suit of f%^RED%^i"+
		    "%^ORANGE%^r%^RED%^e o%^ORANGE%^p%^RED%^a%^ORANGE%^l "+
		    "full plate%^RESET%^");
		 TO->set_long("%^RESET%^%^ORANGE%^This suit of exquisite full "+
		    "plate armor has been shaped out of a soild chunk of "+
			"f%^RED%^i%^ORANGE%^r%^RED%^e o%^ORANGE%^p%^RED%^a"+
			"%^ORANGE%^l. Although made out of an unconventional "+
			"material, this plate appears to be more than capable "+
			"of providing the level of protection expected from a "+
			"suit of metallic plate. The suit lacks the typical "+
			"decorative embellishments found on most plate armor, "+
			"such as flutes and etching, rather it is decorated "+
			"naturally through the colored mineral bands of the "+
			"f%^RED%^i%^ORANGE%^r%^RED%^e o%^ORANGE%^p%^RED%^a"+
			"%^ORANGE%^l. The result is a unique, yet stylish suit "+
			"of armor appropriate for any use. The breastplate is "+
			"carved intaglio with a twirling flame, marking its "+
			"wearer as a knight of Kossuth.%^RESET%^");
		 break;
      case "jarmila":
         TO->set_short("%^YELLOW%^Pl%^RED%^a%^YELLOW%^t%^RED%^e "+
		    "o%^YELLOW%^f th%^RED%^e O%^YELLOW%^rd%^RED%^e%^YELLOW%^r "+
			"%^RED%^o%^YELLOW%^f th%^RED%^e A%^YELLOW%^st%^RED%^e"+
			"%^YELLOW%^r%^RESET%^");
		 TO->set_obvious_short("%^YELLOW%^suit of g%^ORANGE%^o%^YELLOW%^lden "+
		    "full plate%^RESET%^");
		 TO->set_long("%^YELLOW%^This suit of exquisite full plate armor "+
		    "has been forged from a g%^ORANGE%^o%^YELLOW%^lden metal. "+
			"The metal bears a high gl%^WHITE%^o%^YELLOW%^ss that readily "+
			"reflects the environment around it. Across most of the "+
			"armor there are intricate engravings of phoenixes and "+
			"asters. The engravings appear to sparkle in the light "+
			"due to the armor's gl%^WHITE%^o%^YELLOW%^ss. The "+
			"breastplate is engraved with a rising sun, marking its "+
			"wearer as a knight of Lathander.%^RESET%^");
		 break;
	  case "callamir":
	     TO->set_short("%^RESET%^%^BLUE%^Pl%^RED%^a%^BLUE%^t%^RED%^e "+
		    "o%^BLUE%^f th%^RED%^e %^BLUE%^Kn%^RED%^i%^BLUE%^ghts "+
			"%^RED%^o%^BLUE%^f th%^RED%^e %^BLUE%^M%^RED%^y%^BLUE%^st"+
			"%^RED%^i%^BLUE%^c F%^RED%^i%^BLUE%^r%^RED%^e%^RESET%^");
		 TO->set_obvious_short("%^RESET%^%^BLUE%^suit of bl%^RED%^u%^BLUE%^e "+
		    "full plate%^RESET%^");
		 TO->set_long("%^RESET%^%^BLUE%^This suit of exquisite full "+
		    "plate armor has been forged from a blue metal. The metal "+
			"bears a high gl%^BOLD%^%^WHITE%^o%^RESET%^%^BLUE%^ss that "+
			"readily reflects the environment around it. In addition to "+
			"the high gl%^BOLD%^%^WHITE%^o%^RESET%^%^BLUE%^ss, the "+
			"paint sp%^BOLD%^%^WHITE%^a%^RESET%^%^BLUE%^rkl%^BOLD%^"+
			"%^WHITE%^e%^RESET%^%^BLUE%^s with metal flakes. The "+
			"breastplate is engraved with rising mist with seven "+
			"stars, marking its wearer as a knight of Mystra.%^RESET%^");
		 break;
	  case "selune":
	     TO->set_short("%^BOLD%^%^WHITE%^Pl%^RESET%^a%^BOLD%^t%^RESET%^e "+
		    "o%^BOLD%^f th%^RESET%^e %^BOLD%^Sw%^RESET%^o%^BOLD%^rds "+
			"%^RESET%^o%^BOLD%^f th%^RESET%^e L%^BOLD%^ady%^RESET%^");
		 TO->set_obvious_short("%^BOLD%^%^WHITE%^suit of s%^RESET%^i"+
		    "%^BOLD%^lv%^RESET%^e%^BOLD%^ry full plate%^RESET%^");
		 TO->set_long("%^BOLD%^%^WHITE%^This suit of exquisite full "+
		    "plate armor has been forged from a s%^RESET%^i%^BOLD%^lv"+
			"%^RESET%^e%^BOLD%^ry metal. The metal bears a high sheen "+
			"and seems to gl%^YELLOW%^i%^WHITE%^mm%^YELLOW%^e%^WHITE%^r "+
			"in any level of light. The armor is embellished with "+
			"numerous engravings of the moon in various phases. The "+
			"breastplate is engraved with a circle of seven stars "+
			"surrounding a pair of eyes, marking its wearer as a "+
			"knight of Selune.%^RESET%^");
		 break;
	  case "shar":
	     TO->set_short("%^BOLD%^%^BLACK%^Pl%^RESET%^%^MAGENTA%^a%^BOLD%^"+
	        "%^BLACK%^t%^RESET%^%^MAGENTA%^e o%^BOLD%^%^BLACK%^f th%^RESET%^"+
	        "%^MAGENTA%^e %^BOLD%^%^BLACK%^D%^RESET%^%^MAGENTA%^a%^BOLD%^"+
	        "%^BLACK%^rk J%^RESET%^%^MAGENTA%^u%^BOLD%^%^BLACK%^st%^RESET%^"+
	        "%^MAGENTA%^i%^BOLD%^%^BLACK%^c%^RESET%^%^MAGENTA%^a%^BOLD%^"+
	        "%^BLACK%^rs%^RESET%^");
	     TO->set_obvious_short("%^BOLD%^%^BLACK%^suit of obs%^WHITE%^i"+
	        "%^BOLD%^%^BLACK%^d%^WHITE%^ia%^BOLD%^%^BLACK%^n full "+
	        "plate%^RESET%^");
	     TO->set_long("%^BOLD%^%^BLACK%^This suit of exquisite full "+
	        "plate armor has been fashioned out of a solid piece of obs"+
	        "%^WHITE%^i%^BOLD%^%^BLACK%^d%^WHITE%^ia%^BOLD%^%^BLACK%^n. "+
	        "Although made out of an unconventional material, this "+
	        "plate appears to be more than capable of providing the "+
	        "level of protection expected from a suit of metallic "+
	        "plate. The suit lacks the typical decorative embellishments "+
	        "found on most plate armor, such as flutes and etching, "+
	        "rather it is decorated naturally through the natural "+
	        "striations. The breastplate is carved intaglio with two "+
	        "concentric circles, marking its wearer as a knight "+
	        "of Shar.%^RESET%^");
	     break;
	  case "sune":
         if((string)ETO->query_gender() == "female"){
		    TO->set_short("%^BOLD%^%^RED%^Pl%^RESET%^%^RED%^a%^BOLD%^t"+
			   "%^RESET%^%^RED%^e o%^BOLD%^f th%^RESET%^%^RED%^e "+
			   "%^BOLD%^S%^RESET%^%^RED%^i%^BOLD%^st%^RESET%^%^RED%^e"+
			   "%^BOLD%^rs %^RESET%^%^RED%^o%^BOLD%^f th%^RESET%^"+
			   "%^RED%^e %^BOLD%^R%^RESET%^%^RED%^u%^BOLD%^by R%^RESET%^"+
			   "%^RED%^o%^BOLD%^s%^RESET%^%^RED%^e%^RESET%^");
		 }
		 else{
		    TO->set_short("%^BOLD%^%^RED%^Pl%^RESET%^%^RED%^a%^BOLD%^t"+
			   "%^RESET%^%^RED%^e o%^BOLD%^f th%^RESET%^%^RED%^e "+
			   "%^BOLD%^Br%^RESET%^%^RED%^o%^BOLD%^th%^RESET%^%^RED%^e"+
			   "%^BOLD%^rs %^RESET%^%^RED%^o%^BOLD%^f th%^RESET%^"+
			   "%^RED%^e %^BOLD%^R%^RESET%^%^RED%^u%^BOLD%^by R%^RESET%^"+
			   "%^RED%^o%^BOLD%^s%^RESET%^%^RED%^e%^RESET%^");
		 }
		 TO->set_obvious_short("%^BOLD%^%^RED%^suit of r%^RESET%^%^RED%^e"+
		    "%^BOLD%^d full plate%^RESET%^");
		 TO->set_long("%^BOLD%^%^RED%^This suit of exquisite full plate "+
		    "armor has been forged from a deep r%^RESET%^%^RED%^e%^BOLD%^"+
		    "d metal. The metal bears a high gl%^WHITE%^o%^RED%^ss that "+
		    "readily reflects the environment around it. Across most of "+
		    "the armor there are intricate engravings of roses and nymphs. "+
		    "The engravings seems to move of their own accord when the "+
		    "light catches the gl%^WHITE%^o%^RED%^ss of the plate in the "+
		    "right light. The breastplate is engraved with a woman's "+
		    "face, marking its wearer as a knight of Sune.%^RESET%^");
         break;
      case "torm":
         TO->set_short("%^YELLOW%^Pl%^WHITE%^a%^YELLOW%^t%^WHITE%^"+
            " o%^YELLOW%^f th%^WHITE%^e O%^YELLOW%^rd%^WHITE%^e%^YELLOW%^"+
            "r %^WHITE%^o%^YELLOW%^f th%^WHITE%^e %^YELLOW%^G%^WHITE%^o"+
            "%^YELLOW%^ld%^WHITE%^e%^YELLOW%^n L%^WHITE%^io%^YELLOW%^"+
            "ns%^RESET%^");
         TO->set_obvious_short("%^YELLOW%^suit of g%^WHITE%^o%^YELLOW%^ld"+
            "%^WHITE%^e%^YELLOW%^n full plate%^RESET%^");
         TO->set_long("%^YELLOW%^This suit of exquisite full plate "+
            "armor has been forged from a g%^WHITE%^o%^YELLOW%^ld"+
            "%^WHITE%^e%^YELLOW%^n metal. The metal has been buffed "+
            "to a m%^BOLD%^i%^RESET%^rr%^CYAN%^o%^RESET%^r-l"+
			"%^BOLD%^i%^RESET%^ke shine. Most of the armor is decorated "+
			"with engravings of lions that appear to glow in bright "+
			"light due to the high gl%^WHITE%^o%^YELLOW%^ss of the "+
			"armor. Embossed on the breastplate is a right hand gauntlet "+
			"with the palm facing outward, marking its wearer as a knight of "+
			"Torm.%^RESET%^");
         break;
      case "tyr":
         TO->set_short("%^BOLD%^%^WHITE%^Pl%^BLUE%^a%^WHITE%^t%^BLUE%^e "+
            "o%^WHITE%^f th%^BLUE%^e %^WHITE%^H%^BLUE%^a%^WHITE%^mm%^BLUE%^"+
            "e%^WHITE%^rs %^BLUE%^o%^WHITE%^f Gr%^BLUE%^i%^WHITE%^mj%^BLUE%^"+
            "a%^WHITE%^ws%^RESET%^");
         TO->set_obvious_short("%^BOLD%^%^WHITE%^suit of white full "+
         "plate%^RESET%^");
         TO->set_long("%^BOLD%^%^WHITE%^This suit of exquisite full plate "+
            "armor has been forged from a brilliant white metal. The "+
            "metal has been buffed to a m%^BOLD%^i%^RESET%^rr%^CYAN%^o"+
            "%^RESET%^r-l%^BOLD%^i%^RESET%^ke %^BOLD%^shine. Most of the "+
            "armor is decorated with engravings of owls and eagles that "+
            "appear to glow in bright light due to the high gloss of the "+
			"armor. Embossed on the breastplate is a set of scales of "+
			"justice resting on a warhammer, marking its wearer as a "+
			"knight of Tyr.%^RESET%^");
         break;
   }
   tell_object(ETO,"%^BOLD%^You feel the power of your deity strengthening "+
      "your resolve.%^RESET%^");
   tell_room(EETO,"%^BOLD%^"+ETOQCN+" looks determined to carry out "+
      ""+ETO->QP+" deity's charge as "+ETO->QS+" wears the full "+
	  "plate.%^RESET%^",ETO);
   return 1;
}

int removeme(){
   tell_object(ETO,"%^BOLD%^You sigh as you feel your resolve "+
      "diminish slightly.%^RESET%^");
   tell_room(EETO,"%^BOLD%^"+ETOQCN+" sighs softly and looks a "+
      "little less determined as "+ETO->QS+" removes the full "+
	  "plate.%^RESET%^",ETO);
   return 1;
}
