#include <std.h>
inherit OBJECT;

void create()
{
   ::create();
   set_name("writing quill");
   set_short("%^BOLD%^%^RED%^A%^RESET%^%^RED%^n %^BOLD%^e%^ORANGE%^x%^RED%^q%^RESET%^%^RED%^u%^BOLD%^isi%^ORANGE%^t%^RED%^e f%^RESET%^%^RED%^i%^BOLD%^e%^ORANGE%^r%^RED%^y-fe%^ORANGE%^a%^RED%^t%^RESET%^%^RED%^h%^BOLD%^er%^ORANGE%^e%^RED%^d wr%^RESET%^%^RED%^i%^BOLD%^ti%^ORANGE%^n%^RED%^g qu%^RESET%^%^RED%^i%^YELLOW%^l%^RED%^l%^RESET%^");
   set_id(({"quill","pen","feather"}));
   set_long(
      "%^BOLD%^%^RED%^This unusual quill has been formed from a "+
      "fiery red feather that is soft to the touch. The feather "+
      "changes color from deep red near the sharpened tip through "+
      "various shades of orange to a %^YELLOW%^bright yellow %^RED%^at "+
      "the end. It would probably make a wonderful writing tool, and "+
      "you feel a strange form of energy that seems to make the quill "+
      "want to spin in your fingers.%^RESET%^"
   );
   set_weight(1);
   set_value(25);
}

void init()
{
   ::init();
   add_action("spin","spin");
}

void spin(string str)
{
        if(ETO->query_bound() || ETO->query_unconcious() || ETO->query_paralyzed()
|| ETO->query_tripped()) {
                TP->send_paralyzed_message("info",TP);
                return 1;
        }
   if(str != "quill") {
      tell_object(TP,"Spin what?");
      return 1;
   }
      tell_object(TP,"%^BOLD%^%^RED%^You spin the quill in your fingers as "+
         "you think about what to write.%^RESET%^");
      tell_room(ETP,"%^BOLD%^%^RED%^"+TPQCN+" spins the quill in "+
         ""+TP->query_possessive()+" fingers with a thoughtful "+
         "look on "+TP->query_possessive()+" face.%^RESET%^",TP);
      return 1;
}
