//librarian for new Seneca
//~Circe~ 11/20/07
#include <std.h>
inherit NPC;

void create(){
   ::create();
   set_name("Elena Clay");
   set_short("Elena Clay, Librarian of Seneca");
   set_id(({"Elena Clay","Elena","elena","librarian"}));
   set_long("Elena Clay is a middle-aged woman with dark skin the "+
      "color of %^ORANGE%^coffee %^CYAN%^sweetened with cream.  "+
      "She has %^BOLD%^%^BLACK%^raven tresses %^RESET%^%^CYAN%^"+
      "sprinkled with a generous helping of %^RESET%^gray%^CYAN%^, "+
      "which she keeps pulled back in a long braid.  She dresses "+
      "simply, in flowing dresses of muted colors that allow her "+
      "to work and climb to retrieve books for people.  She is "+
      "fastidious in her duties, and she watches over the library "+
      "with the protective air of a mother hen.\n\n%^RESET%^She can "+
      "help you <research> someone, or you can see <help library> "+
      "for important commands to use here.");
   set_race("human");
   set_gender("female");
   set_class("bard");
   set_level(25);
   set_alignment(5);
   set_exp(1);
   set_nwp("studying",16);
}
