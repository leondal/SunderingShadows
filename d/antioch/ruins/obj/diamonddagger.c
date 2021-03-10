//new description provided by Mithras and added
//by Circe 7/26/05
//Added exotic weapon prof and lowered level to 20 to match level change to Screamer. Octothorpe 5/7/09
// changed to only hit thru stoneskin on specials, but v high special rate. Moved wield level back to 25, as special is pretty badass. Nienne, 08/09.
//Getting rid of damage override and type override. It's a dagger.  If we want it to be a different type of weapon, so be it, but it's change base type ~ Odin
#include <std.h>

//inherit WEAPON;
inherit "/d/common/obj/weapon/dagger.c";
string OWNER;
void init() {
   ::init();
   if(interactive(TP) && TP==environment(TO) && !OWNER) OWNER = TPQN;
}

void create() {
::create();
   set_name("diamond dagger");
   set_id( ({"dagger","diamond dagger","wrath","wrath of heaven","heaven dagger"}) );
/*
   set_obvious_short("diamond tipped dagger");
   set_short("%^BOLD%^%^CYAN%^W%^BOLD%^%^BLUE%^r%^BOLD%^%^CYAN%^ath of %^BOLD%^%^WHITE%^H%^BOLD%^%^YELLOW%^e%^BOLD%^%^WHITE%^aven%^RESET%^");
   set_long(
      "%^BOLD%^%^CYAN%^A dagger made of flawless steel with a diamond tipped blade. The length"
      " of the dagger is unmarked with any runes, but the tip is set in %^BOLD%^%^WHITE%^glittering%^BOLD%^%^CYAN%^"
      " diamond dust. The hilt is of solid gold and in the shape of a rectangle. The"
      " handle of the weapon follows same theme and is made of solid gold as well, but is"
      " wrapped in many layers of fine Tsarvian silk."
   );
*/
   set_short("%^BOLD%^%^CYAN%^W%^BOLD%^%^BLUE%^r%^BOLD%^%^CYAN%^ath "+
      "%^RESET%^%^WHITE%^of %^BOLD%^%^WHITE%^H%^RESET%^%^WHITE%^e"+
      "%^BOLD%^%^WHITE%^av%^RESET%^%^WHITE%^e%^BOLD%^%^WHITE%^n%^RESET%^");
   set_obvious_short("%^RESET%^%^WHITE%^a g%^BOLD%^%^WHITE%^l%^RESET%^"+
      "%^WHITE%^i%^BOLD%^%^WHITE%^t%^RESET%^%^WHITE%^t%^BOLD%^%^WHITE%^"+
      "e%^RESET%^%^WHITE%^r%^BOLD%^%^WHITE%^i%^RESET%^%^WHITE%^n%^BOLD%^"+
      "%^WHITE%^g %^RESET%^%^WHITE%^dagger%^RESET%^");
   set_long("%^BOLD%^%^CYAN%^This slender dagger is forged from "+
      "%^BOLD%^%^WHITE%^flawless steel %^BOLD%^%^CYAN%^with a long, "+
      "gently curved blade set with fine diamond dust.  There are no "+
      "other markings on the blade, which blends delicately into a "+
      "fine %^RESET%^%^WHITE%^platinum hilt%^BOLD%^%^CYAN%^.  Around "+
      "the grip is wrapped a tight checkered %^BOLD%^%^BLUE%^w%^BOLD%^"+
      "%^WHITE%^e%^BOLD%^%^CYAN%^a%^BOLD%^%^WHITE%^v%^BOLD%^%^BLUE%^e "+
      "%^BOLD%^%^CYAN%^of fine Tsarven silks.  The handle is smoothly "+
      "rounded to fit comfortably into a hand, and ends in an orb as "+
      "its hilt, engraved with %^BOLD%^%^WHITE%^ar%^RESET%^%^WHITE%^c"+
      "%^BOLD%^%^WHITE%^a%^BOLD%^%^CYAN%^n%^RESET%^%^WHITE%^e ru%^BOLD%^"+
      "%^CYAN%^n%^BOLD%^%^WHITE%^e%^RESET%^%^WHITE%^s%^BOLD%^%^CYAN%^.%^RESET%^");
   set_lore(
   "This dagger was created by the wizards, Jancarius Seiryujinn and Mithras Silvertree, and the weaponsmith Tengri Beovule on Lightday 24, Autumnstime 664 SG."+
   "Soon after, the dagger was remade by the Archmage of Antioch Welkanar several times to aid those who are in need of its magic."
   );
   set_property("lore difficulty",20);
   //set_weight(10);
   set_value(2000);
   //set_wc(1,6);
   //set_large_wc(1,8);
   set_size(1);
   //set_weapon_prof("exotic");
   //set_prof_type("diamond dagger");
  // set_type("slashing");
   set_property("enchantment",4);
   set_wield((:TO,"wield":));
   set_unwield((:TO,"unwield":));
   set_hit((:TO,"hit":));
}

int wield() {
   if((int)ETO->query_level() < 25) {
     write("You lack the skill to posses such a weapon.");
     return 0;
   }
   if( (!ETO->is_class("thief"))) {
     write("You are not fit to wield such a weapon");
     return 0;
   }
   if(interactive(TP) && (string)ETO->query_name() !=OWNER){
     write("This is not your dagger.");
     return 0;
   }
   write("%^BOLD%^%^WHITE%^You quietly grip the %^RESET%^platinum%^BOLD%^%^WHITE%^ hilt of the dagger.%^RESET%^");
   ETO->set_property("good item",1);
   return 1;
}

int unwield() {
   ETO->set_property("good item",-1);
   return 1;
}

int hit(object targ) {
   targ = ETO->query_current_attacker();
   if(!objectp(targ)) return 0;
   if(random(1000) < 400){
     tell_room(environment(query_wielded()),"%^BOLD%^%^WHITE%^The dagger shimmers quickly as "+ETOQCN+" expertly cuts "+targ->QCN+" across the face, leaving a wound so clean, it does not bleed until seconds later.%^RESET%^",({ETO,targ}));
     tell_object(ETO,"%^BOLD%^%^WHITE%^The dagger shimmers quickly as you expertly cut "+targ->QCN+" across the face, leaving a wound so clean, it does not bleed until seconds later.%^RESET%^");
     tell_object(targ,"%^BOLD%^%^WHITE%^"+ETOQCN+"'s dagger shimmers quickly as you are expertly cut across the face, leaving a wound so clean, it does not bleed until seconds later.%^RESET%^");
     TO->set_property("magic",1);
     targ->do_damage("head",roll_dice(3,12));
     TO->set_property("magic",-1);
   }
   return 0;
}
