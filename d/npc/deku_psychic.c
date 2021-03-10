#include <std.h>;
inherit "/std/psychic";
object ob;

void make_me() {
  switch(random(2)) {
    case 0:
        set_gender("female");
        set_name("Cathra Gywon");
        set_id(({ "cathra", "gywon", "cathra gywon",
        "Cathra","Gywon","Cathra Gywon","psychic"}));
        set_short("Cathra Gywon, Verbobone Psychic");
        set_long("%^RESET%^The woman you are beholding is "+
        "obviously quite young.  Her body is thin and "+
        "and lightly tanned.  Her slightly almond shaped "+
        "eyes are a piercing %^BLUE%^cobalt blue%^RESET%^ and "+
        "full of life.  Her %^MAGENTA%^auburn%^RESET%^ hair "+
        "is long and curly and she keeps it pulled back "+
        "behind her ears.  She wears a %^GREEN%^dark "+
        "green robe%^RESET%^ that has an open %^BOLD%^"+
        "%^BLACK%^black hand%^RESET%^ embroidered onto "+
        "the front of it.  She is mysterious and her history "+
        "a thing of secret, but recently she has taken "+
        "the job of psychic of Verbobone.  She offers "+
        "her services to anyone who needs them, for a "+
        "price, of course.");
        ob = new("/d/common/obj/armour/robe.c");
        ob->set_short("%^GREEN%^A dark green robe%^RESET%^");
        ob->set_long("%^GREEN%^This thick, heavy, robe is made "+
        "from a mysterious, dark green, fabric.  It comes down "+
        "to slightly below the knees of the wearer and has "+
        "tight sleeves that reach out to the hands.  It has been "+
        "kept suprisingly clean and doesn't look very old.  "+
        "Embroidered onto the front of it is an "+
        "open %^BOLD%^%^BLACK%^black hand%^RESET%^"+
        "%^GREEN%^.%^RESET%^"); 
        ob->set_weight(12);
        ob->move(TO);
        break;
    case 1:
        set_gender("male");
        set_name("Aarian Gywon");
        set_id(({"aarian","gywon","Aarian","Gywon",
        "aarian gywon","Aarian Gywon","psychic"}));
        set_short("Aarian Gywon, Verbobone Psychic");
        set_long("%^RESET%^The man before you is "+
        "obviously quite young.  His toned body is thin and "+
        "a pale white color.  His eyes are "+
        "piercing and seem to be a mixture of green and "+
        "gray, that reflect an intense curiosity.  "+
        "He keeps his head shaved and has several "+
        "strange symbols painted on top of it.  His body "+
        "is covered by a dark %^BLUE%^blue robe%^RESET%^ "+
        "with an open %^BOLD%^%^BLACK%^black hand%^RESET%^ "+
        "embroidered onto the front of it.  He is mysterious "+
        "and his history a thing of secret, but recently "+
        "he has taken the job of psychic of Verbobone.  He offers "+
        "his services to anyone who needs them, for a price, "+
        "of course.%^RESET%^");
        ob = new("/d/common/obj/armour/robe.c");
        ob->set_short("%^BLUE%^A dark blue robe%^RESET%^");
        ob->set_long("%^BLUE%^This thin, light, robe is made "+
        "from a dark blue cloth.  It drapes down to the feet "+
        "of the wearer and has sleeves that hang low and reach "+
        "out to the hands.  It has been kept suprisingly clean "+
        "and doesn't look very old.  Embroidered onto the front "+
        "of it is an open %^BOLD%^%^BLACK%^black hand%^RESET%^"+
        "%^BLUE%^, save that, there is nothing really remarkable "+
        "about this garment.%^RESET%^");
        ob->set_weight(8);
        ob->move(TO);
        break;
    }

}
void create() {
 ::create();
  set_race("human");
  set_alignment(5);
  set_class("mage");
  set_mlevel("mage",16 + random(3));
  set_guild_level("mage",query_level());
  set_hp(query_level() * 6 + random(21));
  set_exp(query_max_hp() * 8);
  set_stats("strength",13);
  set_stats("dexterity",14);
  set_stats("constitution",16);
  set_stats("wisdom",17);
  set_stats("intelligence",22);
  set_stats("charisma",21);
  make_me();
  command("wear robe");
  set_speed(100);
  set_price(200 + random(501));
  set_spells(({"lightning bolt","magic missile",
  "fireball","scorcher","acid arrow"}));
  set_spell_chance(75);
  set_nogo( ({ "/d/deku/forest/dforest23-5", 
		"/d/deku/forest/dforest21-2",
		"/d/deku/forest/dforest15-5"}) );
}

