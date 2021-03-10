#include <std.h>
#include <move.h>
#include "../../tecqumin.h"

inherit VAULT;

void create() {
  ::create();
  set_indoors(1);
  set_property("light", 2);
  set_terrain(STONE_BUILDING);
  set_travel(DECAYED_FLOOR);
  set_name("A stone walled trophy hall");
  set_short( "A stone walled trophy hall" );
  set_long( "This appears to be a %^ORANGE%^trophy hall%^RESET%^. Four"
    +" great square stone pillars are adorned with %^CYAN%^carvings"
    +"%^RESET%^, and the walls are decorated with %^ORANGE%^hunting"
    +" trophies%^RESET%^. A stone staircase in the north of the"
    +" room descends below ground level." );
  set_items(([ ({"pillar", "pillars", "stone pillar", "stone pillars"}) 
              : "The carvings on the pillars appear to be sequential"
    +" %^CYAN%^illustrations%^RESET%^. You may be able to %^BOLD%^"
    +"%^YELLOW%^decipher%^RESET%^ each pillar, if you are canny enough.", 
           ({"staircase", "stairs", "stone staircase", "stone stairs"})
              : "The stairs have collapsed halfway down, and are"
    +" impassable. What remains would have been broad enough to allow"
    +" two human sized creatures to pass easily side by side.",
            ({"trophy", "trophies", "hunting trophy", "hunting trophies"})
              : "Various ugly %^ORANGE%^warthog%^RESET%^ heads are"
    +" displayed on the walls, along with a massive moose head complete"
    +" with antlers; numerous %^BOLD%^%^BLUE%^br%^YELLOW%^i%^BLUE%^g"
    +"%^CYAN%^h%^BLUE%^t%^GREEN%^l%^BLUE%^y %^GREEN%^co%^YELLOW%^l"
    +"%^GREEN%^ou%^BLUE%^"
    +"r%^RED%^e%^GREEN%^d %^YELLOW%^b%^RED%^i%^YELLOW%^rds%^RESET%^,"
    +" two stuffed %^BOLD%^%^YELLOW%^j%^RESET%^%^ORANGE%^a%^BOLD%^g"
    +"%^RESET%^%^ORANGE%^u%^BOLD%^%^BLACK%^a%^YELLOW%^rs%^RESET%^ and"
    +" what looks like a massive %^BOLD%^%^GREEN%^s%^RESET%^%^GREEN%^e"
    +"%^BOLD%^rp%^RESET%^%^GREEN%^e%^BOLD%^nt%^RESET%^ decorated with"
    +" %^BOLD%^%^RED%^b%^CYAN%^i%^RED%^rd %^GREEN%^of %^BLUE%^p"
    +"%^YELLOW%^a%^BLUE%^rad%^CYAN%^i%^BLUE%^se %^RED%^p%^MAGENTA%^l"
    +"%^RED%^um%^CYAN%^e%^RED%^s"  ]));
  set_smell("default","The air is still and humid, carrying hints of the perfumes of jungle plants");
  set_listen("default","Faint sounds of the jungle drift in from outside");
  set_exits((["south"   : CITY_ROOM + "throne_room",
               "east"   : CITY_ROOM + "mehaq_room"]));
  set_door("arched door", CITY_ROOM + "throne_room", "south", 0);
  set_door_description("arched door", "This door is unusual for Tecqumin architecture, being arched whereas most doors of the area have a square stone lintel.");
  set_door("stone door", CITY_ROOM + "mehaq_room", "east", 0);
  set_door_description("stone door", "A heavy stone door, with a square lintel.");
}

void init(){
  ::init();
  add_action("decipher", "decipher");
}

int decipher(string str){
  int roll;
  string result;
  if (!stringp(str)||(!interact("pillar", str) && !interact("marking", str))){ 
    tell_object(TP, "what do you want to decipher?");
    return 1;
  }
  roll = TP->query_skill("academics");
  result = "Which of the four pillars do you wish to decipher?";
  if (str == "pillar 1" || str == "first pillar"){
    result = "The carvings on this pillar appears to relate a creation myth. A plumed surpent gives birth to the shining orb of the sun, and carries it aloft into the sky to keep it safe from the night-time hunters, chief among whom is the stealthy jaguar. The life giving heat and light of the sun shine down upon the lands and cause the maize and all the other plants to grow. However, its safety comes at a cost to the serpent, who is forever separated from those of its kind who cannot fly. Its tears fall on the land as rain, feeding the rivers and canals and giving vibrant life to the jungle.";
  } 
  if (str == "pillar 2" || str == "second pillar"){
  result = "The carvings on this pillar speak of the founding of the society of the Tecqumin. They relate a time when the simple peoples of the jungle knew terror when the sun went into hiding each night. The jaguar moved among them, taking as it would from the young and the sick and the old. A time came when the grief of the plumed serpent grew so strong, the clouds of her tears hid the sun from view for days and weeks on end. But a hero among the men climbed the highest tree to rise above the clouds, and leapt into the the sky to reach the sun. He would have fallen to his death, but the plumed serpent stirred from her grief at the sight of his courage, and caught him as he fell. He told her of the plight of the people, brought on by her tears. Moved by his story, she took him to the sun, who shared with him the secret of fire, that the peoples of the jungle might never again be without heat or light. She also told him of her grief, and he offered her a trade. His people would offer up loved ones of their own as a sacrifce to the sun, to let their grief match that of the plumed serpent, to ensure that she would never again cry so hard or for so long as to deprive them of the light of the sun.";
  } 
  if (str == "pillar 3" || str == "third pillar"){
  result = "The markings on this pillar relate a triumphal story of Tecqumin conquest of surrounding peoples. Armies spearheaded by raging berserkers with great axes and refined heroes dressed in armour of shining plate spread across the lands, capturing territory and bringing back captives - most of whom were lead up the stairs of the mighty ziggurat to die under amber knives wielded by masked priests at the altar at the top.";
  } 
  if (str == "pillar 4" || str == "fourth pillar"){
  result = "The markings on this pillar seem a little less ancient than some of the others. They seem to relate the forging of an alliuance between the Tecqumin people and some sort of being of power. Exactly what this being is, is unclear, but the carvings show it being incorporated into the existing pantheon of Tecqumin deities, and afforded a portion of the worship - and sacrifices - allotted to them. Perhaps a large portion.";
  } 
  if (result == "Which of the four pillars do you wish to decipher?"){
    tell_object(TP, result);
    return 1;
  }
  if (roll <16){
    tell_object(TP, "You don't have the sort of learning you would need to interpret the markings on the pillar");
    return 1;
  }
  roll += random(roll);
  if (roll<30){
    tell_object(TP, "You don't manage to make sense of the markings, though you think you may be on the right track.");
    return 1;
  }
  tell_object(TP, result);
  return 1;
}
