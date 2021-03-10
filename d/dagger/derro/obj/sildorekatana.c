#include <std.h>
inherit "/d/common/obj/weapon/katana.c";

void create(){
   ::create();
    set_short("%^BLUE%^Sildore's W%^BOLD%^%^BLACK%^a%^RESET%^"+
    "%^BLUE%^rr%^BOLD%^%^BLACK%^io%^RESET%^%^BLUE%^r B%^BOLD%^%^BLACK%^"+
    "a%^RESET%^%^BLUE%^n%^BOLD%^%^BLACK%^e%^RESET%^");
    set_obvious_short("An adamantium katana");

    set_long("%^BLUE%^The blade of this weapon is made from "+
    "a solid piece of adamantium.  The edge of the blade has been "+
    "sharpened to a razor point and somehow never manages to dull.  "+
    "The crosspiece that connects the blade to the hilt is made from two "+
    "bits of mithril that intertwine with one another and jut straight "+
    "outward from the weapon.  The hilt of the weapon is made from a "+
    "piece of iron that been engraved with several swords crossed "+
    "in front of a %^CYAN%^sta%^RESET%^%^BLUE%^rbu%^CYAN%^rst%^BLUE%^"+
    " pattern.  The weapon ends with a flattened adamantium pommel.%^RESET%^");
     
    set_lore("Created for the legendary firbolg fighter sildore, this "+
    "sword was thought lost and has been, for a long time, sought out "+
    "with great patience and eagerness.  Legend suggest that it aides "+
    "to the defense of the wielder and that the powerful magic that "+
    "forged it exerts itself in several ways during combat.  Those "+
    "same legends mention at least three mages as having been involved "+
    "with its creation.");

    set_value(2000);
    set_property("enchantment",3);
    set_ac(1);
    set_wield((:TO,"wield_me":));
    set_unwield("%^BLUE%^You release the weapon with a slight "+
    "hesitation and instantly feel more vunerable.%^RESET%^");
    set_hit((:TO,"hit_func":));
}

int wield_me() {
    tell_object(ETO,"%^CYAN%^A bright flash of light bursts forth "+
    "from the pattern on the hilt of your katana and you feel "+
    "guarded.%^RESET%^");
    tell_room(EETO,"%^CYAN%^A bright flash of light bursts forth "+
    "from the pattern on "+ETO->QCN+"%^CYAN%^'s katana!%^RESET%^",ETO);
    return 1;
}

int hit_func(object targ){
    string limb;
    if(random(1000) < 200){
        limb = targ->return_target_limb();
        switch(random(20)) {
            case 0..10:
            tell_room(EETO,ETO->QCN+"%^RED%^ strikes "+targ->QCN+"%^RED%^"+
            " with unnatural precision, cutting deep into "+targ->QP+
            " " +limb+"!%^RESET%^",({ETO,targ}));
            
            tell_object(targ,ETO->QCN+"%^RED%^ strikes you with unnatural "+
            "precision, cutting deep into your "+limb+"!%^RESET%^");
            
            tell_object(ETO,"%^RED%^You strike "+targ->QCN+"%^RED%^ "+
            "with unnatural precision, cutting deep into "+targ->QP+
            " " +limb+"!%^RESET%^");
            return targ->do_damage(limb,roll_dice(2,4));
            break;
            case 11..18:
            tell_room(EETO,ETO->QCN+"%^BOLD%^%^BLACK%^ attacks "+
            targ->QCN+"%^BOLD%^%^BLACK%^ with a sudden fury!"+
            "%^RESET%^",({ETO,targ}));
            
            tell_object(targ,ETO->QCN+"%^BOLD%^%^BLACK%^ furiously "+
            "slashes into your flesh!%^RESET%^");
            
            tell_object(ETO,"%^BOLD%^%^BLACK%^You furiously slash "+
            "into "+targ->QCN+"%^BOLD%^%^BLACK%^'s flesh!%^RESET%^");
            return targ->do_damage(limb,roll_dice(3,4));
            break;
            case 19:
            tell_room(EETO,ETO->QCN+"%^BLUE%^'s attack is suddenly "+
            "quickened!%^RESET%^",({targ,ETO}));
            tell_object(targ,ETO->QCN+"%^BLUE%^'s attack against you "+
            "is suddenly quickened!%^RESET%^");
            tell_object(ETO,"%^BLUE%^Your attack against "+targ->QCN+""+
            " is suddenly quickened as a warmth flows out from the "+
            "hilt of your katana, revitalizing you!%^RESET%^");
            ETO->do_damage("right hand",-(2 + random(7)));
            ETO->execute_attack();
            return 0;
            break;
        }
    }

}
