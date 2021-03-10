#include <std.h>
inherit OBJECT;

int charges;
void set_mydesc();

void create() {
    ::create();
    set_name("box of dust");
    set_id(({"box of dust","iridescent dust","dust","box","small box","powder","insightful powder","chazaels powder"}));
    set_short("%^BOLD%^%^WHITE%^Chazael's Ins%^CYAN%^i%^WHITE%^ght%^RESET%^fu%^BOLD%^%^WHITE%^l Powder%^RESET%^");
    set_obvious_short("%^RESET%^%^ORANGE%^small box of %^RESET%^i%^BOLD%^%^WHITE%^ri%^RESET%^de%^BOLD%^%^WHITE%^s%^CYAN%^c%^RESET%^ent %^ORANGE%^dust%^RESET%^");
    set_property("lore difficulty",30);
    set_property("id difficulty",30);
    set_weight(5);
    set_value(4500);
    charges = 8+ random(5);
    set_mydesc();
}

void init() {
    ::init();
    add_action("dust_fun","sprinkle");
}

void dust_fun(string str) {
    object mytarg;
    string mytarget;
    if(!userp(ETO)) return notify_fail("You must be holding the box of dust to use it.\n");
    if(!str) return notify_fail("What do you want to sprinkle?\n");
    if(sscanf(str,"dust over %s", mytarget) != 1) return notify_fail("You can't sprinkle that.\n");
    if(!mytarg = present(mytarget,ETO)) return notify_fail("You aren't carrying a "+mytarget+".\n");
    if(!charges) return notify_fail("There is no dust left in the box.\n");
    tell_object(ETO,"%^CYAN%^You take a pinch of %^BOLD%^%^WHITE%^dust %^RESET%^%^CYAN%^from the box, and sprinkle it "
"over the "+mytarget+".  The dust vanishes with a %^RESET%^sh%^BOLD%^%^WHITE%^i%^RESET%^mm%^BOLD%^%^CYAN%^e%^RESET%^r "
"%^CYAN%^as it makes contact with the item, leaving its true nature revealed to you!%^RESET%^");
    tell_room(EETO,"%^CYAN%^"+ETO->QCN+" takes a pinch of %^BOLD%^%^WHITE%^dust %^RESET%^%^CYAN%^from the box, and "
"sprinkles it over the "+mytarget+".  The dust vanishes with a %^RESET%^sh%^BOLD%^%^WHITE%^i%^RESET%^mm%^BOLD%^%^CYAN%^e"
"%^RESET%^r %^CYAN%^as it makes contact with the item.%^RESET%^%^RESET%^",ETO);
    mytarg->add_identified((string)TP->query_name());
    charges--;
    set_mydesc();
    return 1;
}

int isMagic(){ return 1; }

