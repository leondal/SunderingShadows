#include <std.h>
inherit "/d/common/obj/lrweapon/longbow";

void create() {
    ::create();
    set_name("longbow");
    set_id(({"longbow","long bow","black bow","bow"}));
    set_short("%^RESET%^%^BLUE%^Black longbow%^RESET%^");
    set_long("%^BOLD%^%^BLUE%^This bow has been cut from a single length of %^BOLD%^%^BLACK%^jet"
"-black wood%^BOLD%^%^BLUE%^, and polished to a smooth finish.  The ends have been dipped in "
"some kind of %^RESET%^dark metal%^BOLD%^%^BLUE%^, perhaps steel, that has been given a non-"
"reflective coating so as not to give away the wielder to a flash of light.  Jagged "
"%^YELLOW%^markings %^BOLD%^%^BLUE%^have been etched down its length, their outlines unsettling "
"to look upon for too long.  A fine black cord of %^RESET%^spidersilk %^BOLD%^%^BLUE%^serves as "
"the bowstring, far stronger than its delicate appearance would suggest.%^RESET%^");
    set_lore("This is one of the longbows so favoured by the Drow archers of the Drow Regime. "
"It is crafted from wood taken from the warped trees of the Dark Forest.");
    set_value(700);
    set_item_bonus("stealth",1);
    set_property("enchantment",3);
    set_wield((: TO,"wieldme" :));
    set_lrhit((:TO,"extra_lrhit":));
}

int wieldme() {
   if((string)ETO->query_race() != "Drow" && (string)ETO->query_race() != "drow"){
      tell_object(ETO,"You feel a %^BOLD%^%^YELLOW%^shock%^RESET%^ run through your "
"body as you wield the bow!");
      ETO->do_damage("torso",roll_dice(2,6));
      ETO->add_attacker(TO);
      ETO->continue_attack();
      ETO->remove_attacker(TO);
    }
    return 1;
}

int extra_lrhit(object targ){
   if(!objectp(targ)) return 0;
   if(!objectp(ETO)) return 0;
   targ = ETO->query_current_attacker();
   if(!random(12)){
     tell_object(ETO,"%^BOLD%^%^BLACK%^The longbow's markings %^YELLOW%^crackle %^BOLD%^%^BLACK%^ominously "
"as you fire a shot.%^RESET%^");
     tell_object(targ,"%^BOLD%^%^BLACK%^The markings on "+ETOQCN+"'s longbow %^YELLOW%^crackle "
"%^BOLD%^%^BLACK%^ominously as "+ETO->QS+" fires a shot, and the arrow sinks into your flesh with a jolt of "
"%^BOLD%^%^RED%^pain%^BOLD%^%^BLACK%^!%^RESET%^");
     tell_room(EETO,"%^BOLD%^%^BLACK%^The markings on "+ETOQCN+"'s longbow %^YELLOW%^crackle "
"%^BOLD%^%^BLACK%^ominously as "+ETO->QS+" fires a shot at "+targ->QCN+"!%^RESET%^",({ETO,targ}));
     targ->do_damage(targ->return_target_limb(),random(6)+12);
     return 1;
   }
}
