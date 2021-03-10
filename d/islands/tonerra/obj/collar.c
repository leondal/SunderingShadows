#include <std.h>
inherit ARMOUR;

void create(){
   ::create();
   set_name("leather collar");
   set_id(({"collar","leather collar","studded collar","studded leather collar","platinum studded collar","platinum-studded collar","platinum-studded leather collar","lyzens collar","lyzen's collar","Lyzen's Collar"}));
   set_short("%^RESET%^%^ORANGE%^Ly%^BOLD%^%^BLACK%^ze%^RESET%^%^ORANGE%^n's Collar%^RESET%^");
   set_obvious_short("%^BOLD%^%^WHITE%^pl%^CYAN%^a%^WHITE%^tinum-st%^RESET%^ud%^BOLD%^%^WHITE%^ded %^RESET%^%^ORANGE%^leather collar%^RESET%^");
   set_long("%^RESET%^This collar is lighter than it first appears, and of "
"much finer make.  A tanned strip of %^ORANGE%^lea%^BOLD%^%^BLACK%^th%^RESET%^"
"%^ORANGE%^er %^RESET%^forms the base of the accessory, which has been "
"carefully bordered with fine stitches of %^ORANGE%^tan thread%^RESET%^, nearly "
"invisible against the dun colored leather.  Along the length of the strip are "
"evenly-spaced studs of brightly polished %^BOLD%^%^WHITE%^pl%^CYAN%^a"
"%^WHITE%^ti%^RESET%^nu%^BOLD%^%^WHITE%^m%^RESET%^, each raised to a gentle "
"point.  They serve to break up the otherwise dull appearance of the garment, "
"as a small touch of extravagance.  At the back, a narrow buckle of the same "
"%^BOLD%^%^WHITE%^bri%^CYAN%^g%^WHITE%^ht m%^RESET%^et%^BOLD%^%^WHITE%^al "
"%^RESET%^serves to hold the garment closed about the throat, adjustable for a "
"variety of sizes by the little notches perforated into the leather.\n");
   set_weight(2);
   set_size(2);
   set_type("clothing");
   set_limbs(({"neck"}));
   set_property("enchantment",5);
   set_item_bonus("magic resistance",1);
   set_value(4000);
   set_lore("'Tomorrow we depart to the caverns. I cautioned the others last "
"night that I still did not trust Sylren, even now, even after twenty years of "
"working with him this closely. He still sets my teeth on edge. My divinations "
"give me no answers, and the research into him that I have paid well for has "
"resulted in likewise. Yet, in my gut, I know he will betray us. Llasbel and "
"Ashalor tell me that if he was going to betray us he would have done so long "
"ago, but I disagree. I believe that Sylren seeks something within the Caverns "
"of Ibrandul. I just cannot fathom what. What I do know is that this mission is "
"ill fated and we will not return from it. So I write these words here that "
"someone may one day find this journal and learn the truth of what happened.'"
"\n\n'When I forged each of the items, including the enchanted collar that I "
"will wear, I added another level of enchantments buried deep within their core"
". I did this without telling anyone, for I believe Sylren's goal in this was "
"to gain the control of all four Godslayer devices and to take the mantle of "
"godhood from Ibrandul. Using us as sacrifices to buy him the time he needs to "
"accomplish this. Thus, I have enchanted the items with a safety device, that "
"if they are ever used together they will counter each other, nulling their "
"collective protections and enchantments. If just carried this will not happen, "
"but if he attempts to use them together he will find himself as naked "
"of protection as a new born babe.'\n\n"
"'I pray that this precaution will not be tested, but I fear that Sylren's true "
"intent is to betray and take these items. And if it comes to that and we fall "
"to his might, then we will at least be able to strike back at him from the "
"grave. And he will fall as well. May Tempus, Akadi and my own Mystra watch "
"over us, for Sylren's god whomever she is will not.' - From the journal of "
"Lyzen Sordas, Arch Magi of Mystra.");
   set_property("lore difficulty",18);
   set_wear((:TO,"wear_it":));
   set_remove((:TO,"remove_it":));
}

int wear_it(){
    tell_room(EETO,"%^ORANGE%^"+ETOQCN+" secures the collar around "+ETO->QP+
" throat.%^RESET%^",ETO);
    tell_object(ETO,"%^ORANGE%^You secure the collar in place with the fine "
"metal buckle.%^RESET%^");
    return 1;
}

int remove_it(){
    tell_room(EETO,"%^ORANGE%^"+ETOQCN+" lets out a sigh as "+ETO->QS+
" unclasps the collar from around "+ETO->QP+" throat.%^RESET%^",ETO);
    tell_object(ETO,"%^ORANGE%^You unclasp the collar and let out a "
"sigh.%^RESET%^");
    return 1;
}
