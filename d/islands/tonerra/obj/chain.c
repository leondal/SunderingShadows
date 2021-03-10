#include <std.h>
inherit "/d/common/obj/armour/chain";

void create(){
   ::create();
   set_name("chain");
   set_id(({"chain","hauberk","mithril chainmail","platinum chainmail","chainmail","chain mail","mithril and platinum chainmail","fortified hauberk"}));
   set_short("%^BOLD%^%^WHITE%^Asha%^RESET%^lo%^BOLD%^%^WHITE%^r's Fo%^YELLOW%^r%^WHITE%^tified Ha%^RESET%^u%^BOLD%^%^WHITE%^berk%^RESET%^");
   set_obvious_short("%^BOLD%^%^WHITE%^mith%^CYAN%^r%^WHITE%^il and pl%^RESET%^at%^BOLD%^%^WHITE%^inum chainmail%^RESET%^");
   set_long("%^BOLD%^%^WHITE%^This suit of armor is made up of countless rings "
"of metal, each shaped as a flawless ring of bright mith%^CYAN%^r%^WHITE%^il "
"metal.  They interlock to form a %^BLUE%^f%^CYAN%^lu%^BLUE%^id %^WHITE%^shield "
"around the wearer's body, allowing for far more movement than plated armor "
"while still affording the protection of metal.  Sleeves extend halfway down "
"the arms, further protecting the limbs from harm.  The suit is surprisingly "
"%^YELLOW%^light %^WHITE%^for such a construction, and oddly interwoven "
"throughout the mith%^CYAN%^r%^WHITE%^il armor are occasional circles of pl"
"%^RESET%^at%^BOLD%^%^WHITE%^inum metal, gleaming brightly amidst the silvery "
"metal.  You're not sure if their placement is strategic for some purpose, or "
"simply random and decorative.%^RESET%^\n");
   set_size(2);
   set_property("enchantment",5);
   set_item_bonus("damage resistance",2);
   set_value(6000);
   set_weight(25);
   set_lore("The betrayal of Sylren the Lordless Knight is a story filled with "
"much speculation and intrigue, as well as a moral that echoes through many "
"adventurer's hearts. It is said that a band of great adventurers, led by the "
"dwarven warrior Ashalor, were beguiled by a Knight that claimed no fidelity to "
"any god or liege but instead claimed to be a hunter of gods. For whatever "
"reason, Ashalor and his companions came to believe this Knight's claims and "
"the greed for fame, glory and reward swept through the already powerful group "
"of adventurers. Wealthy from their past successes, they held nothing back in "
"gathering the needed ingredients and components to forge an item for each of "
"them. Items, which Sylren claimed, would protect and aid them in the coming "
"battle. The armor, forged of mithril links and inset with enchanted hoops of "
"platinum that were specifically designed to protect Ashalor from such a "
"powerful being, was the first of the pieces finished. And with the success of "
"this piece the others were rushed to their completion after twenty long years. "
"Then the Knight led the group down into the earth to where Ibrandul waiting, "
"only to betray them at the end with his greed and belief he would escape. It "
"is said that Sylren indeed prayed to a god, but that She betrayed him in the "
"end, not granting him the portal of escape to take the god slaying items away. "
"Rumor has it that these items lay upon the corpses of the adventuring group "
"still.");
   set_property("lore difficulty",18);
   set_wear((:TO,"wear_it":));
   set_remove((:TO,"remove_it":));
   set_struck((:TO,"strike_it":));
}

int wear_it(){
    tell_room(EETO,"%^YELLOW%^The links of %^WHITE%^pl%^RESET%^at%^BOLD%^"
"%^WHITE%^inum %^YELLOW%^gleam brightly as "+ETOQCN+" slides into the "
"chainmail.%^RESET%^",ETO);
    tell_object(ETO,"%^YELLOW%^The links of %^WHITE%^pl%^RESET%^at%^BOLD%^"
"%^WHITE%^inum %^YELLOW%^gleam brightly as you slide into the chainmail"
".%^RESET%^");
    return 1;
}

int remove_it(){
    tell_room(EETO,"%^YELLOW%^"+ETOQCN+" removes the fine chainmail and glances "
"around.%^RESET%^",ETO);
    tell_object(ETO,"%^YELLOW%^It leaves you feeling vulnerable to remove the "
"suit of fine chainmail.%^RESET%^");
    return 1;
}

int struck_fun(int damage,object what,object who){
   if(!random(3)){
     tell_room(EETO,"%^YELLOW%^"+who->QCN+"'s blow bounces harmlessly off the "
"bright links of "+ETOQCN+"'s chainmail!",({ETO,who}));
     tell_object(ETO,"%^YELLOW%^"+who->QCN+"'s blow bounces harmlessly off the "
"bright links of your chainmail!%^RESET%^");
     tell_object(who,"%^YELLOW%^Your blow bounces harmlessly off the bright "
"links of "+ETOQCN+"'s chainmail!%^RESET%^");
     return damage*(-1);
   }
}