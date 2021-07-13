#include <std.h>
#include "../lair.h"
inherit "/d/common/obj/weapon/waveblade";

int OWNED;
string *owners;

void create() {
    ::create();
    set_name("obsidian dagger");
    set_id(({"sheol dagger","dagger","obsidian dagger","ornate dagger"}) );
    set_short("%^BOLD%^%^BLACK%^Sh%^RESET%^%^BLUE%^e%^BOLD%^%^BLACK%^ol Dag%^RESET%^%^MAGENTA%^g%^BOLD%^%^BLACK%^er%^RESET%^");
    set_obvious_short("%^BOLD%^%^BLACK%^an or%^RESET%^%^MAGENTA%^n%^BOLD%^%^BLACK%^ate obs%^RESET%^%^BLUE%^i%^BOLD%^%^BLACK%^dian dagg%^RESET%^%^MAGENTA%^e%^BOLD%^%^BLACK%^r%^RESET%^");
    set_long("%^RESET%^%^BLUE%^This dagger is nothing short of a work of %^BOLD%^art%^RESET%^%^BLUE%^. "
"Elaborate designs wrap their way up its %^BOLD%^%^BLACK%^obs%^RESET%^%^ORANGE%^i%^BOLD%^%^BLACK%^d%^RESET%^"
"%^ORANGE%^i%^BOLD%^%^BLACK%^an h%^RESET%^%^ORANGE%^i%^BOLD%^%^BLACK%^lt%^RESET%^%^BLUE%^, marking out "
"%^MAGENTA%^da%^CYAN%^rk%^MAGENTA%^ly%^BLUE%^-%^MAGENTA%^gl%^CYAN%^owi%^MAGENTA%^ng%^BLUE%^, abstract patterns "
"against the blackened grip. They draw the eye upward, past the swept hilt towards its %^WHITE%^gl%^BOLD%^"
"%^BLACK%^a%^RESET%^ssy bl%^BOLD%^%^BLACK%^a%^RESET%^de %^BLUE%^which, despite its smooth surface, reflects no "
"%^YELLOW%^l%^WHITE%^i%^YELLOW%^g%^WHITE%^h%^YELLOW%^t %^RESET%^%^BLUE%^forth. The blade itself is absolutely "
"flawless, marred only by the detailed %^GREEN%^r%^BOLD%^u%^RESET%^%^GREEN%^n%^BOLD%^e%^RESET%^%^GREEN%^s "
"%^BLUE%^that mark out unknown meanings across its surface. They glow %^MAGENTA%^so%^CYAN%^ft%^MAGENTA%^ly "
"%^BLUE%^with a faded gleam, creating a beautiful contrast with the weapon's blackened color. Yet as you watch"
", the blade appears to your eyes to be oddly %^BOLD%^%^BLACK%^in%^RESET%^s%^BOLD%^%^BLACK%^ubs%^RESET%^t"
"%^BOLD%^%^BLACK%^ant%^RESET%^i%^BOLD%^%^BLACK%^al%^RESET%^%^BLUE%^, and you can often catch glimpses right "
"through its wavering form.\n%^RESET%^");
    set_lore("The Sheol Dagger is steeped in mystery.  Very few claim to know of its origins and even fewer "
"know of the exact manner in which they are formed.  Rumors are abundant, ranging from tales of complex arcane "
"summoning rituals, to stories of the natural formation of the dagger from the essence of the shadow plane.  "
"Though little is known of its origins, all agree that the weapon is incredibly powerful.  It is able to pass "
"through mere armor and defenses as if they were not even present, nothing more than shadows and mist.  It is "
"said to be so powerful in fact, that its very nature is shared with the one who masters it, causing both "
"blade and wielder to seem insubstantial and hazy as though only partly of this world.");
    set_property("lore difficulty",35);
    set_property("id difficulty",35);
    set_value(13250);
    set_prof_type("sheol dagger");
    set_property("enchantment",5);
    while((int)TO->query_property("enchantment") != 5) {
      TO->remove_property("enchantment");
      TO->set_property("enchantment",5);
    }
    set_item_bonus("attack bonus",4);
    set_item_bonus("stealth",4);
    set_property("magic",1);
    set_wield((:TO,"wield_func":));
    set_unwield((:TO,"unwield_func":));
    set_hit((:TO,"hit_func":));
    set_property("no alter",1);
    owners = ({});
    set_property("master weapon",1);
}

