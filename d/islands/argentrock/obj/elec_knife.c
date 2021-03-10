//Longknife of Thunderstorms -- Yves

#include <std.h>
#include "../argabbr.h"
inherit THROWING_WEAPON;

void create(){
    ::create();
    set_name("%^YELLOW%^e%^BLACK%^le%^RESET%^%^WHITE%^c%^YELLOW%^tr%^RESET%^%^WHITE%^i%^YELLOW%^f%^BLACK%^ie%^YELLOW%^d longknife%^RESET%^");
    set_short("%^YELLOW%^Longknife of T%^BLACK%^hu%^RESET%^%^WHITE%^n%^YELLOW%^de%^RESET%^%^WHITE%^r%^YELLOW%^s%^BLACK%^to%^YELLOW%^r%^RESET%^%^WHITE%^m%^YELLOW%^s%^RESET%^");
    set_obvious_short("%^YELLOW%^An e%^BLACK%^le%^RESET%^%^WHITE%^c%^YELLOW%^tr%^RESET%^%^WHITE%^i%^YELLOW%^f%^BLACK%^ie%^YELLOW%^d longknife%^RESET%^");
    set_id(({
        "longknife of thunderstorms",
        "Longknife of Thunderstorms",
        "knife",
        "electrified longknife",
        "longknife",
        "dagger"
    }));
    set_long(
        "%^YELLOW%^This blade is oversized and long for a normal knife, and "
        "probably a bit awkward to fight with if you are not used to "
        "it. It is thin and %^CYAN%^aerodynamic%^YELLOW%^ however and would make "
        "for an excellent %^WHITE%^thrown%^YELLOW%^ weapon. Strange yellow %^MAGENTA%^runes%^YELLOW%^ run along "
        "the hilt of the finely crafed longknife, they %^WHITE%^glow and pulsate%^YELLOW%^ "
        "every few seconds sending e%^BLACK%^le%^RESET%^%^WHITE%^c%^YELLOW%^tr%^RESET%^%^WHITE%^i%^YELLOW%^c%^BLACK%^a%^YELLOW%^l currents streaking along "
        "the blade.%^RESET%^\n"
    );
    set_lore(
        "%^YELLOW%^This is a Longknife of T%^BLACK%^hu%^RESET%^%^WHITE%^n%^YELLOW%^de%^RESET%^%^WHITE%^r%^YELLOW%^s%^BLACK%^to%^YELLOW%^r%^RESET%^%^WHITE%^m%^YELLOW%^s%^RESET%^ crafted by the "
        "%^RESET%^%^CYAN%^elven%^YELLOW%^ artisans of the island of %^RESET%^%^GREEN%^Argentrock%^YELLOW%^. The %^RESET%^%^CYAN%^elves%^YELLOW%^ began "
        "crafting these longknives after they had been driven into the "
        "%^RESET%^%^ORANGE%^trees%^YELLOW%^ by the demonic %^MAGENTA%^Fey'ri%^YELLOW%^ that now inhabit Argentrock. It "
        "is a formidable weapon in close combat when necessary, "
        "but its true %^WHITE%^power%^YELLOW%^ lies in an accurate %^WHITE%^<throw>%^YELLOW%^ to the head of "
        "an opponent, preferably from a safe distance and concealed "
        "under %^RESET%^%^GREEN%^cover%^YELLOW%^. It is rumored that a direct blow to the face may "
        "even cause temporary %^WHITE%^blindness%^YELLOW%^.%^RESET%^"
    );
    set_property("lore",30);
    set_property("enchantment",4);
    set_hit((:TO, "hitme":));
    set_value(2000);
    set_wield((:TO,"wield_func":));
    set_unwield((:TO,"unwield_func":));
    set_weight(3);
    set_wc(1,3);
    set_large_wc(1,2);
    set_large_thrown_wc(1,4);
    set_thrown_wc(1,6);
    set_thrown_hit_func((:TO,"throwme":));
    set_type("piercing");
    set_prof_type("small blades");
    set_size(1);
    set_property("repairtype",({"woodwork", "weaponsmith"}));
}


void start_reset(object thrower) {
    if(find_call_out("thrown_reset") == -1 && objectp(thrower)) {
        call_out("thrown_reset",10,thrower);
    }
}

void thrown_reset(object thrower){
    if(!objectp(thrower) || !objectp(TO)) {return;}
    if(thrower->query_property("thrown")){
        thrower->remove_property("thrown");
    }
}

