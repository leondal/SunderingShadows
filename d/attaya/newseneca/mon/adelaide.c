//Adelaide - psicrystal vendor for new Seneca
//Circe 12/2/07
#include <std.h>

inherit "/std/psion_vend.c";

void create(){
   ::create();
   set_name("adelaide");
   set_id(({"adelaide","Adelaide","shopkeeper","purveyor","murphy","Adelaide Murphy"}));
   set_short("Adelaide Murphy, Purveyor of Psicrystals");
   set("aggressive", 0);
   set_long(
      "Her soft %^RESET%^silver hair%^CYAN%^ swept into a bun, "+
      "Adelaide is the very picture of matronly warmth.  She is "+
      "dressed in a plain %^BLUE%^wool dress%^CYAN%^ with a high "+
      "neckline edged with lace, as are the cuffs of her long "+
      "sleeves.  A %^BOLD%^%^WHITE%^platinum brooch %^RESET%^%^CYAN%^set "+
      "with a large %^BOLD%^gem %^RESET%^%^CYAN%^graces the bodice, "+
      "giving Adelaide her only adornment.  Her skin is thin and "+
      "beginning to wrinkle, the lines around her eyes and mouth "+
      "attesting to her ready, quiet smile.  She wears sensible "+
      "%^ORANGE%^boots%^RESET%^%^CYAN%^ that offer some protection when "+
      "she chooses to leave the enclave, but she seems quite happy "+
      "to stay here and serve her customers tea, chatting "+
      "animatedly about matters of the mind.\n"+
      "<help shop> will show you how to use this shop"
   );
   set_gender("female");
   set_alignment(4);
   set_race("human");
   set_class("psion");
   set_hd(30,2);
   set_level(30);
   set_guild_level("psion",30);
   set_property("no bump", 1);
   set_spell_chance(60);
   set_spells(({"mind thrust","mind thrust","mind thrust","microcosm",
       "energy bolt","energy bolt"}));
}
