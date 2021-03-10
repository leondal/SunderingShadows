#include <std.h>

#define SHAPES ({"dolphin","whale","shark","kraken","merman","mermaid","sea serpent","seal","sea lion","turtle"})

inherit DAEMON;

int i, j;
string str, DESC1;

void create()
{
   ::create();
}

void create_necklace(object obj)
{
   j = random(sizeof(SHAPES));
   str = SHAPES[j];
   switch(str) {
      case "dolphin":
         DESC1 = "The dolphin is done in fine detail and appears to be in"+
         " mid jump. The tale is clearly defined as well as the face, which"+
         " seems to be smiling. You can even see a small indentation for a"+
         " blowhole on the dolphin's back.";
         break;
      case "whale":
         DESC1 = "The whale appears to be that of a killer whale, a thin"+
         " line has been drawn to mark the white and black pattern that"+
         " would be clear if it were colored. The whale appears to be"+
         " swimming with its powerful tail, but the eyes seem to stare"+
         " right at you. It does not appear to be an evil monster as its"+
         " reputation would maintain.";
         break;
      case "shark":
         DESC1 = "The shark is done with excellent precision, the fin is"+
         " sleek and you can almost imagine the creature gliding through"+
         " the water. Some sailors wear shark pendants for protection against"+
         " the creatures.";
         break;
      case "kraken":
         DESC1 = "The powerful kraken is almost unnerving. It is similar in"+
         " appearance to an octopus, but on a larger scale, with a more"+
         " elongated head and a nasty beak hidden in the center of its"+
         " deadly tentacles.";
         break;
      case "merman":
         DESC1 = "The merman is portrayed wielding a spear in one hand"+
         " and looks rather stern. The large tail that covers half of his"+
         " body is done in such detail that you can see every individual"+
         " scale.";
         break;
      case "mermaid":
         DESC1 = "The mermaid has a smile on her face. She has flowing"+
         " hair, and wears two clam shells that barely conceal her well"+
         " endowed frame. You can see every scale on her long tail, the"+
         " detail is astonishing.";
         break;
      case "sea serpent":
         DESC1 = "The sea serpent is coiled up in a knot, almost like two"+
         " figure-eights if you tilted one to the left and one to the right."+
         " Ridges run down from the top of the creatures head partially"+
         " over the back, re-emerging at the tail.";
         break;
      case "seal":
         DESC1 = "The seal looks sleek and happy, each of its fins done"+
         " with remarkable precision, and you can even see the whiskers on"+
         " its smiling face.";
         break;
      case "sea lion":
         DESC1 = "The sea lion is incredibly large and stands (as best it"+
         " can) tall and proud as though it is guarding its family. Such"+
         " detail has been added to the carving that you can even see its"+
         " whiskers, and a few scars the artist chose to add in.";
         break;
      case "turtle":
         DESC1 = "The turtle is small and appears to be swimming through"+
         " the ocean depths. Its head is out of its shell and you can see"+
         " each toe nail on its feet so much detail has been added. Even the"+
         " pattern on its shell is precise and intricate.";
         break;
   }
   obj->set_long("The necklace has a black silk cord that loops about the"+
   " neck, it also has a pendant of a "+str+" carved out of whalebone."+
   " "+DESC1+"");
   obj->set_name("carved necklace");
   obj->set_short("A "+str+" necklace");
   obj->set_id(({"necklace","carved necklace",""+str+" necklace","torm r_necklace"}));
   obj->set_weight(1);
   obj->set_type("ring");
   obj->set_limbs(({"neck"}));
   obj->set_value(random(25)+50);
}
