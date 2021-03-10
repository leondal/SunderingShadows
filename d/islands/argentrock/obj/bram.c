#include <std.h>

inherit OBJECT;

int blah, dam = 6;

void create()
{
    ::create();

    set_name("brambles");
    set_id(({ "brambobj", "brambles", "bramble", "thorns", "vine", "vines"
              "Choking Brambles", "choking brambles" }));
    set("short", "Choking Brambles");
    set("long", " This is a circular ring of " +
        "thorns around your neck.  It is cutting" +
        " you and keeps getting tighter cutting off your air! \n" +
        "Pehaps you should %^CYAN%^_extract_%^RESET%^ the %^CYAN%^brambles.");
    set_value(0);
    set_weight(0);

    blah = 0;
}

int drop()
{
    return 1;
}

int give()
{
    return 1;
}

void init()
{
    ::init();
    add_action("extract", "extract");
    add_action("my_give", "give");
    add_action("my_give", "offer");
    if (!userp(ETO)) {
        TO->remove();
    }
}

int extract(string str)
{
    if (str != "brambles") {
        return 0;
    }
    write("%^BOLD%^%^GREEN%^You tear the vines from your neck.");
    write("%^BOLD%^%^YELLOW%^ YOU SCREAM IN AGONY AS THE THORNS TEAR YOUR FLESH!");
    tell_room(EETO, "You see " + ETOQCN + " pulls thorns free from "
              + ETO->QP + " neck!", ETO);
    ETO->cause_typed_damage(ETO, 0, roll_dice(3, 6), "piercing");
    TO->remove();
    return 1;
}

void hurt(object tp)
{
    if (!objectp(tp)) {
        remove();
        return;
    }
    if (tp->query_ghost()) {
        remove();
        return;
    }
    tell_object(ETO, "%^BOLD%^Blood drips from your neck as the" +
                " %^RESET%^%^ORANGE%^brambles%^RESET%^%^BOLD%^ cut and tighten.\n");
    dam = roll_dice(2, 6) + dam;
    tp->cause_typed_damage(tp, 0, roll_dice(2, 6), "piercing");
    call_out("hurt", 20, ETO);
    if (blah > 4 && !interactive(ETO)) {
        ETO->force_me("extract brambles");
    }
    blah++;
}

int my_give(string str)
{
    if (id(str)) {
        return 1;
    }
}
