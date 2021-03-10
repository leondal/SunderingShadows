#include <std.h>
#include <daemons.h>
inherit ARMOUR;

int charges;

void create() {
   ::create();
   set_name("circlet");
   set_id(({"circlet","gemmed circlet","silver circlet","circlet of telepathy","Circlet of Telepathy"}));
   set_short("%^BOLD%^%^BLACK%^C%^RESET%^ir%^BOLD%^%^BLACK%^c%^RESET%^le%^BOLD%^%^BLACK%^t %^RESET%^of %^MAGENTA%^Te%^RED%^l%^MAGENTA%^epa%^RED%^t%^MAGENTA%^hy%^RESET%^");
   set_obvious_short("%^BOLD%^%^BLACK%^a %^RESET%^g%^BOLD%^em%^RESET%^m%^BOLD%^e%^RESET%^d %^BOLD%^%^BLACK%^c%^RESET%^ir%^BOLD%^%^BLACK%^c%^RESET%^le%^BOLD%^%^BLACK%^t%^RESET%^");
   set_long("%^BOLD%^%^BLACK%^This simple circlet bears no flaws or blemishes anywhere upon its pristine surface. It "
"exists as nothing more than a perfect circle of brightly polished %^WHITE%^si%^RESET%^lv%^BOLD%^%^WHITE%^er%^BLACK%^, "
"gleaming as it catches light.  Lacking excess adornments, it is set at the front with a single oval gemstone of mottled "
"opal, reflecting soft %^RESET%^p%^CYAN%^a%^WHITE%^st%^MAGENTA%^e%^WHITE%^l %^BOLD%^%^BLACK%^hues in its %^RESET%^cl"
"%^BOLD%^o%^RESET%^udy %^BOLD%^%^BLACK%^depths.  Tiny etchings of %^BLUE%^a%^CYAN%^r%^BLUE%^ca%^CYAN%^n%^BLUE%^e "
"%^BLACK%^runes pattern the underside of the circlet itself, unseen when the delicate piece is worn.%^RESET%^");
   set_lore("%^YELLOW%^...Elsebeth pined, for surely she would never see her love again! Constantly was she under watch "
"and under guard, never allowed to leave home without an escort. Oft she would see him, hiding among the crowds, awaiting "
"any chance to approach her if her minders should become lax, but not once did they waver in their guard.\n\n"
"%^YELLOW%^Days became weeks, and weeks became months, as slowly the seasons began to shift and hope began to fade. It "
"was just another sunny morn in Plantingdays when Elsebeth's attention was drawn to a pretty, but seemingly mundane item "
"of jewelry; a circlet of wrought silver set with a single cloudy gem. As she lifted it from the market stall to take a "
"closer look, a voice whispered as if into her very thoughts, 'Take it'. She knew that voice, knew it all too well.\n\n"
"%^YELLOW%^Elsebeth passed the handful of coins across to the shopkeeper and settled it upon her head, allowing herself a "
"brief smile as her guardian ushered her forward. The soothing sound of that beloved voice returned, reaching more "
"clearly into her thoughts, and she cried out to his mind in answer, after too long apart. Noone would keep her from "
"him, not now...%^RESET%^\n");
   set_property("lore difficulty",30);
   set_property("id difficulty",30);
   set_weight(0);
   set_limbs(({"head"}));
   set_ac(0);
   set_value(2000);
   set_type("clothing");
   set_wear((:TO,"wear_fun":));
   charges = 30+ random(11);
}

void init() {
   ::init();
   add_action("contact_me","contact");
}

int wear_fun() {
    if(ETO->query_level() < 35) {
      tell_object(ETO,"You are not experienced enough to use this circlet.");
      return 0;
    }
    tell_object(ETO,"%^BOLD%^%^BLACK%^The %^RESET%^cl%^BOLD%^o%^RESET%^udy %^BOLD%^%^BLACK%^opal gleams as you settle the "
"circlet in place.  The thought enters your mind, unbidden, to %^YELLOW%^contact%^BLACK%^ someone.%^RESET%^");
    tell_room(EETO,"%^BOLD%^%^BLACK%^The %^RESET%^cl%^BOLD%^o%^RESET%^udy %^BOLD%^%^BLACK%^opal gleams as the circlet "
"settles into place upon "+ETO->QCN+"'s brow.%^RESET%^",ETO);
    return 1;
}

int contact_me(string str) {
   if(!TO->query_worn()) {
     notify_fail("You should be wearing the circlet to activate the spell.\n");
     return 0;
   }
   if(!str) {
     notify_fail("You should specify who you want to contact.\n");
     return 0;
   }
   if(!charges) {
     notify_fail("The circlet's power is already depleted.\n");
     return 0;
   }
   charges--;
   tell_room(ETP,"%^BOLD%^%^BLACK%^The opal %^RESET%^glows %^BOLD%^%^BLACK%^momentarily in "+TP->QCN+
"'s circlet.%^RESET%^",TP);
   new("/cmds/spells/t/_telepathy")->use_spell(ETO,str,40,100,"cleric");
   return 1;
}

int isMagic(){ return 1; }

void renew_charges() { charges = 30+ random(11); }
int is_tazrak_charged() { return 1; }