int wield_func(string str) {
    if((int)ETO->query_level() < 27) {
        tell_object(ETO,
            "%^YELLOW%^You try and wield the %^WHITE%^power%^YELLOW%^ of the e%^BLACK%^le%^RESET%^%^WHITE%^c%^YELLOW%^tr%^RESET%^%^WHITE%^i%^YELLOW%^f%^BLACK%^ie%^YELLOW%^d longknife "
            "but your energies don't align quite right and it %^RED%^BURNS%^YELLOW%^!%^RESET%^"
        );
        ETO->do_damage("torso",random(10)+5);
        return 0;
    }
    if(ETO->query_property("thrown")){
        tell_object(ETO,
            "%^BOLD%^%^BLACK%^Your body is still attuned with the other longknife for now!%^RESET%^\n"
        );
        start_reset(ETO);
        return 0;
    }
    tell_object(ETO,
        "%^YELLOW%^E%^BLACK%^le%^RESET%^%^WHITE%^c%^YELLOW%^tr%^RESET%^%^WHITE%^i%^YELLOW%^c%^BLACK%^a%^YELLOW%^l energy crackles and surges along the blade of the "
        "%^YELLOW%^e%^BLACK%^le%^RESET%^%^WHITE%^c%^YELLOW%^tr%^RESET%^%^WHITE%^i%^YELLOW%^f%^BLACK%^ie%^YELLOW%^d longknife and up your arm as you wield it, "
        "seemingly aligning itself with your natural %^WHITE%^energy%^YELLOW%^.%^RESET%^"
    );
    tell_room(environment(ETO),
        "%^YELLOW%^E%^BLACK%^le%^RESET%^%^WHITE%^c%^YELLOW%^tr%^RESET%^%^WHITE%^i%^YELLOW%^c%^BLACK%^a%^YELLOW%^l energy crackles and surges along the blade of "
        +ETOQCN+"'s longknife as "+ETO->QS+" wields it.%^RESET%^",ETO
    );
    return 1;
}

int unwield_func(string str) {
    tell_object(ETO,
        "%^YELLOW%^You let go of the e%^BLACK%^le%^RESET%^%^WHITE%^c%^YELLOW%^tr%^RESET%^%^WHITE%^i%^YELLOW%^f%^BLACK%^ie%^YELLOW%^d longknife and feel the %^WHITE%^tingle%^YELLOW%^ "
        "leave your body.%^RESET%^"
    );
    tell_room(environment(ETO),
        "%^YELLOW%^"+ETOQCN+" unwields the e%^BLACK%^le%^RESET%^%^WHITE%^c%^YELLOW%^tr%^RESET%^%^WHITE%^i%^YELLOW%^f%^BLACK%^ie%^YELLOW%^d longknife and "+ETO->QP+
        " hair stops %^CYAN%^standing%^YELLOW%^ on end.%^RESET%^",ETO
    );
    return 1;
}

