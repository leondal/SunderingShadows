//minor change to fix readability in her description.  Circe 12/21/03
#include <std.h>

inherit NPC;

void create()
{
    ::create();

    set_name("Anita Kolito");
    set_short("Anita Kolito, caretaker of the Church of Shadow");
    set_id(({ "anita", "kolito", "Anita", "Anita Kolito", "anita kolito", "caretaker" }));
    set_long(
        "Anita Kolito stands before you, her sparkling blue hair " +
        "drifting down her shoulders, almost like a serene waterfall. Her eyes, a " +
        "similar shade of blue, sparkle with life and an inner peace nothing can " +
        "sunder.  Her garments are of a pure white cloth seemingly cut from the " +
        "heavens themselves, moving with the slow flowing movements of wet cloth, " +
        "even though they are as dry as the desert sands, but not as chaotic as if " +
        "they were blown by the winds.  Anita wears around her neck a thin rope, " +
        "along which hangs a simple band of metal, matched to the one on her ring " +
        "finger, you would assume they are both wedding bands, however, rumors abound " +
        "that her husband died shortly after their marriage.  She is, however, " +
        "exceptionally knowledgable about the church and the goings-on in and around " +
        "it."
        );
    set_race("human");
    set_body_type("human");
    set_class("cleric");
    set_hd(50, 1);
    set_hp(10000000);
    set_spells(({ "flame strike", "cause blindness", "hold person", "touchsickle" }));
    set_spell_chance(90);
    new("/d/common/obj/armour/robe")->move(TO);
    command("wear robe");
//   set_unique(1);  // not needed now that we're loading the master object
    set_alignment(4);
    remove_std_db();
    set_gender("female");
    set_spoken("wizish");
}

void init()
{
    ::init();
    if (TP->query_ghost()) {
        call_out("whisper_dead", 1, TP);
    }
}

void whisper_dead(object who)
{
    command("whisper " + who->query_name() + " You may wish to pray, to get a new body. If you need help once you have prayed, we can reequip you with basic items here.");
}
