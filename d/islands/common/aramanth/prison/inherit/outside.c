#include <std.h>
inherit ROOM;

void create(){ 
   ::create();
   set_property("indoors",0);
   set_property("light",2);
   set_property("teleport proof",(25+roll_dice(1,20)));
   set_terrain(ROCKY);
   set_travel(RUBBLE);
   set_name("Below the Heavens");
   set_short("Below the Heavens");
   set_long((:TO,"long_desc":));
   set("night long",(:TO,"night_desc":));
   set_items(([
      "statues":"These are truly horrible images of all manners of humanoids being tortured in various fashions. After closer inspection they seem more like petrified people rather than stone carvings.",
     "rubble":"The rubble is composed of the shattered statues. It is unclear if it covers the ground or is the ground.",
	"sky":"The sky is big, open, and distinctly void of any life."
   ]));
}

string long_desc(){
   return("There is a stark contrast between the magestic"+
   " beauty"+
   " of the open blue sky above you and the morbid rubble"+
   " you tread across. Above you, the clear sky is warm and"+
   " welcoming, but below your feet the ground is completely"+
   " covered in what can only be described as the shattered."+
   " remains of sick and twisted statues.  Statues of"+
   " remarkable detail, each depecting a gruesome and horrible"+
   " fate for whomever it was modeled after."+
   " Seeminly sporadic, large arcing stones protrude from"+
   " the rubble that constitutes the ground you walk on."
   " To the east there is a very large building.");
}
string night_desc() { 
   return("There is a stark contrast between the magestic"+
   " beauty of the starry night sky above you and the morbid"+
   " rubble you tread across. Above you, the clear night sky"+ 
   " is decorated with millions of little dots of light."+
   " The mural of stars painted across the heavens is breath"+  
   " taking, but below your feet the ground is the complete"+
   " opposite. Covered in what can only be described as the"+ 
   " shattered"+
   " remains of sick and twisted statues, the sight is almost"+
   " enough to turn your stomach. Statues of"+
   " remarkable detail, each depecting a gruesome and horrible"+
   " fate for whomever it was modeled after."+
   " Seeminly sporadic, large arcing stones protrude from"+
   " the rubble that constitutes the ground you walk on."
   " To the east there is a very large building.");
}
 