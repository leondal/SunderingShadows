#include <std.h>
inherit "/d/common/obj/weapon/claw.c";

void create() {
    ::create();
    set_name("leather knuckle-guard");
    set_id(({"knuckles","knuckle","knuckle guard","guard","knuckle-guard","burnished knuckle-guard","leather knuckle-guard","vajra mushti","Vajra Mushti"}));
    set_short("%^RESET%^%^ORANGE%^Vaj%^YELLOW%^r%^RESET%^%^ORANGE%^a Mu%^RED%^s%^ORANGE%^hti%^RESET%^");
    set_obvious_short("%^RESET%^%^ORANGE%^a %^RESET%^%^RED%^bu%^ORANGE%^rn%^YELLOW%^i%^RESET%^%^ORANGE%^sh%^RED%^ed %^ORANGE%^leather knuckle-guard%^RESET%^");
    set_long("%^CYAN%^This intriguing weapon seems based upon the standard %^ORANGE%^brass knuckles %^CYAN%^"
"commonly employed by rogues, and such fighters as prefer to do their talking with their fists. A framework of "
"%^BOLD%^%^BLACK%^ste%^RESET%^e%^BOLD%^%^BLACK%^l %^RESET%^%^CYAN%^forms loops to fit around each finger, "
"protecting them from harm while adding a %^RED%^pai%^MAGENTA%^nf%^RED%^ul %^CYAN%^touch to any punch "
"delivered by that hand. A second line of %^BOLD%^%^BLACK%^ste%^RESET%^e%^BOLD%^%^BLACK%^l %^RESET%^%^CYAN%^"
"has been fitted beneath the loops to form a grip for the hand, securing the knuckles in place so they don't "
"slip. Covering the back of this framework is a layer of %^RED%^bu%^ORANGE%^rn%^YELLOW%^i%^RESET%^%^ORANGE%^"
"sh%^RED%^ed %^CYAN%^leather the color of a terracotta pot, sliding through deep russet and ochre shades like "
"the very first hints of %^ORANGE%^d%^YELLOW%^a%^MAGENTA%^w%^RED%^n%^RESET%^%^CYAN%^. Burnt into the surface "
"of this covering is the image of a %^RED%^p%^BOLD%^h%^RESET%^%^RED%^oen%^BOLD%^i%^RESET%^%^RED%^x %^CYAN%^in "
"flight, its wings spread to show its magnificent plumage. The leather-covered metal surface with its narrow "
"design gives the weapon a look of none you have seen before, but you're sure it would give the capacity to "
"cause very specific damage to a target, without any fear of cuts or bleeding caused by the hard %^BOLD%^"
"%^BLACK%^ste%^RESET%^e%^BOLD%^%^BLACK%^l %^RESET%^%^CYAN%^layer beneath.\n%^RESET%^");
   set_value(0);
    while ((int)TO->query_property("enchantment") != 3) {
     TO->remove_property("enchantment");
     TO->set_property("enchantment",3);
   }
   set_item_bonus("armor bonus",1);
   set_lore("%^WHITE%^%^BOLD%^This weapon is one of a kind, crafted for the Lathanderite monk Timothy "
"following his successful attempt to free slaves from Tonovi during its civil war of 602SG. In the chaos, "
"more than a hundred slaves were brought to safety through the efforts of Timothy and his allies, some of "
"which were given refuge at the temple of Lathander following their escape. One such of these was Mikresh "
"Alhajtah, who was once a smith before his capture and containment within Tonovi. On behalf of those who "
"were freed from their imprisonment, and with the blessing of the temple's priests, he crafted this weapon "
"which was gifted in gratitude to Timothy for his efforts.\n\n%^BOLD%^%^WHITE%^The weapon itself is named in "
"the tongue of Mikresh's homeland. Mushti translates as a closed hand, or fist, while Vajra is a religious "
"symbol that translates along the lines of diamond or thunderbolt. This name in full would be known in his "
"lands as the 'diamond fist', or 'thunderbolt fist', which is the title of a style of martial arts that is "
"highly respected in that region. It is practiced by an order of religious monks who prize discipline and "
"skill over violence, and spend many years honing their self-defense abilities to protect their lands and "
"homes.%^RESET%^\n");
   set_property("lore difficulty",22);
   set_wield((:TO,"wield_fun":));
   set_unwield((:TO,"unwield_fun":));
   set_hit((:TO,"hit_fun":));
   set_overallStatus(220);
   set_property("no disenchant",1);
}

