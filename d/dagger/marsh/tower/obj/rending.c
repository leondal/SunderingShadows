#include <std.h>
inherit "/d/common/obj/weapon/dagger.c";
object owner;
int uses;
void init()
{
    ::init();
    if (interactive(TP) && !owner) {
        owner = TPQN;
    }
}

create()
{
    ::create();
    set_name("knife");
    set_id(({ "knife", "knife of rending" }));
    set_short("%^RESET%^%^MAGENTA%^Knife of %^RED%^rending%^RESET%^");
    set_long("%^RED%^"
             "This double-bladed knife is an exceptionally long knife and it's "
             "blade edges are serrated and razor sharp. It's ivory handle glows "
             "with a dull red glow and bears a black rune upon the pommel."
             "%^RESET%^"
             );
    set_value(200);
    set_wield((: TO, "extra_wield" :));
    set_hit((: TO, "extra_hit" :));
    uses = 10;
}
int extra_wield()
{
    if ((int)TP->query_level() < 25 || TP->is_class("fighter")) {
        write("The knife vanishes as you attempt to wield it!");
        TO->remove();
        return 0;
    }
    if ((string)TP->query_name() != owner && (string)TP->query_name() != "morlock") {
        write("The knife fails to bond with you and vanishes!");
        TO->remove();
        return 0;
    }
    write("%^RED%^"
          "The knife settles nicely within your grasp!"
          "%^RESET%^"
          );
    say("%^RED%^"
        + TPQCN +
        " smiles a wicked tooth-filled grin!"
        "%^RESET%^"
        , TP);
    return 1;
}

int extra_hit(object ob)
{
    object vic;
    int dam;
    vic = ETO->query_current_attacker();
    if (random(8) > 4) {
        return 6;
    }
    if (!random(10)) {
        message("my_action", "%^RED%^"
                "As you slash your foe, the knife pulses!\n"
                "%^BLUE%^You sever a %^RED%^major vein%^BLUE%^ within "
                + vic->query_cap_name() +
                "'s body!%^RESET%^"
                , ETO);
        message("other_action", "%^RED%^"
                "The knife wielded by "
                + ETO->query_cap_name() +
                " seems to pulse while slicing deep into "
                + vic->query_cap_name() +
                "'s flesh!\n"
                "%^BLUE%^" + vic->query_cap_name() + "begins to %^RED%^bleed%^BLUE%^ "
                "profusely!"
                "%^RESET%^"
                , environment(vic), (({ ETO, vic })));
        message("my_action", "%^RED%^"
                "The knife wielded by " + ETO->query_cap_name() + " slices a major vein within you!\n"
                "%^BLUE%^A major amount of your %^RED%^blood%^BLUE%^ gushes out "
                "of the wound!%^RESET%^"
                , vic);
        dam = random((int)ETO->query_stats("strength"));
        dam = dam + random((int)ETO->query_lowest_level());
        uses--;
        if (uses < 1) {
            tell_object(ETO, "%^BOLD%^%^RED%^With your last blow, the dagger suddenly vanishes!%^RESET%^");
            TO->remove();
        }
        return dam;
    }
    return 3;
}
