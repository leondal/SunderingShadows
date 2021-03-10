//Morningstar of the Diamond Nova -- Yves
#include <std.h>
inherit "/d/common/obj/weapon/morningstar.c";

void create(){
     ::create();
    set_name("diamond morningstar");
    set_short("%^BOLD%^%^WHITE%^Morningstar of the Dia%^CYAN%^m%^WHITE%^ond Nova%^RESET%^");
    set_obvious_short("%^BOLD%^%^WHITE%^A dia%^CYAN%^m%^WHITE%^ond morningstar%^RESET%^");
    set_id(({
        "star",
        "morningstar",
        "morningstar of the diamond nova",
        "diamond star",
        "diamond morningstar"
    }));
    set_long(
        "%^BOLD%^%^WHITE%^The entirety of this morningstar seems to made out of one huge "
        "piece of dia%^CYAN%^m%^WHITE%^ond, even the shaft. The head has been "
        "painstakingly carved into %^BLACK%^wicked spikes%^WHITE%^ of beautiful and "
        "glittering dia%^CYAN%^m%^WHITE%^ond that look as if they are sharp enough to "
        "pierce even the toughest of armors. Etched into the shaft is a "
        "intricate %^CYAN%^starburst%^WHITE%^ shape that provides a good grip along the "
        "smoothness of the handle.%^RESET%^\n"
    );
    set_lore(
        "%^BOLD%^%^WHITE%^The %^RESET%^%^CYAN%^elves%^BOLD%^%^WHITE%^ of the fallen kingdom of %^RESET%^%^GREEN%^Agrashalva%^BOLD%^%^WHITE%^ often looked to "
        "the %^BLUE%^skies%^WHITE%^ in just about any situation. One star in particular "
        "had always stood out to them and they called it %^BLACK%^Nyrua%^WHITE%^. It "
        "shone brighter and longer than any other star they had ever "
        "known, with a strange %^CYAN%^luminescence%^WHITE%^ similar to a well cut "
        "diamond. It is said that these %^RESET%^%^CYAN%^elves%^BOLD%^%^WHITE%^ of the island of "
        "%^RESET%^%^GREEN%^Argentrock%^BOLD%^%^WHITE%^ were able to harness the light and supernatural "
        "powers of %^BLACK%^Nyrua%^WHITE%^ and imbue it within diamond morningstars. The "
        "stars have now found their way into the hands of the %^RESET%^%^CYAN%^elven%^BOLD%^%^WHITE%^ "
        "warriors who fight against the %^MAGENTA%^Fey'ri%^WHITE%^.%^RESET%^"
    );
    set_property("lore",20);
    set_property("enchantment",4);
    set_hit((:TO, "hitme":));
    set_value(2000);
    set_wield((:TO,"wield_func":));
    set_unwield((:TO,"unwield_func":));
}

int wield_func(string str) {
    if((int)ETO->query_level() < 24) {
        tell_object(ETO,
            "%^BOLD%^%^WHITE%^The morningstar resists your grasp!"
        );
        return 0;
	}
    tell_object(ETO,
        "%^BOLD%^%^WHITE%^The shaft of the dia%^CYAN%^m%^WHITE%^ond morningstar is filled with %^RED%^warmth%^WHITE%^ and "
        "soft %^CYAN%^light%^WHITE%^.%^RESET%^"
    );
    return 1;
}

int unwield_func(string str) {
    tell_object(ETO,
        "%^BOLD%^%^WHITE%^The %^CYAN%^light%^WHITE%^ and %^RED%^warmth%^WHITE%^ fade from the dia%^CYAN%^m%^WHITE%^ond morningstar.%^RESET%^"
    );
    return 1;
}

