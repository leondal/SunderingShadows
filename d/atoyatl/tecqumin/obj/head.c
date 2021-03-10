//Coded by Lujke

#include <std.h>
inherit OBJECT;

string nm, GP;

void create() {
    string temp_name, first_letter;
    ::create();
    temp_name = generate_name();
    first_letter = upper_case(temp_name[0..0]);
    nm = first_letter + temp_name[1..strlen(temp_name)-1];
    set_name("shrunken head");
    set_id( ({"head","shrunken head","tecqumin head", "human head",
                      "blackened head", "shrunken human head", nm}) );
    set_short("The head of " + nm);
    set_obvious_short("%^BOLD%^%^BLACK%^shrunken human head");
    set_weight(4);
    set_long("%^BOLD%^%^BLACK%^This blackened head has been shrunk to"
            +" about the size of a small"
            +" grapefruit. Its skin is blackened and leathery. The empty"
            +" eye sockets have been painted %^RESET%^%^CYAN%^turquoise"
            +" %^BOLD%^%^BLACK%^inside and the drawn back lips reveal a"
            +" nearly full set of %^RESET%^%^ORANGE%^t%^RESET%^e"
            +"%^ORANGE%^et%^RESET%^h%^BOLD%^%^BLACK%^ and, surprisingly,"
            +" a near perfectly preserved %^RESET%^%^RED%^tongue%^BOLD%^"
            +"%^BLACK%^.");
    set_lore("The priests of the %^ORANGE%^Tecqumin%^RESET%^ presided"
            +" over a cult of death and human sacrifice. The"
            +" %^RED%^blood%^RESET%^ of the souls offered up in the"
            +" '%^CYAN%^flowery death%^RESET%^', as they called it, was"
            +" supposed to go to feed the %^BOLD%^%^YELLOW%^S%^BOLD%^"
            +"%^WHITE%^u%^YELLOW%^n L%^BOLD%^%^WHITE%^o%^YELLOW%^rd"
            +"   %^RESET%^and the other %^MAGENTA%^Gods%^RESET%^, to enable"
            +" them to ensure that the sun could make its journey across"
            +" the %^BOLD%^%^CYAN%^s%^BOLD%^%^WHITE%^k%^BOLD%^%^CYAN%^y"
            +"%^RESET%^ each day and the other natural processes could"
            +" occur as they were supposed to. The body parts of the"
            +" sacrifices were supposed to hold some special powers."
            +" Limbs would be eaten in acts of %^RED%^ritual cannibalism"
            +" %^RESET%^and skulls or preserved heads were usually kept"
            +" as tokens or trophies. The higher the %^CYAN%^status"
            +" %^RESET%^of the victim, the more power was ascribed to his"
            +" or her remains. No story survives to explain how the"
            +" %^ORANGE%^Tecqumin%^RESET%^ came to believe these things,"
            +" nor how their once mighty civilisation ceased to exist.");
  set_property("lore",30);
  if (random(2)){
    GP = "her";
  } else {
    GP = "his";
  }
}

string query_name(){
  return nm;
}

int vowel_end(string str){
  int len;
  len = strlen(str)-1;
  if ( str[len..len] == "a" ||str[len..len] == "e" ||str[len..len] == "i"||str[len..len] == "o"||str[len..len] == "u"){
    return 1;
  }
  return 0;
}

int vowel_start(string str){
  if ( str[0..0] == "a" ||str[0..0] == "e" ||str[0..0] == "i"||str[0..0] == "o"||str[0..0] == "u"||str[0..0] == "y"){
    return 1;
  }
  return 0;
}

string generate_name(){
  int i, num;
  string * syllables, syllable, prev_syllable, result;
  syllables = ({"tec", "qual", "tol", "toah", "ram", "ep", "thon", "tal", "meh", "aq", "pro", "ak", "nam", "man", "rath", "um", "on", "frac", "quet", "chech", "zin", "en", "quam", "quan", "in", "ami", "cher", "nob", "ba", "fram", "kal", "fret", "ol", "pret", "trac", "tram", "tec", "qu", "al", "ah", "tham", "nor", "lot", "wa", "hel", "hin", "run", "ram", "tro", "reb", "chi", "ha", "zer", "za", "tsa", "tser", "cra", "tril", "trip", "frit", "tec", "min", "lit", "nom", "hab", "hub", "jin", "ro", "teoc", "hual", "huac", "roca"});
  num = 1 + random(2) + random (2) + random(3);
  prev_syllable = "b";
  result = "";
  for (i = 0; i <num;i++){
    syllable = syllables[random(sizeof(syllables))];
    if (vowel_end(prev_syllable)){
      while (vowel_start(syllable)){
        syllable = syllables[random(sizeof(syllables))];
      }
    }
    result += syllable;
  }
  return result;
}


