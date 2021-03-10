//Changed to use ares' new strength code - Cythera 6/06
//Changed Per Tsera, so that good people no longer feel guilty about wearing them in the name of balance. Dinji 9/14
// str bonus changed to work on new stat system. Nienne, 09/07. Also made adjustable by size.
//adjusted the level requirement now that it's back to 5 levels/enchantment
#include <std.h>
inherit ARMOUR;

void create() {
	::create();
      set_obvious_short("%^YELLOW%^An ornate gold belt%^RESET%^");
	set_name("belt of giant strength");
	set_short("%^YELLOW%^Belt of Giant Strength%^RESET%^");
      set_lore("This ornate belt was created by the grand shaman "+
         "Helgatha Rothmar in the firbolg village of Lothwaite.  "+
         "He is the only one to have ever successfully crafted "+
         "such a belt, though similar magics are thought to exist "+
         "elsewhere.  It is said that a belt such as this will "+
         "increase the strength of the wearer, though only to a "+
         "certain point.");
      set_property("lore difficulty",15);
	set_id(({"belt","gold belt","ornate belt","belt of giant strength"}));
        set_property("repairtype",({ "jewel" }));
        set_long(
         "%^YELLOW%^This belt is made of golden filigree worked "+
         "into a flexible web making it stronger than any metal "+
         "known to man, dwarf, or firbolg.  Between the strands, "+
         "tiny mu%^WHITE%^l%^YELLOW%^ti%^BLUE%^f%^YELLOW%^ac%^GREEN%^"+
         "e%^YELLOW%^te%^RED%^d %^YELLOW%^gems have been set, "+
         "sparkling in a %^RED%^r%^RESET%^%^ORANGE%^a%^YELLOW%^i"+
         "%^GREEN%^n%^CYAN%^b%^BLUE%^o%^MAGENTA%^w %^YELLOW%^of "+
         "%^WHITE%^hues%^YELLOW%^.  The belt has a solid gold "+
         "clasp set with bevelled %^BLUE%^sap%^CYAN%^p%^BLUE%^"+
         "hi%^CYAN%^r%^BLUE%^es%^YELLOW%^."
	);
	set_weight(5);
	set_value(2000);
	set_ac(0);
      set_size(-1);
	set_property("enchantment",2);
      set_item_bonus("strength",1);
	set_type("clothing");
	set_limbs(({"waist"}));
	set_wear((:TO,"wearme":));
	set_remove((:TO,"removeme":));
}

int wearme() { // Making these give the bonus every time, since it's only one level of exceptional -Ares
   if((string)ETO->query_name() == "firbolg ghost") return 1;
   if(ETO->query_lowest_level() < 15) {
	tell_object(ETO,"You are not experienced enough to use this equipment.");
		return 0;
   }
	
      tell_object(ETO,"%^YELLOW%^As you fasten the belt around your "+
         "waist, you feel power flowing through your sinews.");
   return 1;
}

int removeme() {
      tell_object(ETO,"%^RESET%^%^ORANGE%^You feel the strength of "+
         "the mighty firbolgs leave you as you unbuckle the belt.");
   return 1;
}