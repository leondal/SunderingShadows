#include <std.h>
#include "../elf.h"
inherit INTERACTIVE;

void create()
{   object pap;
    ::create();
    remove_std_db();
    remove_dbs(({"miscvendors"}));
    remove_random_act_dbs(({"miscvendorsrandom"}));
    add_id(({"herb merchant"}));
    set_items_allowed("misc");
    set_storage_room(STOR"herb.c");
    set_gender("female");
    set_race("elf");
    set_alignment(1);
    set_hd(20,50);
    set_name("Celisse");
    set_short("Celisse, a herb merchant");
    set_id(({"merchant","elf","celisse","shop keep"}));
    set_long(
    "Celisse is a young wild elf.  She used to live "+
    "in tharis but when her cousin was turned into a"+
    " drow for helping the drow in tharis she left as"+
    " a refugee.  Now she sell herbs in the grove to "+
    "anyone that would have them." );
    new("/d/common/obj/brewing/herb_pouch")->move(TO);
    set_emotes(10,({
    "Celisse says: I used to live in tharis.",
    "Celisse says: Tharis's elf quarter was a terrible place.",
    "Celisse says: There are not humans here tormenting us like in tharis.",
    "Celisse says: In tharis Merve used to hurt me.",
    "Celisse says: Some drow came to tharis offering help....",
    "Celisse says: When the drow started recruiting elves in tharis I knew I had to leave.",
    "Celisse says: I begged my cousin to leave tharis but she wouldn't.",
    "Celisse says: Sometimes I miss tharis, but it is peaceful here.",
    "Celisse says: My cousin stayed in tharis.  She was tricked by the drow.",
    "Celisse says: Drow came to help tharis but look how that turned out.",
    "Celisse says: The tharis elders said never trust a drow.  I had to leave.",
    "Celisse sorts through some herbs.",
    "Celisse says: This place is small but better than tharis.",
    "Celisse smiles and says: Can I offer you some herbs?"
}),0);
  pap = new("/d/common/obj/misc/paper");
  pap->move(TO);
  pap->set("language","elven");
  pap->set("read","%^GREEN%^Dear Cousin in exile\n\n%^RESET%^"+
       "I have no idea if I'll ever send this letter."+
       "  My heart aches when we parted ways because "+
       "of the drow that came to tharis.  I hope one "+
       "day we could bridge the rift they created "+
       "between us.  I know the gods cursed you to become"+
       " a drow.  I still miss you though cousin.");

}