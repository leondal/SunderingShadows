#include <std.h>
inherit "/d/common/obj/clothing/cloak";

void create(){
   ::create();
   set_name("season's cloak");
   set_id(({"cloak","season's cloak","oddly patterned cloak"}));
   set_short(("an oddly patterened cloak"));
   switch(season(time())){
      case "winter": 
         set_short("%^RESET%^%^CYAN%^w%^BOLD%^in%^RESET%^%^CYAN%^ter's c%^BOLD%^lo%^RESET%^%^CYAN%^ak%^RESET%^");
         break;
      case "autumn":
         set_short("%^ORANGE%^a%^YELLOW%^ut%^RESET%^%^ORANGE%^umn's c%^YELLOW%^lo%^RESET%^%^ORANGE%^ak%^RESET%^");
         break;
      case "summer":  
         set_short("%^RESET%^%^ORANGE%^su%^YELLOW%^mm%^RESET%^%^ORANGE%^er's c%^YELLOW%^lo%^RESET%^%^ORANGE%^ak%^RESET%^");
         break;
      default:
         set_short("%^RESET%^%^GREEN%^sp%^BOLD%^ri%^RESET%^%^GREEN%^ng's c%^BOLD%^loa%^RESET%^%^GREEN%^k%^RESET%^");
         break;
   }
//I adjusted the way the short is set based on bug reports that it was returning only 0. ~Circe~ 12/15/15
   set_obvious_short("%^RESET%^%^CYAN%^an oddly patterned cloak%^RESET%^");
   set_lore("This cloak looks to be of elven make."+
    "   There is a small enchantment on it...some kind of illusion.");
   set_property("lore difficulty",30);
   set_long((:TO,"long_desc":));
   set_size(2);
   set_value(5000);
   set_wear((:TO,"wear_me":));
}

int wear_me(){ 
  tell_object(ETO,"%^CYAN%^You throw the cloak over your shoulders and fasten it secure.");
         if(find_call_out("mess")==-1)  
           call_out("mess",120+random(1000)); 
  return 1;
}
string short_desc(){
  if (season(time()) == "winter") 
     return("%^RESET%^%^CYAN%^w%^BOLD%^in%^RESET%^%^CYAN%^ter's c%^BOLD%^lo%^RESET%^%^CYAN%^ak%^RESET%^");
  if (season(time()) == "autumn") 
     return("%^ORANGE%^a%^YELLOW%^ut%^RESET%^%^ORANGE%^umn's c%^YELLOW%^lo%^RESET%^%^ORANGE%^ak%^RESET%^");
  if (season(time()) == "summer") 
     return ("%^RESET%^%^ORANGE%^su%^YELLOW%^mm%^RESET%^%^ORANGE%^er's c%^YELLOW%^lo%^RESET%^%^ORANGE%^ak%^RESET%^");
	
    return("%^RESET%^%^GREEN%^sp%^BOLD%^ri%^RESET%^%^GREEN%^ng's c%^BOLD%^loa%^RESET%^%^GREEN%^k%^RESET%^");

}
string long_desc(){
  if (season(time()) == "winter") 
   return("%^CYAN%^ This is a cloak that is made"+
   " from a strange fabric.  It is colored"+
   " to match the season of wi%^BOLD%^nt%^RESET%^%^CYAN%^er.  "+
   "Patterns of snow flakes, i%^BOLD%^ce%^RESET%^%^CYAN%^d streams "+
   "and fro%^BOLD%^st%^RESET%^%^CYAN%^ed mountains cover the cloak. "+
   " There is subtle movement in the "+
   "patterns as if the landscape is sno%^BOLD%^wi%^RESET%^%^CYAN%^ng.%^RESET%^");

   if (season(time()) == "autumn") 
     return("%^ORANGE%^This is a cloak that is made"+
	 " from a strange fabric.  It is "+
	 "colored to match the season of f%^CYAN%^al%^ORANGE%^l."+
	 "  Patterns of le%^CYAN%^av%^ORANGE%^es and bare limbed "+
	 "trees shift subtlety as an invisible"+
	 " wind blows them.%^RESET%^");
  if (season(time()) == "summer") 
    return ("%^ORANGE%^This is a cloak that is made from a "+
	"strange fabric.  It is colored to "+
	"match the season of of s%^YELLOW%^um%^RESET%^%^ORANGE%^mer.  It "+
	"has patterns of leaves, f%^YELLOW%^lo%^RESET%^%^ORANGE%^wers and"+
	" grass that seem to shift on their "+
	"own as if some unseen breeze moves them.%^RESET%^");
	
	return("%^GREEN%^This is a cloak that is made "+
	"from a strange fabric.  It is colored "+
	"to match the season of s%^BOLD%^pr%^RESET%^%^GREEN%^ing.  Patterns"+
	" of bu%^BOLD%^dd%^RESET%^%^GREEN%^ing plants, melting ice and baby "+
	"birds subtly shift on their own as if an"+
	" unseen breeze moves them. %^RESET%^");
}