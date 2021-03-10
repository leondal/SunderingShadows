#include <std.h>
inherit "/std/armour";

void create()
{
        ::create();
        set_name("Shackles of Lightning");
        set_short("%^RESET%^%^ORANGE%^Sha%^YELLOW%^c%^RESET%^%^ORANGE%^kles of Ligh%^YELLOW%^t%^RESET%^%^ORANGE%^ning");
        set_obvious_short("%^RESET%^%^ORANGE%^gold streaked shackles");
        set_id(({"gold streaked shackles","shackles","shackles of lightning"}));
        set_long(
        "%^BOLD%^%^BLACK%^These shackles strangely do not connect."+
		"  The chains down and end in a %^RED%^sharp point."+
		"  %^BLACK%^The rungs are a darkened metal that looks"+
		" to have streaks of %^YELLOW%^gold runes%^BLACK%^ etched along"+
		" the outside.  The pattern is jagged, not "+
		"unlike that of a %^YELLOW%^lightning bolt%^BLACK%^.  The"+
		" shackles themselves look very cruel to "+
		"wear.  They have a very %^RED%^sharp barb%^BLACK%^ on the"+
		" inside that threatens to gouge the"+
		" wearers wrist is not handled carefully.%^RESET%^");
        set_lore("These shackles are another creation of a "+
		"certain mad mage.  They can be used to control "+
		"those hands that might strike its master by "+
		"administering powerful shocks of energy.  "+
		"Likewise, to keep said mage's property safe,"+
		" the energy can be used against attackers as well.");
		set_property("lore",30);
        set_weight(4);
        set_value(2500);
		set_size(1);
        set_type("armor");
        set_limbs(({"right arm","left arm"}));
        set_property("enchantment",3);
	  set_item_bonus("charisma",-1);
        set_ac(1);
        set_wear((:TO,"wearme":));
        set_remove((:TO,"removeme":));
		set_struck((:TO,"strikeme":));
}

int wearme()
{
   tell_object(ETO,"%^GREEN%^You carefully don "+
    "the shackles, looking much like a slave or a prisoner.");
   return 1;
}

int removeme()
{
   tell_object(ETO,"%^GREEN%^Upon removing "+
    "these things, you feel less like someone's property.");
   return 1;
}
int strikeme(int damage, object what, object who){

        if(random(1000) < 250){
		 tell_object(ETO,"%^YELLOW%^"+who->QCN+
		 " strikes your shackles and they "+
		 "vibrate, sending a shock of lightning out.");
         new("/cmds/spells/l/_lightning_orb")->use_spell(ETO,who,15,100,"mage");
        return 1;
      }
 return damage;
}	  
