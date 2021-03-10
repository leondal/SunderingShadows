//updated by Circe 10/26/03 to use do_damage instead of heal
//updated by Circe 4/20/04 to current code, new desc, etc.
#include <std.h>
inherit "/d/common/obj/weapon/battle_axe.c";
void create() {
    ::create();
        set_name("fire axe");
        set_id(({"fire axe","axe","faxe","Axe","ax","fire"}));
        set_obvious_short("a strange serrated axe");
        set_short("%^RED%^Fire Axe%^RESET%^");
        set_long("%^RED%^This unique axe is formed unlike any "+
           "other.  A handle of %^BOLD%^%^BLACK%^ob%^WHITE%^si"+
           "%^BLACK%^di%^WHITE%^an %^RESET%^%^RED%^that curves "+
           "back and forth in a slight %^BOLD%^'%^RESET%^%^RED%^S"+
           "%^BOLD%^' %^RESET%^%^RED%^shape supports a fantastic "+
           "serrated blade unlike any other.  It looks to be a "+
           "%^BOLD%^stylized fl%^YELLOW%^a%^RED%^me %^RESET%^%^RED%^"+
           "burning with an %^YELLOW%^inner glow%^RESET%^%^RED%^.  "+
           "The material of the axehead is unknown, and it almost "+
           "seems to %^BOLD%^%^WHITE%^flicker %^RESET%^%^RED%^"+
           "as if made of %^BOLD%^fire %^RESET%^%^RED%^itself.");
     //set_weight(7);
        set_value(3500);
     //set_wc(1,8);
     //set_large_wc(1,12);
     //set_size(2);
     //set_type("slashing");
        set_property("enchantment",4);
        set_hit((:TO, "extra_hit":));
        set_wield((:TO, "extra_wield":));
     //set_prof_type("medium axe");
//        set_prof_level(18);  //what is this?
}
int extra_hit(object ob) {
    int dam,dam2;
   if(!objectp(ob)) return random(6);
    dam = random(6) + 1;
    dam2 = random(10)+4;
    if(random(5) > 0) return random(6);
    switch(random(12)){
       case 0..4:
          tell_object(ETO,"%^RED%^The axe sends its %^BOLD%^healing "+
             "burn %^RESET%^%^RED%^into you, stealing from your target.%^RESET%^");
          tell_room(EETO,"%^RED%^The axe wielded by "+ETOQCN+" %^BOLD%^glows "+
             "%^RESET%^%^RED%^as it cuts "+ob->QCN+"'s flesh!%^RESET%^",({ETO, ob}));
          tell_object(ob,"%^RED%^The axe wielded by "+ETOQCN+" %^BOLD%^"+
             "glows %^RESET%^%^RED%^as it cuts into your flesh!%^RESET%^");
          set_property("magic",1);
          ob->do_damage("torso",dam);
          ETO->do_damage("torso",-dam);
          set_property("magic",-1);
          break;
       case 5..6:
          tell_object(ETO,"%^BOLD%^You flip the axe in your hand, striking "+
             ""+ob->QCN+" stoutly as the axe suddenly %^YELLOW%^flares"+
             "%^WHITE%^!%^RESET%^");
          tell_room(EETO,"%^BOLD%^"+ETOQCN+" flips the axe in "+ETO->QP+" "+
             "hand and it %^YELLOW%^flares %^WHITE%^as it strikes "+
             ""+ob->QCN+"!%^RESET%^",({ETO, ob}));
          tell_object(ob,"%^BOLD%^The axe wielded by "+ETOQCN+" %^YELLOW%^"+
             "flares %^WHITE%^as "+ETO->QS+" flips it in "+ETO->QP+" "+
             "hand and strikes you soundly!%^RESET%^");
          set_property("magic",1);
          ob->do_damage("torso",dam2);
          ETO->do_damage("torso",-dam2);
          set_property("magic",-1);
          break;
       case 7:
          tell_object(ETO,"%^BOLD%^%^RED%^Your axe %^YELLOW%^crackles "+
             "%^RED%^as it strikes "+ob->QCN+", sending %^RESET%^%^RED%^"+
             "s%^ORANGE%^p%^BOLD%^%^RED%^a%^YELLOW%^r%^RED%^k%^RESET%^"+
             "%^ORANGE%^s %^BOLD%^%^RED%^into "+ob->QP+" eyes!%^RESET%^");
          tell_room(EETO,"%^RESET%^%^RED%^S%^ORANGE%^p%^BOLD%^%^RED%^a"+
             "%^YELLOW%^r%^RED%^k%^RESET%^%^ORANGE%^s %^BOLD%^%^RED%^"+
             "fly into "+ob->QCN+"'s eyes as "+ETOQCN+" strikes "+
             ""+ob->QO+" with the axe!%^RESET%^",({ETO, ob}));
          tell_object(ob,"%^RESET%^%^RED%^S%^ORANGE%^p%^BOLD%^%^RED%^a"+
             "%^YELLOW%^r%^RED%^k%^RESET%^%^ORANGE%^s %^BOLD%^%^RED%^"+
             "fly into your eyes from "+ETOQCN+"'s axe, blinding you!%^RESET%^");
          set_property("magic",1);
          ob->do_damage("torso",dam);
          ETO->do_damage("torso",-dam);
          set_property("magic",-1);
          ob->set_temporary_blinded(roll_dice(1,6));
          break;
       case 8..11:  break;
       default:  break;
    }
    return random(6);
}

int extra_wield() {
    if((int)ETO->query_lowest_level() < 30){
       tell_object(ETO,"%^BOLD%^%^RED%^The %^YELLOW%^heat "+
          "%^RED%^of the axe is too much for you to bear!");
       tell_room(EETO,"%^BOLD%^%^RED%^"+ETOQCN+" squeels and "+
          "drops the axe!",ETO);
       ETO->force_me("drop axe");
       return 0;
    }
    tell_object(ETO,"%^RED%^You wield the fire axe and it begins "+
       "to %^BOLD%^glow%^RESET%^%^RED%^, burning your hand!%^RESET%^");
    set_property("magic",1);
    ETO->do_damage("torso",random(10)+1);
    set_property("magic",-1);
    tell_room(EETO,"%^RED%^"+ETOQCN+" wields a %^BOLD%^glowing Axe.%^RESET%^",ETO);
    return 1;
}

