//updated by Circe 4/16/04 to current code, desc, etc.
#include <std.h>
inherit "/d/common/obj/weapon/dagger.c";
create() {
    ::create();
     set_id(({"dagger","barbed","black barbed dagger","barbed dagger"}));
     set_name("Black Barbed Dagger");
     set_obvious_short("%^BOLD%^%^BLACK%^a blackened dagger%^RESET%^");
     set_short("%^BOLD%^%^BLACK%^Black Barbed Dagger%^RESET%^");
     set_long("%^RESET%^%^BLUE%^The long blackened blade of this dagger "+
        "is unlike any other.  Looking at it from the tip, it looks "+
        "like a %^BOLD%^%^BLACK%^four-pointed star%^RESET%^%^BLUE%^"+
        ", with each edge covered in small %^BOLD%^%^RED%^jagged "+
        "barbs %^RESET%^%^BLUE%^that would rip %^MAGENTA%^flesh "+
        "%^BLUE%^right from the %^BOLD%^%^WHITE%^bone%^RESET%^%^BLUE%^.  "+
        "The barbs run from tip to hilt, each about a half inch in "+
        "length and %^RESET%^razor-sharp%^BLUE%^.  The blade itself "+
        "is about a foot and a half long, rather long for a dagger, "+
        "and ends in a cruel %^BOLD%^%^WHITE%^ivory hilt%^RESET%^"+
        "%^BLUE%^.  The %^RESET%^hilt %^BLUE%^is ornately carved "+
        "in the perverse likeness of a %^YELLOW%^celestial %^RESET%^"+
        "%^BLUE%^in %^BOLD%^%^WHITE%^prayer%^RESET%^%^BLUE%^.  Its "+
        "%^RESET%^wings %^BLUE%^are outspread, forming the crossbar "+
        "of the blade, and its kneeling feet form the pommel.  The "+
        "image has been twisted and darkened into a %^BOLD%^%^BLACK%^"+
        "mocking debasement %^RESET%^%^BLUE%^of the %^RESET%^"+
         "holy creature%^BLUE%^.%^RESET%^");
     set_lore("These unusual daggers are said to be forged "+
        "within the bowels of the castle on Dallyh.  None "+
        "outside knows the method of creation, though cheap "+
        "imitations have been made.  The true barbed dagger "+
        "is said to reach its full potential in the hands of "+
        "assassins.  The daggers seem to hold a mystical power, "+
        "and indeed it is said that the hilt is carved from the "+
        "bone of a celestial's wing.");
     set_value(1350);
     set_prof_type("barbed dagger");
     set_type("slashing");
     set_property("enchantment",6);
     set_hit((:TO, "extra_hit":) );
     set_wield((:TO, "extra_wield":));
     set_unwield((:TO,"removeme":));
}

int extra_wield() {
    if(ALIGN->is_good(ETO)) {
       tell_object(ETO,"%^BLUE%^The evil of the dagger burns "+
          "your hand!");
       tell_room(EETO,"%^BLUE%^"+ETOQCN+" jerks "+ETO->QP+" hand "+
          "away as the dagger seems to burn it!",ETO);
       ETO->do_damage("torso",roll_dice(2,6));
       ETO->add_attacker(TO);
       ETO->continue_attack();
       ETO->remove_attacker(TO);
       return 0;
    }
    if(ETO->query_property("good item")){
       tell_object(ETO,"The dagger refuses your hand while "+
          "you are wielding such goodly items!");
       return 0;
    }
    if((ETO->query_level() < 45)){
        tell_object(ETO,"%^RESET%^%^BLUE%^You aren't yet "+
           "skilled enough to use such a weapon.");
        return 0;
    }
    if(!ETO->query_property("assassin") && !ETO->is_class("assassin") && !ETO->query("is_assassin")){
       tell_object(ETO,"%^RESET%^%^BLUE%^You accidentally scrape your "+
          "hand across the barbs, slicing your hand!");
       tell_room(EETO,"%^BLUE%^"+ETOQCN+" curses as "+ETO->QS+" slices "+
          ""+ETO->QP+" hand on the dagger.",ETO);
       ETO->do_damage("torso",roll_dice(2,6));
       ETO->add_attacker(TO);
       ETO->continue_attack();
       ETO->remove_attacker(TO);
       ETO->set_property("evil item",1);
       return 1;
    }
    tell_object(ETO,"%^BLUE%^You warily reach for the "+
       "blade, carefully avoiding the barbs.");
    tell_room(EETO,"%^BLUE%^"+ETOQCN+" tentatively reaches "+
       "for the blade, feeling the barbs with "+ETO->QP+" "+
       "fingers.",ETO);
     return 1;
}

int removeme()
{
    if(!ETO->query_property("assassin") && !ETO->is_class("assassin") && !ETO->query("is_assassin")){
       tell_object(ETO,"%^BLUE%^You curse as you nearly slit "+
          "your hand again on the blasted dagger.");
       tell_room(EETO,"%^BLUE%^"+ETOQCN+" curses and jerks "+
          ""+ETO->QP+" hand away from the dagger quickly.",ETO);
       ETO->set_property("evil item",-1);
       return 1;
    }
    tell_object(ETO,"%^BLUE%^You hold back a smile as you "+
       "release the blade, remembering all those fools who "+
       "cut themselves on this damn thing.");
    tell_room(EETO,"%^BLUE%^"+ETOQCN+" smirks as "+ETO->QS+" "+
       "expertly sheaths the blade.",ETO);
    ETO->set_property("evil item",-1);
    return 1;
}

