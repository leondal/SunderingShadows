#include <std.h>
inherit OBJECT;

void init() {
    ::init();
    add_action("press_func","press");
}

void create() {
    ::create();
    set_id(({"jewel","flame_jewel"}));
    set_short("%^RED%^Red jewel%^RESET%^");
    set_long(
        "%^RED%^This is a small red jewel. A small facet on the top of "
        "the jewel appears as though it could be pressed. There appears "
        "to be an inner fire burning in the center of the jewel."
        "%^RESET%^"
    );
    set_weight(5);
    set_value(250);
}

int press_func(string str) {
    if (!str) {
        notify_fail("Press what?\n");
        return 0;
    }
    if (str != "facet") {
        notify_fail("Press what?\n");
        return 0;
    }
    tell_object(TP, "%^BOLD%^%^RED%^You press hard on the facet of the jewel and here a small click!%^RESET%^");
    call_out("do_pulse1", 1, ETO);
    call_out("do_pulse2", 3, ETO);
    call_out("do_pulse3", 6, ETO);
    call_out("do_pulse4", 9, ETO);
    call_out("do_pulse5", 12, ETO);
    call_out("do_hotdeath", 15, ETO);
    return 1;
}

void do_hotdeath (object ob) {
    int wisdom, intel, i, max, number, main_number;
    string hit_limb;
    object here,*inv;
    main_number = 4;
    here = ETO;
    tell_room(ETO,"%^YELLOW%^The jewel begins to glow red from the intense heat it is creating. Then suddenly it explodes into a huge ball of flame that engulfs the entire room, including yourself!%^RESET%^");
    
    for (i=0, max = sizeof(inv=all_living(ETO)); i<max; i++) {
        number = random(main_number)+4;
        if (!living(inv[i])) continue;
        while (number > 0) {
            hit_limb=inv[i]->return_target_limb();
            tell_room(ETO, "%^BOLD%^%^RED%^"+inv[i]->query_cap_name()+" recoils in pain as "+inv[i]->query_possessive()+" "+hit_limb+" burns in flame!", inv[i]);
            tell_object(inv[i], "%^BOLD%^%^RED%^Your "+hit_limb+" screams with pain from the fire!");
            inv[i]->do_damage(hit_limb, random(15) + 6);
            number--;
        }
    }
    TO->remove();
    return;
}

void do_pulse1(object me) {
    if (me = living ( environment ( TO ) ) ) {
        tell_object(ETO, "%^BOLD%^%^RED%^The jewel becomes so hot to the touch that you drop it!%^RESET%^");
        TP->force_me("drop flame_jewel");
        TO->set_weight(10000000);
    }
    tell_room(ETO, "%^BOLD%^The jewel pulses with an inner light!%^RESET%^");
    TO->set_weight(10000000);
    return 1;
}

void do_pulse2(object ob) {
    tell_room(ETO, "%^CYAN%^The jewel pulses with an inner light!%^RESET%^");
    return;
}

void do_pulse3(object ob) {
    tell_room(ETO, "%^YELLOW%^The jewel pulses with an inner light!%^RESET%^");
    return;
}

void do_pulse4(object ob) {
    tell_room(ETO, "%^RED%^The jewel pulses with an inner light!%^RESET%^");
    return;
}

void do_pulse5(object ob) {
    tell_room(ETO, "%^BOLD%^%^RED%^The jewel pulses with an inner light!%^RESET%^");
    return;
}