int wield_fun(){
    tell_object(ETO,"%^RESET%^%^ORANGE%^The image of the phoenix seems to %^BOLD%^%^WHITE%^spa%^YELLOW%^rk"
"%^WHITE%^le %^RESET%^%^ORANGE%^with life as you slip the guard over your fingers.%^RESET%^");
    tell_room(EETO,"%^RESET%^%^ORANGE%^The image of the phoenix seems to %^BOLD%^%^WHITE%^spa%^YELLOW%^rk"
"%^WHITE%^le %^RESET%^%^ORANGE%^with life as "+ETOQCN+" slips the guard over "+ETO->QP+
" fingers.%^RESET%^",ETO);
    return 1;
}

int unwield_fun() {
   tell_object(ETO,"%^RESET%^%^ORANGE%^You feel a twinge of regret to release the guard.%^RESET%^");
   tell_room(EETO,"%^RESET%^%^ORANGE%^"+ETOQCN+" looks relectant to release the guard.%^RESET%^",ETO);
   return 1;
}

int hit_fun(object targ) {
   targ = ETO->query_current_attacker();
   if(random(250)<40){
     switch(random(15)){
       case 0..8:
       tell_object(ETO,"%^WHITE%^%^BOLD%^Your knuckle guard flares on impact with a sudden burst of %^RED%^bri"
"%^YELLOW%^l%^RED%^lia%^RESET%^%^RED%^n%^BOLD%^t fl%^WHITE%^a%^RED%^me%^WHITE%^, leaving a seared wound on "
+targ->QCN+"'s skin!%^RESET%^");
       tell_object(targ,"%^WHITE%^%^BOLD%^"+ETOQCN+"'s knuckle guard flares on impact with a sudden burst of "
"%^RED%^bri%^YELLOW%^l%^RED%^lia%^RESET%^%^RED%^n%^BOLD%^t fl%^WHITE%^a%^RED%^me%^WHITE%^, leaving a seared "
"wound on your skin!%^RESET%^");
       tell_room(EETO,"%^WHITE%^%^BOLD%^"+ETOQCN+"'s knuckle guard flares on impact with a sudden burst of "
"%^RED%^bri%^YELLOW%^l%^RED%^lia%^RESET%^%^RED%^n%^BOLD%^t fl%^WHITE%^a%^RED%^me%^WHITE%^, leaving a seared "
"wound on "+targ->QCN+"'s skin!%^RESET%^",({ETO,targ}));
       return 2;
       break;

       case 9..12:
       tell_object(ETO,"%^WHITE%^%^BOLD%^A %^YELLOW%^rad%^WHITE%^ia%^YELLOW%^nt %^WHITE%^glow bursts forth "
"from your knuckle guard and envelopes your skin, leaving you feeling %^RESET%^%^GREEN%^re%^CYAN%^fr%^GREEN%^e"
"%^CYAN%^sh%^GREEN%^ed%^BOLD%^%^WHITE%^!%^RESET%^");
       tell_room(EETO,"%^WHITE%^%^BOLD%^A %^YELLOW%^rad%^WHITE%^ia%^YELLOW%^nt %^WHITE%^glow bursts forth from "
+ETOQCN+"'s knuckle guard and envelopes "+ETO->QP+" body, leaving him looking %^RESET%^%^GREEN%^in%^CYAN%^vi"
"%^GREEN%^gor%^CYAN%^at%^GREEN%^ed%^BOLD%^%^WHITE%^!%^RESET%^",ETO);
       ETO->cause_typed_damage(targ, targ->return_target_limb(), - roll_dice(1, 8) - 4, "positive energy");
       return 0;
       break;

       case 13..14:
       ETO->execute_attack();
       tell_object(ETO,"%^BOLD%^%^WHITE%^You gather an inner %^RESET%^%^CYAN%^ca%^GREEN%^l%^CYAN%^m%^BOLD%^"
"%^WHITE%^, using perfect discipline to strike rapidly at vulnerable points in "+targ->QCN+"'s "
"defenses!%^RESET%^");
       tell_object(targ,"%^BOLD%^%^WHITE%^"+ETOQCN+" takes on a countenance of absolute %^RESET%^%^CYAN%^ca"
"%^GREEN%^l%^CYAN%^m%^BOLD%^%^WHITE%^, as "+ETO->QP+" hands move almost of their own accord to strike rapidly "
"at vulnerable points in your defenses!%^RESET%^");
       tell_room(EETO,"%^BOLD%^%^WHITE%^"+ETOQCN+" takes on a countenance of absolute %^RESET%^%^CYAN%^ca"
"%^GREEN%^l%^CYAN%^m%^BOLD%^%^WHITE%^, as "+ETO->QP+" hands move almost of their own accord to strike rapidly "
"at vulnerable points in "+targ->QCN+"'s defenses!%^RESET%^",({ETO,targ}));
       return 1;
       break;
     }
   }
   return 1;
}