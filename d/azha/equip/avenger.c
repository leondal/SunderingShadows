//  Holy avenger originally done by Thorn@shadowgate, 970316
// Updated 990908 by Amidon.
#include <std.h>
inherit WEAPON;

void create(){
  ::create();
  set_name("Holy Avenger");
  set_id(({"sword","two handed sword","holy avenger","avenger"}));
  set_short("%^CYAN%^Tsarvani Holy Avenger%^RESET%^");
  set_long(
  "%^CYAN%^"
  "  This is the feared weapon of the paladins of the Tsarvani Imperial Guard."
  "  There is no mistaking the artistry in the blade and the serene goodness that it eminates."
  "  Blessed by great deities of goodness, this blade serves as an extreme retribution upon the forces of evil in this realm."
  );
  set_weight(15);
  set_value(1000);
  set_wc(1,8);
  set_large_wc(1,12);
  set_size(2);
  set_type("slashing");
  set_prof_type("avengers");
  set_property("enchantment",2);
  set_hit((:TO,"extra_hit":));
  set_wield((:TO,"extra_wield":));
  set_unwield((:TO,"extra_unwield":));
}

int extra_hit(object ob){
    int dam;
    if(!objectp(ob)) return 1;
    if (((int)ob->query_alignment() % 3)==0){
        if((int)ob->query_alingment()==6){dam=8;}
        if((int)ob->query_alingment()==9){dam=10;}
        if((int)ob->query_alingment()==3){dam=6;}
        if(!random(2)){
            tell_object(ob,"%^CYAN%^The sword wielded by "+ETO->query_cap_name()+" glows as it cuts into your flesh!%^RESET%^");
            tell_object(ETO,"%^CYAN%^A bluish glow eminates from the blade as it cuts into the corrupt flesh of your enemy!%^RESET%^");
            tell_room(environment(ETO),"%^CYAN%^The sword wielded by "+ETO->query_cap_name()+" glows as it strikes "+ob->query_cap_name()+"!%^RESET%^",({ob,ETO}));
        }
        return dam;
    }
    return random(5)+1;
}

int extra_wield(){

    string wlimb, *wielder;

    if(!TP) return 0;
    if((int)TP->query_level()<25){
        tell_object(ETO,"You may not wield such a powerful weapon!");
        return 0;
    }
    if(query_property("enchantment") < 0) return 1;
    if(TP->is_class("paladin")){
        if (!TP->query_property("holy")){
            while(query_property("enchantment") != 5) {
            remove_property("enchantment");
            set_property("enchantment",5);
            }
            TP->set_property("magic resistance",50);
            ETO->set_property("holy",1);
        }
        write("%^CYAN%^The avenger blazes with holy power in your hands!%^RESET%^");
        say("%^CYAN%^You hear a chorus of angels as "+TPQCN+" wields the Holy Avenger!");
        return 1;
    }
    if(((int)TP->query_alignment() % 3) == 3){
        wielder = TP->query_wielding_limbs();
        rand_wlimb = wielder[random(sizeof(wielder))];
        TP->cause_typed_damage(TP, rand_wlimb, roll_dice(1, 10), "divine");
        write("%^CYAN%^The Avenger blazes with holy power in your evil hands and burns your corrupt flesh!%^RESET%^");
        say("%^CYAN%^You hear "+TPQCN+" scream in pain as the Holy Avenger falls to the ground and disappears!");
        TO->remove();
        return 0;
    }
    while(query_property("enchantment") != 2) {
        remove_property("enchantment");
        set_property("enchantment",2);
    }
    write("%^CYAN%^The sword glows with POWER in your hands!%^RESET%^");
    say("%^CYAN%^"+ETO->query_cap_name()+" wields the Holy Avenger.%^RESET%^");
    return 1;
}
int extra_unwield(){
    if(query_property("enchantment") < 0) return 0;
    while(query_property("enchantment") != 2) {
        remove_property("enchantment");
        set_property("enchantment",2);
    }
    if(ETO->query_property("holy")){
        ETO->set_property("magic resistance",-50);
        ETO->remove_property("holy");
    }
    return 1;
}
