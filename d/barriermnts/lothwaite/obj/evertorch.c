//everburning torch - Circe 4/28/04

#include <std.h>

inherit OBJECT;

nosave int lit;
int brighter;

void create() {
  ::create();
    set_name("everburning torch");
    set_id(({"torch","golden torch","everburning torch","ever burning torch"}));
    set_short("%^YELLOW%^E%^RESET%^%^ORANGE%^v%^YELLOW%^e%^RESET%^"+
       "%^ORANGE%^r%^YELLOW%^b%^RESET%^%^ORANGE%^u%^YELLOW%^r"+
       "%^RESET%^%^ORANGE%^n%^YELLOW%^i%^RESET%^%^ORANGE%^n"+
       "%^YELLOW%^g Torch%^RESET%^");
    set_obvious_short("%^YELLOW%^A golden torch%^RESET%^");
    set_long(
      "%^RESET%^%^ORANGE%^This torch is formed of %^YELLOW%^solid "+
      "gold%^RESET%^%^ORANGE%^, making it rather heavy.  It is "+
      "%^BOLD%^%^WHITE%^exquisitely carved%^RESET%^%^ORANGE%^ and "+
      "detailed, studded with %^BOLD%^%^BLUE%^sapphires %^RESET%^"+
      "%^ORANGE%^and %^BOLD%^%^CYAN%^diamonds%^RESET%^%^ORANGE%^.  "+
      "Smaller gem chips are scattered in a filigree pattern, adding "+
      "%^BOLD%^%^WHITE%^s%^RESET%^p%^BOLD%^a%^RESET%^r%^BOLD%^k"+
      "%^RESET%^l%^BOLD%^e %^RESET%^%^ORANGE%^to the already ornate "+
      "torch.  Strangely, there seems to be no physcial explanation "+
      "for the %^BOLD%^%^WHITE%^bright light %^RESET%^%^ORANGE%^"+
      "emitted from the torch.  There is a tiny inscription running "+
      "just beneath the %^YELLOW%^gold filigree %^RESET%^%^ORANGE%^"+
      "you could perhaps read."
    );
    set_lore("Yet another of the creations of the grand Shaman "+
       "Helgatha Rothmar, this fantastic torch is designed to "+
       "burn endlessly without fuel.  It may be dampened, but "+
       "never fully put out.  This magic was also employed in "+
       "the lanterns that brighten the town of Lothwaite.");
    set_property("lore difficulty",8);
    set_weight(7);
    set_value(1235);
    lit = 0;
    brighter = 2;
}

int query_lit() { return lit; }


void init() {
    add_action("extinguish", "darken");
    add_action("light","brighten");
    add_action("extinguish","darken");
    add_action("read","read");
}

int read(string str){
   if(!str){
      return 0;
   }
   if(str != "torch" && str != "everburning torch"){
      return 0;
   }
   tell_object(ETO,"%^MAGENTA%^A heatless flame to %^YELLOW%^brighten "+
       "%^RESET%^%^MAGENTA%^your way\n"+
       "  %^MAGENTA%^But %^BOLD%^%^BLACK%^darken %^RESET%^%^MAGENTA%^"+
       "to enjoy light of day");
   tell_room(EETO,""+ETOQCN+" reads the torch.",ETO);
   return 1;
}

int light(string str) {
  int prevlight;
   if(TP->query_bound() || TP->query_unconscious()) { 
      TP->send_paralyzed_message("info",TP);
      return 1;
   }
/*   if(prevlight=TP->light_blind(-3)) {

   notify_fail(TP->light_blind_fail_message(prevlight)+"\n");
      return 0;
   }
removed so you can light it in the dark ~Circe~ 5/4/11
*/   
   if(!str) { 
      notify_fail("Light what?\n");
      return 0;
   } 
   if(!id(str))
   if (TO != present(str,ETO)) {
     notify_fail("You can only light things designed to burn and only if you have them.\n"); 
     return 0;
   }
     if(lit) {
       write("It is already lit!\n");
       return 1;
     } 
    tell_object(ETO,"You wave a hand over the torch and it suddenly "+
       "flares into light.");
    tell_room(EETO,""+ETOQCN+" waves a hand over the torch and it "+
       "flares into light.", ETO);
    prevlight = ETO->query_property("light");
    ETO->remove_property("light");
    prevlight += brighter;
    ETO->set_property("light", prevlight);
    lit = 1;
    return 1;
}

int extinguish(string str) {
   if(TP->query_bound() || TP->query_unconscious()){
      TP->send_paralyzed_message("info",TP);
      return 1;
   }
   
   if(!str) { 
      notify_fail("Douse what?\n");
      return 0;
   } 
   if(!id(str))
   if (TO != present(str,ETO)) {
     notify_fail("You can only douse things you have that are lit.\n"); 
     return 0;
   }
   if(!lit) { 
      write("The torch is not lit!");
      return 1;
   }
    tell_object(ETO,"You blow gently and the torch goes out.");
    tell_room(EETO,""+ETOQCN+" extinguishes a torch.",TP);
    ETO->set_property("light", -brighter);
    lit = 0;
    return 1;
}

string query_short() {
    string str;
    str = ::query_short();
    if(lit) str = str+ " (lit)";
    return str;
}

int move(mixed dest) {
    int x;
    if(lit) ETO->set_property("light", -brighter);
    x = ::move(dest);
    if(lit) ETO->set_property("light", brighter);
    return x;
}

remove() {
   if (lit){
     ETO->set_property("light", -brighter);
     lit = 0;
   }
   return ::remove();
}

int isMagic(){
   int magictorch;
   magictorch = ::isMagic();
   magictorch = magictorch+1;
   return magictorch;
}