int hitme(object targ){
    if(!objectp(TO)) return 1;
    if(!objectp(ETO)) return 1;
    if(!objectp(targ)) return 1;
    if(random(1000) < 250){
        switch(random(36)){
    case 0..20:
        tell_room(environment(ETO),
            "%^BOLD%^%^WHITE%^The crystalline %^BLACK%^spikes%^WHITE%^ of "+ETOQCN+"'s dia%^CYAN%^m%^WHITE%^ond morningstar "
            "dig deep into "+targ->QCN+"'s flesh as it is slams into "
            +targ->QO+".%^RESET%^",({ETO,targ})
        );
        tell_object(ETO,
            "%^BOLD%^%^WHITE%^The crystalline %^BLACK%^spikes%^WHITE%^ of your dia%^CYAN%^m%^WHITE%^ond morningstar dig deep "
            "into "+targ->QCN+"'s flesh as you slam it into "+targ->QO+".%^RESET%^"
        );
        tell_object(targ,
            "%^BOLD%^%^WHITE%^The crystalline %^BLACK%^spikes%^WHITE%^ of "+ETOQCN+"'s dia%^CYAN%^m%^WHITE%^ond morningstar "
            "dig deep into your flesh as it slams into you.%^RESET%^"
        );
        targ->do_damage("torso",random(8)+5);
    break;
    case 21..31:
        tell_room(environment(ETO),
            "%^BOLD%^%^BLACK%^The %^WHITE%^dia%^CYAN%^m%^WHITE%^ond morningstar%^BLACK%^ held by "+ETOQCN+" blurs in a flash "
            "of %^CYAN%^light%^BLACK%^ and passes right through "+targ->QCN+" before "
            +targ->QS+" is %^RED%^struck%^BLACK%^ by it again from the other "
            "side.%^RESET%^",({ETO,targ})
        );
        tell_object(ETO,
            "%^BOLD%^%^BLACK%^Your %^WHITE%^dia%^CYAN%^m%^WHITE%^ond morningstar%^BLACK%^ blurs in a flash of %^CYAN%^light%^BLACK%^ and "
            "passes right through "+targ->QCN+" before you %^RED%^strike%^BLACK%^ "
            +targ->QO+" again from the other side.%^RESET%^"
        );
        tell_object(targ,
            "%^BOLD%^%^BLACK%^The %^WHITE%^dia%^CYAN%^m%^WHITE%^ond morningstar%^BLACK%^ held by "+ETOQCN+" blurs in a flash "
            "of %^CYAN%^light%^BLACK%^ and passes right through you before you are %^RED%^struck%^BLACK%^ "
            "again from the other side.%^RESET%^"
        );
        ETO->execute_attack();
    break;
    case 32..35:
        tell_room(environment(ETO),
            "%^BOLD%^%^CYAN%^"+ETOQCN+"'s %^WHITE%^dia%^CYAN%^m%^WHITE%^ond morningstar%^CYAN%^ glows brightly as it "
            "%^RED%^smashes%^CYAN%^ into "+targ->QCN+"'s chest, crushing "+targ->QP+" "
            "%^YELLOW%^flesh%^CYAN%^ and %^WHITE%^bone%^CYAN%^.%^RESET%^",({ETO,targ})
        );
        tell_object(ETO,
            "%^BOLD%^%^CYAN%^Your %^WHITE%^dia%^CYAN%^m%^WHITE%^ond morningstar%^CYAN%^ glows brightly as it %^RED%^smashes%^CYAN%^ into "
            +targ->QCN+"'s chest, crushing "+targ->QP+" %^YELLOW%^flesh%^CYAN%^ and %^WHITE%^bone%^CYAN%^.%^RESET%^"
        );
        tell_object(targ,
            "%^BOLD%^%^CYAN%^A %^BLACK%^sickening%^CYAN%^ crunch can be heard as "+ETOQCN+"'s %^WHITE%^dia%^CYAN%^m%^WHITE%^ond "
            "morningstar%^CYAN%^ glows brightly and %^RED%^smashes%^CYAN%^ into your chest.%^RESET%^"
        );
        set_property("magic",1);
            targ->do_damage("torso",random(10)+10);
            targ->set_paralyzed(random(8)+7,
                "%^BOLD%^%^CYAN%^You are trying to catch your breath after that blow!%^RESET%^"
            );
        set_property("magic", -1);
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

