//updated to remove references to old gods ~Circe~ 8/17/19
//Shar's item - added to by Circe.  4/26/04
#include <std.h>
inherit ARMOUR;

int OWNED;
string owner;

void create(){
   ::create();
   set_name("doublet of the flames");
   set_id(({ "doublet", "doublet of the flames", "red doublet" }));
   set_short("%^BOLD%^%^RED%^Doublet of the %^RESET%^%^RED%^F%^ORANGE%^l%^YELLOW%^a%^RED%^m%^YELLOW%^e%^RESET%^%^RED%^s%^RESET%^%^RESET%^");
   set_obvious_short("%^BOLD%^%^RED%^A fiery red silk doublet%^RESET%^");
   set_long("%^BOLD%^%^RED%^Fiery red silk is used in the creation of this fine doublet.  The silk seems to have been woven with %^YELLOW%^gold%^RED%^ threads giving a metallic cast to the silk.  Braided cord of %^YELLOW%^gold%^RED%^ and deeper shades of %^RESET%^%^RED%^red%^BOLD%^ and%^RESET%^%^ORANGE%^ orange%^BOLD%^%^RED%^ trim the front of the doublet, further adding to the majesty of it.  Puffed length of %^YELLOW%^gold%^RED%^ and crimson striped silk cover the long fiery red sleeves.  Five%^YELLOW%^ golden%^RED%^ buttons embossed with the image of a flame run down the front.  This doublet is without a doubt of the finest quality.  When the light hits it right, it almost seems to %^YELLOW%^g%^RESET%^%^ORANGE%^l%^RED%^o%^YELLOW%^w%^RED%^!%^RESET%^");
   set_weight(4);
   set_value(1200);
   set_lore("Some sages speculate that the Doublet of Flames is a royal garment from the flaming pits of hell itself, worn by the demon and devil princes.  Others laugh at such a notion and credit its creation to followers of Jarmila, who often go overboard with their costumes and outfits.  Though this usually meets with a chuckle from a follower of Ryorik, as they credit this doublet to a member of the Cleansing Flame by the name of Uragondon, a hot-headed misogynistic cleric with a fiery temper.");
   set_type("clothing");
   set_limbs(({ "torso" }));
   set_property("enchantment",3);
   set_wear((:TO,"wear_func":));
   set_remove((:TO,"remove_func":));
   set_struck((:TO,"strike_func":));
}

int wear_func(){
   if((string)ETO->query_name() == "ahstuz"){
      return 1;
   }
   if((string)TPQN != owner) {
      tell_object(ETO,"%^RED%^The doublet does not know you!  It disappears in a wisp of smoke!%^RESET%^");
      tell_room(EETO,"%^RED%^As "+ETOQCN+" tries to put on the doublet, it disappears in a wisp of smoke!%^RESET%^",ETO);
      TO->remove();
      return 0;
   }
   tell_room(EETO,"%^BOLD%^%^RED%^"+ETOQCN+" encases "+ETO->QO+"self inside the fiery red doublet.%^RESET%^",ETO);
   tell_object(ETO,"%^BOLD%^%^RED%^You button up the fine doublet, letting the luxurious silk wrap around you.%^RESET%^");
   return 1;
}

int remove_func(){
	tell_room(EETO,"%^BOLD%^%^RED%^"+ETOQCN+" unbuttons the fiery red silk doublet and pulls it off.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^RED%^You unbutton the doublet and slide out of the fine smooth silk.%^RESET%^");
	return 1;
}

int strike_func(int damage, object what, object who){
   if(random(1000) < 175){
      tell_room(environment(query_worn()),"%^BOLD%^%^RED%^Flames lick off of "+ETOQCN+"s fiery red silk doublet and burn "+who->QCN+"!%^RESET%^",({ETO,who}));
      tell_object(ETO,"%^BOLD%^%^RED%^Flames lick off of the silken doublet and %^RESET%^%^RED%^burn%^BOLD%^ "+who->QCN+"!%^RESET%^");
      tell_object(who,"%^BOLD%^%^RED%^Flames lick off of "+ETOQCN+"s fiery red silk doublet and %^B_RED%^%^YELLOW%^burn%^RESET%^%^BOLD%^%^RED%^ you!%^RESET%^");
      who->do_damage("torso",random(8));
   return 0;
   }
}

void init()
{
        ::init();
        if(!interactive(ETO)) return;
        if(interactive(TP) && TP == environment(TO) && !OWNED) {
                owner = TPQN;
                OWNED = 1;
                set_size(TP->query_size());
        }
}