int wield_func(){
   int myflag, i;
   object myob, *mywielded;
   string thename;
   if(!userp(ETO)) return 1;
   if(member_array("%^BOLD%^%^BLACK%^Vanquished Arkhon Bloodscale, ancient dragon of the deep!%^RESET%^",ETO->query_mini_quests())== -1) {
     tell_object(ETO,"%^BOLD%^%^WHITE%^You have not earned the right to make use of this item.%^RESET%^");
     return 0;
   }
   if(ETO->query_level() < 35) {
     tell_object(ETO,"You are not experienced enough to use this weapon.");
     return 0;
   }
   if(ETO->query_property("master weapon")) { //preventing stack up with other "top" weapons
     tell_object(ETO,"%^MAGENTA%^Your hand passes straight through the dagger's hilt, as if it were made from "
"nothing but %^CYAN%^air %^MAGENTA%^and %^BOLD%^%^BLACK%^shadows%^RESET%^%^MAGENTA%^. You feel a conflict with another weapon in hand.%^RESET%^");
     tell_room(EETO,"%^MAGENTA%^"+ETO->QCN+" tries to grasp the dagger, but "+ETO->QP+" hand passes straight "
"through its hilt as if it were made from nothing but %^CYAN%^air %^MAGENTA%^and %^BOLD%^%^BLACK%^shadows"
"%^RESET%^%^MAGENTA%^.%^RESET%^",ETO);
     return 0;
   }
   tell_object(ETO,"%^MAGENTA%^You grasp the hilt of the blade, and watch as your skin becomes of the same "
"%^CYAN%^misty substance %^MAGENTA%^as the dagger itself.%^RESET%^");
   tell_room(EETO,"%^MAGENTA%^"+ETO->QCN+" grasps the hilt of the blade, and you watch as "+ETO->QP+" skin "
"becomes of the same %^CYAN%^misty substance %^MAGENTA%^as the dagger itself.%^RESET%^",ETO);
   ETO->set_property("added short",({" %^BOLD%^%^BLACK%^(a little faded and hazy)%^RESET%^"}));
   ETO->set("long","%^RESET%^%^MAGENTA%^"+capitalize(nominative(TP))+" looks a little hazy, almost %^CYAN%^"
"ethereal%^MAGENTA%^.%^RESET%^");
   ETO->set_property("master weapon",1);
   return 1;
}

int unwield_func(){
   tell_object(ETO,"%^MAGENTA%^Your body becomes %^BLUE%^solid %^MAGENTA%^again as you release your grip on "
"the dagger.%^RESET%^");
   tell_room(EETO,"%^MAGENTA%^"+ETO->QCN+"'s body becomes %^BLUE%^solid %^MAGENTA%^again as "+ETO->QS+
" releases "+ETO->QP+" grip on the dagger.%^RESET%^",ETO);
   ETO->remove_property_value("added short",({" %^BOLD%^%^BLACK%^(a little faded and hazy)%^RESET%^"}));
   ETO->set("long",0);
   ETO->set_property("master weapon",-1);
   return 1;
}

