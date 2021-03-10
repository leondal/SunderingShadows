#include "/d/dagger/aketon/short.h"

inherit ROOM;

void create() {
   ::create();
   set_property("light",3);
   set_property("indoors",1);
   set_short("Aketon Spell Shop");
   set_long("%^BOLD%^Aketon Spell Shop%^RESET%^
This is one of the most important shops among all in Aketon. As people of "
      "Aketon enjoys the use of magic and spells, this spell shop becomes "
      "one of the most visited places of this highly civilized city. You "
      "can purchase spell books, backups as well as all different kinds "
      "of scrolls here. There is a counter to the western side of this "
      "detailed large room with a chair sitting behind it. Quite a lot of "
      "customers hanging around here looking for some scrolls.\nThere is "
      "a large sign sticked on the wall aside the counter.");
   set_items( (["shop":"This is a spell shop, you can buy spell books, "
      "backups of spell book and scrolls here.",
      "scrolls":"All sorts of scrolls.",
      "spell books":"Some new spell books for sale.",
      "backups":"New backups of spell books.",
      "counter":"A rose wood counter with a chair behind it.",
      "chair":"This is the chair of the shop owner.",
      ({"people","customers"}):"They are looking for the scrolls they "
      "want.",
      "sign":"<help shop> will give you a list of commands."]) );
   set_smell("default","You smell the smell of paper and ink.");
   set_listen("default","You hear the muttering of the customers.");
   set_listen("customers","You hear: what!? 42903 gold? I don't have that "
      "much money!");
   set_exits( (["east":RPATH1+"1one26"]) );
}

void reset() {
   ::reset();
   if( !present("wizolyx") )
      new(MPATH+"wizolyx")->move(TO);
}
