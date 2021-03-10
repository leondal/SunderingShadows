#include <std.h>
#include <move.h>

inherit MONSTER;

void create()
{
    ::create();
    set_name("Agadan");
    set_short("%^RESET%^%^CYAN%^Agadan the " +
              "%^BOLD%^%^WHITE%^Ivory Carver%^RESET%^");
    set_id(({ "agadan", "Agadan", "carver", "ivory carver" }));
    set_long("%^CYAN%^Day or night, no matter the season, Agadan " +
             "can be found lounging on a bench, whittling his time away. " +
             "Beneath his %^BOLD%^%^WHITE%^l%^RESET%^o%^BOLD%^ng " +
             "whi%^RESET%^t%^BOLD%^e b%^RESET%^e%^BOLD%^ar%^RESET%^d%^CYAN%^, " +
             "he chatters softly with himself in a language nobody " +
             "but he can comprehend. His talent for carving one's likeness " +
             "from ivory is known across the realm. This is even more " +
             "impressive when you consider that, rumor has it, he is " +
             "%^WHITE%^completely blind%^CYAN%^. His " +
             "%^BOLD%^%^WHITE%^mil%^RESET%^k%^BOLD%^y " +
             "w%^RESET%^h%^BOLD%^ite ey%^RESET%^e%^BOLD%^s " +
             "%^RESET%^%^CYAN%^certainly lend some credence to this " +
             "story. He will gladly %^BOLD%^<carve> %^RESET%^%^CYAN%^one " +
             "for any whom he deems worthy.. and who has enough " +
             "%^YELLOW%^g%^RESET%^%^ORANGE%^o%^BOLD%^ld%^RESET%^%^CYAN%^, " +
             "of course.%^WHITE%^");
    set_race("human");
    set_body_type("humanoid");
    set_size(2);
    set_hd(10, 1);
    set_hp(query_max_hp());
    set_exp(1000);
}

void init()
{
    ::init();
    add_action("carve", "carve");
}

int carve()
{
    int i;
    object ob;
    command("emote 's %^BOLD%^%^WHITE%^milky eyes%^RESET%^ " +
            "stare right through you.");
    command("speech mumble");
    command("emote draws forth a block of " +
            "%^BOLD%^%^WHITE%^ivory%^RESET%^ and then waits.");
    if (!TP->is_class("mage") && !TP->is_class("bard")
        && !TP->is_class("sorcerer") && !avatarp(TP)) {
        command("emote shakes his head and returns to " +
                "his work, ignoring you.");
        return 1;
    }
    if (!TP->query_funds("gold", 2000)) {
        command("emote grumbles under his breath, shaking his head.");
        command("emote mumbles something about %^YELLOW%^2000 gold%^RESET%^.");
        command("emote hides the %^BOLD%^ivory%^RESET%^ away.");
        return 1;
    }
    TP->use_funds("gold", 2000);
    command("emote utters some words and draws his knife " +
            "across the %^BOLD%^ivory%^RESET%^.");
    ob = new("/d/magic/obj/statue");
    ob->set_weight(0);
    ob->move(TP);
    ob->move(TO);
    ob->set_weight(10);
    command("give statue to " + TPQN);
    return 1;
}
