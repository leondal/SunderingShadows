//Added lore and an obvious short - Cythera 4/05
#include <std.h>
inherit "/std/armour";

void create()
{
   ::create();
   set_name("ruby circlet");
   set_short("%^BOLD%^%^RED%^R%^RESET%^%^RED%^u%^BOLD%^b%^RESET%^%^RED%^y %^BOLD%^Circlet%^RESET%^");
	set_obvious_short("%^BOLD%^%^RED%^A %^YELLOW%^g%^MAGENTA%^o%^YELLOW%^l%^MAGENTA%^d%^RED%^ ruby circlet%^RESET%^");
   set_id(({"circlet","ruby circlet"}));
   set_property("repairtype",({ "jewel" }));
  // set_long("%^RESET%^This circlet is made of a band of %^BOLD%^%^MAGENTA%^rose "+
    //  "gold %^RESET%^and is set with a large %^RED%^r%^BOLD%^u%^RESET%^%^RED%^b%^BOLD%^y"+
      //"%^RESET%^ in the center, with three "+
      //"smaller %^RED%^rubies%^RESET%^ on either side of it. It is a "+
      //"beautiful piece of jewelry and the rubies are of fine quality.%^RESET%^");
      set_long("%^RESET%^Crafted from %^YELLOW%^yellow gold%^RESET%^ and "+
                "%^BOLD%^%^MAGENTA%^rose gold%^RESET%^, this circlet carries"+
                " a %^MAGENTA%^delicate grace%^RESET%^ to it.  The two "+
                "%^YELLOW%^g%^MAGENTA%^o%^YELLOW%^l%^MAGENTA%^d%^YELLOW%^s%^RESET%^"+
                " twist around each other in thin threads that almost seem like "+
                "they could %^ORANGE%^break%^RESET%^ with the slightest "+
                "breeze.  Elegant %^RED%^teardrop%^RESET%^ shaped loops rise and fall "+
                "around the body of the circlet, creating graceful shapes.  "+
                 "Dangling from the center of the circlet is a large teardrop "+
                "shaped %^BOLD%^%^RED%^r%^RESET%^%^RED%^u%^BOLD%^%^RED%^b%^RESET%^%^RED%^y"+
                "%^RESET%^ with multiple %^BOLD%^facets%^RESET%^ that catch "+
                "the light.  Smaller %^BOLD%^%^RED%^r%^RESET%^%^RED%^u%^BOLD%^b"+
                 "%^RESET%^%^RED%^i%^BOLD%^e%^RESET%^%^RED%^s%^RESET%^ are set "+
                 "in %^BOLD%^%^MAGENTA%^rose%^RESET%^ and %^YELLOW%^yellow %^RESET%^"+
                 "gold prongs around the larger stone, creating a %^BOLD%^%^RED%^"+
                 "fiery%^RESET%^ brilliance to this delicate piece of jewelry.\n");
      set_lore("While there are those who will make use of any pieces"+
		" of armor they may come across, it has been the quest of "+
		"those who crave a sense of style of the battlefield to "+
		"find items that fit their need.  The Ruby Circlet was "+
		"created for one such man, the human bard Gabriele. "+
		" Gabriele, like most bards, prized himself on his "+
		"appearance and always strived to present the best image"+
		" to the world.  As a follower of Lathander, it only "+
		"seemed natural that Gabriele favored shades of red and"+
		" yellow for his attire.  Never seeming to find a helm "+
		"or coif he liked, and refusing to wear anything lesser, "+
		"this is how the Ruby Circlet came about.  An overprotective"+
		" warrior/mage of the Dawn Lord grew frustrated at the risks"+
		" that Gabriele was taking with his life by refusing to wear "+
		"a helm in battle.  Calideidrathal finally sought out to do "+
		"something about this predicament.  Using her elven resources"+
		" she commissioned a circlet made of rose gold and rubies to "+
		"be made.  Then calling upon her elven arcane powers she "+
		"enchanted the circlet to offer almost equal protection to "+
		"a full helm to the wearer.  When Calideidrathal presented the "+
		"circlet to her friend, Gabriele was so excited that he composed"+
		" his most famous song on the spot in honor of her, 'Thine Lips "+
		"Sparkle like Rubies'.");
	set_property("lore",10);
   set_weight(2);
   set_type("clothing");
   set_limbs(({"head"}));
   set_ac(0);
   set_value(5000);
   set_property("enchantment",3);
   set_item_bonus("magic resistance",1);
   set_wear((:TO,"wearme":));
}

int wearme()
{
   if(ETO->query_lowest_level() < 19) {
      tell_object(ETO,"You're not experienced enough to utilize this equipment.");
      return 0;
   }
   tell_object(ETO,"%^BOLD%^%^RED%^The ruby circlet fits comfortably on your head.");
   return 1;
}