//Hijacked March 31, 2011 by Ergo for Squire's Trial
//updated by Circe 3/26/04
#include <std.h>
#include <daemons.h>
inherit "/d/common/obj/armour/hide.c";

void create() {
    ::create();
    set_name("demonskin");
    set_id(({"demonskin","hide","armor","skin","demon"}));
    set_obvious_short("Rough hide-like armor");
    set_short("%^RESET%^%^RED%^Demonskin armor%^RESET%^");
    set_lore("This armor has been crafted out of the rough, ruddy "+
       "hide of a greater demon.  The deep gray hue emphasizing the "+
       "the reddish color is a result of being on the plane of Shadow "+
       "for quite some time.  It is said that armor such as this is "+
       "inherently evil and should be destroyed.  Of course...it is only "+
       "the 'good of heart' who say such things.");
    set_long(
       "%^RED%^This rough hide armor is covered with tiny "+
       "%^BOLD%^%^BLACK%^barbs %^RESET%^%^RED%^that can slice "+
       "open skin as easily as any blade.  The demonskin wraps "+
       "itself closely around the wearer's body, bonding to it "+
       "perfectly.  The sleeves of the armor seem to blend in "+
       "with the wearer's own skin somewhere above the elbow, "+
       "doing the same around mid-thigh.  The armor gives the "+
       "wearer a frightening appearance, with the "+
       "reddish skin almost seeming to glisten.\n%^RESET%^"
    );
    set_size(2);
    set_value(3500);
    set_property("enchantment",2);
    set_item_bonus("sight bonus",1);
    set_wear((:TO,"wear_func":));
    set_remove((:TO,"removeme":));
    set_struck((:TO,"strikeme":));
}
int wear_func(string str){
   int bonus;
   int wearalign=ETO->query_alignment();
   if(wearalign==1||wearalign==4||wearalign==7||wearalign==2||wearalign==5||wearalign==8){
      tell_object(ETO,"%^BOLD%^%^RED%^The armor hisses and burns "+
         "your skin!");
      set_property("magic",1);
      ETO->do_damage("torso",random(20)+10);
      ETO->add_attacker(TO);
      ETO->continue_attack();
      ETO->remove_attacker(TO);
      remove_property("magic");
      return 0;
   }else{
   tell_object(ETO,"%^RED%^The demonskin wraps itself around you "+
      "as you hear a low cackle.%^RESET%^");
   tell_room(EETO,"%^RED%^"+ETOQCN+" wears a suit of "+
      "strange armor.%^RESET%^",ETO);
   ETO->set_property("evil item",1);
   return 1;
   }
}

int removeme() {
   int bonus;
   tell_object(ETO,"%^RED%^The demonskin reluctantly pulls "+
      "away from your skin with a malevolent hiss.");
   tell_room(EETO,"%^RED%^You almost think you hear a hiss "+
      "as "+ETOQCN+" pulls off "+ETO->QP+" armor.",ETO);
   ETO->set_property("evil item",-1);
   return 1;
}

int strikeme(int damage, object what, object who){
        if(random(1000) < 400){
        tell_room(environment(query_worn()),"%^BOLD%^%^RED%^"+ETOQCN+"'s red "+
           "armor drags across "+who->QCN+"'s skin, cutting "+who->QO+" deeply!",({ETO,who}));
        tell_object(ETO,"%^BOLD%^%^RED%^The demonskin seems to pull your arm "+
           "suddenly, raking across "+who->QCN+"'s skin!");
        tell_object(who,"%^BOLD%^%^RED%^"+ETOQCN+"'s reddish armor drags across "+
           "your skin, flensing you!");
        who->do_damage("torso",(random(20)+6));
        return damage;  }
}
