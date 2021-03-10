#include <std.h>
#include <magic.h>
inherit "/d/common/obj/weapon/quarter_staff";

void create() {
    ::create();
    set_name("staff");
    set_id(({"staff","bo","bo staff","oak staff","banded staff","white oak staff","boshaku","sensei's boshaku"}));
    set_short("%^BOLD%^%^WHITE%^S%^RESET%^e%^BOLD%^%^BLACK%^n%^BOLD%^%^WHITE%^s%^RESET%^e%^BOLD%^%^WHITE%^i's B%^RESET%^%^ORANGE%^o%^RESET%^s%^BOLD%^%^WHITE%^h%^RESET%^ak%^BOLD%^%^WHITE%^u%^RESET%^");
    set_obvious_short("%^BOLD%^%^BLACK%^b%^RESET%^%^ORANGE%^a%^BOLD%^%^BLACK%^n%^RESET%^%^ORANGE%^d%^BOLD%^%^BLACK%^e%^RESET%^%^ORANGE%^d staff of %^BOLD%^%^WHITE%^w%^RESET%^hi%^BOLD%^%^WHITE%^te o%^RESET%^a%^BOLD%^%^WHITE%^k%^RESET%^");
    set_long("%^BOLD%^%^WHITE%^This is an unusually %^RESET%^%^MAGENTA%^e%^RED%^l%^MAGENTA%^e%^BOLD%^%^MAGENTA%^g"
"%^RESET%^%^RED%^a%^MAGENTA%^n%^RED%^t%^BOLD%^%^WHITE%^, ornate version of a weapon usually known for its simplicity"
".  A circular shaft of perfectly straight %^RESET%^wh%^BOLD%^%^WHITE%^it%^RESET%^e o%^BOLD%^%^WHITE%^a%^RESET%^k "
"%^BOLD%^%^WHITE%^serves as the prime substance of the piece, which easily spans six feet in length.  It is %^RESET%^%^ORANGE%^thick "
"%^BOLD%^%^WHITE%^enough in the midsection to allow for a firm grip, and tapers to a more slender circle at each end.  Wide bands of "
"%^BOLD%^%^BLACK%^i%^RESET%^ro%^BOLD%^%^BLACK%^n %^BOLD%^%^WHITE%^encircle the staff at five equal intervals, "
"providing structural support and likely a painful striking surface as well.  Along the length of the pale oak is "
"carved an intricate pattern that doubles back upon itself and traces %^BOLD%^%^GREEN%^c%^BOLD%^%^CYAN%^h"
"%^BOLD%^%^BLUE%^a%^BOLD%^%^WHITE%^o%^BOLD%^%^CYAN%^t%^BOLD%^%^YELLOW%^i%^BOLD%^%^CYAN%^c %^BOLD%^%^WHITE%^swirls, "
"amongst which dance the outlines of four stylised mythical creatures, one each of a %^RESET%^%^CYAN%^dr"
"%^BOLD%^%^CYAN%^a%^RESET%^%^CYAN%^gon%^BOLD%^%^WHITE%^, a %^BOLD%^%^RED%^bi%^YELLOW%^r%^BOLD%^%^RED%^d%^BOLD%^%^WHITE%^"
", a %^RESET%^tig%^BOLD%^%^WHITE%^e%^RESET%^r %^BOLD%^%^WHITE%^and a %^BOLD%^%^BLACK%^to%^RESET%^rt%^BOLD%^%^BLACK%^oi"
"%^RESET%^s%^BOLD%^%^BLACK%^e%^BOLD%^%^WHITE%^.  The craftsmanship is flawless, resulting in a perfectly balanced "
"weapon that would be devastating in combat.\n%^RESET%^");
   set_lore("%^WHITE%^%^BOLD%^Such a staff as this is held as the weapon of the masters of Bojutsu, a Senzokuan martial "
"style of old.  Usually a precise six feet in length, they served as an extension of the wielder's own limbs, using "
"movements that closely resemble empty-hand fighting techniques.  They would be gripped two-handed in thirds, and when "
"held correctly they could be rotated through the hands, to allow for a variety of blocks, strikes, sweeps and entrapments"
".  Usually made of hardwood for greater impact, they would often be studded or banded with metal to cause more devastating "
"blows to an opponent.  Etched upon it are the images of the four guardian spirits, each representing a cardinal direction "
"and a season; the azure dragon of spring, the vermillion bird of summer, the white tiger of autumn, and the black tortoise "
"of winter.%^RESET%^\n");
   set("no curse",1);
   set_property("lore difficulty",27);
   set_property("enchantment",4);
   set_value(11550);
   set_wield((:TO,"wield_fun":));
   set_unwield((:TO,"unwield_fun":));
   set_hit((:TO,"hit_fun":));
}

