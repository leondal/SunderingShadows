//updated by Circe 6/13/04 with new desc, lore, etc.
#include <std.h>

inherit "/d/common/obj/armour/shield.c";

void create() {
    ::create();
    set_name("aster shield");
    set_id(({"aster","aster shield","star shield","shield"}));
    set_obvious_short("a star-shaped shield");
    set_short("%^BOLD%^%^WHITE%^Aster Shield%^RESET%^");
    set_long(
       "%^BOLD%^This small shield is made of burnished steel "+
       "laid over a %^RESET%^%^ORANGE%^wooden base%^BOLD%^%^WHITE%^.  "+
       "The shield is %^CYAN%^star-shaped %^WHITE%^with six points, "+
       "between which run shallow grooves.  The shield is designed "+
       "to be twisted in combat, catching an opponent's weapon and "+
       "knocking him off balance.  Only the most experienced can "+
       "effectively use such a shield.%^RESET%^");
    set_lore("The aster shield is a unique creation fashioned "+
       "by one of the warring tribes on Attaya during the early "+
       "days.  At one time, the island was ruled by tribal nations "+
       "who were continually at war with one another.  The aster "+
       "shield was created to combat the excellent spear work of "+
       "a neighboring tribe.");
    set_weight(15);
    set_value(10000);
    set_limbs(({"right hand"}));
    set_ac(1);
    set_property("enchantment", 2);
    set_wear( (:TO, "extra_wear":));
    set_struck((:TO,"strikeme":));
}

int extra_wear(){
    int lvl;

    lvl = (int)TP->query_lowest_level();
   if(lvl < 20){
        tell_object(TP, "The shield refuses your hand!!");
        return 0;
    }
    return 1;
}

int strikeme(int damage, object what, object who){
        if(random(1000) < 200){
        tell_room(environment(query_worn()),"%^BOLD%^"+ETOQCN+" twists "+
           ""+ETO->QP+" shield as "+who->QCN+" strikes, catching "+
           "the weapon and pulling "+who->QO+" off balance!",({ETO,who}));
        tell_object(ETO,"%^BOLD%^You twist the shield as "+who->QCN+" "+
           "strikes at you, catching "+who->QP+" weapon and pulling "+
           ""+who->QO+" off balance!");
        tell_object(who,"%^BOLD%^"+ETOQCN+" twists "+
           ""+ETO->QP+" shield as you strike, catching "+
           "the weapon and pulling you off balance!");
        who->set_tripped(1,"You are regaining your balance!");
        return damage;
  }
}
