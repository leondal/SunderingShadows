#include <std.h>
inherit ARMOUR;
void make_me();


#define COLORS ({"%^BOLD%^%^BLACK%^jet black",\
"%^BOLD%^%^WHITE%^brilliant white",\
"%^BOLD%^%^RED%^crimson red",\
"%^RESET%^%^RED%^scarlet red",\
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
"%^MAGENTA%^plum",\
"%^BOLD%^%^MAGENTA%^bright pink",\
"%^BOLD%^%^BLACK%^stormy gray",\
"%^BOLD%^%^CYAN%^sky blue",\
"%^RESET%^s%^BOLD%^i%^RESET%^l%^BOLD%^v%^RESET%^e%^BOLD%^r",\
"%^ORANGE%^g%^BOLD%^o%^RESET%^%^ORANGE%^l%^BOLD%^d",\
"%^BOLD%^%^RED%^ruby red",\
"%^BOLD%^%^WHITE%^light cream",\
"%^BOLD%^%^BLACK%^raven black",\
"%^MAGENTA%^wine",\
"%^BOLD%^%^MAGENTA%^pale pink",\
"%^CYAN%^sea-green"})

#define types ({"silk","cotton","lace","velvet","tweed","suede"})

void create(){
        ::create();
   	make_me();
        set_weight(2);
   	set_value(30);
   	set_type("ring");
   	set_limbs(({"waist"}));
   	set_size(random(2)+1);
        set_property("repairtype",({ "tailor" }));
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
case "silk":
	TO->set_long("Made from fine silk this circle skirt features"+
		" multiple layers of silk chiffon in shades and hues"+
		" of "+COLOR+" %^RESET%^.  The multiple layers of the"+
		" skirt start with the darker shades and work up to "+
		"lighter tints, creating a stunning effect when the "+
		"wearer moves or dances.  The free flowing skirt "+
		"utilizes the lightness of the silk in a stylish manner."+
		"  A silk waistband keeps the multiple layers in check, "+
		"and secures the skirt firmly.\n");
   	TO->set_name("silk skirt");
   	TO->set_short("%^RESET%^"+COLOR+" silk skirt%^RESET%^");
     	TO->set_id(({"skirt","silk skirt"}));
	break;
case "cotton":
      TO->set_long("Made from brushed cotton this straight skirt is"+
		" extremely soft.  The cotton fabric has been dyed an "+
		"eye catching shade of "+COLOR+"%^RESET%^.  Cotton is a"+
		" prized fabric for its versatility and the way it takes"+
		" color.  This simple looking skirt is one that any woman"+
		" could dress up or down with the right accessories, making"+
		" it as versatile as the fabric.\n");
   	TO->set_name("cotton skirt");
   	TO->set_short("%^RESET%^"+COLOR+" cotton skirt%^RESET%^");
      TO->set_id(({"skirt","cotton skirt"}));
      break;
case "lace":
      TO->set_long("Finely woven "+COLOR+" %^RESET%^lace overlays"+
		" a flesh colored shell to create this dramatic and "+
		"feminine skirt.  The fine lace is delicate and intricate"+
		" in design, showing a sign of high workmanship.  The "+
		"heavily embroidered scalloped edge of the lace has "+
		"been used to create the hem.  This skirt falls above"+
		" the knees and is often best reserved for younger girl"+
		" or maidens.\n");
   	TO->set_name("lace skirt");
   	TO->set_short("%^RESET%^"+COLOR+" lace skirt%^RESET%^");
      TO->set_id(({"lace skirt","skirt"}));
      break;
case "velvet":
      TO->set_long("Plush thick "+COLOR+" %^RESET%^velvet is"+
		" used to fashion this skirt.  The long skirt falls"+
		" to the wearer's ankles, allowing for a lady to "+
		"keep her modesty.  While simple in design, the "+
		"fabric more than makes this skirt look rich and "+
		"luxurious.  A favorite with magesses, priestesses,"+
		" and noble women when worn under their robes.\n");
   	TO->set_name("velvet");
   	TO->set_short("%^RESET%^"+COLOR+" velvet skirt%^RESET%^");
	TO->set_id(({"velvet skirt","skirt"}));
      break;
case "tweed":
      TO->set_long("This heavy tweed skirt will keep any lady"+
		" warm during the colder months.  The wool tweed has"+
		" been dyed "+COLOR+" %^RESET%^and features a subtle"+
		" check pattern in a matching hue.  The straight skirt"+
		" comes to the tops of the calves on the wearer, helping"+
		" to protect her from the elements\n");
   	TO->set_name("tweed skirt");
   	TO->set_short("%^RESET%^"+COLOR+" tweed skirt%^RESET%^");
   	TO->set_id(({"skirt","tweed skirt"}));
      break;
case "suede":
      TO->set_long("Soft supple suede dyed "+COLOR+" %^RESET%^is the fabric"+
		" for this A-line skirt.  The skirt uses the weight of"+
		" the suede to create a flared effect.  The skirt skims"+
		" the hips of the wearer before flaring out to create a"+
		" flattering image.  Decorative stitching in the shape "+
		"of circles in complementary shade and hues give this "+
		"rustic skirt a fashionable edge.\n");
   	TO->set_name("suede skirt");
   	TO->set_short("%^RESET%^"+COLOR+" suede skirt%^RESET%^");
	TO->set_id(({"skirt","suede skirt"}));
      break;
	}
}
