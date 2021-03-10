//bard_selune.c - Bard of Selune reward for Nereid Riddle Quest.  Circe 12/18/03
#include <std.h>
#include "../../nereid.h"

inherit CALMLIGHT;

void create(){
    ::create();
//    set_name("selune instrument");
    set_id(({"white lap-harp","lap-harp","harp","instrument"}));
    set_short("%^BOLD%^%^WHITE%^A milky white lap-harp%^RESET%^");
    set_long(
      "%^BOLD%^%^WHITE%^This delicate lap-harp is made of an iri%^CYAN%^de%^WHITE%^scent "+
      "milky white substance that resembles %^CYAN%^moonstone%^WHITE%^.  It is rather heavy "+
      "for its size, but breathtaking.  The sides of the harp all seem to "+
      "be nothing but %^GREEN%^climbing vines%^WHITE%^, which grow together to form a wide, "+
      "flat %^YELLOW%^leaf %^WHITE%^on the front arm of the harp.  There, a pair of darkly beautiful "+
      "f%^RESET%^e%^BOLD%^m%^RESET%^i%^BOLD%^n%^RESET%^i%^BOLD%^n%^RESET%^e %^BOLD%^eyes "+
      "have been carved, embellished with molten si%^YELLOW%^l%^WHITE%^ver that "+
      "shimmers in the moonlight.  The strings of the harp are an ethereal "+
      "silver, the color of a %^CYAN%^moo%^WHITE%^n%^CYAN%^beam%^WHITE%^.  A message has "+
      "been carved along the vine and filled with molten %^YELLOW%^gold%^WHITE%^."
    );
    set_read("%^BOLD%^%^WHITE%^May the light within this harp bring you wisdom "+
       "and compassion to aid those who are lost and the power to sooth "+
       "those rash in their anger.  You may use the harp to "+
       "%^CYAN%^<%^WHITE%^calm%^CYAN%^> %^WHITE%^those who attack you or "+
       "%^CYAN%^<%^WHITE%^play%^CYAN%^> %^WHITE%^to create a bright light.");
    set_weight(8);
    set_value(0);
    set_lore("This breathtaking lap-harp was created to battle the forces "+
       "of the Dark Goddess and guide the Seekers on their paths.  Legend "+
       "says that this mystical instrument will play for only the most devout "+
       "Seekers of the Moonmaiden.  No mortal knows the secret of creating "+
       "these wondrous instruments, and many assert that the Moonmaiden herself "+
       "forms them from her tears.");
    set_property("lore difficulty",12);
}