int extra_hit(object ob)  {
    object obj;
    if(!objectp(ob)) return 1;
    if(!random(8)){
       switch(random(50)){
          case 0..20:  tell_object(ETO,"%^BLUE%^You %^RED%^stab "+
                      "%^BLUE%^the dagger deep into "+ob->QCN+", "+
                      "leaving a vicious star-like wound "+
                      "as you %^RED%^rip %^BLUE%^the %^WHITE%^"+
                      "flesh%^BLUE%^!");
                      tell_object(ob,"%^BLUE%^You gasp for breath "+
                      "as you feel your %^RED%^tendons %^BLUE%^and "+
                      "%^WHITE%^tissue %^BLUE%^ripped from your "+
                      "body on "+ETOQCN+"'s dagger!");
                      tell_room(EETO,"%^BLUE%^"+ETOQCN+" %^RED%^rips "+
                      "%^BLUE%^"+ETO->QP+" dagger from "+ob->QCN+"'s "+
                      "%^WHITE%^flesh%^BLUE%^, leaving a gruesome "+
                      "star-shaped %^RED%^wound%^BLUE%^!",({ETO,ob}));
                      set_property("magic",1);
                      ob->do_damage("torso",15+random(15));
                      remove_property("magic");
                      break;
          case 21..35:  tell_object(ETO,"%^RED%^With a smirk, you "+
                      "%^BOLD%^slash %^RESET%^%^RED%^the barbed "+
                      "dagger across "+ob->QCN+"'s face, sending "+
                      "%^BOLD%^blood %^RESET%^%^RED%^everywhere!");
                      tell_object(ob,"%^RED%^With a smirk, "+ETOQCN+" "+
                      "%^BOLD%^slashes %^RESET%^%^RED%^the barbed "+
                      "dagger across your face, sending "+
                      "%^BOLD%^blood %^RESET%^%^RED%^everywhere!");
                      tell_room(EETO,"%^RED%^With a smirk, "+ETOQCN+" "+
                      "%^BOLD%^slashes %^RESET%^%^RED%^the barbed "+
                      "dagger across "+ob->QCN+"'s face, sending "+
                      "%^BOLD%^blood %^RESET%^%^RED%^everywhere!",({ETO,ob}));
                      set_property("magic",1);
                      ob->do_damage("torso",15+random(20));
                      remove_property("magic");
                      break;
          case 36..40:  tell_object(ETO,"%^BOLD%^%^BLUE%^As you twist "+
                      "the dagger, you feel a %^RED%^barb %^BLUE%^"+
                      "break off into "+ob->QCN+"'s wound!");
                      tell_object(ob,"%^BOLD%^BLUE%^With horror, you "+
                      "feel a %^RED%^barb %^BLUE%^break off of "+
                      ""+ETOQCN+"'s dagger, working its way into "+
                      "your %^RED%^wound%^BLUE%^!");
                      tell_room(EETO,"%^BOLD%^%^BLUE%^"+ETOQCN+" smiles "+
                      "coldly as a %^RED%^barb %^BLUE%^breaks off "+
                      ""+ETO->QP+" dagger and works its way into "+
                      ""+ob->QCN+"'s wound!",({ETO,ob}));
                      set_property("magic",1);
                      ob->do_damage("torso",roll_dice(2,4));
                      remove_property("magic");
                      obj = new("/d/islands/dallyh/marsh/obj/smallbarb");
                      obj->move(ob);
                      obj->hurt(ob);
                      break;
          case 41..49:     tell_object(ETO,"%^BOLD%^%^BLACK%^You see "+
                      ""+ob->QCN+"'s face twist in %^RED%^agony "+
                      "%^BLACK%^as one of the barbs strikes a nerve!");
                      tell_object(ob,"%^BOLD%^%^BLACK%^Your body "+
                      "freezes as "+ETOQCN+"'s dagger strikes a "+
                      "nerve, setting your "+
                      "senses %^RED%^aflame%^BLACK%^!");
                      tell_room(EETO,"%^BOLD%^%^BLACK%^"+ETOQCN+"'s "+
                      "dagger %^RED%^rips %^BLACK%^"+ob->QCN+"'s "+
                      "flesh, paralyzing him!",({ETO,ob}));
                      set_property("magic",1);
                      ob->do_damage("torso",roll_dice(2,6));
                      remove_property("magic");
                      ob->set_paralyzed(2,"Your nerves are paralyzed from the blow!");
                      break;
          default:    break;
       }
    if((ETO->is_class("thief") || ETO->is_class("assassin")) && sizeof(ETO->query_classes()) ==1)
    return roll_dice(2,4);
    else return roll_dice(1,3);
    }
    return random(3)+2;
}
