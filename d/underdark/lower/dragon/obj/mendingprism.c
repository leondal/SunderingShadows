#include <std.h>
inherit OBJECT;

int charges;
void set_my_lore();

void create() {
    ::create();
    set_name("banded onyx prism");
    set_short("%^BOLD%^%^BLACK%^Prism of M%^RESET%^%^ORANGE%^en%^BOLD%^%^BLACK%^d%^RESET%^%^ORANGE%^in%^BOLD%^%^BLACK%^g%^RESET%^");
    set_obvious_short("%^BOLD%^%^BLACK%^b%^RESET%^a%^BOLD%^%^BLACK%^nded on%^RESET%^%^ORANGE%^y%^BOLD%^%^BLACK%^x p%^RESET%^%^ORANGE%^r%^BOLD%^%^BLACK%^ism%^RESET%^");
    set_id(({"prism","onyx prism","banded onyx prism","prism of mending","Prism of Mending"}));
    set_long("%^RED%^This small, solid piece of %^BOLD%^%^BLACK%^ban%^RESET%^%^ORANGE%^d%^BOLD%^%^BLACK%^ed "
"onyx %^RESET%^%^RED%^would fit comfortably in the hand, with bluntly tapered ends at four points. Three of "
"these form the triangular base, equally spaced from its centre, while the fourth lies at the peak of the "
"prism. Thin veins of %^WHITE%^c%^ORANGE%^o%^WHITE%^l%^ORANGE%^o%^WHITE%^r %^RED%^break up its dark, nearly "
"%^BOLD%^%^BLACK%^black %^RESET%^%^RED%^surface, giving it a softly mottled appearance.%^RESET%^");
    set_property("lore difficulty",30);
    set_property("id difficulty",30);
    set_weight(1);
    set_value(6500);
    charges = 25;
    set_my_lore();
}

void init() {
    ::init();
    add_action("mend_me","mend");
}

void mend_me(string str) {
    object mytarg;
    if(!userp(ETO)) {
      notify_fail("You must be holding the prism to activate it.\n");
      return 0;
    }
    if(!str) {
      notify_fail("What do you want to mend?\n");
      return 0;
    }
    if(!mytarg = present(str,ETO)){
      notify_fail("You aren't carrying a "+str+".\n");
      return 0;
    }
    if(mytarg->query_property("no repair")){
      notify_fail("The prism doesn't react. It seems that item cannot be repaired.\n");
      return 0;
    }
    if(!charges){
      notify_fail("The prism doesn't react. It seems to be out of charges.\n");
      return 0;
    }
    tell_object(ETO,"%^ORANGE%^You concentrate upon the prism in your hand, and it pulses briefly with a "
"%^WHITE%^dull glow%^ORANGE%^. Looking over the "+str+", you realise all the damages upon it have been "
"mended!%^RESET%^");
    tell_room(EETO,"%^ORANGE%^"+ETO->QCN+" concentrates upon the prism in "+ETO->QP+" hand, and it pulses "
"briefly with a %^WHITE%^dull glow%^ORANGE%^. Looking over the "+str+", you realise all the damages upon it "
"have been mended!%^RESET%^",ETO);
	//changed to repairMe so that if they are wearing an item that 
	//gives AC it will handle the AC stuff correctly - Saide
    //mytarg->set_overallStatus(100);
	mytarg->repairMe(100);
    charges--;
    set_my_lore();
    return 1;
}

int isMagic(){ return 1; }

void set_my_lore() {
    set_lore("%^WHITE%^%^BOLD%^The story tells of a simple seamstress named Mia who appeared one night at the "
"Inn of the Lost Mule, a rather disheveled place with torn windows and frayed tablecloths.  Having little more "
"then the clothing on her back, Mia offered to trade a bit of mending for a night's supper and lodging.  The "
"innkeeper's wife demanded the crystal about Mia's neck, but the girl refused and instead offered to mend "
"every tablecloth and curtain before she went to bed that night.  Innkeeper's wife laughed and told Mia she "
"would have one loaf of bread and one cup of water and might sleep on the hearth for she could never "
"accomplish such a thing.  After that, the cruel woman went to bed leaving poor Mia to work.  In the morning, "
"the Innkeeper's wife awoke to find everything repaired and Mia asleep on the hearth.  Surprised, the "
"Innkeeper's wife demanded to know how Mia did such a thing, but the girl refused to tell instead insisting on "
"payment of a night's lodging and meal.  The Innkeeper's wife was livid but her husband came forth and spared "
"Mia, leading her to a finely draped table with a wonderful meal they shared.  Then afterward showing her to "
"their best room.  Furious, the Innkeeper's wife slipped into the girl's room intent on harming her, but all "
"she ever found was a small piece of banded onyx, the gem about Mia's neck.  You're fairly sure you could "
"still activate this one if you tried to %^YELLOW%^<mend item>%^WHITE%^.  A close examination reveals that "
"there are "+charges+" charges left in the prism.%^RESET%^\n");
}

void renew_charges() { charges = 25; set_my_lore(); }
int is_tazrak_charged() { return 1; }