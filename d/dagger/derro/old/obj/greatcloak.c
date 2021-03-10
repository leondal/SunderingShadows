//Updated with new look and variety - Cythera 8/05
#include <std.h>
inherit ARMOUR;

#define COLORS ({"%^BOLD%^%^BLACK%^jet black",\
"%^BOLD%^%^WHITE%^brilliant white",\
"%^RESET%^%^RED%^crimson red",\
"%^BOLD%^%^RED%^scarlet red",\
"%^RESET%^%^ORANGE%^bright orange",\
"%^RESET%^%^ORANGE%^walnut brown",\
"%^YELLOW%^goldenrod",\
"%^BOLD%^%^GREEN%^emerald green",\
"%^RESET%^%^GREEN%^forest green",\
"%^BOLD%^%^BLUE%^sapphire blue",\
"%^BOLD%^%^BLUE%^cerulean blue",\
"%^RESET%^%^BLUE%^midnight blue",\
"%^RESET%^%^CYAN%^slate blue",\
"%^BOLD%^%^CYAN%^aquamarine blue",\
"%^RESET%^%^MAGENTA%^deep purple",\
"%^BOLD%^%^BLACK%^gray-%^RESET%^%^GREEN%^green",\
"%^BOLD%^%^WHITE%^ivory white",\
"%^BOLD%^%^BLACK%^stormy gray",\
"%^BOLD%^%^CYAN%^sky blue",\
"%^BOLD%^%^MAGENTA%^mauve",\
"%^RESET%^s%^BOLD%^i%^RESET%^l%^BOLD%^v%^RESET%^e%^BOLD%^r",\
"%^RESET%^%^ORANGE%^g%^BOLD%^o%^RESET%^%^ORANGE%^l%^BOLD%^d",\
"%^BOLD%^%^RED%^ruby red",\
"%^BOLD%^%^WHITE%^light cream",\
"%^BOLD%^%^BLACK%^raven black",\
"%^MAGENTA%^wine",\
"%^RED%^blood red",\
"%^CYAN%^sea green"})

#define cloths ({"suede","silk","leather"})

void create(){
    int i,x;
   string cloth, COLOR;
    i = random(sizeof(COLORS));
       COLOR = COLORS[i];
    x = random(sizeof(cloths));
       cloth = cloths[x];
   ::create();
   	switch(cloth){
case "suede":
	TO->set_long("%^RESET%^Crafted from suede, this short cloak has been "+
		"dyed "+COLOR+"%^RESET%^. The thick suede has a raised"+
		" texture, making it very comfortable to wear.  The short"+
		" cloak only falls to ones upper thighs, leaving the lower"+
		" body exposed to the elements. A high stiff suede collar "+
		"wraps around the neck before each end tapers off to a"+
		" sharp ninety degrees angle.  Up the sides of the cloak"+
		" a band of braided %^BOLD%^%^WHITE%^e%^YELLOW%^l%^BOLD%^"+
		"%^WHITE%^e%^YELLOW%^c%^BOLD%^%^WHITE%^t%^YELLOW%^r%^BOLD%^"+
		"%^WHITE%^u%^YELLOW%^m%^RESET%^ and %^BOLD%^s%^RESET%^i"+
		"%^BOLD%^l%^RESET%^v%^BOLD%^e%^RESET%^r metallic threads "+
		"has been stitched into the thick suede.  A cord of similiar"+
		" metals allows the cloak to be tied around one's neck. \n");
   	TO->set_name("suede cloak");
   	TO->set_short("%^RESET%^"+COLOR+" suede short cloak%^RESET%^");
     	TO->set_id(({"cloak","suede cloak"}));
	break;
case "silk":
      TO->set_long("Crafted from thick silk this long cloak has been dyed"+
		" "+COLOR+"%^RESET%^.  The thick silk has a soft smooth "+
		"texture, perfect for swirling about one in the winds, or"+
		" adding a touch of style to their wardrobe.  The long "+
		"flowing cloak is cut full, allowing the silk to drape "+
		"and pool around ones body.  A double layer of silk adds"+
		" just enough body to the cloak without compromising the "+
		"flowing nature of silk.  The body of the cloak has been "+
		"cut to include a mantle that wraps from shoulder to shoulder."+
		"  All along the outer edges of the cloak a band of braided "+
		"%^BOLD%^%^WHITE%^e%^YELLOW%^l%^BOLD%^"+
		"%^WHITE%^e%^YELLOW%^c%^BOLD%^%^WHITE%^t%^YELLOW%^r%^BOLD%^"+
		"%^WHITE%^u%^YELLOW%^m%^RESET%^ and %^BOLD%^s%^RESET%^i"+
		"%^BOLD%^l%^RESET%^v%^BOLD%^e%^RESET%^r metallic threads has "+
		"been stitched into the double layers of silk.\n");  
   	TO->set_name("silk cloak");
     	TO->set_short("%^RESET%^"+COLOR+" silk voluminous cloak%^RESET%^");
   	TO->set_id(({"cloak","silk cloak"}));   
      break;
case "leather":
      TO->set_long("Crafted from tough leather this long slim cloak has"+
		" been dyed "+COLOR+"%^RESET%^.  The narrow, slender cloak"+
		" lacks barely enough fabric to even brush against ones side."+
		"  The leather is supple and soft, showing a master tanner's"+
		" skill in curing the leather.  The inside of the leather "+
		"cloak has been lined with matching brushed cotton, which "+
		"creates a soft texture and conceals the underside of the "+
		"leather hides.  The sections of leather have been pieced "+
		"together in a manner that the entire cloak looks as if it "+
		"was made out of one large hide.  A cowl hood is attached to"+
		" the slim cloak, lined with matching cotton. Up the sides of"+
		" the cowl and cloak a band of braided %^BOLD%^%^WHITE%^e"+
		"%^YELLOW%^l%^BOLD%^%^WHITE%^e%^YELLOW%^c%^BOLD%^%^WHITE%^t"+
		"%^YELLOW%^r%^BOLD%^%^WHITE%^u%^YELLOW%^m%^RESET%^ and "+
		"%^BOLD%^s%^RESET%^i%^BOLD%^l%^RESET%^v%^BOLD%^e%^RESET%^r"+
		" metallic threads has been stitched \n");
   	TO->set_name("leather cloak");
   	TO->set_short("%^RESET%^"+COLOR+" leather slender cloak%^RESET%^");
     	TO->set_id(({"leather cloak","cloak"}));
      break;
	}
   	set_lore("Across the lands people desire a better life, one"+
		" filled with finery, even the larger races.  One wizard"+
		" with a mind for buisness saw a need in weaving large "+
		"cloaks for the voadkyns and firbolgs of the lands.  "+
		"Alanit Antius used his connections with the distant "+
		"city of Asgard to hire some of the best weavers to spin"+
		" the finest cloth for his cloaks.  Each cloak features "+
		"his trademarke band of electrum and silver metallic "+
		"threads, two of his favorite metals.  The cloaks were "+
		"wildly popular for the large folk felt for one of the "+
		"first times that someone understood their needs and "+
		"desires, and was working to make them come true.  In "+
		"truth Alanit saw a way to become wealthy by tapping "+
		"into a new customer base.  And insanely wealthy he did"+
		" become.\n");
   	set_property("lore difficulty",8);
   	set_weight(6);
  	set_value(2000);
  	set_property("enchantment",3);
  	set_ac(0);
  	set_type("clothing");
  	set_limbs(({"neck"}));
  	set_size(3);
}