//ethereal_bracers - for Lothwaite, coded by Circe 7/6/04
//changed the strike function from 6 out of 10 times to 1 out of 10 times after being told several times that these are //near the best in the game.   I do not agree that this should be true for bracers found in an area designed for mid //20's - Tsera
#include <std.h>
#include <daemons.h>

#define GEMS ({"%^BOLD%^%^BLACK%^on%^WHITE%^y%^BLACK%^x","%^RESET%^%^RED%^ga%^BOLD%^r%^RESET%^%^RED%^net","%^BOLD%^%^BLACK%^smoky quartz","%^BOLD%^%^GREEN%^em%^WHITE%^e%^GREEN%^rald","%^BOLD%^%^BLUE%^sa%^CYAN%^p%^BLUE%^ph%^CYAN%^i%^BLUE%^re","%^RESET%^%^GREEN%^be%^BOLD%^%^BLACK%^r%^RESET%^%^GREEN%^yl"}) 

inherit "/d/common/obj/armour/bracers";

void create(){
   int i;
   string GEM;
    ::create();
    i = random(sizeof(GEMS));
    GEM = GEMS[i];
    set_name("Ethereal Bracers");
    set_id(({ "bracers", "bracer", "ethereal bracers",
       "ethereal bracer","glassteel bracers"}));
    set_short("%^RESET%^%^CYAN%^E%^BOLD%^t%^RESET%^%^CYAN%^h%^BOLD%^e"+
       "%^RESET%^%^CYAN%^r%^BOLD%^e%^RESET%^%^CYAN%^a%^BOLD%^l "+
       "Bracers%^RESET%^");
    set_obvious_short("%^RESET%^%^CYAN%^glassteel bracers%^RESET%^");
    set_long("%^RESET%^%^CYAN%^Fashioned of the strange substance "+
       "known as %^BOLD%^glassteel%^RESET%^%^CYAN%^, these bracers "+
       "are nearly transparent though they seem to have the strength "+
       "of %^RESET%^tempered steel%^CYAN%^.  A light ribbon of "+
       "thin "+GEM+" %^RESET%^%^CYAN%^swirls beneath the surface, seemingly "+
       "in perpetual motion.  The bracers are hinged along the "+
       "length to allow them to be worn easily, but both hinge and "+
       "joint disappear when they are fastened.  At times, it seems "+
       "the bracers become %^BOLD%^%^WHITE%^insubstantial %^RESET%^"+
       "%^CYAN%^before winking into existence again.%^RESET%^");
    set_lore("These bracers were once normal bracers made from "+GEM+""+
       "%^RESET%^.  However, it seems the touch of the ghost has "+
       "affected them somehow, making them not entirely of this plane.  "+
       "Studying the bracers, you realize that they would probably "+
       "occasionally fade into the ethereal plane, though whether "+
       "or not they return - and whether or not they take the wearer - "+
       "is unclear.");
    set_property("lore difficulty",15);
    set_weight(8);
    set_value(1000);
    set_size(2);
    set_property("enchantment",3);
    set_item_bonus("magic resistance",1);
    set_remove((:TO,"remove_func":));
    set_wear( (:TO,"check":) );
    set_struck((:TO,"strike_func":));
}

int check(){
   int level;
   if((string)ETO->query_name() == "firbolg ghost") return 1;
   ::check();
   if(objectp(ETO) && ETO->query_property("no bracers")){    
       tell_object(ETO,"You are currently using an object that "+
          "cannot be worn with bracers.");
       return 0;
   }
   if((int)ETO->query_lowest_level() < 18){
      tell_object(ETO,"The power of the bracers is too great for you!");
      return 0;
   }
      tell_object(ETO,"%^CYAN%^The bracers seem to pulse in and out of "+
         "existence as you settle them on your forearms.");
      tell_room(EETO,"%^CYAN%^"+ETOQCN+"'s bracers seem more "+
         "insubstantial as they settle on "+ETO->QP+" forearms.",ETO);
      return 1;
}

int remove_func(){
    if(!ETO->query_invis()) {
        tell_room(EETO,"%^CYAN%^"+ETOQCN+"'s bracer seem to solidify "+
           "as "+ETO->QS+" removes them.",ETO);
    }
    tell_object(ETO,"%^CYAN%^You feel the bracers solidify as you "+
      "remove them.");
    return 1;
}

int strike_func(int damage, object what, object who){
        if(random(1000) < 100){
        tell_room(environment(query_worn()),"%^BOLD%^%^BLUE%^"+
            ""+ETOQCN+"'s bracers %^B_BLUE%^%^FLASH%^"+
            "%^BOLD%^%^CYAN%^flash%^RESET%^%^BOLD%^%^BLUE%^ as "+
            ""+who->QCN+" strikes them, and "+ETO->QS+" seems to fade "+
            "for a moment!",({ETO,who}));
        tell_object(ETO,"%^BOLD%^%^BLUE%^Your bracers %^B_BLUE%^%^FLASH%^"+
            "%^BOLD%^%^CYAN%^flash%^RESET%^%^BOLD%^%^BLUE%^ as "+
            ""+who->QCN+" strikes them, and you feel yourself blink "+
            "out of existence for a moment!");
        tell_object(who,"%^BOLD%^%^BLUE%^"+ETOQCN+"'s bracers %^B_BLUE%^"+
            "%^BOLD%^%^CYAN%^%^FLASH%^flash%^RESET%^%^BOLD%^%^BLUE%^ as "+
            "you strike them, and "+ETO->QS+" seems to fade for a moment!");
        return (damage*-1);
 }
}
