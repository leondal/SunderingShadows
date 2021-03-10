//sealing wax - for Lothwaite.  Circe 6/18/04
#include <std.h>
#include "../lothwaite.h"

#define COLORS ({"%^BOLD%^white","%^RED%^crimson","%^BOLD%^%^RED%^scarlet","%^ORANGE%^taupe","%^YELLOW%^sunny yellow","%^GREEN%^pine green","%^BOLD%^%^GREEN%^vibrant green","%^CYAN%^sea green","%^BOLD%^%^CYAN%^sky blue","%^BLUE%^midnight blue","%^BOLD%^%^BLUE%^royal blue","%^MAGENTA%^violet","%^BOLD%^%^MAGENTA%^lilac","%^BOLD%^%^BLACK%^black","%^YELLOW%^gold","si%^BOLD%^lv%^RESET%^er","%^BOLD%^plat%^CYAN%^i%^WHITE%^num"})

inherit OBJECT;

int j,uses;
string str, COLOR;

void create()
{
   ::create();
	j = random(sizeof(COLORS));
	COLOR = COLORS[j];
      switch(j){
         case 0..13:  set_value(100);
                      break;
         case 14..16:  set_value(500);
                       break;
         default:  set_value(100);
                   break;
      }
      set_cointype("gold");
	set_name(""+COLOR+" sealing wax%^RESET%^");
	set_short(""+COLOR+" sealing wax%^RESET%^");
	set_id(({"wax","sealing wax",""+COLOR+" sealing wax"}));
      set_long("This is a small, slender rectangle of wax dyed a "+
         ""+COLOR+" shade%^RESET%^.  A braided wick of %^BOLD%^"+
         "soft wool %^RESET%^runs through the center, to keep "+
         "the wax from burning too quickly.  A tail of the wick "+
         "has been left out, allowing one to hold it as the other "+
         "end melts.  Typically, several layers of melted wax "+
         "are applied in one place, then pressed with a seal or "+
         "signet ring to protect a letter or other document from "+
         "forgery or unwanted eyes.");
	set_weight(1);
      uses = 10;
}

int is_sealing_wax(){return 1;}

int query_color(){ return ""+COLOR+"";}

int query_uses() {return uses;}

void set_uses(int num) {
   if(num < 0) num = -1*num;
   uses = num;
}


string query_short() {
   string holder;

   holder = ::query_short();

   holder += " ["+uses+" stamps left]";
   return holder;
}

string query_long(string str) {
   string holder;

   holder = ::query_long(str);

   holder += " ["+uses+" stamps left]";
   return holder;
}

int query_value(){
   int v = ::query_value();
//   if(v) return v;
   if((string)TO->query_name() == "%^YELLOW%^gold sealing wax" || (string)TO->query_name() == "si%^BOLD%^lv%^RESET%^er sealing wax" || (string)TO->query_name() == "%^BOLD%^plat%^CYAN%^i%^WHITE%^num sealing wax"){
      return uses * 50;
   }else{
      return uses * 10;
   }
}