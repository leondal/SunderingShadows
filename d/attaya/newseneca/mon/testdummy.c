//adapted from Ares' testdummy for new Seneca
//used in the mage guild
//~Circe~ 1/9/08
#include <std.h>

inherit "/std/monster.c";

void create(){
    ::create();
    set_name("Test Dummy");
    set_id(({"dummy", "test dummy", "testdummy", "practice dummy"}));
    set_race("test dummy");
    set_body_type("human");
    set_short("practice dummy");
    set_long("This rugged practice dummy is made of magic-"+
       "resistant %^BOLD%^%^BLACK%^void steel %^RESET%^"+
       "%^CYAN%^roughly shaped into the image of a man.  He is left "+
       "featureless, though he has arms, legs, and head to "+
       "allow a mage to practice casting spells at him.  "+
       "Strangely, the metal seems to absorb physical blows "+
       "much as it absorbs magic.  A mystical %^BOLD%^rune "+
       "%^RESET%^%^CYAN%^carved into its chest glows eerily "+
       "and may be used to %^BOLD%^<%^WHITE%^return%^CYAN%^"+
       "> %^RESET%^%^CYAN%^the dummy when practice is finished.%^RESET%^");
    set_hd(1,1);
    set_level(1);
    set_class("fighter");
    set_mlevel("fighter", 1);
    set_hp(10000000);
    set_exp(1);
    set_overall_ac(9);
}

void die(mixed ob){
   set_long("This was once a practice dummy made of void steel "+
      "that finally met its end in combat.  Its mangled form "+
      "is twisted and torn, and it looks as though it will be "+
      "of use no more.");
   ::die(ob);
}