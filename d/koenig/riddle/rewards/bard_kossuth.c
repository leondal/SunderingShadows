//bard_kossuth.c - Bard of Kossuth reward for Nereid Riddle Quest.  Circe 12/18/03
#include <std.h>
#include "../../nereid.h"

inherit ANGERLIGHT;

void create(){
    ::create();
//    set_name("kossuth instrument");
    set_id(({"set of bongo drums","bongo drums","drums","set","bongos","instrument"}));
    set_short("%^ORANGE%^A set of bongo drums%^RESET%^");
    set_long(
      "%^ORANGE%^This set of bongo drums is made much like any other.  "+
      "Two drums, one smaller than the other, have been bound together and "+
      "may be played by striking the tops with either the player's fingers or "+
      "the small mallet that hangs by the larger drum's side.  However, unlike "+
      "most bongos, this set of drums seems to be writhing in f%^RED%^l%^BOLD%^a"+
      "%^YELLOW%^m%^RED%^e%^RESET%^%^ORANGE%^.  The flames dancing up the taut "+
      "sides are clearly some sort of illusion, as they produce no heat at all.  "+
      "They do, however, create a fierce light that causes the flames to dance "+
      "along the musician's face.  A message appears fitfully within the flames."
    );
    set_read("%^BOLD%^%^RED%^May the fury of the blazing fire burn your "+
       "foes.  You may use these bongo drums to call on the fury of the flame and "+
       "%^YELLOW%^<%^RED%^anger%^YELLOW%^> %^RED%^those who dare oppose you or "+
       "%^YELLOW%^<%^RED%^play%^YELLOW%^> %^RED%^to create the light of a fire.");
    set_weight(8);
    set_value(0);
    set_lore("Granted to the faithful of Kossuth who help spread his flames upon "+
       "the world, these bongo drums are seen as a sign of blessing and pleasure of "+
       "Flame Lord.  The illusion used to create the flames is an adaptation of a "+
       "basic illusion spell, perfected by the Invoker Fastidin Alundan as a donation "+
       "to his church.  It is said to never dim or fade, and there are those who say "+
       "Kossuth himself applies the spell to these bongos as a fitting reward for those "+
       "who share his lore.");
    set_property("lore difficulty",12);
}
