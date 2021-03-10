#include <std.h>
inherit ARMOUR;

void create(){
   ::create();
   set_name("heart clasp");
   set_id(({"clasp","four heart clasp","heart clasp","cloak clasp"}));
   set_short("%^BOLD%^%^MAGENTA%^Four-heart clasp%^RESET%^");
   set_long("Made of %^BOLD%^%^RED%^rubies %^RESET%^and "+
      "%^BOLD%^%^MAGENTA%^amethysts%^RESET%^, this cloak "+
      "clasp has been designed to represent four stylized "+
      "hearts, joined at the point.\n\n%^BOLD%^"
" %^MAGENTA%^             GGGGGGGGG     %^RED%^     @@@@@@@@@ \n"
" %^MAGENTA%^           GGG      GGGG    %^RED%^  @@@@      @@@ \n"
" %^MAGENTA%^          GGG         GGG   %^RED%^  @@         @@@ \n"
" %^MAGENTA%^          GGG          GGG  %^RED%^ @@          @@@ \n"
" %^MAGENTA%^          GGGG   GGG   GGG  %^RED%^@@@   @@    @@@@ \n"
" %^MAGENTA%^          GGGGGGGGGG   GGG  %^RED%^@@@   @@@@@@@@@@ \n"
" %^MAGENTA%^   GGGGGGGG GGGGGGGGG  GGG  %^RED%^@@@  @@@@@@@@@ @@@@@@@@ \n"
" %^MAGENTA%^ GGG     GGGG   GGGGG  GGG  %^RED%^@@@  @@@@@@  @@@@     @@@ \n"
" %^MAGENTA%^ GG      GGGGG   GGG   GGG  %^RED%^@@@   @@@    @@@@      @@@ \n"
" %^MAGENTA%^GG       GGGGGG    GGG GGG  %^RED%^@@@ @@@    @@@@@        @@ \n"
" %^MAGENTA%^GGG    GGGGGGGGG    G  GGG  %^RED%^@@@  @    @@@@@@@@@    @@@ \n"
" %^MAGENTA%^GGG      GGGGGGGGG     GGG  %^RED%^@@@     @@@@@@@@@      @@ \n"
" %^MAGENTA%^  GGG                  GGG  %^RED%^@@@                  @@@ \n"
" %^MAGENTA%^   GGGGGGGGGGGGGGGGGGGGGGG  %^RED%^@@@@@@@@@@@@@@@@@@@@@@@ \n"
" %^MAGENTA%^      GGGGGGGGGGGGGGGGGGGG  %^RED%^@@@@@@@@@@@@@@@@@@@@ \n\n"
" %^RED%^      @@@@@@@@@@@@@@@@@@@@ %^MAGENTA%^ GGGGGGGGGGGGGGGGGGGG \n"
" %^RED%^    @@@@@@@@@@@@@@@@@@@@@@ %^MAGENTA%^ GGGGGGGGGGGGGGGGGGGGGG \n"
" %^RED%^  @@@            @     @@@ %^MAGENTA%^ GGG     GG           GGG \n"
" %^RED%^@@@     @@@@@@@@@      @@@ %^MAGENTA%^ GGG      GGGGGGGGG     GG \n"
" %^RED%^@@@     @@@@@@@@    @  @@@ %^MAGENTA%^ GGG  G    GGGGGGGG     GGG \n"
" %^RED%^@@       @@@@@@     @@ @@@ %^MAGENTA%^ GGG GG     GGGGG        GG \n"
" %^RED%^@@@      @@@@@   @@@@  @@@ %^MAGENTA%^ GGG  GGGG    GGGG      GGG \n"
" %^RED%^ @@@     @@@@   @@@@@  @@@ %^MAGENTA%^ GGG  GGGGGG  GGGG     GGG \n"
" %^RED%^   @@@@@@@@@ @@@@@@@@  @@@ %^MAGENTA%^ GGG  GGGGGGGG  GGGGGGGG \n"
" %^RED%^           @@@@@ @@@   @@@ %^MAGENTA%^ GGG   GGG GGGGGG \n"
" %^RED%^          @@@@   @@@   @@@ %^MAGENTA%^ GGG   GG    GGGG \n"
" %^RED%^          @@@          @@@ %^MAGENTA%^  GG          GGG \n"
" %^RED%^          @@@        @@@@  %^MAGENTA%^  GGGG        GGG \n"
" %^RED%^          @@@@      @@@@@  %^MAGENTA%^   GGGG      GGGG \n"
" %^RED%^             @@@@@@@@@     %^MAGENTA%^     GGGGGGGGG %^RESET%^\n\n"
   );
   set_value(450);
   set_type("ring");
   set_weight(1);
   set_ac(0);
   set_limbs(({"neck"}));
}
