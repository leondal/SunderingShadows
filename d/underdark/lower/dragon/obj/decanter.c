#include <std.h>
inherit OBJECT;

void create() {
    ::create();
    set_name("crystalline decanter");
    set_short("%^RESET%^%^CYAN%^Endless Decanter of %^ORANGE%^Dw%^YELLOW%^ar%^RESET%^%^ORANGE%^ve%^YELLOW%^n R%^RESET%^%^ORANGE%^um%^RESET%^");
    set_obvious_short("%^RESET%^%^CYAN%^a %^BOLD%^%^WHITE%^cry%^CYAN%^s%^WHITE%^tall%^CYAN%^i%^WHITE%^ne %^RESET%^%^CYAN%^decanter%^RESET%^");
    set_id(({"decanter","crystal decanter","crystalline decanter","decanter of rum","endless decanter"}));
    set_long("%^CYAN%^Semi-opaque %^BOLD%^%^WHITE%^cr%^CYAN%^y%^WHITE%^stal %^RESET%^%^CYAN%^forms this small "
"decanter, which holds a somewhat rectangular shape, with the neck and stopper protruding from the top.  A "
"line of ornately %^YELLOW%^pa%^RESET%^%^ORANGE%^tt%^YELLOW%^er%^RESET%^%^ORANGE%^ne%^YELLOW%^d g%^RESET%^"
"%^ORANGE%^ol%^YELLOW%^d %^RESET%^%^CYAN%^encircles the neck of the vessel, giving it a more elegant and "
"expensive appearance.  Just inside, you can see that the stoppered lid is attached to a rod, perhaps to aid "
"in decanting the stored liquid.  Within, a %^ORANGE%^dark a%^RED%^m%^ORANGE%^ber-hued li%^RED%^q%^ORANGE%^uid "
"%^RESET%^%^CYAN%^is visible, swirling within the %^BOLD%^%^WHITE%^cr%^CYAN%^y%^WHITE%^stal%^CYAN%^l%^WHITE%^"
"ine %^RESET%^%^CYAN%^container.  Unlike most decanters however, this one seems far too small to be used in "
"pouring out multiple drinks, as it seems only large enough for a drink for one.  It seems you could %^WHITE%^"
"drink from decanter%^CYAN%^ if you were so inclined.  Some runes have been inscribed onto the bottom of the "
"vessel.%^RESET%^");
   set_lore("%^WHITE%^%^BOLD%^In ancient times, the priests of the dwarven city of Migar Denorth were credited "
"as being the creators of this highly-prized dwarven artifact, as a gift to the new king, Thane IronGuurden.  "
"It was said to be just large enough for one dwarf, designed to be drained in a single swig, unlike usual "
"decanters that are made to hold an entire bottle of alcohol within.  Yet, the decanter was enchanted "
"powerfully so that it would never run out of rum, refilling itself whenever it was emptied.  This artifact "
"disappeared many centuries ago after a drow raid upon the underground civilization, and following the city's "
"destruction, it was lost to history for most of the ensuing centuries, with only occasional mentions of its "
"possession by various travellers and adventurers. The last known owner of the vessel was a dwarf by the name "
"of Chance, who roamed the realms of ShadowGate for many years within the last century. Tales of both him and "
"the decanter were lost to the pages of history after he wandered off alone into the underdark.%^RESET%^\n");
    set_property("lore difficulty",30);
    set_property("id difficulty",30);
    set_read("%^RESET%^%^ORANGE%^If lost, return to Chance.%^RESET%^\n");
    set_language("dwarvish");
    set_weight(1);
    set_value(4500);
}

void init() {
    ::init();
    add_action("drink","drink");
}

void drink(string str) {
    if(!userp(ETO)) {
      notify_fail("You must be holding the decanter to drink from it.\n");
      return 0;
    }
    if(!str) {
      notify_fail("Drink from what?\n");
      return 0;
    }
    if(str == "decanter" || str == "from decanter") {
      ETO->add_quenched(20);
      ETO->add_intox(random(100)+200);
      tell_object(ETO,"%^CYAN%^You uncap the decanter and take a long swig, draining the %^ORANGE%^da%^RED%^r"
"%^ORANGE%^k rum %^CYAN%^within it.%^RESET%^");
      tell_room(EETO,"%^CYAN%^"+ETO->QCN+" uncaps "+ETO->QP+" decanter and takes a long swig, draining the "
"%^ORANGE%^da%^RED%^r%^ORANGE%^k rum %^CYAN%^from it.%^RESET%^",ETO);
      tell_room(EETO,"%^CYAN%^A second later, the decanter magically refills itself, and is once again full of "
"the %^ORANGE%^dark a%^RED%^m%^ORANGE%^ber-hued li%^RED%^q%^ORANGE%^uid%^CYAN%^.%^RESET%^");
      return 1;
    }
    notify_fail("You can't drink from that.\n");
    return 0;
}

int isMagic(){ return 1; }