int hitme(object targ){
    if(!objectp(TO)) return 1;
    if(!objectp(ETO)) return 1;
    if(!objectp(targ)) return 1;
    if(random(1000) < 300){
      switch(random(36)){
        case 0..26:
          tell_room(environment(ETO),
            "%^BOLD%^%^RED%^"+ETOQCN+"'s %^YELLOW%^e%^BLACK%^le%^RESET%^%^WHITE%^c%^YELLOW%^tr%^RESET%^%^WHITE%^i%^YELLOW%^f%^BLACK%^ie%^YELLOW%^d%^RED%^ longknife %^BLACK%^s%^RED%^e%^BLACK%^a%^RED%^rs "+targ->QCN+"'s "
            "skin as "+targ->QS+" is struck, leaving the sweet aroma of "
            "%^BLACK%^burning%^RED%^ flesh lingering in the %^CYAN%^air%^RED%^.%^RESET%^",({ETO,targ})
          );
          tell_object(ETO,
            "%^BOLD%^%^RED%^"+targ->QCN+"'s skin is %^BLACK%^s%^RED%^e%^BLACK%^ar%^RED%^ed badly, and leaves the sweet "
            "smell of %^BLACK%^burning%^RED%^ flesh lingering in the %^CYAN%^air%^RED%^ when you cut "
            "through it with your %^YELLOW%^e%^BLACK%^le%^RESET%^%^WHITE%^c%^YELLOW%^tr%^RESET%^%^WHITE%^i%^YELLOW%^f%^BLACK%^ie%^YELLOW%^d%^RED%^ longknife.%^RESET%^"
          );
          tell_object(targ,
            "%^BOLD%^%^RED%^Your skin is severely %^BLACK%^burned%^RED%^ when you are cut by "
            +ETOQCN+"'s %^YELLOW%^e%^BLACK%^le%^RESET%^%^WHITE%^c%^YELLOW%^tr%^RESET%^%^WHITE%^i%^YELLOW%^f%^BLACK%^ie%^YELLOW%^d%^RED%^ longknife, it leaves the sweet "
            "smell of your %^BLACK%^s%^RED%^e%^BLACK%^ar%^RED%^ed flesh lingering in the %^CYAN%^air%^RED%^.%^RESET%^"
          );
          set_property("magic",1);
          targ->do_damage("torso",random(10)+5);
          set_property("magic", -1);
          break;
        case 27..31:
          tell_room(environment(ETO),
            "%^YELLOW%^E%^BLACK%^le%^RESET%^%^WHITE%^c%^YELLOW%^tr%^RESET%^%^WHITE%^i%^YELLOW%^c%^BLACK%^a%^YELLOW%^l energy crackles and surges along the blade of "
            +ETOQCN+"'s longknife and %^CYAN%^gathers%^YELLOW%^ at the tip momentarily.%^RESET%^",ETO
          );
          tell_object(ETO,
            "%^YELLOW%^E%^BLACK%^le%^RESET%^%^WHITE%^c%^YELLOW%^tr%^RESET%^%^WHITE%^i%^YELLOW%^c%^BLACK%^a%^YELLOW%^l energy crackles and surges along the blade of "
            "your longknife and %^CYAN%^gathers%^YELLOW%^ at the tip momentarily.%^RESET%^"
          );
          new("/cmds/spells/l/_lightning_bolt")->use_spell(ETO,targ,15,100);
          break;
        case 32..35:
          tell_room(environment(ETO),
            "%^BOLD%^%^BLACK%^A thunderous boom echoes throughout the area as "+ETOQCN+
            " strikes "+targ->QCN+" with "+ETO->QP+" %^YELLOW%^e%^BLACK%^le%^RESET%^%^WHITE%^c%^YELLOW%^tr%^RESET%^%^WHITE%^i%^YELLOW%^f%^BLACK%^ie%^YELLOW%^d%^BLACK%^ "
            "longknife, knocking "+targ->QO+" to the %^RED%^ground%^BLACK%^.%^RESET%^",({ETO,targ})
          );
          tell_object(ETO,
            "%^BOLD%^%^BLACK%^A thunderous boom echoes throughout the area as you strike "
            +targ->QCN+" with your longknife, knocking "+targ->QO+" to "
            "the %^RED%^ground%^BLACK%^.%^RESET%^"
          );
          tell_object(targ,
            "%^BOLD%^%^BLACK%^A deafening boom sends you to the ground as "+ETOQCN+
            " strikes you soundly with "+ETO->QP+" %^YELLOW%^e%^BLACK%^le%^RESET%^%^WHITE%^c%^YELLOW%^tr%^RESET%^%^WHITE%^i%^YELLOW%^f%^BLACK%^ie%^YELLOW%^d%^BLACK%^ longknife.%^RESET%^"
          );
          targ->set_paralyzed((random(8)+7),
            "%^BOLD%^%^BLACK%^You are trying to get your bearings after the deafening "
            "boom.%^RESET%^"
          );
          break;
        default:
          tell_object(ETO,
            "Something is broken, or you wouldn't be seeing this "
            "message. Please bug report what you were doing at the time."
          );
          break;
      }
      return 1;
    }
}

int throwme(object targ){
    if(!objectp(TO)) return 0;
    if(!objectp(ETO)) return 0;
    if(!objectp(targ)) return 0;
    ETO->set_property("thrown",1);
    tell_room(environment(ETO),
        "%^YELLOW%^"+ETOQCN+" throws "+ETO->QP+" e%^BLACK%^le%^RESET%^%^WHITE%^c%^YELLOW%^tr%^RESET%^%^WHITE%^i%^YELLOW%^f%^BLACK%^ie%^YELLOW%^d longknife at "
        +targ->QCN+"'s head and it explodes into thousands of %^WHITE%^sparks%^YELLOW%^ as "
        "it makes contact.%^RESET%^",({ETO,targ})
    );
    tell_object(ETO,
        "%^YELLOW%^You throw your e%^BLACK%^le%^RESET%^%^WHITE%^c%^YELLOW%^tr%^RESET%^%^WHITE%^i%^YELLOW%^f%^BLACK%^ie%^YELLOW%^d%^YELLOW%^ longknife at "+targ->QCN+"'s head "
        "and it explodes into thousands of %^WHITE%^sparks%^YELLOW%^ as it makes contact.%^RESET%^"
    );
    tell_object(targ,
        "%^YELLOW%^"+ETOQCN+" throws "+ETO->QP+" e%^BLACK%^le%^RESET%^%^WHITE%^c%^YELLOW%^tr%^RESET%^%^WHITE%^i%^YELLOW%^f%^BLACK%^ie%^YELLOW%^d longknife straight "
        "at you and it explodes into thousands of %^WHITE%^sparks%^YELLOW%^ as it makes "
        "contact with your head.%^RESET%^"
    );
    targ->do_damage("torso",random(21)+50);
    if(!targ->will_save(46)) {
        tell_object(targ,
            "%^YELLOW%^You are temporarily blinded by the %^WHITE%^sparks%^YELLOW%^!%^RESET%^"
        );
        targ->set_temporary_blinded(roll_dice(1,2),
            "%^YELLOW%^You are temporarily blinded by the %^WHITE%^sparks%^YELLOW%^!%^RESET%^"
        );
    }
    new(OBJ+"elec_knife.c")->start_reset(ETO);
    call_out("remove",1);
    return 1;
}