int hit_func(object targ){
   int rand, i, extra;
   object *targetz;

   rand = roll_dice(1,10);
   if(!objectp(ETO)) return 0;
   if(!objectp(EETO)) return 0;
   targ = ETO->query_current_attacker();
   if(!objectp(targ)) return 0;
   if(roll_dice(1,100) > 37) return roll_dice(1,4);

   if(rand > 0 && rand < 5) { // between 1 and 4 or 40%
         tell_room(EETO,"%^MAGENTA%^The dagger's blade fades to %^BOLD%^%^BLACK%^translu%^RESET%^%^BLUE%^ce"
"%^BOLD%^%^BLACK%^nt shadow %^RESET%^%^MAGENTA%^as it passes through armor and clothing unharmed, only leaving "
"its %^RED%^mark %^MAGENTA%^in "+targ->QCN+"'s flesh!%^RESET%^",targ);
         tell_object(targ,"%^MAGENTA%^The dagger's blade fades to %^BOLD%^%^BLACK%^translu%^RESET%^%^BLUE%^ce"
"%^BOLD%^%^BLACK%^nt shadow %^RESET%^%^MAGENTA%^as it passes through your armor and clothing unharmed, only "
"leaving a painful %^RED%^mark %^MAGENTA%^in your flesh!%^RESET%^");
         extra = roll_dice(3,4);
    }

    if(rand > 2 && rand < 6)  {// between 3 and 5 or 30%
         tell_room(EETO,"%^MAGENTA%^"+ETO->QCN+" moves like a %^BOLD%^%^BLACK%^fli%^RESET%^ck%^BOLD%^%^BLACK%^"
"ering sha%^RESET%^d%^BOLD%^%^BLACK%^ow%^RESET%^%^MAGENTA%^, and a trail of %^CYAN%^mist %^MAGENTA%^follows "
+ETO->QP+" movements as "+ETO->QS+" strikes repeatedly at "+targ->QCN+"!%^RESET%^",({ETO,targ}));
         tell_object(ETO,"%^MAGENTA%^You move like a %^BOLD%^%^BLACK%^fli%^RESET%^ck%^BOLD%^%^BLACK%^ering sha"
"%^RESET%^d%^BOLD%^%^BLACK%^ow%^RESET%^%^MAGENTA%^, and a trail of %^CYAN%^mist %^MAGENTA%^follows your "
"movements as you strike repeatedly at "+targ->QCN+"!%^RESET%^");
         tell_object(targ,"%^MAGENTA%^"+ETO->QCN+" moves like a %^BOLD%^%^BLACK%^fli%^RESET%^ck%^BOLD%^"
"%^BLACK%^ering sha%^RESET%^d%^BOLD%^%^BLACK%^ow%^RESET%^%^MAGENTA%^, and a trail of %^CYAN%^mist %^MAGENTA%^"
"follows "+ETO->QP+" movements as "+ETO->QS+" strikes repeatedly at you!%^RESET%^");
       ETO->execute_attack();
    }

    if(rand > 4 && rand < 7) { // between 4 and 6 or 20%
         tell_room(EETO,"%^MAGENTA%^"+ETO->QCN+" slashes the %^BOLD%^%^BLACK%^obs%^RESET%^%^BLUE%^i%^BOLD%^"
"%^BLACK%^dian dagger %^RESET%^%^MAGENTA%^across "+targ->QCN+"'s skin, and "+targ->QP+" movements seem to "
"slow.%^RESET%^",({ETO,targ}));
         tell_object(ETO,"%^MAGENTA%^You slash the %^BOLD%^%^BLACK%^obs%^RESET%^%^BLUE%^i%^BOLD%^%^BLACK%^dian "
"dagger %^RESET%^%^MAGENTA%^across "+targ->QCN+"'s skin, and "+targ->QP+" movements seem to slow.%^RESET%^");
         tell_object(targ,"%^MAGENTA%^"+ETO->QCN+" slashes the %^BOLD%^%^BLACK%^obs%^RESET%^%^BLUE%^i%^BOLD%^"
"%^BLACK%^dian dagger %^RESET%^%^MAGENTA%^across your skin, and where it breaks the flesh an unnatural %^BOLD%^"
"%^CYAN%^c%^WHITE%^h%^CYAN%^ill %^RESET%^%^MAGENTA%^permeates your body, slowing your movements.%^RESET%^");
         targ->set_paralyzed(10 + random(20),"%^BOLD%^%^CYAN%^You are still trying to shake the sluggish feeling from your "
"body!%^RESET%^");
    }

    if(rand > 6 && rand < 10) { // between 7 and 9 or 30%
         tell_room(EETO,"%^MAGENTA%^A glint of %^YELLOW%^li%^WHITE%^gh%^YELLOW%^t %^RESET%^%^MAGENTA%^races up "
"through the runes upon the surface of "+ETO->QCN+"'s blade, lending a momentary %^GREEN%^g%^BOLD%^l%^RESET%^"
"%^GREEN%^e%^BOLD%^a%^RESET%^%^GREEN%^m %^MAGENTA%^to its %^BLUE%^dark%^MAGENTA%^, %^BOLD%^%^BLACK%^glo"
"%^RESET%^ss%^BOLD%^%^BLACK%^y %^RESET%^%^MAGENTA%^surface before they are snuffed out again.%^RESET%^",ETO);
         tell_object(ETO,"%^MAGENTA%^A glint of %^YELLOW%^li%^WHITE%^gh%^YELLOW%^t %^RESET%^%^MAGENTA%^races "
"up through the runes upon the surface of your blade, lending a momentary %^GREEN%^g%^BOLD%^l%^RESET%^"
"%^GREEN%^e%^BOLD%^a%^RESET%^%^GREEN%^m %^MAGENTA%^to its %^BLUE%^dark%^MAGENTA%^, %^BOLD%^%^BLACK%^glo"
"%^RESET%^ss%^BOLD%^%^BLACK%^y %^RESET%^%^MAGENTA%^surface before they are snuffed out again.  A refreshing "
"feeling of %^CYAN%^vitality %^MAGENTA%^runs through you!%^RESET%^");
       ETO->cause_typed_damage(ETO,"torso",(random(40)-80),"positive energy");
    }

    if(rand == 10) { // blind on 10% only
	tell_object(ETO,"%^MAGENTA%^The runes upon your dagger flare with a %^RED%^ma%^BOLD%^%^RED%^l%^RESET%^%^RED%^ign "
"%^MAGENTA%^gleam as you plunge the weapon into "+targ->QCN+", and "+targ->QS+" blinks sightlessly.%^RESET%^");
	tell_object(targ,"%^MAGENTA%^The runes upon "+ETO->QCN+"'s dagger flare with a %^RED%^ma%^BOLD%^%^RED%^l%^RESET%^%^RED%^ign "
"%^MAGENTA%^gleam as "+ETO->QS+" plunges the weapon into you, and a %^BLUE%^dark haze %^MAGENTA%^momentarily obscures your vision!");
	tell_room(EETO,"%^MAGENTA%^The runes upon "+ETO->QCN+"'s dagger flare with a %^RED%^ma%^BOLD%^%^RED%^l%^RESET%^%^RED%^ign "
"%^MAGENTA%^gleam as "+ETO->QS+" plunges the weapon into "+targ->QCN+", and "+targ->QS+" blinks sightlessly.%^RESET%^",({ETO,targ}));
      targ->set_temporary_blinded(2);
    }

    if(extra) return extra;
}

void bind_me(string *pplz) {
   owners += pplz;
   OWNED = 1;
}

string * bound_to() {
   if(sizeof(owners)) return owners;
   return 0;
}
