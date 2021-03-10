#include "/d/dagger/aketon/short.h"

inherit VAULT;

void create() {
   ::create();
   set_property("light",2);
   set_property("indoors",1);
   set_short("An elven home of Aketon");
   set_long("%^GREEN%^An elven home of Aketon%^RESET%^\n"+
   "You have walked into a very lovely living room. The room is large"+
   " with a vaulted ceiling that has a beautiful chandelier hanging"+
   " from it in the shape of a large flower. There are two couches"+
   " that are covered in cotton with embroidered silk designs. In the"+
   " southwest corner of the room is a dining table with six chairs."+
   " Beautiful paintings made of dyed shells are hung on the walls."+
   " There are actual doors that lead to other rooms to the west and"+
   " south.");
   set_smell("default","The room has a light and pleasant smell to it.");
   set_listen("default","You hear the wind whistling through the leaves outside.");
   set_items(([
   ({"doors","door"}) : "There are three doors here, two are made of"+
   " cedar, the one leading south is made of oak.",
   "ceiling" : "The ceiling is made out of wood and is beautifully"+
   " vaulted and rather tall. From the center hangs an exquisite"+
   " chandelier.",
   "chandelier" : "There is a beautiful crystal chandelier that hangs"+
   " from a bronze chain down in the center of the room. It is in the"+
   " shape of a flower with six petals that come out. There are no"+
   " candles lighting it, but instead softly glowing sunstones that"+
   " have been enchanted by a mage.",
   ({"wall","walls","paintings"}) : "The walls are mostly bare except"+
   " for two paintings, one hung on the north and one hung on the"+
   " east wall. They are a matched set, not quite identical but they"+
   " compliment eachother well. They are made from sea shells that have"+
   " been dyed various colors, and sometimes broken or crushed. They"+
   " stand out from the velvet background that they have been set on"+
   " and are rather remarkable. They are pictures of a castle on a cliff"+
   " at different angles. Some of the longer shells serve for towers,"+
   " some crushed shells make up the cliff, and some of the more common"+
   " and smaller sea shells make up the bricks of the main part of the"+
   " castle.",
   "couches" : "There are two couches in the middle of the room that"+
   " are made of light cream cotton. They have silk designs embroidered"+
   " on them in the shapes of various intricate flowers.",
   ({"table","dining table"}) : "The dining room table is in the south"+
   " east part of the room. It is made of dark walnut and is rectangular."+
   " There are six chairs placed around it, one at either end and"+
   " two on each of the other sides. In the center of the table is a"+
   " beautiful crystal vase with a single rose in it.",
   ({"vase","crystal vase"}) : "There is a beautiful vase in the center"+
   " of the dining room table that holds a single %^BOLD%^MAGENTA%^purple%^RESET%^ rose.",
   ({"rose","purple rose","silk rose"}) : "%^MAGENTA%^The rose in the"+
   " vase is quite beautiful, but upon close examination you discover"+
   " that it is actually made of silk! It looks so real, though, that"+
   " it is hard to tell the difference. The petals are a dark purple"+
   " and the leaves are a %^GREEN%^rich green%^MAGENTA%^, it even has"+
   " thorns on the stems.",
   "chairs" : "There are six chairs around the rectangular dining"+
   " room table that are carved with beautiful designs. They match"+
   " the table perfectly.",
   ]));
   set_door("cedar door",RPATH3+"3one30","northeast",0);
   set_door("door",RPATH3+"3one33","west",0);
   set_door("oak door",RPATH3+"3one38","south",0);
   set_exits( (["northeast":RPATH3+"3one30",
      "south":RPATH3+"3one38",
      "west":RPATH3+"3one33"]) );
}
