//updated by Circe 6/12/04 with new desc, lore, etc.
//updated by Circe to include new specials to put it in line with other weapons
#include <std.h>
inherit "/d/common/obj/weapon/hhlance";
//inherit "std/weapon";

void create() {
    ::create();
    set_name("Lightning Lance");
    set_id(({"lance","lightning","lightning lance","heavy lance"}));
    set_obvious_short("%^YELLOW%^heavy gold-plated lance%^RESET%^");
    set_short("%^BOLD%^%^YELLOW%^Lightning Lance%^RESET%^");
    set_long(
       "%^BOLD%^This beautifully crafted lance has been plated with "+
       "%^YELLOW%^gold%^WHITE%^.  Deep carvings in the shape of "+
       "%^YELLOW%^lightning bolts %^WHITE%^run full-length along the "+
       "lance and reveal the heavy steel beneath.  Unlike most lances, "+
       "this one does not end in a simple steel tip.  Rather, it has "+
       "been fitted with a %^YELLOW%^jagged tip %^WHITE%^made to look "+
       "like a stylized lightning bolt that would leave quite a tear "+
       "in an opponent.  The handle of the lance is made of %^YELLOW%^"+
       "oak %^WHITE%^painted the %^BLUE%^deep blue of the sky %^WHITE%^"+
       "and fitted with a ring of cabochon-cut %^RESET%^white "+
       "citrine%^BOLD%^ gems.%^RESET%^");
    set_lore("This lightning lance is a conduit of a good god's power. "+
       "Made specifically for the knights of the good orders, it can +"
       "potentially call upon the power of the gods themselves.  The "+
       "lance is enchanted during a collaborative ceremony of priests of "+
       "at least three good faiths, who each request the blessings "+
       "of their god for this unique lance.  The white citrine is said "+
       "to clear the mind and aid the prayers of mortals to their "+
       "deities.");
//    set_weight(15);
    set_value(1500);
//    set_wc(1,12);
//    set_large_wc(1,21);
    set_property("enchantment",3);
//    set_size(1);
//    set_type("piercing");
//    set_prof_type("lance");
//    set_property("lance",1);
    set_wield((:TO,"wield":));
    set_unwield((:TO,"removeme":));
    set_hit((:TO,"check":));
}

int wield() {
   if((int)TP->query_alignment()%3){
        ETO->set_property("good item",1);
        tell_room(EETO,"%^CYAN%^A low humming fills the air as "+ETOQCN+" wields "+ETO->QP+" lance.%^RESET%^",ETO);
        tell_object(ETO,"%^CYAN%^A low humming fills the air as you wield your lance.%^RESET%^");
        return 1;
    }
    write("You are thoroughly rejected by this item.");
    return 0;
}
int removeme() {
    ETO->set_property("good item",-1);
    return 1;
}

int check(object targ){
   string deity;
   ::check(targ);
   if(!objectp(ETO)) return 0;
   if(!objectp(targ)) return 0;
   
   deity = ETO->query_diety();
   if(!deity || deity == "pan" || deity == "Pan"){ deity = "the heavens"; }
   deity = capitalize(deity);

   if(!random(6)){
      switch(random(6)){
         case 0..3:
            tell_room(environment(targ),"%^BOLD%^%^WHITE%^A bolt of pure %^YELLOW%^power "
               "%^WHITE%^shoots from "+ETOQCN+"'s lance as %^CYAN%^chimes "
               "%^WHITE%^ring overhead!%^RESET%^",ETO);
            tell_object(ETO,"%^BOLD%^%^WHITE%^A bolt of pure %^YELLOW%^power "
               "%^WHITE%^shoots from your lance as %^CYAN%^chimes "
               "%^WHITE%^ring overhead!%^RESET%^");
            return random(7);
            break;
         case 4:
            tell_room(environment(targ),"%^YELLOW%^"+ETOQCN+" raises "+ETO->QP+" "
               "lance straight overhead and the metal %^WHITE%^glows %^YELLOW%^as "
               "%^CYAN%^energy %^YELLOW%^gathers.  Lowering the lance, "+ETOQCN+" "
               "calls out to "+deity+" and surges forward, attacking so swiftly "
               ""+ETO->QS+" blurs!%^RESET%^",ETO);
            tell_object(ETO,"%^YELLOW%^Your raise your "
               "lance straight overhead and the metal %^WHITE%^glows %^YELLOW%^as "
               "%^CYAN%^energy %^YELLOW%^gathers.  Lowering the lance, you "
               "call out to "+deity+" and surge forward, attacking so swiftly "
               "everyone else seems to be standing still!%^RESET%^");
               ETO->execute_attack();
            break;
         default:
            tell_room(environment(targ),"%^RESET%^%^CYAN%^The lance wielded by "
               ""+ETOQCN+" %^BOLD%^glows %^RESET%^%^CYAN%^as "+ETO->QS+" strikes "
               ""+targ->QCN+", leaving "+targ->QO+" looking drained!%^RESET%^",({targ,ETO}));
            tell_object(targ,"%^RESET%^%^CYAN%^The lance wielded by "
               ""+ETOQCN+" %^BOLD%^glows %^RESET%^%^CYAN%^as "+ETO->QS+" strikes "
               "you, leaving you feeling drained!%^RESET%^");
            tell_object(ETO,"%^RESET%^%^CYAN%^You feel the might of "+deity+" as you "
               "strike "+targ->QCN+" and some of "+targ->QP+" %^BOLD%^life force "
               "%^RESET%^%^CYAN%^flows into you!%^RESET%^");
            set_property("magic",1);
            targ->do_damage("torso",roll_dice(2,12));
            ETO->do_damage("torso",(-1)*(roll_dice(4,12)));
		remove_property("magic");
            break;
      }
   }
   return 0;
}


int query_size() {
    if(objectp(ETO)&&living(ETO))
        return(int)ETO->query_size()  ;
    return ::query_size();
}