void set_mydesc() {
    if(!charges) {
      set_long("%^RESET%^%^ORANGE%^This small wooden box is only about six inches long, and half that in height.  Despite "
"its size, every inch of its outer surface is covered in carvings that form a massive, %^MAGENTA%^w%^GREEN%^ho%^MAGENTA%^"
"rl%^CYAN%^in%^MAGENTA%^g %^ORANGE%^pattern that seems to have no real purpose other than its own chaotic artistry.  It "
"has been carefully oiled to bring out a %^RED%^deep s%^ORANGE%^h%^RED%^ine %^ORANGE%^from the wood itself.  Opening its "
"small %^YELLOW%^gol%^WHITE%^d%^YELLOW%^en %^RESET%^%^ORANGE%^clasp reveals that the box is empty inside, with only a few "
"grains of fine, %^RESET%^i%^BOLD%^%^WHITE%^ri%^RESET%^de%^BOLD%^%^WHITE%^s%^CYAN%^c%^RESET%^ent %^ORANGE%^white dust in "
"the corners to hint at its original contents.%^RESET%^");
      set_lore("%^WHITE%^%^BOLD%^Chazael, an enchanter and cunning merchant, devised magical items of all kinds for the "
"nobility, believing that in selling to the upper class was the way to quick riches. However, one of his magical "
"creations which scholars billed as ingenius, saw none of the fame to which some of his others rose. Dust created from "
"pearl and owlfeathers, the usual components of identification magic, was imbued with an enchantment-in-stasis. This had "
"the effect of only completing the spell when scattered, identifying whatever item it fell upon and consuming the "
"components upon the casting. To most this would seem valuable indeed, allowing use of the spell without a scroll or the "
"assistance of a wizard. It seems very few parties were interested in the purchase of the dust at the time, however, as "
"the nobility had more than enough petty mages at their call who would take care of such spells for them. So, it seems, "
"the knowledge of the spells used to create the dust were lost from memory, and one of the highest praised creations of "
"the fifth century now remains nothing more than rumor.  You're fairly sure you could have used such dust, but there is "
"none left...\n");
      return;
    }
    if(charges < 3) {
      set_long("%^RESET%^%^ORANGE%^This small wooden box is only about six inches long, and half that in height.  Despite "
"its size, every inch of its outer surface is covered in carvings that form a massive, %^MAGENTA%^w%^GREEN%^ho%^MAGENTA%^"
"rl%^CYAN%^in%^MAGENTA%^g %^ORANGE%^pattern that seems to have no real purpose other than its own chaotic artistry.  It "
"has been carefully oiled to bring out a %^RED%^deep s%^ORANGE%^h%^RED%^ine %^ORANGE%^from the wood itself.  Opening its "
"small %^YELLOW%^gol%^WHITE%^d%^YELLOW%^en %^RESET%^%^ORANGE%^clasp reveals that the box contains a few pinches of white "
"dust, finer than sand and possessed of an %^RESET%^i%^BOLD%^%^WHITE%^ri%^RESET%^de%^BOLD%^%^WHITE%^s%^CYAN%^c%^RESET%^"
"ent %^ORANGE%^sheen.%^RESET%^");
      set_lore("%^WHITE%^%^BOLD%^Chazael, an enchanter and cunning merchant, devised magical items of all kinds for the "
"nobility, believing that in selling to the upper class was the way to quick riches. However, one of his magical "
"creations which scholars billed as ingenius, saw none of the fame to which some of his others rose. Dust created from "
"pearl and owlfeathers, the usual components of identification magic, was imbued with an enchantment-in-stasis. This had "
"the effect of only completing the spell when scattered, identifying whatever item it fell upon and consuming the "
"components upon the casting. To most this would seem valuable indeed, allowing use of the spell without a scroll or the "
"assistance of a wizard. It seems very few parties were interested in the purchase of the dust at the time, however, as "
"the nobility had more than enough petty mages at their call who would take care of such spells for them. So, it seems, "
"the knowledge of the spells used to create the dust were lost from memory, and one of the highest praised creations of "
"the fifth century now remains nothing more than rumor.  You're fairly sure you could still use this dust with %^YELLOW%^"
"<sprinkle dust over item>%^WHITE%^.  You imagine there is enough dust left to identify only "+charges+" more items."
"%^RESET%^\n");
      return;
    }
    set_long("%^RESET%^%^ORANGE%^This small wooden box is only about six inches long, and half that in height.  Despite "
"its size, every inch of its outer surface is covered in carvings that form a massive, %^MAGENTA%^w%^GREEN%^ho%^MAGENTA%^"
"rl%^CYAN%^in%^MAGENTA%^g %^ORANGE%^pattern that seems to have no real purpose other than its own chaotic artistry.  It "
"has been carefully oiled to bring out a %^RED%^deep s%^ORANGE%^h%^RED%^ine %^ORANGE%^from the wood itself.  Opening its "
"small %^YELLOW%^gol%^WHITE%^d%^YELLOW%^en %^RESET%^%^ORANGE%^clasp reveals that the box contains a portion of white dust"
", finer than sand and possessed of an %^RESET%^i%^BOLD%^%^WHITE%^ri%^RESET%^de%^BOLD%^%^WHITE%^s%^CYAN%^c%^RESET%^ent "
"%^ORANGE%^sheen.%^RESET%^");
    set_lore("%^WHITE%^%^BOLD%^Chazael, an enchanter and cunning merchant, devised magical items of all kinds for the "
"nobility, believing that in selling to the upper class was the way to quick riches. However, one of his magical "
"creations which scholars billed as ingenius, saw none of the fame to which some of his others rose. Dust created from "
"pearl and owlfeathers, the usual components of identification magic, was imbued with an enchantment-in-stasis. This had "
"the effect of only completing the spell when scattered, identifying whatever item it fell upon and consuming the "
"components upon the casting. To most this would seem valuable indeed, allowing use of the spell without a scroll or the "
"assistance of a wizard. It seems very few parties were interested in the purchase of the dust at the time, however, as "
"the nobility had more than enough petty mages at their call who would take care of such spells for them. So, it seems, "
"the knowledge of the spells used to create the dust were lost from memory, and one of the highest praised creations of "
"the fifth century now remains nothing more than rumor.  You're fairly sure you could still use this dust with %^YELLOW%^"
"<sprinkle dust over item>%^WHITE%^.  You imagine there is enough dust left to identify "+charges+" more items.%^RESET%^"
"\n");
}

void renew_charges() { charges = 8+ random(5); set_mydesc(); }
int is_tazrak_charged() { return 1; }