int wield_fun(){
    int toenchant;
    if(userp(ETO) && member_array("%^RESET%^%^MAGENTA%^%^Defeated the masters of the Vasati Aadhyaatmika.%^RESET%^",ETO->query_mini_quests())== -1) {
      tell_object(ETO,"%^BOLD%^You have not earned the right to make use of this item.%^RESET%^");
      return 0;
    }
    if(userp(ETO) && (int)ETO->query_level() < 25) {
      tell_object(ETO,"%^BOLD%^You must train further before you can attempt to use a weapon of this calibre.%^RESET%^");
      return 0;
    }
    if (!ETO->query_property("silent_wield")) {
        tell_object(ETO, "%^BOLD%^%^BLACK%^You take a balanced grip on the staff and extend it horizontally, ready for combat.%^RESET%^");
        tell_room(EETO, "%^BOLD%^%^BLACK%^" + ETO->QCN + " takes a sturdy grip on the staff and extends it horizontally, ready for combat.%^RESET%^", ETO);
    }
    return 1;
}

int unwield_fun() {
    if (!ETO->query_property("silent_wield")) {
        tell_object(ETO, "%^BOLD%^%^BLACK%^You set the staff aside for now.%^RESET%^");
        tell_room(EETO, "%^BOLD%^%^BLACK%^" + ETOQCN + " sets the staff aside.%^RESET%^", ETO);
    }
    return 1;
}

int hit_fun(object targ) {
   targ = ETO->query_current_attacker();
   if(random(2500)<750){
     switch(random(400)){
       case 0..99:
       tell_object(ETO,"%^CYAN%^You swing the staff forward as the etched dragon g%^BOLD%^%^CYAN%^l%^RESET%^%^CYAN%^e"
"%^BOLD%^%^CYAN%^am%^RESET%^%^CYAN%^s, empowering your strike!%^RESET%^");
       tell_room(EETO,"%^CYAN%^"+ETOQCN+" swings the staff forward as the etched dragon g%^BOLD%^%^CYAN%^l%^RESET%^"
"%^CYAN%^e%^BOLD%^%^CYAN%^am%^RESET%^%^CYAN%^s, empowering "+ETO->QP+" strike!%^RESET%^",ETO);
       return 10;
       break;

       case 100..199:
       tell_object(ETO,"%^RED%^The bird etching sparks with a trace of f%^BOLD%^%^RED%^l%^YELLOW%^a%^RESET%^%^RED%^m"
"%^ORANGE%^e %^RED%^as your staff connects forcefully with "+targ->QCN+", leaving a painful red welt!%^RESET%^");
       tell_object(targ,"%^RED%^The bird etching sparks with a trace of f%^BOLD%^%^RED%^l%^YELLOW%^a%^RESET%^%^RED%^m"
"%^ORANGE%^e %^RED%^as "+ETO->QCN+"'s staff connects forcefully with you, leaving a burning welt!%^RESET%^");
       tell_room(EETO,"%^RED%^The bird etching sparks with a trace of f%^BOLD%^%^RED%^l%^YELLOW%^a%^RESET%^%^RED%^m"
"%^ORANGE%^e %^RED%^as "+ETO->QCN+"'s staff connects forcefully with "+targ->QCN+", leaving a painful red welt"
"!%^RESET%^",({ETO,targ}));
       return 10;
       break;

       case 200..299:
       ETO->execute_attack();
       tell_object(ETO,"%^WHITE%^%^BOLD%^The outline of the carved tiger %^RESET%^sh%^BOLD%^%^WHITE%^i%^RESET%^mme"
"%^BOLD%^%^WHITE%^r%^RESET%^s %^BOLD%^%^WHITE%^as you lash out with newfound speed, stirring the air with a quick "
"second strike!%^RESET%^");
       tell_room(EETO,"%^WHITE%^%^BOLD%^The outline of the carved tiger %^RESET%^sh%^BOLD%^%^WHITE%^i%^RESET%^mme"
"%^BOLD%^%^WHITE%^r%^RESET%^s %^BOLD%^%^WHITE%^as "+ETOQCN+" lashes out with newfound speed, stirring the air with "
"a quick second strike!%^RESET%^",ETO);
       return 1;
       break;

       case 300..399:
       tell_object(ETO,"%^BOLD%^%^BLACK%^You impact "+targ->QCN+" with your staff as the tortoise etching %^RESET%^"
"%^BLUE%^glows %^BOLD%^%^BLACK%^ominously, sending a chill through the weapon! "+targ->QCN+" seems to freeze up"
"!%^RESET%^");
       tell_object(targ,"%^BOLD%^%^BLACK%^"+ETO->QCN+" impacts you with "+ETO->QP+" staff as the tortoise etching "
"glows ominously, sending a chill through the weapon that freezes you to the bone!%^RESET%^");
       tell_room(EETO,"%^BOLD%^%^BLACK%^"+ETO->QCN+" impacts "+targ->QCN+" with "+ETO->QP+" staff as the tortoise "
"etching glows ominously, and "+targ->QCN+" seems to freeze in place!%^RESET%^",({ETO,targ}));
       targ->set_paralyzed((random(5)+20),"%^BOLD%^%^CYAN%^You're still trying to shake off the chill!%^RESET%^");
       return 1;
       break;
     }
   }
   return 1;
}